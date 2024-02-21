#include "ui.h"
#include "ui_helpers.h"
#include "main.h"
#include "language.h"


///////////////////// VARIABLES ////////////////////
// SCREEN: ui_Start

lv_obj_t * ui_Start;
lv_obj_t * ui_Logo;
lv_obj_t * ui_StartButtonL;
lv_obj_t * ui_StartButtonLText;
lv_obj_t * ui_StartButtonM;
lv_obj_t * ui_StartButtonMText;
lv_obj_t * ui_StartButtonR;
lv_obj_t * ui_StartButtonRText;
lv_obj_t * ui_LOVE_Logo;
lv_obj_t * ui_Welcome;
lv_obj_t * ui_Batt;
lv_obj_t * ui_BattValue;
lv_obj_t * ui_Battery;
lv_obj_t * ui_connect_start;

// SCREEN: ui_Connect

lv_obj_t * ui_Connect;
lv_obj_t * ui_ConnectButtonL;
lv_obj_t * ui_ConnectButtonLText;
lv_obj_t * ui_ConnectButtonM;
lv_obj_t * ui_ConnectButtonMText;
lv_obj_t * ui_ConnectButtonR;
lv_obj_t * ui_ConnectButtonRText;
lv_obj_t * ui_Connect_Batt;
lv_obj_t * ui_Connect_BattValue;
lv_obj_t * ui_Connect_Battery;
lv_obj_t * ui_connect_connect;
lv_obj_t * ui_connect_roller;
lv_obj_t * ui_connect_spinner;

// SCREEN: ui_Home

lv_obj_t * ui_Home;
lv_obj_t * ui_Logo2;
lv_obj_t * ui_HomeButtonL;  
lv_obj_t * ui_HomeButtonLText;
lv_obj_t * ui_HomeButtonM;
lv_obj_t * ui_HomeButtonMText;
lv_obj_t * ui_HomeButtonR;
lv_obj_t * ui_HomeButtonRText;
lv_obj_t * ui_SpeedL;
lv_obj_t * ui_homespeedslider;
lv_obj_t * ui_homespeedvalue;
lv_obj_t * ui_DepthL;
lv_obj_t * ui_homedepthslider;
lv_obj_t * ui_homedepthvalue;
lv_obj_t * ui_StrokeL;
lv_obj_t * ui_homestrokeslider;
lv_obj_t * ui_homestrokevalue;
lv_obj_t * ui_SensationL;
lv_obj_t * ui_homesensationslider;
lv_obj_t * ui_Batt2;
lv_obj_t * ui_BattValue2;
lv_obj_t * ui_Battery2;
lv_obj_t * ui_HomePatternLabel1;
lv_obj_t * ui_HomePatternLabel;
lv_obj_t * ui_connect_home;

// SCREEN: ui_Menue

lv_obj_t * ui_Menue;
lv_obj_t * ui_Logo3;
lv_obj_t * ui_MenueButtonL;
lv_obj_t * ui_MenueButtonLText;
lv_obj_t * ui_MenueButtonM;
lv_obj_t * ui_MenueButtonMText;
lv_obj_t * ui_MenueButtonR;
lv_obj_t * ui_MenueButtonRText;
lv_obj_t * ui_Batt3;
lv_obj_t * ui_BattValue3;
lv_obj_t * ui_Battery3;
lv_obj_t * ui_SDepthI;
lv_obj_t * ui_SDepthIL;
lv_obj_t * ui_SDepthF;
lv_obj_t * ui_SDepthFL;
lv_obj_t * ui_SPattern;
lv_obj_t * ui_SPatternL;
lv_obj_t * ui_STorqe;
lv_obj_t * ui_STorqeL;
lv_obj_t * ui_EJECTSettingButton;
lv_obj_t * ui_EJECTSettingButtonText;

// SCREEN: ui_Pattern

lv_obj_t * ui_Pattern;
lv_obj_t * ui_Logo5;
lv_obj_t * ui_PatternButtonL;
lv_obj_t * ui_PatternButtonLText;
lv_obj_t * ui_PatternButtonM;
lv_obj_t * ui_PatternButtonMText;
lv_obj_t * ui_PatternButtonR;
lv_obj_t * ui_PatternButtonRText;
lv_obj_t * ui_Batt5;
lv_obj_t * ui_BattValue5;
lv_obj_t * ui_Battery5;
lv_obj_t * ui_Label4;
lv_obj_t * ui_PatternS;

// SCREEN: ui_Torqe

lv_obj_t * ui_Torqe;
lv_obj_t * ui_Logo4;
lv_obj_t * ui_TorqeButtonL;
lv_obj_t * ui_TorqeButtonLText;
lv_obj_t * ui_TorqeButtonM;
lv_obj_t * ui_TorqeButtonMText;
lv_obj_t * ui_TorqeButtonR;
lv_obj_t * ui_TorqeButtonRText;
lv_obj_t * ui_outtroqelabel;
lv_obj_t * ui_outtroqevalue;
lv_obj_t * ui_outtroqeslider;
lv_obj_t * ui_Low1;
lv_obj_t * ui_High1;
lv_obj_t * ui_introqelabel;
lv_obj_t * ui_introqevalue;
lv_obj_t * ui_introqeslider;
lv_obj_t * ui_Low2;
lv_obj_t * ui_High;
lv_obj_t * ui_Batt4;
lv_obj_t * ui_BattValue4;
lv_obj_t * ui_Battery4;

