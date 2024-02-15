#include "../ui.h"
#include "../../language.h"
#include "main.h"

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
    //lv_label_set_recolor(ui_BattValue6, "true");

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