// Define Remote Devices MAC Adress

#define OSSM 1
uint8_t OSSM_Address[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
//uint8_t OSSM_Address[] = {0x40, 0x91, 0x51, 0xBB, 0xCC, 0x88};
#define CUM 2
uint8_t CUM_Address[] ={0x34, 0xb4, 0x72, 0x12, 0xab, 0xa0};

//PIn Definitons Encoders V1:

//#define ENC_1_CLK 25
//#define ENC_1_DT 26

//#define ENC_2_CLK 13
//#define ENC_2_DT 14

//#define ENC_3_CLK 33
//#define ENC_3_DT 32

//#define ENC_4_CLK 19
//#define ENC_4_DT 27
//OneButton Button1(35, false);
//OneButton Button2(38, false);
//OneButton Button3(18, false);
//#define ANALOGIN 36 

//PIn Definitons Encoders V2:

#define ENC_1_CLK 25
#define ENC_1_DT 26

#define ENC_2_CLK 13
#define ENC_2_DT 14

#define ENC_3_CLK 33
#define ENC_3_DT 32

#define ENC_4_CLK 19
#define ENC_4_DT 27
OneButton Button1(35, false); //MX Button
OneButton Button2(36, false); //Encoder Left
OneButton Button3(34, false, true); // Encoder Right



#define Encoder_MAP 84




// Color 
#define TextColor  TFT_PURPLE
#define BgColor    TFT_WHITE
#define FrontColor TFT_PURPLE
#define HighlightColor TFT_BLACK

// Language
#define T_HEADER            "Poundinator"
#define T_CON               "CON"
#define T_BLANK             ""
#define T_MENUE             "Menue"
#define T_CONNECT           "Connect"
#define T_START             "Start"
#define T_STOP              "Stop"
#define T_CUM               "Cum"
#define T_HOME              "Home"
#define T_MEN1              "Up"
#define T_MEN2              "Down"
#define T_SPEED             "Speed:"
#define T_DEPTH             "Depth:"
#define T_MM                " mm"
#define T_STROKE            "Stroke:"
#define T_SENSATION         "Sensation:"
#define T_SETUP_DEPTH_I     "Setup Depth Interactively"
#define T_SETUP_DEPTH_F     "Setup Depth Fancy"
#define T_SELECT_PATTERN    "Select Pattern"
#define T_RESTART           "Restart"
#define T_SETUP_TORQE       "Setup Troqe"
#define T_OUT_TORQE         "Out Torqe:"
#define T_IN_TORQE          "In Torqe:"

#define T_Patterns          "Patterns"
#define T_SimpleStroke      "Simple Stroke"
#define T_TeasingPounding   "Teasing or Pounding"
#define T_RoboStroke        "Robo Stroke"
#define T_HalfnHalf         "HalfnHalf"
#define T_Deeper            "Deeper"
#define T_StopNGo           "Stop'n'Go"
#define T_Insist            "Insist"
#define T_JackHammer        "Jack Hammer"
#define T_StrokeNibbler     "Stroke Nibbler"

#define T_CUM_SPEED         "CUM Speed"
#define T_CUM_TIME          "CUM Time"
#define T_CUM_Volume        "CUM Volume"
#define T_CUM_Accel         "CUM Accel"

#define T_FUCKS_MIN         " F/m"
