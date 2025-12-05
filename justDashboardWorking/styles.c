#include "styles.h"
#include "images.h"
#include "fonts.h"

#include "ui.h"
#include "screens.h"

//
// Style: Heading
//

void init_style_heading_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &ui_font_anton_14);
    lv_style_set_text_color(style, lv_color_hex(0xffffffff));
    lv_style_set_text_letter_space(style, 2);
};

lv_style_t *get_style_heading_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_heading_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_heading(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_heading_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_heading(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_heading_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_heading,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_heading,
    };
    remove_style_funcs[styleIndex](obj);
}

