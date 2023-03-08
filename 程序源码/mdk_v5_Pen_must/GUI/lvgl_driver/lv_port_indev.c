/**
 * @file lv_port_indev_templ.c
 *
 */

 /*Copy this file as "lv_port_indev.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_indev.h"
#include "lvgl/lvgl.h"

#include "CST816.h"
#include "KEY_NVIC.h"
//#include "usart.h"
//#include "delay.h"
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void touchpad_init(void);
static void touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
static void touchpad_get_xy(lv_coord_t * x, lv_coord_t * y);
static bool touchpad_is_pressed(void);
/**********************
 *  STATIC VARIABLES
 **********************/
lv_indev_t * indev_touchpad;

/**********************
 *      MACROS
 **********************/
uint16_t Key_pressed(void);
int16_t enc_get_new_Key(void);
static void ECO_Init(void);
static void encoder_read(lv_indev_drv_t* indev_drv,lv_indev_data_t* data);

lv_indev_t * indev_ecodes;
int32_t encoder_buff;
/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_indev_init(void)
{
  

//    static lv_indev_drv_t indev_drv;


//    touchpad_init();

    /*Register a touchpad input device*/
//    lv_indev_drv_init(&indev_drv);
//    indev_drv.type = LV_INDEV_TYPE_POINTER;
//    indev_drv.read_cb = touchpad_read;
//    indev_touchpad = lv_indev_drv_register(&indev_drv);
	  
			static lv_indev_drv_t indev_drv_ec;
			ECO_Init();
	
			lv_indev_drv_init(&indev_drv_ec);
			indev_drv_ec.type=LV_INDEV_TYPE_ENCODER;
			indev_drv_ec.read_cb = encoder_read;
			indev_ecodes = lv_indev_drv_register(&indev_drv_ec);
	  
}


static void touchpad_init(void)
{
	  CST816_GPIO_Init();
    //EXTI_config();
}


/*Will be called by the library to read the touchpad*/
static void touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    static lv_coord_t last_x = 0;
    static lv_coord_t last_y = 0;
	  Pen_Flag=CST816_IIC_ReadREG(0x02);
    CST816_Get_XY_AXIS();
    /*保存按下的坐标和状态*/
    if(Pen_Flag ==1 ){
      touchpad_get_xy(&last_x, &last_y);
			data->point.x = last_x;
      data->point.y = last_y;
			data->state = LV_INDEV_STATE_PR;
      
    } else {
					
        data->state = LV_INDEV_STATE_REL;
    }

    /*设置最后按下的坐标*/
    		data->point.x = last_x;
        data->point.y = last_y;
}

/*Return true is the touchpad is pressed*/
static bool touchpad_is_pressed(void)
{
    /*Your code comes here*/
/*    if(CST816_Instance.sta != 1)
    {
			
        return true;
			
    }
    return false;*/
}

/*Get the x and y coordinates if the touchpad is pressed*/
static void touchpad_get_xy(lv_coord_t * x, lv_coord_t * y)
{
    /*Your code comes here*/
		//CST816_Get_XY_AXIS();
    (*x) = CST816_Instance.X_Pos;
    (*y) = CST816_Instance.Y_Pos;
}

static void ECO_Init(void){
	
	KEY_Init();	
}
/*
*旋转编码器按下
*/
uint16_t Key_pressed(void)
{
	if(KEY2==0){
		
		return LV_KEY_ENTER;
	
	}
	return 0;
}
/*
*旋转编码器方向键
*/
int16_t enc_get_new_Key(void)
{
	static uint8_t sta=0;
	int16_t Key_Valye=0;

		sta=1;
		if(KEY1==0){
			Delay_ms(100);
			if(KEY1==0){
				Key_Valye=1;
				sta=1;
			}
		}
		if(KEY0==0){
			Delay_ms(100);
			if(KEY0==0){
				Key_Valye=-1;	
				//LV_KEY_RIGHT
				sta=1;
			}
		}		
	
	if(KEY0==1 && KEY1==1)
	{
		sta=0;
		
	}

	return Key_Valye;
}

static void encoder_read(lv_indev_drv_t* indev_drv,lv_indev_data_t* data){

	data->enc_diff=	enc_get_new_Key();
	if(Key_pressed()==10){		
		data->state=LV_INDEV_STATE_PRESSED;
		//data->enc_diff=	enc_get_new_Key();
	}else
	{
		data->state=LV_INDEV_STATE_RELEASED;
		
	}
	
}

#else /*Enable this file at the top*/


typedef int keep_pedantic_happy;
#endif