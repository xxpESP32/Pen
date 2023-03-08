#include "LVGL_PORT_5.h"
#include "LVGL_Main.h"
#include "rtc.h"
#include "w25q128.h"
#include "lcd_init.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"

/* 更新时间：2022/10/27
*更新内容：增加每日单词30个提醒
*           增加旋转界面设置。
*/

lv_obj_t* Set_mu;
lv_obj_t* Set_Back_btn;

lv_obj_t* Set_other;

lv_obj_t* Set_slider_h;
lv_obj_t* Set_slider_m;
lv_obj_t* Set_slider_s;
lv_obj_t* Set_slider_y;
lv_obj_t* Set_slider_mo;
lv_obj_t* Set_slider_d;

lv_obj_t* Set_h_label_v;
lv_obj_t* Set_m_label_v;
lv_obj_t* Set_s_label_v;
lv_obj_t* Set_y_label_v;
lv_obj_t* Set_mo_label_v;
lv_obj_t* Set_d_label_v;
lv_obj_t* Set_true_label;
static void LV_Set_Display_Back_btn(lv_obj_t* bt);
static void LV_Set_time(lv_obj_t* bt);


lv_obj_t* Set_sw_label_v;
uint8_t Sw_Flag;

uint8_t Sw_Numbel;
uint8_t Language_buff[10];

static void LV_Set_Display_switch(lv_obj_t* sw);

struct Set_time SETS;
LV_FONT_DECLARE(HZ);

uint8_t Sw_Bg_Flag;

lv_obj_t* Set_sw_label_bg;
uint8_t Background_buff[10];
static void LV_Set_Display_switch_bg(lv_obj_t* b);

//更新时间 2022.10.23 
lv_obj_t* Set_sw_label_ro;
int32_t Ro_Flag;
static void LV_Set_Display_switch_ro(lv_obj_t* b);
//更新时间 2022.10.29
lv_obj_t* Set_sw_label_Wrod;
int32_t Wrod_Flag;

static void LV_Set_Display_switch_Wrod(lv_obj_t* b);
//更新时间 2022.11.17
void LV_Set_Power_prompt(lv_obj_t* b);
static lv_obj_t* spinbox;
int32_t Vol_Value;
uint8_t power_cp[10];


/*函数：void LV_Set_Display_Menu(lv_obj_t* mu)
*作者：小夏
*形参：lv_obj_t* mu
*描述：绘制tabview控件。
*修改时间：2022/9/20
*修改内容：无
*/
void LV_Set_Display_Menu(lv_obj_t* mu) {

		Set_mu = lv_tabview_create(mu,LV_DIR_TOP, 16);
    lv_obj_set_style_radius(Set_mu, 2, 0);
    lv_obj_set_size(Set_mu,155,80);
    lv_obj_align(Set_mu, LV_ALIGN_TOP_RIGHT, 13, -13);
	 
	 
    Set_other = lv_tabview_add_tab(Set_mu, "Set");
    lv_obj_set_scrollbar_mode(Set_other, LV_SCROLLBAR_MODE_OFF);//不显示滚动条
   // lv_obj_clear_flag(Set_other, LV_OBJ_FLAG_SCROLLABLE);//使对象不可滚动。
    LV_Set_Display_Back_btn(Set_other);
    LV_Set_time(Set_other);
		LV_Set_Display_switch(Set_other);
		LV_Set_Display_switch_bg(Set_other);
		LV_Set_Display_switch_ro(Set_other); //更新 2020.10.23
	  LV_Set_Display_switch_Wrod(Set_other);//更新 2020.10.29
		LV_Set_Power_prompt(Set_other);//更新 2020.11.17
}
/*函数：static void Set_Back_handler(lv_event_t* e) 
*作者：小夏
*形参：lv_event_t* e
*描述：lv_obj_add_event_cb(Set_Back_btn, Set_Back_handler, LV_EVENT_ALL, NULL);
			 事件执行函数
			 退出按键功能
*修改时间：2022/9/20
*修改内容：无
*/
static void Set_Back_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* new_name = lv_event_get_target(e);

    if (code ==LV_EVENT_CLICKED) {
        if (new_name== Set_Back_btn) {
            lv_obj_clean(obj_6);
        }
        LV_Menu_Init();
    }


}


