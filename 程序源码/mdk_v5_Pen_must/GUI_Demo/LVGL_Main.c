#include "LVGL_Main.h"
#include "LVGL_PORT.h"
#include "LVGL_PORT_1.h"
#include "LVGL_PORT_2.h"
#include "LVGL_PORT_3.h"
#include "LVGL_PORT_4.h"
#include "LVGL_PORT_5.h"
#include "LVGL_PORT_6.h"

#include "lvgl/lvgl.h"
#include "lv_port_indev.h"
#include "w25q128.h"
#include "rtc.h"

uint8_t obj_2_FLAG = 0;
uint8_t obj_3_FLAG = 0;
uint8_t obj_4_FLAG = 0;
uint8_t del_Flag = 0;

lv_obj_t* obj;
lv_obj_t* obj_1;
lv_obj_t* obj_2;
lv_obj_t* obj_3;
lv_obj_t* obj_4;
lv_obj_t* obj_5;
lv_obj_t* obj_6;

lv_obj_t* Back_btn;
lv_obj_t* Back_btn_1;
lv_obj_t* Back_btn_2;
lv_obj_t* Back_btn_3;
lv_obj_t* Back_btn_4;
lv_obj_t* Back_btn_5;
lv_group_t* g;

lv_obj_t* btn;
lv_obj_t* btn1;
lv_obj_t* btn2;
lv_obj_t* btn3;
lv_obj_t* btn4;
lv_obj_t* btn5;

LV_IMG_DECLARE(LV_Eglish);
LV_IMG_DECLARE(RTCS);
LV_IMG_DECLARE(Games);
LV_IMG_DECLARE(Set);
LV_IMG_DECLARE(Timer);
LV_IMG_DECLARE(Song);

uint8_t Clear_Flag;
uint8_t Language_Flag;
uint8_t Bg_Flag;
uint16_t Word_Flag;

void Eglish_Disc_Function(void);
//菜单二 RTC时钟
void RTC_Time_Function(void);
//菜单三 定时提醒
void Timer_Function(void);
//菜单四 贪吃蛇游戏
void Games_Function(void);
//菜单五 曲谱
void Song_Function(void);
//设置
void Set_Function(void);

void LV_Menu_Init(void);
void Eglish_Main_Function(void);
void RTC_Timer_Main_Function(void);
void Timer_Main_Function(void);
void Games_Main_Function(void);
void Song_Main_Function(void);
void Set_Main_Function(void);

void LV_Main_Code(void);

#if 0
void Back_btn_Handler(lv_event_t* param);
void Back_Main(lv_obj_t* fai);
#endif 

void ALL_INPUT_Handler(lv_event_t* pamar);
void LV_KEY(void);
void LV_KEY_End(void);


LV_FONT_DECLARE(HZ);
uint8_t Key_main_FLAG=0;
uint8_t Key_once=0;
lv_obj_t* Key_Main_btn;
lv_obj_t* label_word;
uint8_t Word_buff[10];
uint8_t Hour_Cp;
uint8_t Power_buff[10];

//*****************************************************************************
// 
//                     更新时间2022.11.29   --大更新
// 
//****************************************************************************
lv_obj_t* btn6;
void add_word_Function(void);
void personal_Main_Function(void);
LV_IMG_DECLARE(own_Word);
lv_obj_t* obj_7;
//*****************************************************************************
// 
//                     更新时间2023.2.5   --小更新
// 
//更新内容：添加开机动画，设置添加恢复出厂设置
//****************************************************************************
lv_obj_t* lv_bars;
lv_obj_t* lv_main_objs;
lv_timer_t* lv_Timers_anim;
lv_obj_t* lv_label_anim;
int32_t bars_Value;
int32_t bars_y;
u8 anim_flag;

