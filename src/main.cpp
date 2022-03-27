#include <M5Core2.h>
#include <ESP32Encoder.h>
#include <esp_now.h>
#include <WiFi.h>
#include <PatternMath.h>

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



#define ENC_1_CLK 25
#define ENC_1_DT 26

#define ENC_2_CLK 13
#define ENC_2_DT 14

#define ENC_3_CLK 33
#define ENC_3_DT 32

#define ENC_4_CLK 19
#define ENC_4_DT 27
#define Button 35
#define ENCBUTTON1 38
#define ENCBUTTON2 18 
#define ANALOGIN 36 

#define Encoder_MAP 84
#define TextColor  TFT_PURPLE
#define BgColor    TFT_WHITE
#define FrontColor TFT_PURPLE

#define OFF 0.0
#define ON 1.0

// Menü States

#define CONNECT 0
#define HOME 1
#define MENUE 2
#define PATTERN_MENUE 3

int menuestatus = CONNECT;

// Command States
#define SPEED 1
#define DEPTH 2
#define STROKE 3
#define SENSATION 4
#define PATTERN 5
#define TORQE 6
#define OFF 10
#define ON   11
#define SETUP_D_I 12
#define SETUP_D_I_F 13
#define REBOOT 14

int displaywidth;
int displayheight;
int progheight = 30;
int distheight = 10;
int S1Pos;
int S2Pos;
int S3Pos;
int S4Pos;
bool rstate = false;
int pattern = 0;

long enc1 = 0;
long enc2 = 0;
long enc3 = 0;
long enc4 = 0;

float speed = 0.0;
float depth = 0.0;
float stroke = 0.0;
float sensation = 0.0;
float maxdepthinmm = 0.0;
float speedlimit = 0.0;

ESP32Encoder encoder1;
ESP32Encoder encoder2;
ESP32Encoder encoder3;
ESP32Encoder encoder4;

