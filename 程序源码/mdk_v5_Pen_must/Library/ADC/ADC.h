#ifndef __ADC_H
#define __ADC_H
#include "at32f403a_407_board.h"
#include "at32f403a_407_clock.h"

extern float OUTPUT_ADC;
void ADC_GPIO_Init(void);
void ADC_Init(void);
float ADC_GET_Value(void);

#endif