static void Timer_ainm_begin(lv_timer_t* param);
static void lv_begin_anim(void);
static void LV_MAIN_Handler(lv_event_t* e);

	
static void Timer_ainm_begin(lv_timer_t* param){
    if (bars_Value<=100) {
        bars_Value += 10;
        lv_bar_set_value(lv_bars, bars_Value, LV_ANIM_ON);
        lv_obj_set_style_opa(lv_bars, bars_Value*2,0);
        if (bars_Value * 2>=200) {
            lv_obj_set_style_opa(lv_bars, 255, 0);
        }
    }
    else {
       
        if (bars_y<5) {
            bars_y++;
            lv_obj_align(lv_bars, LV_ALIGN_CENTER, 0, bars_y);
            lv_obj_align(lv_label_anim, LV_ALIGN_CENTER, 0, bars_y*2*-1);
            lv_obj_set_style_opa(lv_label_anim, bars_y*50,0);
        }
        if (bars_y>=5) {
            lv_obj_del(lv_main_objs);
            lv_timer_pause(lv_Timers_anim);
									//显示已经显示多少单词
						Key_Main_btn = lv_btn_create(lv_scr_act());
						lv_obj_set_scrollbar_mode(Key_Main_btn, LV_SCROLLBAR_MODE_OFF);//不显示滚动条
						lv_obj_clear_flag(Key_Main_btn, LV_OBJ_FLAG_SCROLLABLE);//使对象不可滚动。
						lv_obj_set_size(Key_Main_btn,130,20);
						lv_obj_align(Key_Main_btn,LV_ALIGN_BOTTOM_MID,0,-13);
						lv_obj_set_style_bg_color(Key_Main_btn,lv_color_hex(0x808A87),0);
						lv_obj_set_style_radius(Key_Main_btn,0,0);
						lv_obj_t* Key_Main_label = lv_label_create(Key_Main_btn);
						lv_obj_set_style_text_font(Key_Main_label,&HZ,0);
						lv_label_set_text(Key_Main_label, "进入");
						lv_obj_center(Key_Main_label);

						lv_obj_add_event_cb(Key_Main_btn,LV_MAIN_Handler,LV_EVENT_ALL,NULL);
						
						if(Key_main_FLAG == 0) {
								label_word = lv_label_create(lv_scr_act());
								lv_obj_set_scrollbar_mode(label_word, LV_SCROLLBAR_MODE_OFF);//不显示滚动条
								lv_obj_clear_flag(label_word, LV_OBJ_FLAG_SCROLLABLE);//使对象不可滚动。
								lv_obj_set_style_text_font(label_word,&HZ,0);
								
								if(Wrod_Ch_Flag == 1){
									lv_label_set_text_fmt(label_word,"需记 30 个四级单词.\n已记 %d 个单词.",Word_Flag);
								}else if(Wrod_Ch_Flag == 2){
									lv_label_set_text_fmt(label_word,"需记 30 个二级单词.\n已记 %d 个单词.",Word_Flag);
								}
								lv_obj_align(label_word,LV_ALIGN_TOP_MID,0,0);
						}
					
						LV_KEY_End();
        }
    }

}

static void lv_begin_anim(void)
{
#if 1
    lv_main_objs = lv_obj_create(lv_scr_act());
		lv_obj_set_scrollbar_mode(lv_main_objs , LV_SCROLLBAR_MODE_OFF);//不显示滚动条
		lv_obj_clear_flag(lv_main_objs , LV_OBJ_FLAG_SCROLLABLE);//使对象不可滚动。
    lv_obj_set_size(lv_main_objs, 160, 80);
	  lv_obj_set_style_radius(lv_main_objs,0,0);
    lv_obj_set_style_bg_color(lv_main_objs, lv_color_hex(0xffffff), 0);
    lv_bars = lv_bar_create(lv_main_objs);
    lv_obj_set_size(lv_bars,100,4);
    lv_obj_align(lv_bars,LV_ALIGN_CENTER,0,0);
    lv_obj_set_style_bg_color(lv_bars, lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_set_style_bg_color(lv_bars,lv_color_hex(0xFF8000), LV_PART_INDICATOR);
    //显示标签
    lv_label_anim = lv_label_create(lv_main_objs);
    // lv_obj_set_style_text_font(lv_label_anim, LV_FONT_MONTSERRAT_24, 0);
    lv_obj_set_style_text_font(lv_label_anim, &lv_font_montserrat_24, 0);
    lv_label_set_recolor(lv_label_anim, true);
    lv_label_set_text(lv_label_anim, "#FF8000 PEN");
    lv_obj_align(lv_label_anim, LV_ALIGN_CENTER, -10, 0);
    lv_obj_set_style_opa(lv_label_anim,0,0);
    lv_obj_t* lv_label_vis = lv_label_create(lv_main_objs);
    // lv_obj_set_style_text_font(lv_label_anim, LV_FONT_MONTSERRAT_24, 0);
    lv_obj_set_style_text_font(lv_label_vis, &lv_font_montserrat_12, 0);
    lv_label_set_recolor(lv_label_vis, true);
    lv_label_set_text(lv_label_vis, "#FF8000 VES.1.0.2");
    lv_obj_align(lv_label_vis, LV_ALIGN_BOTTOM_RIGHT, 5, 2);
   //Time定时器
    lv_Timers_anim = lv_timer_create(Timer_ainm_begin,80,NULL);

#endif
        
}

/*****************************************************************************/

static void LV_MAIN_Handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    if (code==LV_EVENT_CLICKED) {
        Key_once++;
        if (Key_once ==1) {
            lv_obj_del(Key_Main_btn);
            lv_obj_del(label_word);
            LV_Menu_Init();
        }
        //LV_LOG_USER("Eglish_Flag =%d\n", Key_main_FLAG);
    }

}

