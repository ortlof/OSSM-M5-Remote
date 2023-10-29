// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: OSSM-White

#include "ui.h"
#include "ui_helpers.h"
#include "main.h"
#include "language.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Start;
lv_obj_t * ui_Logo;
lv_obj_t * ui_StartButtonL;
lv_obj_t * ui_StartButtonLText;
lv_obj_t * ui_StartButtonM;
lv_obj_t * ui_StartButtonMText;
lv_obj_t * ui_StartButtonR;
lv_obj_t * ui_StartButtonRText;
lv_obj_t * ui_KMLogo;
lv_obj_t * ui_OrtlofLogo;
lv_obj_t * ui_Welcome;
lv_obj_t * ui_Batt;
lv_obj_t * ui_BattValue;
lv_obj_t * ui_Battery;
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
lv_obj_t * ui_connect;
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
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "#error LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
static void ui_event_Start(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_SCREEN_LOADED) {
        screenmachine(e);
    }
}
static void ui_event_StartButtonL(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        connectbutton(e);
    }
}
static void ui_event_StartButtonM(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
    }
}
static void ui_event_StartButtonR(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
    }
}
static void ui_event_Home(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_SCREEN_LOADED) {
        screenmachine(e);
    }
}
static void ui_event_HomeButtonL(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        //ejectcreampie(e);
    }
}
static void ui_event_HomeButtonM(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        homebuttonmevent(e);
    }
}
static void ui_event_HomeButtonR(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Pattern, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
    } else if(event == LV_EVENT_LONG_PRESSED){
        _ui_screen_change(ui_Menue, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
    }
}
static void ui_event_Menue(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_SCREEN_LOADED) {
        screenmachine(e);
    }
}
static void ui_event_MenueButtonL(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
    }
}
static void ui_event_MenueButtonM(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
    }
}
static void ui_event_MenueButtonR(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
}
static void ui_event_SDepthI(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
        setupDepthInter(e);
    }
}
static void ui_event_SDepthF(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        setupdepthF(e);
        _ui_screen_change(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
    }
}
static void ui_event_SPattern(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Pattern, LV_SCR_LOAD_ANIM_FADE_ON, 90, 0);
    }
}
static void ui_event_STorqe(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Torqe, LV_SCR_LOAD_ANIM_FADE_ON, 90, 0);
    }
}
static void ui_event_EJECTSettingButton(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_EJECTSettings, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
    }
}
static void ui_event_Pattern(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_SCREEN_LOADED) {
        screenmachine(e);
    }
}
static void ui_event_PatternButtonL(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Menue, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
    }
}
static void ui_event_PatternButtonM(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
    }
}
static void ui_event_PatternButtonR(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
        savepattern(e);
    }
}
static void ui_event_Torqe(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_SCREEN_LOADED) {
        screenmachine(e);
    }
}
static void ui_event_TorqeButtonL(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
}
static void ui_event_TorqeButtonM(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
    }
}
static void ui_event_TorqeButtonR(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Menue, LV_SCR_LOAD_ANIM_FADE_ON, 90, 0);
    }
}
static void ui_event_EJECTSettings(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_SCREEN_LOADED) {
        screenmachine(e);
    }
}
static void ui_event_EJECTButtonL(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
}
static void ui_event_EJECTButtonM(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 90, 0);
    }
}
static void ui_event_EJECTButtonR(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Menue, LV_SCR_LOAD_ANIM_FADE_ON, 90, 0);
    }
}
static void ui_event_Settings(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_SCREEN_LOADED) {
        screenmachine(e);
    }
}
static void ui_event_SettingsButtonL(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        savesettings(e);
    }
}
static void ui_event_SettingsButtonM(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 90, 0);
    }
}
static void ui_event_SettingsButtonR(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Menue, LV_SCR_LOAD_ANIM_FADE_ON, 20, 0);
    }
}
static void ui_event_ejectaddon(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
}

