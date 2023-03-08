#ifndef __LVGL_PORT_5_H
#define __LVGL_PORT_5_H

#ifdef __cplusplus
extern "C" {
#endif
#include "lvgl/lvgl.h"
#include "LVGL_Main.h"

#define Language_Flag_Addr  (1024*1024*121)
#define Background_Flag_Addr (1024*1024*122)

struct Set_time{
	uint8_t Hs;
	uint8_t Ms;
	uint8_t Ss;
	uint16_t Ys;
	uint8_t MOs;
	uint8_t Ds;
	
};
extern struct Set_time SETS;
    
		extern uint8_t Language_buff[10];
		extern uint8_t Background_buff[10];
		extern int32_t Vol_Value;
     
    void LV_Set_Display_Menu(lv_obj_t* mu);

#ifdef __cplusplus
}
#endif


#endif // !__LVGL_PORT_H
