#ifndef __LVGL_Main_H
#define __LVGL_Main_H

#ifdef __cplusplus
extern "C" {
#endif
#include "lvgl/lvgl.h"

#define Word_Flag_Addr (1024*1024*129)

extern uint8_t obj_2_FLAG;
extern uint8_t obj_3_FLAG;
extern uint8_t obj_4_FLAG;

extern lv_obj_t* obj;
extern lv_obj_t* obj_1;
extern lv_obj_t* obj_2;
extern lv_obj_t* obj_3;
extern lv_obj_t* obj_4;
extern lv_obj_t* obj_5;
extern lv_obj_t* obj_6;
extern lv_obj_t* obj_7;

extern uint8_t Language_Flag; 
extern uint8_t Bg_Flag;
extern uint8_t Hour_Cp;
extern uint16_t Word_Flag;


void LV_Main_Code(void);

void LV_Menu_Init(void);




#ifdef __cplusplus
} /*extern "C"*/
#endif




#endif // __LVGL_Main_H

