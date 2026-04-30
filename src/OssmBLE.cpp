#include "OssmBLE.h"

#include <NimBLEDevice.h>
#include <math.h>

static const char* OSSM_BLE_DEVICE_NAME = "OSSM";
static const char* OSSM_BLE_SERVICE_UUID = "522b443a-4f53-534d-0001-420badbabe69";
static const char* OSSM_BLE_COMMAND_CHAR_UUID = "522b443a-4f53-534d-1000-420badbabe69";
static const char* OSSM_BLE_SPEED_KNOB_CHAR_UUID = "522b443a-4f53-534d-1010-420badbabe69";
static const char* OSSM_BLE_STATE_CHAR_UUID = "522b443a-4f53-534d-2000-420badbabe69";

static bool ble_initialized = false;
static bool use_ble_transport = false;

static NimBLEClient* ble_client = nullptr;
static NimBLERemoteCharacteristic* ble_command_char = nullptr;
static NimBLERemoteCharacteristic* ble_speed_knob_char = nullptr;
static NimBLERemoteCharacteristic* ble_state_char = nullptr;

static uint32_t ble_last_state_poll_ms = 0;
static String ble_last_state_raw;
static const uint32_t BLE_STATE_POLL_INTERVAL_MS = 1000;

static int clampPercent(float value)
{
  if (value < 0.0f) return 0;
  if (value > 100.0f) return 100;
  return (int)(value + 0.5f);
}

static int mapSensationToBlePercent(float value)
{
  float normalized = value / 100.0f;
  if (normalized < -1.0f) normalized = -1.0f;
  if (normalized > 1.0f) normalized = 1.0f;

  float shaped = copysignf(powf(fabsf(normalized), 1.25f), normalized);
  float percent = (shaped + 1.0f) * 50.0f;
  return clampPercent(percent);
}

static int mapSpeedToBlePercent(float value, float maxSpeedValue)
{
  if (maxSpeedValue > 0.0f) {
    return clampPercent((value * 100.0f) / maxSpeedValue);
  }
  return clampPercent(value);
}

static int mapDepthToBlePercent(float value, float maxDepthMm)
{
  if (maxDepthMm > 0.0f) {
    return clampPercent((value * 100.0f) / maxDepthMm);
  }
  return clampPercent(value);
}

static float extractValueAfterKey(const String& text, const String& key)
{
  int keyPos = text.indexOf(key);
  if (keyPos < 0) {
    return -1.0f;
  }

  int pos = keyPos + key.length();
  while (pos < text.length()) {
    char c = text.charAt(pos);
    if ((c >= '0' && c <= '9') || c == '-' || c == '.') {
      break;
    }
    ++pos;
  }

  if (pos >= text.length()) {
    return -1.0f;
  }

  int end = pos;
  while (end < text.length()) {
    char c = text.charAt(end);
    if (!((c >= '0' && c <= '9') || c == '.')) {
      break;
    }
    ++end;
  }

  String valueStr = text.substring(pos, end);
  return valueStr.toFloat();
}

static String toBleCommandString(int command, float value, float speedValue, float maxDepthMm, float maxSpeedValue)
{
  switch (command)
  {
    case 1: // SPEED
    {
      return String("set:speed:") + String(clampPercent(value));
    }
    case 2: // DEPTH
    {
      return String("set:depth:") + String(clampPercent(value));
    }
    case 3: // STROKE
    {
      return String("set:stroke:") + String(clampPercent(value));
    }
    case 4: // SENSATION
    {
      return String("set:sensation:") + String(mapSensationToBlePercent(value));
    }
    case 5: // PATTERN
    {
      int patternIdx = (int)(value + 0.5f);
      if (patternIdx < 0) patternIdx = 0;
      if (patternIdx > 6) patternIdx = 6;
      return String("set:pattern:") + String(patternIdx);
    }
    case 11: // ON
    {
      int resumeSpeed = clampPercent(speedValue);
      if (resumeSpeed <= 0) {
        resumeSpeed = 0;
      }
      return String("set:speed:") + String(resumeSpeed);
      Serial.println("Started OSSM, speedValue: " + String(speedValue) + ", resumeSpeed: " + String(resumeSpeed));
    }
    case 10: // OFF
        Serial.println("BLE OFF command received - sending speed 0");
    return String("set:speed:0");
    default:
      return String("");
  }
}

bool OssmBleConnected()
{
  return (ble_client != nullptr && ble_client->isConnected() && ble_command_char != nullptr);
}

