#include <M5Core2.h>
#include <ESP32Encoder.h>
#include <esp_now.h>
#include <WiFi.h>
#include <PatternMath.h>
#include "OneButton.h"          //For Button Debounce and Longpress
#include "config.h"

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
long menue_enc = 0;

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


TaskHandle_t eRemote_t  = nullptr;  // Esp Now Remote Task
TaskHandle_t vibrate_t  = nullptr; // Vibration Task
TaskHandle_t home_t     = nullptr; // Homescreen Task
TaskHandle_t menue_t    = nullptr;
TaskHandle_t torqe_t    = nullptr;
TaskHandle_t cum_t      = nullptr; 
void espNowRemoteTask(void *pvParameters); // Handels the EspNow Remote
void vibrationTask(void *pvParameters); // Handels the EspNow Remote
void homescreentask(void *pvParameters); // Handels the Homescreen
void menuescreentask(void *pvParameters); // Handels the Menue Screen
void torqescreentask(void *pvParameters); // Handels Torqe Settings Display
void cumscreentask(void *pvParameters); // Handels Lube Display
void menueUpdate(int select); //Handels update of Menue
void drawdisplay(int display); //Handels Display Drawing
bool connectbtn(); //Handels Connectbtn
void menue_state_machine(int menuestate);
void updatepowerbars();
int64_t touchmenue();
void vibrate();
void mxclick();
void mxlong();
void click2();
void click3();

void powerBar(int x, int y, int w, int h, uint8_t val) {
  M5.lcd.drawRect(x, y, w, h, FrontColor);
  M5.lcd.fillRect(x + 1, y + 1, w * (((float)100) / 100.0), h - 1, BgColor);
  M5.lcd.fillRect(x + 1, y + 1, w * (((float)val) / 100.0), h - 1, FrontColor);
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
      menue_state_machine(HOME);
      menuestatus = HOME;
      menueUpdate(2);
      delay(200);
      vTaskResume(home_t);
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

void setup(){
  M5.begin(true, false, true, true); //Init M5Core2.
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

  xTaskCreatePinnedToCore(homescreentask,     /* Task function. */
                            "homescreentask", /* name of task. */
                            6072,                /* Stack size of task */
                            NULL,                /* parameter of the task */
                            1,                   /* priority of the task */
                            &home_t,            /* Task handle to keep track of created task */
                            0);                  /* pin task to core 0 */
  vTaskSuspend(home_t);

  xTaskCreatePinnedToCore(menuescreentask,     /* Task function. */
                            "menuescreentask", /* name of task. */
                            4096,                /* Stack size of task */
                            NULL,                /* parameter of the task */
                            1,                   /* priority of the task */
                            &menue_t,            /* Task handle to keep track of created task */
                            0);                  /* pin task to core 0 */
  vTaskSuspend(menue_t);

  xTaskCreatePinnedToCore(torqescreentask,     /* Task function. */
                            "torqescreentask", /* name of task. */
                            4096,                /* Stack size of task */
                            NULL,                /* parameter of the task */
                            1,                   /* priority of the task */
                            &torqe_t,            /* Task handle to keep track of created task */
                            0);                  /* pin task to core 0 */
  vTaskSuspend(torqe_t);

  xTaskCreatePinnedToCore(vibrationTask,     /* Task function. */
                            "vibrationTask", /* name of task. */
                            2048,                /* Stack size of task */
                            NULL,                /* parameter of the task */
                            1,                   /* priority of the task */
                            &vibrate_t,            /* Task handle to keep track of created task */
                            0);                  /* pin task to core 0 */
  vTaskSuspend(vibrate_t);

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
  displaywidth = M5.Lcd.width();
  displayheight = M5.Lcd.height();

  S4Pos = displayheight - 40 - progheight;
  S3Pos = S4Pos - progheight - distheight;
  S2Pos = S3Pos - progheight - distheight;
  S1Pos = S2Pos - progheight - distheight;

  drawdisplay(HOME);
  menueUpdate(0);
  powerBar(displaywidth*0.5+10,S1Pos,displaywidth*0.5-20,progheight, 0);
  powerBar(displaywidth*0.5+10,S2Pos,displaywidth*0.5-20,progheight, 0);
  powerBar(displaywidth*0.5+10,S3Pos,displaywidth*0.5-20,progheight, 0);
  powerBar(displaywidth*0.5+10,S4Pos,displaywidth*0.5-20,progheight, 50);

  encoder4.setCount(Encoder_MAP*0.5);
}

void loop()
{
     M5.update();
     Button1.tick();
     Button2.tick();
     Button3.tick();
     //LogDebug(digitalRead(ENCBUTTON1));
     //LogDebug(digitalRead(ENCBUTTON2));
     //LogDebug(analogReadMilliVolts(ANALOGIN));
     //LogDebug(M5.Axp.GetBatVoltage());
     switch(menuestatus){
      case CONNECT:
      {
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
  delay(100);
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
    updatepowerbars();
    SendCommand(SPEED, speed, OSSM);
  }
  if(encoder2.getCount() != depthenc){
    depthenc = encoder2.getCount();
    depth = map(constrain(depthenc,0,Encoder_MAP),0,Encoder_MAP,0,maxdepthinmm);
    updatepowerbars();
    SendCommand(DEPTH, depth, OSSM);
  }
  if(encoder3.getCount() != strokeenc){
    strokeenc = encoder3.getCount();
    stroke = map(constrain(strokeenc,0,maxdepthinmm),0,maxdepthinmm,0,maxdepthinmm);
    updatepowerbars();
    SendCommand(STROKE, stroke, OSSM);
  }


  if(encoder4.getCount() != sensationenc){
    sensationenc = encoder4.getCount();
    sensation = map(constrain(sensationenc,0,Encoder_MAP),0,Encoder_MAP,-100,100);
    updatepowerbars();
    SendCommand(SENSATION, sensation, OSSM);
  }
}
vTaskDelay(100);
} 
}