/*函数：static void LV_Set_Display_Back_btn(lv_obj_t* bt)
*作者：小夏
*形参：lv_obj_t* bt
*描述：//退出按键绘制
*修改时间：2022/11/21
*修改内容：更新时间：2020.11.21 更新back的位置原来是210 改为 210+15
*/
static void LV_Set_Display_Back_btn(lv_obj_t* bt) {
    Set_Back_btn = lv_btn_create(bt);

    lv_obj_set_size(Set_Back_btn, 140, 10);
    lv_obj_set_style_radius(Set_Back_btn, 0, 0);
    lv_obj_set_style_bg_color(Set_Back_btn, lv_color_hex(0x808A87), 0);
    lv_obj_align(Set_Back_btn, LV_ALIGN_BOTTOM_MID, 0, 210+15);
    lv_obj_t* Set_Back_label = lv_label_create(Set_Back_btn);
    lv_label_set_text(Set_Back_label, "Back");
    lv_obj_center(Set_Back_label);
    lv_obj_add_event_cb(Set_Back_btn, Set_Back_handler, LV_EVENT_ALL, NULL);
}
/*函数：static void Set_h_Handler(lv_event_t* e) 
*作者：小夏
*形参：lv_event_t* e
*描述：lv_obj_add_event_cb(Set_slider_h,Set_h_Handler, LV_EVENT_ALL, NULL);
			 事件执行函数
       显示设置日期的label。
*修改时间：2022/9/20
*修改内容：无
*/
static void Set_h_Handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* new_name = lv_event_get_target(e);
    if (code == LV_EVENT_VALUE_CHANGED)
    {
        if (new_name== Set_slider_h) {
            SETS.Hs = lv_slider_get_value(Set_slider_h);
            lv_label_set_text_fmt(Set_h_label_v, "%d", lv_slider_get_value(Set_slider_h));
        }
        if (new_name == Set_slider_m) {
            SETS.Ms = lv_slider_get_value(Set_slider_m);
            lv_label_set_text_fmt(Set_m_label_v, "%d", lv_slider_get_value(Set_slider_m));
        }
        if (new_name == Set_slider_s) {
            SETS.Ss = lv_slider_get_value(Set_slider_s);
            lv_label_set_text_fmt(Set_s_label_v, "%d", lv_slider_get_value(Set_slider_s));
        }
        if (new_name == Set_slider_y) {
            SETS.Ys = 2000 + lv_slider_get_value(Set_slider_y);
            lv_label_set_text_fmt(Set_y_label_v, "%d", 2000+lv_slider_get_value(Set_slider_y));
        }
        if (new_name == Set_slider_mo) {
            SETS.MOs = lv_slider_get_value(Set_slider_mo);
            lv_label_set_text_fmt(Set_mo_label_v, "%d",lv_slider_get_value(Set_slider_mo));
        }
        if (new_name == Set_slider_d) {
            SETS.Ds = lv_slider_get_value(Set_slider_d);
            lv_label_set_text_fmt(Set_d_label_v, "%d", lv_slider_get_value(Set_slider_d));
        }
				printf("%d-%d-%d-%d-%d-%d\n",SETS.Hs,SETS.Ms,SETS.Ss,SETS.Ys,SETS.MOs,SETS.Ds);
    }

}
 
