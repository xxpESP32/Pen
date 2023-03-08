#ifndef __LVGL_PORT_3_H
#define __LVGL_PORT_3_H
#ifdef __cplusplus
extern "C" {
#endif
#include "lvgl/lvgl.h"
#include "LVGL_Main.h"

struct Dinosaur_FLAG { //–°ø÷¡˙
    lv_coord_t end_y;
    lv_coord_t obs_y;
    lv_coord_t Don_FLAG;
    lv_coord_t Don_score;

};
extern struct Dinosaur_FLAG Din;

struct Cactus_FLAG{//œ…»À’∆
	int8_t OBS;
	uint32_t Don_rand;
	uint8_t OBS_Ch;
	
};
extern struct Cactus_FLAG Cas;

struct Cloud_FLAG{
	int32_t cloud_value; //‘∆∂‰
	int32_t cloud_init;
};
extern struct Cloud_FLAG Clu;

extern lv_timer_t* timer;
extern lv_timer_t* timer1;
extern lv_timer_t* timer_2;

    void LV_Games_Display_Din(lv_obj_t* game);
    void LV_Games_Display_btn(lv_obj_t* game);
    void LV_Game_Display_Road_Obs(lv_obj_t* game);
    void my_timer_road(lv_timer_t* timer);
		void LV_Get_score(lv_obj_t* game);
		void LV_Game_Play_Once(lv_obj_t* game);
		void LV_Game_Display_Cloud(lv_obj_t* game);	
		void LV_PORT_3_Back_btn(lv_obj_t* one);
#ifdef __cplusplus
} /*extern "C"*/
#endif


#endif
