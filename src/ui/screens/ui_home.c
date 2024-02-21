#include "../ui.h"
#include "../../language.h"
#include "../../main.h"

// SCREEN: ui_Home

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
    lv_slider_set_range(ui_homespeedslider, 0, rate_limit);
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
    lv_slider_set_range(ui_homedepthslider, 0, depth_limit);

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
    lv_slider_set_range(ui_homestrokeslider, 0, depth_limit);

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
    //lv_label_set_color(ui_BattValue2, "true");

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

    ui_connect_home = lv_label_create(ui_Home);

    lv_obj_set_width(ui_connect_home, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_connect_home, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_connect_home, -115);
    lv_obj_set_y(ui_connect_home, -105);
    lv_obj_set_width(ui_connect_home, 83);
    lv_obj_set_height(ui_connect_home, 25);
    lv_obj_set_align(ui_connect_home, LV_ALIGN_CENTER);
    lv_label_set_text(ui_connect_home, T_BLANK);
    lv_obj_set_style_text_font(ui_connect_home, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
}