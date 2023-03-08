#ifndef __KEY_NVIC_H
#define __KEY_NVIC_H
#ifdef  __cplusplus
extern "C"{
#endif

#include "at32f403a_407_board.h"
#include "at32f403a_407_clock.h"
#define KEY0 gpio_input_data_bit_read(GPIOB,GPIO_PINS_5)
#define KEY1 gpio_input_data_bit_read(GPIOB,GPIO_PINS_6)
#define KEY2 gpio_input_data_bit_read(GPIOB,GPIO_PINS_4)

void KEY_Init(void);
void EXTI_Init(void);


#ifdef __cplusplus
}
#endif

#endif