#include "../ui.h"
#include "../../language.h"

// SCREEN: ui_Start

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

    lv_obj_add_state(ui_StartButtonL, LV_STATE_DISABLED);
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
    lv_obj_add_state(ui_StartButtonM, LV_STATE_DISABLED);

    //lv_obj_add_event_cb(ui_StartButtonM, ui_event_StartButtonM, LV_EVENT_ALL, NULL);
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

    ui_LOVE_Logo = lv_img_create(ui_Start);
    lv_img_set_src(ui_LOVE_Logo, &image50x50);

    lv_obj_set_width(ui_LOVE_Logo, 100);    lv_obj_set_height(ui_LOVE_Logo, 100);

    lv_obj_set_x(ui_LOVE_Logo, 0);
    lv_obj_set_y(ui_LOVE_Logo, 10);

    lv_obj_set_align(ui_LOVE_Logo, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_LOVE_Logo, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_LOVE_Logo, LV_OBJ_FLAG_SCROLLABLE);


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

        // ui_connect

    ui_connect_start = lv_label_create(ui_Start);

    lv_obj_set_width(ui_connect_start, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_connect_start, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_connect_start, -115);
    lv_obj_set_y(ui_connect_start, -105);
    lv_obj_set_width(ui_connect_start, 83);
    lv_obj_set_height(ui_connect_start, 25);
    lv_obj_set_align(ui_connect_start, LV_ALIGN_CENTER);
    lv_label_set_text(ui_connect_start, T_BLANK);
    lv_obj_set_style_text_font(ui_connect_start, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
}