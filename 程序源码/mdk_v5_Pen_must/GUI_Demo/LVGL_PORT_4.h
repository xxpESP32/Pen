#ifndef __LVGL_PORT_4_H
#define __LVGL_PORT_4_H

#ifdef __cplusplus
extern "C" {
#endif
#include "lvgl/lvgl.h"
#include "LVGL_Main.h"

extern lv_obj_t* rgb_slider_1;

struct RGB_FLAG {  //RGB的标志位

    uint8_t RGB_Btn_Flag;
    uint8_t RGB_Exti_Flag;
    uint8_t RGB_CHO_FLAG;
	  uint8_t RGB_Flick_FLAG;
};
extern struct RGB_FLAG rgb;

struct RGB_Value { //RBG颜色
    uint8_t Red;
    uint8_t Green;
    uint8_t Blue;
};
extern struct RGB_Value rgbv;

    void LV_RGB_Display_btn(lv_obj_t* colors);
    void LV_RGB_Display_Cor(lv_obj_t* colors);
    void LV_RGB_Display_Red_Slider(lv_obj_t* colors);
		void LV_PORT_4_Back_btn(lv_obj_t* one);

#ifdef __cplusplus
}
#endif


#endif
