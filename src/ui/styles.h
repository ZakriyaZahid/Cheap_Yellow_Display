#ifndef EEZ_LVGL_UI_STYLES_H
#define EEZ_LVGL_UI_STYLES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Style: left_menu_button_style
lv_style_t *get_style_left_menu_button_style_MAIN_DEFAULT();
void add_style_left_menu_button_style(lv_obj_t *obj);
void remove_style_left_menu_button_style(lv_obj_t *obj);

// Style: left_menu_label_style
lv_style_t *get_style_left_menu_label_style_MAIN_DEFAULT();
void add_style_left_menu_label_style(lv_obj_t *obj);
void remove_style_left_menu_label_style(lv_obj_t *obj);

// Style: list_labels
lv_style_t *get_style_list_labels_MAIN_DEFAULT();
void add_style_list_labels(lv_obj_t *obj);
void remove_style_list_labels(lv_obj_t *obj);

// Style: list_buttons
lv_style_t *get_style_list_buttons_MAIN_DEFAULT();
void add_style_list_buttons(lv_obj_t *obj);
void remove_style_list_buttons(lv_obj_t *obj);

// Style: bottom_right_container
void add_style_bottom_right_container(lv_obj_t *obj);
void remove_style_bottom_right_container(lv_obj_t *obj);

// Style: spec5_home_page_labels
lv_style_t *get_style_spec5_home_page_labels_MAIN_DEFAULT();
void add_style_spec5_home_page_labels(lv_obj_t *obj);
void remove_style_spec5_home_page_labels(lv_obj_t *obj);



#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_STYLES_H*/