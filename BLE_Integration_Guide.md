# BLE Integration Guide for OSSM M5 Remote
*A technical reference for applying the BLE connection layer to your own M5 Remote firmware.*

---

## Overview

The original OSSM M5 Remote firmware communicates with the OSSM machine using **ESP-NOW** — a proprietary Espressif peer-to-peer radio protocol. This version adds an alternative transport: **Bluetooth Low Energy (BLE)**, allowing the remote to connect directly to the OSSM's built-in BLE GATT server.

Both transports coexist in the firmware. When connecting, the remote first tries BLE; if that doesn't find an OSSM, it falls back to ESP-NOW. Only one transport is active at a time, tracked by an internal flag.

---

## Files Added / Modified

| File | Status | Purpose |
|---|---|---|
| `src/OssmBLE.h` | **New** | Public API header for the BLE layer |
| `src/OssmBLE.cpp` | **New** | Full BLE implementation (scanning, connecting, sending) |
| `src/main.cpp` | **Modified** | Integration points — routing, UI, button handlers |
| `platformio.ini` | **Modified** | Added `NimBLE-Arduino` library dependency |

---

## Part 1 — The BLE Library (`OssmBLE.h` / `OssmBLE.cpp`)

These two files are self-contained and can be dropped into any ESP32 Arduino / PlatformIO project.

### Public API (`src/OssmBLE.h`)

```cpp
bool OssmBleTryConnect();           // Scan and connect to OSSM BLE device
bool OssmBleConnected();            // Returns true if currently connected

void OssmBleSetMode(bool enabled);  // Enable/disable BLE as the active transport
bool OssmBleIsMode();               // Returns true if BLE mode is currently active

bool OssmBleSendText(const String& command, String* response = nullptr);
bool OssmBleSendCommand(int command, float value, float speedValue,
                        float maxDepthMm, float maxSpeedValue,
                        String* response = nullptr);
bool OssmBlePrepareStrokeEngine();  // Send "go:strokeEngine" — required before starting
bool OssmBleReadState(String* stateText);
bool OssmBlePollLimits(float* outMaxDepthMm, float* outMaxSpeedValue);
```

---

### The OSSM BLE Protocol

The OSSM firmware exposes a GATT service with three characteristics:

| Characteristic | UUID | Direction | Purpose |
|---|---|---|---|
| Command | `522b443a-4f53-534d-1000-420badbabe69` | Write | Send control commands |
| Speed Knob | `522b443a-4f53-534d-1010-420badbabe69` | Write | Configure knob independence |
| State | `522b443a-4f53-534d-2000-420badbabe69` | Read | Read machine state / limits |

**Service UUID:** `522b443a-4f53-534d-0001-420badbabe69`  
**Device Name (advertised):** `OSSM`

Commands are plain **ASCII strings** written to the Command characteristic. The OSSM replies with `ok:...` or `fail:...` which can be read back from the same characteristic.

#### Command Reference

| Command string | What it does |
|---|---|
| `go:strokeEngine` | Activates the stroke engine — **must be sent before any movement** |
| `set:speed:N` | Set speed, N = 0–100 (percent) |
| `set:depth:N` | Set depth, N = 0–100 (percent) |
| `set:stroke:N` | Set stroke length, N = 0–100 (percent) |
| `set:sensation:N` | Set sensation / waveform, N = 0–100 (percent) |
| `set:pattern:N` | Set motion pattern, N = 0–6 |

**Important:** All values are percentages (0–100), not raw mm or RPM. The OSSM side applies its own limits. This is different from ESP-NOW, which uses raw units.

---

### How Scanning and Connection Works (`OssmBleTryConnect()`)

Location: `src/OssmBLE.cpp`, function `OssmBleTryConnect()`

```
1. If already connected, return true immediately.
2. Initialise NimBLE stack (once only) — device name "M5-OSSM-Remote", max TX power.
3. Run an active BLE scan for 3 seconds.
4. Look for a device whose advertised name is "OSSM" OR whose service UUID matches.
5. Connect to that device.
6. Obtain the GATT service, then grab the three characteristics.
7. Write "false" to the Speed Knob characteristic — this disables the OSSM's
   built-in physical knob so the remote has full speed authority.
8. Return true on success.
```

The function is safe to call multiple times — it returns early if a connection already exists and will re-attempt connection if it was lost.

