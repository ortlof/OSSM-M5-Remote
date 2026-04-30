#pragma GCC optimize ("Ofast")
#include <M5Unified.h>
#include <ESP32Encoder.h>
#include <esp_now.h>
#include <WiFi.h>
#include <PatternMath.h>
#include "OneButton.h"          //For Button Debounce and Longpress
#include "config.h"
#include <Arduino.h>
#include <Wire.h>
#include <lvgl.h>
#include <SPI.h>
#include "ui/ui.h"
#include "main.h"
#include "Preferences.h"      //EEPROM replacement function
#include "OssmBLE.h"
#include "language.h"
#include <esp_timer.h>

constexpr int32_t HOR_RES=320;
constexpr int32_t VER_RES=240;

///////////////////////////////////////////
////
////  To Debug or not to Debug
////
///////////////////////////////////////////

// Uncomment the following line if you wish to print DEBUG info
#define DEBUG 

#ifdef DEBUG
#define LogDebug(...) Serial.println(__VA_ARGS__)
#define LogDebugFormatted(...) Serial.printf(__VA_ARGS__)
#else
#define LogDebug(...) ((void)0)
#define LogDebugFormatted(...) ((void)0)
#endif

#define OFF 0
#define ON 1

// Screens 

#define ST_UI_START 0
#define ST_UI_HOME 1

#define ST_UI_MENUE 10
#define ST_UI_PATTERN 11
#define ST_UI_Torqe 12
#define ST_UI_EJECTSETTINGS 13

#define ST_UI_SETTINGS 20

int st_screens = ST_UI_START;



// Menü States

#define CONNECT 0
#define HOME 1
#define MENUE 2
#define MENUE2 3
#define TORQE 4
#define PATTERN_MENUE 5
#define PATTERN_MENUE2 6
#define PATTERN_MENUE3 7
#define CUM_MENUE 20

int menuestatus = CONNECT;

// EEPROM replacement function using Non-volatie memory (NVS)
Preferences m5prf; //initiate an instance of the Preferences library

bool eject_status = false;
bool dark_mode = false;
bool vibrate_mode = true;
bool touch_home = false;
bool touch_disabled = false;

// Command States
#undef OFF
#undef ON
#undef CONNECT
#define CONN 0
#define SPEED 1
#define DEPTH 2
#define STROKE 3
#define SENSATION 4
#define PATTERN 5
#define TORQE_F 6
#define TORQE_R 7
#define OFF 10
#define ON  11
#define SETUP_D_I 12
#define SETUP_D_I_F 13
#define REBOOT 14

#define CUMSPEED 20
#define CUMTIME 21
#define CUMSIZE   22
#define CUMACCEL  23

#define CONNECT 88
#define HEARTBEAT 99

int displaywidth;
int displayheight;
int progheight = 30;
int distheight = 10;
int S1Pos;
int S2Pos;
int S3Pos;
int S4Pos;
bool rstate = false;
int pattern = 2;
char patternstr[20];
bool onoff = false;


long speedenc = 0;
long depthenc = 0;
long strokeenc = 0;
long sensationenc = 0;
long torqe_f_enc = 0;
long torqe_r_enc = 0;
long cum_t_enc = 0;
long cum_si_enc =0;
long cum_s_enc = 0;
long cum_a_enc = 0;
long encoder4_enc = 0;

float maxdepthinmm = 400.0;
float speedlimit = 300;
int speedscale = -5;

float speed = 0.0;
float depth = 0.0;
float stroke = 0.0;
float sensation = 0.0;
float torqe_f = 100.0;
float torqe_r = -180.0;
float cum_time = 0.0;
float cum_speed = 0.0;
float cum_size = 0.0;
float cum_accel = 0.0;

unsigned long nowMs;
unsigned long rampMs = 0;
bool rampEnabled = true;
int rampValue = 1;
int rampTime = 75;
int maxRamp = 8;
int encId = 0;
int activeEncId = 0;

bool dynamicStroke = false;

ESP32Encoder encoder1;
ESP32Encoder encoder2;
ESP32Encoder encoder3;
ESP32Encoder encoder4;

// Variable to store if sending data was successful
String success;

float out_esp_speed;
float out_esp_depth;
float out_esp_stroke;
float out_esp_sensation;
float out_esp_pattern;
bool out_esp_rstate;
bool out_esp_connected;
int out_esp_command;
float out_esp_value;
int out_esp_target;

float incoming_esp_speed;
float incoming_esp_depth;
float incoming_esp_stroke;
float incoming_esp_sensation;
float incoming_esp_pattern;
bool incoming_esp_rstate;
bool incoming_esp_connected;
bool incoming_esp_heartbeat;
int incoming_esp_target;

typedef struct struct_message {
  float esp_speed;
  float esp_depth;
  float esp_stroke;
  float esp_sensation;
  float esp_pattern;
  bool esp_rstate;
  bool esp_connected;
  bool esp_heartbeat;
  int esp_command;
  float esp_value;
  int esp_target;
} struct_message;

bool Ossm_paired = false;

struct_message outgoingcontrol;
struct_message incomingcontrol;

esp_now_peer_info_t peerInfo;
uint8_t OSSM_Address[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}; // Broadcast to all ESP32s, upon connection gets updated to the actual address

#define HEARTBEAT_INTERVAL 5000/portTICK_PERIOD_MS	// 5 seconds

// Bool

bool EJECT_On = false;
bool OSSM_On = false;

// Tasks:

TaskHandle_t eRemote_t  = nullptr;  // Esp Now Remote Task

void espNowRemoteTask(void *pvParameters); // Handels the EspNow Remote
bool connectbtn(); //Handels Connectbtn
int64_t touchmenue();
bool SendCommand(int Command, float Value, int Target);

