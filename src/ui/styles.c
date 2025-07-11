#include "styles.h"
#include "images.h"
#include "fonts.h"

#include "ui.h"
#include "screens.h"

//
// Style: sensor_name
//

void init_style_sensor_name_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_color(style, lv_color_hex(0xff3205db));
    lv_style_set_text_font(style, &lv_font_montserrat_10);
};

lv_style_t *get_style_sensor_name_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_sensor_name_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_sensor_name(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_sensor_name_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_sensor_name(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_sensor_name_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: sensor_value_cover
//

void init_style_sensor_value_cover_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_color(style, lv_color_hex(0xff000000));
    lv_style_set_bg_color(style, lv_color_hex(0xff6fde71));
    lv_style_set_bg_opa(style, 255);
    lv_style_set_border_color(style, lv_color_hex(0xff1113c7));
    lv_style_set_border_width(style, 1);
    lv_style_set_radius(style, 50);
    lv_style_set_min_height(style, 60);
    lv_style_set_max_width(style, 60);
    lv_style_set_min_width(style, 60);
    lv_style_set_max_height(style, 60);
    lv_style_set_text_align(style, LV_TEXT_ALIGN_CENTER);
};

lv_style_t *get_style_sensor_value_cover_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_sensor_value_cover_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_sensor_value_cover(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_sensor_value_cover_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_sensor_value_cover(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_sensor_value_cover_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: critical_name
//

void init_style_critical_name_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_color(style, lv_color_hex(0xff3205db));
    lv_style_set_text_font(style, &lv_font_montserrat_12);
};

lv_style_t *get_style_critical_name_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_critical_name_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_critical_name(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_critical_name_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_critical_name(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_critical_name_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: critical_input
//

void init_style_critical_input_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_color(style, lv_color_hex(0xffff0000));
    lv_style_set_text_font(style, &lv_font_montserrat_12);
};

lv_style_t *get_style_critical_input_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_critical_input_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_critical_input(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_critical_input_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_critical_input(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_critical_input_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Keypad_button
//

void add_style_keypad_button(lv_obj_t *obj) {
    (void)obj;
};

void remove_style_keypad_button(lv_obj_t *obj) {
    (void)obj;
};

//
// Style: sensor_value
//

void init_style_sensor_value_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_min_width(style, 50);
    lv_style_set_min_height(style, 16);
    lv_style_set_max_height(style, 16);
    lv_style_set_max_width(style, 50);
    lv_style_set_text_color(style, lv_color_hex(0xff000000));
    lv_style_set_text_align(style, LV_TEXT_ALIGN_CENTER);
};

lv_style_t *get_style_sensor_value_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_sensor_value_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_sensor_value(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_sensor_value_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_sensor_value(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_sensor_value_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_sensor_name,
        add_style_sensor_value_cover,
        add_style_critical_name,
        add_style_critical_input,
        add_style_keypad_button,
        add_style_sensor_value,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_sensor_name,
        remove_style_sensor_value_cover,
        remove_style_critical_name,
        remove_style_critical_input,
        remove_style_keypad_button,
        remove_style_sensor_value,
    };
    remove_style_funcs[styleIndex](obj);
}

