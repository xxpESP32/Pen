#ifndef __LVGL_PORT_1_H
#define __LVGL_PORT_1_H

#ifdef __cplusplus
extern "C" {
#endif

#include "LVGL_Main.h"
#include "lvgl/lvgl.h"
#define RTC_True 1
    extern lv_obj_t* Time_hour;
    extern lv_obj_t* Time_month;
    extern lv_obj_t* data;
    extern lv_obj_t* Week;



    void RTC_Display_Time(uint8_t hour, uint8_t month, lv_obj_t* tim);
    void RTC_Display_Data(uint8_t year, uint8_t month, uint8_t day, lv_obj_t* na);
    void RTC_Display_Cyc_Data(uint16_t year, uint8_t month, uint8_t day);
    void RTC_Display_Week(uint16_t year, uint8_t month, uint8_t day, lv_obj_t* na);

    void RTC_Display_Course(lv_obj_t* na);
		void LV_PORT_2_Back_btn(lv_obj_t* one);
		void LV_Time_Display_BG(lv_obj_t* bgd);
#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif // __LVGL_PORT_1_H
