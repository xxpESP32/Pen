#include "spi.h"

uint16_t SIZE_LEN;
uint8_t buffsend[Size];

spi_init_type spi_Init;
spi_init_type spi2_Init;

dma_init_type dma_Init;

static void SPI2_GPIO_Init(void);

void DMA_Init(u32 adrr,u32 cmar,u16 len)
{
	crm_periph_clock_enable(CRM_DMA1_PERIPH_CLOCK,TRUE);
	dma_reset(DMA1_CHANNEL3);
	dma_default_para_init(&dma_Init);
	SIZE_LEN=len;
	dma_Init.peripheral_base_addr=adrr;
	dma_Init.memory_base_addr =cmar;
	dma_Init.direction=DMA_DIR_MEMORY_TO_PERIPHERAL ;
	dma_Init.buffer_size=len;
	dma_Init.peripheral_inc_enable=FALSE;
	dma_Init.memory_inc_enable=TRUE;
	dma_Init.peripheral_data_width=DMA_PERIPHERAL_DATA_WIDTH_BYTE ;
	dma_Init.memory_data_width=DMA_MEMORY_DATA_WIDTH_BYTE;
	dma_Init.loop_mode_enable= FALSE;
	dma_Init.priority=DMA_PRIORITY_VERY_HIGH;
	dma_init(DMA1_CHANNEL3,&dma_Init);
	
	nvic_irq_enable(DMA1_Channel3_IRQn,0,0);
	dma_interrupt_enable(DMA1_CHANNEL3,DMA_FDT_INT,TRUE);
	
		
}

void MYDMA_Enable(u16 len)
{
	dma_channel_enable(DMA1_CHANNEL3, FALSE);
	dma_data_number_set(DMA1_CHANNEL3, len);
	dma_channel_enable(DMA1_CHANNEL3, TRUE);
}

static void SPI_GPIO_Init(void)
{
	gpio_init_type gpio_Init;
	crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK,TRUE);
	gpio_default_para_init(&gpio_Init);

	  /* sck */
  gpio_Init.gpio_out_type       = GPIO_OUTPUT_PUSH_PULL;
  gpio_Init.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
  gpio_Init.gpio_pull           = GPIO_PULL_NONE;
  gpio_Init.gpio_mode           = GPIO_MODE_MUX;
  gpio_Init.gpio_pins           = GPIO_PINS_5;
  gpio_init(GPIOA, &gpio_Init);

  /* mosi */
  gpio_Init.gpio_out_type       = GPIO_OUTPUT_PUSH_PULL;
  gpio_Init.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;	
  gpio_Init.gpio_pull           = GPIO_PULL_NONE;
  gpio_Init.gpio_mode           = GPIO_MODE_MUX;
  gpio_Init.gpio_pins           = GPIO_PINS_7;
	gpio_init(GPIOA, &gpio_Init);
	
}

void SPI1_Init(void)
{
	SPI_GPIO_Init();
	crm_periph_clock_enable(CRM_SPI1_PERIPH_CLOCK,TRUE);
	spi_default_para_init(&spi_Init);
	
	spi_Init.transmission_mode =SPI_TRANSMIT_FULL_DUPLEX ;
	spi_Init.master_slave_mode=SPI_MODE_MASTER;
	spi_Init.mclk_freq_division=SPI_MCLK_DIV_2;
	spi_Init.first_bit_transmission=SPI_FIRST_BIT_MSB;
	spi_Init.frame_bit_num=SPI_FRAME_8BIT;
	spi_Init.clock_phase=SPI_CLOCK_PHASE_2EDGE;
	spi_Init.clock_polarity=SPI_CLOCK_POLARITY_HIGH;
	spi_Init.cs_mode_selection =SPI_CS_SOFTWARE_MODE;	
	spi_init(SPI1,&spi_Init);	
	spi_crc_polynomial_set(SPI1,7);	
  spi_crc_enable(SPI1,FALSE);	
	
	//nvic_irq_enable(SPI1_IRQn, 0, 0);
  //spi_i2s_interrupt_enable(SPI1, SPI_I2S_TDBE_INT, TRUE);
	
	spi_enable(SPI1,TRUE);
}

static void SPI2_GPIO_Init(void)
{
	gpio_init_type GPIO_Init;
	crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK,TRUE);
	/* Mosi¡¢Sclk and Miso*/
	GPIO_Init.gpio_drive_strength= GPIO_DRIVE_STRENGTH_STRONGER;
	GPIO_Init.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
	GPIO_Init.gpio_mode = GPIO_MODE_MUX;
	GPIO_Init.gpio_pins = GPIO_PINS_15|GPIO_PINS_14|GPIO_PINS_13;
	GPIO_Init.gpio_pull = GPIO_PULL_UP;
	
	gpio_init(GPIOB,&GPIO_Init);
	
	/* CS */
	GPIO_Init.gpio_mode = GPIO_MODE_OUTPUT;
	GPIO_Init.gpio_pins = GPIO_PINS_12;
	GPIO_Init.gpio_pull = GPIO_PULL_UP;

	gpio_init(GPIOB,&GPIO_Init);
	GPIOB->scr =GPIO_PINS_12;
	
}

void SPI2_Init(void)
{
	SPI2_GPIO_Init();
	crm_periph_clock_enable(CRM_SPI2_PERIPH_CLOCK,TRUE);
	spi_default_para_init(&spi2_Init);
	
	spi2_Init.master_slave_mode =SPI_MODE_MASTER;
	spi2_Init.transmission_mode =SPI_TRANSMIT_FULL_DUPLEX;
	spi2_Init.mclk_freq_division =SPI_MCLK_DIV_2;
	spi2_Init.frame_bit_num =SPI_FRAME_8BIT;
	spi2_Init.first_bit_transmission =SPI_FIRST_BIT_MSB;
	spi2_Init.cs_mode_selection =SPI_CS_SOFTWARE_MODE;
	spi2_Init.clock_polarity =SPI_CLOCK_POLARITY_HIGH;
	spi2_Init.clock_phase =SPI_CLOCK_PHASE_2EDGE;
	
	spi_init(SPI2,&spi2_Init);	
	spi_crc_polynomial_set(SPI2,7);	
  spi_crc_enable(SPI2,FALSE);
	
	spi_enable(SPI2,TRUE);
}

u8 SPI2_ReadWriteByte(u8 dat)
{
	//SPI1->dt=dat;
	//while(spi_i2s_flag_get(SPI1, SPI_I2S_TDBE_FLAG) == RESET);
	u8 retry=0;
	while(spi_i2s_flag_get(SPI2, SPI_I2S_TDBE_FLAG) == RESET)
	{
		retry++;
		if(retry ==200){
			return 0;
		}
	}
	SPI2->dt=dat;
	retry =0;
	
	while(spi_i2s_flag_get(SPI2,SPI_I2S_RDBF_FLAG) == RESET){
		retry++;
		if(retry ==200){
			return 0;
		}
	}
	return spi_i2s_data_receive(SPI2);
}
