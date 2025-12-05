#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H
#include <stdio.h>  // required for snprintf used in tick_screen_main

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Implement these in your mk_4.ino (or a .cpp) to control the hardware relays.
void relay_light_set(bool on);
void relay_fan_set(bool on);


typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *head_container;
    lv_obj_t *page_1_heading;
    lv_obj_t *obj0;
    lv_obj_t *temperature_container;
    lv_obj_t *obj1;
    lv_obj_t *termperature_value;
    lv_obj_t *temperature_arc;
    lv_obj_t *termperature_value_1;
    lv_obj_t *termperature_value_2;
    lv_obj_t *obj2;
    lv_obj_t *time_container_1;
    lv_obj_t *time_hour_text_1;
    lv_obj_t *month_1;
    lv_obj_t *time_minute_text_1;
    lv_obj_t *centre_dot_1;
    lv_obj_t *date_2;
    lv_obj_t *date_3;
    lv_obj_t *sunlight_label;
    lv_obj_t *air_quality_container;
    lv_obj_t *humidity_label;
    lv_obj_t *air_quality_status_text;
    lv_obj_t *humidity_percentage;
    lv_obj_t *air_quality_label;
    lv_obj_t *air_quality_number_text;
    lv_obj_t *humidity_text;
    lv_obj_t *light_text;
    lv_obj_t *light_percentage;
    lv_obj_t *observations_text;
    lv_obj_t *switch_control_contaniner;
    lv_obj_t *bulb_label_;
    lv_obj_t *light_switch;
    lv_obj_t *bulb_label__1;
    lv_obj_t *fan_switch;
    lv_obj_t *control_text;
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