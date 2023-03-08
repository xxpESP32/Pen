#include "Timer.h"
#include "at32f403a_407_board.h"
#include "lvgl.h"
#include "LVGL_Main.h"
#include "LVGL_PORT_1.h"
#include "LVGL_PORT_2.h"
#include "LVGL_PORT_4.h"
#include "LVGL_PORT_5.h"
#include "RTC.h"
#include "ws2812b.h"
#include "ADC.h"
#include "LVGL_PORT.h"
#include "LVGL_PORT_6.h"
#include "WWDG.h"
float voltage;
//u8 Own_buff_cp[1030];

int32_t vol;
void Timer_Init(void){
	crm_periph_clock_enable(CRM_TMR1_PERIPH_CLOCK,TRUE);
	tmr_base_init(TMR1, 240-1, 35000-1);
  tmr_cnt_dir_set(TMR1, TMR_COUNT_UP);
  tmr_clock_source_div_set(TMR1, TMR_CLOCK_DIV1);
	
	tmr_interrupt_enable(TMR1, TMR_OVF_INT, TRUE);
	nvic_irq_enable(TMR1_OVF_TMR10_IRQn, 0, 4);
	
	
	tmr_counter_enable(TMR1, TRUE);
}
void Timer_2_Init(void){
	crm_periph_clock_enable(CRM_TMR2_PERIPH_CLOCK,TRUE);
	tmr_base_init(TMR2, 240-1, 1000-1);
	tmr_cnt_dir_set(TMR2,TMR_COUNT_UP);
	tmr_clock_source_div_set(TMR2, TMR_CLOCK_DIV1);
	
	tmr_interrupt_enable(TMR2, TMR_OVF_INT, TRUE);
	nvic_irq_enable(TMR2_GLOBAL_IRQn, 0, 0);

	tmr_counter_enable(TMR2, TRUE);
}

void Timer_8_Init(void){//2ms
	crm_periph_clock_enable(CRM_TMR8_PERIPH_CLOCK,TRUE);
	tmr_base_init(TMR8, 240-1, 2000000-1);
  tmr_cnt_dir_set(TMR8, TMR_COUNT_UP);
  tmr_clock_source_div_set(TMR8, TMR_CLOCK_DIV1);
	
	tmr_interrupt_enable(TMR8, TMR_OVF_INT, TRUE);
	nvic_irq_enable(TMR8_OVF_TMR13_IRQn, 0, 3);
	
	
	tmr_counter_enable(TMR8, TRUE);
	
}
void TMR2_GLOBAL_IRQHandler(void)
{
	if(tmr_flag_get(TMR2,TMR_OVF_FLAG)){
		wdt_counter_reload();//喂狗
		lv_tick_inc(1);
		
		tmr_flag_clear(TMR2,TMR_OVF_FLAG);
		
	}
	
	
}

void TMR8_OVF_TMR13_IRQHandler(void){
	if(tmr_flag_get(TMR8, TMR_OVF_FLAG) != RESET){
			  if(rtc_flag_get(RTC_TS_FLAG) != RESET)
				{
					rtc_time_get();	
					rtc_wait_config_finish();
					 while (RTC->ctrll_bit.cfgf == 0 );

					/* clear the rtc second flag */
					rtc_flag_clear(RTC_TS_FLAG);
					 while (RTC->ctrll_bit.cfgf == 0 );
			 
					if(obj_2_FLAG==1){
						lv_label_set_recolor(Time_hour, true);
						lv_label_set_text_fmt(Time_hour,"#ffa500 %02d:%02d:%02d#",calendar.hour,calendar.min,calendar.sec);
						RTC_Display_Cyc_Data(calendar.year,calendar.month, calendar.date);
					}			
				}   		 
			 if(time.Timer_Start_Stop_Flag == 1){
				if(time.Cp_h==calendar.hour && time.Cp_m==calendar.min &&time.Cp_s<=calendar.sec){
					
					if(time.Timer_Begin_Flag==0){ //定时闪烁
						RGB_Write_ALL(0xff,0x00,0x00);
					}
					if(time.Timer_Begin_Flag==1){
						RGB_Write_ALL(0x00,0xff,0x00);
					}
					if(time.Timer_Begin_Flag==2){
						RGB_Write_ALL(0x00,0x00,0xff);
					}
					time.Timer_Begin_Flag++;
					if(time.Timer_Begin_Flag>=3){
						time.Timer_Begin_Flag=0;				
					}
				}
		 
		  }
			 //按键控制灯光闪烁
		if(rgb.RGB_Btn_Flag==3){
			rgb.RGB_Flick_FLAG+=1;
			if(rgb.RGB_Flick_FLAG >=3){
						rgb.RGB_Flick_FLAG=0;						
			}

		}			
			
		if(rgb.RGB_Flick_FLAG == 1){
			RGB_Write_ALL(rgbv.Green,rgbv.Red,rgbv.Blue);		
		}
		else if(rgb.RGB_Flick_FLAG == 2){
			RGB_Write_ALL(0x00,0x00,0x00);
		}
		//写入低电压检测。一直检测 然后main函数里面读取W25Q128的数据。
       

			 vol=voltage*100;
		   if(Vol_Value>=vol){
				 RGB_Write_ALL(0x00,0xff,0x00);	
				 
			 }
			 if(rgb.RGB_Btn_Flag != 1){
					if(Vol_Value<vol){
				  RGB_Write_ALL(0x00,0x00,0x00);
			 }
		 }
			tmr_flag_clear(TMR8, TMR_OVF_FLAG);
  }
	
	
}

void TMR1_OVF_TMR10_IRQHandler(void)
{
  if(tmr_flag_get(TMR1, TMR_OVF_FLAG) != RESET)
  {
     if(rgb.RGB_Exti_Flag==1){
			 if(rgb.RGB_CHO_FLAG==0){
					rgbv.Red=lv_slider_get_value(rgb_slider_1)*10;					
			 }
			 if(rgb.RGB_CHO_FLAG==1){
				 rgbv.Green=lv_slider_get_value(rgb_slider_1)*10;	
			 }
			 if(rgb.RGB_CHO_FLAG==2){
				 rgbv.Blue=lv_slider_get_value(rgb_slider_1)*10;	
			 }
			 RGB_Write_ALL(rgbv.Green,rgbv.Red,rgbv.Blue);
		 }	
		 			 
     tmr_flag_clear(TMR1, TMR_OVF_FLAG);
  }
}