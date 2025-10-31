#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_active_nodes;
extern const lv_img_dsc_t img_active_nodes_active;
extern const lv_img_dsc_t img_group_message;
extern const lv_img_dsc_t img_group_message_active;
extern const lv_img_dsc_t img_received_messages;
extern const lv_img_dsc_t img_received_messages_active;
extern const lv_img_dsc_t img_sent_messages;
extern const lv_img_dsc_t img_sent_messages_active;
extern const lv_img_dsc_t img_spec5;
extern const lv_img_dsc_t img_spec5_active;
extern const lv_img_dsc_t img_terminal;
extern const lv_img_dsc_t img_terminal_active;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[12];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/