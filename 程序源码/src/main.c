#include "at32f403a_407_board.h"
#include "at32f403a_407_clock.h"
#include "lcd_init.h"
#include "lcd.h"
#include "pic.h"
#include "CST816.h"
#include "Timer.h"
#include "rtc.h"
#include "ws2812b.h"
#include "W25Q128.h"
#include "FreeRTOS.h"
#include "task.h"
#include "Timers.h"
#include "ADC.h"

#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "LVGL_Main.h"
#include "LVGL_PORT_1.h"
#include "LVGL_PORT.h"
#include "LVGL_PORT_2.h"
#include "LVGL_PORT_3.h"
#include "LVGL_PORT_4.h"
#include "LVGL_PORT_5.h"
#include "LVGL_PORT_6.h"
#include "fontupd.h"
#include "text.h"	
#include "KEY_NVIC.h"
#include "WWDG.h"

/* 更新时间：2022/10/27
*更新内容：增加每日单词30个提醒
*           增加旋转界面设置。
*版本号：1.0.1
*/

/* 更新时间：2022/10/29
*更新内容：增加小学初中单词2100个
*           增加小学单词和四级单词设置显示。
*           FLW为四级单词  SOW为二级单词
*版本号：1.0.2
*/

/* 更新时间：2023/2/5
*更新内容：添加开机动画，设置添加恢复出厂设置
*版本号：1.0.3
*/

/* 更新时间：2023/2/15
*更新内容：添加独立看门狗，解决有时突然卡死的情况，卡死就复位
*版本号：1.0.4
*/

TaskHandle_t Handler_Task;
TaskHandle_t Handler_Task1;
TaskHandle_t Handler_Task2;


BaseType_t xReturn;
BaseType_t Task3Return;

StackType_t xIdle3Static[128];
StaticTask_t xIdleTCB;

StackType_t xITimeStatic[524];
StaticTask_t xITimeTCB;


uint8_t CC_BUFF[1024];
u16 W25Q128_ID;
uint8_t Reset_buff[10];

uint8_t ResetS_buff[10];
uint8_t Reset_buffs[10];
uint8_t YES_Buff[10];
uint8_t YES_val;

double virf_Value;

void vApplicationGetIdleTaskMemory( StaticTask_t ** ppxIdleTaskTCBBuffer,StackType_t ** ppxIdleTaskStackBuffer,uint32_t * pulIdleTaskStackSize ){
			*ppxIdleTaskTCBBuffer=&xIdleTCB;				
			*ppxIdleTaskStackBuffer=xIdle3Static;
			*pulIdleTaskStackSize=128;
}
void vApplicationGetTimerTaskMemory( StaticTask_t ** ppxTimerTaskTCBBuffer,
                                          StackType_t ** ppxTimerTaskStackBuffer,
                                              uint32_t * pulTimerTaskStackSize ){
			* ppxTimerTaskTCBBuffer=&xITimeTCB;																					
			* ppxTimerTaskStackBuffer=xITimeStatic;
			* pulTimerTaskStackSize	=524;																			
}
//空闲任务
void vApplicationIdleHook(void){
	
	while(1){
		
	}
	
}
//进入低功耗模式执行任务
void PreSleepProcessing(uint32_t ulExpectedldleTime){
  crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK,FALSE);
  crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK,FALSE);
	crm_periph_clock_enable(CRM_GPIOC_PERIPH_CLOCK,FALSE);
	crm_periph_clock_enable(CRM_GPIOD_PERIPH_CLOCK,FALSE);
	crm_periph_clock_enable(CRM_GPIOE_PERIPH_CLOCK,FALSE);
}

//退出低功耗模式执行任务
void PostSleepProcessing(uint32_t ulExpectedldleTime){
	crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK,TRUE);
	crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK,TRUE);
	crm_periph_clock_enable(CRM_GPIOC_PERIPH_CLOCK,TRUE);
	crm_periph_clock_enable(CRM_GPIOD_PERIPH_CLOCK,TRUE);
	crm_periph_clock_enable(CRM_GPIOE_PERIPH_CLOCK,TRUE);
	
}

