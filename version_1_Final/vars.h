#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// enum declarations

typedef enum {
    DayOfWeek_SAT = 6,
    DayOfWeek_FRI = 5,
    DayOfWeek_THU = 4,
    DayOfWeek_WED = 3,
    DayOfWeek_TUE = 2,
    DayOfWeek_MON = 1,
    DayOfWeek_SUN = 0
} DayOfWeek;

// Flow global variables

enum FlowGlobalVariables {
    FLOW_GLOBAL_VARIABLE_TIME_HOUR = 0,
    FLOW_GLOBAL_VARIABLE_MONTH = 1,
    FLOW_GLOBAL_VARIABLE_TIME_MINUTE = 2,
    FLOW_GLOBAL_VARIABLE_DATE = 3,
    FLOW_GLOBAL_VARIABLE_DAYOF_WEEK_VAR = 4,
    FLOW_GLOBAL_VARIABLE_TEMPERTURE_VALUE = 5,
    FLOW_GLOBAL_VARIABLE_HUMIDITY_VALUE = 6,
    FLOW_GLOBAL_VARIABLE_AIR_QUALITY_VALUE = 7,
    FLOW_GLOBAL_VARIABLE_AIR_QUALITY_STATUS = 8,
    FLOW_GLOBAL_VARIABLE_LDR_VALUE = 9
};

// Native global variables

extern int32_t get_var_time_hour();
extern void set_var_time_hour(int32_t value);
extern const char *get_var_month();
extern void set_var_month(const char *value);
extern int32_t get_var_time_minute();
extern void set_var_time_minute(int32_t value);
extern int32_t get_var_date();
extern void set_var_date(int32_t value);
extern DayOfWeek get_var_dayof_week_var();
extern void set_var_dayof_week_var(DayOfWeek value);
extern int32_t get_var_temperture_value();
extern void set_var_temperture_value(int32_t value);
extern int32_t get_var_humidity_value();
extern void set_var_humidity_value(int32_t value);
extern int32_t get_var_air_quality_value();
extern void set_var_air_quality_value(int32_t value);
extern const char *get_var_air_quality_status();
extern void set_var_air_quality_status(const char *value);
extern int32_t get_var_ldr_value();
extern void set_var_ldr_value(int32_t value);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/