// Makes vibration motor go Brrrrr
void vibrate(int vbr_Intensity = 200, int vbr_Length = 100){
    if(lv_obj_has_state(ui_vibrate, LV_STATE_CHECKED) == 1){
      M5.Power.setVibration(vbr_Intensity);
      vTaskDelay(vbr_Length);
      M5.Power.setVibration(0);
    }
}

void mxclick();
bool mxclick_short_waspressed = false;
void mxlong();
bool mxclick_long_waspressed = false;
void click2();
bool click2_short_waspressed = false;
void click3();
bool click3_short_waspressed = false;
void c3long();
bool click3_long_waspressed = false;
void c3double();
bool click3_double_waspressed = false;


static int getRampedDetentDelta(int encoderId, int detents)
{
  if (detents == 0) return 0;
  if (!rampEnabled) {
    rampValue = 1;
    activeEncId = encoderId;
    rampMs = millis();
    return detents;
  }
  unsigned long now = millis();
  bool sameEncoder = (encoderId == activeEncId);
  bool withinRampWindow = ((now - rampMs) <= (unsigned long)rampTime);
  if (!sameEncoder || !withinRampWindow) {
    rampValue = 1;
  }
  int sign = (detents > 0) ? 1 : -1;
  int steps = abs(detents);
  int delta = 0;
  for (int i = 0; i < steps; ++i) {
    delta += sign * rampValue;
    if (rampValue < maxRamp) ++rampValue;
  }
  activeEncId = encoderId;
  rampMs = now;
  return delta;
}

lv_display_t *display;
lv_indev_t *indev;

static lv_draw_buf_t *draw_buf1;
static lv_draw_buf_t *draw_buf2;

// Display flushing
void my_display_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  lv_draw_sw_rgb565_swap(px_map, w*h);
  M5.Display.pushImageDMA<uint16_t>(area->x1, area->y1, w, h, (uint16_t *)px_map);
  lv_disp_flush_ready(disp);
}

uint32_t my_tick_function() {
  return (esp_timer_get_time() / 1000LL);
}

void my_touchpad_read(lv_indev_t * drv, lv_indev_data_t * data) {
  M5.update();
  auto count = M5.Touch.getCount();

  if(touch_disabled != true){
    if ( count == 0 ) {
      data->state = LV_INDEV_STATE_RELEASED;
    } else {
      auto touch = M5.Touch.getDetail(0);
      data->state = LV_INDEV_STATE_PRESSED; 
      data->point.x = touch.x;
      data->point.y = touch.y;
    }
}
}

static void event_cb(lv_event_t *e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *label = reinterpret_cast<lv_obj_t *>(lv_event_get_user_data(e));

  switch (code)
  {
  case LV_EVENT_PRESSED:
    lv_label_set_text(label, "The last button event:\nLV_EVENT_PRESSED");
    break;
  case LV_EVENT_CLICKED:
    lv_label_set_text(label, "The last button event:\nLV_EVENT_CLICKED");
    break;
  case LV_EVENT_LONG_PRESSED:
    lv_label_set_text(label, "The last button event:\nLV_EVENT_LONG_PRESSED");
    break;
  case LV_EVENT_LONG_PRESSED_REPEAT:
    lv_label_set_text(label, "The last button event:\nLV_EVENT_LONG_PRESSED_REPEAT");
    break;
  default:
    break;
  }
}

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
}

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&incomingcontrol, incomingData, sizeof(incomingcontrol));



  
  if(incomingcontrol.esp_target == M5_ID && Ossm_paired == false){

    // Remove the existing peer (0xFF:0xFF:0xFF:0xFF:0xFF:0xFF)
    esp_err_t result = esp_now_del_peer(peerInfo.peer_addr);

    if (result == ESP_OK) {

      memcpy(OSSM_Address, mac, 6); //get the mac address of the sender
      
      // Add the new peer
      memcpy(peerInfo.peer_addr, OSSM_Address, 6);
      if (esp_now_add_peer(&peerInfo) == ESP_OK) {
        LogDebugFormatted("New peer added successfully, OSSM addresss : %02X:%02X:%02X:%02X:%02X:%02X\n", OSSM_Address[0], OSSM_Address[1], OSSM_Address[2], OSSM_Address[3], OSSM_Address[4], OSSM_Address[5]);
        Ossm_paired = true;
        lv_label_set_text(ui_Welcome, T_ESPCONNECTED);
      }
      else {
        LogDebug("Failed to add new peer");
      }
    }
    else {
      LogDebug("Failed to remove peer");
    }

    
    if(incomingcontrol.esp_speed > speedlimit){
      speedlimit = 300;
    } else (
    speedlimit = incomingcontrol.esp_speed);
    LogDebug(speedlimit);
    maxdepthinmm = incomingcontrol.esp_depth;
    LogDebug(maxdepthinmm);
    pattern = incomingcontrol.esp_pattern;
    LogDebug(pattern);
    outgoingcontrol.esp_target = OSSM_ID;
    
    result = esp_now_send(OSSM_Address, (uint8_t *) &outgoingcontrol, sizeof(outgoingcontrol));
    LogDebug(result);
    
    if (result == ESP_OK) {
      Ossm_paired = true;
      lv_label_set_text(ui_connect, "Connected");
      lv_scr_load_anim(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON,20,0,false);
    }
  }

  // Update limits from post-homing OSSM packets.
  // The OSSM sends speed=0 before homing, then sends the real max speed once homing
  // is complete. Because Ossm_paired is already true by then, the block above is
  // skipped – so we catch those updates here instead.
  if (incomingcontrol.esp_target == M5_ID && Ossm_paired == true && !OssmBleIsMode()) {
    if (incomingcontrol.esp_speed > 0) {
      //speedlimit = (incomingcontrol.esp_speed > 300) ? 300.0f : incomingcontrol.esp_speed;
      if (st_screens == ST_UI_HOME) {
        lv_slider_set_range(ui_homespeedslider, 0, incomingcontrol.esp_speed);
      }
    }
    if (incomingcontrol.esp_depth > 0) {
      maxdepthinmm = incomingcontrol.esp_depth;
      if (st_screens == ST_UI_HOME) {
        lv_slider_set_range(ui_homedepthslider, 0, maxdepthinmm);
        lv_slider_set_range(ui_homestrokeslider, 0, maxdepthinmm);
      }
    }
  }

  switch(incomingcontrol.esp_command)
    {
    case OFF: 
    {
    OSSM_On = false;
    }
    break;
    case ON:
    {
    OSSM_On = true;
    }
    break;
    }
}

