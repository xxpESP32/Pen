#ifndef __LVGL_PORT_6_H
#define __LVGL_PORT_6_H

#ifdef __cplusplus
extern "C" {
#endif
#include "lvgl/lvgl.h"
#include "LVGL_Main.h"
#include "at32f403a_407_board.h"
#include "at32f403a_407_clock.h"

		extern u8 Own_buff[1024];

		extern u8 important_word_size;
		extern u8* important_word[30];
    void LV_PORT_6_Back_btn(lv_obj_t* one);
		void LV_PORT_6_Display_Own_Wrod(lv_obj_t* one);
#ifdef __cplusplus
}
#endif


#endif // !__LVGL_PORT_H
