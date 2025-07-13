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
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff536864), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // temp_visual
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.temp_visual = obj;
            lv_obj_set_pos(obj, 33, 33);
            lv_obj_set_size(obj, 18, 139);
            lv_bar_set_value(obj, 75, LV_ANIM_OFF);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // co2_visual
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.co2_visual = obj;
            lv_obj_set_pos(obj, 271, 33);
            lv_obj_set_size(obj, 18, 139);
            lv_bar_set_value(obj, 75, LV_ANIM_OFF);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.humid_visual = obj;
            lv_obj_set_pos(obj, 85, 51);
            lv_obj_set_size(obj, 150, 150);
            lv_arc_set_range(obj, 0, 100);
            lv_arc_set_value(obj, 0);

            // Hide the knob (indicator circle)
            lv_obj_set_style_pad_all(obj, 0, LV_PART_KNOB);
            lv_obj_set_style_bg_opa(obj, LV_OPA_TRANSP, LV_PART_KNOB);

            // Set arc thickness
            lv_obj_set_style_arc_width(obj, 15, LV_PART_MAIN);
            lv_obj_set_style_arc_width(obj, 15, LV_PART_INDICATOR);

            // Set static color for arc fill
            lv_obj_set_style_arc_color(obj, lv_color_hex(0x2196F3), LV_PART_INDICATOR);

            // Transparent background if desired
            lv_obj_set_style_bg_opa(obj, LV_OPA_TRANSP, LV_PART_MAIN);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 25, 176);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_sensor_name(obj);
            lv_label_set_text(obj, "Temp");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 131, 109);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_sensor_name(obj);
            lv_label_set_text(obj, "Humidity");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 267, 176);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_sensor_name(obj);
            lv_label_set_text(obj, "CO2");
        }
        {
            // temp_value_display
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.temp_value_display = obj;
            lv_obj_set_pos(obj, 17, 191);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_sensor_value(obj);
            lv_obj_set_style_min_width(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_max_width(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_min_height(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_max_height(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "00.00");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 53, 11);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff48b41a), LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Sensor Data Dashboard");
        }
        {
            // humid_value_display
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.humid_value_display = obj;
            lv_obj_set_pos(obj, 135, 126);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_sensor_value(obj);
            lv_obj_set_style_min_width(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_max_width(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_min_height(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_max_height(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "00.00");
        }
        {
            // co2_value_display
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.co2_value_display = obj;
            lv_obj_set_pos(obj, 255, 191);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_sensor_value(obj);
            lv_obj_set_style_min_width(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_max_width(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_min_height(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_max_height(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "00.00");
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj4 = obj;
            lv_obj_set_pos(obj, 126, 201);
            lv_obj_set_size(obj, 70, 25);
            lv_obj_add_event_cb(obj, action_go_to_settings, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff474c4f), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Settings");
                }
            }
        }
    }

    tick_screen_dashboard();
}

void tick_screen_dashboard()
{
}

void create_screen_main()
{
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_text_color(obj, lv_color_hex(0xff212121), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff536864), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_spinner_create(parent_obj);
            objects.obj4 = obj;
            lv_obj_set_pos(obj, 105, 54);
            lv_obj_set_size(obj, 110, 110);
            lv_spinner_set_anim_params(obj, 1000, 60);

            lv_obj_set_style_arc_width(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

            // ✅ Set rotating arc color (indicator part)
            lv_obj_set_style_arc_color(obj, lv_color_hex(0xFFFFC8), LV_PART_INDICATOR | LV_STATE_DEFAULT);

            // Optional: Make background transparent if needed
            lv_obj_set_style_bg_opa(obj, LV_OPA_TRANSP, LV_PART_MAIN);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj5 = obj;
            lv_obj_set_pos(obj, 123, 164);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Loading");
        }
    }

    tick_screen_main();
}

void tick_screen_main()
{
}

void create_screen_settings()
{
    lv_obj_t *obj = lv_obj_create(0);
    objects.settings = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff536864), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj6 = obj;
            lv_obj_set_pos(obj, 117, 10);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff48b41a), LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
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
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_WITH_ARROW);
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
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_WITH_ARROW);
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
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_WITH_ARROW);
            add_style_critical_input(obj);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

            lv_obj_add_event_cb(obj, textarea_event_cb, LV_EVENT_ALL, NULL);
        }
        {
            // home_button
            lv_obj_t *obj = lv_button_create(parent_obj);
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
            lv_obj_t *obj = lv_button_create(parent_obj);
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

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_dashboard,
    tick_screen_main,
    tick_screen_settings,
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
    create_screen_main();
    create_screen_settings();
    init_sensor_data();
    lv_timer_create(update_sensor_display_cb, 1000, NULL);
}
