#ifndef __CST816_H
#define __CST816_H

#include "stdint.h"
#include "at32f403a_407.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32; 

#define I2C_WR 0 /* 写控制bit */
#define I2C_RD 1 /* 读控制bit */

#define I2C_SCL_PIN GPIO_PINS_14 /* 连接到SCL时钟线的GPIO */
#define I2C_SDA_PIN GPIO_PINS_13 /* 连接到SDA数据线的GPIO */
#define TOUCH_RST_PIN GPIO_PINS_12
#define TOUCH_INT_PIN GPIO_PINS_4

//#define TOUCH_SCL_0 HAL_GPIO_WritePin(GPIOB, I2C_SCL_PIN,GPIO_PIN_RESET)
//#define TOUCH_SCL_1 HAL_GPIO_WritePin(GPIOB, I2C_SCL_PIN,GPIO_PIN_SET)

#define TOUCH_SCL_0 gpio_bits_write(GPIOB,I2C_SCL_PIN,0);
#define TOUCH_SCL_1 gpio_bits_write(GPIOB,I2C_SCL_PIN,1);

//#define TOUCH_SDA_0 HAL_GPIO_WritePin(GPIOB, I2C_SDA_PIN,GPIO_PIN_RESET)
//#define TOUCH_SDA_1 HAL_GPIO_WritePin(GPIOB, I2C_SDA_PIN,GPIO_PIN_SET)

#define TOUCH_SDA_0 gpio_bits_write(GPIOB,I2C_SDA_PIN,0)
#define TOUCH_SDA_1 gpio_bits_write(GPIOB,I2C_SDA_PIN,1)

//#define TOUCH_RST_0 HAL_GPIO_WritePin(GPIOB, TOUCH_RST_PIN,GPIO_PIN_RESET)
//#define TOUCH_RST_1 HAL_GPIO_WritePin(GPIOB, TOUCH_RST_PIN,GPIO_PIN_SET)

#define TOUCH_RST_0 gpio_bits_write(GPIOB,TOUCH_RST_PIN,0)
#define TOUCH_RST_1 gpio_bits_write(GPIOB,TOUCH_RST_PIN,1)

//#define I2C_SDA_READ() HAL_GPIO_ReadPin(GPIOB, I2C_SDA_PIN)
#define I2C_SDA_READ() gpio_input_data_bit_read(GPIOB,I2C_SDA_PIN)

//#define TOUCH_FLAG HAL_GPIO_ReadPin(GPIOA,TOUCH_INT_PIN)
#define TOUCH_FLAG gpio_input_data_bit_read(GPIOA,TOUCH_INT_PIN)
/* 设备地址 */
#define Device_Write_Addr 	0x2A
#define Device_Read_Addr 	0x2B

/* 触摸屏寄存器 */
#define GestureID 			0x01
#define FingerNum 			0x02
#define XposH 				0x03
#define XposL 				0x04
#define YposH 				0x05
#define YposL 				0x06
#define ChipID 				0xA7
#define MotionMask 			0xEC
#define IrqPluseWidth 		0xED
#define NorScanPer 			0xEE
#define MotionSlAngle 		0xEF
#define LpAutoWakeTime 		0xF4
#define LpScanTH 			0xF5
#define LpScanWin 			0xF6
#define LpScanFreq 			0xF7
#define LpScanIdac 			0xF8
#define AutoSleepTime 		0xF9
#define IrqCtl 				0xFA
#define AutoReset 			0xFB
#define LongPressTime 		0xFC
#define IOCtl 				0xFD
#define DisAutoSleep 		0xFE

/* 触摸屏坐标结构体 */
typedef struct
{
	unsigned int X_Pos;
	unsigned int Y_Pos;
	u8 sta;
	u8 DOWN;
} CST816_Info;

#define TP_PRES_DOWN 0x80
#define TP_CATH_PRES 0x40
//#define 
extern CST816_Info CST816_Instance;
extern uint8_t Pen_Flag;
/* 手势ID识别选项 */
typedef enum
{
	NOGESTURE = 	0x00,
	DOWNGLIDE = 	0x01,
	UPGLIDE = 		0x02,
	LEFTGLIDE = 	0x03,
	RIGHTGLIDE = 	0x04,
	CLICK = 		0x05,
	DOUBLECLICK = 	0x0B,
	LONGPRESS = 	0x0C,
} GestureID_TypeDef;

/* 连续动作配置选项 */
typedef enum
{
	M_DISABLE = 	0x00,
	EnConLR = 		0x01,
	EnConUD = 		0x02,
	EnDClick = 		0x03,
	M_ALLENABLE = 	0x07,
} MotionMask_TypeDef;

/* 中断低脉冲发射方式选项 */
typedef enum
{
	OnceWLP = 		0x00,
	EnMotion = 		0x10,
	EnChange = 		0x20,
	EnTouch = 		0x40,
	EnTest = 		0x80,
} IrqCtl_TypeDef;

/* IIC相关函数 */
void I2C_START(void);
void I2C_STOP(void);
void I2C_Ack(void);
void I2C_NAck(void);
uint8_t I2C_WaitAck(void);
void I2C_SEND_ONE_BYTE(uint8_t _ucByte);
uint8_t I2C_READ_ONE_BYTE(void);

/* 触摸屏初始化相关函数 */
void CST816_GPIO_Init(void);
void CST816_RESET(void);

/* 触摸屏操作函数 */
void CST816_Get_XY_AXIS(void);
uint8_t CST816_Get_ChipID(void);

/* 触摸屏读写函数 */
void CST816_IIC_WriteREG(uint8_t addr, uint8_t dat);
uint8_t CST816_IIC_ReadREG(unsigned char addr);

/* 触摸屏有关参数配置函数 */
void CST816_Config_MotionMask(uint8_t mode);
void CST816_Config_AutoSleepTime(uint8_t time);
void CST816_Config_MotionSlAngle(uint8_t x_right_y_up_angle);
void CST816_Config_NorScanPer(uint8_t Period);
void CST816_Config_IrqPluseWidth(uint8_t Width);
void CST816_Config_LpScanTH(uint8_t TH);

#endif
