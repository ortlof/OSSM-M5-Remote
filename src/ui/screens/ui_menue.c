#include "../ui.h"
#include "../../language.h"
#include "main.h"


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
    //lv_label_set_recolor(ui_BattValue3, "true");

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