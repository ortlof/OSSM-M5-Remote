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
lv_obj_t * ui_DepthL;
lv_obj_t * ui_Depth;
lv_obj_t * ui_StrokeL;
lv_obj_t * ui_Stroke;
lv_obj_t * ui_SensationL;
lv_obj_t * ui_Sensation;
lv_obj_t * ui_Batt2;
lv_obj_t * ui_BattValue2;
lv_obj_t * ui_Battery2;

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
        _ui_screen_change(ui_Start, LV_SCR_LOAD_ANIM_FADE_ON, 90, 0);
    }
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

    lv_label_set_text(ui_SpeedL, "Speed");

    lv_obj_set_style_text_color(ui_SpeedL, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SpeedL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SpeedL, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Speed

    ui_Speed = lv_slider_create(ui_SpeedL);
    lv_slider_set_range(ui_Speed, 0, 100);

    lv_obj_set_width(ui_Speed, 175);
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

    // ui_DepthL

    ui_DepthL = lv_label_create(ui_Home);

    lv_obj_set_width(ui_DepthL, lv_pct(95));
    lv_obj_set_height(ui_DepthL, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_DepthL, 0);
    lv_obj_set_y(ui_DepthL, -25);

    lv_obj_set_align(ui_DepthL, LV_ALIGN_CENTER);

    lv_label_set_text(ui_DepthL, "Depth");

    lv_obj_set_style_text_color(ui_DepthL, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DepthL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DepthL, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Depth

    ui_Depth = lv_slider_create(ui_DepthL);
    lv_slider_set_range(ui_Depth, 0, 100);

    lv_obj_set_width(ui_Depth, 175);
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

    // ui_StrokeL

    ui_StrokeL = lv_label_create(ui_Home);

    lv_obj_set_width(ui_StrokeL, lv_pct(95));
    lv_obj_set_height(ui_StrokeL, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_StrokeL, 0);
    lv_obj_set_y(ui_StrokeL, 10);

    lv_obj_set_align(ui_StrokeL, LV_ALIGN_CENTER);

    lv_label_set_text(ui_StrokeL, "Stroke");

    lv_obj_set_style_text_color(ui_StrokeL, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_StrokeL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_StrokeL, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Stroke

    ui_Stroke = lv_slider_create(ui_StrokeL);
    lv_slider_set_range(ui_Stroke, 0, 100);

    lv_obj_set_width(ui_Stroke, 175);
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

    // ui_SensationL

    ui_SensationL = lv_label_create(ui_Home);

    lv_obj_set_width(ui_SensationL, lv_pct(95));
    lv_obj_set_height(ui_SensationL, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_SensationL, 0);
    lv_obj_set_y(ui_SensationL, 45);

    lv_obj_set_align(ui_SensationL, LV_ALIGN_CENTER);

    lv_label_set_text(ui_SensationL, "Sensation");

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

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Start_screen_init();
    ui_Settings_screen_init();
    ui_Home_screen_init();
    lv_disp_load_scr(ui_Start);
}

