#include "ws2812b.h"


void WS2812B_GPIO_Init(void)
{
	gpio_init_type gpio_Init;
	
	crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK,TRUE);
	gpio_default_para_init(&gpio_Init);
	
	gpio_Init.gpio_drive_strength =GPIO_DRIVE_STRENGTH_STRONGER;
	gpio_Init.gpio_mode =GPIO_MODE_OUTPUT;
	gpio_Init.gpio_out_type =GPIO_OUTPUT_PUSH_PULL;
	gpio_Init.gpio_pins =WS2812B_Bit;
	
	gpio_init(WS2812B,&gpio_Init);
	gpio_bits_write(WS2812B,WS2812B_Bit,TRUE);	
	
}

void WS2812B_Write_0(void){

	WS2812B->scr =WS2812B_Bit;	//高电平
	
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();
	WS2812B->clr =WS2812B_Bit; //低电平
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();	
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	
	

}
void WS2812B_Write_1(void){

	WS2812B->scr =WS2812B_Bit;	//高电平
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();	
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();

	WS2812B->clr =WS2812B_Bit; //低电平
	
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	
}
void WS2812B_RESET(void)
{
	WS2812B->clr =WS2812B_Bit;
	delay_us(80);
}

void RGB_Write_Byte(uint8_t byte){
	uint8_t i;
	for(i=0;i<8;i++){
		if(byte & 0x80){
			WS2812B_Write_1();
		}else{
			WS2812B_Write_0();
		}
		byte<<=1;
	}
}
void RGB_Write_ALL(uint8_t G,uint8_t R,uint8_t B){
	RGB_Write_Byte(G);
	RGB_Write_Byte(R);
	RGB_Write_Byte(B);
	WS2812B_RESET();
}