bool OssmBleTryConnect()
{
  if (OssmBleConnected()) {
    return true;
  }

  if (!ble_initialized) {
    NimBLEDevice::init("M5-OSSM-Remote");
    NimBLEDevice::setPower(ESP_PWR_LVL_P9);
    ble_initialized = true;
  }

  NimBLEScan* scanner = NimBLEDevice::getScan();
  if (scanner == nullptr) {
    return false;
  }

  scanner->setActiveScan(true);
  NimBLEScanResults results = scanner->start(3, false);

  std::string targetAddress;
  NimBLEUUID serviceUuid(OSSM_BLE_SERVICE_UUID);
  for (int i = 0; i < results.getCount(); ++i) {
    NimBLEAdvertisedDevice device = results.getDevice(i);

    bool nameMatch = device.haveName() && device.getName() == OSSM_BLE_DEVICE_NAME;
    bool serviceMatch = device.haveServiceUUID() && device.isAdvertisingService(serviceUuid);
    if (nameMatch || serviceMatch) {
      targetAddress = device.getAddress().toString();
      break;
    }
  }

  scanner->clearResults();

  if (targetAddress.empty()) {
    return false;
  }

  if (ble_client == nullptr) {
    ble_client = NimBLEDevice::createClient();
    if (ble_client == nullptr) {
      return false;
    }
  }

  NimBLEAddress remoteAddress(targetAddress);
  bool connected = ble_client->connect(remoteAddress);

  if (!connected) {
    ble_command_char = nullptr;
    ble_speed_knob_char = nullptr;
    ble_state_char = nullptr;
    return false;
  }

  NimBLERemoteService* service = ble_client->getService(NimBLEUUID(OSSM_BLE_SERVICE_UUID));
  if (service == nullptr) {
    ble_client->disconnect();
    ble_command_char = nullptr;
    return false;
  }

  ble_command_char = service->getCharacteristic(NimBLEUUID(OSSM_BLE_COMMAND_CHAR_UUID));
  if (ble_command_char == nullptr || !ble_command_char->canWrite()) {
    ble_client->disconnect();
    ble_command_char = nullptr;
    ble_speed_knob_char = nullptr;
    ble_state_char = nullptr;
    return false;
  }

  ble_speed_knob_char = service->getCharacteristic(NimBLEUUID(OSSM_BLE_SPEED_KNOB_CHAR_UUID));
  if (ble_speed_knob_char != nullptr && ble_speed_knob_char->canWrite()) {
    static const char* independentMode = "false";
    ble_speed_knob_char->writeValue((uint8_t*)independentMode, strlen(independentMode), true);
  }

  ble_state_char = service->getCharacteristic(NimBLEUUID(OSSM_BLE_STATE_CHAR_UUID));

  return true;
}

void OssmBleSetMode(bool enabled)
{
  use_ble_transport = enabled;
}

bool OssmBleIsMode()
{
  return use_ble_transport;
}

bool OssmBleSendText(const String& command, String* response)
{
  if (command.length() == 0) {
    return false;
  }

  if (!OssmBleTryConnect()) {
    return false;
  }

  ble_command_char->writeValue((uint8_t*)command.c_str(), command.length(), true);

  if (ble_command_char->canRead()) {
    std::string raw = ble_command_char->readValue();
    if (response != nullptr) {
      *response = String(raw.c_str());
    }

    if (raw.rfind("ok:", 0) == 0) {
      return true;
    }
    if (raw.rfind("fail:", 0) == 0) {
      return false;
    }
  }

  return true;
}

bool OssmBleSendCommand(int command, float value, float speedValue, float maxDepthMm, float maxSpeedValue, String* response)
{
  String bleCommand = toBleCommandString(command, value, speedValue, maxDepthMm, maxSpeedValue);
  if (bleCommand.length() == 0) {
    return false;
  }

  Serial.print("BLE tx: ");
  Serial.println(bleCommand);

  return OssmBleSendText(bleCommand, response);
}

bool OssmBlePrepareStrokeEngine()
{
  return OssmBleSendText("go:strokeEngine", nullptr);
}

bool OssmBleReadState(String* stateText)
{
  if (stateText == nullptr) {
    return false;
  }

  stateText->remove(0);

  if (!OssmBleTryConnect()) {
    return false;
  }

  if (ble_state_char == nullptr || !ble_state_char->canRead()) {
    return false;
  }

  std::string raw = ble_state_char->readValue();
  if (raw.empty()) {
    return false;
  }

  *stateText = String(raw.c_str());
  return true;
}

bool OssmBlePollLimits(float* outMaxDepthMm, float* outMaxSpeedValue)
{
  if (outMaxDepthMm == nullptr || outMaxSpeedValue == nullptr) {
    return false;
  }

  if (!OssmBleIsMode()) {
    return false;
  }

  uint32_t nowMs = millis();
  if ((nowMs - ble_last_state_poll_ms) < BLE_STATE_POLL_INTERVAL_MS) {
    return false;
  }
  ble_last_state_poll_ms = nowMs;

  String state;
  if (!OssmBleReadState(&state) || state.length() == 0 || state == ble_last_state_raw) {
    return false;
  }
  ble_last_state_raw = state;

  String lower = state;
  lower.toLowerCase();

  float parsedMaxDepth = extractValueAfterKey(lower, "maxdepth");
  if (parsedMaxDepth <= 0.0f) parsedMaxDepth = extractValueAfterKey(lower, "depthmax");
  if (parsedMaxDepth <= 0.0f) parsedMaxDepth = extractValueAfterKey(lower, "max_depth");

  float parsedMaxSpeed = extractValueAfterKey(lower, "maxspeed");
  if (parsedMaxSpeed <= 0.0f) parsedMaxSpeed = extractValueAfterKey(lower, "speedmax");
  if (parsedMaxSpeed <= 0.0f) parsedMaxSpeed = extractValueAfterKey(lower, "max_speed");

  bool updated = false;
  if (parsedMaxDepth > 0.0f) {
    *outMaxDepthMm = parsedMaxDepth;
    updated = true;
  }
  if (parsedMaxSpeed > 0.0f) {
    *outMaxSpeedValue = parsedMaxSpeed;
    updated = true;
  }

  return updated;
}