uint8_t broadcastAddress[] = {0x34, 0x86, 0x5d, 0x57, 0xf5, 0x84};

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
void espNowRemoteTask(void *pvParameters); // Handels the EspNow Remote
void vibrationTask(void *pvParameters); // Handels the EspNow Remote
void homescreentask(void *pvParameters); // Handels the Homescreen
void menueUpdate(int select); //Handels update of Menue
void drawdisplay(int display); //Handels Display Drawing
bool connectbtn(); //Handels Connectbtn
void menue_state_machine(int menuestate);
void updatepowerbars();
int64_t touchmenue();

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
    esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &outgoingcontrol, sizeof(outgoingcontrol));
    LogDebug(result);
    if (result == ESP_OK) {
      esp_connect = true;
      outgoingcontrol.esp_connected = true;
      M5.Lcd.setCursor(5,20);
      M5.Lcd.setFont(&FreeSansBold9pt7b);
      M5.Lcd.setTextColor(FrontColor);
      M5.Lcd.print("CON");
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
bool SendCommand(int Command, float Value){
      if(esp_connect == true){
      outgoingcontrol.esp_connected = true;
      outgoingcontrol.esp_command = Command;
      outgoingcontrol.esp_value = Value;
      esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &outgoingcontrol, sizeof(outgoingcontrol));
      if (result == ESP_OK) {
      return true;
      } else {
      return false;
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

  xTaskCreatePinnedToCore(vibrationTask,     /* Task function. */
                            "vibrationTask", /* name of task. */
                            2048,                /* Stack size of task */
                            NULL,                /* parameter of the task */
                            1,                   /* priority of the task */
                            &vibrate_t,            /* Task handle to keep track of created task */
                            0);                  /* pin task to core 0 */
  vTaskSuspend(vibrate_t);

  encoder1.attachHalfQuad(ENC_1_CLK, ENC_1_DT);
  encoder2.attachHalfQuad(ENC_2_CLK, ENC_2_DT);
  encoder3.attachHalfQuad(ENC_3_CLK, ENC_3_DT);
  encoder4.attachHalfQuad(ENC_4_CLK, ENC_4_DT);
  pinMode(Button, INPUT);
  pinMode(ENCBUTTON1, INPUT);
  pinMode(ENCBUTTON2, INPUT);
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
     //LogDebug(digitalRead(Button));
     //LogDebug(digitalRead(ENCBUTTON1));
     //LogDebug(digitalRead(ENCBUTTON2));
     //LogDebug(analogReadMilliVolts(ANALOGIN));
     //LogDebug(M5.Axp.GetBatVoltage());
     switch(menuestatus){
      case CONNECT:
      if(M5.BtnC.wasReleased()) {
      outgoingcontrol.esp_connected = false;
      esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &outgoingcontrol, sizeof(outgoingcontrol));
      M5.Axp.SetLDOEnable(3,true);
      vTaskDelay(300);
      M5.Axp.SetLDOEnable(3,false);
      delay(100);
      }
      if(M5.BtnA.wasReleased()) {
      delay(100);
      }
      break;
      
      case HOME:
      if(M5.BtnA.wasReleased()) {
      SendCommand(ON, 0);
      enc1 = encoder1.getCount();
      speed = fscale(0, Encoder_MAP, 0.5, speedlimit, constrain(encoder1.getCount(),0,Encoder_MAP), -3);
      SendCommand(SPEED, speed);
      enc2 = encoder2.getCount();
      depth = map(constrain(enc2,0,Encoder_MAP),0,Encoder_MAP,0,maxdepthinmm);
      SendCommand(DEPTH, depth);
      enc3 = encoder3.getCount();
      stroke = map(constrain(encoder3.getCount(),0,maxdepthinmm),0,maxdepthinmm,0,maxdepthinmm);
      SendCommand(STROKE, stroke);
      enc4 = encoder4.getCount();
      sensation = map(constrain(encoder4.getCount(),0,Encoder_MAP),0,Encoder_MAP,-100,100);
      SendCommand(SENSATION, sensation);
      
      menueUpdate(1);
      M5.Axp.SetLDOEnable(3,true);
      vTaskDelay(300);
      M5.Axp.SetLDOEnable(3,false);
      }

      if(M5.BtnB.wasReleased()) {
      menue_state_machine(MENUE);
      M5.Axp.SetLDOEnable(3,true);
      vTaskDelay(300);
      M5.Axp.SetLDOEnable(3,false);
      }
  
      if(M5.BtnC.wasReleased()) {
      SendCommand(OFF, 0);
      menueUpdate(2);
      M5.Axp.SetLDOEnable(3,true);
      vTaskDelay(300);
      M5.Axp.SetLDOEnable(3,false);
      }
      break;

      case MENUE:
     {
      switch(touchmenue()){
        case 1:
        menue_state_machine(HOME);
        SendCommand(SETUP_D_I, 0);
        updatepowerbars();
        M5.Axp.SetLDOEnable(3,true);
        vTaskDelay(300);
        M5.Axp.SetLDOEnable(3,false);
        break;
        case 2:
        menue_state_machine(HOME);
        SendCommand(SETUP_D_I_F, 0);
        updatepowerbars();
        M5.Axp.SetLDOEnable(3,true);
        vTaskDelay(300);
        M5.Axp.SetLDOEnable(3,false);
        break;
        case 3:
        menue_state_machine(PATTERN_MENUE);
        M5.Axp.SetLDOEnable(3,true);
        vTaskDelay(300);
        M5.Axp.SetLDOEnable(3,false);
        break;
        case 4:
        M5.Axp.SetLDOEnable(3,true);
        vTaskDelay(300);
        M5.Axp.SetLDOEnable(3,false);
        SendCommand(REBOOT,0);
        ESP.restart();
        break;
      }

      if(M5.BtnB.wasReleased()) {
      menue_state_machine(HOME);
      M5.Axp.SetLDOEnable(3,true);
      vTaskDelay(300);
      M5.Axp.SetLDOEnable(3,false);
      }
     }
      break;
      case PATTERN_MENUE:
      { 
      
      switch(touchmenue()){
        case 1:
        SendCommand(PATTERN, 0);
        menue_state_machine(HOME);
        updatepowerbars();
        M5.Axp.SetLDOEnable(3,true);
        vTaskDelay(300);
        M5.Axp.SetLDOEnable(3,false);
        break;
        case 2:
        SendCommand(PATTERN, 6);
        menue_state_machine(HOME);
        updatepowerbars();
        M5.Axp.SetLDOEnable(3,true);
        vTaskDelay(300);
        M5.Axp.SetLDOEnable(3,false);
        break;
        case 3:
        SendCommand(PATTERN, 4);
        menue_state_machine(HOME);
        updatepowerbars();
        M5.Axp.SetLDOEnable(3,true);
        vTaskDelay(300);
        M5.Axp.SetLDOEnable(3,false);
        break;
        case 4:
        SendCommand(PATTERN, 8);
        menue_state_machine(HOME);
        updatepowerbars();
        M5.Axp.SetLDOEnable(3,true);
        vTaskDelay(300);
        M5.Axp.SetLDOEnable(3,false);
        break;
      }

      if(M5.BtnB.wasReleased()) {
      menue_state_machine(HOME);
      M5.Axp.SetLDOEnable(3,true);
      vTaskDelay(300);
      M5.Axp.SetLDOEnable(3,false);
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

    // Register peer
    memcpy(peerInfo.peer_addr, broadcastAddress, 6);
    peerInfo.channel = 0;  
    peerInfo.encrypt = false;
  
      // Add peer        
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
  if(encoder1.getCount() != enc1){
    enc1 = encoder1.getCount();
    speed = fscale(0, Encoder_MAP, 0.5, speedlimit, constrain(encoder1.getCount(),0,Encoder_MAP), -3);
    updatepowerbars();
    SendCommand(SPEED, speed);
  }

  if(encoder2.getCount() != enc2){
    enc2 = encoder2.getCount();
    depth = map(constrain(enc2,0,Encoder_MAP),0,Encoder_MAP,0,maxdepthinmm);
    updatepowerbars();
    SendCommand(DEPTH, depth);
  }

  if(encoder3.getCount() != enc3){
    enc3 = encoder3.getCount();
    stroke = map(constrain(encoder3.getCount(),0,maxdepthinmm),0,maxdepthinmm,0,maxdepthinmm);
    updatepowerbars();
    SendCommand(STROKE, stroke);
  }

  if(encoder4.getCount() != enc4){
    enc4 = encoder4.getCount();
    sensation = map(constrain(encoder4.getCount(),0,Encoder_MAP),0,Encoder_MAP,-100,100);
    updatepowerbars();
    SendCommand(SENSATION, sensation);
  }
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
    M5.Lcd.print("");
    M5.Lcd.setCursor(displaywidth*0.5-35,displayheight-5);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.print("Menu");
    M5.Lcd.setTextColor(TFT_BLACK);
    M5.Lcd.setCursor(displaywidth-110,displayheight-5);
    M5.Lcd.print("Connect");
    break;
    case 1:
    M5.Lcd.setCursor(displaywidth-80,displayheight-5);
    M5.Lcd.setTextPadding(displaywidth);
    M5.Lcd.setFont(&FreeSansBold12pt7b);
    M5.Lcd.setCursor(20,displayheight-5);
    M5.Lcd.setTextColor(TFT_BLACK);
    M5.Lcd.print("Start");
    M5.Lcd.setCursor(displaywidth*0.5-35,displayheight-5);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.print("Menu");
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.setCursor(displaywidth-80,displayheight-5);
    M5.Lcd.print("Stop");
    break;
    case 2:
    M5.Lcd.setCursor(displaywidth-80,displayheight-5);
    M5.Lcd.setTextPadding(displaywidth);
    M5.Lcd.setFont(&FreeSansBold12pt7b);
    M5.Lcd.setCursor(20,displayheight-5);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.print("Start");
    M5.Lcd.setCursor(displaywidth*0.5-35,displayheight-5);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.print("Menu");
    M5.Lcd.setTextColor(TFT_BLACK);
    M5.Lcd.setCursor(displaywidth-80,displayheight-5);
    M5.Lcd.print("Stop");
    break;
    case 3:
    M5.Lcd.setCursor(displaywidth-80,displayheight-5);
    M5.Lcd.setTextPadding(displaywidth);
    M5.Lcd.setFont(&FreeSansBold12pt7b);
    M5.Lcd.setCursor(20,displayheight-5);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.print("");
    M5.Lcd.setCursor(displaywidth*0.5-35,displayheight-5);
    M5.Lcd.setTextColor(FrontColor);
    M5.Lcd.print("Home");
    M5.Lcd.setTextColor(TFT_BLACK);
    M5.Lcd.setCursor(displaywidth-80,displayheight-5);
    M5.Lcd.print("");
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
      M5.Lcd.setCursor(80,20);
      M5.Lcd.setFont(&FreeSansBold12pt7b);
      M5.Lcd.print("OSSM Remote");
      M5.Lcd.setTextColor(TextColor);
      M5.Lcd.fillRect(0,S1Pos-distheight,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S1Pos+progheight-5);
      M5.Lcd.print("Speed:");
      M5.Lcd.fillRect(0,S1Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S2Pos+progheight-5);
      M5.Lcd.print("Depth:");
      int mm = depth;
      M5.Lcd.setCursor(95,S2Pos+progheight-5);
      M5.Lcd.print(mm);
      M5.Lcd.print(" mm");
      M5.Lcd.fillRect(0,S2Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S3Pos+progheight-5);
      M5.Lcd.print("Stroke:");
      mm = stroke;
      M5.Lcd.setCursor(95,S3Pos+progheight-5);
      M5.Lcd.print(mm);
      M5.Lcd.print(" mm");
      M5.Lcd.fillRect(0,S3Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S4Pos+progheight-5);
      M5.Lcd.print("Sensation:");
      M5.Lcd.fillRect(0,S4Pos+progheight+2,displaywidth,distheight-4, FrontColor);
    }
    break;
    case MENUE:
    {
      M5.lcd.clearDisplay();
      M5.Lcd.fillScreen(BgColor);
      M5.Lcd.setTextColor(TextColor);
      M5.Lcd.setTextSize(1);
      M5.Lcd.setCursor(80,20);
      M5.Lcd.setFont(&FreeSansBold12pt7b);
      M5.Lcd.print("OSSM Remote");
      M5.Lcd.setTextColor(TextColor);
      M5.Lcd.fillRect(0,S1Pos-distheight,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S1Pos+progheight-5);
      M5.Lcd.print("Setup Depth Interactively");
      M5.Lcd.fillRect(0,S1Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S2Pos+progheight-5);
      M5.Lcd.print("Setup Depth Fancy");
      M5.Lcd.fillRect(0,S2Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S3Pos+progheight-5);
      M5.Lcd.print("Select Pattern");
      M5.Lcd.fillRect(0,S3Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S4Pos+progheight-5);
      M5.Lcd.print("Restart");
      M5.Lcd.fillRect(0,S4Pos+progheight+2,displaywidth,distheight-4, FrontColor);
    }
    break;
    case PATTERN_MENUE:
    {
      M5.lcd.clearDisplay();
      M5.Lcd.fillScreen(BgColor);
      M5.Lcd.setTextColor(TextColor);
      M5.Lcd.setTextSize(1);
      M5.Lcd.setCursor(80,20);
      M5.Lcd.setFont(&FreeSansBold12pt7b);
      M5.Lcd.print("OSSM Patterns");
      M5.Lcd.setTextColor(TextColor);
      M5.Lcd.fillRect(0,S1Pos-distheight,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S1Pos+progheight-5);
      M5.Lcd.print("SimpleStroke");
      M5.Lcd.fillRect(0,S1Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S2Pos+progheight-5);
      M5.Lcd.print("Insist");
      M5.Lcd.fillRect(0,S2Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S3Pos+progheight-5);
      M5.Lcd.print("Deeper");
      M5.Lcd.fillRect(0,S3Pos+progheight+2,displaywidth,distheight-4, FrontColor);
      M5.Lcd.setCursor(5,S4Pos+progheight-5);
      M5.Lcd.print("StrokeNibbler");
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
    vTaskResume(home_t);
    menuestatus = HOME;
    break;
    case MENUE:
    vTaskSuspend(home_t);
    menuestatus = MENUE;
    drawdisplay(MENUE);
    menueUpdate(3);
    break;
    case PATTERN_MENUE:
    vTaskSuspend(home_t);
    menuestatus = PATTERN_MENUE;
    drawdisplay(PATTERN_MENUE);
    menueUpdate(3);
    break;
}
}

void updatepowerbars(){
  M5.Lcd.setFreeFont(&FreeSansBold9pt7b);
  M5.Lcd.fillRect(85,S1Pos,85,30,TFT_WHITE);
  int mms = speed;
  M5.Lcd.setCursor(95,S1Pos+progheight-5);
  M5.Lcd.print(mms);
  M5.Lcd.print(" F/m");
  powerBar(displaywidth*0.5+10,S1Pos,displaywidth*0.5-20,progheight, map(constrain(encoder1.getCount(),0,Encoder_MAP),0,Encoder_MAP,0,100));
  M5.Lcd.setFreeFont(&FreeSansBold9pt7b);
  M5.Lcd.fillRect(85,S2Pos,85,30,TFT_WHITE);
  int mmd = depth;
  M5.Lcd.setCursor(95,S2Pos+progheight-5);
  M5.Lcd.print(mmd);
  M5.Lcd.print(" mm");
  powerBar(displaywidth*0.5+10,S2Pos,displaywidth*0.5-20,progheight, map(depth, 0, maxdepthinmm, 0, 100));
  M5.Lcd.setFreeFont(&FreeSansBold9pt7b);
  M5.Lcd.fillRect(85,S3Pos,85,30,TFT_WHITE);
  int mmst = stroke;
  M5.Lcd.setCursor(95,S3Pos+progheight-5);
  M5.Lcd.print(mmst);
  M5.Lcd.print(" mm");
  powerBar(displaywidth*0.5+10,S3Pos,displaywidth*0.5-20,progheight, map(stroke, 0, maxdepthinmm, 0, 100));
  powerBar(displaywidth*0.5+10,S4Pos,displaywidth*0.5-20,progheight, map(sensation,-100,100,0,100));
}

int64_t touchmenue(){
      TouchPoint_t coordinate;
      coordinate = M5.Touch.getPressPoint();

      if(coordinate.y >= 60 && coordinate.y <= 110){
        return 1;
      } else if(coordinate.y >= 110 && coordinate.y <= 145){
        return 2;
      } else if(coordinate.y >= 145 && coordinate.y <= 165){
        return 3;
      } else if(coordinate.y >= 165 && coordinate.y <= 195){
        return 4;
      }
}