#include "LVGL_PORT_1.h"
#include "LVGL_Main.h"
#include "RTC.h"
/*************************************************************主要写每个菜单的任务*************************************************************/
//RTC时钟显示
lv_obj_t* Time_hour;
lv_obj_t* data;
lv_obj_t* Week;

lv_obj_t* Chunk;
lv_obj_t* Course_all;
lv_obj_t* Course_one;

lv_obj_t* PORT_2_Back_btn;

uint16_t Week_day;

uint8_t data_buff[48];
uint16_t data_buff_1[48];

LV_IMG_DECLARE(time_bg);
/*函数：void LV_Time_Display_BG(lv_obj_t* bgd)
*作者：小夏
*形参：lv_obj_t* bgd
*描述：背景图绘制
*修改时间：2022/9/20
*修改内容：无
*/
void LV_Time_Display_BG(lv_obj_t* bgd) {
    lv_obj_t* T_bg = lv_img_create(bgd);
    lv_img_set_src(T_bg,&time_bg);
    lv_obj_align(T_bg,LV_ALIGN_TOP_LEFT,-15,-15);
}
/*函数：uint8_t Data_Week(uint16_t year, uint8_t month, uint8_t day)
*作者：小夏
*形参：uint16_t year, uint8_t month, uint8_t day
*描述：基姆拉尔森公式。知道日期求星期
*修改时间：2022/9/20
*修改内容：无
*/
uint8_t Data_Week(uint16_t year, uint8_t month, uint8_t day)
{

    if (month == 1 | month == 2)
    {
        month += 12;
        year--;
    }
    uint8_t W = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
    switch (W)
    {
    case 0: return W = 0; break;
    case 1: return W = 1; break;
    case 2: return W = 2; break;
    case 3: return W = 3; break;
    case 4: return W = 4; break;
    case 5: return W = 5; break;
    case 6: return W = 6; break;
    }

}
/*函数：void RTC_Display_Time(uint8_t hour, uint8_t month, lv_obj_t* tim)
*作者：小夏
*形参：uint8_t hour, uint8_t month, lv_obj_t* tim
*描述：显示时间
*修改时间：2022/9/20
*修改内容：无
*/
void RTC_Display_Time(uint8_t hour, uint8_t month, lv_obj_t* tim)
{

    Time_hour = lv_label_create(tim);

    lv_obj_set_style_text_font(Time_hour, &lv_font_montserrat_28, 0);
    lv_label_set_long_mode(Time_hour, LV_LABEL_LONG_SCROLL_CIRCULAR); //字体滚动
    lv_obj_set_width(Time_hour, 75);

    lv_label_set_text_fmt(Time_hour, "%02d:%02d",hour,month);
    lv_obj_align(Time_hour, LV_ALIGN_LEFT_MID, -13, -13);

}
/*函数：void RTC_Display_Data(uint8_t year, uint8_t month, uint8_t day, lv_obj_t* na)
*作者：小夏
*形参：uint8_t year, uint8_t month, uint8_t day, lv_obj_t* na
*描述：显示日期
*修改时间：2022/9/20
*修改内容：无
*/