void LV_Main_Code(void) {
    LV_KEY();
    
		
	  //读取上一次语言设置  
		W25QXX_Read(Language_buff,Language_Flag_Addr,sizeof(Language_buff));
	  Language_Flag =atoi(Language_buff);
	  //读取上一次背景设置			
		W25QXX_Read(Background_buff,Background_Flag_Addr,sizeof(Background_buff));
	  Bg_Flag =atoi(Background_buff);
	//读取上一次
		W25QXX_Read(Word_buff,Word_Flag_Addr,sizeof(Word_buff));
		Word_Flag=atoi(Word_buff);
	  word_num=Word_Flag;
	//读取上一次设置电压警报
	  W25QXX_Read(Power_buff,1024*1024*141,sizeof(Power_buff));
	  Vol_Value =atoi(Power_buff);
	lv_begin_anim();//开机动画
  #if 0
	//显示已经显示多少单词
    Key_Main_btn = lv_btn_create(lv_scr_act());
		lv_obj_set_scrollbar_mode(Key_Main_btn, LV_SCROLLBAR_MODE_OFF);//不显示滚动条
    lv_obj_clear_flag(Key_Main_btn, LV_OBJ_FLAG_SCROLLABLE);//使对象不可滚动。
    lv_obj_set_size(Key_Main_btn,130,20);
    lv_obj_align(Key_Main_btn,LV_ALIGN_BOTTOM_MID,0,-13);
    lv_obj_set_style_bg_color(Key_Main_btn,lv_color_hex(0x808A87),0);
    lv_obj_set_style_radius(Key_Main_btn,0,0);
    lv_obj_t* Key_Main_label = lv_label_create(Key_Main_btn);
		lv_obj_set_style_text_font(Key_Main_label,&HZ,0);
    lv_label_set_text(Key_Main_label, "进入");
    lv_obj_center(Key_Main_label);

    lv_obj_add_event_cb(Key_Main_btn,LV_MAIN_Handler,LV_EVENT_ALL,NULL);
		
    if(Key_main_FLAG == 0) {
        label_word = lv_label_create(lv_scr_act());
			  lv_obj_set_scrollbar_mode(label_word, LV_SCROLLBAR_MODE_OFF);//不显示滚动条
        lv_obj_clear_flag(label_word, LV_OBJ_FLAG_SCROLLABLE);//使对象不可滚动。
				lv_obj_set_style_text_font(label_word,&HZ,0);
				
				if(Wrod_Ch_Flag == 1){
					lv_label_set_text_fmt(label_word,"需记 30 个四级单词.\n已记 %d 个单词.",Word_Flag);
			  }else if(Wrod_Ch_Flag == 2){
					lv_label_set_text_fmt(label_word,"需记 30 个二级单词.\n已记 %d 个单词.",Word_Flag);
			  }
        lv_obj_align(label_word,LV_ALIGN_TOP_MID,0,0);
    }
	
    LV_KEY_End();
		#endif
}