//Sends Commands and Value to Remote device returns ture or false if sended
bool SendCommand(int Command, float Value, int Target){
  if(Target == OSSM_ID && OssmBleIsMode()){
    // Safety rule: when speed is set while depth or stroke is zero on screen,
    // force depth/stroke zero first to avoid stale OSSM-side values.
    if (Command == SPEED && (depth <= 0.5f || stroke <= 0.5f)) {
      OssmBleSendCommand(DEPTH, 0, speed, maxdepthinmm, speedlimit, nullptr);
      OssmBleSendCommand(STROKE, 0, speed, maxdepthinmm, speedlimit, nullptr);
    }

    String response;
    bool ok = OssmBleSendCommand(Command, Value, speed, maxdepthinmm, speedlimit, &response);
    if (response.length() > 0) {
      LogDebug("BLE response:");
      LogDebug(response);
    }
    return ok;
  }

  if(Ossm_paired == true){

    outgoingcontrol.esp_connected = true;
    outgoingcontrol.esp_command = Command;
    outgoingcontrol.esp_value = Value;
    outgoingcontrol.esp_target = Target;
    esp_err_t result = esp_now_send(OSSM_Address, (uint8_t *) &outgoingcontrol, sizeof(outgoingcontrol));
  
    if (result == ESP_OK) {
      return true;
    } 
    else {
      delay(20);
      esp_now_send(OSSM_Address, (uint8_t *) &outgoingcontrol, sizeof(outgoingcontrol));
      return false;
    }
  }

  return false;
}

void connectbutton(lv_event_t * e)
{
    lv_label_set_text(ui_Welcome, T_CONNECTING);

    if(!Ossm_paired){
      OssmBleSetMode(false);

      outgoingcontrol.esp_command = HEARTBEAT;
      outgoingcontrol.esp_heartbeat = true;
      outgoingcontrol.esp_target = OSSM_ID;
      esp_now_send(OSSM_Address, (uint8_t *) &outgoingcontrol, sizeof(outgoingcontrol));

      bool bleConnected = OssmBleTryConnect();
      if (bleConnected) {
        lv_label_set_text(ui_Welcome, T_BLECONNECTED);

        OssmBleSetMode(true);
        Ossm_paired = true;
        OssmBlePrepareStrokeEngine();
        //lv_label_textall
        lv_label_set_text(ui_connect, "BLE");
        lv_scr_load_anim(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON,20,0,false);
      }
      return;
    }

    if (OssmBleIsMode()) {
      lv_label_set_text(ui_connect, "BLE");
      lv_scr_load_anim(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON,20,0,false);
    }
}

void savesettings(lv_event_t * e)
{

  m5prf.begin("m5-ctnr", false); //open NVS-storage container/session. False means that it's used it in read+write mode. Set true to open or create the namespace in read-only mode.

  if(lv_obj_has_state(ui_vibrate, LV_STATE_CHECKED) == 1){
    m5prf.putBool("Vibrate", true); //NSV-storage write true to key "Vibrate"
	}else if(lv_obj_has_state(ui_vibrate, LV_STATE_CHECKED) == 0){
    m5prf.putBool("Vibrate", false);
	}

  if(lv_obj_has_state(ui_lefty, LV_STATE_CHECKED) == 1){
    m5prf.putBool("Lefty", true); // ui_lefty in SL-Studio code is actually Touch-enable toggle
	}else if(lv_obj_has_state(ui_lefty, LV_STATE_CHECKED) == 0){
    m5prf.putBool("Lefty", false);
	}

	if(lv_obj_has_state(ui_ejectaddon, LV_STATE_CHECKED) == 1){
    m5prf.putBool("ejectAddon", true);  
	}else if(lv_obj_has_state(ui_ejectaddon, LV_STATE_CHECKED) == 0){
    m5prf.putBool("ejectAddon", false);
	}

  //read darkmode saved setting to force reboot for theme change
  bool theme_Change_Previous = false;
  bool theme_Change_New = false;
  theme_Change_Previous = m5prf.getBool("Darkmode", true);

  if(lv_obj_has_state(ui_darkmode, LV_STATE_CHECKED) == 1){
    theme_Change_New = true;
    m5prf.putBool("Darkmode", true);
	}else if(lv_obj_has_state(ui_darkmode, LV_STATE_CHECKED) == 0){
    theme_Change_New = false;
    m5prf.putBool("Darkmode", false);
	}

  m5prf.end(); //close storage container/session.
  delay(100);

  if(theme_Change_Previous != theme_Change_New){
    vibrate(225,75);
    ESP.restart(); //reboot is only required to change themes, you don't need to restart for settings to save with NVS.
  }else{
    vibrate(225,75);
  }
}

