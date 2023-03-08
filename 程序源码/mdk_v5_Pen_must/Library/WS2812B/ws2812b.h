#ifndef __WS2812B_H
#define __WS2812B_H

#include "at32f403a_407_board.h"
#include "at32f403a_407_clock.h"

#define WS2812B_Bit GPIO_PINS_0
#define WS2812B GPIOB
void WS2812B_GPIO_Init(void);
void WS2812B_Write_0(void);
void WS2812B_Write_1(void);
void WS2812B_RESET(void);
void RGB_Write_Byte(uint8_t byte);
void RGB_Write_ALL(uint8_t G,uint8_t R,uint8_t B);
#endif