static void scroll_event_cb(lv_event_t* e)
{
    lv_obj_t* cont = lv_event_get_target(e);

    lv_area_t cont_a;
    lv_obj_get_coords(cont, &cont_a);
    lv_coord_t cont_y_center = cont_a.y1 + lv_area_get_height(&cont_a) / 2;

    lv_coord_t r = lv_obj_get_height(cont) * 7 / 10;
    uint32_t i;
    uint32_t child_cnt = lv_obj_get_child_cnt(cont);
    for (i = 0; i < child_cnt; i++) {
        lv_obj_t* child = lv_obj_get_child(cont, i);
        lv_area_t child_a;
        lv_obj_get_coords(child, &child_a);

        lv_coord_t child_y_center = child_a.y1 + lv_area_get_height(&child_a) / 2;

        lv_coord_t diff_y = child_y_center - cont_y_center;
        diff_y = LV_ABS(diff_y);

        /*Get the x of diff_y on a circle.*/
        lv_coord_t x;
        /*If diff_y is out of the circle use the last point of the circle (the radius)*/
        if (diff_y >= r) {
            x = r;
        }
        else {
            /*Use Pythagoras theorem to get x from radius and y*/
            uint32_t x_sqr = r * r - diff_y * diff_y;
            lv_sqrt_res_t res;
            lv_sqrt(x_sqr, &res, 0x8000);   /*Use lvgl's built in sqrt root function*/
            x = r - res.i;
        }

        /*Translate the item by the calculated X coordinate*/
        lv_obj_set_style_translate_x(child, x, 0);

        /*Use some opacity with larger translations*/
        lv_opa_t opa = lv_map(x, 0, r, LV_OPA_TRANSP, LV_OPA_COVER);
        lv_obj_set_style_opa(child, LV_OPA_COVER - opa, 0);
    }
}

/**
 * Translate the object as they scroll
 */
void LV_KEY(void)
{
    g = lv_group_create();
    lv_group_set_default(g);


}
void LV_KEY_End(void) {
		//lv_group_add_obj(g,obj);
    lv_indev_set_group(indev_ecodes, g);

}
void LV_Menu_Init(void)
{

    // LV_KEY_Init();
    obj = lv_obj_create(lv_scr_act());
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xC0D2F0), 0);


    lv_obj_set_size(obj, 160, 80);
    lv_obj_center(obj);
    lv_obj_set_flex_flow(obj, LV_FLEX_FLOW_COLUMN);
    lv_obj_add_event_cb(obj, scroll_event_cb, LV_EVENT_SCROLL, NULL);
    lv_obj_set_style_radius(obj, 5, 0);
    lv_obj_set_style_clip_corner(obj, true, 0);
    lv_obj_set_scroll_dir(obj, LV_DIR_VER);
    lv_obj_set_scroll_snap_y(obj, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
    lv_event_send(obj, LV_EVENT_SCROLL, NULL);
    //菜单一 英语词典
    Eglish_Disc_Function();
    //菜单二 RTC时钟
    RTC_Time_Function();
    //菜单三 定时提醒
    Timer_Function();
    //菜单四 贪吃蛇游戏
    Games_Function();
    //菜单五 曲谱
    Song_Function();
    //设置
    Set_Function();
       //添加自己的单词 更新时间2022.11.29
    add_word_Function();
    /*Update the buttons position manually for first*/

    lv_obj_clear_flag(obj, LV_OBJ_FLAG_HIDDEN);
    /*Be sure the fist button is in the middle*/
    lv_obj_scroll_to_view(lv_obj_get_child(obj, 0), LV_ANIM_OFF);
    //lv_indev_set_group(lv_win32_encoder_device_object, g);
   //LV_KEY_Config();
}


#if 0 //你想卡死你可以使用
void Back_btn_Handler(lv_event_t* param)
{
    lv_event_code_t vscode = lv_event_get_code(param);
    lv_obj_t* mune = lv_event_get_target(param);


    if (vscode == LV_EVENT_CLICKED) {


        //LV_LOG_USER("Function_1=%d\n",(int32_t)mune);
        if (mune == Back_btn) {
            // LV_LOG_USER("Function_1\n");
            lv_obj_clean(obj_1);
           
        }
        if (mune == Back_btn_1) {
           
            obj_2_FLAG = 0;
					  
            lv_obj_clean(obj_2);
            
        }
        if (mune == Back_btn_2) {
            
            lv_obj_clean(obj_3);
           
        }
        if (mune == Back_btn_3) {

            
            lv_timer_pause(timer);
            lv_timer_pause(timer1);
            lv_timer_pause(timer_2);
            obj_4_FLAG = 0;           
            
            lv_timer_del(timer);
            lv_timer_del(timer1);
            lv_timer_del(timer_2);
						lv_obj_clean(obj_4);

        }
        if (mune == Back_btn_4) {

            lv_obj_del(obj_5);
           
        }
        if (mune == Back_btn_5) {

            lv_obj_clean(obj_6);
            
        }

        LV_Menu_Init();

    

    }


}
#endif

