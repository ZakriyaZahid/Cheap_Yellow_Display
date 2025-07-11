#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;
uint32_t active_theme_index = 0;

void create_screen_dashboard()
{
    lv_obj_t *obj = lv_obj_create(0);
    objects.dashboard = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff71c2f0), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // settings_button
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.settings_button = obj;
            lv_obj_set_pos(obj, 125, 198);
            lv_obj_set_size(obj, 70, 25);
            lv_obj_add_event_cb(obj, action_go_to_settings, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0d85e4), LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffec1d1d), LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffe82323), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff474c4f), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj0 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_label_set_text(obj, "Settings");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 238, 102);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_sensor_value_cover(obj);
            lv_label_set_text(obj, "");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 132, 50);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_sensor_value_cover(obj);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj2 = obj;
            lv_obj_set_pos(obj, 18, 167);
            lv_obj_set_size(obj, 75, 11);
            add_style_sensor_name(obj);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff1113c7), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Temprature(c)");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 256, 167);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_sensor_name(obj);
            lv_label_set_text(obj, "CO2 %");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 138, 113);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_sensor_name(obj);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff3205db), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Humidity");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj4 = obj;
            lv_obj_set_pos(obj, 62, 10);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff48b41a), LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff3600ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Sensors Data Dashboard");
        }
        {
            // CO2_value_display
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.co2_value_display = obj;
            lv_obj_set_pos(obj, 243, 125);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_sensor_value(obj);
            lv_label_set_text(obj, "00.00");
        }
        {
            // humid_value_display
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.humid_value_display = obj;
            lv_obj_set_pos(obj, 138, 72);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_sensor_value(obj);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "00.00");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj5 = obj;
            lv_obj_set_pos(obj, 25, 103);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_sensor_value_cover(obj);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // temp_value_display_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.temp_value_display = obj;
            lv_obj_set_pos(obj, 30, 125);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_sensor_value(obj);
            lv_label_set_text(obj, "00.00");
        }
    }

    tick_screen_dashboard();
}

void tick_screen_dashboard()
{
}

void create_screen_settings()
{
    lv_obj_t *obj = lv_obj_create(0);
    objects.settings = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff71c2f0), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj6 = obj;
            lv_obj_set_pos(obj, 117, 10);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff48b41a), LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff3600ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Settings");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 28, 60);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_critical_name(obj);
            lv_label_set_text(obj, "Temprature Critical Value:");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 28, 108);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_critical_name(obj);
            lv_label_set_text(obj, "Humidity Critical Value:");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 28, 153);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_critical_name(obj);
            lv_label_set_text(obj, "CO2 Critical Value:");
        }
        {
            // CO2_critical_value
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.co2_critical_value = obj;
            lv_obj_set_pos(obj, 193, 141);
            lv_obj_set_size(obj, 100, 35);
            lv_textarea_set_max_length(obj, 5);
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            add_style_critical_input(obj);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

            lv_obj_add_event_cb(obj, textarea_event_cb, LV_EVENT_ALL, NULL);
        }
        {
            // humid_critical_value
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.humid_critical_value = obj;
            lv_obj_set_pos(obj, 193, 96);
            lv_obj_set_size(obj, 100, 35);
            lv_textarea_set_max_length(obj, 5);
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            add_style_critical_input(obj);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

            lv_obj_add_event_cb(obj, textarea_event_cb, LV_EVENT_ALL, NULL);
        }
        {
            // temp_critical_value
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.temp_critical_value = obj;
            lv_obj_set_pos(obj, 193, 48);
            lv_obj_set_size(obj, 100, 35);
            lv_textarea_set_max_length(obj, 5);
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            add_style_critical_input(obj);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

            lv_obj_add_event_cb(obj, textarea_event_cb, LV_EVENT_ALL, NULL);
        }
        {
            // home_button
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.home_button = obj;
            lv_obj_set_pos(obj, 64, 197);
            lv_obj_set_size(obj, 70, 25);
            lv_obj_add_event_cb(obj, action_go_to_home, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0d85e4), LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffec1d1d), LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffe82323), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff474c4f), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Back");
                }
            }
        }
        {
            // update_critical_values_button
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.update_critical_values_button = obj;
            lv_obj_set_pos(obj, 183, 197);
            lv_obj_set_size(obj, 70, 25);
            lv_obj_add_event_cb(obj, action_update_critical_values, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0d85e4), LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffec1d1d), LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffe82323), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff474c4f), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Update");
                }
            }
        }
        {
            // keypad
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.keypad = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 257, 174);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_keyboard_set_textarea(obj, NULL);      // Initially detached
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN); // Hidden at start

            // Optional: dismiss keyboard on "Done" or "Cancel"
            lv_obj_add_event_cb(obj, keypad_event_cb, LV_EVENT_ALL, NULL);
        }
    }

    tick_screen_settings();
}

void tick_screen_settings()
{
}

void create_screen_main()
{
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_text_color(obj, lv_color_hex(0xff212121), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff71c2f0), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_spinner_create(parent_obj, 1000, 60);
            lv_obj_set_pos(obj, 105, 54);
            lv_obj_set_size(obj, 110, 110);
            lv_obj_set_style_arc_width(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj7 = obj;
            lv_obj_set_pos(obj, 123, 164);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff1300fc), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Loading");
        }
    }

    tick_screen_main();
}

void tick_screen_main()
{
}

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_dashboard,
    tick_screen_settings,
    tick_screen_main,
};
void tick_screen(int screen_index)
{
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId)
{
    tick_screen_funcs[screenId - 1]();
}

void create_screens()
{
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);

    create_screen_dashboard();
    create_screen_settings();
    create_screen_main();

    // ############################################################# //
    init_sensor_data();
    lv_timer_create(update_sensor_display_cb, 1000, NULL);
    // ############################################################# //
}