// SCREEN: ui_EJECTSettings

lv_obj_t * ui_EJECTSettings;
lv_obj_t * ui_Logo6;
lv_obj_t * ui_EJECTButtonL;
lv_obj_t * ui_EJECTButtonLText;
lv_obj_t * ui_EJECTButtonM;
lv_obj_t * ui_EJECTButtonMText;
lv_obj_t * ui_EJECTButtonR;
lv_obj_t * ui_EJECTButtonRText;
lv_obj_t * ui_Batt6;
lv_obj_t * ui_BattValue6;
lv_obj_t * ui_Battery6;
lv_obj_t * ui_Settings;
lv_obj_t * ui_Logo1;
lv_obj_t * ui_SettingsButtonL;
lv_obj_t * ui_SettingsButtonLText;
lv_obj_t * ui_SettingsButtonM;
lv_obj_t * ui_SettingsButtonMText;
lv_obj_t * ui_SettingsButtonR;
lv_obj_t * ui_SettingsButtonRText;
lv_obj_t * ui_Batt1;
lv_obj_t * ui_BattValue1;
lv_obj_t * ui_Battery1;
lv_obj_t * ui_ejectaddon;
lv_obj_t * ui_darkmode;
lv_obj_t * ui_vibrate;
lv_obj_t * ui_lefty;
lv_group_t * ui_g_menue;
lv_group_t * ui_g_settings;


///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "#error LV_COLOR_16_SWAP should be 0
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

// START SCREEN //
void ui_event_Start(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_SCREEN_LOADED) {
        screenmachine(e);
    }
}
void ui_event_StartButtonL(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Connect, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
    }
}
void ui_event_StartButtonM(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
    }
}
void ui_event_StartButtonR(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
    }
}

// CONNECT SCREEN //
void ui_event_Connect(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_SCREEN_LOADED) {
        screenmachine(e);
        scanmdns(e);
    }
}
void ui_event_ConnectButtonL(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
    }
}
void ui_event_ConnectButtonM(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        scanmdns(e);
    }
}
void ui_event_ConnectButtonR(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        connectbutton(e);
    }
}


// HOME SCREEN //
void ui_event_Home(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_SCREEN_LOADED) {
        screenmachine(e);
    }
}
void ui_event_HomeButtonL(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        //ejectcreampie(e);
    }
}
void ui_event_HomeButtonM(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        homebuttonmevent(e);
    }
}
void ui_event_HomeButtonR(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Pattern, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
    } else if(event == LV_EVENT_LONG_PRESSED){
        _ui_screen_change(ui_Menue, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
    }
}

// MENUE SCREEN //
void ui_event_Menue(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_SCREEN_LOADED) {
        screenmachine(e);
    }
}
void ui_event_MenueButtonL(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
    }
}
void ui_event_MenueButtonM(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
    }
}
void ui_event_MenueButtonR(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
}
void ui_event_SDepthI(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
        setupDepthInter(e);
    }
}
void ui_event_SDepthF(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        setupdepthF(e);
        _ui_screen_change(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
    }
}
void ui_event_SPattern(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Pattern, LV_SCR_LOAD_ANIM_FADE_ON, 90, 0);
    }
}
void ui_event_STorqe(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Torqe, LV_SCR_LOAD_ANIM_FADE_ON, 90, 0);
    }
}
void ui_event_EJECTSettingButton(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_EJECTSettings, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
    }
}

// PATTERN SCREEN //
void ui_event_Pattern(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_SCREEN_LOADED) {
        screenmachine(e);
    }
}
void ui_event_PatternButtonL(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Menue, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
    }
}
void ui_event_PatternButtonM(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
    }
}
void ui_event_PatternButtonR(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
        savepattern(e);
    }
}

// TORQE SCREEN //
void ui_event_Torqe(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_SCREEN_LOADED) {
        screenmachine(e);
    }
}
void ui_event_TorqeButtonL(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
}
void ui_event_TorqeButtonM(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
    }
}
void ui_event_TorqeButtonR(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Menue, LV_SCR_LOAD_ANIM_FADE_ON, 90, 0);
    }
}

// EJECTSETTINGS SCREEN //
void ui_event_EJECTSettings(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_SCREEN_LOADED) {
        screenmachine(e);
    }
}
void ui_event_EJECTButtonL(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
}
void ui_event_EJECTButtonM(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 90, 0);
    }
}
void ui_event_EJECTButtonR(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Menue, LV_SCR_LOAD_ANIM_FADE_ON, 90, 0);
    }
}

// SETTINGS SCREEN //
void ui_event_Settings(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_SCREEN_LOADED) {
        screenmachine(e);
    }
}
void ui_event_SettingsButtonL(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        savesettings(e);
    }
}
void ui_event_SettingsButtonM(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 90, 0);
    }
}
void ui_event_SettingsButtonR(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Menue, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
    }
}
void ui_event_ejectaddon(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
}


void ui_m5init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_color_hex(0x83247B), lv_color_hex(0xD591D5), dark_mode, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Start_screen_init();
    ui_Connect_screen_init();
    ui_Home_screen_init();
    ui_Menue_screen_init();
    ui_Pattern_screen_init();
    ui_Torqe_screen_init();
    ui_EJECTSettings_screen_init();
    ui_Settings_screen_init();
    lv_disp_load_scr(ui_Start);
}