#if 0
void Back_Main(lv_obj_t* fai) {
    if (fai == obj_1) {
        Back_btn = lv_btn_create(obj_1);
        lv_obj_set_size(Back_btn, 36, 12);
        lv_obj_set_style_radius(Back_btn, 5, 0);
        lv_obj_align(Back_btn, LV_ALIGN_TOP_LEFT, -13, -13);
        lv_obj_set_style_bg_color(Back_btn, lv_color_hex(0x808A87), LV_PART_MAIN);
        lv_obj_t* Back_label = lv_label_create(Back_btn);
        lv_label_set_recolor(Back_label, true);
        lv_label_set_text(Back_label, "#000000 <#");
        lv_obj_center(Back_label);

        lv_obj_add_event_cb(Back_btn, Back_btn_Handler, LV_EVENT_CLICKED, NULL);
    }
    if (fai == obj_2) {
        Back_btn_1 = lv_btn_create(obj_2);
        lv_obj_set_size(Back_btn_1, 36, 12);
        lv_obj_set_style_radius(Back_btn_1, 5, 0);
        lv_obj_align(Back_btn_1, LV_ALIGN_TOP_LEFT, -13, -13);
        lv_obj_set_style_bg_color(Back_btn_1, lv_color_hex(0x808A87), LV_PART_MAIN);
        lv_obj_t* Back_label_1 = lv_label_create(Back_btn_1);
        lv_label_set_recolor(Back_label_1, true);
        lv_label_set_text(Back_label_1, "#000000 <#");
        lv_obj_center(Back_label_1);
        lv_obj_add_event_cb(Back_btn_1, Back_btn_Handler, LV_EVENT_CLICKED, NULL);
    }
    if (fai == obj_3) {
        Back_btn_2 = lv_btn_create(obj_3);
        lv_obj_set_size(Back_btn_2, 36, 12);
        lv_obj_set_style_radius(Back_btn_2, 5, 0);
        lv_obj_align(Back_btn_2, LV_ALIGN_TOP_LEFT, -13, -13);
        lv_obj_set_style_bg_color(Back_btn_2, lv_color_hex(0x808A87), LV_PART_MAIN);
        lv_obj_t* Back_label_2 = lv_label_create(Back_btn_2);
        lv_label_set_recolor(Back_label_2, true);
        lv_label_set_text(Back_label_2, "#000000 <#");
        lv_obj_center(Back_label_2);
        lv_obj_add_event_cb(Back_btn_2, Back_btn_Handler, LV_EVENT_CLICKED, NULL);
    }
    if (fai == obj_4) {
        Back_btn_3 = lv_btn_create(obj_4);
        lv_obj_set_size(Back_btn_3, 36, 12);
        lv_obj_set_style_radius(Back_btn_3, 5, 0);
        lv_obj_align(Back_btn_3, LV_ALIGN_TOP_LEFT, -13, -13);
        lv_obj_set_style_bg_color(Back_btn_3, lv_color_hex(0x808A87), LV_PART_MAIN);
        lv_obj_t* Back_label_3 = lv_label_create(Back_btn_3);
        lv_label_set_recolor(Back_label_3, true);
        lv_label_set_text(Back_label_3, "#000000 <#");
        lv_obj_center(Back_label_3);
        lv_obj_add_event_cb(Back_btn_3, Back_btn_Handler, LV_EVENT_CLICKED, NULL);
    }
    if (fai == obj_5) {
        Back_btn_4 = lv_btn_create(obj_5);
        lv_obj_set_size(Back_btn_4, 36, 12);
        lv_obj_set_style_radius(Back_btn_4, 5, 0);
        lv_obj_align(Back_btn_4, LV_ALIGN_TOP_LEFT, -13, -13);
        lv_obj_set_style_bg_color(Back_btn_4, lv_color_hex(0x808A87), LV_PART_MAIN);
        lv_obj_t* Back_label_4 = lv_label_create(Back_btn_4);
        lv_label_set_recolor(Back_label_4, true);
        lv_label_set_text(Back_label_4, "#000000 <#");
        lv_obj_center(Back_label_4);
        lv_obj_add_event_cb(Back_btn_4, Back_btn_Handler, LV_EVENT_CLICKED, NULL);
    }
    if (fai == obj_6) {
        Back_btn_5 = lv_btn_create(obj_6);
        lv_obj_set_size(Back_btn_5, 36, 12);
        lv_obj_set_style_radius(Back_btn_5, 5, 0);
        lv_obj_align(Back_btn_5, LV_ALIGN_TOP_LEFT, -13, -13);
        lv_obj_set_style_bg_color(Back_btn_5, lv_color_hex(0x808A87), LV_PART_MAIN);
        lv_obj_t* Back_label_5 = lv_label_create(Back_btn_5);
        lv_label_set_recolor(Back_label_5, true);
        lv_label_set_text(Back_label_5, "#000000 <#");
        lv_obj_center(Back_label_5);
        lv_obj_add_event_cb(Back_btn_5, Back_btn_Handler, LV_EVENT_CLICKED, NULL);
    }
}
#endif