void RTC_Display_Data(uint8_t year, uint8_t month, uint8_t day, lv_obj_t* na)
{
    
   // sprintf(data_buff, "20%d-%d-%d", year, month, day);
   // lv_snprintf(data_buff, sizeof(data_buff), "20%d-%d-%d", year, month, day);
    data = lv_label_create(na);
    lv_obj_set_style_text_font(data, &lv_font_montserrat_14, 0);
    lv_label_set_text_fmt(data, "20%d-%d-%d",year, month, day);
    lv_obj_align(data, LV_ALIGN_LEFT_MID, -6, 8);
}
/*函数：void RTC_Display_Cyc_Data(uint16_t year, uint8_t month, uint8_t day)
*作者：小夏
*形参：uint16_t year, uint8_t month, uint8_t day
*描述：显示星期
*修改时间：2022/9/20
*修改内容：无
*/
void RTC_Display_Cyc_Data(uint16_t year, uint8_t month, uint8_t day) {
   
   

    
    lv_label_set_text_fmt(data, "%d-%d-%d", year, month, day);
    Week_day = Data_Week(year, month, day);
    switch (Week_day)
    {
    case 0:lv_label_set_text(Week, "Monday"); lv_obj_align(Week, LV_ALIGN_LEFT_MID, -2, 22); break;
    case 1:lv_label_set_text(Week, "Tuesday"); lv_obj_align(Week, LV_ALIGN_LEFT_MID, -2, 22); break;
    case 2:lv_label_set_text(Week, "Wednesday"); lv_obj_align(Week, LV_ALIGN_LEFT_MID, -13, 22); break;
    case 3:lv_label_set_text(Week, "Tursday"); lv_obj_align(Week, LV_ALIGN_LEFT_MID, -6, 22); break;
    case 4:lv_label_set_text(Week, "Friday"); lv_obj_align(Week, LV_ALIGN_LEFT_MID, -2, 22); break;
    case 5:lv_label_set_text(Week, "Saturday"); lv_obj_align(Week, LV_ALIGN_LEFT_MID, -6, 22); break;
    case 6:lv_label_set_text(Week, "Sunday"); lv_obj_align(Week, LV_ALIGN_LEFT_MID, -2, 22); break;
    }
 
}
/*函数：void RTC_Display_Week(uint16_t year, uint8_t month, uint8_t day, lv_obj_t* na)
*作者：小夏
*形参：uint16_t year, uint8_t month, uint8_t day, lv_obj_t* na
*描述：刷新星期
*修改时间：2022/9/20
*修改内容：无
*/
void RTC_Display_Week(uint16_t year, uint8_t month, uint8_t day, lv_obj_t* na)
{
    //uint16_t years=0;
    //years = year + 2000;

    Week_day = Data_Week(year, month, day);
    Week = lv_label_create(na);
    lv_obj_set_style_text_font(Week, &lv_font_montserrat_12, 0);
    switch (Week_day)
    {
    case 0:lv_label_set_text(Week, "Monday"); lv_obj_align(Week, LV_ALIGN_LEFT_MID, -2, 22); break;
    case 1:lv_label_set_text(Week, "Tuesday"); lv_obj_align(Week, LV_ALIGN_LEFT_MID, -2, 22); break;
    case 2:lv_label_set_text(Week, "Wednesday"); lv_obj_align(Week, LV_ALIGN_LEFT_MID, -13, 22); break;
    case 3:lv_label_set_text(Week, "Tursday"); lv_obj_align(Week, LV_ALIGN_LEFT_MID, -6, 22); break;
    case 4:lv_label_set_text(Week, "Friday"); lv_obj_align(Week, LV_ALIGN_LEFT_MID, -2, 22); break;
    case 5:lv_label_set_text(Week, "Saturday"); lv_obj_align(Week, LV_ALIGN_LEFT_MID, -6, 22); break;
    case 6:lv_label_set_text(Week, "Sunday"); lv_obj_align(Week, LV_ALIGN_LEFT_MID, -2, 22); break;
    }
}

