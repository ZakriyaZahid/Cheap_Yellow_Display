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

// Arrays to simulate sensor values
float temp_values[50];
float humid_values[50];
float co2_values[50];

// Index tracker
int value_index = 0;

// Critical thresholds
float temp_critical = 32.0;
float humid_critical = 45.0;
float co2_critical = 900.0;

void init_sensor_data()
{
    for (int i = 0; i < 50; i++)
    {
        temp_values[i] = 30.0 + i * 0.1;  // 30.0 to 35.0
        humid_values[i] = 40.0 + i * 0.2; // 40.0 to 50.0
        co2_values[i] = 800.0 + i * 10;   // 800 to 1300
    }
}

void create_screen_main()
{
    init_sensor_data();

    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff71c2f0), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // settings_button
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.settings_button = obj;
            lv_obj_set_pos(obj, 125, 190);
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
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Settings");
                }
            }
        }
        {
            // temp_value_display
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.temp_value_display = obj;
            lv_obj_set_pos(obj, 40, 112);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_sensor_value(obj);
            lv_label_set_text(obj, "00.00");
        }
        {
            // CO2_value_display
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.co2_value_display = obj;
            lv_obj_set_pos(obj, 249, 112);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_sensor_value(obj);
            lv_label_set_text(obj, "00.00");
        }
        {
            // humid_value_display
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.humid_value_display = obj;
            lv_obj_set_pos(obj, 141, 54);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_sensor_value(obj);
            lv_label_set_text(obj, "00.00");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 28, 134);
            lv_obj_set_size(obj, 64, 11);
            add_style_sensor_name(obj);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff1113c7), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Temprature");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 257, 134);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_sensor_name(obj);
            lv_label_set_text(obj, "CO2 %");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 136, 73);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_sensor_name(obj);
            lv_label_set_text(obj, "Humidity");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 75, 13);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff48b41a), LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Monitor Sensor Values");
        }
    }

    tick_screen_main();
}

void tick_screen_main()
{
}

void keypad_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_READY || code == LV_EVENT_CANCEL)
    {
        lv_obj_add_flag(objects.keypad, LV_OBJ_FLAG_HIDDEN); // Hide keyboard
        lv_keyboard_set_textarea(objects.keypad, NULL);      // Detach from textarea
    }
}

void textarea_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *ta = lv_event_get_target(e);

    if (code == LV_EVENT_FOCUSED)
    {
        lv_keyboard_set_textarea(objects.keypad, ta);
        lv_obj_clear_flag(objects.keypad, LV_OBJ_FLAG_HIDDEN); // Show keyboard
    }
    else if (code == LV_EVENT_DEFOCUSED)
    {
        lv_obj_add_flag(objects.keypad, LV_OBJ_FLAG_HIDDEN); // Hide keyboard
        lv_keyboard_set_textarea(objects.keypad, NULL);      // Detach
    }
}

void create_screen_seetings()
{
    lv_obj_t *obj = lv_obj_create(0);
    objects.seetings = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff71c2f0), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj2 = obj;
            lv_obj_set_pos(obj, 130, 11);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff48b41a), LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
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

    tick_screen_seetings();
}

void tick_screen_seetings()
{
}

void create_screen_loading()
{
    lv_obj_t *obj = lv_obj_create(0);
    objects.loading = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_text_color(obj, lv_color_hex(0xff212121), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff71c2f0), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_spinner_create(parent_obj, 1000, 60);
            lv_obj_set_pos(obj, 120, 80);
            lv_obj_set_size(obj, 80, 80);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 127, 168);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff1300fc), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Loading");
        }
    }

    tick_screen_loading();
}

void tick_screen_loading()
{
}

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_seetings,
    tick_screen_loading,
};
void tick_screen(int screen_index)
{
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId)
{
    tick_screen_funcs[screenId - 1]();
}

void update_sensor_display_cb(lv_timer_t *timer)
{
    if (value_index >= 50)
        value_index = 0;

    float temp = temp_values[value_index];
    float humid = humid_values[value_index];
    float co2 = co2_values[value_index];
    value_index++;

    char buf[16];

    // Update temperature
    snprintf(buf, sizeof(buf), "%.2f", temp);
    lv_label_set_text(objects.temp_value_display, buf);
    lv_obj_set_style_text_color(objects.temp_value_display,
                                temp > temp_critical ? lv_color_hex(0xFF0000) : lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);

    // Update humidity
    snprintf(buf, sizeof(buf), "%.2f", humid);
    lv_label_set_text(objects.humid_value_display, buf);
    lv_obj_set_style_text_color(objects.humid_value_display,
                                humid > humid_critical ? lv_color_hex(0xFF0000) : lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);

    // Update CO2
    snprintf(buf, sizeof(buf), "%.2f", co2);
    lv_label_set_text(objects.co2_value_display, buf);
    lv_obj_set_style_text_color(objects.co2_value_display,
                                co2 > co2_critical ? lv_color_hex(0xFF0000) : lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
}

void create_screens()
{
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);

    create_screen_main();
    create_screen_seetings();
    create_screen_loading();

    lv_timer_create(update_sensor_display_cb, 1000, NULL); // 1000ms = 1 second
}
