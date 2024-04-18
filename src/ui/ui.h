//#ifndef _OSSM-WHITE_UI_H
#define _OSSM-WHITE_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if __has_include("lvgl.h")
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


// SCREEN: ui_Start
void ui_Start_screen_init(void);
void ui_event_Start(lv_event_t * e);
extern lv_obj_t * ui_Start;
extern lv_obj_t * ui_Logo;
extern lv_obj_t * ui_StartButtonL;
extern lv_obj_t * ui_StartButtonLText;
void ui_event_StartButtonL(lv_event_t * e);
extern lv_obj_t * ui_StartButtonM;
extern lv_obj_t * ui_StartButtonMText;
void ui_event_StartButtonM(lv_event_t * e);
extern lv_obj_t * ui_StartButtonR;
extern lv_obj_t * ui_StartButtonRText;
void ui_event_StartButtonR(lv_event_t * e);
extern lv_obj_t * ui_LOVE_Logo;
extern lv_obj_t * ui_Welcome;
extern lv_obj_t * ui_Batt;
extern lv_obj_t * ui_BattValue;
extern lv_obj_t * ui_Battery;
extern lv_obj_t * ui_connect_start;

// SCREEN: ui_Connect

void ui_Connect_screen_init(void);
void ui_event_Connect(lv_event_t * e);
lv_obj_t * ui_Connect;
lv_obj_t * ui_ConnectButtonL;
lv_obj_t * ui_ConnectButtonLText;
void ui_event_ConnectButtonL(lv_event_t * e);
lv_obj_t * ui_ConnectButtonM;
lv_obj_t * ui_ConnectButtonMText;
void ui_event_ConnectButtonM(lv_event_t * e);
lv_obj_t * ui_ConnectButtonR;
lv_obj_t * ui_ConnectButtonRText;
void ui_event_ConnectButtonR(lv_event_t * e);
lv_obj_t * ui_Connect_Batt;
lv_obj_t * ui_Connect_BattValue;
lv_obj_t * ui_Connect_Battery;
lv_obj_t * ui_connect_connect;
lv_obj_t * ui_connect_roller;
lv_obj_t * ui_connect_spinner;


// SCREEN: ui_Home

void ui_Home_screen_init(void);
void ui_event_Home(lv_event_t * e);
extern lv_obj_t * ui_Home;
extern lv_obj_t * ui_Logo2;
extern lv_obj_t * ui_HomeButtonL;
extern lv_obj_t * ui_HomeButtonLText;
void ui_event_HomeButtonL(lv_event_t * e);
extern lv_obj_t * ui_HomeButtonM;
extern lv_obj_t * ui_HomeButtonMText;
void ui_event_HomeButtonM(lv_event_t * e);
extern lv_obj_t * ui_HomeButtonR;
extern lv_obj_t * ui_HomeButtonRText;
void ui_event_HomeButtonR(lv_event_t * e);
extern lv_obj_t * ui_SpeedL;
extern lv_obj_t * ui_homespeedslider;
extern lv_obj_t * ui_homespeedvalue;
extern lv_obj_t * ui_DepthL;
extern lv_obj_t * ui_homedepthslider;
extern lv_obj_t * ui_homedepthvalue;
extern lv_obj_t * ui_StrokeL;
extern lv_obj_t * ui_homestrokeslider;
extern lv_obj_t * ui_homestrokevalue;
extern lv_obj_t * ui_SensationL;
extern lv_obj_t * ui_homesensationslider;
extern lv_obj_t * ui_Batt2;
extern lv_obj_t * ui_BattValue2;
extern lv_obj_t * ui_Battery2;
extern lv_obj_t * ui_HomePatternLabel1;
extern lv_obj_t * ui_HomePatternLabel;
extern lv_obj_t * ui_connect_home;

// SCREEN: ui_Menue

void ui_Menue_screen_init(void);
void ui_event_Menue(lv_event_t * e);
extern lv_obj_t * ui_Menue;
extern lv_obj_t * ui_Logo3;
extern lv_obj_t * ui_MenueButtonL;
extern lv_obj_t * ui_MenueButtonLText;
void ui_event_MenueButtonL(lv_event_t * e);
extern lv_obj_t * ui_MenueButtonM;
extern lv_obj_t * ui_MenueButtonMText;
void ui_event_MenueButtonM(lv_event_t * e);
extern lv_obj_t * ui_MenueButtonR;
extern lv_obj_t * ui_MenueButtonRText;
void ui_event_MenueButtonR(lv_event_t * e);
extern lv_obj_t * ui_Batt3;
extern lv_obj_t * ui_BattValue3;
extern lv_obj_t * ui_Battery3;
extern lv_obj_t * ui_SDepthI;
extern lv_obj_t * ui_SDepthIL;
void ui_event_SDepthI(lv_event_t * e);
extern lv_obj_t * ui_SDepthF;
extern lv_obj_t * ui_SDepthFL;
void ui_event_SDepthF(lv_event_t * e);
extern lv_obj_t * ui_SPattern;
extern lv_obj_t * ui_SPatternL;
void ui_event_SPattern(lv_event_t * e);
extern lv_obj_t * ui_STorqe;
extern lv_obj_t * ui_STorqeL;
void ui_event_STorqe(lv_event_t * e);
extern lv_obj_t * ui_EJECTSettingButton;
extern lv_obj_t * ui_EJECTSettingButtonText;
void ui_event_EJECTSettingButton(lv_event_t * e);