/*函数：static void Set_h_Handler(lv_event_t* e) 
*作者：小夏
*形参：lv_event_t* e
*描述：lv_obj_add_event_cb(Set_true_btn, Set_true_handler, LV_EVENT_ALL, NULL);
       的事件执行函数
			 设置事件初始化。
*修改时间：2022/9/20
*修改内容：无
*/
static void Set_true_handler(lv_event_t* e){
	lv_event_code_t code =lv_event_get_code(e);
	
	if(code == LV_EVENT_CLICKED){
	calendar.year  = SETS.Ys;
  calendar.month = SETS.MOs;
  calendar.date  = SETS.Ds;
  calendar.hour  = SETS.Hs;
  calendar.min   = SETS.Ms;
  calendar.sec   = SETS.Ss;
	rtc_time_set(&calendar);	
		if(Language_Flag==0) lv_label_set_text(Set_true_label, "<设置成功>");
		else if(Language_Flag==1) lv_label_set_text(Set_true_label, "<Set success>");	
	}
	
}
/*函数：static void LV_Set_time(lv_obj_t* bt)
*作者：小夏
*形参：lv_obj_t* bt
*描述：绘制时间控件。
*修改时间：2022/11/21
*修改内容：修改坐标+15，添加一个无用按键 file_btn
*/
static void LV_Set_time(lv_obj_t* bt) {
		lv_obj_t* file_btn = lv_btn_create(bt);
    lv_obj_set_style_bg_color(file_btn, lv_color_hex(0x808A87), 0);
    lv_obj_set_style_radius(file_btn,0,0);
    lv_obj_set_size(file_btn,155,10);
    lv_obj_align(file_btn, LV_ALIGN_TOP_MID, 0, -10);
	  
    //小时
    Set_slider_h = lv_slider_create(bt);
    lv_obj_set_size(Set_slider_h, 50, 14);
    lv_slider_set_range(Set_slider_h, 0,24);
	  //获取快捷设置时间
	  //lv_slider_set_value(Set_slider_h,calendar.hour,LV_ANIM_ON);
    lv_obj_align(Set_slider_h, LV_ALIGN_TOP_RIGHT, -20, -12+15);
    lv_obj_t* Set_h_label = lv_label_create(bt);
    lv_obj_set_style_opa(Set_slider_h, 0, LV_PART_KNOB);
    lv_obj_set_style_radius(Set_slider_h,0,LV_PART_MAIN);
    lv_obj_set_style_radius(Set_slider_h, 0, LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(Set_slider_h, lv_color_hex(0x808a87), LV_PART_INDICATOR);

    lv_obj_add_event_cb(Set_slider_h,Set_h_Handler, LV_EVENT_ALL, NULL);

    //lv_obj_set_style_text_font(Set_h_label, &lv_font_montserrat_10, 0);
	  lv_obj_set_style_text_font(Set_h_label,&HZ,0);
		
    if(Language_Flag==0) lv_label_set_text(Set_h_label, "小时,");
		else if(Language_Flag==1) {
			lv_obj_set_style_text_font(Set_h_label,&lv_font_montserrat_14,0);
			lv_label_set_text(Set_h_label, "Hour");
		}
		
    lv_obj_align(Set_h_label, LV_ALIGN_TOP_LEFT, -10, -14+15);

    Set_h_label_v = lv_label_create(bt);
    lv_obj_set_style_text_font(Set_h_label_v, &lv_font_montserrat_10, 0);
    lv_label_set_text_fmt(Set_h_label_v, "%d",lv_slider_get_value(Set_slider_h));
		
    lv_obj_align(Set_h_label_v, LV_ALIGN_TOP_RIGHT, 0, -10+15);

    lv_obj_t* Set_h_btn = lv_btn_create(bt);
    lv_obj_set_size(Set_h_btn, 10, 14);
    lv_obj_set_style_radius(Set_h_btn, 0, 0);
    lv_obj_set_style_bg_color(Set_h_btn, lv_color_hex(0x808A87), 0);
    lv_obj_align(Set_h_btn, LV_ALIGN_TOP_MID, -15, -12+15);

    //分钟
    Set_slider_m = lv_slider_create(bt);
    lv_obj_set_size(Set_slider_m, 50, 14);
    lv_slider_set_range(Set_slider_m, 0, 60);
			  //获取快捷设置时间
	  //lv_slider_set_value(Set_slider_m,calendar.min,LV_ANIM_ON);
    lv_obj_align(Set_slider_m, LV_ALIGN_TOP_RIGHT, -20, 7+15);
    lv_obj_t* Set_m_label = lv_label_create(bt);
    lv_obj_set_style_opa(Set_slider_m, 0, LV_PART_KNOB);
    lv_obj_set_style_radius(Set_slider_m, 0, LV_PART_MAIN);
    lv_obj_set_style_radius(Set_slider_m, 0, LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(Set_slider_m, lv_color_hex(0x808a87), LV_PART_INDICATOR);

    lv_obj_add_event_cb(Set_slider_m, Set_h_Handler, LV_EVENT_ALL, NULL);

    //lv_obj_set_style_text_font(Set_m_label, &lv_font_montserrat_10, 0);
		lv_obj_set_style_text_font(Set_m_label,&HZ,0);
    if(Language_Flag==0) lv_label_set_text(Set_m_label, "分钟,");
		else if(Language_Flag==1) {
			lv_obj_set_style_text_font(Set_m_label,&lv_font_montserrat_14,0);
			lv_label_set_text(Set_m_label, "Minute");
		}
    lv_obj_align(Set_m_label, LV_ALIGN_TOP_LEFT, -10, 5+15);

    Set_m_label_v = lv_label_create(bt);
    lv_obj_set_style_text_font(Set_m_label_v, &lv_font_montserrat_10, 0);
    lv_label_set_text_fmt(Set_m_label_v, "%d", lv_slider_get_value(Set_slider_m));
    lv_obj_align(Set_m_label_v, LV_ALIGN_TOP_RIGHT, 0, 9+15);

    lv_obj_t* Set_m_btn = lv_btn_create(bt);
    lv_obj_set_size(Set_m_btn, 10, 14);
    lv_obj_set_style_radius(Set_m_btn, 0, 0);
    lv_obj_set_style_bg_color(Set_m_btn, lv_color_hex(0x808A87), 0);
    lv_obj_align(Set_m_btn, LV_ALIGN_TOP_MID, -15, 7+15);
    //秒
    Set_slider_s = lv_slider_create(bt);
    lv_obj_set_size(Set_slider_s, 50, 14);
    lv_slider_set_range(Set_slider_s, 0, 60);
			  //获取快捷设置时间
	  //lv_slider_set_value(Set_slider_s,calendar.sec,LV_ANIM_ON);
    lv_obj_align(Set_slider_s, LV_ALIGN_TOP_RIGHT, -20, 24+15);
    lv_obj_t* Set_s_label = lv_label_create(bt);
    lv_obj_set_style_opa(Set_slider_s, 0, LV_PART_KNOB);
    lv_obj_set_style_radius(Set_slider_s, 0, LV_PART_MAIN);
    lv_obj_set_style_radius(Set_slider_s, 0, LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(Set_slider_s, lv_color_hex(0x808a87), LV_PART_INDICATOR);

    lv_obj_add_event_cb(Set_slider_s, Set_h_Handler, LV_EVENT_ALL, NULL);

    //lv_obj_set_style_text_font(Set_s_label, &lv_font_montserrat_10, 0);
		lv_obj_set_style_text_font(Set_s_label,&HZ,0);
    if(Language_Flag==0) lv_label_set_text(Set_s_label, "秒,");
		else if(Language_Flag==1) {
			lv_obj_set_style_text_font(Set_s_label,&lv_font_montserrat_14,0);
			lv_label_set_text(Set_s_label, "Second");
		}
    lv_obj_align(Set_s_label, LV_ALIGN_TOP_LEFT,-10, 22+15);

    Set_s_label_v = lv_label_create(bt);
    lv_obj_set_style_text_font(Set_s_label_v, &lv_font_montserrat_10, 00);
    lv_label_set_text_fmt(Set_s_label_v, "%d", lv_slider_get_value(Set_slider_s));
    lv_obj_align(Set_s_label_v, LV_ALIGN_TOP_RIGHT, 0, 26+15);

    lv_obj_t* Set_s_btn = lv_btn_create(bt);
    lv_obj_set_size(Set_s_btn, 10, 14);
    lv_obj_set_style_radius(Set_s_btn, 0, 0);
    lv_obj_set_style_bg_color(Set_s_btn, lv_color_hex(0x808A87), 0);
    lv_obj_align(Set_s_btn, LV_ALIGN_TOP_MID, -15, 24+15);
    //按键
    /*

    lv_obj_t* Set_chonse_label = lv_label_create(Set_chonse_btn);
    lv_label_set_text(Set_chonse_label, "day");
    lv_obj_center(Set_chonse_label);*/

    //年
    Set_slider_y = lv_slider_create(bt);
    lv_obj_set_size(Set_slider_y, 50, 14);
    lv_slider_set_range(Set_slider_y, 0, 60);
			  //获取快捷设置时间
	  //lv_slider_set_value(Set_slider_y,calendar.year,LV_ANIM_ON);
    lv_obj_align(Set_slider_y, LV_ALIGN_TOP_RIGHT, -20, 41+15);
    lv_obj_t* Set_y_label = lv_label_create(bt);
    lv_obj_set_style_opa(Set_slider_y, 0, LV_PART_KNOB);
    lv_obj_set_style_radius(Set_slider_y, 0, LV_PART_MAIN);
    lv_obj_set_style_radius(Set_slider_y, 0, LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(Set_slider_y, lv_color_hex(0x808a87), LV_PART_INDICATOR);

    lv_obj_add_event_cb(Set_slider_y, Set_h_Handler, LV_EVENT_ALL, NULL);

    //lv_obj_set_style_text_font(Set_y_label, &lv_font_montserrat_10, 0);
		lv_obj_set_style_text_font(Set_y_label,&HZ,0);
    if(Language_Flag==0) lv_label_set_text(Set_y_label, "年,");
		else if(Language_Flag==1) {
			lv_obj_set_style_text_font(Set_y_label,&lv_font_montserrat_16,0);
			lv_label_set_text(Set_y_label, "Year");
		}
    lv_obj_align(Set_y_label, LV_ALIGN_TOP_LEFT, -10, 39+15);

    Set_y_label_v = lv_label_create(bt);
    lv_obj_set_style_text_font(Set_y_label_v, &lv_font_montserrat_10, 0);
    lv_label_set_text_fmt(Set_y_label_v, "%d", 2000+lv_slider_get_value(Set_slider_y));
    lv_obj_align(Set_y_label_v, LV_ALIGN_TOP_RIGHT, 10, 43+15);

    lv_obj_t* Set_y_btn = lv_btn_create(bt);
    lv_obj_set_size(Set_y_btn, 10, 14);
    lv_obj_set_style_radius(Set_y_btn, 0, 0);
    lv_obj_set_style_bg_color(Set_y_btn, lv_color_hex(0x808A87), 0);
    lv_obj_align(Set_y_btn, LV_ALIGN_TOP_MID, -15, 41+15);
    //月
    Set_slider_mo = lv_slider_create(bt);
    lv_obj_set_size(Set_slider_mo, 50, 14);
    lv_slider_set_range(Set_slider_mo, 0, 12);
			  //获取快捷设置时间
	  //lv_slider_set_value(Set_slider_mo,calendar.month,LV_ANIM_ON);
    lv_obj_align(Set_slider_mo, LV_ALIGN_TOP_RIGHT, -20, 58+15);
    lv_obj_t* Set_mo_label = lv_label_create(bt);
    lv_obj_set_style_opa(Set_slider_mo, 0, LV_PART_KNOB);
    lv_obj_set_style_radius(Set_slider_mo, 0, LV_PART_MAIN);
    lv_obj_set_style_radius(Set_slider_mo, 0, LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(Set_slider_mo, lv_color_hex(0x808a87), LV_PART_INDICATOR);

    lv_obj_add_event_cb(Set_slider_mo, Set_h_Handler, LV_EVENT_ALL, NULL);

    //lv_obj_set_style_text_font(Set_mo_label, &lv_font_montserrat_10, 0);
		lv_obj_set_style_text_font(Set_mo_label,&HZ,0);
    if(Language_Flag==0) lv_label_set_text(Set_mo_label, "月,");
		else if(Language_Flag==1) {
			lv_obj_set_style_text_font(Set_mo_label,&lv_font_montserrat_16,0);
			lv_label_set_text(Set_mo_label, "Month");
		}
    lv_obj_align(Set_mo_label, LV_ALIGN_TOP_LEFT, -10, 56+15);

    Set_mo_label_v = lv_label_create(bt);
    lv_obj_set_style_text_font(Set_mo_label_v, &lv_font_montserrat_10, 0);
    lv_label_set_text_fmt(Set_mo_label_v, "%d", lv_slider_get_value(Set_slider_mo));
    lv_obj_align(Set_mo_label_v, LV_ALIGN_TOP_RIGHT, 10, 60+15);

    lv_obj_t* Set_mo_btn = lv_btn_create(bt);
    lv_obj_set_size(Set_mo_btn, 10, 14);
    lv_obj_set_style_radius(Set_mo_btn, 0, 0);
    lv_obj_set_style_bg_color(Set_mo_btn, lv_color_hex(0x808A87), 0);
    lv_obj_align(Set_mo_btn, LV_ALIGN_TOP_MID, -15, 58+15);
    //日
    Set_slider_d = lv_slider_create(bt);
    lv_obj_set_size(Set_slider_d, 50, 14);
    lv_slider_set_range(Set_slider_d, 0, 31);
			  //获取快捷设置时间
	  //lv_slider_set_value(Set_slider_d,calendar.date,LV_ANIM_ON);
    lv_obj_align(Set_slider_d, LV_ALIGN_TOP_RIGHT, -20, 75+15);
    lv_obj_t* Set_d_label = lv_label_create(bt);
    lv_obj_set_style_opa(Set_slider_d, 0, LV_PART_KNOB);
    lv_obj_set_style_radius(Set_slider_d, 0, LV_PART_MAIN);
    lv_obj_set_style_radius(Set_slider_d, 0, LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(Set_slider_d, lv_color_hex(0x808a87), LV_PART_INDICATOR);

    lv_obj_add_event_cb(Set_slider_d, Set_h_Handler, LV_EVENT_ALL, NULL);
    //lv_timer_set_repeat_count
    //lv_obj_set_style_text_font(Set_d_label, &lv_font_montserrat_10, 0);
		lv_obj_set_style_text_font(Set_d_label,&HZ,0);
    if(Language_Flag==0) lv_label_set_text(Set_d_label, "日,");
		else if(Language_Flag==1) {
			lv_obj_set_style_text_font(Set_d_label,&lv_font_montserrat_16,0);
			lv_label_set_text(Set_d_label, "Date");
		}
    lv_obj_align(Set_d_label, LV_ALIGN_TOP_LEFT, -10, 73+15);

    Set_d_label_v = lv_label_create(bt);
    lv_obj_set_style_text_font(Set_d_label_v, &lv_font_montserrat_10, 0);
    lv_label_set_text_fmt(Set_d_label_v, "%d", lv_slider_get_value(Set_slider_d));
    lv_obj_align(Set_d_label_v, LV_ALIGN_TOP_RIGHT, 10, 77+15);

    lv_obj_t* Set_d_btn = lv_btn_create(bt);
    lv_obj_set_size(Set_d_btn, 10, 14);
    lv_obj_set_style_radius(Set_d_btn, 0, 0);
    lv_obj_set_style_bg_color(Set_d_btn, lv_color_hex(0x808A87), 0);
    lv_obj_align(Set_d_btn, LV_ALIGN_TOP_MID, -15, 75+15);
    //创建一个设置时间设置按键
    lv_obj_t* Set_true_btn = lv_btn_create(bt);

    lv_obj_set_size(Set_true_btn, 140, 23);
    lv_obj_set_style_radius(Set_true_btn, 0, 0);
    lv_obj_set_style_bg_color(Set_true_btn, lv_color_hex(0x808A87), 0);
    lv_obj_align(Set_true_btn, LV_ALIGN_BOTTOM_MID, 0, 80+15);
    Set_true_label = lv_label_create(Set_true_btn);
		lv_obj_set_style_text_font(Set_true_label,&HZ,0);
    if(Language_Flag==0) lv_label_set_text(Set_true_label, "<设置>");
		else if(Language_Flag==1) lv_label_set_text(Set_true_label, "<Set>");
    lv_obj_center(Set_true_label);
    lv_obj_add_event_cb(Set_true_btn, Set_true_handler, LV_EVENT_ALL, NULL);

}
/*
void LV_Slider_set_label(lv_obj_t* bt,lv_obj_t* mou,lv_obj_t* set_label, lv_coord_t new_x, int32_t range_v,)
{
    mou = lv_slider_create(bt);
    lv_obj_set_size(mou, 50, 10);
    lv_slider_set_range(mou, 0, range_v);
    lv_obj_align(mou, LV_ALIGN_TOP_RIGHT, -20, new_x);
    set_label = lv_label_create(bt);
    lv_obj_set_style_opa(mou, 0, LV_PART_KNOB);
    lv_obj_set_style_radius(mou, 0, LV_PART_MAIN);
    lv_obj_set_style_radius(mou, 0, LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(mou, lv_color_hex(0x808a87), LV_PART_INDICATOR);

    lv_obj_add_event_cb(mou, Set_h_Handler, LV_EVENT_ALL, NULL);

    lv_obj_set_style_text_font(set_label, &lv_font_montserrat_10, 0);
    lv_label_set_text(set_label, "Hour");
    lv_obj_align(set_label, LV_ALIGN_TOP_LEFT, 0, new_x);

    Set_h_label_v = lv_label_create(bt);
    lv_obj_set_style_text_font(Set_h_label_v, &lv_font_montserrat_10, 0);
    lv_label_set_text_fmt(Set_h_label_v, "%d", lv_slider_get_value(mou));
    lv_obj_align(Set_h_label_v, LV_ALIGN_TOP_RIGHT, 0, new_x);


}
*/
/*函数：static void LV_SW_Handler(lv_event_t* e)
*作者：小夏
*形参：lv_event_t* e
*描述：lv_obj_add_event_cb(Set_Switch,LV_SW_Handler,LV_EVENT_ALL,NULL);
       的事件执行函数
			 语言的开关控件功能
*修改时间：2022/9/20
*修改内容：无
*/
static void LV_SW_Handler(lv_event_t* e)
{
    lv_event_code_t vscode = lv_event_get_code(e);

    if (vscode == LV_EVENT_VALUE_CHANGED) {
        Sw_Flag++;
        if (Sw_Flag >= 2) Sw_Flag = 0;
        if (Sw_Flag==1) {
            lv_label_set_text_fmt(Set_sw_label_v, "C");
            Language_Flag = 0;
        }
        else {
            lv_label_set_text_fmt(Set_sw_label_v, "E");
           Language_Flag = 1;
        }
				
				sprintf(Language_buff,"%d",Language_Flag);
				W25QXX_Write(Language_buff,Language_Flag_Addr,sizeof(Language_buff));
    }

}
/*函数：static void LV_Set_Display_switch(lv_obj_t* sw)
*作者：小夏
*形参：lv_obj_t* sw
*描述：语言设置控件绘制
*修改时间：2022/9/20
*修改内容：无
*/
static void LV_Set_Display_switch(lv_obj_t* sw)
{
    lv_obj_t* Set_Switch = lv_switch_create(sw);
    lv_obj_t* Set_Switch_label = lv_label_create(sw);
    //开关
    lv_obj_set_style_radius(Set_Switch, 0, LV_PART_MAIN);
    lv_obj_set_style_radius(Set_Switch, 0, LV_PART_INDICATOR);
    lv_obj_set_style_radius(Set_Switch, 0, LV_PART_KNOB);
    //lv_obj_set_style_size(Set_Switch,15,10,LV_PART_KNOB);
    lv_obj_set_size(Set_Switch, 30, 10);
    lv_obj_align(Set_Switch,LV_ALIGN_TOP_RIGHT,-20,123+15);
    lv_obj_add_event_cb(Set_Switch,LV_SW_Handler,LV_EVENT_ALL,NULL);
    //标签
    lv_obj_set_style_text_font(Set_Switch_label, &lv_font_montserrat_10, 0);
    lv_label_set_text(Set_Switch_label, "Language");
    lv_obj_align(Set_Switch_label, LV_ALIGN_TOP_LEFT, -10, 125+15);
    //按键方块
    lv_obj_t* Set_sw_btn = lv_btn_create(sw);
    lv_obj_set_size(Set_sw_btn, 10, 10);
    lv_obj_set_style_radius(Set_sw_btn, 0, 0);
    lv_obj_set_style_bg_color(Set_sw_btn, lv_color_hex(0x808A87), 0);
    lv_obj_align(Set_sw_btn, LV_ALIGN_TOP_MID, 0,123+15);
    //开关指示标签
    Set_sw_label_v = lv_label_create(sw);
    lv_obj_set_style_text_font(Set_sw_label_v, &lv_font_montserrat_10, 0);
    lv_label_set_text_fmt(Set_sw_label_v, "E");
    lv_obj_align(Set_sw_label_v, LV_ALIGN_TOP_RIGHT, 10, 123+15);
}
/*函数：static void LV_SW_BG_Handler(lv_event_t* e)
*作者：小夏
*形参：lv_event_t* e
*描述：lv_obj_add_event_cb(Set_Switch_bg, LV_SW_BG_Handler, LV_EVENT_ALL, NULL);
       的执行函数
			 界面一的背景图片设置
*修改时间：2022/9/20
*修改内容：无
*/
static void LV_SW_BG_Handler(lv_event_t* e)
{
    lv_event_code_t vscode = lv_event_get_code(e);
    if (vscode== LV_EVENT_VALUE_CHANGED) {
        Sw_Bg_Flag++;
        if (Sw_Bg_Flag >= 2) Sw_Bg_Flag = 0;
        if (Sw_Bg_Flag == 0) {
            lv_label_set_text_fmt(Set_sw_label_bg, "PAF");
            Bg_Flag = 0;
            
        }
        else if (Sw_Bg_Flag == 1) {
            lv_label_set_text_fmt(Set_sw_label_bg, "TS");
            Bg_Flag = 1;
            
        }
        sprintf(Background_buff,"%d",Bg_Flag);
				W25QXX_Write(Background_buff,Background_Flag_Addr,sizeof(Background_buff));
        
    }


}
/*函数：static void LV_Set_Display_switch_bg(lv_obj_t* b)
*作者：小夏
*形参：lv_obj_t* b
*描述：界面一背景图片设置控件绘制
*修改时间：2022/9/20
*修改内容：无
*/
static void LV_Set_Display_switch_bg(lv_obj_t* b)
{
    lv_obj_t* Set_Switch_bg = lv_switch_create(b);
    lv_obj_t* Set_Switch_label_bg = lv_label_create(b);
    //开关
    lv_obj_set_style_radius(Set_Switch_bg, 0, LV_PART_MAIN);
    lv_obj_set_style_radius(Set_Switch_bg, 0, LV_PART_INDICATOR);
    lv_obj_set_style_radius(Set_Switch_bg, 0, LV_PART_KNOB);
    //lv_obj_set_style_size(Set_Switch_bg, 15, 10, LV_PART_KNOB);
    lv_obj_set_size(Set_Switch_bg, 30, 10);
    lv_obj_align(Set_Switch_bg, LV_ALIGN_TOP_RIGHT, -20, 123+15+15);
    lv_obj_add_event_cb(Set_Switch_bg, LV_SW_BG_Handler, LV_EVENT_ALL, NULL);
    //标签
    lv_obj_set_style_text_font(Set_Switch_label_bg, &lv_font_montserrat_10, 0);
    lv_label_set_text(Set_Switch_label_bg, "background");
    lv_obj_align(Set_Switch_label_bg, LV_ALIGN_TOP_LEFT, -10, 123+15+15);
    //按键方块
    lv_obj_t* Set_sw_btn_bg = lv_btn_create(b);
    lv_obj_set_size(Set_sw_btn_bg, 10, 10);
    lv_obj_set_style_radius(Set_sw_btn_bg, 0, 0);
    lv_obj_set_style_bg_color(Set_sw_btn_bg, lv_color_hex(0x808A87), 0);
    lv_obj_align(Set_sw_btn_bg, LV_ALIGN_TOP_MID, 0, 123+15+15);
    //开关指示标签
    Set_sw_label_bg = lv_label_create(b);
    lv_obj_set_style_text_font(Set_sw_label_bg, &lv_font_montserrat_10, 0);
    lv_label_set_text_fmt(Set_sw_label_bg, "PAF");
    lv_obj_align(Set_sw_label_bg, LV_ALIGN_TOP_RIGHT, 10, 123+15+15);
    

}

/*函数：static void LV_Set_Display_switch_bg(lv_obj_t* b)
*作者：小夏
*形参：lv_obj_t* b
*描述：lv_obj_add_event_cb(Set_Switch_ro, LV_SW_RO_Handler, LV_EVENT_ALL, NULL);
			 的事件执行函数
旋转界面，注意每次旋转需要重启开发板。不然没有旋转效果。
*修改时间：2022/10/27
*修改内容：无
*/
static void LV_SW_RO_Handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_VALUE_CHANGED) {
        Ro_Flag++;
        if (Ro_Flag >= 2) Ro_Flag = 0;
        if (Ro_Flag == 0) {
            lv_label_set_text_fmt(Set_sw_label_ro, "180");
						sprintf(LCD_Write_RO_Buff,"%d",3);
						W25QXX_Write(LCD_Write_RO_Buff,1024*1024*135,sizeof(LCD_Write_RO_Buff));
						
        }
        else if (Ro_Flag == 1) {
            lv_label_set_text_fmt(Set_sw_label_ro, "360");
          	sprintf(LCD_Write_RO_Buff,"%d",2);
						W25QXX_Write(LCD_Write_RO_Buff,1024*1024*135,sizeof(LCD_Write_RO_Buff));
						
        }
				
    }

}
/*函数：static void LV_Set_Display_switch_ro(lv_obj_t* b)
*作者：小夏
*形参：lv_obj_t* b
*描述：旋转设置控件绘制
*修改时间：2022/10/27
*修改内容：无
*/
static void LV_Set_Display_switch_ro(lv_obj_t* b)
{
    lv_obj_t* Set_Switch_ro = lv_switch_create(b);
    lv_obj_t* Set_Switch_label_ro = lv_label_create(b);
    //开关
    lv_obj_set_style_radius(Set_Switch_ro, 0, LV_PART_MAIN);
    lv_obj_set_style_radius(Set_Switch_ro, 0, LV_PART_INDICATOR);
    lv_obj_set_style_radius(Set_Switch_ro, 0, LV_PART_KNOB);
    //lv_obj_set_style_size(Set_Switch_bg, 15, 10, LV_PART_KNOB);
    lv_obj_set_size(Set_Switch_ro, 30, 10);
    lv_obj_align(Set_Switch_ro, LV_ALIGN_TOP_RIGHT, -20, 123 + 30+15);
    lv_obj_add_event_cb(Set_Switch_ro, LV_SW_RO_Handler, LV_EVENT_ALL, NULL);
    //标签
    lv_obj_set_style_text_font(Set_Switch_label_ro, &lv_font_montserrat_10, 0);
    lv_label_set_text(Set_Switch_label_ro, "rotating");
    lv_obj_align(Set_Switch_label_ro, LV_ALIGN_TOP_LEFT, -10, 123 + 30+15);
    //按键方块
    lv_obj_t* Set_sw_btn_ro = lv_btn_create(b);
    lv_obj_set_size(Set_sw_btn_ro, 10, 10);
    lv_obj_set_style_radius(Set_sw_btn_ro, 0, 0);
    lv_obj_set_style_bg_color(Set_sw_btn_ro, lv_color_hex(0x808A87), 0);
    lv_obj_align(Set_sw_btn_ro, LV_ALIGN_TOP_MID, 0, 123 + 30+15);
    //开关指示标签
    Set_sw_label_ro = lv_label_create(b);
    lv_obj_set_style_text_font(Set_sw_label_ro, &lv_font_montserrat_10, 0);
    lv_label_set_text_fmt(Set_sw_label_ro, "180");
    lv_obj_align(Set_sw_label_ro, LV_ALIGN_TOP_RIGHT, 10, 123 + 30+15);


}
/*******************************************************************************************************************

                                               更新时间2022.10.29

*******************************************************************************************************************/
/*函数：static void LV_SW_Wrod_Handler(lv_event_t* e)
*作者：小夏
*形参：lv_event_t* e
*描述：lv_obj_add_event_cb(Set_Switch_Wrod, LV_SW_Wrod_Handler, LV_EVENT_ALL, NULL);
*      的事件执行函数
*      单词切换功能
*修改时间：2022/10/29
*修改内容：无
*/

static void LV_SW_Wrod_Handler(lv_event_t* e)
{
		lv_event_code_t code =lv_event_get_code(e);
		if(code ==LV_EVENT_VALUE_CHANGED)
		{
			 Wrod_Flag++;
       if (Wrod_Flag >= 2) Wrod_Flag = 0;
			  if (Wrod_Flag == 0) {
            lv_label_set_text_fmt(Set_sw_label_Wrod, "FLW");
						sprintf(LV_W_Wrod_Buff,"%d",1);
						W25QXX_Write(LV_W_Wrod_Buff,1024*1024*100,sizeof(LV_W_Wrod_Buff));
						Wrod_Ch_Flag =1;
        }
        else if (Wrod_Flag == 1) {
            lv_label_set_text_fmt(Set_sw_label_Wrod, "SOW");
          	sprintf(LV_W_Wrod_Buff,"%d",2);
						W25QXX_Write(LV_W_Wrod_Buff,1024*1024*100,sizeof(LV_W_Wrod_Buff));
						Wrod_Ch_Flag =2;
        }
							
			
		}

}

/*函数：static void LV_Set_Display_switch_Wrod(lv_obj_t* b)
*作者：小夏
*形参：lv_obj_t* b
*描述：单词切换开关绘制 
*修改时间：2022/10/29
*修改内容：无
*/
static void LV_Set_Display_switch_Wrod(lv_obj_t* b)
{
    lv_obj_t* Set_Switch_Wrod = lv_switch_create(b);
    lv_obj_t* Set_Switch_label_Wrod = lv_label_create(b);
    //开关
    lv_obj_set_style_radius(Set_Switch_Wrod, 0, LV_PART_MAIN);
    lv_obj_set_style_radius(Set_Switch_Wrod, 0, LV_PART_INDICATOR);
    lv_obj_set_style_radius(Set_Switch_Wrod, 0, LV_PART_KNOB);
    //lv_obj_set_style_size(Set_Switch_bg, 15, 10, LV_PART_KNOB);
    lv_obj_set_size(Set_Switch_Wrod, 30, 10);
    lv_obj_align(Set_Switch_Wrod, LV_ALIGN_TOP_RIGHT, -20, 123 + 45+15);
    lv_obj_add_event_cb(Set_Switch_Wrod, LV_SW_Wrod_Handler, LV_EVENT_ALL, NULL);
    //标签
    lv_obj_set_style_text_font(Set_Switch_label_Wrod, &lv_font_montserrat_10, 0);
    lv_label_set_text(Set_Switch_label_Wrod, "Word");
    lv_obj_align(Set_Switch_label_Wrod, LV_ALIGN_TOP_LEFT, -10, 123 + 45+15);
    //按键方块
    lv_obj_t* Set_sw_btn_Wrod = lv_btn_create(b);
    lv_obj_set_size(Set_sw_btn_Wrod, 10, 10);
    lv_obj_set_style_radius(Set_sw_btn_Wrod, 0, 0);
    lv_obj_set_style_bg_color(Set_sw_btn_Wrod, lv_color_hex(0x808A87), 0);
    lv_obj_align(Set_sw_btn_Wrod, LV_ALIGN_TOP_MID, 0, 123 + 45+15);
    //开关指示标签
    Set_sw_label_Wrod = lv_label_create(b);
    lv_obj_set_style_text_font(Set_sw_label_Wrod, &lv_font_montserrat_10, 0);
    lv_label_set_text_fmt(Set_sw_label_Wrod, "FLW");
    lv_obj_align(Set_sw_label_Wrod, LV_ALIGN_TOP_RIGHT, 10, 123 + 45+15);


}

/*******************************************************************************************************************

                                               更新时间2022.11.17

*******************************************************************************************************************/
/*函数：static void LV_SW_Wrod_Handler(lv_event_t* e)
*作者：小夏
*形参：lv_event_t* e
*描述：lv_obj_add_event_cb(Set_Switch_Wrod, LV_SW_Wrod_Handler, LV_EVENT_ALL, NULL);
 *      的事件执行函数
*     单词切换功能
*修改时间：2022/10/29
*修改内容：无
*/

static void lv_spinbox_increment_event_cb(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT) {
        lv_spinbox_decrement(spinbox);
				Vol_Value=lv_spinbox_get_value(spinbox);
			  sprintf(power_cp,"%d",Vol_Value);
			  W25QXX_Write(power_cp,1024*1024*141,sizeof(power_cp));
    }
}

static void lv_spinbox_decrement_event_cb(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT) {
        
			lv_spinbox_increment(spinbox);
			Vol_Value=lv_spinbox_get_value(spinbox);
			sprintf(power_cp,"%d",Vol_Value);
			W25QXX_Write(power_cp,1024*1024*141,sizeof(power_cp));
    }
}

void LV_Set_Power_prompt(lv_obj_t* b) {
    //标签

    lv_obj_t* Set_Switch_label_prompt = lv_label_create(b);
    lv_obj_set_style_text_font(Set_Switch_label_prompt, &lv_font_montserrat_10, 0);
    lv_label_set_text(Set_Switch_label_prompt, "Prower Set");
    lv_obj_align(Set_Switch_label_prompt, LV_ALIGN_TOP_MID, 0, 123 + 60+15);
    //主体
    spinbox = lv_spinbox_create(b);
    lv_spinbox_set_range(spinbox, 0, 450);
    lv_spinbox_set_digit_format(spinbox, 3, 1);
    lv_spinbox_step_prev(spinbox);
    lv_obj_set_size(spinbox,55,30);
    lv_obj_align(spinbox, LV_ALIGN_TOP_MID, 0, 123 + 75+15);
    
	  //W25Q128写入报警电压（然后进入Timer定时器里面循环检测）
	  
    lv_spinbox_set_value(spinbox,Vol_Value);//设置数
    
 
   	lv_obj_t* btn = lv_btn_create(b);
    lv_obj_set_size(btn, 30, 30);
    lv_obj_align_to(btn, spinbox, LV_ALIGN_OUT_LEFT_MID, -5, 0);
    lv_obj_set_style_bg_img_src(btn, LV_SYMBOL_PLUS, 0);
		lv_obj_set_style_bg_color(btn, lv_color_hex(0x808A87), 0);
    lv_obj_add_event_cb(btn, lv_spinbox_decrement_event_cb, LV_EVENT_ALL, NULL);
		
		btn = lv_btn_create(b);
    lv_obj_set_size(btn, 30,30);
    lv_obj_align_to(btn, spinbox, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_obj_set_style_bg_img_src(btn, LV_SYMBOL_MINUS, 0);
		lv_obj_set_style_bg_color(btn, lv_color_hex(0x808A87), 0);
    lv_obj_add_event_cb(btn, lv_spinbox_increment_event_cb, LV_EVENT_ALL, NULL);
   
}