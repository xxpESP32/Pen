#include "LVGL_PORT_2.h"
#include "LVGL_Main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "Timers.h"
#include "at32f403a_407_board.h"
#include "at32f403a_407_clock.h"

lv_obj_t* roller_1;
lv_obj_t* roller_2;
lv_obj_t* roller_3;
lv_obj_t* roller_label;
lv_obj_t* roller_btn;

struct Time_Display time;

static void Back_main(lv_event_t* e);
static void event_handler_2(lv_event_t* param);
static void event_handler(lv_event_t* param);
static void event_handler_1(lv_event_t* param);


static void event_handler(lv_event_t* param) {
  
    lv_event_code_t code = lv_event_get_code(param);
    lv_obj_t* roller_cp = lv_event_get_target(param);
    if (code== LV_EVENT_VALUE_CHANGED) {
        time.H=lv_roller_get_selected(roller_cp);
        time.Cp_h=time.H+1;
        
				

    }


}

void LV_Timer_Display_roller(lv_obj_t* re)
{

    roller_1 = lv_roller_create(re);
    lv_obj_set_height(roller_1,50);
		lv_obj_set_width(roller_1,40);
	  lv_obj_set_style_bg_color(roller_1,lv_color_hex(0x808a87),0);
	  lv_obj_set_style_bg_color(roller_1,lv_color_hex(0x00CDCD),LV_PART_SELECTED);
    lv_roller_set_options(roller_1,
        "1\n"
        "2\n"
        "3\n"
        "4\n"
        "5\n"
        "6\n"
        "7\n"
        "8\n"
        "9\n"
        "10\n"
        "11\n"
        "12\n"
        "13\n"
        "14\n"
        "15\n"
        "16\n"
        "17\n"
        "18\n"
        "19\n"
        "20\n"
        "21\n"
        "22\n"
        "23\n"
        "24",
        LV_ROLLER_MODE_NORMAL);
				lv_roller_set_selected(roller_1,time.H,LV_ANIM_ON);

    lv_obj_align(roller_1,LV_ALIGN_LEFT_MID,-10,-10);
    lv_obj_add_event_cb(roller_1, event_handler, LV_EVENT_ALL, NULL);
		
	

}
static void event_handler_1(lv_event_t* param) {
    
    lv_event_code_t code_1 = lv_event_get_code(param);
    lv_obj_t* roller_cp_1 = lv_event_get_target(param);
    if (code_1 == LV_EVENT_VALUE_CHANGED) {
        time.M = lv_roller_get_selected(roller_cp_1);
       // lv_roller_get_selected_str(roller_cp, buf_1, sizeof(buf_1));
        time.Cp_m =time.M+1;


    }


}
void LV_Timer_Display_roller_1(lv_obj_t* re)
{

    roller_2 = lv_roller_create(re);
    lv_obj_set_height(roller_2, 50);
		lv_obj_set_width(roller_2,40);
	lv_obj_set_style_bg_color(roller_2,lv_color_hex(0x808a87),0);
	lv_obj_set_style_bg_color(roller_2,lv_color_hex(0x00CDCD),LV_PART_SELECTED);
    lv_roller_set_options(roller_2,
        "1\n"
        "2\n"
        "3\n"
        "4\n"
        "5\n"
        "6\n"
        "7\n"
        "8\n"
        "9\n"
        "10\n"
        "11\n"
        "12\n"
        "13\n"
        "14\n"
        "15\n"
        "16\n"
        "17\n"
        "18\n"
        "19\n"
        "20\n"
        "21\n"
        "22\n"
        "23\n"
        "24\n"
        "25\n"
        "26\n"
        "27\n"
        "28\n"
        "29\n"
        "30\n"
        "31\n"
        "32\n"
        "33\n"
        "34\n"
        "35\n"
        "36\n"
        "37\n"
        "38\n"
        "39\n"
        "40\n"
        "41\n"
        "42\n"
        "43\n"
        "44\n"
        "45\n"
        "46\n"
        "47\n"
        "48\n"
        "49\n"
        "50\n"
        "51\n"
        "52\n"
        "53\n"
        "54\n"
        "55\n"
        "56\n"
        "57\n"
        "58\n"
        "59\n"
        "60",
    LV_ROLLER_MODE_NORMAL);
		lv_roller_set_selected(roller_2,time.M,LV_ANIM_ON);
   // time.M = lv_roller_get_selected(roller_2);
    //lv_roller_get_selected_str(roller_2, buf_1, sizeof(buf_1));
    lv_obj_align(roller_2, LV_ALIGN_CENTER, 0, -10);
    lv_obj_add_event_cb(roller_2, event_handler_1, LV_EVENT_ALL, NULL);
}
static void event_handler_2(lv_event_t* param) {

   
    lv_event_code_t code_2 = lv_event_get_code(param);
    lv_obj_t* roller_cp_2 = lv_event_get_target(param);
    if (code_2 == LV_EVENT_VALUE_CHANGED) {
        time.S = lv_roller_get_selected(roller_cp_2);
       // lv_roller_get_selected_str(roller_cp, buf_2, sizeof(buf_2));
        time.Cp_s=time.S+1;
				

    }


}
void LV_Timer_Display_roller_2(lv_obj_t* re)
{
    
    roller_3 = lv_roller_create(re);
    lv_obj_set_height(roller_3, 50);
	  lv_obj_set_width(roller_3,40);
	  lv_obj_set_style_bg_color(roller_3,lv_color_hex(0x808a87),0);
	  lv_obj_set_style_bg_color(roller_3,lv_color_hex(0x00CDCD),LV_PART_SELECTED);
    lv_roller_set_options(roller_3,
        "1\n"
        "2\n"
        "3\n"
        "4\n"
        "5\n"
        "6\n"
        "7\n"
        "8\n"
        "9\n"
        "10\n"
        "11\n"
        "12\n"
        "13\n"
        "14\n"
        "15\n"
        "16\n"
        "17\n"
        "18\n"
        "19\n"
        "20\n"
        "21\n"
        "22\n"
        "23\n"
        "24\n"
        "25\n"
        "26\n"
        "27\n"
        "28\n"
        "29\n"
        "30\n"
        "31\n"
        "32\n"
        "33\n"
        "34\n"
        "35\n"
        "36\n"
        "37\n"
        "38\n"
        "39\n"
        "40\n"
        "41\n"
        "42\n"
        "43\n"
        "44\n"
        "45\n"
        "46\n"
        "47\n"
        "48\n"
        "49\n"
        "50\n"
        "51\n"
        "52\n"
        "53\n"
        "54\n"
        "55\n"
        "56\n"
        "57\n"
        "58\n"
        "59\n"
        "60",
        LV_ROLLER_MODE_NORMAL);
				lv_roller_set_selected(roller_3,time.S,LV_ANIM_ON);
    //time.S = lv_roller_get_selected(roller_2);
   // lv_roller_get_selected_str(roller_3, buf_2, sizeof(buf_2));
    lv_obj_align(roller_3, LV_ALIGN_RIGHT_MID, 10, -10);
		
    lv_obj_add_event_cb(roller_3, event_handler_2, LV_EVENT_ALL, NULL);
}

