#include "lcd_init.h"
#include "at32f403a_407_clock.h"
#include "spi.h"
#include "FreeRTOS.h"
#include "task.h"
#include "W25Q128.h"
//#include "sys.h"
u8 USE_HORIZONTAL;
u8 LCD_RO_Buff[10];
u8 LCD_Write_RO_Buff[10];

void LCD_GPIO_Init(void)
{
	gpio_init_type gpio_Init;
	crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK,TRUE);
	crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK,TRUE);
	gpio_default_para_init(&gpio_Init);
	//crm_periph_clock_enable(CRM_IOMUX_PERIPH_CLOCK, TRUE);
  //gpio_pin_remap_config(SWJTAG_GMUX_010, TRUE);
	
	gpio_Init.gpio_drive_strength=GPIO_DRIVE_STRENGTH_STRONGER;
	gpio_Init.gpio_mode =GPIO_MODE_OUTPUT;
	gpio_Init.gpio_out_type=GPIO_OUTPUT_PUSH_PULL;
	gpio_Init.gpio_pins=GPIO_PINS_3|GPIO_PINS_6|GPIO_PINS_4|GPIO_PINS_8;
	gpio_Init.gpio_pull=GPIO_PULL_NONE;
	gpio_init(GPIOA,&gpio_Init);
	gpio_bits_write(GPIOA,GPIO_PINS_3|GPIO_PINS_6|GPIO_PINS_4|GPIO_PINS_8,TRUE);
	
	
}

/******************************************************************************
      函数说明：LCD串行数据写入函数
      入口数据：dat  要写入的串行数据
      返回值：  无
******************************************************************************/


void LCD_Writ_Bus(u8 dat) 
{	
	GPIOA->clr = GPIO_PINS_4;
	SPI1->dt=dat;
	while(spi_i2s_flag_get(SPI1, SPI_I2S_TDBE_FLAG) == RESET);

	GPIOA->scr = GPIO_PINS_4;
}

/*
void DMA1_Channel3_IRQHandler(void)
{
	while(dma_flag_get(DMA1_FDT3_FLAG)){
		dma_flag_clear(DMA1_FDT3_FLAG);
		GPIOA->scr = GPIO_PINS_3;
	}
	
}*/



/*
void SPI1_IRQHandler(u8 dat)
{
	LCD_Writ_Bus(dat);
}*/	

/******************************************************************************
      函数说明：LCD写入数据
      入口数据：dat 写入的数据
      返回值：  无
******************************************************************************/
void LCD_WR_DATA8(u8 dat)
{
	LCD_Writ_Bus(dat);
}


/******************************************************************************
      閿熸枻鎷烽敓鏂ゆ嫹璇撮敓鏂ゆ嫹閿熸枻鎷稬CD鍐欓敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹
      閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷疯崺閿熺禌at 鍐欓敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿燂拷
      閿熸枻鎷烽敓鏂ゆ嫹鍊奸敓鏂ゆ嫹  閿熸枻鎷?
******************************************************************************/
void LCD_WR_DATA(u16 dat)
{
	LCD_Writ_Bus(dat>>8);
	LCD_Writ_Bus(dat);
}


/******************************************************************************
      閿熸枻鎷烽敓鏂ゆ嫹璇撮敓鏂ゆ嫹閿熸枻鎷稬CD鍐欓敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹
      閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷疯崺閿熺禌at 鍐欓敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿燂拷
      閿熸枻鎷烽敓鏂ゆ嫹鍊奸敓鏂ゆ嫹  閿熸枻鎷?
******************************************************************************/
void LCD_WR_REG(u8 dat)
{
	LCD_DC_Clr();//鍐欓敓鏂ゆ嫹閿熸枻鎷?
	LCD_Writ_Bus(dat);
	LCD_DC_Set();//鍐欓敓鏂ゆ嫹閿熸枻鎷?
}


