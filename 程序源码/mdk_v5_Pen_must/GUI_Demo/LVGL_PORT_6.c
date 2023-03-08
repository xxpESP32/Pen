#include "LVGL_PORT_6.h"
#include "Timer.h"

u8 Own_buff[1024];

u8 important_word_size; 
u8* important_word[30];
int16_t pox_y[30]={0,85,170,255,340,425,510-5,595-5,680-5,765-5,
									 850-10,935-12,1020-13,1105-14,1190-15,1275-16,1360-17,1445-18,1530-19,1615-20,
	                 1700-20,1785-21,1870-22,1955-23,2040-24,2125-25,2210-26,2295-27,2380-28,2465-29
};


lv_obj_t* PORT_6_Back_btn;
lv_obj_t* btn_text;
LV_FONT_DECLARE(HZ);
int creat_value;
//退出按键
static void PORT_6_Back_btn_Handler(lv_event_t* param) {

    lv_event_code_t vscode = lv_event_get_code(param);
    lv_obj_t* mune = lv_event_get_target(param);

    if (vscode == LV_EVENT_CLICKED) {
        if (mune == PORT_6_Back_btn | mune == btn_text) {
            lv_obj_del(obj_7);

        }
        LV_Menu_Init();

    }
}

void LV_PORT_6_Back_btn(lv_obj_t* one) {
    PORT_6_Back_btn = lv_btn_create(one);
    lv_obj_set_size(PORT_6_Back_btn, 36, 12);
    lv_obj_set_style_radius(PORT_6_Back_btn, 5, 0);
    lv_obj_align(PORT_6_Back_btn, LV_ALIGN_TOP_LEFT, -13, -13);
    lv_obj_set_style_bg_color(PORT_6_Back_btn, lv_color_hex(0x808A87), LV_PART_MAIN);
    lv_obj_t* Back_label = lv_label_create(PORT_6_Back_btn);
    lv_label_set_recolor(Back_label, true);
    lv_label_set_text(Back_label, "#000000 <#");
    lv_obj_center(Back_label);

    lv_obj_add_event_cb(PORT_6_Back_btn, PORT_6_Back_btn_Handler, LV_EVENT_ALL, NULL);

}

static void PORT_6_Back_btn_text_Handler(lv_event_t* param) {

    lv_event_code_t vscode = lv_event_get_code(param);
    lv_obj_t* mune = lv_event_get_target(param);

    if (vscode == LV_EVENT_CLICKED) { 
            lv_obj_del(obj_7);

        
        LV_Menu_Init();

    }
}
//显示单词
void LV_PORT_6_Display_Own_Wrod(lv_obj_t* one) {
		for(creat_value=0;creat_value<30;creat_value++){
			btn_text=lv_btn_create(one);
			lv_obj_set_style_bg_color(btn_text,lv_color_hex(0xff00ff),0);
			//lv_obj_set_style_opa(btn_text,0,0);
			lv_obj_set_size(btn_text,1,60);
			lv_obj_set_style_radius(btn_text,0,0);
		  lv_obj_set_pos(btn_text,130,pox_y[creat_value]);
			lv_obj_add_event_cb(btn_text, PORT_6_Back_btn_text_Handler, LV_EVENT_ALL, NULL);
	 	 			
		}
    lv_obj_t* label_Own_Word = lv_label_create(one);
    
	  lv_obj_set_style_text_font(label_Own_Word,&HZ,0);

	  lv_obj_align(label_Own_Word,LV_ALIGN_TOP_LEFT,-10,0);
    
	 //printf("%s\r\n",string_buff);

    lv_label_set_text(label_Own_Word,DMA_Buff_1);
			
   
}