void menuescreentask(void *pvParameters)
{
for(;;)
{

  if(encoder4.getCount() != menue_enc)
    {
    menue_enc = encoder4.getCount();
    switch(menue_enc){
      case 1:
      LogDebug("1");
      break;
      case 2:
      LogDebug("2");
      break;
      case 3:
      LogDebug("3");
      break;
      case 4:
      LogDebug("4");
      break;
    }
    }
  vTaskDelay(300); 
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

void vibrationTask(void *pvParameters)
{
for(;;)
  {
    vTaskDelay(300); 
  }
}

void menueUpdate(int select){
  M5.Lcd.setCursor(0,displayheight-5);
  M5.Lcd.setTextPadding(displaywidth);
  switch(select){
    case 0:
    M5.Lcd.setCursor(displaywidth-80,displayheight-5);
    M5.Lcd.setTextPadding(displaywidth);
    M5.Lcd.setFont(&FreeSansBold12pt7b);
    M5.Lcd.setCursor(10,displayheight-5);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.print(T_BLANK);
    M5.Lcd.setCursor(displaywidth*0.5-(M5.Lcd.textWidth(T_MENUE)*0.5),displayheight-5);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.print(T_MENUE);
    M5.Lcd.setTextColor(HighlightColor);
    M5.Lcd.setCursor(displaywidth-110,displayheight-5);
    M5.Lcd.print(T_CONNECT);
    break;
    case 1:
    M5.Lcd.setCursor(displaywidth-80,displayheight-5);
    M5.Lcd.setTextPadding(displaywidth);
    M5.Lcd.setFont(&FreeSansBold12pt7b);
    M5.Lcd.setCursor(20,displayheight-5);
    M5.Lcd.setTextColor(HighlightColor);
    M5.Lcd.print(T_START);
    M5.Lcd.setCursor(displaywidth*0.5-(M5.Lcd.textWidth(T_MENUE)*0.5),displayheight-5);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.print(T_MENUE);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.setCursor(displaywidth-80,displayheight-5);
    M5.Lcd.print(T_STOP);
    break;
    case 2:
    M5.Lcd.setCursor(displaywidth-80,displayheight-5);
    M5.Lcd.setTextPadding(displaywidth);
    M5.Lcd.setFont(&FreeSansBold12pt7b);
    M5.Lcd.setCursor(20,displayheight-5);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.print(T_START);
    M5.Lcd.setCursor(displaywidth*0.5-(M5.Lcd.textWidth(T_MENUE)*0.5),displayheight-5);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.print(T_MENUE);
    M5.Lcd.setTextColor(HighlightColor);
    M5.Lcd.setCursor(displaywidth-80,displayheight-5);
    M5.Lcd.print(T_STOP);
    break;
    case 3:
    M5.Lcd.setCursor(displaywidth-80,displayheight-5);
    M5.Lcd.setTextPadding(displaywidth);
    M5.Lcd.setFont(&FreeSansBold12pt7b);
    M5.Lcd.setCursor(20,displayheight-5);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.print(T_CUM);
    M5.Lcd.setCursor(displaywidth*0.5-(M5.Lcd.textWidth(T_HOME)*0.5),displayheight-5);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.print(T_HOME);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.setCursor(displaywidth-90,displayheight-5);
    M5.Lcd.fillTriangle(305, 235, 295, 215, 315, 215, FrontColor);
    M5.Lcd.print(T_MEN2);
    break;
    case 4:
    M5.Lcd.setCursor(displaywidth-80,displayheight-5);
    M5.Lcd.setTextPadding(displaywidth);
    M5.Lcd.setFont(&FreeSansBold12pt7b);
    M5.Lcd.setCursor(20,displayheight-5);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.print(T_CUM);
    M5.Lcd.setCursor(displaywidth*0.5-(M5.Lcd.textWidth(T_HOME)*0.5),displayheight-5);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.print(T_HOME);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.setCursor(displaywidth-90,displayheight-5);
    M5.Lcd.fillTriangle(305, 215, 295, 235, 315, 235, FrontColor);
    M5.Lcd.print(T_MEN1);
    break;
    case 5:
    M5.Lcd.setCursor(displaywidth-80,displayheight-5);
    M5.Lcd.setTextPadding(displaywidth);
    M5.Lcd.setFont(&FreeSansBold12pt7b);
    M5.Lcd.setCursor(20,displayheight-5);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.print(T_BLANK);
    M5.Lcd.setCursor(displaywidth*0.5-(M5.Lcd.textWidth(T_HOME)*0.5),displayheight-5);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.print(T_HOME);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.setCursor(displaywidth-90,displayheight-5);
    M5.Lcd.print(T_BLANK);
    break;
    case 6:
    M5.Lcd.setCursor(displaywidth-80,displayheight-5);
    M5.Lcd.setTextPadding(displaywidth);
    M5.Lcd.setFont(&FreeSansBold12pt7b);
    M5.Lcd.setCursor(20,displayheight-5);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.print(T_BLANK);
    M5.Lcd.setCursor(displaywidth*0.5-(M5.Lcd.textWidth(T_HOME)*0.5),displayheight-5);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.print(T_HOME);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.setCursor(displaywidth-90,displayheight-5);
    M5.Lcd.fillTriangle(305, 235, 295, 215, 315, 215, FrontColor);
    M5.Lcd.print(T_MEN2);
    break;
    case 7:
    M5.Lcd.setCursor(displaywidth-80,displayheight-5);
    M5.Lcd.setTextPadding(displaywidth);
    M5.Lcd.setFont(&FreeSansBold12pt7b);
    M5.Lcd.setCursor(20,displayheight-5);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.fillTriangle(10, 215, 0, 235, 20, 235, FrontColor);
    M5.Lcd.print(T_MEN1);
    M5.Lcd.setCursor(displaywidth*0.5-(M5.Lcd.textWidth(T_HOME)*0.5),displayheight-5);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.print(T_HOME);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.setCursor(displaywidth-90,displayheight-5);
    M5.Lcd.fillTriangle(305, 235, 295, 215, 315, 215, FrontColor);
    M5.Lcd.print(T_MEN2);
    break;
    case 8:
    M5.Lcd.setCursor(displaywidth-80,displayheight-5);
    M5.Lcd.setTextPadding(displaywidth);
    M5.Lcd.setFont(&FreeSansBold12pt7b);
    M5.Lcd.setCursor(20,displayheight-5);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.fillTriangle(10, 215, 0, 235, 20, 235, FrontColor);
    M5.Lcd.print(T_MEN1);
    M5.Lcd.setCursor(displaywidth*0.5-(M5.Lcd.textWidth(T_HOME)*0.5),displayheight-5);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.print(T_HOME);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.setCursor(displaywidth-90,displayheight-5);
    M5.Lcd.print(T_BLANK);
    break;
  }

}

void drawdisplay(int display){
  switch (display){
    case HOME:
    {
      M5.lcd.clearDisplay();
      M5.Lcd.fillScreen(BgColor);
      M5.Lcd.setTextColor(TextColor);
      M5.Lcd.setTextSize(1);
      M5.Lcd.setFont(&FreeSansBold12pt7b);
      M5.Lcd.setCursor(displaywidth*0.5-(M5.Lcd.textWidth(T_HEADER)*0.5),25);
      M5.Lcd.print(T_HEADER);
      M5.Lcd.setTextColor(TextColor);
      M5.Lcd.fillRect(0,S1Pos-distheight,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S1Pos+progheight-5);
      M5.Lcd.print(T_SPEED);
      M5.Lcd.fillRect(0,S1Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S2Pos+progheight-5);
      M5.Lcd.print(T_DEPTH);
      int mm = depth;
      M5.Lcd.setCursor(95,S2Pos+progheight-5);
      M5.Lcd.print(mm);
      M5.Lcd.print(T_MM);
      M5.Lcd.fillRect(0,S2Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S3Pos+progheight-5);
      M5.Lcd.print(T_STROKE);
      mm = stroke;
      M5.Lcd.setCursor(95,S3Pos+progheight-5);
      M5.Lcd.print(mm);
      M5.Lcd.print(T_MM);
      M5.Lcd.fillRect(0,S3Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S4Pos+progheight-5);
      M5.Lcd.print(T_SENSATION);
      M5.Lcd.fillRect(0,S4Pos+progheight+2,displaywidth,distheight-4, FrontColor);
    }
    break;
    case MENUE:
    {
      M5.lcd.clearDisplay();
      M5.Lcd.fillScreen(BgColor);
      M5.Lcd.setTextColor(TextColor);
      M5.Lcd.setTextSize(1);
      M5.Lcd.setFont(&FreeSansBold12pt7b);
      M5.Lcd.setCursor(displaywidth*0.5-(M5.Lcd.textWidth(T_HEADER)*0.5),25);
      M5.Lcd.print(T_HEADER);
      M5.Lcd.setTextColor(TextColor);
      M5.Lcd.fillRect(0,S1Pos-distheight,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S1Pos+progheight-5);
      M5.Lcd.print(T_SETUP_DEPTH_I);
      M5.Lcd.fillRect(0,S1Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S2Pos+progheight-5);
      M5.Lcd.print(T_SETUP_DEPTH_F);
      M5.Lcd.fillRect(0,S2Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S3Pos+progheight-5);
      M5.Lcd.print(T_SELECT_PATTERN);
      M5.Lcd.fillRect(0,S3Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S4Pos+progheight-5);
      M5.Lcd.print(T_SETUP_TORQE);
      M5.Lcd.fillRect(0,S4Pos+progheight+2,displaywidth,distheight-4, FrontColor);
    }
    break;
    case MENUE2:
    {
      M5.lcd.clearDisplay();
      M5.Lcd.fillScreen(BgColor);
      M5.Lcd.setTextColor(TextColor);
      M5.Lcd.setTextSize(1);
      M5.Lcd.setFont(&FreeSansBold12pt7b);
      M5.Lcd.setCursor(displaywidth*0.5-(M5.Lcd.textWidth(T_HEADER)*0.5),25);
      M5.Lcd.print(T_HEADER);
      M5.Lcd.setTextColor(TextColor);
      M5.Lcd.fillRect(0,S1Pos-distheight,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S1Pos+progheight-5);
      M5.Lcd.print(T_RESTART);
      M5.Lcd.fillRect(0,S1Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S2Pos+progheight-5);
      M5.Lcd.print(T_BLANK);
      M5.Lcd.fillRect(0,S2Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S3Pos+progheight-5);
      M5.Lcd.print(T_BLANK);
      M5.Lcd.fillRect(0,S3Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S4Pos+progheight-5);
      M5.Lcd.print(T_BLANK);
      M5.Lcd.fillRect(0,S4Pos+progheight+2,displaywidth,distheight-4, FrontColor);
    }
    break;
    case TORQE:
    {
      M5.lcd.clearDisplay();
      M5.Lcd.fillScreen(BgColor);
      M5.Lcd.setTextColor(TextColor);
      M5.Lcd.setTextSize(1);
      M5.Lcd.setFont(&FreeSansBold12pt7b);
      M5.Lcd.setCursor(displaywidth*0.5-(M5.Lcd.textWidth(T_HEADER)*0.5),25);
      M5.Lcd.print(T_HEADER);
      M5.Lcd.setTextColor(TextColor);
      M5.Lcd.fillRect(0,S1Pos-distheight,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S1Pos+progheight-5);
      M5.Lcd.print(T_OUT_TORQE);
      M5.Lcd.fillRect(199,S1Pos,85,30,BgColor);
      M5.Lcd.setCursor(200,S1Pos+progheight-5);
      M5.Lcd.print(torqe_r);
      M5.Lcd.fillRect(0,S1Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S2Pos+progheight-5);
      M5.Lcd.print(T_IN_TORQE);
      M5.Lcd.fillRect(199,S2Pos,85,30,BgColor);
      M5.Lcd.setCursor(200,S2Pos+progheight-5);
      M5.Lcd.print(torqe_f);
      M5.Lcd.fillRect(0,S2Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S3Pos+progheight-5);
      M5.Lcd.print(T_BLANK);
      M5.Lcd.fillRect(0,S3Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S4Pos+progheight-5);
      M5.Lcd.print(T_BLANK);
      M5.Lcd.fillRect(0,S4Pos+progheight+2,displaywidth,distheight-4, FrontColor);
    }
    break;
    case PATTERN_MENUE:
    {
      M5.lcd.clearDisplay();
      M5.Lcd.fillScreen(BgColor);
      M5.Lcd.setTextColor(TextColor);
      M5.Lcd.setTextSize(1);
      M5.Lcd.setFont(&FreeSansBold12pt7b);
      M5.Lcd.setCursor(displaywidth*0.5-(M5.Lcd.textWidth(T_Patterns)*0.5),25);
      M5.Lcd.print(T_Patterns);
      M5.Lcd.setTextColor(TextColor);
      M5.Lcd.fillRect(0,S1Pos-distheight,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S1Pos+progheight-5);
      M5.Lcd.print(T_SimpleStroke);
      M5.Lcd.fillRect(0,S1Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S2Pos+progheight-5);
      M5.Lcd.print(T_RoboStroke);
      M5.Lcd.fillRect(0,S2Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S3Pos+progheight-5);
      M5.Lcd.print(T_TeasingPounding);
      M5.Lcd.fillRect(0,S3Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S4Pos+progheight-5);
      M5.Lcd.print(T_HalfnHalf);
      M5.Lcd.fillRect(0,S4Pos+progheight+2,displaywidth,distheight-4, FrontColor);
    }
    break;
    case PATTERN_MENUE2:
    {
      M5.lcd.clearDisplay();
      M5.Lcd.fillScreen(BgColor);
      M5.Lcd.setTextColor(TextColor);
      M5.Lcd.setTextSize(1);
      M5.Lcd.setFont(&FreeSansBold12pt7b);
      M5.Lcd.setCursor(displaywidth*0.5-(M5.Lcd.textWidth(T_Patterns)*0.5),25);
      M5.Lcd.print(T_Patterns);
      M5.Lcd.setTextColor(TextColor);
      M5.Lcd.fillRect(0,S1Pos-distheight,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S1Pos+progheight-5);
      M5.Lcd.print(T_StopNGo);
      M5.Lcd.fillRect(0,S1Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S2Pos+progheight-5);
      M5.Lcd.print(T_Insist);
      M5.Lcd.fillRect(0,S2Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S3Pos+progheight-5);
      M5.Lcd.print(T_Deeper);
      M5.Lcd.fillRect(0,S3Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S4Pos+progheight-5);
      M5.Lcd.print(T_StrokeNibbler);
      M5.Lcd.fillRect(0,S4Pos+progheight+2,displaywidth,distheight-4, FrontColor);
    }
    break;
    case PATTERN_MENUE3:
    {
      M5.lcd.clearDisplay();
      M5.Lcd.fillScreen(BgColor);
      M5.Lcd.setTextColor(TextColor);
      M5.Lcd.setTextSize(1);
      M5.Lcd.setFont(&FreeSansBold12pt7b);
      M5.Lcd.setCursor(displaywidth*0.5-(M5.Lcd.textWidth(T_Patterns)*0.5),25);
      M5.Lcd.print(T_Patterns);
      M5.Lcd.setTextColor(TextColor);
      M5.Lcd.fillRect(0,S1Pos-distheight,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S1Pos+progheight-5);
      M5.Lcd.print(T_JackHammer);
      M5.Lcd.fillRect(0,S1Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S2Pos+progheight-5);
      M5.Lcd.print(T_BLANK);
      M5.Lcd.fillRect(0,S2Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S3Pos+progheight-5);
      M5.Lcd.print(T_BLANK);
      M5.Lcd.fillRect(0,S3Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S4Pos+progheight-5);
      M5.Lcd.print(T_BLANK);
      M5.Lcd.fillRect(0,S4Pos+progheight+2,displaywidth,distheight-4, FrontColor);
    }
    break;
    case CUM_MENUE:
    {
      M5.lcd.clearDisplay();
      M5.Lcd.fillScreen(BgColor);
      M5.Lcd.setTextColor(TextColor);
      M5.Lcd.setTextSize(1);
      M5.Lcd.setFont(&FreeSansBold12pt7b);
      M5.Lcd.setCursor(displaywidth*0.5-(M5.Lcd.textWidth(T_HEADER)*0.5),25);
      M5.Lcd.print(T_HEADER);
      M5.Lcd.setTextColor(TextColor);
      M5.Lcd.fillRect(0,S1Pos-distheight,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S1Pos+progheight-5);
      M5.Lcd.print(T_CUM_SPEED);
      M5.Lcd.fillRect(199,S1Pos,85,30,BgColor);
      M5.Lcd.setCursor(200,S1Pos+progheight-5);
      M5.Lcd.print(cum_speed);
      M5.Lcd.fillRect(0,S1Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S2Pos+progheight-5);
      M5.Lcd.print(T_CUM_TIME);
      M5.Lcd.fillRect(199,S2Pos,85,30,BgColor);
      M5.Lcd.setCursor(200,S2Pos+progheight-5);
      M5.Lcd.print(cum_time);
      M5.Lcd.fillRect(0,S2Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S3Pos+progheight-5);
      M5.Lcd.print(T_CUM_Volume);
      M5.Lcd.fillRect(0,S3Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S4Pos+progheight-5);
      M5.Lcd.print(T_CUM_Accel);
      M5.Lcd.fillRect(0,S4Pos+progheight+2,displaywidth,distheight-4, FrontColor);
    }
    break;
  }
}

void menue_state_machine(int menuestate){
  switch (menuestate) {
    case HOME:
    drawdisplay(HOME);
    menueUpdate(2);
    powerBar(displaywidth*0.5+10,S1Pos,displaywidth*0.5-20,progheight, 0);
    powerBar(displaywidth*0.5+10,S2Pos,displaywidth*0.5-20,progheight, 0);
    powerBar(displaywidth*0.5+10,S3Pos,displaywidth*0.5-20,progheight, 0);
    powerBar(displaywidth*0.5+10,S4Pos,displaywidth*0.5-20,progheight, 50);
    encoder1.setCount(speedenc);
    encoder2.setCount(depthenc);
    encoder3.setCount(strokeenc);
    sensationenc = map(sensation, -100,100, 0, Encoder_MAP);
    encoder4.setCount(sensationenc);
    vTaskResume(home_t);
    vTaskSuspend(torqe_t);
    vTaskSuspend(cum_t);
    menuestatus = HOME;
    break;
    case MENUE:
    vTaskSuspend(home_t);
    vTaskSuspend(torqe_t);
    vTaskSuspend(cum_t);
    menuestatus = MENUE;
    drawdisplay(MENUE);
    menueUpdate(3);
    break;
    case MENUE2:
    vTaskSuspend(home_t);
    vTaskSuspend(torqe_t);
    vTaskSuspend(cum_t);
    menuestatus = MENUE2;
    drawdisplay(MENUE2);
    menueUpdate(4);
    break;
    case TORQE:
    vTaskSuspend(home_t);
    torqe_f_enc = map(torqe_f, 200, 20, 0, Encoder_MAP);
    torqe_r_enc = map(torqe_r, -200,-50, 0, Encoder_MAP);
    encoder1.setCount(torqe_r_enc);
    encoder4.setCount(torqe_f_enc);
    vTaskResume(torqe_t);
    vTaskSuspend(cum_t);
    menuestatus = TORQE;
    drawdisplay(TORQE);
    menueUpdate(5);
    break;
    case PATTERN_MENUE:
    vTaskSuspend(home_t);
    vTaskSuspend(torqe_t);
    vTaskSuspend(cum_t);
    menuestatus = PATTERN_MENUE;
    drawdisplay(PATTERN_MENUE);
    menueUpdate(6);
    break;
    case PATTERN_MENUE2:
    vTaskSuspend(home_t);
    vTaskSuspend(torqe_t);
    vTaskSuspend(cum_t);
    menuestatus = PATTERN_MENUE2;
    drawdisplay(PATTERN_MENUE2);
    menueUpdate(7);
    break;
    case PATTERN_MENUE3:
    vTaskSuspend(home_t);
    vTaskSuspend(torqe_t);
    vTaskSuspend(cum_t);
    menuestatus = PATTERN_MENUE3;
    drawdisplay(PATTERN_MENUE3);
    menueUpdate(8);
    break;
    case CUM_MENUE:
    vTaskSuspend(home_t);
    encoder1.setCount(cum_s_enc);
    encoder2.setCount(cum_t_enc);
    encoder3.setCount(cum_si_enc);
    encoder4.setCount(cum_a_enc);
    vTaskResume(cum_t);
    menuestatus = CUM_MENUE;
    drawdisplay(CUM_MENUE);
    menueUpdate(5);
    break;
}
}

void updatepowerbars(){
  M5.Lcd.setFreeFont(&FreeSansBold9pt7b);
  M5.Lcd.fillRect(85,S1Pos,85,30,BgColor);
  int mms = speed;
  M5.Lcd.setCursor(95,S1Pos+progheight-5);
  M5.Lcd.print(mms);
  M5.Lcd.print(T_FUCKS_MIN);
  powerBar(displaywidth*0.5+10,S1Pos,displaywidth*0.5-20,progheight, map(constrain(encoder1.getCount(),0,Encoder_MAP),0,Encoder_MAP,0,100));
  M5.Lcd.setFreeFont(&FreeSansBold9pt7b);
  M5.Lcd.fillRect(85,S2Pos,85,30,BgColor);
  int mmd = depth;
  M5.Lcd.setCursor(95,S2Pos+progheight-5);
  M5.Lcd.print(mmd);
  M5.Lcd.print(T_MM);
  powerBar(displaywidth*0.5+10,S2Pos,displaywidth*0.5-20,progheight, map(depth, 0, maxdepthinmm, 0, 100));
  M5.Lcd.setFreeFont(&FreeSansBold9pt7b);
  M5.Lcd.fillRect(85,S3Pos,85,30,BgColor);
  int mmst = stroke;
  M5.Lcd.setCursor(95,S3Pos+progheight-5);
  M5.Lcd.print(mmst);
  M5.Lcd.print(T_MM);
  powerBar(displaywidth*0.5+10,S3Pos,displaywidth*0.5-20,progheight, map(stroke, 0, maxdepthinmm, 0, 100));
  powerBar(displaywidth*0.5+10,S4Pos,displaywidth*0.5-20,progheight, map(sensation,-100,100,0,100));
}

int64_t touchmenue(){
      TouchPoint_t coordinate;
      coordinate = M5.Touch.getPressPoint();
      int touch = constrain(coordinate.y,0,300);

      if((touch >= 60) && (touch <= 110)){
        LogDebug("Touch1");
        return 1;
      } else if((touch >= 110) && (touch <= 145)){
        LogDebug("Touch2");
        return 2;
      } else if((touch >= 145) && (touch <= 165)){
        LogDebug("Touch3");
        return 3;
      } else if((touch >= 165) && (touch <= 190)){
        LogDebug("Touch4");
        return 4;
      } else {
        return 0;
      }
}

void vibrate(){
    M5.Axp.SetLDOEnable(3,true);
    vTaskDelay(300);
    M5.Axp.SetLDOEnable(3,false);
}


void mxclick() {
  Serial.println("MX click.");
         switch(onoff){
           case true:
           SendCommand(OFF, 0, OSSM);
           if(menuestatus == HOME){
             menueUpdate(2);
           }
           onoff = false;
           break;
           case false:
           SendCommand(ON, 0, OSSM);
           if(menuestatus == HOME){
             menueUpdate(1);
           }
           onoff = true;
           break;
         }
} 
void mxlong(){
  Serial.println("MX Long click.");
  menue_state_machine(MENUE);
  vibrate();
} 
void click2() {
  Serial.println("Button 2 click.");
} // click1
void click3() {
  Serial.println("Button 3 click.");
} // click1