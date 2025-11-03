#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *spec5_home_container;
    lv_obj_t *active_nodes_label;
    lv_obj_t *group_message_label;
    lv_obj_t *received_message_label;
    lv_obj_t *sent_message_label;
    lv_obj_t *terminal_label;
    lv_obj_t *header_container;
    lv_obj_t *title_header_label;
    lv_obj_t *info_header_label;
    lv_obj_t *terminal_container;
    lv_obj_t *terminal_back_btn;
    lv_obj_t *terminal_text_area;
    lv_obj_t *left_icon_bar;
    lv_obj_t *spec5_icon_btn;
    lv_obj_t *nodes_icon_btn;
    lv_obj_t *recieved_messages_icon_btn;
    lv_obj_t *sent_messages_icon_btn;
    lv_obj_t *group_messages_icon_btn;
    lv_obj_t *terminal_icon_btn;
    lv_obj_t *input_text_container;
    lv_obj_t *send_input_text_btn;
    lv_obj_t *obj0;
    lv_obj_t *input_text_area;
    lv_obj_t *label_list_container;
    lv_obj_t *label_list;
    lv_obj_t *label1;
    lv_obj_t *label2;
    lv_obj_t *label3;
    lv_obj_t *label4;
    lv_obj_t *label5;
    lv_obj_t *label6;
    lv_obj_t *label7;
    lv_obj_t *label8;
    lv_obj_t *label9;
    lv_obj_t *label10;
    lv_obj_t *text_container;
    lv_obj_t *back_from_text_btn;
    lv_obj_t *obj1;
    lv_obj_t *msg_text_area;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
};

void create_screen_main();
void tick_screen_main();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/