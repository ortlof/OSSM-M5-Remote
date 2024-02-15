#include "../ui.h"
#include "../../language.h"
#include "main.h"

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
    //lv_label_set_recolor(ui_BattValue4, "true");

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