///////////////////// SCREENS ////////////////////
void ui_Start_screen_init(void)
{

    // ui_Start

    ui_Start = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Start, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_Start, ui_event_Start, LV_EVENT_ALL, NULL);


    // ui_Logo

    ui_Logo = lv_label_create(ui_Start);

    lv_obj_set_width(ui_Logo, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Logo, LV_SIZE_CONTENT);

    lv_obj_set_y(ui_Logo, -103);
    lv_obj_set_x(ui_Logo, lv_pct(0));

    lv_obj_set_align(ui_Logo, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Logo, T_HEADER);

    lv_obj_set_style_text_font(ui_Logo, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Logo, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Logo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Logo, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Logo, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_StartButtonL

    ui_StartButtonL = lv_btn_create(ui_Start);

    lv_obj_set_width(ui_StartButtonL, 100);
    lv_obj_set_height(ui_StartButtonL, 30);

    lv_obj_set_y(ui_StartButtonL, 100);
    lv_obj_set_x(ui_StartButtonL, lv_pct(-33));

    lv_obj_set_align(ui_StartButtonL, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_StartButtonL, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_StartButtonL, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_StartButtonL, ui_event_StartButtonL, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_StartButtonL, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_StartButtonL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_StartButtonLText

    ui_StartButtonLText = lv_label_create(ui_StartButtonL);

    lv_obj_set_width(ui_StartButtonLText, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_StartButtonLText, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_StartButtonLText, lv_pct(0));
    lv_obj_set_y(ui_StartButtonLText, lv_pct(0));

    lv_obj_set_align(ui_StartButtonLText, LV_ALIGN_CENTER);

    lv_label_set_text(ui_StartButtonLText, T_CONNECT);

    lv_obj_set_style_text_color(ui_StartButtonLText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_StartButtonLText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_StartButtonM

    ui_StartButtonM = lv_btn_create(ui_Start);

    lv_obj_set_width(ui_StartButtonM, 100);
    lv_obj_set_height(ui_StartButtonM, 30);

    lv_obj_set_y(ui_StartButtonM, 100);
    lv_obj_set_x(ui_StartButtonM, lv_pct(0));

    lv_obj_set_align(ui_StartButtonM, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_StartButtonM, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_StartButtonM, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_StartButtonM, ui_event_StartButtonM, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_StartButtonM, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_StartButtonM, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_StartButtonMText

    ui_StartButtonMText = lv_label_create(ui_StartButtonM);

    lv_obj_set_width(ui_StartButtonMText, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_StartButtonMText, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_StartButtonMText, lv_pct(0));
    lv_obj_set_y(ui_StartButtonMText, lv_pct(0));

    lv_obj_set_align(ui_StartButtonMText, LV_ALIGN_CENTER);

    lv_label_set_text(ui_StartButtonMText, T_SETTINGS);

    lv_obj_set_style_text_color(ui_StartButtonMText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_StartButtonMText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_StartButtonR

    ui_StartButtonR = lv_btn_create(ui_Start);

    lv_obj_set_width(ui_StartButtonR, 100);
    lv_obj_set_height(ui_StartButtonR, 30);

    lv_obj_set_y(ui_StartButtonR, 100);
    lv_obj_set_x(ui_StartButtonR, lv_pct(33));

    lv_obj_set_align(ui_StartButtonR, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_StartButtonR, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_StartButtonR, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_StartButtonR, ui_event_StartButtonR, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_StartButtonR, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_StartButtonR, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_StartButtonRText

    ui_StartButtonRText = lv_label_create(ui_StartButtonR);

    lv_obj_set_width(ui_StartButtonRText, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_StartButtonRText, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_StartButtonRText, lv_pct(0));
    lv_obj_set_y(ui_StartButtonRText, lv_pct(0));

    lv_obj_set_align(ui_StartButtonRText, LV_ALIGN_CENTER);

    lv_label_set_text(ui_StartButtonRText, T_DEMO);

    lv_obj_set_style_text_color(ui_StartButtonRText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_StartButtonRText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_KMLogo

    ui_KMLogo = lv_img_create(ui_Start);
    lv_img_set_src(ui_KMLogo, &ui_img_km__png);

    lv_obj_set_width(ui_KMLogo, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_KMLogo, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_KMLogo, -80);
    lv_obj_set_y(ui_KMLogo, 0);

    lv_obj_set_align(ui_KMLogo, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_KMLogo, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_KMLogo, LV_OBJ_FLAG_SCROLLABLE);

    // ui_OrtlofLogo

    ui_OrtlofLogo = lv_img_create(ui_Start);
    lv_img_set_src(ui_OrtlofLogo, &ui_img_ortlodof_png);

    lv_obj_set_width(ui_OrtlofLogo, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_OrtlofLogo, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_OrtlofLogo, 80);
    lv_obj_set_y(ui_OrtlofLogo, 0);

    lv_obj_set_align(ui_OrtlofLogo, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_OrtlofLogo, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_OrtlofLogo, LV_OBJ_FLAG_SCROLLABLE);

    // ui_Welcome

    ui_Welcome = lv_label_create(ui_Start);

    lv_obj_set_width(ui_Welcome, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Welcome, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Welcome, 0);
    lv_obj_set_y(ui_Welcome, -70);

    lv_obj_set_align(ui_Welcome, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Welcome, T_MOTD);

    // ui_Batt

    ui_Batt = lv_label_create(ui_Start);

    lv_obj_set_width(ui_Batt, 85);
    lv_obj_set_height(ui_Batt, 30);

    lv_obj_set_x(ui_Batt, 115);
    lv_obj_set_y(ui_Batt, -103);

    lv_obj_set_align(ui_Batt, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Batt, T_BATT);

    // ui_BattValue

    ui_BattValue = lv_label_create(ui_Batt);

    lv_obj_set_width(ui_BattValue, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_BattValue, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_BattValue, 0);
    lv_obj_set_y(ui_BattValue, -7);

    lv_obj_set_align(ui_BattValue, LV_ALIGN_RIGHT_MID);

    lv_label_set_text(ui_BattValue, T_BLANK);

    // ui_Battery

    ui_Battery = lv_bar_create(ui_Batt);
    lv_bar_set_range(ui_Battery, 0, 100);

    lv_obj_set_width(ui_Battery, 80);
    lv_obj_set_height(ui_Battery, 10);

    lv_obj_set_x(ui_Battery, 0);
    lv_obj_set_y(ui_Battery, 10);

    lv_obj_set_align(ui_Battery, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_Battery, lv_color_hex(0xD591D5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Battery, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Battery, lv_color_hex(0x83247B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Battery, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

}
void ui_Home_screen_init(void)
{

    // ui_Home

    ui_Home = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Home, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_Home, ui_event_Home, LV_EVENT_ALL, NULL);

    // ui_Logo2

    ui_Logo2 = lv_label_create(ui_Home);

    lv_obj_set_width(ui_Logo2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Logo2, LV_SIZE_CONTENT);

    lv_obj_set_y(ui_Logo2, -103);
    lv_obj_set_x(ui_Logo2, lv_pct(0));

    lv_obj_set_align(ui_Logo2, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Logo2, T_HEADER);

    lv_obj_set_style_text_font(ui_Logo2, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Logo2, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Logo2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Logo2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Logo2, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_HomeButtonL

    ui_HomeButtonL = lv_btn_create(ui_Home);

    lv_obj_set_width(ui_HomeButtonL, 100);
    lv_obj_set_height(ui_HomeButtonL, 30);

    lv_obj_set_y(ui_HomeButtonL, 100);
    lv_obj_set_x(ui_HomeButtonL, lv_pct(-33));

    lv_obj_set_align(ui_HomeButtonL, LV_ALIGN_CENTER);

    lv_obj_add_state(ui_HomeButtonL, LV_STATE_DISABLED);

    lv_obj_add_flag(ui_HomeButtonL, LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_HomeButtonL, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_HomeButtonL, ui_event_HomeButtonL, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_HomeButtonL, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_HomeButtonL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_HomeButtonLText

    ui_HomeButtonLText = lv_label_create(ui_HomeButtonL);

    lv_obj_set_width(ui_HomeButtonLText, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_HomeButtonLText, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_HomeButtonLText, lv_pct(0));
    lv_obj_set_y(ui_HomeButtonLText, lv_pct(0));

    lv_obj_set_align(ui_HomeButtonLText, LV_ALIGN_CENTER);

    lv_label_set_text(ui_HomeButtonLText, T_CREAMPIE);

    lv_obj_set_style_text_color(ui_HomeButtonLText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_HomeButtonLText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_HomeButtonM

    ui_HomeButtonM = lv_btn_create(ui_Home);

    lv_obj_set_width(ui_HomeButtonM, 100);
    lv_obj_set_height(ui_HomeButtonM, 30);

    lv_obj_set_y(ui_HomeButtonM, 100);
    lv_obj_set_x(ui_HomeButtonM, lv_pct(0));

    lv_obj_set_align(ui_HomeButtonM, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_HomeButtonM, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_HomeButtonM, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_HomeButtonM, ui_event_HomeButtonM, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_HomeButtonM, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_HomeButtonM, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_HomeButtonMText

    ui_HomeButtonMText = lv_label_create(ui_HomeButtonM);

    lv_obj_set_width(ui_HomeButtonMText, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_HomeButtonMText, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_HomeButtonMText, lv_pct(0));
    lv_obj_set_y(ui_HomeButtonMText, lv_pct(0));

    lv_obj_set_align(ui_HomeButtonMText, LV_ALIGN_CENTER);

    lv_label_set_text(ui_HomeButtonMText, T_START);

    lv_obj_set_style_text_color(ui_HomeButtonMText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_HomeButtonMText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_HomeButtonR

    ui_HomeButtonR = lv_btn_create(ui_Home);

    lv_obj_set_width(ui_HomeButtonR, 100);
    lv_obj_set_height(ui_HomeButtonR, 30);

    lv_obj_set_y(ui_HomeButtonR, 100);
    lv_obj_set_x(ui_HomeButtonR, lv_pct(33));

    lv_obj_set_align(ui_HomeButtonR, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_HomeButtonR, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_HomeButtonR, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_HomeButtonR, ui_event_HomeButtonR, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_HomeButtonR, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_HomeButtonR, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_HomeButtonRText

    ui_HomeButtonRText = lv_label_create(ui_HomeButtonR);

    lv_obj_set_width(ui_HomeButtonRText, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_HomeButtonRText, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_HomeButtonRText, lv_pct(0));
    lv_obj_set_y(ui_HomeButtonRText, lv_pct(0));

    lv_obj_set_align(ui_HomeButtonRText, LV_ALIGN_CENTER);

    lv_label_set_text(ui_HomeButtonRText, T_PATTERN_Button);

    lv_obj_set_style_text_color(ui_HomeButtonRText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_HomeButtonRText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_HomeButtonRText, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SpeedL

    ui_SpeedL = lv_label_create(ui_Home);

    lv_obj_set_width(ui_SpeedL, lv_pct(95));
    lv_obj_set_height(ui_SpeedL, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_SpeedL, 0);
    lv_obj_set_y(ui_SpeedL, -60);

    lv_obj_set_align(ui_SpeedL, LV_ALIGN_CENTER);

    lv_label_set_text(ui_SpeedL, T_SPEED);

    lv_obj_set_style_text_font(ui_SpeedL, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_homespeedslider

    ui_homespeedslider = lv_slider_create(ui_SpeedL);
    lv_slider_set_range(ui_homespeedslider, 0, speedlimit);
    lv_slider_set_mode(ui_homespeedslider, LV_SLIDER_MODE_SYMMETRICAL);

    lv_obj_set_width(ui_homespeedslider, 130);
    lv_obj_set_height(ui_homespeedslider, 10);

    lv_obj_set_x(ui_homespeedslider, -15);
    lv_obj_set_y(ui_homespeedslider, 0);

    lv_obj_set_align(ui_homespeedslider, LV_ALIGN_RIGHT_MID);

    lv_obj_set_style_bg_color(ui_homespeedslider, lv_color_hex(0xD691D0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_homespeedslider, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_homespeedslider, lv_color_hex(0x83277B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_homespeedslider, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_homespeedslider, lv_color_hex(0x83277B), LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_homespeedslider, lv_color_hex(0x83277B), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_homespeedslider, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    // ui_homespeedvalue

    ui_homespeedvalue = lv_label_create(ui_SpeedL);

    lv_obj_set_width(ui_homespeedvalue, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_homespeedvalue, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_homespeedvalue, 80);
    lv_obj_set_y(ui_homespeedvalue, 0);

    lv_obj_set_align(ui_homespeedvalue, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_homespeedvalue, T_BLANK);

    // ui_DepthL

    ui_DepthL = lv_label_create(ui_Home);

    lv_obj_set_width(ui_DepthL, lv_pct(95));
    lv_obj_set_height(ui_DepthL, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_DepthL, 0);
    lv_obj_set_y(ui_DepthL, -25);

    lv_obj_set_align(ui_DepthL, LV_ALIGN_CENTER);

    lv_label_set_text(ui_DepthL, T_DEPTH);

    lv_obj_set_style_text_font(ui_DepthL, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_homedepthslider

    ui_homedepthslider = lv_slider_create(ui_DepthL);
    lv_slider_set_range(ui_homedepthslider, 0, maxdepthinmm);

    lv_obj_set_width(ui_homedepthslider, 130);
    lv_obj_set_height(ui_homedepthslider, 10);

    lv_obj_set_x(ui_homedepthslider, -15);
    lv_obj_set_y(ui_homedepthslider, 0);

    lv_obj_set_align(ui_homedepthslider, LV_ALIGN_RIGHT_MID);

    lv_obj_set_style_bg_color(ui_homedepthslider, lv_color_hex(0xD691D0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_homedepthslider, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_homedepthslider, lv_color_hex(0x83277B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_homedepthslider, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_homedepthslider, lv_color_hex(0x83277B), LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_homedepthslider, lv_color_hex(0x83277B), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_homedepthslider, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    // ui_homedepthvalue

    ui_homedepthvalue = lv_label_create(ui_DepthL);

    lv_obj_set_width(ui_homedepthvalue, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_homedepthvalue, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_homedepthvalue, 80);
    lv_obj_set_y(ui_homedepthvalue, 0);

    lv_obj_set_align(ui_homedepthvalue, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_homedepthvalue, T_BLANK);

    // ui_StrokeL

    ui_StrokeL = lv_label_create(ui_Home);

    lv_obj_set_width(ui_StrokeL, lv_pct(95));
    lv_obj_set_height(ui_StrokeL, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_StrokeL, 0);
    lv_obj_set_y(ui_StrokeL, 10);

    lv_obj_set_align(ui_StrokeL, LV_ALIGN_CENTER);

    lv_label_set_text(ui_StrokeL, T_STROKE);

    lv_obj_set_style_text_font(ui_StrokeL, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_homestrokeslider

    ui_homestrokeslider = lv_slider_create(ui_StrokeL);
    lv_slider_set_range(ui_homestrokeslider, 0, maxdepthinmm);

    lv_obj_set_width(ui_homestrokeslider, 130);
    lv_obj_set_height(ui_homestrokeslider, 10);

    lv_obj_set_x(ui_homestrokeslider, -15);
    lv_obj_set_y(ui_homestrokeslider, 0);

    lv_obj_set_align(ui_homestrokeslider, LV_ALIGN_RIGHT_MID);

    lv_obj_set_style_bg_color(ui_homestrokeslider, lv_color_hex(0xD691D0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_homestrokeslider, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_homestrokeslider, lv_color_hex(0x83277B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_homestrokeslider, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_homestrokeslider, lv_color_hex(0x83277B), LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_homestrokeslider, lv_color_hex(0x83277B), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_homestrokeslider, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    // ui_homestrokevalue

    ui_homestrokevalue = lv_label_create(ui_StrokeL);

    lv_obj_set_width(ui_homestrokevalue, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_homestrokevalue, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_homestrokevalue, 80);
    lv_obj_set_y(ui_homestrokevalue, 0);

    lv_obj_set_align(ui_homestrokevalue, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_homestrokevalue, T_BLANK);

    // ui_SensationL

    ui_SensationL = lv_label_create(ui_Home);

    lv_obj_set_width(ui_SensationL, lv_pct(95));
    lv_obj_set_height(ui_SensationL, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_SensationL, 0);
    lv_obj_set_y(ui_SensationL, 45);

    lv_obj_set_align(ui_SensationL, LV_ALIGN_CENTER);

    lv_label_set_text(ui_SensationL, T_SENSATION);

    lv_obj_set_style_text_font(ui_SensationL, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_homesensationslider

    ui_homesensationslider = lv_slider_create(ui_SensationL);
    lv_slider_set_range(ui_homesensationslider, -100, 100);
    lv_slider_set_mode(ui_homesensationslider, LV_SLIDER_MODE_SYMMETRICAL);

    lv_obj_set_width(ui_homesensationslider, 170);
    lv_obj_set_height(ui_homesensationslider, 10);

    lv_obj_set_x(ui_homesensationslider, -15);
    lv_obj_set_y(ui_homesensationslider, 0);

    lv_obj_set_align(ui_homesensationslider, LV_ALIGN_RIGHT_MID);

    lv_obj_set_style_bg_color(ui_homesensationslider, lv_color_hex(0xD691D0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_homesensationslider, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_homesensationslider, lv_color_hex(0x83277B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_homesensationslider, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_homesensationslider, lv_color_hex(0x83277B), LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_homesensationslider, lv_color_hex(0x83277B), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_homesensationslider, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    // ui_Batt2

    ui_Batt2 = lv_label_create(ui_Home);

    lv_obj_set_width(ui_Batt2, 85);
    lv_obj_set_height(ui_Batt2, 30);

    lv_obj_set_x(ui_Batt2, 115);
    lv_obj_set_y(ui_Batt2, -103);

    lv_obj_set_align(ui_Batt2, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Batt2, T_BATT);

    // ui_BattValue2

    ui_BattValue2 = lv_label_create(ui_Batt2);

    lv_obj_set_width(ui_BattValue2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_BattValue2, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_BattValue2, 0);
    lv_obj_set_y(ui_BattValue2, -7);

    lv_obj_set_align(ui_BattValue2, LV_ALIGN_RIGHT_MID);

    lv_label_set_text(ui_BattValue2, T_BLANK);
    lv_label_set_recolor(ui_BattValue2, "true");

    // ui_Battery2

    ui_Battery2 = lv_bar_create(ui_Batt2);
    lv_bar_set_range(ui_Battery2, 0, 100);

    lv_obj_set_width(ui_Battery2, 80);
    lv_obj_set_height(ui_Battery2, 10);

    lv_obj_set_x(ui_Battery2, 0);
    lv_obj_set_y(ui_Battery2, 10);

    lv_obj_set_align(ui_Battery2, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_Battery2, lv_color_hex(0xD591D5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Battery2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Battery2, lv_color_hex(0x83247B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Battery2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_HomePatternLabel1

    ui_HomePatternLabel1 = lv_label_create(ui_Home);

    lv_obj_set_width(ui_HomePatternLabel1, lv_pct(95));
    lv_obj_set_height(ui_HomePatternLabel1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_HomePatternLabel1, 10);
    lv_obj_set_y(ui_HomePatternLabel1, 70);

    lv_obj_set_align(ui_HomePatternLabel1, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_HomePatternLabel1, T_Patterns);

    lv_obj_set_style_text_font(ui_HomePatternLabel1, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_HomePatternLabel

    ui_HomePatternLabel = lv_label_create(ui_HomePatternLabel1);

    lv_obj_set_width(ui_HomePatternLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_HomePatternLabel, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_HomePatternLabel, 120);
    lv_obj_set_y(ui_HomePatternLabel, 0);

    lv_obj_set_align(ui_HomePatternLabel, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_HomePatternLabel, T_BLANK);

    // ui_connect

    ui_connect = lv_label_create(ui_Home);

    lv_obj_set_width(ui_connect, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_connect, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_connect, -113);
    lv_obj_set_y(ui_connect, -102);

    lv_obj_set_align(ui_connect, LV_ALIGN_CENTER);

    lv_label_set_text(ui_connect, T_BLANK);

}
void ui_Menue_screen_init(void)
{

    // ui_Menue

    ui_Menue = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Menue, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_Menue, ui_event_Menue, LV_EVENT_ALL, NULL);

    // ui_Logo3

    ui_Logo3 = lv_label_create(ui_Menue);

    lv_obj_set_width(ui_Logo3, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Logo3, LV_SIZE_CONTENT);

    lv_obj_set_y(ui_Logo3, -103);
    lv_obj_set_x(ui_Logo3, lv_pct(0));

    lv_obj_set_align(ui_Logo3, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Logo3, T_HEADER);

    lv_obj_set_style_text_font(ui_Logo3, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Logo3, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Logo3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Logo3, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Logo3, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_MenueButtonL

    ui_MenueButtonL = lv_btn_create(ui_Menue);

    lv_obj_set_width(ui_MenueButtonL, 100);
    lv_obj_set_height(ui_MenueButtonL, 30);

    lv_obj_set_y(ui_MenueButtonL, 100);
    lv_obj_set_x(ui_MenueButtonL, lv_pct(-33));

    lv_obj_set_align(ui_MenueButtonL, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_MenueButtonL, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_MenueButtonL, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_MenueButtonL, ui_event_MenueButtonL, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_MenueButtonL, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_MenueButtonL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_MenueButtonLText

    ui_MenueButtonLText = lv_label_create(ui_MenueButtonL);

    lv_obj_set_width(ui_MenueButtonLText, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_MenueButtonLText, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_MenueButtonLText, lv_pct(0));
    lv_obj_set_y(ui_MenueButtonLText, lv_pct(0));

    lv_obj_set_align(ui_MenueButtonLText, LV_ALIGN_CENTER);

    lv_label_set_text(ui_MenueButtonLText, T_SETTINGS);

    lv_obj_set_style_text_color(ui_MenueButtonLText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_MenueButtonLText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_MenueButtonM

    ui_MenueButtonM = lv_btn_create(ui_Menue);

    lv_obj_set_width(ui_MenueButtonM, 100);
    lv_obj_set_height(ui_MenueButtonM, 30);

    lv_obj_set_y(ui_MenueButtonM, 100);
    lv_obj_set_x(ui_MenueButtonM, lv_pct(0));

    lv_obj_set_align(ui_MenueButtonM, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_MenueButtonM, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_MenueButtonM, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_MenueButtonM, ui_event_MenueButtonM, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_MenueButtonM, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_MenueButtonM, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_MenueButtonMText

    ui_MenueButtonMText = lv_label_create(ui_MenueButtonM);

    lv_obj_set_width(ui_MenueButtonMText, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_MenueButtonMText, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_MenueButtonMText, lv_pct(0));
    lv_obj_set_y(ui_MenueButtonMText, lv_pct(0));

    lv_obj_set_align(ui_MenueButtonMText, LV_ALIGN_CENTER);

    lv_label_set_text(ui_MenueButtonMText, T_HOME);

    lv_obj_set_style_text_color(ui_MenueButtonMText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_MenueButtonMText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_MenueButtonR

    ui_MenueButtonR = lv_btn_create(ui_Menue);

    lv_obj_set_width(ui_MenueButtonR, 100);
    lv_obj_set_height(ui_MenueButtonR, 30);

    lv_obj_set_y(ui_MenueButtonR, 100);
    lv_obj_set_x(ui_MenueButtonR, lv_pct(33));

    lv_obj_set_align(ui_MenueButtonR, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_MenueButtonR, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_MenueButtonR, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_state(ui_MenueButtonR, LV_STATE_DISABLED);

    lv_obj_add_event_cb(ui_MenueButtonR, ui_event_MenueButtonR, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_MenueButtonR, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_MenueButtonR, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_MenueButtonRText

    ui_MenueButtonRText = lv_label_create(ui_MenueButtonR);

    lv_obj_set_width(ui_MenueButtonRText, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_MenueButtonRText, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_MenueButtonRText, lv_pct(0));
    lv_obj_set_y(ui_MenueButtonRText, lv_pct(0));

    lv_obj_set_align(ui_MenueButtonRText, LV_ALIGN_CENTER);

    lv_label_set_text(ui_MenueButtonRText, T_BLANK);

    lv_obj_set_style_text_color(ui_MenueButtonRText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_MenueButtonRText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Batt3

    ui_Batt3 = lv_label_create(ui_Menue);

    lv_obj_set_width(ui_Batt3, 85);
    lv_obj_set_height(ui_Batt3, 30);

    lv_obj_set_x(ui_Batt3, 115);
    lv_obj_set_y(ui_Batt3, -103);

    lv_obj_set_align(ui_Batt3, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Batt3, T_BATT);

    // ui_BattValue3

    ui_BattValue3 = lv_label_create(ui_Batt3);

    lv_obj_set_width(ui_BattValue3, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_BattValue3, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_BattValue3, 0);
    lv_obj_set_y(ui_BattValue3, -7);

    lv_obj_set_align(ui_BattValue3, LV_ALIGN_RIGHT_MID);

    lv_label_set_text(ui_BattValue3, T_BLANK);
    lv_label_set_recolor(ui_BattValue3, "true");

    // ui_Battery3

    ui_Battery3 = lv_bar_create(ui_Batt3);
    lv_bar_set_range(ui_Battery3, 0, 100);

    lv_obj_set_width(ui_Battery3, 80);
    lv_obj_set_height(ui_Battery3, 10);

    lv_obj_set_x(ui_Battery3, 0);
    lv_obj_set_y(ui_Battery3, 10);

    lv_obj_set_align(ui_Battery3, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_Battery3, lv_color_hex(0xD591D5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Battery3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Battery3, lv_color_hex(0x83247B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Battery3, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_SDepthI

    ui_SDepthI = lv_btn_create(ui_Menue);

    lv_obj_set_height(ui_SDepthI, 30);
    lv_obj_set_width(ui_SDepthI, lv_pct(80));

    lv_obj_set_y(ui_SDepthI, -60);
    lv_obj_set_x(ui_SDepthI, lv_pct(1));

    lv_obj_set_align(ui_SDepthI, LV_ALIGN_CENTER);
    lv_obj_add_state(ui_SDepthI, LV_STATE_FOCUSED);

    lv_obj_add_flag(ui_SDepthI, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_SDepthI, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_SDepthI, ui_event_SDepthI, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_SDepthI, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SDepthI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SDepthI, lv_color_hex(0x5b0353), LV_PART_MAIN | LV_STATE_FOCUSED);

    // ui_SDepthIL

    ui_SDepthIL = lv_label_create(ui_SDepthI);

    lv_obj_set_width(ui_SDepthIL, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SDepthIL, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_SDepthIL, lv_pct(0));
    lv_obj_set_y(ui_SDepthIL, lv_pct(0));

    lv_obj_set_align(ui_SDepthIL, LV_ALIGN_CENTER);

    lv_label_set_text(ui_SDepthIL, T_SETUP_DEPTH_I);

    lv_obj_set_style_text_color(ui_SDepthIL, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SDepthIL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SDepthF

    ui_SDepthF = lv_btn_create(ui_Menue);

    lv_obj_set_height(ui_SDepthF, 30);
    lv_obj_set_width(ui_SDepthF, lv_pct(80));

    lv_obj_set_y(ui_SDepthF, -20);
    lv_obj_set_x(ui_SDepthF, lv_pct(1));

    lv_obj_set_align(ui_SDepthF, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_SDepthF, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_SDepthF, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_SDepthF, ui_event_SDepthF, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_SDepthF, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SDepthF, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SDepthF, lv_color_hex(0x5b0353), LV_PART_MAIN | LV_STATE_FOCUSED);

    // ui_SDepthFL

    ui_SDepthFL = lv_label_create(ui_SDepthF);

    lv_obj_set_width(ui_SDepthFL, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SDepthFL, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_SDepthFL, lv_pct(0));
    lv_obj_set_y(ui_SDepthFL, lv_pct(0));

    lv_obj_set_align(ui_SDepthFL, LV_ALIGN_CENTER);

    lv_label_set_text(ui_SDepthFL, T_SETUP_DEPTH_F);

    lv_obj_set_style_text_color(ui_SDepthFL, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SDepthFL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SPattern

    ui_SPattern = lv_btn_create(ui_Menue);

    lv_obj_set_height(ui_SPattern, 30);
    lv_obj_set_width(ui_SPattern, lv_pct(38));

    lv_obj_set_y(ui_SPattern, 20);
    lv_obj_set_x(ui_SPattern, lv_pct(-20));

    lv_obj_set_align(ui_SPattern, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_SPattern, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_SPattern, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_SPattern, ui_event_SPattern, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_SPattern, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SPattern, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SPattern, lv_color_hex(0x5b0353), LV_PART_MAIN | LV_STATE_FOCUSED);

    // ui_SPatternL

    ui_SPatternL = lv_label_create(ui_SPattern);

    lv_obj_set_width(ui_SPatternL, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SPatternL, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_SPatternL, lv_pct(0));
    lv_obj_set_y(ui_SPatternL, lv_pct(0));

    lv_obj_set_align(ui_SPatternL, LV_ALIGN_CENTER);

    lv_label_set_text(ui_SPatternL, T_SELECT_PATTERN);

    lv_obj_set_style_text_color(ui_SPatternL, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SPatternL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_STorqe

    ui_STorqe = lv_btn_create(ui_Menue);

    lv_obj_set_height(ui_STorqe, 30);
    lv_obj_set_width(ui_STorqe, lv_pct(38));

    lv_obj_set_y(ui_STorqe, 20);
    lv_obj_set_x(ui_STorqe, lv_pct(21));

    lv_obj_set_align(ui_STorqe, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_STorqe, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_STorqe, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_STorqe, ui_event_STorqe, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_STorqe, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_STorqe, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_STorqe, lv_color_hex(0x5b0353), LV_PART_MAIN | LV_STATE_FOCUSED);

    // ui_STorqeL

    ui_STorqeL = lv_label_create(ui_STorqe);

    lv_obj_set_width(ui_STorqeL, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_STorqeL, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_STorqeL, lv_pct(0));
    lv_obj_set_y(ui_STorqeL, lv_pct(0));

    lv_obj_set_align(ui_STorqeL, LV_ALIGN_CENTER);

    lv_label_set_text(ui_STorqeL, T_SETUP_TORQE);

    lv_obj_set_style_text_color(ui_STorqeL, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_STorqeL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_EJECTSettingButton

    ui_EJECTSettingButton = lv_btn_create(ui_Menue);

    lv_obj_set_height(ui_EJECTSettingButton, 30);
    lv_obj_set_width(ui_EJECTSettingButton, lv_pct(80));

    lv_obj_set_y(ui_EJECTSettingButton, 60);
    lv_obj_set_x(ui_EJECTSettingButton, lv_pct(1));

    lv_obj_set_align(ui_EJECTSettingButton, LV_ALIGN_CENTER);

    lv_obj_add_state(ui_EJECTSettingButton, LV_STATE_DISABLED);

    lv_obj_add_flag(ui_EJECTSettingButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_EJECTSettingButton, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_EJECTSettingButton, ui_event_EJECTSettingButton, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_EJECTSettingButton, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_EJECTSettingButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_EJECTSettingButton, lv_color_hex(0x5b0353), LV_PART_MAIN | LV_STATE_FOCUSED);

    // ui_EJECTSettingButtonText

    ui_EJECTSettingButtonText = lv_label_create(ui_EJECTSettingButton);

    lv_obj_set_width(ui_EJECTSettingButtonText, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_EJECTSettingButtonText, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_EJECTSettingButtonText, lv_pct(0));
    lv_obj_set_y(ui_EJECTSettingButtonText, lv_pct(0));

    lv_obj_set_align(ui_EJECTSettingButtonText, LV_ALIGN_CENTER);

    lv_label_set_text(ui_EJECTSettingButtonText, T_EJECT_SETTINGS);

    lv_obj_set_style_text_color(ui_EJECTSettingButtonText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_EJECTSettingButtonText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_g_menue = lv_group_create();
    lv_group_add_obj(ui_g_menue, ui_SDepthI);
    lv_group_add_obj(ui_g_menue, ui_SDepthF);
    lv_group_add_obj(ui_g_menue, ui_SPattern);
    lv_group_add_obj(ui_g_menue, ui_STorqe);
    lv_group_add_obj(ui_g_menue, ui_EJECTSettingButton);

}
void ui_Pattern_screen_init(void)
{

    // ui_Pattern

    ui_Pattern = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Pattern, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_Pattern, ui_event_Pattern, LV_EVENT_ALL, NULL);

    // ui_Logo5

    ui_Logo5 = lv_label_create(ui_Pattern);

    lv_obj_set_width(ui_Logo5, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Logo5, LV_SIZE_CONTENT);

    lv_obj_set_y(ui_Logo5, -103);
    lv_obj_set_x(ui_Logo5, lv_pct(0));

    lv_obj_set_align(ui_Logo5, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Logo5, T_HEADER);

    lv_obj_set_style_text_font(ui_Logo5, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Logo5, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Logo5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Logo5, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Logo5, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_PatternButtonL

    ui_PatternButtonL = lv_btn_create(ui_Pattern);

    lv_obj_set_width(ui_PatternButtonL, 100);
    lv_obj_set_height(ui_PatternButtonL, 30);

    lv_obj_set_y(ui_PatternButtonL, 100);
    lv_obj_set_x(ui_PatternButtonL, lv_pct(-33));

    lv_obj_set_align(ui_PatternButtonL, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_PatternButtonL, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_PatternButtonL, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_PatternButtonL, ui_event_PatternButtonL, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_PatternButtonL, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PatternButtonL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_PatternButtonLText

    ui_PatternButtonLText = lv_label_create(ui_PatternButtonL);

    lv_obj_set_width(ui_PatternButtonLText, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_PatternButtonLText, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_PatternButtonLText, lv_pct(0));
    lv_obj_set_y(ui_PatternButtonLText, lv_pct(0));

    lv_obj_set_align(ui_PatternButtonLText, LV_ALIGN_CENTER);

    lv_label_set_text(ui_PatternButtonLText, T_MENUE);

    lv_obj_set_style_text_color(ui_PatternButtonLText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_PatternButtonLText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_PatternButtonM

    ui_PatternButtonM = lv_btn_create(ui_Pattern);

    lv_obj_set_width(ui_PatternButtonM, 100);
    lv_obj_set_height(ui_PatternButtonM, 30);

    lv_obj_set_y(ui_PatternButtonM, 100);
    lv_obj_set_x(ui_PatternButtonM, lv_pct(0));

    lv_obj_set_align(ui_PatternButtonM, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_PatternButtonM, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_PatternButtonM, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_PatternButtonM, ui_event_PatternButtonM, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_PatternButtonM, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PatternButtonM, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_PatternButtonMText

    ui_PatternButtonMText = lv_label_create(ui_PatternButtonM);

    lv_obj_set_width(ui_PatternButtonMText, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_PatternButtonMText, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_PatternButtonMText, lv_pct(0));
    lv_obj_set_y(ui_PatternButtonMText, lv_pct(0));

    lv_obj_set_align(ui_PatternButtonMText, LV_ALIGN_CENTER);

    lv_label_set_text(ui_PatternButtonMText, T_HOME);

    lv_obj_set_style_text_color(ui_PatternButtonMText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_PatternButtonMText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_PatternButtonR

    ui_PatternButtonR = lv_btn_create(ui_Pattern);

    lv_obj_set_width(ui_PatternButtonR, 100);
    lv_obj_set_height(ui_PatternButtonR, 30);

    lv_obj_set_y(ui_PatternButtonR, 100);
    lv_obj_set_x(ui_PatternButtonR, lv_pct(33));

    lv_obj_set_align(ui_PatternButtonR, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_PatternButtonR, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_PatternButtonR, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_PatternButtonR, ui_event_PatternButtonR, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_PatternButtonR, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PatternButtonR, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_PatternButtonRText

    ui_PatternButtonRText = lv_label_create(ui_PatternButtonR);

    lv_obj_set_width(ui_PatternButtonRText, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_PatternButtonRText, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_PatternButtonRText, lv_pct(0));
    lv_obj_set_y(ui_PatternButtonRText, lv_pct(0));

    lv_obj_set_align(ui_PatternButtonRText, LV_ALIGN_CENTER);

    lv_label_set_text(ui_PatternButtonRText, T_SAVE);

    lv_obj_set_style_text_color(ui_PatternButtonRText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_PatternButtonRText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Batt5

    ui_Batt5 = lv_label_create(ui_Pattern);

    lv_obj_set_width(ui_Batt5, 85);
    lv_obj_set_height(ui_Batt5, 30);

    lv_obj_set_x(ui_Batt5, 115);
    lv_obj_set_y(ui_Batt5, -103);

    lv_obj_set_align(ui_Batt5, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Batt5, T_BATT);

    // ui_BattValue5

    ui_BattValue5 = lv_label_create(ui_Batt5);

    lv_obj_set_width(ui_BattValue5, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_BattValue5, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_BattValue5, 0);
    lv_obj_set_y(ui_BattValue5, -7);

    lv_obj_set_align(ui_BattValue5, LV_ALIGN_RIGHT_MID);

    lv_label_set_text(ui_BattValue5, T_BLANK);
    lv_label_set_recolor(ui_BattValue5, "true");

    // ui_Battery5

    ui_Battery5 = lv_bar_create(ui_Batt5);
    lv_bar_set_range(ui_Battery5, 0, 100);

    lv_obj_set_width(ui_Battery5, 80);
    lv_obj_set_height(ui_Battery5, 10);

    lv_obj_set_x(ui_Battery5, 0);
    lv_obj_set_y(ui_Battery5, 10);

    lv_obj_set_align(ui_Battery5, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_Battery5, lv_color_hex(0xD591D5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Battery5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Battery5, lv_color_hex(0x83247B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Battery5, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_Label4

    ui_Label4 = lv_label_create(ui_Pattern);

    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label4, 0);
    lv_obj_set_y(ui_Label4, -60);

    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label4, T_SELECT_PATTERN);

    lv_obj_set_style_text_font(ui_Label4, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

// ui_PatternS

    ui_PatternS = lv_roller_create(ui_Pattern);
    lv_roller_set_options(ui_PatternS,
                          "SimpleStroke\nTeasingPounding\nRoboStroke\nHalfnHalf\nDeeper\nStopNGo\nInsist",
                          LV_ROLLER_MODE_NORMAL);

    lv_obj_set_height(ui_PatternS, 119);
    lv_obj_set_width(ui_PatternS, lv_pct(95));

    lv_obj_set_x(ui_PatternS, 0);
    lv_obj_set_y(ui_PatternS, 15);

    lv_obj_set_align(ui_PatternS, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_PatternS, lv_color_hex(0xB481AC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PatternS, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_PatternS, lv_color_hex(0x83247B), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PatternS, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);

}
void ui_Torqe_screen_init(void)
{

    // ui_Torqe

    ui_Torqe = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Torqe, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_Torqe, ui_event_Torqe, LV_EVENT_ALL, NULL);

    // ui_Logo4

    ui_Logo4 = lv_label_create(ui_Torqe);

    lv_obj_set_width(ui_Logo4, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Logo4, LV_SIZE_CONTENT);

    lv_obj_set_y(ui_Logo4, -103);
    lv_obj_set_x(ui_Logo4, lv_pct(0));

    lv_obj_set_align(ui_Logo4, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Logo4, T_HEADER);

    lv_obj_set_style_text_font(ui_Logo4, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Logo4, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Logo4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Logo4, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Logo4, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_TorqeButtonL

    ui_TorqeButtonL = lv_btn_create(ui_Torqe);

    lv_obj_set_width(ui_TorqeButtonL, 100);
    lv_obj_set_height(ui_TorqeButtonL, 30);

    lv_obj_set_y(ui_TorqeButtonL, 100);
    lv_obj_set_x(ui_TorqeButtonL, lv_pct(-33));

    lv_obj_set_align(ui_TorqeButtonL, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_TorqeButtonL, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_TorqeButtonL, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_TorqeButtonL, ui_event_TorqeButtonL, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_TorqeButtonL, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TorqeButtonL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_TorqeButtonLText

    ui_TorqeButtonLText = lv_label_create(ui_TorqeButtonL);

    lv_obj_set_width(ui_TorqeButtonLText, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_TorqeButtonLText, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_TorqeButtonLText, lv_pct(0));
    lv_obj_set_y(ui_TorqeButtonLText, lv_pct(0));

    lv_obj_set_align(ui_TorqeButtonLText, LV_ALIGN_CENTER);

    lv_label_set_text(ui_TorqeButtonLText, T_BLANK);

    lv_obj_set_style_text_color(ui_TorqeButtonLText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TorqeButtonLText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_TorqeButtonM

    ui_TorqeButtonM = lv_btn_create(ui_Torqe);

    lv_obj_set_width(ui_TorqeButtonM, 100);
    lv_obj_set_height(ui_TorqeButtonM, 30);

    lv_obj_set_y(ui_TorqeButtonM, 100);
    lv_obj_set_x(ui_TorqeButtonM, lv_pct(0));

    lv_obj_set_align(ui_TorqeButtonM, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_TorqeButtonM, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_TorqeButtonM, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_TorqeButtonM, ui_event_TorqeButtonM, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_TorqeButtonM, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TorqeButtonM, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_TorqeButtonMText

    ui_TorqeButtonMText = lv_label_create(ui_TorqeButtonM);

    lv_obj_set_width(ui_TorqeButtonMText, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_TorqeButtonMText, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_TorqeButtonMText, lv_pct(0));
    lv_obj_set_y(ui_TorqeButtonMText, lv_pct(0));

    lv_obj_set_align(ui_TorqeButtonMText, LV_ALIGN_CENTER);

    lv_label_set_text(ui_TorqeButtonMText, T_HOME);

    lv_obj_set_style_text_color(ui_TorqeButtonMText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TorqeButtonMText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_TorqeButtonR

    ui_TorqeButtonR = lv_btn_create(ui_Torqe);

    lv_obj_set_width(ui_TorqeButtonR, 100);
    lv_obj_set_height(ui_TorqeButtonR, 30);

    lv_obj_set_y(ui_TorqeButtonR, 100);
    lv_obj_set_x(ui_TorqeButtonR, lv_pct(33));

    lv_obj_set_align(ui_TorqeButtonR, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_TorqeButtonR, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_TorqeButtonR, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_TorqeButtonR, ui_event_TorqeButtonR, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_TorqeButtonR, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TorqeButtonR, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_TorqeButtonRText

    ui_TorqeButtonRText = lv_label_create(ui_TorqeButtonR);

    lv_obj_set_width(ui_TorqeButtonRText, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_TorqeButtonRText, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_TorqeButtonRText, lv_pct(0));
    lv_obj_set_y(ui_TorqeButtonRText, lv_pct(0));

    lv_obj_set_align(ui_TorqeButtonRText, LV_ALIGN_CENTER);

    lv_label_set_text(ui_TorqeButtonRText, T_MENUE);

    lv_obj_set_style_text_color(ui_TorqeButtonRText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TorqeButtonRText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_outtroqelabel

    ui_outtroqelabel = lv_label_create(ui_Torqe);

    lv_obj_set_height(ui_outtroqelabel, 60);
    lv_obj_set_width(ui_outtroqelabel, lv_pct(93));

    lv_obj_set_x(ui_outtroqelabel, 10);
    lv_obj_set_y(ui_outtroqelabel, -45);

    lv_obj_set_align(ui_outtroqelabel, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_outtroqelabel, T_OUT_TORQE);

    lv_obj_set_style_text_font(ui_outtroqelabel, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_outtroqevalue

    ui_outtroqevalue = lv_label_create(ui_outtroqelabel);

    lv_obj_set_width(ui_outtroqevalue, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_outtroqevalue, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_outtroqevalue, 190);
    lv_obj_set_y(ui_outtroqevalue, -14);

    lv_obj_set_align(ui_outtroqevalue, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_outtroqevalue, T_BLANK);

    lv_obj_set_style_text_font(ui_outtroqevalue, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_outtroqeslider

    ui_outtroqeslider = lv_slider_create(ui_outtroqelabel);
    lv_slider_set_range(ui_outtroqeslider, 50, 200);
    lv_slider_set_value(ui_outtroqeslider, 180, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_outtroqeslider) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_outtroqeslider, 0,
                                                                                                   LV_ANIM_OFF);

    lv_obj_set_width(ui_outtroqeslider, 195);
    lv_obj_set_height(ui_outtroqeslider, 10);

    lv_obj_set_x(ui_outtroqeslider, 50);
    lv_obj_set_y(ui_outtroqeslider, 15);

    lv_obj_set_align(ui_outtroqeslider, LV_ALIGN_LEFT_MID);

    lv_obj_set_style_bg_color(ui_outtroqeslider, lv_color_hex(0xD691D0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_outtroqeslider, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_outtroqeslider, lv_color_hex(0x83277B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_outtroqeslider, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_outtroqeslider, lv_color_hex(0x83277B), LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_outtroqeslider, lv_color_hex(0x83277B), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_outtroqeslider, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    // ui_Low1

    ui_Low1 = lv_label_create(ui_outtroqelabel);

    lv_obj_set_width(ui_Low1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Low1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Low1, 0);
    lv_obj_set_y(ui_Low1, 14);

    lv_obj_set_align(ui_Low1, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_Low1, T_LOW);

    lv_obj_set_style_text_font(ui_Low1, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_High1

    ui_High1 = lv_label_create(ui_outtroqelabel);

    lv_obj_set_width(ui_High1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_High1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_High1, 0);
    lv_obj_set_y(ui_High1, 14);

    lv_obj_set_align(ui_High1, LV_ALIGN_RIGHT_MID);

    lv_label_set_text(ui_High1, T_HIGH);

    lv_obj_set_style_text_font(ui_High1, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_introqelabel

    ui_introqelabel = lv_label_create(ui_Torqe);

    lv_obj_set_height(ui_introqelabel, 60);
    lv_obj_set_width(ui_introqelabel, lv_pct(93));

    lv_obj_set_x(ui_introqelabel, 10);
    lv_obj_set_y(ui_introqelabel, 30);

    lv_obj_set_align(ui_introqelabel, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_introqelabel, T_IN_TORQE);

    lv_obj_set_style_text_font(ui_introqelabel, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_introqevalue

    ui_introqevalue = lv_label_create(ui_introqelabel);

    lv_obj_set_width(ui_introqevalue, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_introqevalue, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_introqevalue, 190);
    lv_obj_set_y(ui_introqevalue, -14);

    lv_obj_set_align(ui_introqevalue, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_introqevalue, T_BLANK);

    lv_obj_set_style_text_font(ui_introqevalue, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_introqeslider

    ui_introqeslider = lv_slider_create(ui_introqelabel);
    lv_slider_set_range(ui_introqeslider, 20, 200);
    lv_slider_set_value(ui_introqeslider, 100, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_introqeslider) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_introqeslider, 0,
                                                                                                  LV_ANIM_OFF);

    lv_obj_set_width(ui_introqeslider, 195);
    lv_obj_set_height(ui_introqeslider, 10);

    lv_obj_set_x(ui_introqeslider, 50);
    lv_obj_set_y(ui_introqeslider, 15);

    lv_obj_set_align(ui_introqeslider, LV_ALIGN_LEFT_MID);

    lv_obj_set_style_bg_color(ui_introqeslider, lv_color_hex(0xD691D0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_introqeslider, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_introqeslider, lv_color_hex(0x83277B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_introqeslider, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_introqeslider, lv_color_hex(0x83277B), LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_introqeslider, lv_color_hex(0x83277B), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_introqeslider, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    // ui_Low2

    ui_Low2 = lv_label_create(ui_introqelabel);

    lv_obj_set_width(ui_Low2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Low2, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Low2, 0);
    lv_obj_set_y(ui_Low2, 14);

    lv_obj_set_align(ui_Low2, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_Low2, T_LOW);

    lv_obj_set_style_text_font(ui_Low2, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_High

    ui_High = lv_label_create(ui_introqelabel);

    lv_obj_set_width(ui_High, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_High, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_High, 0);
    lv_obj_set_y(ui_High, 14);

    lv_obj_set_align(ui_High, LV_ALIGN_RIGHT_MID);

    lv_label_set_text(ui_High, T_HIGH);

    lv_obj_set_style_text_font(ui_High, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Batt4

    ui_Batt4 = lv_label_create(ui_Torqe);

    lv_obj_set_width(ui_Batt4, 85);
    lv_obj_set_height(ui_Batt4, 30);

    lv_obj_set_x(ui_Batt4, 115);
    lv_obj_set_y(ui_Batt4, -103);

    lv_obj_set_align(ui_Batt4, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Batt4, T_BATT);

    // ui_BattValue4

    ui_BattValue4 = lv_label_create(ui_Batt4);

    lv_obj_set_width(ui_BattValue4, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_BattValue4, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_BattValue4, 0);
    lv_obj_set_y(ui_BattValue4, -7);

    lv_obj_set_align(ui_BattValue4, LV_ALIGN_RIGHT_MID);

    lv_label_set_text(ui_BattValue4, T_BLANK);
    lv_label_set_recolor(ui_BattValue4, "true");

    // ui_Battery4

    ui_Battery4 = lv_bar_create(ui_Batt4);
    lv_bar_set_range(ui_Battery4, 0, 100);

    lv_obj_set_width(ui_Battery4, 80);
    lv_obj_set_height(ui_Battery4, 10);

    lv_obj_set_x(ui_Battery4, 0);
    lv_obj_set_y(ui_Battery4, 10);

    lv_obj_set_align(ui_Battery4, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_Battery4, lv_color_hex(0xD591D5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Battery4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Battery4, lv_color_hex(0x83247B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Battery4, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

}
void ui_EJECTSettings_screen_init(void)
{

    // ui_EJECTSettings

    ui_EJECTSettings = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_EJECTSettings, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_EJECTSettings, ui_event_EJECTSettings, LV_EVENT_ALL, NULL);

    // ui_Logo6

    ui_Logo6 = lv_label_create(ui_EJECTSettings);

    lv_obj_set_width(ui_Logo6, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Logo6, LV_SIZE_CONTENT);

    lv_obj_set_y(ui_Logo6, -103);
    lv_obj_set_x(ui_Logo6, lv_pct(0));

    lv_obj_set_align(ui_Logo6, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Logo6, T_HEADER);

    lv_obj_set_style_text_font(ui_Logo6, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Logo6, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Logo6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Logo6, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Logo6, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_EJECTButtonL

    ui_EJECTButtonL = lv_btn_create(ui_EJECTSettings);

    lv_obj_set_width(ui_EJECTButtonL, 100);
    lv_obj_set_height(ui_EJECTButtonL, 30);

    lv_obj_set_y(ui_EJECTButtonL, 100);
    lv_obj_set_x(ui_EJECTButtonL, lv_pct(-33));

    lv_obj_set_align(ui_EJECTButtonL, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_EJECTButtonL, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_EJECTButtonL, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_EJECTButtonL, ui_event_EJECTButtonL, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_EJECTButtonL, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_EJECTButtonL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_EJECTButtonLText

    ui_EJECTButtonLText = lv_label_create(ui_EJECTButtonL);

    lv_obj_set_width(ui_EJECTButtonLText, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_EJECTButtonLText, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_EJECTButtonLText, lv_pct(0));
    lv_obj_set_y(ui_EJECTButtonLText, lv_pct(0));

    lv_obj_set_align(ui_EJECTButtonLText, LV_ALIGN_CENTER);

    lv_label_set_text(ui_EJECTButtonLText, "");

    lv_obj_set_style_text_color(ui_EJECTButtonLText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_EJECTButtonLText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_EJECTButtonM

    ui_EJECTButtonM = lv_btn_create(ui_EJECTSettings);

    lv_obj_set_width(ui_EJECTButtonM, 100);
    lv_obj_set_height(ui_EJECTButtonM, 30);

    lv_obj_set_y(ui_EJECTButtonM, 100);
    lv_obj_set_x(ui_EJECTButtonM, lv_pct(0));

    lv_obj_set_align(ui_EJECTButtonM, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_EJECTButtonM, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_EJECTButtonM, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_EJECTButtonM, ui_event_EJECTButtonM, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_EJECTButtonM, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_EJECTButtonM, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_EJECTButtonMText

    ui_EJECTButtonMText = lv_label_create(ui_EJECTButtonM);

    lv_obj_set_width(ui_EJECTButtonMText, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_EJECTButtonMText, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_EJECTButtonMText, lv_pct(0));
    lv_obj_set_y(ui_EJECTButtonMText, lv_pct(0));

    lv_obj_set_align(ui_EJECTButtonMText, LV_ALIGN_CENTER);

    lv_label_set_text(ui_EJECTButtonMText, T_HOME);

    lv_obj_set_style_text_color(ui_EJECTButtonMText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_EJECTButtonMText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_EJECTButtonR

    ui_EJECTButtonR = lv_btn_create(ui_EJECTSettings);

    lv_obj_set_width(ui_EJECTButtonR, 100);
    lv_obj_set_height(ui_EJECTButtonR, 30);

    lv_obj_set_y(ui_EJECTButtonR, 100);
    lv_obj_set_x(ui_EJECTButtonR, lv_pct(33));

    lv_obj_set_align(ui_EJECTButtonR, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_EJECTButtonR, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_EJECTButtonR, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_EJECTButtonR, ui_event_EJECTButtonR, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_EJECTButtonR, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_EJECTButtonR, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_EJECTButtonRText

    ui_EJECTButtonRText = lv_label_create(ui_EJECTButtonR);

    lv_obj_set_width(ui_EJECTButtonRText, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_EJECTButtonRText, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_EJECTButtonRText, lv_pct(0));
    lv_obj_set_y(ui_EJECTButtonRText, lv_pct(0));

    lv_obj_set_align(ui_EJECTButtonRText, LV_ALIGN_CENTER);

    lv_label_set_text(ui_EJECTButtonRText, T_MENUE);

    lv_obj_set_style_text_color(ui_EJECTButtonRText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_EJECTButtonRText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Batt6

    ui_Batt6 = lv_label_create(ui_EJECTSettings);

    lv_obj_set_width(ui_Batt6, 85);
    lv_obj_set_height(ui_Batt6, 30);

    lv_obj_set_x(ui_Batt6, 115);
    lv_obj_set_y(ui_Batt6, -103);

    lv_obj_set_align(ui_Batt6, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Batt6, T_BATT);

    // ui_BattValue6

    ui_BattValue6 = lv_label_create(ui_Batt6);

    lv_obj_set_width(ui_BattValue6, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_BattValue6, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_BattValue6, 0);
    lv_obj_set_y(ui_BattValue6, -7);

    lv_obj_set_align(ui_BattValue6, LV_ALIGN_RIGHT_MID);

    lv_label_set_text(ui_BattValue6, T_BLANK);
    lv_label_set_recolor(ui_BattValue6, "true");

    // ui_Battery6

    ui_Battery6 = lv_bar_create(ui_Batt6);
    lv_bar_set_range(ui_Battery6, 0, 100);

    lv_obj_set_width(ui_Battery6, 80);
    lv_obj_set_height(ui_Battery6, 10);

    lv_obj_set_x(ui_Battery6, 0);
    lv_obj_set_y(ui_Battery6, 10);

    lv_obj_set_align(ui_Battery6, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_Battery6, lv_color_hex(0xD591D5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Battery6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Battery6, lv_color_hex(0x83247B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Battery6, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

}
void ui_Settings_screen_init(void)
{

    // ui_Settings

    ui_Settings = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Settings, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_Settings, ui_event_Settings, LV_EVENT_ALL, NULL);

    // ui_Logo1

    ui_Logo1 = lv_label_create(ui_Settings);

    lv_obj_set_width(ui_Logo1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Logo1, LV_SIZE_CONTENT);

    lv_obj_set_y(ui_Logo1, -103);
    lv_obj_set_x(ui_Logo1, lv_pct(0));

    lv_obj_set_align(ui_Logo1, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Logo1, T_HEADER);

    lv_obj_set_style_text_font(ui_Logo1, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Logo1, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Logo1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Logo1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Logo1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SettingsButtonL

    ui_SettingsButtonL = lv_btn_create(ui_Settings);

    lv_obj_set_width(ui_SettingsButtonL, 100);
    lv_obj_set_height(ui_SettingsButtonL, 30);

    lv_obj_set_x(ui_SettingsButtonL, -102);
    lv_obj_set_y(ui_SettingsButtonL, 100);

    lv_obj_set_align(ui_SettingsButtonL, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_SettingsButtonL, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_SettingsButtonL, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_SettingsButtonL, ui_event_SettingsButtonL, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_SettingsButtonL, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SettingsButtonL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SettingsButtonLText

    ui_SettingsButtonLText = lv_label_create(ui_SettingsButtonL);

    lv_obj_set_width(ui_SettingsButtonLText, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SettingsButtonLText, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_SettingsButtonLText, lv_pct(0));
    lv_obj_set_y(ui_SettingsButtonLText, lv_pct(0));

    lv_obj_set_align(ui_SettingsButtonLText, LV_ALIGN_CENTER);

    lv_label_set_text(ui_SettingsButtonLText, T_SAVE);

    lv_obj_set_style_text_color(ui_SettingsButtonLText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SettingsButtonLText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SettingsButtonM

    ui_SettingsButtonM = lv_btn_create(ui_Settings);

    lv_obj_set_width(ui_SettingsButtonM, 100);
    lv_obj_set_height(ui_SettingsButtonM, 30);

    lv_obj_set_y(ui_SettingsButtonM, 100);
    lv_obj_set_x(ui_SettingsButtonM, lv_pct(0));

    lv_obj_set_align(ui_SettingsButtonM, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_SettingsButtonM, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_SettingsButtonM, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_SettingsButtonM, ui_event_SettingsButtonM, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_SettingsButtonM, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SettingsButtonM, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SettingsButtonMText

    ui_SettingsButtonMText = lv_label_create(ui_SettingsButtonM);

    lv_obj_set_width(ui_SettingsButtonMText, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SettingsButtonMText, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_SettingsButtonMText, lv_pct(0));
    lv_obj_set_y(ui_SettingsButtonMText, lv_pct(0));

    lv_obj_set_align(ui_SettingsButtonMText, LV_ALIGN_CENTER);

    lv_label_set_text(ui_SettingsButtonMText, T_HOME);

    lv_obj_set_style_text_color(ui_SettingsButtonMText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SettingsButtonMText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SettingsButtonR

    ui_SettingsButtonR = lv_btn_create(ui_Settings);

    lv_obj_set_width(ui_SettingsButtonR, 100);
    lv_obj_set_height(ui_SettingsButtonR, 30);

    lv_obj_set_y(ui_SettingsButtonR, 100);
    lv_obj_set_x(ui_SettingsButtonR, lv_pct(33));

    lv_obj_set_align(ui_SettingsButtonR, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_SettingsButtonR, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_SettingsButtonR, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_SettingsButtonR, ui_event_SettingsButtonR, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_SettingsButtonR, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SettingsButtonR, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SettingsButtonRText

    ui_SettingsButtonRText = lv_label_create(ui_SettingsButtonR);

    lv_obj_set_width(ui_SettingsButtonRText, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SettingsButtonRText, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_SettingsButtonRText, lv_pct(0));
    lv_obj_set_y(ui_SettingsButtonRText, lv_pct(0));

    lv_obj_set_align(ui_SettingsButtonRText, LV_ALIGN_CENTER);

    lv_label_set_text(ui_SettingsButtonRText, T_MENUE);

    lv_obj_set_style_text_color(ui_SettingsButtonRText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SettingsButtonRText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Batt1

    ui_Batt1 = lv_label_create(ui_Settings);

    lv_obj_set_width(ui_Batt1, 85);
    lv_obj_set_height(ui_Batt1, 30);

    lv_obj_set_x(ui_Batt1, 115);
    lv_obj_set_y(ui_Batt1, -103);

    lv_obj_set_align(ui_Batt1, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Batt1, T_BATT);

    // ui_BattValue1

    ui_BattValue1 = lv_label_create(ui_Batt1);

    lv_obj_set_width(ui_BattValue1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_BattValue1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_BattValue1, 0);
    lv_obj_set_y(ui_BattValue1, -7);

    lv_obj_set_align(ui_BattValue1, LV_ALIGN_RIGHT_MID);

    lv_label_set_text(ui_BattValue1, T_BLANK);
    lv_label_set_recolor(ui_BattValue1, "true");

    // ui_Battery1

    ui_Battery1 = lv_bar_create(ui_Batt1);
    lv_bar_set_range(ui_Battery1, 0, 100);

    lv_obj_set_width(ui_Battery1, 80);
    lv_obj_set_height(ui_Battery1, 10);

    lv_obj_set_x(ui_Battery1, 0);
    lv_obj_set_y(ui_Battery1, 10);

    lv_obj_set_align(ui_Battery1, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_Battery1, lv_color_hex(0xD591D5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Battery1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Battery1, lv_color_hex(0x83247B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Battery1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_ejectaddon

    ui_ejectaddon = lv_checkbox_create(ui_Settings);
    lv_checkbox_set_text(ui_ejectaddon, T_EJECT);

    lv_obj_set_width(ui_ejectaddon, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ejectaddon, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ejectaddon, 10);
    lv_obj_set_y(ui_ejectaddon, -60);

    lv_obj_set_align(ui_ejectaddon, LV_ALIGN_LEFT_MID);

    lv_obj_add_flag(ui_ejectaddon, LV_OBJ_FLAG_SCROLL_ON_FOCUS);

    lv_obj_add_event_cb(ui_ejectaddon, ui_event_ejectaddon, LV_EVENT_ALL, NULL);

    lv_obj_set_style_text_font(ui_ejectaddon, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_border_color(ui_ejectaddon, lv_color_hex(0x83247B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ejectaddon, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_darkmode

    ui_darkmode = lv_checkbox_create(ui_Settings);
    lv_checkbox_set_text(ui_darkmode, T_DARKM);

    lv_obj_set_width(ui_darkmode, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_darkmode, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_darkmode, 10);
    lv_obj_set_y(ui_darkmode, 60);

    lv_obj_set_align(ui_darkmode, LV_ALIGN_LEFT_MID);

    lv_obj_add_flag(ui_darkmode, LV_OBJ_FLAG_SCROLL_ON_FOCUS);

    lv_obj_set_style_text_font(ui_darkmode, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_darkmode, lv_color_hex(0x5b0353), LV_PART_MAIN | LV_STATE_FOCUSED);

    //lv_obj_set_style_border_color(ui_darkmode, lv_color_hex(0x83247B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    //lv_obj_set_style_border_opa(ui_darkmode, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_vibrate

    ui_vibrate = lv_checkbox_create(ui_Settings);
    lv_checkbox_set_text(ui_vibrate, T_VIBRATE);

    lv_obj_set_width(ui_vibrate, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_vibrate, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_vibrate, 155);
    lv_obj_set_y(ui_vibrate, -60);

    lv_obj_set_align(ui_vibrate, LV_ALIGN_LEFT_MID);

    lv_obj_add_flag(ui_vibrate, LV_OBJ_FLAG_SCROLL_ON_FOCUS);

    lv_obj_set_style_text_font(ui_vibrate, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_border_color(ui_vibrate, lv_color_hex(0x83247B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_vibrate, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_lefty

    ui_lefty = lv_checkbox_create(ui_Settings);
    lv_checkbox_set_text(ui_lefty, T_TOUCHSETTING);

    lv_obj_set_width(ui_lefty, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_lefty, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_lefty, 11);
    lv_obj_set_y(ui_lefty, -18);

    lv_obj_set_align(ui_lefty, LV_ALIGN_LEFT_MID);

    lv_obj_add_flag(ui_lefty, LV_OBJ_FLAG_SCROLL_ON_FOCUS);

    lv_obj_set_style_text_font(ui_lefty, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_border_color(ui_lefty, lv_color_hex(0x83247B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_lefty, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_color_hex(0x83247B), lv_color_hex(0xD591D5), dark_mode, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Start_screen_init();
    ui_Home_screen_init();
    ui_Menue_screen_init();
    ui_Pattern_screen_init();
    ui_Torqe_screen_init();
    ui_EJECTSettings_screen_init();
    ui_Settings_screen_init();
    lv_disp_load_scr(ui_Start);
}