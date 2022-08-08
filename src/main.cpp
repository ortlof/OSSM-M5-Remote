#pragma GCC optimize ("Ofast")
#include <M5Core2.h>
#include <ESP32Encoder.h>
#include <esp_now.h>
#include <WiFi.h>
#include <PatternMath.h>
#include "OneButton.h"          //For Button Debounce and Longpress
#include "config.h"
#include <Arduino.h>
#include <lvgl.h>
#include <Wire.h>
#include <SPI.h>
#include <lv_conf.h>
#include "ui/ui.h"
#include <EEPROM.h>

int screenWidth  = 320;
int screenHeight = 240;

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

// EEPROM Area:

#define EJECT 0
#define DARKMODE 1
#define VIBRATE 2
#define LEFTY 3

bool eject_status = false;
bool dark_mode = false;
bool vibrate_mode = true;
bool lefty_mode = false;

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

int displaywidth;
int displayheight;
int progheight = 30;
int distheight = 10;
int S1Pos;
int S2Pos;
int S3Pos;
int S4Pos;
bool rstate = false;
int pattern = 1;
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

float speed = 0.0;
float depth = 0.0;
float stroke = 0.0;
float sensation = 0.0;
float maxdepthinmm = 180.0;
float speedlimit = 1200;
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

float out_esp_speed;
float out_esp_depth;
float out_esp_stroke;
float out_esp_sensation;
float out_esp_pattern;
bool out_esp_rstate;
bool out_esp_connected;
int out_esp_command;
float out_esp_value;

float incoming_esp_speed;
float incoming_esp_depth;
float incoming_esp_stroke;
float incoming_esp_sensation;
float incoming_esp_pattern;
bool incoming_esp_rstate;
bool incoming_esp_connected;

typedef struct struct_message {
  float esp_speed;
  float esp_depth;
  float esp_stroke;
  float esp_sensation;
  float esp_pattern;
  bool esp_rstate;
  bool esp_connected;
  int esp_command;
  float esp_value;
} struct_message;

bool esp_connect = false;

struct_message outgoingcontrol;
struct_message incomingcontrol;

esp_now_peer_info_t peerInfo;

// Bool

bool EJECT_On = false;
bool OSSM_On = false;


#define EEPROM_SIZE 200

// Tasks:

TaskHandle_t eRemote_t  = nullptr;  // Esp Now Remote Task
TaskHandle_t torqe_t    = nullptr;
TaskHandle_t cum_t      = nullptr; 
void espNowRemoteTask(void *pvParameters); // Handels the EspNow Remote
void vibrationTask(void *pvParameters); // Handels the EspNow Remote
void torqescreentask(void *pvParameters); // Handels Torqe Settings Display
void cumscreentask(void *pvParameters); // Handels Lube Display
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

// init the tft espi
static lv_disp_draw_buf_t draw_buf;
static lv_disp_drv_t disp_drv;  // Descriptor of a display driver
static lv_indev_drv_t indev_drv; // Descriptor of a touch driver

M5Display *tft;
static lv_obj_t * kb;

void tft_lv_initialization() {
  M5.begin();
  lv_init();
  static lv_color_t buf1[(LV_HOR_RES_MAX * LV_VER_RES_MAX) / 10];  // Declare a buffer for 1/10 screen siz
  static lv_color_t buf2[(LV_HOR_RES_MAX * LV_VER_RES_MAX) / 10];  // second buffer is optionnal

  // Initialize `disp_buf` display buffer with the buffer(s).
  lv_disp_draw_buf_init(&draw_buf, buf1, buf2, (LV_HOR_RES_MAX * LV_VER_RES_MAX) / 10);

  tft = &M5.Lcd;
}

// Display flushing
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  tft->startWrite();
  tft->setAddrWindow(area->x1, area->y1, w, h);
  tft->pushColors((uint16_t *)&color_p->full, w * h, true);
  tft->endWrite();

  lv_disp_flush_ready(disp);
}