void screenmachine(lv_event_t * e)
{
  if (lv_scr_act() == ui_Start){
    st_screens = ST_UI_START;
  } else if (lv_scr_act() == ui_Home){
    st_screens = ST_UI_HOME;
    speed = lv_slider_get_value(ui_homespeedslider);
    LogDebug(speedenc);
    LogDebug(speed);

    if (OssmBleIsMode()) {
      lv_slider_set_range(ui_homespeedslider, 0, 100);
      lv_slider_set_range(ui_homedepthslider, 0, 100);
      lv_slider_set_range(ui_homestrokeslider, 0, 100);
    } else {
      lv_slider_set_range(ui_homespeedslider, 0, speedlimit);
      lv_slider_set_range(ui_homedepthslider, 0, maxdepthinmm);
      lv_slider_set_range(ui_homestrokeslider, 0, maxdepthinmm);
    }

            
  } else if (lv_scr_act() == ui_Menue){
    st_screens = ST_UI_MENUE;
  } else if (lv_scr_act() == ui_Pattern){
    st_screens = ST_UI_PATTERN;
  } else if (lv_scr_act() == ui_Torqe){
    st_screens = ST_UI_Torqe;
    torqe_f = lv_slider_get_value(ui_outtroqeslider);
    torqe_f_enc = fscale(50, 200, 0, Encoder_MAP, torqe_f, 0);
    encoder1.setCount(torqe_f_enc);

    torqe_r = lv_slider_get_value(ui_introqeslider);
    torqe_r_enc = fscale(20, 200, 0, Encoder_MAP, torqe_r, 0);
    encoder4.setCount(torqe_r_enc);

  } else if (lv_scr_act() == ui_EJECTSettings){
    st_screens = ST_UI_EJECTSETTINGS;
  } else if (lv_scr_act() == ui_Settings){
    st_screens = ST_UI_SETTINGS;
  }
}

void ejectcreampie(lv_event_t * e){
  lv_obj_clear_state(ui_HomeButtonL, LV_STATE_CHECKED);
  if (eject_status == false) {
    // No eject addon: button does a pullout manoeuvre
    depth = 0;
    speed = 0;
    stroke = 0;
    SendCommand(SETUP_D_I, 0.0, OSSM_ID);
    SendCommand(DEPTH, depth, OSSM_ID);
    screenmachine(e);
  } else {
    // Eject addon enabled: toggle eject/cumpump
    if (EJECT_On == true) {
      EJECT_On = false;
      SendCommand(SETUP_D_I, 0.0, OSSM_ID);  // retract
    } else {
      EJECT_On = true;
      SendCommand(SETUP_D_I_F, 0.0, OSSM_ID); // eject forward
    }
  }
}

void savepattern(lv_event_t * e){
  pattern = lv_roller_get_selected(ui_PatternS);
  lv_roller_get_selected_str(ui_PatternS,patternstr,0);
  lv_label_set_text(ui_HomePatternLabel,patternstr);
  LogDebug(pattern);
  float patterns = pattern;
  SendCommand(PATTERN, patterns, OSSM_ID);
}

void homebuttonmevent(lv_event_t * e){
  LogDebug("HomeButton");
  if(OSSM_On == false){
    if (OssmBleIsMode()) {
      OssmBlePrepareStrokeEngine();
    }
    SendCommand(ON, 0, OSSM_ID);
    if (OssmBleIsMode()) {
      OSSM_On = true;
    }
  } else if(OSSM_On == true){
    SendCommand(OFF, 0, OSSM_ID);
    if (OssmBleIsMode()) {
      OSSM_On = false;
    }
  }
}

void setupDepthInter(lv_event_t * e){
    SendCommand(SETUP_D_I, 0, OSSM_ID);
}

void setupdepthF(lv_event_t * e){
    SendCommand(SETUP_D_I_F, 0, OSSM_ID);
}

void setup(){
  Serial.begin(115200);
  delay(50);

  auto cfg = M5.config();
  M5.begin(cfg);

  m5prf.begin("m5-ctnr", false); 
    // Loads these settings at boot
    eject_status = m5prf.getBool("ejectAddon", false); //boolean here is used if key does not exist yet
    dark_mode = m5prf.getBool("Darkmode", true);       // ^ (basically first boot defaults, saving settings surives a re-flash!)
    vibrate_mode = m5prf.getBool("Vibrate", true);
    touch_home= m5prf.getBool("Lefty", false);       // = touchcreen. There apears to be no actual lefthanded mode anywhere
  m5prf.end();

  M5.Power.setChargeCurrent(BATTERY_CHARGE_CURRENT);
  LogDebug("\n Starting");      // Start LogDebug

  WiFi.mode(WIFI_STA);
  LogDebug(WiFi.macAddress());

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
  } else {
    Serial.println("esp_now_init ok");
  }
  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_register_send_cb(OnDataSent);

  // register peer
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  // register first peer  
  memcpy(peerInfo.peer_addr, OSSM_Address, 6);
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
  }
  // Register for a callback function that will be called when data is received
  esp_now_register_recv_cb(OnDataRecv);

  xTaskCreatePinnedToCore(espNowRemoteTask,      /* Task function. */
                            "espNowRemoteTask",  /* name of task. */
                            3096,               /* Stack size of task */
                            NULL,               /* parameter of the task */
                            5,                  /* priority of the task */
                            &eRemote_t,         /* Task handle to keep track of created task */
                            0);                 /* pin task to core 0 */
  delay(200);
  
  encoder1.attachHalfQuad(ENC_1_CLK, ENC_1_DT);
  encoder2.attachHalfQuad(ENC_2_CLK, ENC_2_DT);
  encoder3.attachHalfQuad(ENC_3_CLK, ENC_3_DT);
  encoder4.attachHalfQuad(ENC_4_CLK, ENC_4_DT);
  Button1.attachClick(mxclick);
  Button1.attachLongPressStart(mxlong);
  Button2.attachClick(click2);
  Button3.attachClick(click3);
  Button3.attachLongPressStart(c3long);
  Button3.attachDoubleClick(c3double);

  // Initialize `disp_buf` display buffer with the buffer(s).
  // lv_draw_buf_init(&draw_buf, LV_HOR_RES_MAX, LV_VER_RES_MAX);
  M5.Display.setEpdMode(epd_mode_t::epd_fastest); // fastest but very-low quality.
  if (M5.Display.width() < M5.Display.height())
  { /// Landscape mode.
  M5.Display.setRotation(M5.Display.getRotation() ^ 1);
  }
  
  lv_init();
  lv_tick_set_cb(my_tick_function);

  display = lv_display_create(HOR_RES, VER_RES);
  lv_display_set_flush_cb(display, my_display_flush);

  // Force a strict alignment for LVGL draw buffer.
  static lv_color_t buf1[HOR_RES * 15] __attribute__((aligned(16)));
  lv_display_set_buffers(display, buf1, nullptr, sizeof(buf1), LV_DISPLAY_RENDER_MODE_PARTIAL);

  indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, my_touchpad_read);
  ui_init();  

  lv_obj_clear_state(ui_HomeButtonL, LV_STATE_DISABLED);
  if(eject_status == true){
  lv_obj_add_state(ui_ejectaddon, LV_STATE_CHECKED);
  lv_obj_clear_state(ui_EJECTSettingButton, LV_STATE_DISABLED);
  }
  if(dark_mode == true){
  lv_obj_add_state(ui_darkmode, LV_STATE_CHECKED);
  }
  if(vibrate_mode == true){
  lv_obj_add_state(ui_vibrate, LV_STATE_CHECKED);
  }
  if(touch_home == true){
  lv_obj_add_state(ui_lefty, LV_STATE_CHECKED);
  }
  lv_roller_set_selected(ui_PatternS,2,LV_ANIM_OFF);
  lv_roller_get_selected_str(ui_PatternS,patternstr,0);
  lv_label_set_text(ui_HomePatternLabel,patternstr);

  LogDebug("Setup complete");
}