/******************************************************************************
      閿熸枻鎷烽敓鏂ゆ嫹璇撮敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹濮嬮敓閰垫枻鎷烽敓鏂ゆ嫹閿熸枻鎷峰潃
      閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷疯崺閿熺蛋1,x2 閿熸枻鎷烽敓鏂ゆ嫹閿熷彨纰夋嫹閿熸枻鎷峰閿熼叺鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹鍧?
                y1,y2 閿熸枻鎷烽敓鏂ゆ嫹閿熷彨纰夋嫹閿熸枻鎷峰閿熼叺鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹鍧?
      閿熸枻鎷烽敓鏂ゆ嫹鍊奸敓鏂ゆ嫹  閿熸枻鎷?
******************************************************************************/
void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2)
{
	if(USE_HORIZONTAL==0)
	{
		LCD_WR_REG(0x2a);//閿熷彨纰夋嫹鍧?閿熸枻鎷烽敓鏂ゆ嫹
		LCD_WR_DATA(x1+26);
		LCD_WR_DATA(x2+26);
		LCD_WR_REG(0x2b);//閿熷彨纰夋嫹鍧?閿熸枻鎷烽敓鏂ゆ嫹
		LCD_WR_DATA(y1+1);
		LCD_WR_DATA(y2+1);
		LCD_WR_REG(0x2c);//閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷峰啓
	}
	else if(USE_HORIZONTAL==1)
	{
		LCD_WR_REG(0x2a);//閿熷彨纰夋嫹鍧?閿熸枻鎷烽敓鏂ゆ嫹
		LCD_WR_DATA(x1+26);
		LCD_WR_DATA(x2+26);
		LCD_WR_REG(0x2b);//閿熷彨纰夋嫹鍧?閿熸枻鎷烽敓鏂ゆ嫹
		LCD_WR_DATA(y1+1);
		LCD_WR_DATA(y2+1);
		LCD_WR_REG(0x2c);//閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷峰啓
	}
	else if(USE_HORIZONTAL==2)
	{
		LCD_WR_REG(0x2a);//閿熷彨纰夋嫹鍧?閿熸枻鎷烽敓鏂ゆ嫹
		LCD_WR_DATA(x1+1);
		LCD_WR_DATA(x2+1);
		LCD_WR_REG(0x2b);//閿熷彨纰夋嫹鍧?閿熸枻鎷烽敓鏂ゆ嫹
		LCD_WR_DATA(y1+26);
		LCD_WR_DATA(y2+26);
		LCD_WR_REG(0x2c);//閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷峰啓
	}
	else
	{
		LCD_WR_REG(0x2a);//閿熷彨纰夋嫹鍧?閿熸枻鎷烽敓鏂ゆ嫹
		LCD_WR_DATA(x1+1);
		LCD_WR_DATA(x2+1);
		LCD_WR_REG(0x2b);//閿熷彨纰夋嫹鍧?閿熸枻鎷烽敓鏂ゆ嫹
		LCD_WR_DATA(y1+26);
		LCD_WR_DATA(y2+26);
		LCD_WR_REG(0x2c);//閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷峰啓
	}
}