void init_disp_driver() {
  lv_disp_drv_init(&disp_drv);  // Basic initialization

  disp_drv.flush_cb = my_disp_flush;  // Set your driver function
  disp_drv.draw_buf = &draw_buf;      // Assign the buffer to the display
  disp_drv.hor_res = LV_HOR_RES_MAX;  // Set the horizontal resolution of the display
  disp_drv.ver_res = LV_VER_RES_MAX;  // Set the vertical resolution of the display

  lv_disp_drv_register(&disp_drv);                   // Finally register the driver
  lv_disp_set_bg_color(NULL, lv_color_hex3(0x000));  // Set default background color to black
}

void my_touchpad_read(lv_indev_drv_t * drv, lv_indev_data_t * data)
{
  TouchPoint_t pos = M5.Touch.getPressPoint();
  bool touched = ( pos.x == -1 ) ? false : true;  

  if(!touched) {
      data->state = LV_INDEV_STATE_RELEASED;
  } else {
    if (M5.BtnA.wasPressed()){  // tab 1 : A Button
      LogDebug("ButtonA");
      data->point.x = 80; data->point.y = 220; // mouse position x,y
      data->state =LV_INDEV_STATE_PR; M5.update();
      } else if (M5.BtnB.wasPressed()){  // tab 2 : B Button
      LogDebug("ButtonB");
      data->point.x = 160; data->point.y = 220;
      data->state =LV_INDEV_STATE_PR; M5.update();
      } else if (M5.BtnC.wasPressed()){  // tab 3 : C Button
      LogDebug("ButtonC");
      data->point.x = 270; data->point.y = 220;
      data->state =LV_INDEV_STATE_PR; M5.update();
      } else {
    data->state = LV_INDEV_STATE_PRESSED; 
    data->point.x = pos.x;
    data->point.y = pos.y;
  } 
}
}

void init_touch_driver() {
  lv_disp_drv_register(&disp_drv);

  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_t * my_indev = lv_indev_drv_register(&indev_drv);  // register
}

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
}

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&incomingcontrol, incomingData, sizeof(incomingcontrol));
  LogDebug("Bytes received: ");
  LogDebug(len);

  if(esp_connect == false && incomingcontrol.esp_connected == true){  
    speedlimit = incomingcontrol.esp_speed;
    maxdepthinmm = incomingcontrol.esp_depth;
    pattern = incomingcontrol.esp_pattern;
    outgoingcontrol.esp_connected = false;
    esp_err_t result = esp_now_send(OSSM_Address, (uint8_t *) &outgoingcontrol, sizeof(outgoingcontrol));
    LogDebug(result);
    if (result == ESP_OK) {
      esp_connect = true;
      outgoingcontrol.esp_connected = true;
      M5.Lcd.setCursor(5,20);
      M5.Lcd.setFont(&FreeSansBold9pt7b);
      M5.Lcd.setTextColor(FrontColor);
      M5.Lcd.print(T_CON);
      M5.Lcd.fillScreen(WHITE);
      delay(200);
    }
  } 
}

//Sends Commands and Value to Remote device returns ture or false if sended
bool SendCommand(int Command, float Value, int Target){
      if(esp_connect == true){
      switch (Target){
      case OSSM:
      {
      outgoingcontrol.esp_connected = true;
      outgoingcontrol.esp_command = Command;
      outgoingcontrol.esp_value = Value;
      esp_err_t result = esp_now_send(OSSM_Address, (uint8_t *) &outgoingcontrol, sizeof(outgoingcontrol));
      if (result == ESP_OK) {
      return true;
      } else {
      return false;
      }
      }
      break;
      case CUM:
      {
      outgoingcontrol.esp_connected = true;
      outgoingcontrol.esp_command = Command;
      outgoingcontrol.esp_value = Value;
      LogDebug(Command);
      LogDebug(Value);
      esp_err_t result = esp_now_send(CUM_Address, (uint8_t *) &outgoingcontrol, sizeof(outgoingcontrol));
      if (result == ESP_OK) {
      return true;
      } else {
      return false;
      } 
      break;
      }
      }
      }
}