void loop()
{

     bool changed=false;
     const int BatteryLevel = M5.Power.getBatteryLevel();
     String BatteryValue = (String(BatteryLevel, DEC) + "%");
     const char *battVal = BatteryValue.c_str();
     lv_bar_set_value(ui_Battery, BatteryLevel, LV_ANIM_OFF);
     lv_label_set_text(ui_BattValue, battVal);
     lv_bar_set_value(ui_Battery1, BatteryLevel, LV_ANIM_OFF);
     lv_label_set_text(ui_BattValue1, battVal);
     lv_bar_set_value(ui_Battery2, BatteryLevel, LV_ANIM_OFF);
     lv_label_set_text(ui_BattValue2, battVal);
     lv_bar_set_value(ui_Battery3, BatteryLevel, LV_ANIM_OFF);
     lv_label_set_text(ui_BattValue3, battVal);
     lv_bar_set_value(ui_Battery4, BatteryLevel, LV_ANIM_OFF);
     lv_label_set_text(ui_BattValue4, battVal);
     lv_bar_set_value(ui_Battery5, BatteryLevel, LV_ANIM_OFF);
     lv_label_set_text(ui_BattValue5, battVal);

     M5.update();
     lv_task_handler();
     Button1.tick();
     Button2.tick();
     Button3.tick();

     switch(st_screens){
      
     case ST_UI_START: //Menu With logo after boot
      {
        if(lv_obj_has_state(ui_lefty, LV_STATE_CHECKED) == 1){
          touch_disabled = true;
        }

        if(click2_short_waspressed == true){
         lv_obj_send_event(ui_StartButtonL, LV_EVENT_CLICKED, NULL);
        } else if(mxclick_short_waspressed == true){
         lv_obj_send_event(ui_StartButtonM, LV_EVENT_CLICKED, NULL);
        } else if(click3_short_waspressed == true){
         lv_obj_send_event(ui_StartButtonR, LV_EVENT_CLICKED, NULL);
        }
      }
      break;

      case ST_UI_HOME: //Menu with OSSM control sliders
      {
        static int lastHomeTransportMode = -1;
        int currentTransportMode = OssmBleIsMode() ? 1 : 0;
        if (lastHomeTransportMode != currentTransportMode) {
          if (currentTransportMode == 1) {
            lv_slider_set_range(ui_homespeedslider, 0, 100);
            lv_slider_set_range(ui_homedepthslider, 0, 100);
            lv_slider_set_range(ui_homestrokeslider, 0, 100);
          } else {
            lv_slider_set_range(ui_homespeedslider, 0, speedlimit);
            lv_slider_set_range(ui_homedepthslider, 0, maxdepthinmm);
            lv_slider_set_range(ui_homestrokeslider, 0, maxdepthinmm);
          }

          if (speed > lv_slider_get_max_value(ui_homespeedslider)) {
            speed = lv_slider_get_max_value(ui_homespeedslider);
          }
          if (depth > lv_slider_get_max_value(ui_homedepthslider)) {
            depth = lv_slider_get_max_value(ui_homedepthslider);
          }
          if (stroke > lv_slider_get_max_value(ui_homestrokeslider)) {
            stroke = lv_slider_get_max_value(ui_homestrokeslider);
          }

          lastHomeTransportMode = currentTransportMode;
        }

        if(lv_obj_has_state(ui_lefty, LV_STATE_CHECKED) == 1){
          touch_disabled = true;
        }

        //
        // Encoder 1 Speed 
        //
        if(lv_slider_is_dragged(ui_homespeedslider) == false){ //if knob gets rotated
          changed = false;
          lv_slider_set_value(ui_homespeedslider, speed, LV_ANIM_OFF);

          long speedCount = encoder1.getCount();
          int speedDetents = (int)(speedCount / 2);
          if (speedDetents != 0) {
            changed = true;
            speed += getRampedDetentDelta(1, speedDetents);
            encoder1.setCount(speedCount % 2);
          }

          //speed min-max bounds
          if (speed < 0){
            changed = true;
            speed = 0;
          }
          const float speedMax = OssmBleIsMode() ? 100.0f : speedlimit;
          if (speed > speedMax){
            changed = true;
            speed = speedMax;
          }
          
          //send speed
          if (changed) {
            SendCommand(SPEED, speed, OSSM_ID);
          }
        
        
        }else if (lv_slider_get_value(ui_homespeedslider) != speed){ //if slider moved
            speed = lv_slider_get_value(ui_homespeedslider);
            SendCommand(SPEED, speed, OSSM_ID);
        }
        char speed_v[12];
        if (OssmBleIsMode()) {
          snprintf(speed_v, sizeof(speed_v), "%d%%", (int)(speed + 0.5f));
        } else {
          dtostrf(speed, 6, 0, speed_v);
        }
        lv_label_set_text(ui_homespeedvalue, speed_v);

        //
        // Encoder 2 Depth 
        //
        if(lv_slider_is_dragged(ui_homedepthslider) == false){ //if knob gets rotated
          changed = false;
          lv_slider_set_value(ui_homedepthslider, depth, LV_ANIM_OFF);

          long depthCount = encoder2.getCount();
          int depthDetents = (int)(depthCount / 2);
          if (depthDetents != 0) {
            changed = true;
            int depthDelta = getRampedDetentDelta(2, depthDetents);
            depth += depthDelta;
            if (dynamicStroke == true) {
              stroke += depthDelta;
              if (stroke >= depth) stroke = depth;
            }
            encoder2.setCount(depthCount % 2);
          }

          //depth min-max bounds
          if (depth < 0){
            changed = true;
            depth = 0;
          }
          const float depthMax = OssmBleIsMode() ? 100.0f : maxdepthinmm;
          if (depth > depthMax){
            changed = true;
            depth = depthMax;
          }
          
          //send depth
          if (changed) {
            SendCommand(DEPTH, depth, OSSM_ID);
            SendCommand(STROKE, stroke, OSSM_ID);
          }
        }else if(lv_slider_get_value(ui_homedepthslider) != depth){
            depth = lv_slider_get_value(ui_homedepthslider);
            SendCommand(DEPTH, depth, OSSM_ID);
            SendCommand(STROKE, stroke, OSSM_ID);
        }
        char depth_v[12];
        if (OssmBleIsMode()) {
          snprintf(depth_v, sizeof(depth_v), "%d%%", (int)(depth + 0.5f));
        } else {
          dtostrf(depth, 6, 0, depth_v);
        }
        lv_label_set_text(ui_homedepthvalue, depth_v);
        
        //
        // Encoder 3 Stroke 
        //
        if(lv_slider_is_dragged(ui_homestrokeslider) == false){ //if knob gets rotated
          changed = false;
          lv_bar_set_start_value(ui_homestrokeslider, depth - stroke, LV_ANIM_OFF);
          lv_slider_set_value(ui_homestrokeslider, depth, LV_ANIM_OFF);


          long strokeCount = encoder3.getCount();
          int strokeDetents = (int)(strokeCount / 2);
          if (strokeDetents != 0) {
            changed = true;
            stroke += getRampedDetentDelta(3, strokeDetents);
            encoder3.setCount(strokeCount % 2);
          }

          //Stoke min-max bounds
          if (stroke < 0){
            changed = true;
            stroke = 0;
          }
          const float strokeMax = OssmBleIsMode() ? 100.0f : maxdepthinmm;
          if (stroke > strokeMax){
            changed = true;
            stroke = strokeMax;
          }
          
          //send stroke
          if (changed) {
            SendCommand(STROKE, stroke, OSSM_ID);
            SendCommand(DEPTH, depth, OSSM_ID);
          }

        } else if(lv_slider_get_left_value(ui_homestrokeslider) != depth - stroke){
            stroke = depth - lv_slider_get_left_value(ui_homestrokeslider);
            SendCommand(STROKE, stroke, OSSM_ID);
        } else if(lv_slider_get_value(ui_homestrokeslider) != depth){
            depth = lv_slider_get_value(ui_homestrokeslider);
            SendCommand(DEPTH, depth, OSSM_ID);
            SendCommand(DEPTH, depth, OSSM_ID);
        }

        char stroke_v[12];
        if (OssmBleIsMode()) {
          snprintf(stroke_v, sizeof(stroke_v), "%d%%", (int)(stroke + 0.5f));
        } else {
          dtostrf(stroke, 6, 0, stroke_v);
        }
        lv_label_set_text(ui_homestrokevalue, stroke_v);  //was lv_label_set_text(ui_homestrokevalue, stroke_v);

        //
        // Encoder4 Sensation
        //
        if(lv_slider_is_dragged(ui_homesensationslider) == false){
          changed = false;
          lv_slider_set_value(ui_homesensationslider, sensation, LV_ANIM_OFF);

          long sensationCount = encoder4.getCount();
          int sensationDetents = (int)(sensationCount / 2);
          if (sensationDetents != 0) {
            changed = true;
            sensation += 2.0f * getRampedDetentDelta(4, sensationDetents);
            encoder4.setCount(sensationCount % 2);
          }

          //Stoke min-max bounds
          if (sensation < -100){
            changed = true;
            sensation = -100;
          }
          if (sensation > 100){
            changed = true;
            sensation = 100;
          }

          if (changed) {
            SendCommand(SENSATION, sensation, OSSM_ID);
          }          
        } else if(lv_slider_get_value(ui_homesensationslider) != sensation){
            sensation = lv_slider_get_value(ui_homesensationslider);
            SendCommand(SENSATION, sensation, OSSM_ID);
        }

        if(click2_short_waspressed == true){
         lv_obj_send_event(ui_HomeButtonL, LV_EVENT_CLICKED, NULL);
        } else if(mxclick_short_waspressed == true){
         lv_obj_send_event(ui_HomeButtonM, LV_EVENT_CLICKED, NULL);
        } else if(click3_short_waspressed == true){
         lv_obj_send_event(ui_HomeButtonR, LV_EVENT_CLICKED, NULL);
        } else if(click3_long_waspressed == true){
          sensation = 0;        //reset sensation to zero
          SendCommand(SENSATION, sensation, OSSM_ID);
        }else if(click3_double_waspressed == true){
          if (dynamicStroke == false){
            dynamicStroke = true;;            /// dynamicStroke = !dynamicStroke; crashes M5 for some reason
          }else{
            dynamicStroke = false;;
          }
          if (stroke >= depth){
            stroke = depth;
          }
        }
      }
      break;

      case ST_UI_MENUE:
      {
        if(lv_obj_has_state(ui_lefty, LV_STATE_CHECKED) == 1){
          touch_disabled = true;
        }
        if(encoder4.getCount() > encoder4_enc + 2){
          LogDebug("next");
          lv_group_focus_next(ui_g_menue);
          encoder4_enc = encoder4.getCount();
        } else if(encoder4.getCount() < encoder4_enc -2){
          lv_group_focus_prev(ui_g_menue);
          LogDebug("Preview");
          encoder4_enc = encoder4.getCount();
        }

        if(click2_short_waspressed == true){
         lv_obj_send_event(ui_MenueButtonL, LV_EVENT_CLICKED, NULL);
        } else if(mxclick_short_waspressed == true){
         lv_obj_send_event(ui_MenueButtonM, LV_EVENT_CLICKED, NULL);
        } else if(click3_short_waspressed == true){
         lv_obj_send_event(lv_group_get_focused(ui_g_menue), LV_EVENT_CLICKED, NULL);
        } else if(click3_long_waspressed == true){
         SendCommand(REBOOT, 0, OSSM_ID);
        } 
      }
      break;

      case ST_UI_PATTERN:
      {
        if(lv_obj_has_state(ui_lefty, LV_STATE_CHECKED) == 1){
          touch_disabled = true;
        }
        if(encoder4.getCount() > encoder4_enc + 2){
          LogDebug("next");
          uint32_t t = LV_KEY_DOWN;
          lv_obj_send_event(ui_PatternS, LV_EVENT_KEY, &t);
          encoder4_enc = encoder4.getCount();
        } else if(encoder4.getCount() < encoder4_enc -2){
          uint32_t t = LV_KEY_UP;
          lv_obj_send_event(ui_PatternS, LV_EVENT_KEY, &t);
          LogDebug("Preview");
          encoder4_enc = encoder4.getCount();
        }
         if(click2_short_waspressed == true){
         lv_obj_send_event(ui_PatternButtonL, LV_EVENT_CLICKED, NULL);
        } else if(mxclick_short_waspressed == true){
         lv_obj_send_event(ui_PatternButtonM, LV_EVENT_CLICKED, NULL);
        } else if(click3_short_waspressed == true){
         lv_obj_send_event(ui_PatternButtonR, LV_EVENT_CLICKED, NULL);
        }
      }
      break;

      case ST_UI_Torqe:
      {
        if(lv_obj_has_state(ui_lefty, LV_STATE_CHECKED) == 1){
          touch_disabled = true;
        }
        // Encoder 1 Torqe Out
        if(lv_slider_is_dragged(ui_outtroqeslider) == false){
          if (encoder1.getCount() != torqe_f_enc){
            lv_slider_set_value(ui_outtroqeslider, torqe_f, LV_ANIM_OFF);
            if(encoder1.getCount() <= 0){
              encoder1.setCount(0);
            } else if (encoder1.getCount() >= Encoder_MAP){
              encoder1.setCount(Encoder_MAP);
            } 
            torqe_f_enc = encoder1.getCount();
            torqe_f = fscale(0, Encoder_MAP, 50, 200, torqe_f_enc, 0);
            SendCommand(TORQE_F, torqe_f, OSSM_ID);
          }
        } else if(lv_slider_get_value(ui_outtroqeslider) != torqe_f){
            torqe_f_enc = fscale(50, 200, 0, Encoder_MAP, torqe_f, 0);
            encoder1.setCount(torqe_f_enc);
            torqe_f = lv_slider_get_value(ui_outtroqeslider);
            SendCommand(TORQE_F, torqe_f, OSSM_ID);
        }
        char torqe_f_v[7];
        dtostrf((torqe_f*-1), 6, 0, torqe_f_v);
        lv_label_set_text(ui_outtroqevalue, torqe_f_v);

        // Encoder 4 Torqe IN
        if(lv_slider_is_dragged(ui_introqeslider) == false){
          if (encoder4.getCount() != torqe_r_enc){
            lv_slider_set_value(ui_introqeslider, torqe_r, LV_ANIM_OFF);
            if(encoder4.getCount() <= 0){
              encoder4.setCount(0);
            } else if (encoder4.getCount() >= Encoder_MAP){
              encoder4.setCount(Encoder_MAP);
            } 
            torqe_r_enc = encoder4.getCount();
            torqe_r = fscale(0, Encoder_MAP, 20, 200, torqe_r_enc, 0);
            SendCommand(TORQE_R, torqe_r, OSSM_ID);
          }
        } else if(lv_slider_get_value(ui_introqeslider) != torqe_r){
            torqe_r_enc = fscale(20, 200, 0, Encoder_MAP, torqe_r, 0);
            encoder4.setCount(torqe_r_enc);
            torqe_r = lv_slider_get_value(ui_introqeslider);
            SendCommand(TORQE_R, torqe_r, OSSM_ID);
        }
        char torqe_r_v[7];
        dtostrf(torqe_r, 6, 0, torqe_r_v);
        lv_label_set_text(ui_introqevalue, torqe_r_v);

         if(click2_short_waspressed == true){
         lv_obj_send_event(ui_TorqeButtonL, LV_EVENT_CLICKED, NULL);
        } else if(mxclick_short_waspressed == true){
         lv_obj_send_event(ui_TorqeButtonM, LV_EVENT_CLICKED, NULL);
        } else if(click3_short_waspressed == true){
         lv_obj_send_event(ui_TorqeButtonR, LV_EVENT_CLICKED, NULL);
        }
      }
      break;

      case ST_UI_EJECTSETTINGS:
      {
        if(lv_obj_has_state(ui_lefty, LV_STATE_CHECKED) == 1){
          touch_disabled = true;
        }
        
         if(click2_short_waspressed == true){
         lv_obj_send_event(ui_EJECTButtonL, LV_EVENT_CLICKED, NULL);
        } else if(mxclick_short_waspressed == true){
         lv_obj_send_event(ui_EJECTButtonM, LV_EVENT_CLICKED, NULL);
        } else if(click3_short_waspressed == true){
         
        }
      }
      break;

      case ST_UI_SETTINGS: //Settings Menu
      {
        touch_disabled = false;

        if(encoder4.getCount() > encoder4_enc + 2){
          LogDebug("next");
          lv_group_focus_next(ui_g_settings);
          encoder4_enc = encoder4.getCount();
        } else if(encoder4.getCount() < encoder4_enc -2){
          lv_group_focus_prev(ui_g_settings);
          LogDebug("Preview");
          encoder4_enc = encoder4.getCount();
        }

        if(click2_short_waspressed == true){
         lv_obj_send_event(ui_MenueButtonL, LV_EVENT_CLICKED, NULL);
        } else if(mxclick_short_waspressed == true){
         lv_obj_send_event(ui_MenueButtonM, LV_EVENT_CLICKED, NULL);
        } else if(click3_short_waspressed == true){
         lv_obj_send_event(ui_EJECTButtonR, LV_EVENT_CLICKED, NULL);
        }
      }
      break;

     }
     mxclick_long_waspressed = false;
     mxclick_short_waspressed = false;
     click2_short_waspressed = false;
     click3_short_waspressed = false;
     click3_long_waspressed = false;
     click3_double_waspressed = false;

  delay(5);
}

