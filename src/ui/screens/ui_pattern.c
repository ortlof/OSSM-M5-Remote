#include "../ui.h"
#include "../../language.h"
#include "main.h"

// SCREEN: ui_Pattern

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
    //lv_label_set_recolor(ui_BattValue5, "true");

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
    lv_roller_set_options(ui_PatternS,"",LV_ROLLER_MODE_NORMAL);

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