---

### Value Mapping

For most parameters (speed, depth, stroke), the value coming in from the UI is already 0–100 in BLE mode and is clamped then written directly:

```cpp
static int clampPercent(float value) {
    if (value < 0.0f) return 0;
    if (value > 100.0f) return 100;
    return (int)(value + 0.5f);
}
```

**Sensation** is special — it uses a power curve to give better feel at the extremes:

```cpp
static int mapSensationToBlePercent(float value) {
    float normalized = value / 100.0f;          // -1.0 to +1.0
    float shaped = copysignf(powf(fabsf(normalized), 1.25f), normalized);
    float percent = (shaped + 1.0f) * 50.0f;    // map to 0–100
    return clampPercent(percent);
}
```

---

## Part 2 — Integration into `main.cpp`

### 2.1 Add the header include

At the top of `main.cpp`, alongside the other includes:

```cpp
#include "OssmBLE.h"
```

---

### 2.2 Slider Range Awareness

**Location:** `src/main.cpp`, `screenmachine()` function and the `ST_UI_HOME` case in `loop()`

In ESP-NOW mode, sliders are ranged in real units (mm, RPM). In BLE mode they must be 0–100:

```cpp
if (OssmBleIsMode()) {
    lv_slider_set_range(ui_homespeedslider, 0, 100);
    lv_slider_set_range(ui_homedepthslider, 0, 100);
    lv_slider_set_range(ui_homestrokeslider, 0, 100);
} else {
    lv_slider_set_range(ui_homespeedslider, 0, speedlimit);
    lv_slider_set_range(ui_homedepthslider, 0, maxdepthinmm);
    lv_slider_set_range(ui_homestrokeslider, 0, maxdepthinmm);
}
```

The same `OssmBleIsMode()` check is also used to display values differently — percentage vs raw number:

```cpp
if (OssmBleIsMode()) {
    snprintf(speed_v, sizeof(speed_v), "%d%%", (int)(speed + 0.5f));
} else {
    dtostrf(speed, 6, 0, speed_v);
}
```

---

### 2.3 The Connect Button Handler

**Location:** `src/main.cpp`, `connectbutton()` function

The connect button now tries BLE first, then falls back to ESP-NOW (which waits for the OSSM to broadcast):

```cpp
void connectbutton(lv_event_t * e) {
    lv_label_set_text(ui_Welcome, T_CONNECTING);

    if (!Ossm_paired) {
        OssmBleSetMode(false);  // start in ESP-NOW mode while trying

        // First, broadcast a heartbeat for ESP-NOW devices
        outgoingcontrol.esp_command = HEARTBEAT;
        outgoingcontrol.esp_heartbeat = true;
        outgoingcontrol.esp_target = OSSM_ID;
        esp_now_send(OSSM_Address, (uint8_t*)&outgoingcontrol, sizeof(outgoingcontrol));

        // Then try BLE
        bool bleConnected = OssmBleTryConnect();
        if (bleConnected) {
            OssmBleSetMode(true);     // activate BLE transport
            Ossm_paired = true;
            OssmBlePrepareStrokeEngine();   // IMPORTANT: activate stroke engine
            lv_label_set_text(ui_connect, "BLE");
            lv_scr_load_anim(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0, false);
        }
        return;
    }
    // If already paired via BLE, just navigate home
    if (OssmBleIsMode()) {
        lv_label_set_text(ui_connect, "BLE");
        lv_scr_load_anim(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0, false);
    }
}
```

**Key point:** `OssmBlePrepareStrokeEngine()` sends `"go:strokeEngine"` at connect time. Without this, the OSSM won't move even if it receives speed/depth commands.

---

### 2.4 The `SendCommand()` Router

**Location:** `src/main.cpp`, `SendCommand()` function

This is the central dispatch point. If BLE mode is active and the target is the OSSM, commands go via BLE; otherwise they go via ESP-NOW:

