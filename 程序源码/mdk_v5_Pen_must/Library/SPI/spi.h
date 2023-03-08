#ifndef __spi_H
#define __spi_H
#include "stdio.h"
#include "at32f403a_407.h"
extern spi_init_type spi_Init;

#define SPI2_CS_HIGH GPIOB->scr=GPIO_PINS_12
#define SPI2_CS_LOW  GPIOB->clr =GPIO_PINS_12

extern uint16_t SIZE_LEN;
#define Size 1
extern uint8_t buffsend[Size];

void SPI1_Init(void);
void DMA_Init(u32 adrr,u32 cmar,u16 len);
void MYDMA_Enable(u16 len);

void SPI2_Init(void);
u8 SPI2_ReadWriteByte(u8 dat);
#endif