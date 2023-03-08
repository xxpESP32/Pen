#ifndef __LVGL_PORT_H
#define __LVGL_PORT_H

#ifdef __cplusplus
extern "C" {
#endif
#include "lvgl/lvgl.h"
#include "LVGL_Main.h"
	
#define ADDR  (1024*1024*120) //写入单词位置的宏定义
		extern uint8_t CallBack[10]; 
		extern uint32_t Eglish_Flag;
		extern int INT_OUT_ADC;
		extern char float_Buff[10];
		extern uint8_t word_num;
		extern uint8_t word_b[10];
		
		extern lv_obj_t* Power_Slider;
	  void LV_English_Display_Bg(lv_obj_t* En);
    void LV_Eglish_Display_btn(lv_obj_t* Eg);
    void LV_Eglish_Display_label(lv_obj_t* Eg);
		void LV_PORT_1_Back_btn(lv_obj_t* one);
#ifdef __cplusplus
}
#endif


#endif