void LV_Timer_Display_time(lv_obj_t* lv){
	lv_obj_t* Timer_btn=lv_btn_create(lv);
	lv_obj_t* Timer_btn_labels = lv_label_create(Timer_btn);
  lv_obj_align(Timer_btn,LV_ALIGN_TOP_MID,0,-10);
  lv_obj_set_size(Timer_btn, 155, 16);
  lv_obj_set_style_text_font(Timer_btn_labels,&lv_font_montserrat_14,0);
  lv_label_set_text(Timer_btn_labels, "<Set>");
  lv_obj_center(Timer_btn_labels);
	
}

void LV_Timer_Display_label(lv_obj_t* re) {
    if (obj_3_FLAG==1) {
        roller_label = lv_label_create(re);
        lv_obj_set_pos(roller_label, 0, 60);
        lv_obj_set_style_text_font(roller_label, &lv_font_montserrat_32, 0);
        lv_label_set_text_fmt(roller_label, "%d:%d:%d", time.H + 1, time.M + 1, time.S + 1);
    }
}
static void Back_main(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* roller_cp_3 = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED)
    {
        if (roller_cp_3== roller_btn) {
            lv_obj_del(obj_3);           
            obj_3_FLAG = 0;
            time.Timer_Start_Stop_Flag=1;
					  printf("H=%d\tM=%d\tS=%d\n",time.Cp_h,time.Cp_m,time.Cp_s);
        }
        LV_Menu_Init();
    }

}
void LV_Timer_Display_btn(lv_obj_t* re)
{
	
    roller_btn = lv_btn_create(re);
		lv_obj_clear_flag(roller_btn, LV_OBJ_FLAG_SCROLLABLE);//使对象不可滚动。
    lv_obj_t* btn_labels = lv_label_create(roller_btn);
    lv_obj_set_pos(roller_btn, 5, 45);
    lv_obj_set_size(roller_btn, 120, 20);
    lv_obj_set_style_text_font(btn_labels,&lv_font_montserrat_16,0);
    lv_label_set_text(btn_labels, "<Back>");
    lv_obj_center(btn_labels);
    lv_obj_add_event_cb(roller_btn, Back_main, LV_EVENT_ALL, NULL);
}

void LV_Timer_Display_Cyc_Value(lv_obj_t* roller_name1, lv_obj_t* roller_name2, lv_obj_t* roller_name3)
{


}
