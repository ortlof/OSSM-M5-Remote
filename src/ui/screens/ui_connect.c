#include "../ui.h"
#include "../../language.h"

// SCREEN: ui_Connect

void ui_Connect_screen_init(void)
{

    // ui_Connect

    ui_Connect = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Connect, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_Connect, ui_event_Start, LV_EVENT_ALL, NULL);


    // ui_Logo

    ui_Logo = lv_label_create(ui_Connect);

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

    // ui_ConnectButtonL

    ui_ConnectButtonL = lv_btn_create(ui_Connect);

    lv_obj_set_width(ui_ConnectButtonL, 100);
    lv_obj_set_height(ui_ConnectButtonL, 30);

    lv_obj_set_y(ui_ConnectButtonL, 100);
    lv_obj_set_x(ui_ConnectButtonL, lv_pct(-33));

    lv_obj_set_align(ui_ConnectButtonL, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ConnectButtonL, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ConnectButtonL, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_state(ui_ConnectButtonL, LV_STATE_DISABLED);
    lv_obj_add_event_cb(ui_ConnectButtonL, ui_event_ConnectButtonL, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ConnectButtonL, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ConnectButtonL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ConnectButtonLText

    ui_ConnectButtonLText = lv_label_create(ui_ConnectButtonL);

    lv_obj_set_width(ui_ConnectButtonLText, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ConnectButtonLText, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ConnectButtonLText, lv_pct(0));
    lv_obj_set_y(ui_ConnectButtonLText, lv_pct(0));

    lv_obj_set_align(ui_ConnectButtonLText, LV_ALIGN_CENTER);

    lv_label_set_text(ui_ConnectButtonLText, T_CONNECT);

    lv_obj_set_style_text_color(ui_ConnectButtonLText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ConnectButtonLText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ConnectButtonM

    ui_ConnectButtonM = lv_btn_create(ui_Connect);

    lv_obj_set_width(ui_ConnectButtonM, 100);
    lv_obj_set_height(ui_ConnectButtonM, 30);

    lv_obj_set_y(ui_ConnectButtonM, 100);
    lv_obj_set_x(ui_ConnectButtonM, lv_pct(0));

    lv_obj_set_align(ui_ConnectButtonM, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ConnectButtonM, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ConnectButtonM, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ConnectButtonM, ui_event_ConnectButtonM, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ConnectButtonM, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ConnectButtonM, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ConnectButtonMText

    ui_ConnectButtonMText = lv_label_create(ui_ConnectButtonM);

    lv_obj_set_width(ui_ConnectButtonMText, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ConnectButtonMText, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ConnectButtonMText, lv_pct(0));
    lv_obj_set_y(ui_ConnectButtonMText, lv_pct(0));

    lv_obj_set_align(ui_ConnectButtonMText, LV_ALIGN_CENTER);

    lv_label_set_text(ui_ConnectButtonMText, T_RESCAN);
  
    lv_obj_set_style_text_color(ui_ConnectButtonMText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ConnectButtonMText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ConnectButtonR

    ui_ConnectButtonR = lv_btn_create(ui_Connect);

    lv_obj_set_width(ui_ConnectButtonR, 100);
    lv_obj_set_height(ui_ConnectButtonR, 30);

    lv_obj_set_y(ui_ConnectButtonR, 100);
    lv_obj_set_x(ui_ConnectButtonR, lv_pct(33));

    lv_obj_set_align(ui_ConnectButtonR, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ConnectButtonR, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ConnectButtonR, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_state(ui_ConnectButtonR, LV_STATE_DISABLED);
    lv_obj_add_event_cb(ui_ConnectButtonR, ui_event_ConnectButtonR, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ConnectButtonR, lv_color_hex(0x83277B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ConnectButtonR, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ConnectButtonRText

    ui_ConnectButtonRText = lv_label_create(ui_ConnectButtonR);

    lv_obj_set_width(ui_ConnectButtonRText, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ConnectButtonRText, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ConnectButtonRText, lv_pct(0));
    lv_obj_set_y(ui_ConnectButtonRText, lv_pct(0));

    lv_obj_set_align(ui_ConnectButtonRText, LV_ALIGN_CENTER);

    lv_label_set_text(ui_ConnectButtonRText, T_CONNECT);

    lv_obj_set_style_text_color(ui_ConnectButtonRText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ConnectButtonRText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Batt

    ui_Connect_Batt = lv_label_create(ui_Connect);

    lv_obj_set_width(ui_Connect_Batt, 85);
    lv_obj_set_height(ui_Connect_Batt, 30);

    lv_obj_set_x(ui_Connect_Batt, 115);
    lv_obj_set_y(ui_Connect_Batt, -103);

    lv_obj_set_align(ui_Connect_Batt, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Connect_Batt, T_BATT);

    // ui_Connect_BattValue

    ui_Connect_BattValue = lv_label_create(ui_Connect_Batt);

    lv_obj_set_width(ui_Connect_BattValue, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Connect_BattValue, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Connect_BattValue, 0);
    lv_obj_set_y(ui_Connect_BattValue, -7);

    lv_obj_set_align(ui_Connect_BattValue, LV_ALIGN_RIGHT_MID);

    lv_label_set_text(ui_Connect_BattValue, T_BLANK);

    // ui_Connect_Battery

    ui_Connect_Battery = lv_bar_create(ui_Batt);
    lv_bar_set_range(ui_Connect_Battery, 0, 100);

    lv_obj_set_width(ui_Connect_Battery, 80);
    lv_obj_set_height(ui_Connect_Battery, 10);

    lv_obj_set_x(ui_Connect_Battery, 0);
    lv_obj_set_y(ui_Connect_Battery, 10);

    lv_obj_set_align(ui_Connect_Battery, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_Connect_Battery, lv_color_hex(0xD591D5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Connect_Battery, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Connect_Battery, lv_color_hex(0x83247B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Connect_Battery, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_connect

    ui_connect_connect = lv_label_create(ui_Connect);

    lv_obj_set_x(ui_connect_connect, -115);
    lv_obj_set_y(ui_connect_connect, -105);
    lv_obj_set_width(ui_connect_connect, 83);
    lv_obj_set_height(ui_connect_connect, 25);
    lv_obj_set_align(ui_connect_connect, LV_ALIGN_CENTER);
    lv_label_set_text(ui_connect_connect, T_BLANK);
    lv_obj_set_style_text_font(ui_connect_connect, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Connect_Spinner

    ui_connect_spinner = lv_label_create(ui_Connect);
    lv_obj_set_width(ui_connect_spinner, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_connect_spinner, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_connect_spinner, 0);
    lv_obj_set_y(ui_connect_spinner, -70);
    lv_obj_set_align(ui_connect_spinner, LV_ALIGN_CENTER);
    lv_label_set_text(ui_connect_spinner, T_SCAN);
    lv_obj_add_flag(ui_connect_spinner, LV_OBJ_FLAG_HIDDEN);

    // ui_PatternS

    ui_connect_roller = lv_roller_create(ui_Connect);
    lv_roller_set_options(ui_connect_roller,"",LV_ROLLER_MODE_NORMAL);

    lv_obj_set_height(ui_connect_roller, 119);
    lv_obj_set_width(ui_connect_roller, lv_pct(95));

    lv_obj_set_x(ui_connect_roller, 0);
    lv_obj_set_y(ui_connect_roller, 15);

    lv_obj_set_align(ui_connect_roller, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_connect_roller, lv_color_hex(0xB481AC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_connect_roller, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_connect_roller, lv_color_hex(0x83247B), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_connect_roller, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
}