```cpp
bool SendCommand(int Command, float Value, int Target) {
    if (Target == OSSM_ID && OssmBleIsMode()) {

        // Safety rule: if speed is being set while depth or stroke are zero,
        // explicitly zero them on the OSSM first to avoid stale values causing
        // unexpected movement.
        if (Command == SPEED && (depth <= 0.5f || stroke <= 0.5f)) {
            OssmBleSendCommand(DEPTH, 0, speed, maxdepthinmm, speedlimit, nullptr);
            OssmBleSendCommand(STROKE, 0, speed, maxdepthinmm, speedlimit, nullptr);
        }

        String response;
        bool ok = OssmBleSendCommand(Command, Value, speed, maxdepthinmm, speedlimit, &response);
        return ok;
    }

    // ESP-NOW path (unchanged from original)
    if (Ossm_paired == true) {
        outgoingcontrol.esp_command = Command;
        outgoingcontrol.esp_value = Value;
        outgoingcontrol.esp_target = Target;
        esp_now_send(OSSM_Address, (uint8_t*)&outgoingcontrol, sizeof(outgoingcontrol));
        ...
    }
}
```

**Why the safety rule?** After the OSSM homes (on any connection), it may retain its last known depth position internally. If the remote sends a speed command before depth/stroke are set, the OSSM resumes at that stale position. Sending explicit `DEPTH 0` + `STROKE 0` first resets that state safely.

---

### 2.5 The Start/Stop Button

**Location:** `src/main.cpp`, `homebuttonmevent()` function

In BLE mode, the OSSM does not send back ON/OFF state feedback, so it must be tracked locally:

```cpp
void homebuttonmevent(lv_event_t * e) {
    if (OSSM_On == false) {
        if (OssmBleIsMode()) {
            OssmBlePrepareStrokeEngine();   // re-send go:strokeEngine to be safe
        }
        SendCommand(ON, 0, OSSM_ID);
        if (OssmBleIsMode()) {
            OSSM_On = true;   // manually track state in BLE mode
        }
    } else {
        SendCommand(OFF, 0, OSSM_ID);
        if (OssmBleIsMode()) {
            OSSM_On = false;
        }
    }
}
```

**Note:** In ESP-NOW, `OSSM_On` is updated by the `OnDataRecv` callback when the OSSM sends back confirmation. In BLE there's no such callback, so we set it ourselves.

---

## Part 3 — PlatformIO Dependency

Add the following to your `platformio.ini` under `lib_deps`:

```ini
lib_deps =
    h2zero/NimBLE-Arduino@^1.4.2
    ; ... your other libraries
```

NimBLE is used instead of the Arduino BLE library because it is significantly more memory-efficient on ESP32, which matters here as the firmware also runs LVGL, ESP-NOW, and multiple FreeRTOS tasks.

---

## Quick-Start Checklist for Porting

If you want to add BLE to your own M5 Remote firmware:

1. **Copy** `src/OssmBLE.h` and `src/OssmBLE.cpp` into your project's `src/` folder.
2. **Add** `h2zero/NimBLE-Arduino@^1.4.2` to `platformio.ini` `lib_deps`.
3. **Add** `#include "OssmBLE.h"` to `main.cpp`.
4. **In your connect handler:** call `OssmBleTryConnect()`, if it returns `true` call `OssmBleSetMode(true)` then `OssmBlePrepareStrokeEngine()`.
5. **In your command dispatcher:** check `OssmBleIsMode()` and call `OssmBleSendCommand()` instead of your ESP-NOW send.
6. **Slider ranges:** set to 0–100 when BLE mode is active (values are percentages not mm/RPM).
7. **Start/Stop:** call `OssmBlePrepareStrokeEngine()` before starting and track `OSSM_On` locally — no feedback comes back over BLE.
8. **Safety:** consider sending `DEPTH 0` + `STROKE 0` before the first speed command after connect, especially if the OSSM may still be homing.

---

## Notes and Gotchas

- **`go:strokeEngine` must be sent before movement commands.** The OSSM ignores speed/depth/stroke until this is received after connection.
- **All BLE values are 0–100%.** There are no raw mm or RPM values on the wire. The OSSM applies its own configured limits server-side.
- **The speed knob characteristic** (`...1010...`) is written with `"false"` at connect time. This puts the OSSM in "remote control" mode where the BLE remote, not the physical knob, controls speed. If you omit this, the physical knob will override your remote's speed commands.
- **NimBLE re-connect:** `OssmBleTryConnect()` checks `OssmBleConnected()` first and returns early if still connected, so it is safe to call on every command without reconnect overhead.
- **Pattern numbers** match the OSSM firmware's internal pattern list: 0–6. Check the OSSM firmware source if you need to map them to names.
