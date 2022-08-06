// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Start;
lv_obj_t * ui_Logo;
lv_obj_t * ui_ButtonL;
lv_obj_t * ui_LabelL;
lv_obj_t * ui_ButtonM;
lv_obj_t * ui_LabelM;
lv_obj_t * ui_ButtonR;
lv_obj_t * ui_LabelR;
lv_obj_t * ui_KMLogo;
lv_obj_t * ui_OrtlofLogo;
lv_obj_t * ui_Welcome;
lv_obj_t * ui_Batt;
lv_obj_t * ui_BattValue;
lv_obj_t * ui_Battery;
lv_obj_t * ui_Settings;
lv_obj_t * ui_Logo1;
lv_obj_t * ui_ButtonL1;
lv_obj_t * ui_LabelL1;
lv_obj_t * ui_ButtonM1;
lv_obj_t * ui_LabelM1;
lv_obj_t * ui_ButtonR1;
lv_obj_t * ui_LabelR1;
lv_obj_t * ui_Batt1;
lv_obj_t * ui_BattValue1;
lv_obj_t * ui_Battery1;
lv_obj_t * ui_ejectaddon;
lv_obj_t * ui_darkmode;
lv_obj_t * ui_multimode;
lv_obj_t * ui_Home;
lv_obj_t * ui_Logo2;
lv_obj_t * ui_ButtonL2;
lv_obj_t * ui_LabelL2;
lv_obj_t * ui_ButtonM2;
lv_obj_t * ui_LabelM2;
lv_obj_t * ui_ButtonR2;
lv_obj_t * ui_LabelR2;
lv_obj_t * ui_SpeedL;
lv_obj_t * ui_Speed;
lv_obj_t * ui_SpeedV;
lv_obj_t * ui_DepthL;
lv_obj_t * ui_Depth;
lv_obj_t * ui_DepthV;
lv_obj_t * ui_StrokeL;
lv_obj_t * ui_Stroke;
lv_obj_t * ui_StrokeV;
lv_obj_t * ui_SensationL;
lv_obj_t * ui_Sensation;
lv_obj_t * ui_Batt2;
lv_obj_t * ui_BattValue2;
lv_obj_t * ui_Battery2;
lv_obj_t * ui_Menue;
lv_obj_t * ui_Logo3;
lv_obj_t * ui_ButtonL3;
lv_obj_t * ui_LabelL3;
lv_obj_t * ui_ButtonM3;
lv_obj_t * ui_LabelM3;
lv_obj_t * ui_ButtonR3;
lv_obj_t * ui_LabelR3;
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
lv_obj_t * ui_Torqe;
lv_obj_t * ui_Logo4;
lv_obj_t * ui_ButtonL4;
lv_obj_t * ui_LabelL4;
lv_obj_t * ui_ButtonM4;
lv_obj_t * ui_LabelM4;
lv_obj_t * ui_ButtonR4;
lv_obj_t * ui_LabelR4;
lv_obj_t * ui_SpeedL1;
lv_obj_t * ui_Otorqe;
lv_obj_t * ui_DepthL1;
lv_obj_t * ui_Itorqe;
lv_obj_t * ui_Batt4;
lv_obj_t * ui_BattValue4;
lv_obj_t * ui_Battery4;
lv_obj_t * ui_Pattern;
lv_obj_t * ui_Logo5;
lv_obj_t * ui_ButtonL5;
lv_obj_t * ui_LabelL5;
lv_obj_t * ui_ButtonM5;
lv_obj_t * ui_LabelM5;
lv_obj_t * ui_ButtonR5;
lv_obj_t * ui_LabelR5;
lv_obj_t * ui_Batt5;
lv_obj_t * ui_BattValue5;
lv_obj_t * ui_Battery5;
lv_obj_t * ui_PatternS;
lv_obj_t * ui_Label4;
lv_obj_t * ui_PatternOK;
lv_obj_t * ui_LabelL6;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "#error LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
static void ui_event_ButtonM(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 90, 0);
    }
}
static void ui_event_ButtonR(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 90, 0);
    }
}
static void ui_event_ButtonM1(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 90, 0);
    }
}
static void ui_event_ejectaddon(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
}
static void ui_event_darkmode(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
}
static void ui_event_multimode(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
}
static void ui_event_ButtonL2(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 90, 0);
    }
}
static void ui_event_ButtonR2(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Menue, LV_SCR_LOAD_ANIM_FADE_ON, 90, 0);
    }
}
static void ui_event_ButtonM3(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 90, 0);
    }
}
static void ui_event_SDepthI(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
}
static void ui_event_SDepthF(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
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
static void ui_event_ButtonM4(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 90, 0);
    }
}
static void ui_event_ButtonR4(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Menue, LV_SCR_LOAD_ANIM_FADE_ON, 90, 0);
    }
}
static void ui_event_ButtonM5(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 90, 0);
    }
}
static void ui_event_ButtonR5(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Menue, LV_SCR_LOAD_ANIM_FADE_ON, 90, 0);
    }
}
static void ui_event_PatternOK(lv_event_t * e)
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

    // ui_Logo

    ui_Logo = lv_label_create(ui_Start);

    lv_obj_set_width(ui_Logo, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Logo, LV_SIZE_CONTENT);

    lv_obj_set_y(ui_Logo, -103);
    lv_obj_set_x(ui_Logo, lv_pct(0));

    lv_obj_set_align(ui_Logo, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Logo, "OSSM REMOTE");

    lv_obj_set_style_text_font(ui_Logo, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Logo, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Logo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Logo, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Logo, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonL

    ui_ButtonL = lv_btn_create(ui_Start);

    lv_obj_set_width(ui_ButtonL, 100);
    lv_obj_set_height(ui_ButtonL, 30);

    lv_obj_set_y(ui_ButtonL, 100);
    lv_obj_set_x(ui_ButtonL, lv_pct(-33));

    lv_obj_set_align(ui_ButtonL, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonL, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonL, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_ButtonL, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelL

    ui_LabelL = lv_label_create(ui_ButtonL);

    lv_obj_set_width(ui_LabelL, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelL, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelL, lv_pct(0));
    lv_obj_set_y(ui_LabelL, lv_pct(0));

    lv_obj_set_align(ui_LabelL, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelL, "Connect");

    lv_obj_set_style_text_color(ui_LabelL, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonM

    ui_ButtonM = lv_btn_create(ui_Start);

    lv_obj_set_width(ui_ButtonM, 100);
    lv_obj_set_height(ui_ButtonM, 30);

    lv_obj_set_y(ui_ButtonM, 100);
    lv_obj_set_x(ui_ButtonM, lv_pct(0));

    lv_obj_set_align(ui_ButtonM, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonM, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonM, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonM, ui_event_ButtonM, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonM, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonM, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelM

    ui_LabelM = lv_label_create(ui_ButtonM);

    lv_obj_set_width(ui_LabelM, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelM, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelM, lv_pct(0));
    lv_obj_set_y(ui_LabelM, lv_pct(0));

    lv_obj_set_align(ui_LabelM, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelM, "Settings");

    lv_obj_set_style_text_color(ui_LabelM, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelM, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonR

    ui_ButtonR = lv_btn_create(ui_Start);

    lv_obj_set_width(ui_ButtonR, 100);
    lv_obj_set_height(ui_ButtonR, 30);

    lv_obj_set_y(ui_ButtonR, 100);
    lv_obj_set_x(ui_ButtonR, lv_pct(33));

    lv_obj_set_align(ui_ButtonR, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonR, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonR, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonR, ui_event_ButtonR, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonR, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonR, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelR

    ui_LabelR = lv_label_create(ui_ButtonR);

    lv_obj_set_width(ui_LabelR, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelR, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelR, lv_pct(0));
    lv_obj_set_y(ui_LabelR, lv_pct(0));

    lv_obj_set_align(ui_LabelR, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelR, "Start");

    lv_obj_set_style_text_color(ui_LabelR, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelR, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

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

    lv_label_set_text(ui_Welcome, "Welcome to OSSM M5 Remote");

    // ui_Batt

    ui_Batt = lv_label_create(ui_Start);

    lv_obj_set_width(ui_Batt, 85);
    lv_obj_set_height(ui_Batt, 30);

    lv_obj_set_x(ui_Batt, 115);
    lv_obj_set_y(ui_Batt, -103);

    lv_obj_set_align(ui_Batt, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Batt, "Batt");

    // ui_BattValue

    ui_BattValue = lv_label_create(ui_Batt);

    lv_obj_set_width(ui_BattValue, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_BattValue, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_BattValue, 0);
    lv_obj_set_y(ui_BattValue, -7);

    lv_obj_set_align(ui_BattValue, LV_ALIGN_RIGHT_MID);

    lv_label_set_text(ui_BattValue, "");

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
void ui_Settings_screen_init(void)
{

    // ui_Settings

    ui_Settings = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Settings, LV_OBJ_FLAG_SCROLLABLE);

    // ui_Logo1

    ui_Logo1 = lv_label_create(ui_Settings);

    lv_obj_set_width(ui_Logo1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Logo1, LV_SIZE_CONTENT);

    lv_obj_set_y(ui_Logo1, -103);
    lv_obj_set_x(ui_Logo1, lv_pct(0));

    lv_obj_set_align(ui_Logo1, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Logo1, "OSSM REMOTE");

    lv_obj_set_style_text_font(ui_Logo1, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Logo1, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Logo1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Logo1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Logo1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonL1

    ui_ButtonL1 = lv_btn_create(ui_Settings);

    lv_obj_set_width(ui_ButtonL1, 100);
    lv_obj_set_height(ui_ButtonL1, 30);

    lv_obj_set_y(ui_ButtonL1, 100);
    lv_obj_set_x(ui_ButtonL1, lv_pct(-33));

    lv_obj_set_align(ui_ButtonL1, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonL1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonL1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_ButtonL1, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonL1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelL1

    ui_LabelL1 = lv_label_create(ui_ButtonL1);

    lv_obj_set_width(ui_LabelL1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelL1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelL1, lv_pct(0));
    lv_obj_set_y(ui_LabelL1, lv_pct(0));

    lv_obj_set_align(ui_LabelL1, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelL1, "");

    lv_obj_set_style_text_color(ui_LabelL1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelL1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonM1

    ui_ButtonM1 = lv_btn_create(ui_Settings);

    lv_obj_set_width(ui_ButtonM1, 100);
    lv_obj_set_height(ui_ButtonM1, 30);

    lv_obj_set_y(ui_ButtonM1, 100);
    lv_obj_set_x(ui_ButtonM1, lv_pct(0));

    lv_obj_set_align(ui_ButtonM1, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonM1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonM1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonM1, ui_event_ButtonM1, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonM1, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonM1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelM1

    ui_LabelM1 = lv_label_create(ui_ButtonM1);

    lv_obj_set_width(ui_LabelM1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelM1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelM1, lv_pct(0));
    lv_obj_set_y(ui_LabelM1, lv_pct(0));

    lv_obj_set_align(ui_LabelM1, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelM1, "Home");

    lv_obj_set_style_text_color(ui_LabelM1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelM1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonR1

    ui_ButtonR1 = lv_btn_create(ui_Settings);

    lv_obj_set_width(ui_ButtonR1, 100);
    lv_obj_set_height(ui_ButtonR1, 30);

    lv_obj_set_y(ui_ButtonR1, 100);
    lv_obj_set_x(ui_ButtonR1, lv_pct(33));

    lv_obj_set_align(ui_ButtonR1, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonR1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonR1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_ButtonR1, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonR1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelR1

    ui_LabelR1 = lv_label_create(ui_ButtonR1);

    lv_obj_set_width(ui_LabelR1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelR1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelR1, lv_pct(0));
    lv_obj_set_y(ui_LabelR1, lv_pct(0));

    lv_obj_set_align(ui_LabelR1, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelR1, "");

    lv_obj_set_style_text_color(ui_LabelR1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelR1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Batt1

    ui_Batt1 = lv_label_create(ui_Settings);

    lv_obj_set_width(ui_Batt1, 85);
    lv_obj_set_height(ui_Batt1, 30);

    lv_obj_set_x(ui_Batt1, 115);
    lv_obj_set_y(ui_Batt1, -103);

    lv_obj_set_align(ui_Batt1, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Batt1, "Batt");

    // ui_BattValue1

    ui_BattValue1 = lv_label_create(ui_Batt1);

    lv_obj_set_width(ui_BattValue1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_BattValue1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_BattValue1, 0);
    lv_obj_set_y(ui_BattValue1, -7);

    lv_obj_set_align(ui_BattValue1, LV_ALIGN_RIGHT_MID);

    lv_label_set_text(ui_BattValue1, "");
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
    lv_checkbox_set_text(ui_ejectaddon, "EJECT Addon Enabled");

    lv_obj_set_width(ui_ejectaddon, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ejectaddon, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ejectaddon, 10);
    lv_obj_set_y(ui_ejectaddon, -65);

    lv_obj_set_align(ui_ejectaddon, LV_ALIGN_LEFT_MID);

    lv_obj_add_flag(ui_ejectaddon, LV_OBJ_FLAG_SCROLL_ON_FOCUS);

    lv_obj_add_event_cb(ui_ejectaddon, ui_event_ejectaddon, LV_EVENT_ALL, NULL);

    lv_obj_set_style_text_font(ui_ejectaddon, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_border_color(ui_ejectaddon, lv_color_hex(0x83247B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ejectaddon, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_darkmode

    ui_darkmode = lv_checkbox_create(ui_Settings);
    lv_checkbox_set_text(ui_darkmode, "Enable Dark Mode");

    lv_obj_set_width(ui_darkmode, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_darkmode, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_darkmode, 10);
    lv_obj_set_y(ui_darkmode, -30);

    lv_obj_set_align(ui_darkmode, LV_ALIGN_LEFT_MID);

    lv_obj_add_flag(ui_darkmode, LV_OBJ_FLAG_SCROLL_ON_FOCUS);

    lv_obj_add_event_cb(ui_darkmode, ui_event_darkmode, LV_EVENT_ALL, NULL);

    lv_obj_set_style_text_font(ui_darkmode, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_border_color(ui_darkmode, lv_color_hex(0x83247B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_darkmode, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_multimode

    ui_multimode = lv_checkbox_create(ui_Settings);
    lv_checkbox_set_text(ui_multimode, "Enable Mulitmode");

    lv_obj_set_width(ui_multimode, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_multimode, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_multimode, 10);
    lv_obj_set_y(ui_multimode, 5);

    lv_obj_set_align(ui_multimode, LV_ALIGN_LEFT_MID);

    lv_obj_add_flag(ui_multimode, LV_OBJ_FLAG_SCROLL_ON_FOCUS);

    lv_obj_add_event_cb(ui_multimode, ui_event_multimode, LV_EVENT_ALL, NULL);

    lv_obj_set_style_text_font(ui_multimode, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_border_color(ui_multimode, lv_color_hex(0x83247B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_multimode, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

}
void ui_Home_screen_init(void)
{

    // ui_Home

    ui_Home = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Home, LV_OBJ_FLAG_SCROLLABLE);

    // ui_Logo2

    ui_Logo2 = lv_label_create(ui_Home);

    lv_obj_set_width(ui_Logo2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Logo2, LV_SIZE_CONTENT);

    lv_obj_set_y(ui_Logo2, -103);
    lv_obj_set_x(ui_Logo2, lv_pct(0));

    lv_obj_set_align(ui_Logo2, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Logo2, "OSSM REMOTE");

    lv_obj_set_style_text_font(ui_Logo2, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Logo2, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Logo2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Logo2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Logo2, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonL2

    ui_ButtonL2 = lv_btn_create(ui_Home);

    lv_obj_set_width(ui_ButtonL2, 100);
    lv_obj_set_height(ui_ButtonL2, 30);

    lv_obj_set_y(ui_ButtonL2, 100);
    lv_obj_set_x(ui_ButtonL2, lv_pct(-33));

    lv_obj_set_align(ui_ButtonL2, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonL2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonL2, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonL2, ui_event_ButtonL2, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonL2, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonL2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelL2

    ui_LabelL2 = lv_label_create(ui_ButtonL2);

    lv_obj_set_width(ui_LabelL2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelL2, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelL2, lv_pct(0));
    lv_obj_set_y(ui_LabelL2, lv_pct(0));

    lv_obj_set_align(ui_LabelL2, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelL2, "Settings");

    lv_obj_set_style_text_color(ui_LabelL2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelL2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonM2

    ui_ButtonM2 = lv_btn_create(ui_Home);

    lv_obj_set_width(ui_ButtonM2, 100);
    lv_obj_set_height(ui_ButtonM2, 30);

    lv_obj_set_y(ui_ButtonM2, 100);
    lv_obj_set_x(ui_ButtonM2, lv_pct(0));

    lv_obj_set_align(ui_ButtonM2, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonM2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonM2, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_ButtonM2, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonM2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelM2

    ui_LabelM2 = lv_label_create(ui_ButtonM2);

    lv_obj_set_width(ui_LabelM2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelM2, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelM2, lv_pct(0));
    lv_obj_set_y(ui_LabelM2, lv_pct(0));

    lv_obj_set_align(ui_LabelM2, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelM2, "Start/Stop");

    lv_obj_set_style_text_color(ui_LabelM2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelM2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonR2

    ui_ButtonR2 = lv_btn_create(ui_Home);

    lv_obj_set_width(ui_ButtonR2, 100);
    lv_obj_set_height(ui_ButtonR2, 30);

    lv_obj_set_y(ui_ButtonR2, 100);
    lv_obj_set_x(ui_ButtonR2, lv_pct(33));

    lv_obj_set_align(ui_ButtonR2, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonR2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonR2, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonR2, ui_event_ButtonR2, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonR2, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonR2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelR2

    ui_LabelR2 = lv_label_create(ui_ButtonR2);

    lv_obj_set_width(ui_LabelR2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelR2, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelR2, lv_pct(0));
    lv_obj_set_y(ui_LabelR2, lv_pct(0));

    lv_obj_set_align(ui_LabelR2, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelR2, "Menue");

    lv_obj_set_style_text_color(ui_LabelR2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelR2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SpeedL

    ui_SpeedL = lv_label_create(ui_Home);

    lv_obj_set_width(ui_SpeedL, lv_pct(95));
    lv_obj_set_height(ui_SpeedL, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_SpeedL, 0);
    lv_obj_set_y(ui_SpeedL, -60);

    lv_obj_set_align(ui_SpeedL, LV_ALIGN_CENTER);

    lv_label_set_text(ui_SpeedL, "Speed:");

    lv_obj_set_style_text_color(ui_SpeedL, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SpeedL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SpeedL, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Speed

    ui_Speed = lv_slider_create(ui_SpeedL);
    lv_slider_set_range(ui_Speed, 0, 100);

    lv_obj_set_width(ui_Speed, 130);
    lv_obj_set_height(ui_Speed, 10);

    lv_obj_set_x(ui_Speed, -15);
    lv_obj_set_y(ui_Speed, 0);

    lv_obj_set_align(ui_Speed, LV_ALIGN_RIGHT_MID);

    lv_obj_set_style_bg_color(ui_Speed, lv_color_hex(0xD691D0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Speed, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Speed, lv_color_hex(0x83277B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Speed, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Speed, lv_color_hex(0x83277B), LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Speed, lv_color_hex(0x83277B), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Speed, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    // ui_SpeedV

    ui_SpeedV = lv_label_create(ui_SpeedL);

    lv_obj_set_width(ui_SpeedV, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SpeedV, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_SpeedV, 80);
    lv_obj_set_y(ui_SpeedV, 0);

    lv_obj_set_align(ui_SpeedV, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_SpeedV, "");

    // ui_DepthL

    ui_DepthL = lv_label_create(ui_Home);

    lv_obj_set_width(ui_DepthL, lv_pct(95));
    lv_obj_set_height(ui_DepthL, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_DepthL, 0);
    lv_obj_set_y(ui_DepthL, -25);

    lv_obj_set_align(ui_DepthL, LV_ALIGN_CENTER);

    lv_label_set_text(ui_DepthL, "Depth:");

    lv_obj_set_style_text_color(ui_DepthL, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DepthL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DepthL, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Depth

    ui_Depth = lv_slider_create(ui_DepthL);
    lv_slider_set_range(ui_Depth, 0, 100);

    lv_obj_set_width(ui_Depth, 130);
    lv_obj_set_height(ui_Depth, 10);

    lv_obj_set_x(ui_Depth, -15);
    lv_obj_set_y(ui_Depth, 0);

    lv_obj_set_align(ui_Depth, LV_ALIGN_RIGHT_MID);

    lv_obj_set_style_bg_color(ui_Depth, lv_color_hex(0xD691D0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Depth, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Depth, lv_color_hex(0x83277B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Depth, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Depth, lv_color_hex(0x83277B), LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Depth, lv_color_hex(0x83277B), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Depth, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    // ui_DepthV

    ui_DepthV = lv_label_create(ui_DepthL);

    lv_obj_set_width(ui_DepthV, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_DepthV, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_DepthV, 80);
    lv_obj_set_y(ui_DepthV, 0);

    lv_obj_set_align(ui_DepthV, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_DepthV, "");

    // ui_StrokeL

    ui_StrokeL = lv_label_create(ui_Home);

    lv_obj_set_width(ui_StrokeL, lv_pct(95));
    lv_obj_set_height(ui_StrokeL, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_StrokeL, 0);
    lv_obj_set_y(ui_StrokeL, 10);

    lv_obj_set_align(ui_StrokeL, LV_ALIGN_CENTER);

    lv_label_set_text(ui_StrokeL, "Stroke:");

    lv_obj_set_style_text_color(ui_StrokeL, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_StrokeL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_StrokeL, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Stroke

    ui_Stroke = lv_slider_create(ui_StrokeL);
    lv_slider_set_range(ui_Stroke, 0, 100);

    lv_obj_set_width(ui_Stroke, 130);
    lv_obj_set_height(ui_Stroke, 10);

    lv_obj_set_x(ui_Stroke, -15);
    lv_obj_set_y(ui_Stroke, 0);

    lv_obj_set_align(ui_Stroke, LV_ALIGN_RIGHT_MID);

    lv_obj_set_style_bg_color(ui_Stroke, lv_color_hex(0xD691D0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Stroke, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Stroke, lv_color_hex(0x83277B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Stroke, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Stroke, lv_color_hex(0x83277B), LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Stroke, lv_color_hex(0x83277B), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Stroke, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    // ui_StrokeV

    ui_StrokeV = lv_label_create(ui_StrokeL);

    lv_obj_set_width(ui_StrokeV, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_StrokeV, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_StrokeV, 80);
    lv_obj_set_y(ui_StrokeV, 0);

    lv_obj_set_align(ui_StrokeV, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_StrokeV, "");

    // ui_SensationL

    ui_SensationL = lv_label_create(ui_Home);

    lv_obj_set_width(ui_SensationL, lv_pct(95));
    lv_obj_set_height(ui_SensationL, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_SensationL, 0);
    lv_obj_set_y(ui_SensationL, 45);

    lv_obj_set_align(ui_SensationL, LV_ALIGN_CENTER);

    lv_label_set_text(ui_SensationL, "Sensation:");

    lv_obj_set_style_text_color(ui_SensationL, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SensationL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SensationL, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Sensation

    ui_Sensation = lv_slider_create(ui_SensationL);
    lv_slider_set_range(ui_Sensation, 0, 100);
    lv_slider_set_value(ui_Sensation, 50, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_Sensation) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_Sensation, 0, LV_ANIM_OFF);

    lv_obj_set_width(ui_Sensation, 175);
    lv_obj_set_height(ui_Sensation, 10);

    lv_obj_set_x(ui_Sensation, -15);
    lv_obj_set_y(ui_Sensation, 0);

    lv_obj_set_align(ui_Sensation, LV_ALIGN_RIGHT_MID);

    lv_obj_set_style_bg_color(ui_Sensation, lv_color_hex(0xD691D0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Sensation, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Sensation, lv_color_hex(0x83277B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Sensation, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Sensation, lv_color_hex(0x83277B), LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Sensation, lv_color_hex(0x83277B), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Sensation, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    // ui_Batt2

    ui_Batt2 = lv_label_create(ui_Home);

    lv_obj_set_width(ui_Batt2, 85);
    lv_obj_set_height(ui_Batt2, 30);

    lv_obj_set_x(ui_Batt2, 115);
    lv_obj_set_y(ui_Batt2, -103);

    lv_obj_set_align(ui_Batt2, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Batt2, "Batt");

    // ui_BattValue2

    ui_BattValue2 = lv_label_create(ui_Batt2);

    lv_obj_set_width(ui_BattValue2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_BattValue2, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_BattValue2, 0);
    lv_obj_set_y(ui_BattValue2, -7);

    lv_obj_set_align(ui_BattValue2, LV_ALIGN_RIGHT_MID);

    lv_label_set_text(ui_BattValue2, "");
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

}
void ui_Menue_screen_init(void)
{

    // ui_Menue

    ui_Menue = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Menue, LV_OBJ_FLAG_SCROLLABLE);

    // ui_Logo3

    ui_Logo3 = lv_label_create(ui_Menue);

    lv_obj_set_width(ui_Logo3, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Logo3, LV_SIZE_CONTENT);

    lv_obj_set_y(ui_Logo3, -103);
    lv_obj_set_x(ui_Logo3, lv_pct(0));

    lv_obj_set_align(ui_Logo3, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Logo3, "OSSM REMOTE");

    lv_obj_set_style_text_font(ui_Logo3, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Logo3, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Logo3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Logo3, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Logo3, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonL3

    ui_ButtonL3 = lv_btn_create(ui_Menue);

    lv_obj_set_width(ui_ButtonL3, 100);
    lv_obj_set_height(ui_ButtonL3, 30);

    lv_obj_set_y(ui_ButtonL3, 100);
    lv_obj_set_x(ui_ButtonL3, lv_pct(-33));

    lv_obj_set_align(ui_ButtonL3, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonL3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonL3, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_ButtonL3, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonL3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelL3

    ui_LabelL3 = lv_label_create(ui_ButtonL3);

    lv_obj_set_width(ui_LabelL3, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelL3, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelL3, lv_pct(0));
    lv_obj_set_y(ui_LabelL3, lv_pct(0));

    lv_obj_set_align(ui_LabelL3, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelL3, "");

    lv_obj_set_style_text_color(ui_LabelL3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelL3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonM3

    ui_ButtonM3 = lv_btn_create(ui_Menue);

    lv_obj_set_width(ui_ButtonM3, 100);
    lv_obj_set_height(ui_ButtonM3, 30);

    lv_obj_set_y(ui_ButtonM3, 100);
    lv_obj_set_x(ui_ButtonM3, lv_pct(0));

    lv_obj_set_align(ui_ButtonM3, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonM3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonM3, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonM3, ui_event_ButtonM3, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonM3, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonM3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelM3

    ui_LabelM3 = lv_label_create(ui_ButtonM3);

    lv_obj_set_width(ui_LabelM3, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelM3, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelM3, lv_pct(0));
    lv_obj_set_y(ui_LabelM3, lv_pct(0));

    lv_obj_set_align(ui_LabelM3, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelM3, "Home");

    lv_obj_set_style_text_color(ui_LabelM3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelM3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonR3

    ui_ButtonR3 = lv_btn_create(ui_Menue);

    lv_obj_set_width(ui_ButtonR3, 100);
    lv_obj_set_height(ui_ButtonR3, 30);

    lv_obj_set_y(ui_ButtonR3, 100);
    lv_obj_set_x(ui_ButtonR3, lv_pct(33));

    lv_obj_set_align(ui_ButtonR3, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonR3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonR3, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_ButtonR3, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonR3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelR3

    ui_LabelR3 = lv_label_create(ui_ButtonR3);

    lv_obj_set_width(ui_LabelR3, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelR3, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelR3, lv_pct(0));
    lv_obj_set_y(ui_LabelR3, lv_pct(0));

    lv_obj_set_align(ui_LabelR3, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelR3, "");

    lv_obj_set_style_text_color(ui_LabelR3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelR3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Batt3

    ui_Batt3 = lv_label_create(ui_Menue);

    lv_obj_set_width(ui_Batt3, 85);
    lv_obj_set_height(ui_Batt3, 30);

    lv_obj_set_x(ui_Batt3, 115);
    lv_obj_set_y(ui_Batt3, -103);

    lv_obj_set_align(ui_Batt3, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Batt3, "Batt");

    // ui_BattValue3

    ui_BattValue3 = lv_label_create(ui_Batt3);

    lv_obj_set_width(ui_BattValue3, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_BattValue3, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_BattValue3, 0);
    lv_obj_set_y(ui_BattValue3, -7);

    lv_obj_set_align(ui_BattValue3, LV_ALIGN_RIGHT_MID);

    lv_label_set_text(ui_BattValue3, "");
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

    lv_obj_add_flag(ui_SDepthI, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_SDepthI, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_SDepthI, ui_event_SDepthI, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_SDepthI, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SDepthI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SDepthIL

    ui_SDepthIL = lv_label_create(ui_SDepthI);

    lv_obj_set_width(ui_SDepthIL, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SDepthIL, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_SDepthIL, lv_pct(0));
    lv_obj_set_y(ui_SDepthIL, lv_pct(0));

    lv_obj_set_align(ui_SDepthIL, LV_ALIGN_CENTER);

    lv_label_set_text(ui_SDepthIL, "Setup Depth Interactively");

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

    // ui_SDepthFL

    ui_SDepthFL = lv_label_create(ui_SDepthF);

    lv_obj_set_width(ui_SDepthFL, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SDepthFL, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_SDepthFL, lv_pct(0));
    lv_obj_set_y(ui_SDepthFL, lv_pct(0));

    lv_obj_set_align(ui_SDepthFL, LV_ALIGN_CENTER);

    lv_label_set_text(ui_SDepthFL, "Setup Depth Fancy");

    lv_obj_set_style_text_color(ui_SDepthFL, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SDepthFL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SPattern

    ui_SPattern = lv_btn_create(ui_Menue);

    lv_obj_set_height(ui_SPattern, 30);
    lv_obj_set_width(ui_SPattern, lv_pct(80));

    lv_obj_set_y(ui_SPattern, 20);
    lv_obj_set_x(ui_SPattern, lv_pct(1));

    lv_obj_set_align(ui_SPattern, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_SPattern, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_SPattern, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_SPattern, ui_event_SPattern, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_SPattern, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SPattern, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SPatternL

    ui_SPatternL = lv_label_create(ui_SPattern);

    lv_obj_set_width(ui_SPatternL, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SPatternL, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_SPatternL, lv_pct(0));
    lv_obj_set_y(ui_SPatternL, lv_pct(0));

    lv_obj_set_align(ui_SPatternL, LV_ALIGN_CENTER);

    lv_label_set_text(ui_SPatternL, "Select Pattern");

    lv_obj_set_style_text_color(ui_SPatternL, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SPatternL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_STorqe

    ui_STorqe = lv_btn_create(ui_Menue);

    lv_obj_set_height(ui_STorqe, 30);
    lv_obj_set_width(ui_STorqe, lv_pct(80));

    lv_obj_set_y(ui_STorqe, 60);
    lv_obj_set_x(ui_STorqe, lv_pct(1));

    lv_obj_set_align(ui_STorqe, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_STorqe, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_STorqe, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_STorqe, ui_event_STorqe, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_STorqe, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_STorqe, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_STorqeL

    ui_STorqeL = lv_label_create(ui_STorqe);

    lv_obj_set_width(ui_STorqeL, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_STorqeL, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_STorqeL, lv_pct(0));
    lv_obj_set_y(ui_STorqeL, lv_pct(0));

    lv_obj_set_align(ui_STorqeL, LV_ALIGN_CENTER);

    lv_label_set_text(ui_STorqeL, "Setup Torqe");

    lv_obj_set_style_text_color(ui_STorqeL, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_STorqeL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

}
void ui_Torqe_screen_init(void)
{

    // ui_Torqe

    ui_Torqe = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Torqe, LV_OBJ_FLAG_SCROLLABLE);

    // ui_Logo4

    ui_Logo4 = lv_label_create(ui_Torqe);

    lv_obj_set_width(ui_Logo4, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Logo4, LV_SIZE_CONTENT);

    lv_obj_set_y(ui_Logo4, -103);
    lv_obj_set_x(ui_Logo4, lv_pct(0));

    lv_obj_set_align(ui_Logo4, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Logo4, "OSSM REMOTE");

    lv_obj_set_style_text_font(ui_Logo4, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Logo4, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Logo4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Logo4, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Logo4, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonL4

    ui_ButtonL4 = lv_btn_create(ui_Torqe);

    lv_obj_set_width(ui_ButtonL4, 100);
    lv_obj_set_height(ui_ButtonL4, 30);

    lv_obj_set_y(ui_ButtonL4, 100);
    lv_obj_set_x(ui_ButtonL4, lv_pct(-33));

    lv_obj_set_align(ui_ButtonL4, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonL4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonL4, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_ButtonL4, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonL4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelL4

    ui_LabelL4 = lv_label_create(ui_ButtonL4);

    lv_obj_set_width(ui_LabelL4, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelL4, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelL4, lv_pct(0));
    lv_obj_set_y(ui_LabelL4, lv_pct(0));

    lv_obj_set_align(ui_LabelL4, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelL4, "");

    lv_obj_set_style_text_color(ui_LabelL4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelL4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonM4

    ui_ButtonM4 = lv_btn_create(ui_Torqe);

    lv_obj_set_width(ui_ButtonM4, 100);
    lv_obj_set_height(ui_ButtonM4, 30);

    lv_obj_set_y(ui_ButtonM4, 100);
    lv_obj_set_x(ui_ButtonM4, lv_pct(0));

    lv_obj_set_align(ui_ButtonM4, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonM4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonM4, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonM4, ui_event_ButtonM4, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonM4, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonM4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelM4

    ui_LabelM4 = lv_label_create(ui_ButtonM4);

    lv_obj_set_width(ui_LabelM4, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelM4, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelM4, lv_pct(0));
    lv_obj_set_y(ui_LabelM4, lv_pct(0));

    lv_obj_set_align(ui_LabelM4, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelM4, "Home");

    lv_obj_set_style_text_color(ui_LabelM4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelM4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonR4

    ui_ButtonR4 = lv_btn_create(ui_Torqe);

    lv_obj_set_width(ui_ButtonR4, 100);
    lv_obj_set_height(ui_ButtonR4, 30);

    lv_obj_set_y(ui_ButtonR4, 100);
    lv_obj_set_x(ui_ButtonR4, lv_pct(33));

    lv_obj_set_align(ui_ButtonR4, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonR4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonR4, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonR4, ui_event_ButtonR4, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonR4, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonR4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelR4

    ui_LabelR4 = lv_label_create(ui_ButtonR4);

    lv_obj_set_width(ui_LabelR4, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelR4, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelR4, lv_pct(0));
    lv_obj_set_y(ui_LabelR4, lv_pct(0));

    lv_obj_set_align(ui_LabelR4, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelR4, "Menue");

    lv_obj_set_style_text_color(ui_LabelR4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelR4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SpeedL1

    ui_SpeedL1 = lv_label_create(ui_Torqe);

    lv_obj_set_width(ui_SpeedL1, lv_pct(70));
    lv_obj_set_height(ui_SpeedL1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_SpeedL1, 20);
    lv_obj_set_y(ui_SpeedL1, -60);

    lv_obj_set_align(ui_SpeedL1, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_SpeedL1, "Out Torqe:");

    lv_obj_set_style_text_color(ui_SpeedL1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SpeedL1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SpeedL1, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Otorqe

    ui_Otorqe = lv_label_create(ui_SpeedL1);

    lv_obj_set_width(ui_Otorqe, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Otorqe, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Otorqe, 0);
    lv_obj_set_y(ui_Otorqe, 2);

    lv_obj_set_align(ui_Otorqe, LV_ALIGN_RIGHT_MID);

    lv_label_set_text(ui_Otorqe, "");

    // ui_DepthL1

    ui_DepthL1 = lv_label_create(ui_Torqe);

    lv_obj_set_width(ui_DepthL1, lv_pct(70));
    lv_obj_set_height(ui_DepthL1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_DepthL1, 20);
    lv_obj_set_y(ui_DepthL1, -25);

    lv_obj_set_align(ui_DepthL1, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_DepthL1, "In Torqe:");

    lv_obj_set_style_text_color(ui_DepthL1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DepthL1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DepthL1, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Itorqe

    ui_Itorqe = lv_label_create(ui_DepthL1);

    lv_obj_set_width(ui_Itorqe, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Itorqe, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Itorqe, 0);
    lv_obj_set_y(ui_Itorqe, 0);

    lv_obj_set_align(ui_Itorqe, LV_ALIGN_RIGHT_MID);

    lv_label_set_text(ui_Itorqe, "");

    // ui_Batt4

    ui_Batt4 = lv_label_create(ui_Torqe);

    lv_obj_set_width(ui_Batt4, 85);
    lv_obj_set_height(ui_Batt4, 30);

    lv_obj_set_x(ui_Batt4, 115);
    lv_obj_set_y(ui_Batt4, -103);

    lv_obj_set_align(ui_Batt4, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Batt4, "Batt");

    // ui_BattValue4

    ui_BattValue4 = lv_label_create(ui_Batt4);

    lv_obj_set_width(ui_BattValue4, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_BattValue4, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_BattValue4, 0);
    lv_obj_set_y(ui_BattValue4, -7);

    lv_obj_set_align(ui_BattValue4, LV_ALIGN_RIGHT_MID);

    lv_label_set_text(ui_BattValue4, "");
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
void ui_Pattern_screen_init(void)
{

    // ui_Pattern

    ui_Pattern = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Pattern, LV_OBJ_FLAG_SCROLLABLE);

    // ui_Logo5

    ui_Logo5 = lv_label_create(ui_Pattern);

    lv_obj_set_width(ui_Logo5, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Logo5, LV_SIZE_CONTENT);

    lv_obj_set_y(ui_Logo5, -103);
    lv_obj_set_x(ui_Logo5, lv_pct(0));

    lv_obj_set_align(ui_Logo5, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Logo5, "OSSM REMOTE");

    lv_obj_set_style_text_font(ui_Logo5, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Logo5, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Logo5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Logo5, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Logo5, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonL5

    ui_ButtonL5 = lv_btn_create(ui_Pattern);

    lv_obj_set_width(ui_ButtonL5, 100);
    lv_obj_set_height(ui_ButtonL5, 30);

    lv_obj_set_y(ui_ButtonL5, 100);
    lv_obj_set_x(ui_ButtonL5, lv_pct(-33));

    lv_obj_set_align(ui_ButtonL5, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonL5, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonL5, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_ButtonL5, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonL5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelL5

    ui_LabelL5 = lv_label_create(ui_ButtonL5);

    lv_obj_set_width(ui_LabelL5, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelL5, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelL5, lv_pct(0));
    lv_obj_set_y(ui_LabelL5, lv_pct(0));

    lv_obj_set_align(ui_LabelL5, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelL5, "");

    lv_obj_set_style_text_color(ui_LabelL5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelL5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonM5

    ui_ButtonM5 = lv_btn_create(ui_Pattern);

    lv_obj_set_width(ui_ButtonM5, 100);
    lv_obj_set_height(ui_ButtonM5, 30);

    lv_obj_set_y(ui_ButtonM5, 100);
    lv_obj_set_x(ui_ButtonM5, lv_pct(0));

    lv_obj_set_align(ui_ButtonM5, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonM5, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonM5, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonM5, ui_event_ButtonM5, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonM5, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonM5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelM5

    ui_LabelM5 = lv_label_create(ui_ButtonM5);

    lv_obj_set_width(ui_LabelM5, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelM5, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelM5, lv_pct(0));
    lv_obj_set_y(ui_LabelM5, lv_pct(0));

    lv_obj_set_align(ui_LabelM5, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelM5, "Home");

    lv_obj_set_style_text_color(ui_LabelM5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelM5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonR5

    ui_ButtonR5 = lv_btn_create(ui_Pattern);

    lv_obj_set_width(ui_ButtonR5, 100);
    lv_obj_set_height(ui_ButtonR5, 30);

    lv_obj_set_y(ui_ButtonR5, 100);
    lv_obj_set_x(ui_ButtonR5, lv_pct(33));

    lv_obj_set_align(ui_ButtonR5, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonR5, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonR5, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonR5, ui_event_ButtonR5, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonR5, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonR5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelR5

    ui_LabelR5 = lv_label_create(ui_ButtonR5);

    lv_obj_set_width(ui_LabelR5, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelR5, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelR5, lv_pct(0));
    lv_obj_set_y(ui_LabelR5, lv_pct(0));

    lv_obj_set_align(ui_LabelR5, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelR5, "Menue");

    lv_obj_set_style_text_color(ui_LabelR5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelR5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Batt5

    ui_Batt5 = lv_label_create(ui_Pattern);

    lv_obj_set_width(ui_Batt5, 85);
    lv_obj_set_height(ui_Batt5, 30);

    lv_obj_set_x(ui_Batt5, 115);
    lv_obj_set_y(ui_Batt5, -103);

    lv_obj_set_align(ui_Batt5, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Batt5, "Batt");

    // ui_BattValue5

    ui_BattValue5 = lv_label_create(ui_Batt5);

    lv_obj_set_width(ui_BattValue5, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_BattValue5, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_BattValue5, 0);
    lv_obj_set_y(ui_BattValue5, -7);

    lv_obj_set_align(ui_BattValue5, LV_ALIGN_RIGHT_MID);

    lv_label_set_text(ui_BattValue5, "");
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

    // ui_PatternS

    ui_PatternS = lv_dropdown_create(ui_Pattern);
    lv_dropdown_set_options(ui_PatternS,
                            "SimpleStroke\nTeasingPounding\nRoboStroke\nHalfnHalf\nDeeper\nStopNGo\nInsist\nJackHammer\nStrokeNibbler");
    lv_dropdown_set_text(ui_PatternS, "");

    lv_obj_set_width(ui_PatternS, lv_pct(90));
    lv_obj_set_height(ui_PatternS, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_PatternS, 0);
    lv_obj_set_y(ui_PatternS, -20);

    lv_obj_set_align(ui_PatternS, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_PatternS, LV_OBJ_FLAG_SCROLL_ON_FOCUS);

    // ui_Label4

    ui_Label4 = lv_label_create(ui_Pattern);

    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label4, 0);
    lv_obj_set_y(ui_Label4, -60);

    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label4, "Select Pattern:");

    // ui_PatternOK

    ui_PatternOK = lv_btn_create(ui_Pattern);

    lv_obj_set_width(ui_PatternOK, 100);
    lv_obj_set_height(ui_PatternOK, 30);

    lv_obj_set_y(ui_PatternOK, 40);
    lv_obj_set_x(ui_PatternOK, lv_pct(0));

    lv_obj_set_align(ui_PatternOK, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_PatternOK, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_PatternOK, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_PatternOK, ui_event_PatternOK, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_PatternOK, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PatternOK, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelL6

    ui_LabelL6 = lv_label_create(ui_PatternOK);

    lv_obj_set_width(ui_LabelL6, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelL6, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelL6, lv_pct(0));
    lv_obj_set_y(ui_LabelL6, lv_pct(0));

    lv_obj_set_align(ui_LabelL6, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelL6, "OK");

    lv_obj_set_style_text_color(ui_LabelL6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelL6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Start_screen_init();
    ui_Settings_screen_init();
    ui_Home_screen_init();
    ui_Menue_screen_init();
    ui_Torqe_screen_init();
    ui_Pattern_screen_init();
    lv_disp_load_scr(ui_Start);
}

