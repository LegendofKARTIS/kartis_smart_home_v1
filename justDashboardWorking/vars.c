// vars.c -- implementations for EEZ global variables (C)
#include <stdint.h>
#include <string.h>
#include "vars.h"

// Time / date / enums
static int32_t time_hour = 0;
static char month_buf[32] = "";
static int32_t time_minute = 0;
static int32_t date_val = 0;
static DayOfWeek dow = DayOfWeek_SUN;

// Sensors & UI variables
static int32_t temperture_value = 0;
static int32_t humidity_value = 0;
static int32_t air_quality_value = 0;
static char air_quality_status[100] = {0};
static int32_t ldr_value = 0;

// ---- getters / setters ----

int32_t get_var_time_hour() { return time_hour; }
void set_var_time_hour(int32_t value) { time_hour = value; }

const char *get_var_month() { return month_buf; }
void set_var_month(const char *value) {
    if (value) {
        strncpy(month_buf, value, sizeof(month_buf)-1);
        month_buf[sizeof(month_buf)-1] = '\0';
    } else {
        month_buf[0] = '\0';
    }
}

int32_t get_var_time_minute() { return time_minute; }
void set_var_time_minute(int32_t value) { time_minute = value; }

int32_t get_var_date() { return date_val; }
void set_var_date(int32_t value) { date_val = value; }

DayOfWeek get_var_dayof_week_var() { return dow; }
void set_var_dayof_week_var(DayOfWeek value) { dow = value; }

int32_t get_var_temperture_value() { return temperture_value; }
void set_var_temperture_value(int32_t value) { temperture_value = value; }

int32_t get_var_humidity_value() { return humidity_value; }
void set_var_humidity_value(int32_t value) { humidity_value = value; }

int32_t get_var_air_quality_value() { return air_quality_value; }
void set_var_air_quality_value(int32_t value) { air_quality_value = value; }

const char *get_var_air_quality_status() { return air_quality_status; }
void set_var_air_quality_status(const char *value) {
    if (value) {
        strncpy(air_quality_status, value, sizeof(air_quality_status)-1);
        air_quality_status[sizeof(air_quality_status)-1] = '\0';
    } else {
        air_quality_status[0] = '\0';
    }
}

int32_t get_var_ldr_value() { return ldr_value; }
void set_var_ldr_value(int32_t value) { ldr_value = value; }