void savesettings(lv_event_t * e)
{
	if(lv_obj_get_state(ui_ejectaddon) == 1){
		EEPROM.writeBool(EJECT,true);
	} else if(lv_obj_get_state(ui_ejectaddon) == 0){
		EEPROM.writeBool(EJECT,false);
	}
  if(lv_obj_get_state(ui_darkmode) == 1){
		EEPROM.writeBool(DARKMODE,true);
	} else if(lv_obj_get_state(ui_darkmode) == 0){
		EEPROM.writeBool(DARKMODE,false);
	}
  if(lv_obj_get_state(ui_vibrate) == 1){
		EEPROM.writeBool(VIBRATE,true);
	} else if(lv_obj_get_state(ui_vibrate) == 0){
		EEPROM.writeBool(VIBRATE,false);
	}
  if(lv_obj_get_state(ui_lefty) == 1){
		EEPROM.writeBool(LEFTY,true);
	} else if(lv_obj_get_state(ui_lefty) == 0){
		EEPROM.writeBool(LEFTY,false);
	}
  EEPROM.commit();
  delay(20);
  ESP.restart();
}

void screenmachine(lv_event_t * e)
{
  if (lv_scr_act() == ui_Start){
    st_screens = ST_UI_START;
  } else if (lv_scr_act() == ui_Home){
    st_screens = ST_UI_HOME;
    speed = lv_slider_get_value(ui_homespeedslider);
    speedenc =  fscale(0.5, speedlimit, 0, Encoder_MAP, speed, 0);
    encoder1.setCount(speedenc); 

    depth = lv_slider_get_value(ui_homedepthslider);       
    depthenc =  fscale(0, maxdepthinmm, 0, Encoder_MAP, depth, 0);
    encoder2.setCount(depthenc);
            
    stroke = lv_slider_get_value(ui_homestrokeslider);    
    strokeenc =  fscale(0, maxdepthinmm, 0, Encoder_MAP, stroke, 0);
    encoder3.setCount(strokeenc);

    sensation = lv_slider_get_value(ui_homesensationslider);
    sensationenc =  fscale(-100, 100, (Encoder_MAP/2*-1), (Encoder_MAP/2), sensation, 0);
    encoder4.setCount(sensationenc);        
            
  } else if (lv_scr_act() == ui_Menue){
    st_screens = ST_UI_MENUE;
  } else if (lv_scr_act() == ui_Pattern){
    st_screens = ST_UI_PATTERN;
  } else if (lv_scr_act() == ui_Torqe){
    st_screens = ST_UI_Torqe;
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

}

void homebuttonmevent(lv_event_t * e){
  if(OSSM_On == true){
    lv_obj_clear_state(ui_HomeButtonM, LV_STATE_CHECKED);
    OSSM_On = false;
  } else if(OSSM_On == false){
    lv_obj_add_state(ui_HomeButtonM, LV_STATE_CHECKED);
    OSSM_On = true;
  } 
}

void setup(){
  M5.begin(true, false, true, true); //Init M5Core2.
  EEPROM.begin(EEPROM_SIZE);
  M5.Axp.SetLcdVoltage(3000);
  LogDebug("\n Starting");      // Start LogDebug 
  

  xTaskCreatePinnedToCore(espNowRemoteTask,      /* Task function. */
                            "espNowRemoteTask",  /* name of task. */
                            4096,               /* Stack size of task */
                            NULL,               /* parameter of the task */
                            5,                  /* priority of the task */
                            &eRemote_t,         /* Task handle to keep track of created task */
                            0);                 /* pin task to core 0 */
  delay(100);

  xTaskCreatePinnedToCore(torqescreentask,     /* Task function. */
                            "torqescreentask", /* name of task. */
                            4096,                /* Stack size of task */
                            NULL,                /* parameter of the task */
                            1,                   /* priority of the task */
                            &torqe_t,            /* Task handle to keep track of created task */
                            0);                  /* pin task to core 0 */
  vTaskSuspend(torqe_t);

  xTaskCreatePinnedToCore(cumscreentask,     /* Task function. */
                            "cumscreentask", /* name of task. */
                            4096,                /* Stack size of task */
                            NULL,                /* parameter of the task */
                            1,                   /* priority of the task */
                            &cum_t,            /* Task handle to keep track of created task */
                            0);                  /* pin task to core 0 */
  vTaskSuspend(cum_t);

  encoder1.attachHalfQuad(ENC_1_CLK, ENC_1_DT);
  encoder2.attachHalfQuad(ENC_2_CLK, ENC_2_DT);
  encoder3.attachHalfQuad(ENC_3_CLK, ENC_3_DT);
  encoder4.attachHalfQuad(ENC_4_CLK, ENC_4_DT);
  Button1.attachClick(mxclick);
  Button1.attachLongPressStop(mxlong);
  Button2.attachClick(click2);
  Button3.attachClick(click3);

  tft_lv_initialization();
  init_disp_driver();
  init_touch_driver();

  ui_init();

  //****Load EEPROOM:
  eject_status = EEPROM.readBool(EJECT);
  dark_mode = EEPROM.readBool(DARKMODE);
  vibrate_mode = EEPROM.readBool(VIBRATE);
  lefty_mode = EEPROM.readBool(LEFTY);
  
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
  if(lefty_mode == true){
  lv_obj_add_state(ui_lefty, LV_STATE_CHECKED);
  }

  encoder4.setCount(Encoder_MAP*0.5);

}

void loop()
{
     const int BatteryLevel = M5.Axp.GetBatteryLevel();
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
      
     case ST_UI_START:
      {
        if(click2_short_waspressed == true){
         lv_event_send(ui_StartButtonL, LV_EVENT_CLICKED, NULL);
        } else if(mxclick_short_waspressed == true){
         lv_event_send(ui_StartButtonM, LV_EVENT_CLICKED, NULL);
        } else if(click3_short_waspressed == true){
         lv_event_send(ui_StartButtonR, LV_EVENT_CLICKED, NULL);
        }
      }
      break;

      case ST_UI_HOME:
      {
        // Encoder 1 Speed 
        if(lv_slider_is_dragged(ui_homespeedslider) == false){
          if (encoder1.getCount() != speedenc){
            lv_slider_set_value(ui_homespeedslider, speed, LV_ANIM_OFF);
            if(encoder1.getCount() <= 0){
              encoder1.setCount(0);
            } else if (encoder1.getCount() >= Encoder_MAP){
              encoder1.setCount(Encoder_MAP);
            } 
            speedenc = encoder1.getCount();
            speed = fscale(0, Encoder_MAP, 0, speedlimit, speedenc, 0);
          }
        } else if(lv_slider_get_value(ui_homespeedslider) != speed){
            speedenc =  fscale(0.5, speedlimit, 0, Encoder_MAP, speed, 0);
            encoder1.setCount(speedenc);
            speed = lv_slider_get_value(ui_homespeedslider);
        }
        char speed_v[7];
        dtostrf(speed, 6, 0, speed_v);
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
            depth = fscale(0, Encoder_MAP, 0, maxdepthinmm, depthenc, 0);
          }
        } else if(lv_slider_get_value(ui_homedepthslider) != depth){
            depthenc =  fscale(0, maxdepthinmm, 0, Encoder_MAP, depth, 0);
            encoder2.setCount(depthenc);
            depth = lv_slider_get_value(ui_homedepthslider);
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
            stroke = fscale(0, Encoder_MAP, 0, maxdepthinmm, strokeenc, 0);
          }
        } else if(lv_slider_get_value(ui_homestrokeslider) != stroke){
            strokeenc =  fscale(0, maxdepthinmm, 0, Encoder_MAP, stroke, 0);
            encoder3.setCount(strokeenc);
            stroke = lv_slider_get_value(ui_homestrokeslider);
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
          }
        } else if(lv_slider_get_value(ui_homesensationslider) != sensation){
            sensationenc =  fscale(-100, 100, (Encoder_MAP/2*-1), (Encoder_MAP/2), sensation, 0);
            encoder4.setCount(sensationenc);
            sensation = lv_slider_get_value(ui_homesensationslider);
        }

        if(click2_short_waspressed == true){
         lv_event_send(ui_HomeButtonL, LV_EVENT_CLICKED, NULL);
        } else if(mxclick_short_waspressed == true){
         lv_event_send(ui_HomeButtonM, LV_EVENT_CLICKED, NULL);
        } else if(click3_short_waspressed == true){
         lv_event_send(ui_HomeButtonR, LV_EVENT_CLICKED, NULL);
        }
        

      }
      break;
      case ST_UI_MENUE:
      {
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
         lv_event_send(ui_MenueButtonL, LV_EVENT_CLICKED, NULL);
        } else if(mxclick_short_waspressed == true){
         lv_event_send(ui_MenueButtonM, LV_EVENT_CLICKED, NULL);
        } else if(click3_short_waspressed == true){
         lv_event_send(lv_group_get_focused(ui_g_menue), LV_EVENT_CLICKED, NULL);
        }
      }
      break;

      case ST_UI_PATTERN:
      {
         if(click2_short_waspressed == true){
         lv_event_send(ui_PatternButtonL, LV_EVENT_CLICKED, NULL);
        } else if(mxclick_short_waspressed == true){
         lv_event_send(ui_PatternButtonM, LV_EVENT_CLICKED, NULL);
        } else if(click3_short_waspressed == true){
         lv_event_send(ui_PatternButtonR, LV_EVENT_CLICKED, NULL);
        }
      }
      break;

      case ST_UI_Torqe:
      {
         if(click2_short_waspressed == true){
         lv_event_send(ui_TorqeButtonL, LV_EVENT_CLICKED, NULL);
        } else if(mxclick_short_waspressed == true){
         lv_event_send(ui_TorqeButtonM, LV_EVENT_CLICKED, NULL);
        } else if(click3_short_waspressed == true){
         lv_event_send(ui_TorqeButtonR, LV_EVENT_CLICKED, NULL);
        }
      }
      break;

      case ST_UI_EJECTSETTINGS:
      {
         if(click2_short_waspressed == true){
         lv_event_send(ui_EJECTButtonL, LV_EVENT_CLICKED, NULL);
        } else if(mxclick_short_waspressed == true){
         lv_event_send(ui_EJECTButtonM, LV_EVENT_CLICKED, NULL);
        } else if(click3_short_waspressed == true){
         lv_event_send(ui_EJECTButtonR, LV_EVENT_CLICKED, NULL);
        }
      }
      break;

      case ST_UI_SETTINGS:
      {
         if(click2_short_waspressed == true){
         lv_event_send(ui_SettingsButtonL, LV_EVENT_CLICKED, NULL);
        } else if(mxclick_short_waspressed == true){
         lv_event_send(ui_SettingsButtonM, LV_EVENT_CLICKED, NULL);
        } else if(click3_short_waspressed == true){
         lv_event_send(ui_SettingsButtonR, LV_EVENT_CLICKED, NULL);
        }
      }
      break;    
     }
      
      /*
      if(M5.BtnC.wasReleased()) {
      outgoingcontrol.esp_connected = false;
      esp_err_t result = esp_now_send(OSSM_Address, (uint8_t *) &outgoingcontrol, sizeof(outgoingcontrol));
      vibrate();
      delay(100);
      }

      if(M5.BtnA.wasReleased()) {
      esp_connect = true;
      outgoingcontrol.esp_connected = true;
      M5.Lcd.setCursor(5,20);
      M5.Lcd.setFont(&FreeSansBold9pt7b);
      M5.Lcd.setTextColor(FrontColor);
      M5.Lcd.print(T_CON);
      M5.Lcd.fillScreen(WHITE);
      menue_state_machine(HOME);
      menuestatus = HOME;
      menueUpdate(2);
      delay(200);
      vTaskResume(home_t);
      }
      
      }
      break;
      
      case HOME:
      if(M5.BtnA.wasReleased()) {
      speedenc = encoder1.getCount();
      speed = fscale(0, Encoder_MAP, 0.5, speedlimit, constrain(speedenc,0,Encoder_MAP), -3);
      SendCommand(SPEED, speed, OSSM);
      depthenc = encoder2.getCount();
      depth = map(constrain(depthenc,0,Encoder_MAP),0,Encoder_MAP,0,maxdepthinmm);
      SendCommand(DEPTH, depth, OSSM);
      strokeenc = encoder3.getCount();
      stroke = map(constrain(strokeenc,0,maxdepthinmm),0,maxdepthinmm,0,maxdepthinmm);
      SendCommand(STROKE, stroke, OSSM);
      sensationenc = encoder4.getCount();
      sensation = map(constrain(sensationenc,0,Encoder_MAP),0,Encoder_MAP,-100,100);
      SendCommand(SENSATION, sensation, OSSM);
      SendCommand(ON, 0, OSSM);
      menueUpdate(1);
      vibrate();
      }

      if(M5.BtnB.wasReleased()) {
      menue_state_machine(MENUE);
      vibrate();
      }
  
      if(M5.BtnC.wasReleased()) {
      SendCommand(OFF, 0, OSSM);
      menueUpdate(2);
      vibrate();
      }
      break;

      case MENUE:
     {
      switch(touchmenue()){
        case 1:
        menue_state_machine(HOME);
        SendCommand(SETUP_D_I, 0, OSSM);
        updatepowerbars();
      vibrate();
        break;
        case 2:
        menue_state_machine(HOME);
        SendCommand(SETUP_D_I_F, 0, OSSM);
        updatepowerbars();
      vibrate();
        break;
        case 3:
        menue_state_machine(PATTERN_MENUE);
      vibrate();
        break;
        case 4:
        menue_state_machine(TORQE);
        vibrate();
        break;
      }
      
      if(M5.BtnA.wasReleased()) {
      menue_state_machine(CUM_MENUE);
      vibrate();
      delay(100);
      }

      if(M5.BtnB.wasReleased()) {
      menue_state_machine(HOME);
      vibrate();
      }

      if(M5.BtnC.wasReleased()) {
      menue_state_machine(MENUE2);
      }
     }
    break;

    case MENUE2:
     {
      switch(touchmenue()){
        case 1:
        vibrate();
        LogDebug("Reboot Triggerd");
        SendCommand(REBOOT, 0, OSSM);
        ESP.restart();
        break;
        case 2:
      vibrate();
        break;
        case 3:
      vibrate();
        break;
        case 4:
      vibrate();
        break;
      }

      if(M5.BtnB.wasReleased()) {
      menue_state_machine(HOME);
      vibrate();
      }
      if(M5.BtnC.wasReleased()) {
      menue_state_machine(MENUE);
      vibrate();
      }
     }
      break;

      case TORQE:
      {
      if(M5.BtnB.wasReleased()) {
      menue_state_machine(HOME);
      vibrate();
      }  
      }
      break;
      case PATTERN_MENUE:
      { 
      
      switch(touchmenue()){
        case 1:
          SendCommand(PATTERN, 0, OSSM);
          menue_state_machine(HOME);
          updatepowerbars();
          vibrate();
          break;
        case 2:
          SendCommand(PATTERN, 2, OSSM);
          menue_state_machine(HOME);
          updatepowerbars();
          vibrate();
          break;
        case 3:
          SendCommand(PATTERN, 1, OSSM);
          menue_state_machine(HOME);
          updatepowerbars();
          vibrate();
          break;
        case 4:
          SendCommand(PATTERN, 3, OSSM);
          menue_state_machine(HOME);
          updatepowerbars();
          vibrate();
          break;
      }

      if(M5.BtnB.wasReleased()) {
        menue_state_machine(HOME);
        vibrate();
      }
      if(M5.BtnC.wasReleased()) {
        menue_state_machine(PATTERN_MENUE2);
        vibrate();
      }
      }
      break;
      case PATTERN_MENUE2:
      {
      switch(touchmenue()){
        case 1:
          SendCommand(PATTERN, 5, OSSM);
          menue_state_machine(HOME);
          updatepowerbars();
          vibrate();
          break;
        case 2:
          SendCommand(PATTERN, 6, OSSM);
          menue_state_machine(HOME);
          updatepowerbars();
          vibrate();
          break;
        case 3:
          SendCommand(PATTERN, 4, OSSM);
          menue_state_machine(HOME);
          updatepowerbars();
          vibrate();
          break;
        case 4:
          SendCommand(PATTERN, 8, OSSM);
          menue_state_machine(HOME);
          updatepowerbars();
          vibrate();
          break;
      }
      if(M5.BtnA.wasReleased()) {
        menue_state_machine(PATTERN_MENUE);
        vibrate();
      }
      if(M5.BtnB.wasReleased()) {
        menue_state_machine(HOME);
        vibrate();
      }
      if(M5.BtnC.wasReleased()) {
        menue_state_machine(PATTERN_MENUE3);
        vibrate();
      }
      }
      break;
      case PATTERN_MENUE3:
      { 
      switch(touchmenue()){
        case 1:
          SendCommand(PATTERN, 7, OSSM);
          menue_state_machine(HOME);
          updatepowerbars();
          vibrate();
          break;
        case 2:
          vibrate();
          break;
        case 3:
          vibrate();
          break;
        case 4:
          vibrate();
          break;
      }
      if(M5.BtnA.wasReleased()) {
        menue_state_machine(PATTERN_MENUE2);
        vibrate();
      }
      if(M5.BtnB.wasReleased()) {
        menue_state_machine(HOME);
        vibrate();
      }
      }
      break;
      case CUM_MENUE:
      {
      if(M5.BtnB.wasReleased()) {
      menue_state_machine(HOME);
      vibrate();
      } 
      }
      break;
      }
      */
     mxclick_long_waspressed = false;
     mxclick_short_waspressed = false;
     click2_short_waspressed = false;
     click3_short_waspressed = false;

  delay(5);
}

