#include "CST816.h" 
#include "at32f403a_407_clock.h"


CST816_Info	CST816_Instance;
uint8_t Pen_Flag;
/* 模拟IIC引脚初始化 */
#if 0
void CST816_GPIO_Init(void)
{	
	GPIO_InitTypeDef GPIO_Init;
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	
	/* 初始化复位引脚 */
	GPIO_Init.Pin=TOUCH_RST_PIN;
	GPIO_Init.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB,&GPIO_Init);
	HAL_GPIO_WritePin(GPIOB,TOUCH_RST_PIN,GPIO_PIN_SET);
	
	/* 初始化中断引脚,不用中断的话屏蔽掉 */
	GPIO_Init.Pin=TOUCH_INT_PIN;
	GPIO_Init.Mode=GPIO_MODE_INPUT;
	GPIO_Init.Pull=GPIO_PULLUP;
	GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA,&GPIO_Init);
	HAL_GPIO_WritePin(GPIOA,TOUCH_INT_PIN,GPIO_PIN_RESET);
	
	/* 初始化I2C引脚 */
	GPIO_Init.Pin=I2C_SCL_PIN | I2C_SDA_PIN;
	GPIO_Init.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB,&GPIO_Init);
	HAL_GPIO_WritePin(GPIOB,I2C_SCL_PIN | I2C_SDA_PIN,GPIO_PIN_SET);
	

	
	/* 给一个停止信号, 复位I2C总线上的所有设备到待机模式 */
	I2C_STOP();
}
#endif
void CST816_GPIO_Init(void)
{
	gpio_init_type gpio_Init;
	crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK|CRM_GPIOB_PERIPH_CLOCK,TRUE);
	/* 初始化复位引脚 */
	gpio_default_para_init(&gpio_Init);
	gpio_Init.gpio_drive_strength=GPIO_DRIVE_STRENGTH_STRONGER;
	gpio_Init.gpio_mode=GPIO_MODE_OUTPUT;
	gpio_Init.gpio_out_type=GPIO_OUTPUT_PUSH_PULL;
	gpio_Init.gpio_pins=TOUCH_RST_PIN;
	gpio_Init.gpio_pull=GPIO_PULL_NONE;
	gpio_init(GPIOB,&gpio_Init);
	gpio_bits_write(GPIOB,TOUCH_RST_PIN,SET);
	/* 初始化中断引脚,不用中断的话屏蔽掉 */
	gpio_default_para_init(&gpio_Init);
	gpio_Init.gpio_drive_strength=GPIO_DRIVE_STRENGTH_STRONGER;
	gpio_Init.gpio_mode=GPIO_MODE_INPUT;
	gpio_Init.gpio_out_type=GPIO_OUTPUT_PUSH_PULL;
	gpio_Init.gpio_pins=TOUCH_INT_PIN;
	gpio_Init.gpio_pull=GPIO_PULL_UP;
	gpio_init(GPIOA,&gpio_Init);
	gpio_bits_write(GPIOA,TOUCH_INT_PIN,RESET);
	/* 初始化I2C引脚 */
	gpio_default_para_init(&gpio_Init);
	gpio_Init.gpio_mode=GPIO_MODE_OUTPUT;
	gpio_Init.gpio_drive_strength=GPIO_DRIVE_STRENGTH_STRONGER;
	gpio_Init.gpio_out_type=GPIO_OUTPUT_PUSH_PULL;
	gpio_Init.gpio_pins=I2C_SCL_PIN | I2C_SDA_PIN;
	gpio_Init.gpio_pull=GPIO_PULL_NONE;
	gpio_init(GPIOB,&gpio_Init);
	gpio_bits_write(GPIOB,I2C_SCL_PIN | I2C_SDA_PIN,SET);
	
}

