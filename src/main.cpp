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
#include <esp_timer.h>
#include <SPI.h>
#include "ui/ui.h"
#include <EEPROM.h>
#include "main.h"
#include <ESP32SvelteKit.h>
#include <ESPmDNS.h>
#include <M5SettingsService.h>
#include <HTTPClient.h>
#include "ArduinoJson.h"
#include <PsychicHttpServer.h>
#include <WebSocketsClient.h> // WebSocket Client Library for WebSocket
#include <StreamString.h>

#define LV_CONF_INCLUDE_SIMPLE
#include <lvgl.h>
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

#define OFF 0.0
#define ON 1.0

// Screens 

#define ST_UI_START 0
#define ST_UI_CONNECT 1
#define ST_UI_HOME 2
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

// EEPROM Area:

#define EJECT 0
#define DARKMODE 1
#define VIBRATE 2
#define LEFTY 6

bool eject_status = false;
bool dark_mode = false;
bool vibrate_mode = true;
bool touch_home = false;
bool touch_disabled = false;

// Command States
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

String patterns = "";
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

float depth_limit = 0;
float stroke_limit = 0;
float rate_limit = 0;
bool heartbeat_mode = false;
long ease_in_speed = 0;

int speedscale = 0;

String command = "STOP";
float travel;
float depth;
float stroke;
float rate;
char patternstr[20];
float sensation;
bool vibration_override;
float vibration_amplitude;
float vibration_frequency;

float torqe_f = 100.0;
float torqe_r = -180.0;
float cum_time = 0.0;
float cum_speed = 0.0;
float cum_size = 0.0;
float cum_accel = 0.0;

ESP32Encoder encoder1;
ESP32Encoder encoder2;
ESP32Encoder encoder3;
ESP32Encoder encoder4;

// Variable to store if sending data was successful
String success;


String OSSM_IP = "0.0.0.0";
int mdnsid = 0;
String mdnstable;
unsigned long  sendforheartbeat = 100;
unsigned long nextsendtime= 0;
bool sendnow = false;

WebSocketsClient webSocket; // websocket client class instance
StaticJsonDocument<100> docws; // Allocate a static JSON document

bool Ossm_paired = false;

#define HEARTBEAT_INTERVAL 5000/portTICK_PERIOD_MS	// 5 seconds



// Bool

bool EJECT_On = false;
bool OSSM_On = false;

#define EEPROM_SIZE 200

// Tasks:

TaskHandle_t wsRemote_t  = nullptr;  // Wsebsocket Remote task
void wsRemoteTask(void *pvParameters); // Wsebsocket Remote task
bool connectbtn(); //Handels Connectbtn
int64_t touchmenue();
void vibrate();
void mxclick();
bool mxclick_short_waspressed = false;
void mxlong();
bool mxclick_long_waspressed = false;
void click2();
bool click2_short_waspressed = false;
void click3();
bool click3_short_waspressed = false;

