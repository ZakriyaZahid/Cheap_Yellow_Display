#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C"
{
#endif

    extern void textarea_event_cb(lv_event_t *e);

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
    typedef struct _ext_img_desc_t
    {
        const char *name;
        const lv_img_dsc_t *img_dsc;
    } ext_img_desc_t;
#endif

    extern const ext_img_desc_t images[1];

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/