void espNowRemoteTask(void *pvParameters)
{
  for(;;){
    if(Ossm_paired && !OssmBleIsMode()){
      outgoingcontrol.esp_command = HEARTBEAT;
      outgoingcontrol.esp_heartbeat = true;
      outgoingcontrol.esp_target = OSSM_ID;
      esp_now_send(OSSM_Address, (uint8_t *) &outgoingcontrol, sizeof(outgoingcontrol));
    }
    vTaskDelay(HEARTBEAT_INTERVAL);
  }
}

/*
void cumscreentask(void *pvParameters)
{
  for(;;)
  {
    M5.Lcd.setTextColor(FrontColor);
    if(encoder1.getCount() != cum_s_enc)
    {
    cum_s_enc = encoder1.getCount();
    cum_speed = map(constrain(cum_s_enc,0,Encoder_MAP),0,Encoder_MAP,1000,30000);
    M5.Lcd.fillRect(199,S1Pos,85,30,BgColor);
    M5.Lcd.setCursor(200,S1Pos+progheight-5);
    M5.Lcd.print(cum_speed);
    SendCommand(CUMSPEED, cum_speed, CUM);
    }

  if(encoder2.getCount() != cum_t_enc)
    {
    cum_t_enc = encoder2.getCount();
    cum_time = map(constrain(cum_t_enc,0,Encoder_MAP),0,Encoder_MAP,0,60);
    M5.Lcd.fillRect(199,S2Pos,85,30,BgColor);
    M5.Lcd.setCursor(200,S2Pos+progheight-5);
    M5.Lcd.print(cum_time);
    SendCommand(CUMTIME, cum_time, CUM);
    }

   if(encoder3.getCount() != cum_si_enc)
    {
    cum_si_enc = encoder3.getCount();
    cum_size = map(constrain(cum_si_enc,0,Encoder_MAP),0,Encoder_MAP,0,40);
    M5.Lcd.fillRect(199,S3Pos,85,30,BgColor);
    M5.Lcd.setCursor(200,S3Pos+progheight-5);
    M5.Lcd.print(cum_size);
    SendCommand(CUMSIZE, cum_size, CUM);
    }

   if(encoder4.getCount() != cum_a_enc)
    {
    cum_a_enc = encoder4.getCount();
    cum_accel = map(constrain(cum_a_enc,0,Encoder_MAP),0,Encoder_MAP,0,20);
    M5.Lcd.fillRect(199,S4Pos,85,30,BgColor);
    M5.Lcd.setCursor(200,S4Pos+progheight-5);
    M5.Lcd.print(cum_accel);
    SendCommand(CUMACCEL, cum_accel, CUM);
    }
  vTaskDelay(100);
  }
}
*/


void mxclick() {
  vibrate();
  mxclick_short_waspressed = true;
} 

void mxlong(){
  vibrate(200, 200);
  mxclick_long_waspressed = true;
} 

void click2() {
  vibrate();
  click2_short_waspressed = true;
} // click2

void click3() {
  vibrate();
  click3_short_waspressed = true;
} // click3

void c3long() {
    vibrate();
  click3_long_waspressed = true;
}

void c3double() {
    vibrate();
  click3_double_waspressed = true;
}