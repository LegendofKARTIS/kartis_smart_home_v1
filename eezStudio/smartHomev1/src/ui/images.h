#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_cold;
extern const lv_img_dsc_t img_hot;
extern const lv_img_dsc_t img_humidity_image;
extern const lv_img_dsc_t img_air_quality_image;
extern const lv_img_dsc_t img_smart_home_image;
extern const lv_img_dsc_t img_bulb_small;
extern const lv_img_dsc_t img_wifi_icon;
extern const lv_img_dsc_t img_ai_icon;
extern const lv_img_dsc_t img_sun_icon;
extern const lv_img_dsc_t img_fan_icon;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[10];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/