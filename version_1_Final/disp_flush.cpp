// disp_flush.cpp
#include <TFT_eSPI.h>
#include <lvgl.h>

extern TFT_eSPI tft;

void disp_flush(lv_display_t *display, const lv_area_t *area, unsigned char *data) {
    (void)display;

    lv_color_t *colors = (lv_color_t*)data;
    int w = area->x2 - area->x1 + 1;
    int h = area->y2 - area->y1 + 1;

    // push full rectangle — TFT_eSPI will swap bytes for us (setSwapBytes(true))
    tft.pushImage(area->x1, area->y1, w, h, (uint16_t*)colors);

    lv_display_flush_ready(display);
}