/*函数：void RTC_Display_Course(lv_obj_t* na)
*作者：小夏
*形参：lv_obj_t* na
*描述：显示课表
*修改时间：2022/9/20
*修改内容：无
*/
void RTC_Display_Course(lv_obj_t* na) {
    Chunk = lv_obj_create(na);
    lv_obj_set_style_opa(Chunk, 200, 0);
    lv_obj_set_style_radius(Chunk, 5, 0);
    lv_obj_set_style_bg_color(Chunk, lv_color_hex(0xa9a9a9), LV_PART_MAIN);

    //lv_obj_clear_flag(Chunk, LV_OBJ_FLAG_SCROLL_CHAIN_HOR);//使对象不可滚动。
    lv_obj_set_size(Chunk, 82, 80);
    lv_obj_align(Chunk, LV_ALIGN_RIGHT_MID, 18, 0);


    Course_all = lv_label_create(Chunk);
    lv_obj_set_style_text_font(Course_all, &lv_font_montserrat_12, 0);
    lv_label_set_text(Course_all, "Course list");
    lv_obj_align(Course_all, LV_ALIGN_TOP_MID, 0, -13);

     Course_one = lv_label_create(Chunk);
    lv_obj_set_style_text_font(Course_one, &lv_font_montserrat_8, 0);
	  lv_label_set_recolor(Course_one, true);
    if (Week_day == 0) {
        lv_label_set_text(Course_one, "AM8:20-9:55\n#FF00FF Computer#\nPM2:00-15:55\n#EE0000 Eglish#\nPM16:15-17:50\n#00F5FF Math#");

    }
    else if (Week_day == 1) {
        lv_label_set_text(Course_one, "AM10:35-12:10\n#FF00FF Computer#\nPM2:00-15:55\n#EE0000 Eglish#\nPM16:15-17:50\n#00F5FF Math#");

    }
		else if(Week_day == 2){
			 lv_label_set_text(Course_one, "AM8:20-9:55\n#00F5FF Math#\nPM2:00-15:55\n#EE0000 Eglish#");
			
		}
		else if(Week_day == 3){
			lv_label_set_text(Course_one, "AM10:35-12:10\n#FF00FF Computer#\nPM2:00-15:55\n#EE0000 Eglish#\nPM16:15-17:50\n#00F5FF Math#");
		}
		else if(Week_day == 4){
			lv_label_set_text(Course_one, "AM8:20-9:55\n#00F5FF Math#\nAM10:35-12:10\n#00F5FF Math#");
		}
		
    lv_obj_align(Course_one, LV_ALIGN_LEFT_MID, -13, 4);

}
/*函数：static void PORT_1_Back_btn_Handler(lv_event_t* param)
*作者：小夏
*形参：lv_event_t* param
*描述：lv_obj_add_event_cb(PORT_2_Back_btn, PORT_1_Back_btn_Handler, LV_EVENT_ALL, NULL)
			 事件执行函数
       退出按键功能
*修改时间：2022/9/20
*修改内容：无
*/
static void PORT_1_Back_btn_Handler(lv_event_t* param) {

    lv_event_code_t vscode = lv_event_get_code(param);
    lv_obj_t* mune = lv_event_get_target(param);

    if (vscode == LV_EVENT_CLICKED) {
        if (mune == PORT_2_Back_btn) {
            obj_2_FLAG = 0;
            lv_obj_del(obj_2);

        }
        LV_Menu_Init();

    }
}
/*函数：void LV_PORT_2_Back_btn(lv_obj_t* one) 
*作者：小夏
*形参：lv_obj_t* one
*描述：退出按键绘制
*修改时间：2022/9/20
*修改内容：无
*/
void LV_PORT_2_Back_btn(lv_obj_t* one) {
    PORT_2_Back_btn = lv_btn_create(one);
    lv_obj_set_size(PORT_2_Back_btn, 36, 12);
    lv_obj_set_style_radius(PORT_2_Back_btn, 5, 0);
    lv_obj_align(PORT_2_Back_btn, LV_ALIGN_TOP_LEFT, -13, -13);
    lv_obj_set_style_bg_color(PORT_2_Back_btn, lv_color_hex(0x808A87), LV_PART_MAIN);
    lv_obj_t* Back_label = lv_label_create(PORT_2_Back_btn);
    lv_label_set_recolor(Back_label, true);
    lv_label_set_text(Back_label, "#000000 <#");
    lv_obj_center(Back_label);

    lv_obj_add_event_cb(PORT_2_Back_btn, PORT_1_Back_btn_Handler, LV_EVENT_ALL, NULL);
}
