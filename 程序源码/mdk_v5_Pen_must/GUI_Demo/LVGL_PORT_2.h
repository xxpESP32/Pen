#ifndef __LVGL_PORT_2_H
#define __LVGL_PORT_2_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
#include "LVGL_Main.h"
#include "LVGL_PORT_1.h"
#include "FreeRTOS.h"
#include "task.h"
#include "Timers.h"
#include "at32f403a_407_board.h"
#include "at32f403a_407_clock.h"


extern lv_obj_t* roller_1;
extern lv_obj_t* roller_2;
extern lv_obj_t* roller_3;
extern lv_obj_t* roller_label;
struct Time_Display {
    uint16_t H;
    uint16_t M;
    uint16_t S;
	
		uint16_t Cp_h;
		uint16_t Cp_m;
		uint16_t Cp_s;
	
		uint8_t Timer_Begin_Flag;
		uint8_t Timer_Start_Stop_Flag;
};
extern struct Time_Display time;

    void LV_Timer_Display_roller(lv_obj_t* re);
    void LV_Timer_Display_roller_1(lv_obj_t* re);
    void LV_Timer_Display_roller_2(lv_obj_t* re);
    void LV_Timer_Display_label(lv_obj_t* re);
    void LV_Timer_Display_btn(lv_obj_t* re);
    void LV_Timer_Display_Cyc_Value(lv_obj_t* roller_name1, lv_obj_t* roller_name2, lv_obj_t* roller_name3);
		void LV_Timer_Display_time(lv_obj_t* lv);
		
#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif // __LVGL_PORT_2_H