/* 配置IIC的数据线为输入模式 */
void SDA_INPUT()
{
	
	gpio_init_type gpio_Init;
	crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK,TRUE);
	
	gpio_default_para_init(&gpio_Init);
	gpio_Init.gpio_drive_strength=GPIO_DRIVE_STRENGTH_STRONGER;
	gpio_Init.gpio_mode=GPIO_MODE_INPUT;
	gpio_Init.gpio_out_type=GPIO_OUTPUT_PUSH_PULL;
	gpio_Init.gpio_pins=I2C_SDA_PIN;
	gpio_Init.gpio_pull=GPIO_PULL_UP;
	gpio_init(GPIOB,&gpio_Init);
	
}


/* 配置IIC的数据线为输出模式 */
void SDA_OUT()
{

	gpio_init_type gpio_Init;
	
	crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK,TRUE);
	
	gpio_default_para_init(&gpio_Init);
	gpio_Init.gpio_mode=GPIO_MODE_OUTPUT;
	gpio_Init.gpio_drive_strength=GPIO_DRIVE_STRENGTH_STRONGER;
	gpio_Init.gpio_out_type=GPIO_OUTPUT_PUSH_PULL;
	gpio_Init.gpio_pins= I2C_SDA_PIN;
	gpio_Init.gpio_pull=GPIO_PULL_NONE;
	gpio_init(GPIOB,&gpio_Init);
}

/* 延时函数，如果不准调i值 */
static void I2C_Delay(void)
{
	/*　
    工作条件：CPU主频72MHz ，MDK编译环境，1级优化
  
		循环次数为10时，SCL频率 = 205KHz 
		循环次数为7时，SCL频率 = 347KHz， SCL高电平时间1.5us，SCL低电平时间2.87us 
	 	循环次数为5时，SCL频率 = 421KHz， SCL高电平时间1.25us，SCL低电平时间2.375us 
	*/
	uint8_t i;
	for (i = 0; i < 17; i++);
}


/* IIC起始信号 */
void I2C_START(void)
{
	TOUCH_SDA_1;
	TOUCH_SCL_1;
	delay_us(1);
	TOUCH_SDA_0;
	I2C_Delay();
	TOUCH_SCL_0;
	delay_us(2);
}


/* IIC结束信号 */
void I2C_STOP(void)
{
	TOUCH_SDA_0;
	TOUCH_SCL_1;
	delay_us(2);
	TOUCH_SDA_1;
}


/*
*********************************************************************************************************
*	函 数 名: i2c_Ack
*	功能说明: CPU产生一个ACK信号
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void I2C_Ack(void)
{
	TOUCH_SDA_0;	/* CPU驱动SDA = 0 */
	I2C_Delay();
	TOUCH_SCL_1;	/* CPU产生1个时钟 */
	I2C_Delay();
	TOUCH_SCL_0;
	I2C_Delay();
	TOUCH_SDA_1;	/* CPU释放SDA总线 */
}


/*
*********************************************************************************************************
*	函 数 名: i2c_NAck
*	功能说明: CPU产生1个NACK信号
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void I2C_NAck(void)
{
	TOUCH_SDA_1;	/* CPU驱动SDA = 1 */
	I2C_Delay();
	TOUCH_SCL_1;	/* CPU产生1个时钟 */
	delay_us(1);
	TOUCH_SCL_0;
	delay_us(2);
}


/*
*********************************************************************************************************
*	函 数 名: i2c_SendByte
*	功能说明: CPU向I2C总线设备发送8bit数据
*	形    参：_ucByte ： 等待发送的字节
*	返 回 值: 无
*********************************************************************************************************
*/
void I2C_SEND_ONE_BYTE(uint8_t _ucByte)
{
	uint8_t i;
	/* 先发送字节的高位bit7 */
	for (i = 0; i < 8; i++)
	{		
		if (_ucByte & 0x80)	//写数据
		{
			TOUCH_SDA_1;
		}
		else
		{
			TOUCH_SDA_0;
		}
		I2C_Delay();
		TOUCH_SCL_1;
		I2C_Delay();
		TOUCH_SCL_0;
		if (i == 7)
		{
			 TOUCH_SDA_1; // 释放总线
		}
		_ucByte <<= 1;
		delay_us(2);
	}
}


/*
*********************************************************************************************************
*	函 数 名: I2C_READ_ONE_BYTE
*	功能说明: CPU从I2C总线设备读取8bit数据
*	形    参：无
*	返 回 值: 读到的数据
*********************************************************************************************************
*/
uint8_t I2C_READ_ONE_BYTE(void)
{
	uint8_t i;
	uint8_t value;

	/* 读到第1个bit为数据的bit7,因为1-7才是数据有效位 */
	value = 0;
	for (i = 0; i < 8; i++)	//循环8次
	{
		//一定要先左移再写入数据，不然数据不对齐
		value <<= 1;
		TOUCH_SCL_1;
		I2C_Delay();
		SDA_INPUT();
		if (I2C_SDA_READ())	//读取到高电平则写1
		{
			value = value + 1;	//自加1
		}
		TOUCH_SCL_0;
		SDA_OUT();
		delay_us(2);
	}
	return value;
}


/*
*********************************************************************************************************
*	函 数 名: i2c_WaitAck
*	功能说明: CPU产生一个时钟，并读取器件的ACK应答信号
*	形    参：无
*	返 回 值: 返回0表示正确应答，1表示无器件响应
*********************************************************************************************************
*/
uint8_t I2C_WaitAck(void)
{
	uint8_t re;
	TOUCH_SDA_1;	/* CPU释放SDA总线 */
	I2C_Delay();
	TOUCH_SCL_1;	/* CPU驱动SCL = 1, 此时器件会返回ACK应答 */
	I2C_Delay();
	SDA_INPUT();
	if (I2C_SDA_READ())	/* CPU读取SDA口线状态 */
	{
		re = 1; 
	}
	else
	{
		re = 0;
	}
	TOUCH_SCL_0;
	SDA_OUT();
	delay_us(2);
	return re;
}


/*
*********************************************************************************************************
*	函 数 名: CST816_IIC_ReadREG
*	功能说明: 读取触摸屏单个寄存器的数据
*	形    参：reg：寄存器地址
*	返 回 值: 返回寄存器存储的数据
*********************************************************************************************************
*/
uint8_t CST816_IIC_ReadREG(uint8_t addr)
{
	uint8_t dat;
	I2C_START();
	I2C_SEND_ONE_BYTE(Device_Write_Addr);
	I2C_WaitAck();
	I2C_SEND_ONE_BYTE(addr);
	I2C_WaitAck();
	I2C_START();
	I2C_SEND_ONE_BYTE(Device_Read_Addr);
	I2C_WaitAck();
	dat = I2C_READ_ONE_BYTE();
	I2C_NAck();
	I2C_STOP();
	return dat;
}


/*
*********************************************************************************************************
*	函 数 名: CST816_IIC_WriteREG
*	功能说明: 向触摸屏的寄存器写入数据
*	形    参：addr：寄存器地址
*						dat:	写入的数据
*	返 回 值: 返回寄存器存储的数据
*********************************************************************************************************
*/
void CST816_IIC_WriteREG(uint8_t addr, uint8_t dat)
{
	I2C_START();
	I2C_SEND_ONE_BYTE(Device_Write_Addr);
	I2C_WaitAck();
	I2C_SEND_ONE_BYTE(addr);
	I2C_WaitAck();
	I2C_SEND_ONE_BYTE(dat);
	I2C_NAck();
	I2C_STOP();
}


/*
*********************************************************************************************************
*	函 数 名: TOUCH_RESET
*	功能说明: 触摸屏复位
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void CST816_RESET(void)
{
	TOUCH_RST_0;
	delay_ms(10);
	TOUCH_RST_1;
	delay_ms(100);
}


/*
*********************************************************************************************************
*	函 数 名: TOUCH_READ_X
*	功能说明: 读取触摸屏在触摸时的坐标值
*	形    参：无
*	返 回 值: 无 （数据存储在CST816_Instance结构体中）
*********************************************************************************************************
*/

void CST816_Get_XY_AXIS(void)
{
	

	uint8_t DAT[4];
	I2C_START();
	I2C_SEND_ONE_BYTE(Device_Write_Addr);
	I2C_WaitAck();
	I2C_SEND_ONE_BYTE(XposH);
	I2C_WaitAck();
	I2C_START();
	I2C_SEND_ONE_BYTE(Device_Read_Addr);
	I2C_WaitAck();
	DAT[0] = I2C_READ_ONE_BYTE();	
	I2C_Ack();
	DAT[1] = I2C_READ_ONE_BYTE();	
	I2C_Ack();
	DAT[2] = I2C_READ_ONE_BYTE();	
	I2C_Ack();
	DAT[3] = I2C_READ_ONE_BYTE();	
	I2C_NAck();
	I2C_STOP();
	
	CST816_Instance.X_Pos=((DAT[0]&0x0F)<<8)|DAT[1];//(temp[0]&0X0F)<<4|
	CST816_Instance.Y_Pos=((DAT[2]&0x0F)<<8)|DAT[3];//(temp[2]&0X0F)<<4|
	//是否被按下标志位
	//printf("FLAG=%d\r\n",CST816_Instance.sta);
	
	
	
	
}


/*
*********************************************************************************************************
*	函 数 名: CST816_Get_ChipID
*	功能说明: 读取触摸屏的芯片ID
*	形    参：无
*	返 回 值: 返回芯片ID
*********************************************************************************************************
*/
uint8_t CST816_Get_ChipID(void)
{
	return CST816_IIC_ReadREG(ChipID);
}


/*
*********************************************************************************************************
*	函 数 名: CST816_Config_MotionMask
*	功能说明: 使能连续动作（连续左右滑动，连续上下滑动，双击）
*	形    参：mode：模式(5种)
*	返 回 值: 无
*	注    意：使能连续动作会增加响应时间
*********************************************************************************************************
*/
void CST816_Config_MotionMask(uint8_t mode)
{
	CST816_IIC_WriteREG(MotionMask,mode);
}


/*
*********************************************************************************************************
*	函 数 名: CST816_Config_AutoSleepTime
*	功能说明: 规定time内无触摸，自动进入低功耗模式
*	形    参：time：时间
*	返 回 值: 无
*********************************************************************************************************
*/
void CST816_Config_AutoSleepTime(uint8_t time)
{
	CST816_IIC_WriteREG(AutoSleepTime,time);
}


/*
*********************************************************************************************************
*	函 数 名: CST816_Config_MotionSlAngle
*	功能说明: 手势检测滑动分区角度控制。Angle=tan(c)*10 c为以x轴正方向为基准的角度。
*	形    参：x_right_y_up_angle：角度值
*	返 回 值: 无
*********************************************************************************************************
*/
void CST816_Config_MotionSlAngle(uint8_t x_right_y_up_angle)
{
	CST816_IIC_WriteREG(MotionSlAngle,x_right_y_up_angle);
}


/*
*********************************************************************************************************
*	函 数 名: CST816_Config_NorScanPer
*	功能说明: 正常快速检测周期配置函数。
*						此值会影响到LpAutoWakeTime和AutoSleepTime。 
*						单位10ms，可选值：1～30。默认值为1。
*	形    参：Period：周期值
*	返 回 值: 无
*********************************************************************************************************
*/
void CST816_Config_NorScanPer(uint8_t Period)
{
	if(Period >= 30)
		Period = 30;
	CST816_IIC_WriteREG(NorScanPer,Period);
}


/*
*********************************************************************************************************
*	函 数 名: CST816_Config_IrqPluseWidth
*	功能说明: 中断低脉冲输出宽度配置函数
*	形    参：Period：周期值
*	返 回 值: 无
*********************************************************************************************************
*/
void CST816_Config_IrqPluseWidth(uint8_t Width)
{
	if(Width >= 200)
		Width = 200;
	CST816_IIC_WriteREG(IrqPluseWidth,Width);
}


/*
*********************************************************************************************************
*	函 数 名: CST816_Config_NorScanPer
*	功能说明: 低功耗扫描唤醒门限配置函数。越小越灵敏。默认值48
*	形    参：TH：门限值
*	返 回 值: 无
*********************************************************************************************************
*/
void CST816_Config_LpScanTH(uint8_t TH)
{
	CST816_IIC_WriteREG(LpScanTH,TH);
}
