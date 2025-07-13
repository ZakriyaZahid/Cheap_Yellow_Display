#ifndef EEZ_LVGL_UI_STYLES_H
#define EEZ_LVGL_UI_STYLES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Style: Keypad_button
void add_style_keypad_button(lv_obj_t *obj);
void remove_style_keypad_button(lv_obj_t *obj);

// Style: critical_input
lv_style_t *get_style_critical_input_MAIN_DEFAULT();
void add_style_critical_input(lv_obj_t *obj);
void remove_style_critical_input(lv_obj_t *obj);

// Style: critical_name
lv_style_t *get_style_critical_name_MAIN_DEFAULT();
void add_style_critical_name(lv_obj_t *obj);
void remove_style_critical_name(lv_obj_t *obj);

// Style: sensor_name
lv_style_t *get_style_sensor_name_MAIN_DEFAULT();
void add_style_sensor_name(lv_obj_t *obj);
void remove_style_sensor_name(lv_obj_t *obj);

// Style: sensor_value
lv_style_t *get_style_sensor_value_MAIN_DEFAULT();
void add_style_sensor_value(lv_obj_t *obj);
void remove_style_sensor_value(lv_obj_t *obj);

// Style: sensor_value_cover
lv_style_t *get_style_sensor_value_cover_MAIN_DEFAULT();
void add_style_sensor_value_cover(lv_obj_t *obj);
void remove_style_sensor_value_cover(lv_obj_t *obj);



#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_STYLES_H*/