void espNowRemoteTask(void *pvParameters)
{
    WiFi.mode(WIFI_STA);
    LogDebug(WiFi.macAddress());

    // Init ESP-NOW
    if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
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
    return;
  }
  // register second peer  
  memcpy(peerInfo.peer_addr, CUM_Address, 6);
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
    // Register for a callback function that will be called when data is received
    esp_now_register_recv_cb(OnDataRecv);

    for(;;)
    {
      vTaskDelay(200);
    }
}

void homescreentask(void *pvParameters)
{
for(;;)
 {
  if(esp_connect == true){
  M5.Lcd.setTextColor(FrontColor);
  if(encoder1.getCount() != speedenc){
    speedenc = encoder1.getCount();
    speed = fscale(0, Encoder_MAP, 0.5, speedlimit, constrain(speedenc,0,Encoder_MAP), -3);
    SendCommand(SPEED, speed, OSSM);
  }
  if(encoder2.getCount() != depthenc){
    depthenc = encoder2.getCount();
    depth = map(constrain(depthenc,0,Encoder_MAP),0,Encoder_MAP,0,maxdepthinmm);
    SendCommand(DEPTH, depth, OSSM);
  }
  if(encoder3.getCount() != strokeenc){
    strokeenc = encoder3.getCount();
    stroke = map(constrain(strokeenc,0,maxdepthinmm),0,maxdepthinmm,0,maxdepthinmm);
    SendCommand(STROKE, stroke, OSSM);
  }


  if(encoder4.getCount() != sensationenc){
    sensationenc = encoder4.getCount();
    sensation = map(constrain(sensationenc,0,Encoder_MAP),0,Encoder_MAP,-100,100);
    SendCommand(SENSATION, sensation, OSSM);
  }
}
vTaskDelay(100);
} 
}