void Task_1_Function(void* param)
{
			WS2812B_GPIO_Init();
			WS2812B_RESET();

		
		
			lv_init();
			lv_port_disp_init();
			lv_port_indev_init();
	

			
			//lv_obj_del(label_word);
	    
		
			LV_Main_Code();
			Timer_8_Init();
			Timer_Init();
			//读取英语单词上一次看的地方
			W25QXX_Read(CallBack,ADDR,sizeof(CallBack));
			Eglish_Flag=atoi(CallBack);
			WWCG_Init();//独立看门狗，每最大300ms喂一次狗
		while(1){
			  wdt_counter_reload();//喂狗
				lv_task_handler();			
			  voltage=ADC_GET_Value()*3.2;//更新时间 2022.12.6
			
		}		
	
}

/*
void Task_3_Function(void* param){
		//进入定时器
	while(1){  
			
		
	}	
}	*/

void Task_2_Function(void *param){
  taskENTER_CRITICAL();//进入临界区

	//创建任务一
	#if 1
	xReturn=xTaskCreate(Task_1_Function,"Task1",2800,NULL,1,&Handler_Task);
	
	if(xReturn== pdPASS){
		printf("Task Created successfully\r\n");	
	}else{
		printf("Failed to create a task\r\n");	
	}
	#endif
	//创建任务二
	#if 0
	Task3Return =xTaskCreate(Task_3_Function,"Task3",128,NULL,2,&Handler_Task2);
	if(Task3Return== pdPASS){
		printf("Task Created successfully\n");	
	}else{
		printf("Failed to create a task\n");	
	}
	#endif
	//删除首任务，释放内存
	vTaskDelete(Handler_Task1);
	
	taskEXIT_CRITICAL();//退出临界区
	while(1);
}


int main(void)
{

  system_clock_config();
  at32_board_init();
	NVIC_SetPriorityGrouping(NVIC_PRIORITY_GROUP_2);
	uart_print_init(115200);
	alarm_init();
	W25Q128_Init();	
	ADC_Init();
	LCD_Init();	
	LCD_Fill(0,0,160,80,WHITE);

	//update_font(0,20,12);//更新字库
	//串口下载字库
//更新时间2022.11.29 左键开机进行单词烧录
	KEY_Init();
	if(KEY0 ==0){
		update_font_word(0,20,12);//更新字库
		while(font_word_init())
		{
			
			printf("NO FONT!\r\n");

			LCD_ShowString(0,0,(u8*)"Font Error!",RED,WHITE,12,0);
			Delay_ms(1000);
			LCD_ShowString(0,0,(u8*)"Start Updating Font!",RED,WHITE,12,0);
			printf("UPDATA_XWP...\r\n");
			update_font_word(0,20,12);//更新字库
			break;
		}
	}

		//更新 2022.11.29 获取自己单词
	W25QXX_Read(Own_buff,1024*1024*144+9,sizeof(Own_buff));
	
  sprintf(DMA_Buff_1,"%s",Own_buff);
	printf("%s\r\n",DMA_Buff_1);	
//更新2022.11.29       END
	#if 1
	while(font_init())
	{
	  
		printf("NO FONT!\r\n");

		LCD_ShowString(0,0,(u8*)"Font Error!",RED,WHITE,12,0);
		Delay_ms(1000);
		LCD_ShowString(0,0,(u8*)"Start Updating Font!",RED,WHITE,12,0);
		printf("开始更新字库...\r\n");
		update_font(0,20,12);//更新字库
		break;
	}
	printf("ADC_Begin...\r\n");
	
			//读取BUFF的值
			W25QXX_Read(ResetS_buff,1024*1024*126,sizeof(ResetS_buff));
			YES_val=atoi(ResetS_buff);
			rtc_time_get();
			printf("Hour=%d\r\n",calendar.date);
    if(YES_val != calendar.date){	
			sprintf(YES_Buff,"%d",calendar.date);
			W25QXX_Write(YES_Buff,1024*1024*126,sizeof(YES_Buff));
			sprintf(word_b,"%d",0);
			W25QXX_Write(word_b,Word_Flag_Addr,sizeof(word_b));
			printf("INPUT");			
		}
		sprintf(YES_Buff,"%d",calendar.date);
		W25QXX_Write(YES_Buff,1024*1024*126,sizeof(YES_Buff));
		
		W25QXX_Read(LV_R_Wrod_Buff,1024*1024*100,sizeof(LV_R_Wrod_Buff));
		Wrod_Ch_Flag=atoi(LV_R_Wrod_Buff);
		printf("NUMBER[1]=%d\n",Wrod_Ch_Flag);
		
		
		
		Timer_2_Init();
 #endif
	xTaskCreate(Task_2_Function,"Task2",3000,NULL,1,&Handler_Task1);
	
	vTaskStartScheduler();
   
  while(1)
  {


  }
}