// SCREEN: ui_Pattern
void ui_Pattern_screen_init(void);
void ui_event_Pattern(lv_event_t * e);
extern lv_obj_t * ui_Pattern;
extern lv_obj_t * ui_Logo5;
extern lv_obj_t * ui_PatternButtonL;
extern lv_obj_t * ui_PatternButtonLText;
void ui_event_PatternButtonL(lv_event_t * e);
extern lv_obj_t * ui_PatternButtonM;
extern lv_obj_t * ui_PatternButtonMText;
void ui_event_PatternButtonM(lv_event_t * e);
extern lv_obj_t * ui_PatternButtonR;
extern lv_obj_t * ui_PatternButtonRText;
void ui_event_PatternButtonR(lv_event_t * e);
extern lv_obj_t * ui_Batt5;
extern lv_obj_t * ui_BattValue5;
extern lv_obj_t * ui_Battery5;
extern lv_obj_t * ui_Label4;
extern lv_obj_t * ui_PatternS;

// SCREEN: ui_Torqe
void ui_Torqe_screen_init(void);
void ui_event_Torqe(lv_event_t * e);
extern lv_obj_t * ui_Torqe;
extern lv_obj_t * ui_Logo4;
extern lv_obj_t * ui_TorqeButtonL;
extern lv_obj_t * ui_TorqeButtonLText;
void ui_event_TorqeButtonL(lv_event_t * e);
extern lv_obj_t * ui_TorqeButtonM;
extern lv_obj_t * ui_TorqeButtonMText;
void ui_event_TorqeButtonM(lv_event_t * e);
extern lv_obj_t * ui_TorqeButtonR;
extern lv_obj_t * ui_TorqeButtonRText;
void ui_event_TorqeButtonR(lv_event_t * e);
extern lv_obj_t * ui_outtroqelabel;
extern lv_obj_t * ui_outtroqevalue;
extern lv_obj_t * ui_outtroqeslider;
extern lv_obj_t * ui_Low1;
extern lv_obj_t * ui_High1;
extern lv_obj_t * ui_introqelabel;
extern lv_obj_t * ui_introqevalue;
extern lv_obj_t * ui_introqeslider;
extern lv_obj_t * ui_Low2;
extern lv_obj_t * ui_High;
extern lv_obj_t * ui_Batt4;
extern lv_obj_t * ui_BattValue4;
extern lv_obj_t * ui_Battery4;

// SCREEN: ui_EJECTSettings
void ui_EJECTSettings_screen_init(void);
void ui_event_EJECTSettings(lv_event_t * e);
extern lv_obj_t * ui_EJECTSettings;
extern lv_obj_t * ui_Logo6;
extern lv_obj_t * ui_EJECTButtonL;
extern lv_obj_t * ui_EJECTButtonLText;
void ui_event_EJECTButtonL(lv_event_t * e);
extern lv_obj_t * ui_EJECTButtonM;
extern lv_obj_t * ui_EJECTButtonMText;
void ui_event_EJECTButtonM(lv_event_t * e);
extern lv_obj_t * ui_EJECTButtonR;
extern lv_obj_t * ui_EJECTButtonRText;
void ui_event_EJECTButtonR(lv_event_t * e);
extern lv_obj_t * ui_Batt6;
extern lv_obj_t * ui_BattValue6;
extern lv_obj_t * ui_Battery6;

// SCREEN: ui_Settings
void ui_Settings_screen_init(void);
void ui_event_Settings(lv_event_t * e);
extern lv_obj_t * ui_Settings;
extern lv_obj_t * ui_Logo1;
extern lv_obj_t * ui_SettingsButtonL;
extern lv_obj_t * ui_SettingsButtonLText;
void ui_event_SettingsButtonL(lv_event_t * e);
extern lv_obj_t * ui_SettingsButtonM;
extern lv_obj_t * ui_SettingsButtonMText;
void ui_event_SettingsButtonM(lv_event_t * e);
extern lv_obj_t * ui_SettingsButtonR;
extern lv_obj_t * ui_SettingsButtonRText;
void ui_event_SettingsButtonR(lv_event_t * e);
extern lv_obj_t * ui_Batt1;
extern lv_obj_t * ui_BattValue1;
extern lv_obj_t * ui_Battery1;
extern lv_obj_t * ui_ejectaddon;
void ui_event_ejectaddon(lv_event_t * e);
extern lv_obj_t * ui_darkmode;
extern lv_obj_t * ui_vibrate;
extern lv_obj_t * ui_lefty;
extern lv_group_t * ui_g_menue;
extern lv_group_t * ui_g_settings;


void screenmachine(lv_event_t * e);
void scanmdns(lv_event_t * e);
void connectbutton(lv_event_t * e);
void ejectcreampie(lv_event_t * e);
void homebuttonmevent(lv_event_t * e);
void setupDepthInter(lv_event_t * e);
void setupdepthF(lv_event_t * e);
void savepattern(lv_event_t * e);
void savesettings(lv_event_t * e);
void demo(lv_event_t * e);

LV_IMG_DECLARE(image50x50);    // assets\logo.svg

void ui_m5init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif