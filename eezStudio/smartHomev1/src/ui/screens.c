#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;
uint32_t active_theme_index = 0;

static void event_handler_cb_main_temperature_arc(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_arc_get_value(ta);
            set_var_temperture_value(value);
        }
    }
}

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // headContainer
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.head_container = obj;
            lv_obj_set_pos(obj, 0, 3);
            lv_obj_set_size(obj, 320, 33);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    lv_obj_set_pos(obj, 6, -1);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_image_set_src(obj, &img_smart_home_image);
                    lv_image_set_pivot(obj, 0, 0);
                    lv_image_set_scale(obj, 70);
                    lv_image_set_inner_align(obj, LV_IMAGE_ALIGN_DEFAULT);
                }
                {
                    // page_1_heading
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.page_1_heading = obj;
                    lv_obj_set_pos(obj, 40, 3);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "SMART HOME");
                }
                {
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.obj0 = obj;
                    lv_obj_set_pos(obj, 281, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_image_set_src(obj, &img_wifi_icon);
                    lv_image_set_pivot(obj, 0, 0);
                    lv_image_set_scale(obj, 140);
                    lv_image_set_inner_align(obj, LV_IMAGE_ALIGN_DEFAULT);
                    lv_obj_set_style_image_recolor(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_image_recolor_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    lv_obj_set_pos(obj, 240, -2);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_image_set_src(obj, &img_ai_icon);
                    lv_image_set_pivot(obj, 0, 0);
                    lv_image_set_scale(obj, 170);
                    lv_image_set_inner_align(obj, LV_IMAGE_ALIGN_DEFAULT);
                }
            }
        }
        {
            // TemperatureContainer
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.temperature_container = obj;
            lv_obj_set_pos(obj, 185, 40);
            lv_obj_set_size(obj, 135, 84);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.obj1 = obj;
                    lv_obj_set_pos(obj, -16, -14);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_image_set_src(obj, &img_cold);
                    lv_image_set_scale(obj, 100);
                    lv_obj_set_style_image_recolor(obj, lv_color_hex(0xff00a4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_image_recolor_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // termperature_value
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.termperature_value = obj;
                    lv_obj_set_pos(obj, 34, 36);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // temperature_Arc
                    lv_obj_t *obj = lv_arc_create(parent_obj);
                    objects.temperature_arc = obj;
                    lv_obj_set_pos(obj, 4, 7);
                    lv_obj_set_size(obj, 127, 110);
                    lv_arc_set_range(obj, 0, 50);
                    lv_arc_set_bg_start_angle(obj, 10);
                    lv_arc_set_bg_end_angle(obj, 180);
                    lv_arc_set_mode(obj, LV_ARC_MODE_SYMMETRICAL);
                    lv_arc_set_rotation(obj, 175);
                    lv_obj_add_event_cb(obj, event_handler_cb_main_temperature_arc, LV_EVENT_ALL, 0);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                    lv_obj_set_style_arc_color(obj, lv_color_hex(0xff828282), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_color(obj, lv_color_hex(0xffffffff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    // termperature_value_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.termperature_value_1 = obj;
                    lv_obj_set_pos(obj, 79, 40);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "C");
                }
                {
                    // termperature_value_2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.termperature_value_2 = obj;
                    lv_obj_set_pos(obj, 71, 21);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "o");
                }
                {
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.obj2 = obj;
                    lv_obj_set_pos(obj, 68, -35);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_image_set_src(obj, &img_hot);
                    lv_image_set_scale(obj, 70);
                    lv_obj_set_style_image_recolor(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_image_recolor_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // TimeContainer_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.time_container_1 = obj;
            lv_obj_set_pos(obj, 8, 39);
            lv_obj_set_size(obj, 156, 77);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // time_hour_text_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.time_hour_text_1 = obj;
                    lv_obj_set_pos(obj, 21, 7);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_38, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // month_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.month_1 = obj;
                    lv_obj_set_pos(obj, 14, 47);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // time_minute_text_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.time_minute_text_1 = obj;
                    lv_obj_set_pos(obj, 88, 7);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_38, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // centreDot_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.centre_dot_1 = obj;
                    lv_obj_set_pos(obj, 72, 6);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_38, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, ":");
                }
                {
                    // date_2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.date_2 = obj;
                    lv_obj_set_pos(obj, 67, 47);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // date_3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.date_3 = obj;
                    lv_obj_set_pos(obj, 100, 47);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // sunlightLabel
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.sunlight_label = obj;
            lv_obj_set_pos(obj, 9, 191);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_sun_icon);
            lv_image_set_scale(obj, 160);
            lv_image_set_inner_align(obj, LV_IMAGE_ALIGN_DEFAULT);
        }
        {
            // AirQualityContainer
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.air_quality_container = obj;
            lv_obj_set_pos(obj, 8, 124);
            lv_obj_set_size(obj, 149, 108);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // humidityLabel
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.humidity_label = obj;
                    lv_obj_set_pos(obj, 4, 2);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_image_set_src(obj, &img_humidity_image);
                    lv_image_set_scale(obj, 150);
                    lv_obj_set_style_image_recolor_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_image_recolor(obj, lv_color_hex(0xff029bf0), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // airQualityStatusText
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.air_quality_status_text = obj;
                    lv_obj_set_pos(obj, 66, 44);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // humidityPercentage
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.humidity_percentage = obj;
                    lv_obj_set_pos(obj, 103, 13);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "%");
                }
                {
                    // airQualityLabel
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.air_quality_label = obj;
                    lv_obj_set_pos(obj, 0, 36);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_image_set_src(obj, &img_air_quality_image);
                    lv_image_set_scale(obj, 130);
                    lv_obj_set_style_image_recolor_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_image_recolor(obj, lv_color_hex(0xff029bf0), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // airQualityNumberText
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.air_quality_number_text = obj;
                    lv_obj_set_pos(obj, 82, 65);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffb1b1b1), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // humidityText
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.humidity_text = obj;
                    lv_obj_set_pos(obj, 62, 13);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // lightText
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.light_text = obj;
                    lv_obj_set_pos(obj, 64, 80);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // lightPercentage
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.light_percentage = obj;
                    lv_obj_set_pos(obj, 103, 78);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "%");
                }
            }
        }
        {
            // Observations_text
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.observations_text = obj;
            lv_obj_set_pos(obj, 40, 115);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Observations");
        }
        {
            // switchControlContaniner
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.switch_control_contaniner = obj;
            lv_obj_set_pos(obj, 166, 124);
            lv_obj_set_size(obj, 149, 108);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // bulbLabel_
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.bulb_label_ = obj;
                    lv_obj_set_pos(obj, 20, 5);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_image_set_src(obj, &img_bulb_small);
                    lv_image_set_scale(obj, 250);
                    lv_image_set_inner_align(obj, LV_IMAGE_ALIGN_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_switch_create(parent_obj);
                    objects.obj3 = obj;
                    lv_obj_set_pos(obj, 90, 15);
                    lv_obj_set_size(obj, 50, 25);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffaaaaaa), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffce00), LV_PART_INDICATOR | LV_STATE_CHECKED);
                }
                {
                    // bulbLabel__1
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.bulb_label__1 = obj;
                    lv_obj_set_pos(obj, 22, 52);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_image_set_src(obj, &img_fan_icon);
                    lv_image_set_scale(obj, 250);
                    lv_image_set_inner_align(obj, LV_IMAGE_ALIGN_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_switch_create(parent_obj);
                    objects.obj4 = obj;
                    lv_obj_set_pos(obj, 90, 69);
                    lv_obj_set_size(obj, 50, 25);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffaaaaaa), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffce00), LV_PART_INDICATOR | LV_STATE_CHECKED);
                }
            }
        }
        {
            // control_text
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.control_text = obj;
            lv_obj_set_pos(obj, 217, 115);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Controls");
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
    {
        const char *new_val = get_var_temperture_value();
        const char *cur_val = lv_label_get_text(objects.termperature_value);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.termperature_value;
            lv_label_set_text(objects.termperature_value, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var_temperture_value();
        int32_t cur_val = lv_arc_get_value(objects.temperature_arc);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.temperature_arc;
            lv_arc_set_value(objects.temperature_arc, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_time_hour();
        const char *cur_val = lv_label_get_text(objects.time_hour_text_1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.time_hour_text_1;
            lv_label_set_text(objects.time_hour_text_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_month();
        const char *cur_val = lv_label_get_text(objects.month_1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.month_1;
            lv_label_set_text(objects.month_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_time_minute();
        const char *cur_val = lv_label_get_text(objects.time_minute_text_1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.time_minute_text_1;
            lv_label_set_text(objects.time_minute_text_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_month();
        const char *cur_val = lv_label_get_text(objects.date_2);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.date_2;
            lv_label_set_text(objects.date_2, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_dayof_week_var();
        const char *cur_val = lv_label_get_text(objects.date_3);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.date_3;
            lv_label_set_text(objects.date_3, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_air_quality_status();
        const char *cur_val = lv_label_get_text(objects.air_quality_status_text);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.air_quality_status_text;
            lv_label_set_text(objects.air_quality_status_text, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_air_quality_value();
        const char *cur_val = lv_label_get_text(objects.air_quality_number_text);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.air_quality_number_text;
            lv_label_set_text(objects.air_quality_number_text, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_humidity_value();
        const char *cur_val = lv_label_get_text(objects.humidity_text);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.humidity_text;
            lv_label_set_text(objects.humidity_text, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_ldr_value();
        const char *cur_val = lv_label_get_text(objects.light_text);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.light_text;
            lv_label_set_text(objects.light_text, new_val);
            tick_value_change_obj = NULL;
        }
    }
}



typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
}
