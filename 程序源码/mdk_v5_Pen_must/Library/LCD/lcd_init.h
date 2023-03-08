#ifndef __LCD_INIT_H
#define __LCD_INIT_H

#include "at32f403a_407.h"

typedef unsigned char u8;
typedef unsigned short u16;


extern u8 USE_HORIZONTAL;  //设置横屏或者竖屏显示 0或1为竖屏 2或3为横屏
//#define USE_HORIZONTAL 3


#if USE_HORIZONTAL==11||USE_HORIZONTAL==22
#define LCD_W 80
#define LCD_H 160

#else
#define LCD_W 160
#define LCD_H 80
#endif

extern u8 LCD_RO_Buff[10];
extern u8 LCD_Write_RO_Buff[10];
#define LCD_RO_Addr 1024*1024*135
//-----------------LCD端口定义---------------- 

//#define LCD_SCLK_Clr() gpio_bits_write(GPIOB,GPIO_PINS_5,RESET)//SCL=SCLK
//#define LCD_SCLK_Set() gpio_bits_write(GPIOB,GPIO_PINS_5,SET)

//#define LCD_MOSI_Clr() gpio_bits_write(GPIOB,GPIO_PINS_7,RESET)//SDA=MOSI
//#define LCD_MOSI_Set() gpio_bits_write(GPIOB,GPIO_PINS_7,RESET)

//#define LCD_RES_Clr()  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_RESET);
//#define LCD_RES_Set()  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_SET);

#define LCD_RES_Clr()  gpio_bits_write(GPIOA,GPIO_PINS_6,RESET)
#define LCD_RES_Set()  gpio_bits_write(GPIOA,GPIO_PINS_6,SET)

//#define LCD_DC_Clr()   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_RESET);
//#define LCD_DC_Set()   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_SET);
 
#define LCD_DC_Clr()   gpio_bits_write(GPIOA,GPIO_PINS_3,RESET)
#define LCD_DC_Set()   gpio_bits_write(GPIOA,GPIO_PINS_3,SET)

//#define LCD_CS_Clr()   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_RESET);
//#define LCD_CS_Set()   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_SET);

#define LCD_CS_Clr()   gpio_bits_write(GPIOA,GPIO_PINS_4,RESET)
#define LCD_CS_Set()   gpio_bits_write(GPIOA,GPIO_PINS_4,SET)

//#define LCD_BLK_Clr()  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
//#define LCD_BLK_Set()  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);

#define LCD_BLK_Clr()  gpio_bits_write(GPIOA,GPIO_PINS_8,RESET)
#define LCD_BLK_Set()  gpio_bits_write(GPIOA,GPIO_PINS_8,SET)


void LCD_GPIO_Init(void);//初始化GPIO
void LCD_Writ_Bus(u8 dat);//模拟SPI时序
void LCD_WR_DATA8(u8 dat);//写入一个字节
void LCD_WR_DATA(u16 dat);//写入两个字节
void LCD_WR_REG(u8 dat);//写入一个指令
void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2);//设置坐标函数
void LCD_Init(void);//LCD初始化
#endif