void ALL_INPUT_Handler(lv_event_t* pamar)
{
    lv_event_code_t btn_code = lv_event_get_code(pamar);
    lv_obj_t* name = lv_event_get_target(pamar);

    if (btn_code == LV_EVENT_CLICKED) {

        lv_obj_del(obj);

        if (name == btn) {
					//del_who();
            Eglish_Main_Function();
           
        }
        if (name == btn1) {
					//del_who();
            obj_2_FLAG = 1;
            RTC_Timer_Main_Function();
            
        }
        if (name == btn2) {
					//del_who();
            obj_3_FLAG = 1;
            Timer_Main_Function();
            
        }
        if (name == btn3) {
						//del_who();
					//小恐龙快跑初始化
            Din.end_y = 20;
            Din.obs_y = 130;
            Clu.cloud_init = 130;
            Clu.cloud_value = 0;
            Din.Don_score = 0;
            Cas.Don_rand = 0;
            Cas.OBS = 0;
            Cas.OBS_Ch = 0;  
						Games_Main_Function();
            lv_timer_resume(timer);
            lv_timer_resume(timer1);
            lv_timer_resume(timer_2);
            obj_4_FLAG = 1;
        }
        if (name == btn4) {
					
            Song_Main_Function();
        }
        if (name == btn5) {
					  
            Set_Main_Function();
        }
				        //更新时间2022.11.29
        if (name == btn6) {
            personal_Main_Function();
        }
    }

}


//菜单一 英语词典
void Eglish_Main_Function(void) {
		del_Flag=1;
    obj_1 = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj_1, 160, 80);
    lv_obj_center(obj_1);
		lv_obj_set_style_radius(obj_1, 0, 0);
	  lv_obj_set_scrollbar_mode(obj_1, LV_SCROLLBAR_MODE_OFF);//不显示滚动条
    lv_obj_clear_flag(obj_1, LV_OBJ_FLAG_SCROLLABLE);//使对象不可滚动。
		LV_English_Display_Bg(obj_1);
    LV_Eglish_Display_btn(obj_1);
    LV_Eglish_Display_label(obj_1);
	  LV_PORT_Power(obj_1);
    //Back_Main(obj_1);
    LV_PORT_1_Back_btn(obj_1);
}

void Eglish_Disc_Function(void)
{
    btn = lv_btn_create(obj);
		lv_obj_set_style_bg_color(btn, lv_color_hex(0x808A87), 0);
    lv_obj_set_size(btn, 120, 50);
	
    lv_obj_t* label = lv_label_create(btn);
	  lv_obj_set_style_text_font(label,&HZ,0);
	  //中英文切换
	  if(Language_Flag==0)    lv_label_set_text(label, "单词");
		else if(Language_Flag==1)  lv_label_set_text(label, "English");
    lv_obj_align(label, LV_ALIGN_RIGHT_MID, 0, 0);
    //显示图片
    lv_obj_t* img = lv_img_create(btn);
    lv_img_set_src(img, &LV_Eglish);
    lv_obj_align(img, LV_ALIGN_LEFT_MID, 0, 0);

    lv_obj_add_event_cb(btn, ALL_INPUT_Handler, LV_EVENT_ALL, NULL);
}



//菜单二 RTC时钟
void RTC_Timer_Main_Function(void) {
		del_Flag=2;
    obj_2 = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj_2, 160, 80);
    lv_obj_center(obj_2);
		lv_obj_set_style_radius(obj_2, 0, 0);
    lv_obj_set_scrollbar_mode(obj_2, LV_SCROLLBAR_MODE_OFF);//不显示滚动条
    lv_obj_clear_flag(obj_2, LV_OBJ_FLAG_SCROLLABLE);//使对象不可滚动。
		LV_Time_Display_BG(obj_2);
    RTC_Display_Time(9, 9, obj_2);//显示时间
    RTC_Display_Data(22, 9, 15, obj_2);
    RTC_Display_Week(22, 9, 15, obj_2);
    RTC_Display_Course(obj_2);
    //Back_Main(obj_2);
    LV_PORT_2_Back_btn(obj_2);
}



