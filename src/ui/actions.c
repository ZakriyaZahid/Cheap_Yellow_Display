#include "lvgl.h"
#include "actions.h"
#include "screens.h"
#include <stdio.h>

float temp_critical = 32.0;
float humid_critical = 45.0;
float co2_critical = 900.0;
int value_index = 0;

void action_go_to_settings(lv_event_t *e)
{
    // Example logic to switch screen
    loadScreen(SCREEN_ID_SETTINGS);
    populate_critical_inputs();
}

void action_go_to_home(lv_event_t *e)
{
    loadScreen(SCREEN_ID_DASHBOARD);
}

void action_update_critical_values(lv_event_t *e)
{
    // Your custom logic here
    update_critical_values_from_inputs();
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

void keypad_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_READY || code == LV_EVENT_CANCEL)
    {
        lv_obj_add_flag(objects.keypad, LV_OBJ_FLAG_HIDDEN); // Hide keyboard
        lv_keyboard_set_textarea(objects.keypad, NULL);      // Detach from textarea
    }
}

void init_sensor_data()
{
    for (int i = 0; i < 50; i++)
    {
        temp_values[i] = 30.0 + i * 0.1;  // 30.0 to 35.0
        humid_values[i] = 40.0 + i * 0.2; // 40.0 to 50.0
        co2_values[i] = 800.0 + i * 10;   // 800 to 1300
    }
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

void populate_critical_inputs(void)
{
    char buf[6]; // 5 digits max + null terminator

    // Temp
    lv_textarea_set_text(objects.temp_critical_value, ""); // Optional clear
    snprintf(buf, sizeof(buf), "%.1f", temp_critical);
    lv_textarea_set_text(objects.temp_critical_value, buf);

    // Humidity
    lv_textarea_set_text(objects.humid_critical_value, "");
    snprintf(buf, sizeof(buf), "%.1f", humid_critical);
    lv_textarea_set_text(objects.humid_critical_value, buf);

    // CO2
    lv_textarea_set_text(objects.co2_critical_value, "");
    snprintf(buf, sizeof(buf), "%.1f", co2_critical);
    lv_textarea_set_text(objects.co2_critical_value, buf);
}

void update_critical_values_from_inputs(void)
{
    const char *temp_str = lv_textarea_get_text(objects.temp_critical_value);
    const char *humid_str = lv_textarea_get_text(objects.humid_critical_value);
    const char *co2_str = lv_textarea_get_text(objects.co2_critical_value);

    temp_critical = atof(temp_str);
    humid_critical = atof(humid_str);
    co2_critical = atof(co2_str);
}