void LCD_Init(void)
{
	SPI1_Init();
	W25QXX_Read(LCD_RO_Buff,1024*1024*135,sizeof(LCD_RO_Buff));
	USE_HORIZONTAL =atoi(LCD_RO_Buff);
	if(USE_HORIZONTAL==0){
		USE_HORIZONTAL =3;
	}
	LCD_GPIO_Init();//閿熸枻鎷峰閿熸枻鎷稧PIO
	
	LCD_RES_Clr();//閿熸枻鎷蜂綅
	Delay_ms(100);
	LCD_RES_Set();
	Delay_ms(100);
	
	LCD_BLK_Set();//閿熸触寮?鎲嬫嫹閿熸枻鎷?
	Delay_ms(100);
	
	LCD_WR_REG(0x11);     //Sleep out
	Delay_ms(120);                //Delay 120ms
	LCD_WR_REG(0xB1);     //Normal mode
	LCD_WR_DATA8(0x05);   
	LCD_WR_DATA8(0x3C);   
	LCD_WR_DATA8(0x3C);   
	LCD_WR_REG(0xB2);     //Idle mode
	LCD_WR_DATA8(0x05);   
	LCD_WR_DATA8(0x3C);   
	LCD_WR_DATA8(0x3C);   
	LCD_WR_REG(0xB3);     //Partial mode
	LCD_WR_DATA8(0x05);   
	LCD_WR_DATA8(0x3C);   
	LCD_WR_DATA8(0x3C);   
	LCD_WR_DATA8(0x05);   
	LCD_WR_DATA8(0x3C);   
	LCD_WR_DATA8(0x3C);   
	LCD_WR_REG(0xB4);     //Dot inversion
	LCD_WR_DATA8(0x03);   
	LCD_WR_REG(0xC0);     //AVDD GVDD
	LCD_WR_DATA8(0xAB);   
	LCD_WR_DATA8(0x0B);   
	LCD_WR_DATA8(0x04);   
	LCD_WR_REG(0xC1);     //VGH VGL
	LCD_WR_DATA8(0xC5);   //C0
	LCD_WR_REG(0xC2);     //Normal Mode
	LCD_WR_DATA8(0x0D);   
	LCD_WR_DATA8(0x00);   
	LCD_WR_REG(0xC3);     //Idle
	LCD_WR_DATA8(0x8D);   
	LCD_WR_DATA8(0x6A);   
	LCD_WR_REG(0xC4);     //Partial+Full
	LCD_WR_DATA8(0x8D);   
	LCD_WR_DATA8(0xEE);   
	LCD_WR_REG(0xC5);     //VCOM
	LCD_WR_DATA8(0x0F);   
	LCD_WR_REG(0xE0);     //positive gamma
	LCD_WR_DATA8(0x07);   
	LCD_WR_DATA8(0x0E);   
	LCD_WR_DATA8(0x08);   
	LCD_WR_DATA8(0x07);   
	LCD_WR_DATA8(0x10);   
	LCD_WR_DATA8(0x07);   
	LCD_WR_DATA8(0x02);   
	LCD_WR_DATA8(0x07);   
	LCD_WR_DATA8(0x09);   
	LCD_WR_DATA8(0x0F);   
	LCD_WR_DATA8(0x25);   
	LCD_WR_DATA8(0x36);   
	LCD_WR_DATA8(0x00);   
	LCD_WR_DATA8(0x08);   
	LCD_WR_DATA8(0x04);   
	LCD_WR_DATA8(0x10);   
	LCD_WR_REG(0xE1);     //negative gamma
	LCD_WR_DATA8(0x0A);   
	LCD_WR_DATA8(0x0D);   
	LCD_WR_DATA8(0x08);   
	LCD_WR_DATA8(0x07);   
	LCD_WR_DATA8(0x0F);   
	LCD_WR_DATA8(0x07);   
	LCD_WR_DATA8(0x02);   
	LCD_WR_DATA8(0x07);   
	LCD_WR_DATA8(0x09);   
	LCD_WR_DATA8(0x0F);   
	LCD_WR_DATA8(0x25);   
	LCD_WR_DATA8(0x35);   
	LCD_WR_DATA8(0x00);   
	LCD_WR_DATA8(0x09);   
	LCD_WR_DATA8(0x04);   
	LCD_WR_DATA8(0x10);
		 
	LCD_WR_REG(0xFC);    
	LCD_WR_DATA8(0x80);  
		
	LCD_WR_REG(0x3A);     
	LCD_WR_DATA8(0x05);   
	LCD_WR_REG(0x36);
	if(USE_HORIZONTAL==0)LCD_WR_DATA8(0x08);
	else if(USE_HORIZONTAL==1)LCD_WR_DATA8(0xC8);
	else if(USE_HORIZONTAL==2)LCD_WR_DATA8(0x78);
	else LCD_WR_DATA8(0xA8);   
	LCD_WR_REG(0x21);     //Display inversion
	LCD_WR_REG(0x29);     //Display on
	LCD_WR_REG(0x2A);     //Set Column Address
	LCD_WR_DATA8(0x00);   
	LCD_WR_DATA8(0x1A);  //26  
	LCD_WR_DATA8(0x00);   
	LCD_WR_DATA8(0x69);   //105 
	LCD_WR_REG(0x2B);     //Set Page Address
	LCD_WR_DATA8(0x00);   
	LCD_WR_DATA8(0x01);    //1
	LCD_WR_DATA8(0x00);   
	LCD_WR_DATA8(0xA0);    //160
	LCD_WR_REG(0x2C); 
	uint32_t i=50;
}