void RTC_Time_Function(void)
{
    btn1 = lv_btn_create(obj);
		lv_obj_set_style_bg_color(btn1, lv_color_hex(0x808A87), 0);
    lv_obj_set_size(btn1, 120, 40);
    lv_obj_t* label1 = lv_label_create(btn1);
		lv_obj_set_style_text_font(label1,&HZ,0);
    if(Language_Flag==0) lv_label_set_text(label1, "时间");
	  else if(Language_Flag ==1) lv_label_set_text(label1, "Time");
    lv_obj_align(label1, LV_ALIGN_RIGHT_MID, 0, 0);

    //显示图片
    lv_obj_t* img1 = lv_img_create(btn1);
    lv_img_set_src(img1,&RTCS);
    lv_obj_align(img1, LV_ALIGN_LEFT_MID, 0, 0);
    //创建新的子界面
   // RTC_Timer_Main_Function();
   // lv_obj_add_flag(obj_2, LV_OBJ_FLAG_HIDDEN);

    lv_obj_add_event_cb(btn1, ALL_INPUT_Handler, LV_EVENT_ALL, NULL);

}
//菜单三 定时提醒
void Timer_Main_Function(void) {
		del_Flag=3;
    obj_3 = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj_3, 160, 80);
    lv_obj_set_scrollbar_mode(obj_3, LV_SCROLLBAR_MODE_OFF);
    lv_obj_center(obj_3);
    LV_Timer_Display_roller(obj_3);
    LV_Timer_Display_roller_1(obj_3);
    LV_Timer_Display_roller_2(obj_3);
    //LV_Timer_Display_label(obj_3);
    LV_Timer_Display_btn(obj_3);
		//LV_Timer_Display_time(obj_3);
    //Back_Main(obj_3);
}

void Timer_Function(void)
{
    btn2 = lv_btn_create(obj);
		lv_obj_set_style_bg_color(btn2, lv_color_hex(0x808A87), 0);
    lv_obj_set_size(btn2, 120, 40);
    lv_obj_t* label2 = lv_label_create(btn2);
		lv_obj_set_style_text_font(label2,&HZ,0);
    if(Language_Flag==0) lv_label_set_text(label2, "定时");
		else if(Language_Flag==1) lv_label_set_text(label2, "Timer");
    lv_obj_align(label2, LV_ALIGN_RIGHT_MID, 0, 0);
    //显示图片
    lv_obj_t* img2 = lv_img_create(btn2);
    lv_img_set_src(img2, &Timer);
    lv_obj_align(img2, LV_ALIGN_LEFT_MID, 0, 0);
    //创建新的子界面
   // Timer_Main_Function();
   // lv_obj_add_flag(obj_3, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_event_cb(btn2, ALL_INPUT_Handler, LV_EVENT_ALL, NULL);

}
//菜单四 贪吃蛇游戏
void Games_Main_Function(void) {
		del_Flag=4;
    obj_4 = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj_4, 160, 80);
    lv_obj_center(obj_4);

    LV_Game_Display_Cloud(obj_4);
    LV_Games_Display_Din(obj_4);

    LV_Game_Play_Once(obj_4);
    LV_Get_score(obj_4);
    LV_Games_Display_btn(obj_4);
    LV_Game_Display_Road_Obs(obj_4);
    //Back_Main(obj_4);
	  LV_PORT_3_Back_btn(obj_4);
}

void Games_Function(void)
{
    btn3 = lv_btn_create(obj);
	  lv_obj_set_style_bg_color(btn3, lv_color_hex(0x808A87), 0);
    lv_obj_set_size(btn3, 120, 40);
    lv_obj_t* label3 = lv_label_create(btn3);
		lv_obj_set_style_text_font(label3,&HZ,0);
	
    if(Language_Flag==0) lv_label_set_text(label3, "游戏");
		else if(Language_Flag==1) lv_label_set_text(label3, "Games");
    lv_obj_align(label3, LV_ALIGN_RIGHT_MID, 0, 0);
    //显示图片
    lv_obj_t* img3 = lv_img_create(btn3);
    lv_img_set_src(img3, &Games);
    lv_obj_align(img3, LV_ALIGN_LEFT_MID, 0, 0);
    //创建新的子界面
  //  Games_Main_Function();
   // lv_obj_add_flag(obj_4, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_event_cb(btn3, ALL_INPUT_Handler, LV_EVENT_ALL, NULL);
}
//菜单五 曲谱
void Song_Main_Function(void) {
	  del_Flag=5;
    obj_5 = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj_5, 160, 80);
    lv_obj_set_scrollbar_mode(obj_5, LV_SCROLLBAR_MODE_OFF);//不显示滚动条
    lv_obj_clear_flag(obj_5, LV_OBJ_FLAG_SCROLLABLE);//使对象不可滚动。
    lv_obj_center(obj_5);
    LV_RGB_Display_btn(obj_5);
    LV_RGB_Display_Cor(obj_5);
    LV_RGB_Display_Red_Slider(obj_5);
    //Back_Main(obj_5);
		LV_PORT_4_Back_btn(obj_5);
}

