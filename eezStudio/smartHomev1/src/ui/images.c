#include "images.h"

const ext_img_desc_t images[10] = {
    { "cold", &img_cold },
    { "hot", &img_hot },
    { "humidityImage", &img_humidity_image },
    { "airQualityImage", &img_air_quality_image },
    { "smartHomeImage", &img_smart_home_image },
    { "bulb small", &img_bulb_small },
    { "wifiIcon", &img_wifi_icon },
    { "aiIcon", &img_ai_icon },
    { "sun_Icon", &img_sun_icon },
    { "fanIcon", &img_fan_icon },
};
