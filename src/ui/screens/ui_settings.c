#include "../ui.h"
#include "../../language.h"
#include "main.h"

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
    //lv_label_set_recolor(ui_BattValue1, "true");

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