void torqescreentask(void *pvParameters)
{
  for(;;)
  {
  M5.Lcd.setTextColor(FrontColor);
  if(encoder1.getCount() != torqe_r_enc)
    {
    torqe_r_enc = encoder1.getCount();
    torqe_r = map(constrain(torqe_r_enc,0,Encoder_MAP),0,Encoder_MAP,-200,-50);
    M5.Lcd.fillRect(199,S1Pos,85,30,BgColor);
    M5.Lcd.setCursor(200,S1Pos+progheight-5);
    M5.Lcd.print(torqe_r);
    SendCommand(TORQE_R, torqe_r, OSSM);
    }

  if(encoder4.getCount() != torqe_f_enc)
    {
    torqe_f_enc = encoder4.getCount();
    torqe_f = map(constrain(torqe_f_enc,0,Encoder_MAP),0,Encoder_MAP,200,20);
    M5.Lcd.fillRect(199,S2Pos,85,30,BgColor);
    M5.Lcd.setCursor(200,S2Pos+progheight-5);
    M5.Lcd.print(torqe_f);
    SendCommand(TORQE_F, torqe_f, OSSM);
    }
  vTaskDelay(100);
  }
}

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

void vibrate(){
    if(vibrate_mode == true){
    M5.Axp.SetLDOEnable(3,true);
    vTaskDelay(300);
    M5.Axp.SetLDOEnable(3,false);
    }
}

void mxclick() {
  vibrate();
  Serial.println("MX click.");
  mxclick_short_waspressed = true;
} 

void mxlong(){
  vibrate();
  Serial.println("MX Long click.");
  mxclick_long_waspressed = true;
} 

void click2() {
  vibrate();
  click2_short_waspressed = true;
} // click1

void click3() {
  vibrate();
  Serial.println("Button 3 click.");
  click3_short_waspressed = true;
} // click1