void Song_Function(void)
{
    btn4 = lv_btn_create(obj);
	lv_obj_set_style_bg_color(btn4, lv_color_hex(0x808A87), 0);
    lv_obj_set_size(btn4, 120, 40);
    lv_obj_t* label4 = lv_label_create(btn4);
	  lv_obj_set_style_text_font(label4,&HZ,0);
    if(Language_Flag==0) lv_label_set_text(label4, "灯光");
	  else if(Language_Flag==1) lv_label_set_text(label4, "RGB");
    lv_obj_align(label4, LV_ALIGN_RIGHT_MID, 0, 0);
    //显示图片
    lv_obj_t* img4 = lv_img_create(btn4);
    lv_img_set_src(img4, &Song);
    lv_obj_align(img4, LV_ALIGN_LEFT_MID, 0, 0);
    //创建新的子界面
   // Song_Main_Function();
   // lv_obj_add_flag(obj_5, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_event_cb(btn4, ALL_INPUT_Handler, LV_EVENT_ALL, NULL);
}
//菜单六 设置
void Set_Main_Function(void) {
		del_Flag=6;
    obj_6 = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj_6, 160, 80);
    lv_obj_center(obj_6);
	  lv_obj_set_scrollbar_mode(obj_6, LV_SCROLLBAR_MODE_OFF);//不显示滚动条
    LV_Set_Display_Menu(obj_6);
    //Back_Main(obj_6);
		
}

void Set_Function(void)
{
    btn5 = lv_btn_create(obj);
	  lv_obj_set_style_bg_color(btn5, lv_color_hex(0x808A87), 0);
    lv_obj_set_size(btn5, 120, 40);
    lv_obj_t* label5 = lv_label_create(btn5);
	  lv_obj_set_style_text_font(label5,&HZ,0);
    if(Language_Flag==0) lv_label_set_text(label5, "设置");
	  else if(Language_Flag==1) lv_label_set_text(label5, "Set");
    lv_obj_align(label5, LV_ALIGN_RIGHT_MID, 0, 0);
    //显示图片
    lv_obj_t* img5 = lv_img_create(btn5);
    lv_img_set_src(img5, &Set);
    lv_obj_align(img5, LV_ALIGN_LEFT_MID, 0, 0);
    //创建新的子界面
  //  Set_Main_Function();
   // lv_obj_add_flag(obj_6, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_event_cb(btn5, ALL_INPUT_Handler, LV_EVENT_ALL, NULL);
}

//更新时间2022.11.29
void personal_Main_Function(void) {
    del_Flag = 7;
    obj_7 = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj_7, 160, 80);
    LV_PORT_6_Back_btn(obj_7);
		lv_obj_set_scrollbar_mode(obj_7, LV_SCROLLBAR_MODE_OFF);//不显示滚动条
		LV_PORT_6_Display_Own_Wrod(obj_7);
}



void  add_word_Function(void) {
    btn6 = lv_btn_create(obj);
		lv_obj_set_style_bg_color(btn6, lv_color_hex(0x808A87), 0);
    lv_obj_set_size(btn6,120,40);
    lv_obj_t* label6 = lv_label_create(btn6);
	  lv_obj_set_style_text_font(label6,&HZ,0);
		if(Language_Flag==0) lv_label_set_text(label6, "个人");
	  else if(Language_Flag==1) lv_label_set_text(label6, "Word");
    
    lv_obj_align(label6, LV_ALIGN_RIGHT_MID, 0, 0);
      
    lv_obj_t* img6 = lv_img_create(btn6);
    lv_img_set_src(img6, &own_Word);
    lv_obj_align(img6, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_add_event_cb(btn6, ALL_INPUT_Handler, LV_EVENT_ALL, NULL);
}