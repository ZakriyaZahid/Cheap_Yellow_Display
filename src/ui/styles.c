#include "styles.h"
#include "images.h"
#include "fonts.h"

#include "ui.h"
#include "screens.h"

//
// Style: left_menu_button_style
//

void init_style_left_menu_button_style_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xff46494b));
    lv_style_set_shadow_color(style, lv_color_hex(0xff2d3237));
};

lv_style_t *get_style_left_menu_button_style_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_left_menu_button_style_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_left_menu_button_style(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_left_menu_button_style_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_left_menu_button_style(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_left_menu_button_style_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: left_menu_label_style
//

void init_style_left_menu_label_style_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_color(style, lv_color_hex(0xffffffff));
    lv_style_set_text_font(style, &lv_font_montserrat_8);
};

lv_style_t *get_style_left_menu_label_style_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_left_menu_label_style_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_left_menu_label_style(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_left_menu_label_style_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_left_menu_label_style(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_left_menu_label_style_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: list_labels
//

void init_style_list_labels_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_margin_bottom(style, 3);
    lv_style_set_margin_top(style, 3);
};

lv_style_t *get_style_list_labels_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_list_labels_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_list_labels(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_list_labels_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_list_labels(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_list_labels_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: list_buttons
//

void init_style_list_buttons_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_margin_top(style, 3);
    lv_style_set_margin_bottom(style, 3);
};

lv_style_t *get_style_list_buttons_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_list_buttons_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_list_buttons(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_list_buttons_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_list_buttons(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_list_buttons_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: bottom_right_container
//

void add_style_bottom_right_container(lv_obj_t *obj) {
    (void)obj;
};

void remove_style_bottom_right_container(lv_obj_t *obj) {
    (void)obj;
};

//
// Style: spec5_home_page_labels
//

void init_style_spec5_home_page_labels_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_border_color(style, lv_color_hex(0xffffffff));
    lv_style_set_border_width(style, 2);
    lv_style_set_text_color(style, lv_color_hex(0xffffffff));
};

lv_style_t *get_style_spec5_home_page_labels_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_spec5_home_page_labels_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_spec5_home_page_labels(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_spec5_home_page_labels_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_spec5_home_page_labels(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_spec5_home_page_labels_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_left_menu_button_style,
        add_style_left_menu_label_style,
        add_style_list_labels,
        add_style_list_buttons,
        add_style_bottom_right_container,
        add_style_spec5_home_page_labels,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_left_menu_button_style,
        remove_style_left_menu_label_style,
        remove_style_list_labels,
        remove_style_list_buttons,
        remove_style_bottom_right_container,
        remove_style_spec5_home_page_labels,
    };
    remove_style_funcs[styleIndex](obj);
}