PsychicHttpServer server;
ESP32SvelteKit esp32sveltekit(&server, 115);
M5SettingsService m5SettingsService =
    M5SettingsService(&server, esp32sveltekit.getFS(), esp32sveltekit.getSecurityManager());

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

  if ( count == 0 ) {
    data->state = LV_INDEV_STATE_RELEASED;
  } else {
    auto touch = M5.Touch.getDetail(0);
    data->state = LV_INDEV_STATE_PRESSED; 
    data->point.x = touch.x;
    data->point.y = touch.y;
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

void connectbutton(lv_event_t * e)
{
  int connectid = lv_roller_get_selected(ui_connect_roller);
  OSSM_IP = MDNS.IP(connectid).toString();
  LogDebug(OSSM_IP);
  HTTPClient http;
  String serverpath = "http://" + OSSM_IP + "/rest/environment";
  http.begin(serverpath.c_str());
  int httpResponseCode = http.GET();
  String payload = http.getString();
     // Check if http.GET() returns an error
  if (httpResponseCode = HTTP_CODE_OK) {
      LogDebug(http.errorToString(httpResponseCode));
      LogDebug(payload);
      http.end();
      StaticJsonDocument<256> doc;
      deserializeJson(doc, payload);
      travel = doc["travel"];
      JsonArray patternsarray = doc["patterns"];
      String patterns;
      for (int i = 0; i < patternsarray.size(); ++i) {
        patterns = patterns + patternsarray[i].as<String>() + "\n";
      }
      Serial.println(patterns);
      serverpath = "http://" + OSSM_IP + "/rest/safety";
      http.begin(serverpath.c_str());
      httpResponseCode = http.GET();
      LogDebug(httpResponseCode);

      payload = http.getString();
      LogDebug(payload);
      http.end();
      deserializeJson(doc, payload);
      depth_limit = doc["depth_limit"];
      stroke_limit = doc["stroke_limit"];
      rate_limit = doc["rate_limit"];
      heartbeat_mode = doc["heartbeat_mode"];
      ease_in_speed = doc["ease_in_speed"];
      LogDebug(travel);
      LogDebug(heartbeat_mode);
      LogDebug(ease_in_speed);
      LogDebug(travel);
      LogDebug(rate_limit);
      LogDebug(patterns);
      webSocket.begin(OSSM_IP, 80, "/ws/control");
      webSocket.setReconnectInterval(5000);
      Ossm_paired = true;
      vTaskResume(wsRemote_t);
  } else {
    LogDebug(http.errorToString(httpResponseCode));
    http.end();
  }
}

void savesettings(lv_event_t * e)
{
	if(lv_obj_get_state(ui_ejectaddon) == 1){
		eject_status = true;
	} else if(lv_obj_get_state(ui_ejectaddon) == 0){
		eject_status = false;
	}
  if(lv_obj_get_state(ui_darkmode) == 1){
		dark_mode = true;
	} else if(lv_obj_get_state(ui_darkmode) == 0){
		dark_mode = false;
	}
    if(lv_obj_get_state(ui_vibrate) == 1){
  		vibrate_mode = true;
  	} else if(lv_obj_get_state(ui_vibrate) == 0){
  		vibrate_mode = false;
  	}
    if(lv_obj_get_state(ui_lefty) == 1){
      touch_home = true;
    } else if(lv_obj_get_state(ui_lefty) == 0){
      touch_home = false;
    }

    //m5SettingsService.callUpdateHandlers();
    
    delay(100);
    ESP.restart();

}

void scanmdns(lv_event_t * e)
{
  LogDebug("Scanning for services");
  lv_obj_remove_flag(ui_connect_spinner, LV_OBJ_FLAG_HIDDEN);
  int timeout = 0;
  while (mdnsid == 0 & timeout < 20) {
    mdnsid = MDNS.queryService(ServiceName, "tcp");
    timeout++;
  }
  if (mdnsid == 0) {
        LogDebug("no services found");
        mdnstable = "no services found";
    } else {
        mdnstable = "";
        LogDebug(mdnsid);
        LogDebug(" service(s) found");
        for (int i = 0; i < mdnsid; ++i) {
            // Print details for each service found
            String Hostname = MDNS.hostname(i).c_str();
            String IP = MDNS.IP(i).toString();
            mdnstable = mdnstable + " "+ Hostname + " " + IP + "\n";
            LogDebug("  ");
            LogDebug(i + 1);
            LogDebug(": ");
            LogDebug(MDNS.hostname(i));
            LogDebug(" (");
            LogDebug(MDNS.IP(i));
        }
        const char* mdnstable_cstr = mdnstable.c_str();
        lv_obj_add_flag(ui_connect_spinner, LV_OBJ_FLAG_HIDDEN);
        lv_roller_set_options(ui_connect_roller, mdnstable_cstr, LV_ROLLER_MODE_NORMAL); 
        lv_obj_remove_state(ui_ConnectButtonR, LV_STATE_DISABLED);
   }
}

void sendws()
{
  StreamString data;

}

void wsRemoteTask(void *pvParameters){
  for(;;){
      if (Ossm_paired == true ) {     
       if(millis() >= nextsendtime){
       String jsonPayload = "{\"command\":\"" + String(command) + "\",\"depth\":\"" + String(depth) + "\",\"stroke\":\"" + String(stroke) + "\",\"rate\":\"" + String(rate) + "\",\"patterns\":\"" + String(pattern) + "\",\"vibration_override\":\"" + String(vibration_override) + "\",\"vibration_amplitude\":\"" + String(vibration_amplitude) + "\",\"vibration_frequency\":\"" + String(vibration_frequency) + "\"}";
       webSocket.sendTXT(jsonPayload);
       nextsendtime = millis() + sendforheartbeat;
     }
     }
  }
}

void demo(lv_event_t * e){
  rate_limit = 200;
  depth_limit = 140;
}

void screenmachine(lv_event_t * e)
{
  if (lv_scr_act() == ui_Start){
    st_screens = ST_UI_START;
  } else if(lv_scr_act() == ui_Connect){
    st_screens = ST_UI_CONNECT;
   } else if (lv_scr_act() == ui_Home){
    st_screens = ST_UI_HOME;
    rate = lv_slider_get_value(ui_homespeedslider);
    speedenc =  fscale(0, rate_limit, 0, Encoder_MAP, rate, 0);
    encoder1.setCount(speedenc); 

    depth = lv_slider_get_value(ui_homedepthslider);       
    depthenc =  fscale(0, depth_limit, 0, Encoder_MAP, depth, 0);
    encoder2.setCount(depthenc);
            
    stroke = lv_slider_get_value(ui_homestrokeslider);    
    strokeenc =  fscale(0, depth_limit, 0, Encoder_MAP, stroke, 0);
    encoder3.setCount(strokeenc);

    sensation = lv_slider_get_value(ui_homesensationslider);
    sensationenc =  fscale(-100, 100, (Encoder_MAP/2*-1), (Encoder_MAP/2), sensation, 0);
    encoder4.setCount(sensationenc);        
            
  } else if (lv_scr_act() == ui_Menue){
    st_screens = ST_UI_MENUE;
  } else if (lv_scr_act() == ui_Pattern){
    st_screens = ST_UI_PATTERN;
    const char* patterns_cstr = patterns.c_str();
    lv_roller_set_options(ui_PatternS, patterns_cstr, LV_ROLLER_MODE_NORMAL);
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
  if(EJECT_On == true){
    lv_obj_clear_state(ui_HomeButtonL, LV_STATE_CHECKED);
    EJECT_On = false;
  } else if(EJECT_On == false){
    lv_obj_add_state(ui_HomeButtonL, LV_STATE_CHECKED);
    EJECT_On = true;
  } 
}

void savepattern(lv_event_t * e){
  pattern = lv_roller_get_selected(ui_PatternS);
  lv_roller_get_selected_str(ui_PatternS,patternstr,0);
  lv_label_set_text(ui_HomePatternLabel,patternstr);
  LogDebug(pattern);
  sendws();
  //SendCommand(PATTERN, patterns, OSSM_ID);
}

void homebuttonmevent(lv_event_t * e){
  LogDebug("HomeButton");
  if(command == "STOP"){ 
    command = "playpattern";
  } else if(command != "STOP"){
    command = "STOP";
  }
  sendws();
}

void setupDepthInter(lv_event_t * e){
   //SendCommand(SETUP_D_I, 0.0, OSSM_ID);
}

void setupdepthF(lv_event_t * e){
    command = "depth";
}

char string[16];
uint32_t f;

void setup(){
  Serial.begin(115200);
  M5.begin(); //Init M5Core2.
  ESP_LOGI("main", "Starting Psychic HTTP Server");
  // start the framework and demo project
  esp32sveltekit.setMDNSAppName(APP_NAME);
  ESP_LOGI("main", "Starting ESP32-SvelteKit");
  // start ESP32-SvelteKit
  esp32sveltekit.begin();
  ESP_LOGI("main", "Starting LightStateService");
  m5SettingsService.begin();
  ESP_LOGI("main", "Ready");

  //M5.Axp.SetCHGCurrent(AXP192::BATTERY_CHARGE_CURRENT);
  //M5.Axp.SetLcdVoltage(3000);
  LogDebug("\n Starting");      // Start LogDebug 

  xTaskCreatePinnedToCore(wsRemoteTask,      /* Task function. */
                            "WebSocketConnection",  /* name of task. */
                            4096,               /* Stack size of task */
                            NULL,               /* parameter of the task */
                            5,                  /* priority of the task */
                            &wsRemote_t,         /* Task handle to keep track of created task */
                            0);                 /* pin task to core 0 */

  delay(200);
  vTaskSuspend(wsRemote_t);
  
  
  encoder1.attachHalfQuad(ENC_1_CLK, ENC_1_DT);
  encoder2.attachHalfQuad(ENC_2_CLK, ENC_2_DT);
  encoder3.attachHalfQuad(ENC_3_CLK, ENC_3_DT);
  encoder4.attachHalfQuad(ENC_4_CLK, ENC_4_DT);
  Button1.attachClick(mxclick);
  Button1.attachLongPressStop(mxlong);
  Button2.attachClick(click2);
  Button3.attachClick(click3);
  Button3.setDebounceMs(20);


  m5SettingsService.read([&](M5Settings &settings) {
    dark_mode = settings.darkmode;
    vibrate_mode = settings.vibrate;
    touch_home = settings.touch;
    eject_status = settings.eject;
  });

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

  static lv_color_t buf1[HOR_RES * 15]; 
  lv_display_set_buffers(display, buf1, nullptr, sizeof(buf1), LV_DISPLAY_RENDER_MODE_PARTIAL);

  indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, my_touchpad_read);
  ui_m5init();  
  
  if(eject_status == true){
  lv_obj_add_state(ui_ejectaddon, LV_STATE_CHECKED);
  lv_obj_clear_state(ui_EJECTSettingButton, LV_STATE_DISABLED);
  lv_obj_clear_state(ui_HomeButtonL, LV_STATE_DISABLED);
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
  if (!MDNS.begin("ESP32_Browser")) {
        Serial.println("Error setting up MDNS responder!");
        while(1){
            delay(500);
        }
  }

}

void loop()
{
     const int BatteryLevel = M5.Power.Axp192.getBatteryLevel();
     String BatteryValue = (String(BatteryLevel, DEC) + "%");
     const char *battVal = BatteryValue.c_str();
     const int WifiRssi = WiFi.RSSI();
     String WifiName = WiFi.SSID();
     String WifiValue = (WifiName + " " + String(WifiRssi, DEC) + " dBm");
     const char *wifiVal = WifiValue.c_str();
     lv_label_set_text(ui_connect_start, wifiVal);
     lv_label_set_text(ui_connect_connect, wifiVal);
     lv_label_set_text(ui_connect_home, wifiVal);

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
     if(WiFi.isConnected() == true){
       lv_obj_clear_state(ui_StartButtonL, LV_STATE_DISABLED);
     }
     
     M5.update();
     lv_task_handler();
     
     Button1.tick();
     Button2.tick();
     Button3.tick();

     webSocket.loop();
     

     /*if(Ossm_paired == true){
      if(sendnow == true){
        Serial.print(OSSM_IP);
        lastsendtime = millis();
        sendnow = false;
      }
     };*/


    
     switch(st_screens){
      
     case ST_UI_START:
      {
        if(click2_short_waspressed == true){
         lv_obj_send_event(ui_StartButtonL, LV_EVENT_CLICKED, NULL);
        } else if(mxclick_short_waspressed == true){
         lv_obj_send_event(ui_StartButtonM, LV_EVENT_CLICKED, NULL);
        } else if(click3_short_waspressed == true){
         lv_obj_send_event(ui_StartButtonR, LV_EVENT_CLICKED, NULL);
        }
      }
      break;

      case ST_UI_CONNECT:
      {
        if(touch_home == true){
          touch_disabled = true;
        }
        if(encoder4.getCount() > encoder4_enc + 2){
          LogDebug("next");
          uint32_t t = LV_KEY_DOWN;
          lv_obj_send_event(ui_connect_roller, LV_EVENT_KEY, &t);
          encoder4_enc = encoder4.getCount();
        } else if(encoder4.getCount() < encoder4_enc -2){
          uint32_t t = LV_KEY_UP;
          lv_obj_send_event(ui_connect_roller, LV_EVENT_KEY, &t);
          LogDebug("Preview");
          encoder4_enc = encoder4.getCount();
        }

        if(click2_short_waspressed == true){
         lv_obj_send_event(ui_ConnectButtonL, LV_EVENT_CLICKED, NULL);
        } else if(mxclick_short_waspressed == true){
         lv_obj_send_event(ui_ConnectButtonM, LV_EVENT_CLICKED, NULL);
        } else if(click3_short_waspressed == true){
         lv_obj_send_event(ui_ConnectButtonR, LV_EVENT_CLICKED, NULL);
        }
      }
      break;

      case ST_UI_HOME:
      {
        if(touch_home == true){
          touch_disabled = true;
        }
        // Encoder 1 Speed 
        if(lv_slider_is_dragged(ui_homespeedslider) == false){
          if (encoder1.getCount() != speedenc){
            lv_slider_set_value(ui_homespeedslider, rate, LV_ANIM_OFF);
            if(encoder1.getCount() <= 0){
              encoder1.setCount(0);
            } else if (encoder1.getCount() >= Encoder_MAP){
              encoder1.setCount(Encoder_MAP);
            } 
            speedenc = encoder1.getCount();
            rate = fscale(0, Encoder_MAP, 0, rate_limit, speedenc, speedscale);
            //SendCommand(SPEED, rate, OSSM_ID);
            //sendws();
          }
        } else if(lv_slider_get_value(ui_homespeedslider) != rate){
            speedenc =  fscale(0.5, rate_limit, 0, Encoder_MAP, rate, speedscale);
            encoder1.setCount(speedenc);
            rate = lv_slider_get_value(ui_homespeedslider);
            //SendCommand(SPEED, rate, OSSM_ID);
            //sendws();
        }
        char speed_v[7];
        dtostrf(rate, 6, 0, speed_v);
        lv_label_set_text(ui_homespeedvalue, speed_v);


        // Encoder2 Depth
        if(lv_slider_is_dragged(ui_homedepthslider) == false){
          if (encoder2.getCount() != depthenc){
            lv_slider_set_value(ui_homedepthslider, depth, LV_ANIM_OFF);
            if(encoder2.getCount() <= 0){
              encoder2.setCount(0);
            } else if (encoder2.getCount() >= Encoder_MAP){
              encoder2.setCount(Encoder_MAP);
            } 
            depthenc = encoder2.getCount();
            depth = fscale(0, Encoder_MAP, 0, depth_limit, depthenc, 0);
            //SendCommand(DEPTH, depth, OSSM_ID);
            //sendws();
          }
        } else if(lv_slider_get_value(ui_homedepthslider) != depth){
            depthenc =  fscale(0, depth_limit, 0, Encoder_MAP, depth, 0);
            encoder2.setCount(depthenc);
            depth = lv_slider_get_value(ui_homedepthslider);
            //SendCommand(DEPTH, depth, OSSM_ID);
            //sendws();
        }
        char depth_v[7];
        dtostrf(depth, 6, 0, depth_v);
        lv_label_set_text(ui_homedepthvalue, depth_v);
        

        // Encoder3 Stroke
        if(lv_slider_is_dragged(ui_homestrokeslider) == false){
          if (encoder3.getCount() != strokeenc){
            lv_slider_set_value(ui_homestrokeslider, stroke, LV_ANIM_OFF);
            if(encoder3.getCount() <= 0){
              encoder3.setCount(0);
            } else if (encoder3.getCount() >= Encoder_MAP){
              encoder3.setCount(Encoder_MAP);
            } 
            strokeenc = encoder3.getCount();
            stroke = fscale(0, Encoder_MAP, 0, depth_limit, strokeenc, 0);
            //SendCommand(STROKE, stroke, OSSM_ID);
            //sendws();
          }
        } else if(lv_slider_get_value(ui_homestrokeslider) != stroke){
            strokeenc =  fscale(0, depth_limit, 0, Encoder_MAP, stroke, 0);
            encoder3.setCount(strokeenc);
            stroke = lv_slider_get_value(ui_homestrokeslider);
           // SendCommand(STROKE, stroke, OSSM_ID);
           //sendws();
        }
        char stroke_v[7];
        dtostrf(stroke, 6, 0, stroke_v);
        lv_label_set_text(ui_homestrokevalue, stroke_v);

        // Encoder4 Senstation
        if(lv_slider_is_dragged(ui_homesensationslider) == false){
          if (encoder4.getCount() != sensationenc){
            lv_slider_set_value(ui_homesensationslider, sensation, LV_ANIM_OFF);
            if(encoder4.getCount() <= (Encoder_MAP/2*-1)){
              encoder4.setCount((Encoder_MAP/2*-1));
            } else if (encoder4.getCount() >= (Encoder_MAP/2)){
              encoder4.setCount((Encoder_MAP/2));
            } 
            sensationenc = encoder4.getCount();
            sensation = fscale((Encoder_MAP/2*-1), (Encoder_MAP/2), -100, 100, sensationenc, 0);
            //SendCommand(SENSATION, sensation, OSSM_ID);
            //sendws();
          }
        } else if(lv_slider_get_value(ui_homesensationslider) != sensation){
            sensationenc =  fscale(-100, 100, (Encoder_MAP/2*-1), (Encoder_MAP/2), sensation, 0);
            encoder4.setCount(sensationenc);
            sensation = lv_slider_get_value(ui_homesensationslider);
            //SendCommand(SENSATION, sensation, OSSM_ID);
            //sendws();
        }

        if(click2_short_waspressed == true){
          lv_obj_send_event(ui_HomeButtonL, LV_EVENT_CLICKED, NULL);
        } else if(mxclick_short_waspressed == true){
         lv_obj_send_event(ui_HomeButtonM, LV_EVENT_CLICKED, NULL);
        } else if(click3_short_waspressed == true){
         lv_obj_send_event(ui_HomeButtonR, LV_EVENT_CLICKED, NULL);
        }
        

      }
      break;

      case ST_UI_MENUE:
      {
        if(touch_home == true){
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
         lv_obj_send_event((lv_obj_t*)ui_MenueButtonL, LV_EVENT_CLICKED,NULL);
        } else if(mxclick_short_waspressed == true){
         lv_obj_send_event((lv_obj_t*)ui_MenueButtonM, LV_EVENT_CLICKED, NULL);
        } else if(click3_short_waspressed == true){
         lv_obj_send_event((lv_obj_t*)ui_MenueButtonR, LV_EVENT_CLICKED, NULL);
        }
      }
      break;

      case ST_UI_PATTERN:
      {
        if(touch_home == true){
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
        if(touch_home == true){
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
            //SendCommand(TORQE_F, torqe_f, OSSM_ID);
            sendws();
          }
        } else if(lv_slider_get_value(ui_outtroqeslider) != torqe_f){
            torqe_f_enc = fscale(50, 200, 0, Encoder_MAP, torqe_f, 0);
            encoder1.setCount(torqe_f_enc);
            torqe_f = lv_slider_get_value(ui_outtroqeslider);
            //SendCommand(TORQE_F, torqe_f, OSSM_ID);
            sendws();
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
            //SendCommand(TORQE_R, torqe_r, OSSM_ID);
            sendws();
          }
        } else if(lv_slider_get_value(ui_introqeslider) != torqe_r){
            torqe_r_enc = fscale(20, 200, 0, Encoder_MAP, torqe_r, 0);
            encoder4.setCount(torqe_r_enc);
            torqe_r = lv_slider_get_value(ui_introqeslider);
            //SendCommand(TORQE_R, torqe_r, OSSM_ID);
            sendws();
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
        if(touch_home == true){
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

      case ST_UI_SETTINGS:
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

void vibrate(){
    if(vibrate_mode == true){
    M5.Power.setVibration(255);
    //M5.Power.Axp192.setLDO3(true);
    //M5.Power.Axp192.setLDO3(false);
    M5.Power.setVibration(0);
    }
}

void mxclick() {
  vibrate();
  mxclick_short_waspressed = true;
  LogDebug("mxclick");
} 

void mxlong(){
  vibrate();
  mxclick_long_waspressed = true;
  LogDebug("mxlong");
} 

void click2() {
  vibrate();
  click2_short_waspressed = true;
  LogDebug("click2");
} // click1

void click3() {
  vibrate();
  click3_short_waspressed = true;
  LogDebug("click3");
} // click1