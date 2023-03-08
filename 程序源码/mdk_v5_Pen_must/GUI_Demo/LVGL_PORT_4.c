#include "LVGL_PORT_4.h"
#include "LVGL_PORT_2.h"
#include "LVGL_Main.h"
#include "ws2812b.h"
#include "FreeRTOS.h"
#include "task.h"
#include "Timers.h"


lv_obj_t* rgb_btn;
lv_obj_t* rgb_slider_1;

lv_obj_t* r_btn;
lv_obj_t* g_btn;
lv_obj_t* b_btn;

lv_obj_t* PORT_4_Back_btn;

struct RGB_FLAG rgb;
struct RGB_Value rgbv;
/*函数：static void LV_RGB_Handler(lv_event_t* e)
*作者：小夏
*形参：lv_event_t* e
*描述：lv_obj_add_event_cb(rgb_btn,LV_RGB_Handler,LV_EVENT_ALL,NULL);
			 的事件处理函数
			 按键颜色和控制RGB（WS2812B）灯亮灭和调色FLAG。
*修改时间：2022/9/20
*修改内容：无
*/
static void LV_RGB_Handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_CLICKED) {
        rgb.RGB_Btn_Flag += 1;
			  if(rgb.RGB_Btn_Flag >=4){
					rgb.RGB_Btn_Flag = 1;
				}
				if(rgb.RGB_Btn_Flag==3) {															
				  rgb.RGB_Exti_Flag = 0;
					time.Timer_Start_Stop_Flag=0;					
					lv_obj_set_style_bg_color(rgb_btn, lv_color_hex(0xff00ff), 0);  
				}
				
        if (rgb.RGB_Btn_Flag==2) {
            //rgb.RGB_Btn_Flag = 0;
            rgb.RGB_Exti_Flag = 0;
					  time.Timer_Start_Stop_Flag=0;
						RGB_Write_ALL(0x00,0x00,0x00);
            lv_obj_set_style_bg_color(rgb_btn, lv_color_hex(0x4169E1), 0);         
        }
		
        if (rgb.RGB_Btn_Flag == 1) {
            rgb.RGB_Exti_Flag = 1;
					  rgb.RGB_Flick_FLAG= 0;
						RGB_Write_ALL(0xff,0xff,0xff);
					  
						lv_slider_set_value(rgb_slider_1,255,0);
            lv_obj_set_style_bg_color(rgb_btn, lv_color_hex(0x00fffb), 0);
        }

    }

}
/*函数：void LV_RGB_Display_btn(lv_obj_t* colors)
*作者：小夏
*形参：lv_obj_t* colors
*描述：绘制RGB灯按键开关图形
*修改时间：2022/9/20
*修改内容：无
*/
void LV_RGB_Display_btn(lv_obj_t* colors)
{
    rgb_btn = lv_btn_create(colors);
    lv_obj_set_size(rgb_btn, 40, 40);
    lv_obj_align(rgb_btn, LV_ALIGN_LEFT_MID, -5, 5);
    lv_obj_set_style_bg_color(rgb_btn,lv_color_hex(0x4169E1),0);
    lv_obj_set_style_radius(rgb_btn, 20, LV_PART_MAIN);
    lv_obj_t* rgb_label = lv_label_create(rgb_btn);
    lv_obj_set_style_text_font(rgb_label, &lv_font_montserrat_28, 0);
    lv_label_set_text(rgb_label,LV_SYMBOL_POWER);  
    lv_obj_center(rgb_label);
    lv_obj_add_event_cb(rgb_btn,LV_RGB_Handler,LV_EVENT_ALL,NULL);
}
/*函数：static void LV_RGB_CHO_Handler(lv_event_t* e)
*作者：小夏
*形参：lv_event_t* e
*描述：lv_obj_add_event_cb(r_btn,LV_RGB_CHO_Handler,LV_EVENT_ALL,NULL);
			 lv_obj_add_event_cb(g_btn, LV_RGB_CHO_Handler, LV_EVENT_ALL, NULL);
			 lv_obj_add_event_cb(b_btn, LV_RGB_CHO_Handler, LV_EVENT_ALL, NULL);
			 的事件处理函数。
       控制按键开关的按下颜色转换
*修改时间：2022/9/20
*修改内容：无
*/
static void LV_RGB_CHO_Handler(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* NAME = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED) {
        if (rgb.RGB_Exti_Flag == 1) {
            if (NAME == r_btn) {
								rgb.RGB_CHO_FLAG=0;
                lv_obj_set_style_bg_color(rgb_slider_1, lv_color_hex(0xff0000), LV_PART_INDICATOR);
            }
            if (NAME == g_btn) {
								rgb.RGB_CHO_FLAG=1;
                lv_obj_set_style_bg_color(rgb_slider_1, lv_color_hex(0x00ff00), LV_PART_INDICATOR);
            }
            if (NAME == b_btn) {
								rgb.RGB_CHO_FLAG=2;
                lv_obj_set_style_bg_color(rgb_slider_1, lv_color_hex(0x0000ff), LV_PART_INDICATOR);
            }
            LV_LOG_USER("RGB=%d\n", rgb.RGB_CHO_FLAG);
        }
    }

}
/*函数：void LV_RGB_Display_Cor(lv_obj_t* colors)
*作者：小夏
*形参：lv_obj_t* colors
*描述：R，G，B三个按键绘制
*修改时间：2022/9/20
*修改内容：无
*/
void LV_RGB_Display_Cor(lv_obj_t* colors) {
    r_btn = lv_btn_create(colors);
    g_btn = lv_btn_create(colors);
    b_btn = lv_btn_create(colors);

    lv_obj_set_size(r_btn,30,15);
    lv_obj_set_size(g_btn, 30, 15);
    lv_obj_set_size(b_btn, 30, 15);

    lv_obj_set_style_bg_color(r_btn,lv_color_hex(0xff0000),0);
    lv_obj_set_style_bg_color(g_btn, lv_color_hex(0x00ff00), 0);
    lv_obj_set_style_bg_color(b_btn, lv_color_hex(0x0000ff), 0);

    lv_obj_align(r_btn,LV_ALIGN_TOP_MID,-5,0);
    lv_obj_align(g_btn, LV_ALIGN_CENTER, -5, 5);
    lv_obj_align(b_btn, LV_ALIGN_BOTTOM_MID, -5, 10);

    lv_obj_t* r_label = lv_label_create(r_btn);
    lv_obj_t* g_label = lv_label_create(g_btn);
    lv_obj_t* b_label = lv_label_create(b_btn);

    lv_label_set_text(r_label, "R");
    lv_label_set_text(g_label, "G");
    lv_label_set_text(b_label, "B");

    lv_obj_center(r_label);
    lv_obj_center(g_label);
    lv_obj_center(b_label);

    lv_obj_add_event_cb(r_btn,LV_RGB_CHO_Handler,LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(g_btn, LV_RGB_CHO_Handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(b_btn, LV_RGB_CHO_Handler, LV_EVENT_ALL, NULL);
}

/*函数：LV_RGB_Display_Red_Slider(lv_obj_t* colors)
*作者：小夏
*形参：lv_obj_t* colors
*描述：R，G，B的slider滑动条绘制
*修改时间：2022/9/20
*修改内容：无
*/
void LV_RGB_Display_Red_Slider(lv_obj_t* colors) {
    //rgb_timer = lv_timer_create(My_RGB_Timer, 100, NULL);
    rgb_slider_1 = lv_slider_create(colors);
    lv_obj_set_size(rgb_slider_1, 40,60);
    lv_slider_set_range(rgb_slider_1, 0, 25);
    lv_obj_set_style_bg_color(rgb_slider_1, lv_color_hex(0x8B4513), LV_PART_MAIN);
    lv_obj_set_style_bg_color(rgb_slider_1, lv_color_hex(0xff0000), LV_PART_INDICATOR);
    //lv_obj_set_style_opa(rgb_slider_1, 100, LV_PART_MAIN);
    lv_obj_set_style_opa(rgb_slider_1, 0, LV_PART_KNOB);
    lv_obj_align(rgb_slider_1,LV_ALIGN_RIGHT_MID,0,5);
    lv_obj_set_style_radius(rgb_slider_1,5,LV_PART_MAIN);
    lv_obj_set_style_radius(rgb_slider_1, 0, LV_PART_INDICATOR);
}
/*函数：static void PORT_4_Back_btn_Handler(lv_event_t* param)
*作者：小夏
*形参：lv_event_t* param
*描述：lv_obj_add_event_cb(PORT_4_Back_btn, PORT_4_Back_btn_Handler, LV_EVENT_ALL, NULL);
			 的事件处理函数
       返回退出按键功能
*修改时间：2022/9/20
*修改内容：无
*/
static void PORT_4_Back_btn_Handler(lv_event_t* param) {

    lv_event_code_t vscode = lv_event_get_code(param);
    lv_obj_t* mune = lv_event_get_target(param);

    if (vscode == LV_EVENT_CLICKED) {
        if (mune == PORT_4_Back_btn) {

            lv_obj_del(obj_5);
        }
        LV_Menu_Init();

    }
}
/*函数：void LV_PORT_4_Back_btn(lv_obj_t* one) 
*作者：小夏
*形参：lv_obj_t* one
*描述：退出按键的绘制
*修改时间：2022/9/20
*修改内容：无
*/
void LV_PORT_4_Back_btn(lv_obj_t* one) {
    PORT_4_Back_btn = lv_btn_create(one);
    lv_obj_set_size(PORT_4_Back_btn, 36, 12);
    lv_obj_set_style_radius(PORT_4_Back_btn, 5, 0);
    lv_obj_align(PORT_4_Back_btn, LV_ALIGN_TOP_LEFT, -13, -13);
    lv_obj_set_style_bg_color(PORT_4_Back_btn, lv_color_hex(0x808A87), LV_PART_MAIN);
    lv_obj_t* Back_label = lv_label_create(PORT_4_Back_btn);
    lv_label_set_recolor(Back_label, true);
    lv_label_set_text(Back_label, "#000000 <#");
    lv_obj_center(Back_label);

    lv_obj_add_event_cb(PORT_4_Back_btn, PORT_4_Back_btn_Handler, LV_EVENT_ALL, NULL);
}
