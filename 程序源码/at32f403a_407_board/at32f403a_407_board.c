
#include "at32f403a_407_board.h"

#define STEP_DELAY_MS 50

/* delay variable */
static __IO uint32_t fac_us;
static __IO uint32_t fac_ms;
#if 1
dma_init_type DMA_USART;
u8 DMA_Buff[1028];
u8 DMA_Buff_1[1028];
u8 GBK_BUF_Flag=2;
#endif

/* support printf function, usemicrolib is unnecessary */
#if (__ARMCC_VERSION > 6000000)
  __asm (".global __use_no_semihosting\n\t");
  void _sys_exit(int x)
  {
    x = x;
  }
  /* __use_no_semihosting was requested, but _ttywrch was */
  void _ttywrch(int ch)
  {
    ch = ch;
  }
  FILE __stdout;
#else
 #ifdef __CC_ARM
  #pragma import(__use_no_semihosting)
  struct __FILE
  {
    int handle;
  };
  FILE __stdout;
  void _sys_exit(int x)
  {
    x = x;
  }
  /* __use_no_semihosting was requested, but _ttywrch was */
  void _ttywrch(int ch)
  {
    ch = ch;
  }
 #endif
#endif

#if defined (__GNUC__) && !defined (__clang__)
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

/**
  * @brief  retargets the c library printf function to the usart.
  * @param  none
  * @retval none
  */
PUTCHAR_PROTOTYPE
{
  while(usart_flag_get(PRINT_UART, USART_TDBE_FLAG) == RESET);
  usart_data_transmit(PRINT_UART, ch);
  return ch;
}

#if defined (__GNUC__) && !defined (__clang__)
int _write(int fd, char *pbuffer, int size)
{
  for(int i = 0; i < size; i ++)
  {
    __io_putchar(*pbuffer++);
  }

  return size;
}
#endif

/**
  * @brief  initialize uart
  * @param  baudrate: uart baudrate
  * @retval none
  */
void uart_print_init(uint32_t baudrate)
{
  gpio_init_type gpio_init_struct;

#if defined (__GNUC__) && !defined (__clang__)
  setvbuf(stdout, NULL, _IONBF, 0);
#endif

  /* enable the uart and gpio clock */
  crm_periph_clock_enable(PRINT_UART_CRM_CLK, TRUE);
  crm_periph_clock_enable(PRINT_UART_TX_GPIO_CRM_CLK, TRUE);

  gpio_default_para_init(&gpio_init_struct);

  /* configure the uart tx pin */
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
  gpio_init_struct.gpio_out_type  = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
  gpio_init_struct.gpio_pins = PRINT_UART_TX_PIN;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init(PRINT_UART_TX_GPIO, &gpio_init_struct);

	/* configure the uart rx pin */
	gpio_init_struct.gpio_drive_strength =GPIO_DRIVE_STRENGTH_STRONGER;
	gpio_init_struct.gpio_mode =GPIO_MODE_INPUT;
	gpio_init_struct.gpio_out_type =GPIO_OUTPUT_PUSH_PULL;
	gpio_init_struct.gpio_pins = PRINT_UART_RX_PIN;
	gpio_init_struct.gpio_pull = GPIO_PULL_UP;
	gpio_init(PRINT_UART_TX_GPIO, &gpio_init_struct);
	
	/* configure uart NVIC */
	nvic_irq_enable(USART1_IRQn,2,2);
	usart_interrupt_enable(USART1,USART_IDLE_INT,TRUE);
	//usart_flag_clear(USART1,USART_TDC_FLAG);
  /* configure uart param */
  usart_init(PRINT_UART, baudrate, USART_DATA_8BITS, USART_STOP_1_BIT);
  usart_transmitter_enable(PRINT_UART, TRUE);
	usart_receiver_enable(PRINT_UART,TRUE);

	usart_dma_receiver_enable(USART1,TRUE);
  usart_enable(PRINT_UART, TRUE);
		DMA_USART_Init((u32)(&USART1->dt),(u32)DMA_Buff,1028);

	
}
void DMA_USART_Init(u32 pddr,u32 mddr,u16 buff_size){
	crm_periph_clock_enable(CRM_DMA1_PERIPH_CLOCK,TRUE);
	dma_reset(DMA1_CHANNEL5);
	dma_default_para_init(&DMA_USART);
	
	DMA_USART.peripheral_base_addr =pddr;
	DMA_USART.memory_base_addr =mddr;
	DMA_USART.buffer_size = buff_size;
	DMA_USART.direction = DMA_DIR_PERIPHERAL_TO_MEMORY;
	DMA_USART.loop_mode_enable =TRUE;
	DMA_USART.memory_data_width =DMA_MEMORY_DATA_WIDTH_BYTE;
	DMA_USART.peripheral_data_width =DMA_PERIPHERAL_DATA_WIDTH_BYTE;
	DMA_USART.memory_inc_enable = TRUE;
	DMA_USART.peripheral_inc_enable =FALSE;
	DMA_USART.priority =DMA_PRIORITY_VERY_HIGH;
	dma_init(DMA1_CHANNEL5,&DMA_USART);
	
	nvic_irq_enable(DMA1_Channel5_IRQn,0,0);
  dma_interrupt_enable(DMA1_CHANNEL5,DMA_FDT_INT,TRUE);
	dma_channel_enable(DMA1_CHANNEL5,TRUE);
	//dma_flexible_config(DMA1, FLEX_CHANNEL5, DMA_FLEXIBLE_UART1_RX);
}
void DMA_Enable(void)
{
	//DMA_USART_Init((u32)(&USART1->dt),(u32)DMA_Buff,1028);
	dma_channel_enable(DMA1_CHANNEL5,FALSE);
	//DMA_USART_Init((u32)(&USART1->dt),(u32)DMA_Buff,1028);
	GBK_BUF_Flag=0;
	dma_data_number_set(DMA1_CHANNEL5,1028);
	dma_channel_enable(DMA1_CHANNEL5,TRUE);
}


void USART1_IRQHandler(void){
		 u8 clear=clear;
	if(usart_flag_get(USART1,USART_IDLEF_FLAG)!= RESET){
		 //usart_flag_clear(USART1,USART_IDLEF_FLAG);
		 clear=USART1->sts;
		 clear=USART1->dt;
		 DMA_Enable();
	}
	
	
}


void at32_board_init()
{
  /* initialize delay function */
  delay_init();

  /* configure led in at_start_board */
  at32_led_init(LED2);
  at32_led_init(LED3);
  at32_led_init(LED4);
  at32_led_off(LED2);
  at32_led_off(LED3);
  at32_led_off(LED4);

  /* configure button in at_start board */
  at32_button_init();
}

/**
  * @brief  configure button gpio
  * @param  button: specifies the button to be configured.
  * @retval none
  */
void at32_button_init(void)
{
	/*
  gpio_init_type gpio_init_struct;

 
  crm_periph_clock_enable(USER_BUTTON_CRM_CLK, TRUE);

  
  gpio_default_para_init(&gpio_init_struct);

 
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
  gpio_init_struct.gpio_out_type  = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_mode = GPIO_MODE_INPUT;
  gpio_init_struct.gpio_pins = USER_BUTTON_PIN;
  gpio_init_struct.gpio_pull = GPIO_PULL_DOWN;
  gpio_init(USER_BUTTON_PORT, &gpio_init_struct);*/
}

/**
  * @brief  returns the selected button state
  * @param  none
  * @retval the button gpio pin value
  */
uint8_t at32_button_state(void)
{
  return gpio_input_data_bit_read(USER_BUTTON_PORT, USER_BUTTON_PIN);
}

/**
  * @brief  returns which button have press down
  * @param  none
  * @retval the button have press down
  */
button_type at32_button_press()
{
  static uint8_t pressed = 1;
  /* get button state in at_start board */
  if((pressed == 1) && (at32_button_state() != RESET))
  {
    /* debounce */
    pressed = 0;
    delay_ms(10);
    if(at32_button_state() != RESET)
      return USER_BUTTON;
  }
  else if(at32_button_state() == RESET)
  {
    pressed = 1;
  }
  return NO_BUTTON;
}

/**
  * @brief  configure led gpio
  * @param  led: specifies the led to be configured.
  * @retval none
  */
void at32_led_init(led_type led)
{
/*  gpio_init_type gpio_init_struct;

  
  crm_periph_clock_enable(led_gpio_crm_clk[led], TRUE);

  
  gpio_default_para_init(&gpio_init_struct);


  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
  gpio_init_struct.gpio_out_type  = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_mode = GPIO_MODE_OUTPUT;
  gpio_init_struct.gpio_pins = led_gpio_pin[led];
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init(led_gpio_port[led], &gpio_init_struct);*/
}

/**
  * @brief  turns selected led on.
  * @param  led: specifies the led to be set on.
  *   this parameter can be one of following parameters:
  *     @arg LED2
  *     @arg LED3
  *     @arg LED4
  * @retval none
  */
void at32_led_on(led_type led)
{
/*  if(led > (LED_NUM - 1))
    return;
  if(led_gpio_pin[led])
    led_gpio_port[led]->clr = led_gpio_pin[led];*/
}

/**
  * @brief  turns selected led off.
  * @param  led: specifies the led to be set off.
  *   this parameter can be one of following parameters:
  *     @arg LED2
  *     @arg LED3
  *     @arg LED4
  * @retval none
  */
void at32_led_off(led_type led)
{
 /* if(led > (LED_NUM - 1))
    return;
  if(led_gpio_pin[led])
    led_gpio_port[led]->scr = led_gpio_pin[led];*/
}

/**
  * @brief  turns selected led toggle.
  * @param  led: specifies the led to be set off.
  *   this parameter can be one of following parameters:
  *     @arg LED2
  *     @arg LED3
  *     @arg LED4
  * @retval none
  */
void at32_led_toggle(led_type led)
{
/*  if(led > (LED_NUM - 1))
    return;
  if(led_gpio_pin[led])
    led_gpio_port[led]->odt ^= led_gpio_pin[led];*/
}

/**
  * @brief  initialize delay function
  * @param  none
  * @retval none
  */
void delay_init()
{
  /* configure systick */
  systick_clock_source_config(SYSTICK_CLOCK_SOURCE_AHBCLK_NODIV);
  fac_us = system_core_clock / (1000000U);
  fac_ms = fac_us * (1000U);
}

/**
  * @brief  inserts a delay time.
  * @param  nus: specifies the delay time length, in microsecond.
  * @retval none
  */

void Delay_US(uint32_t nus)
{
  uint32_t temp = 0;
  SysTick->LOAD = (uint32_t)(nus * fac_us);
  SysTick->VAL = 0x00;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk ;
  do
  {
    temp = SysTick->CTRL;
  }while((temp & 0x01) && !(temp & (1 << 16)));

  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
  SysTick->VAL = 0x00;
}

//在此函数中加入初始化sysytick定时器步骤
//参照正点原子例程进行修改
void delay_us(u32 nus)
{
       u32 ticks;
       u32 told,tnow,reload,tcnt=0;
       if((0x0001&(SysTick->CTRL)) ==0)    //定时器未工作
              vPortSetupTimerInterrupt();  //初始化定时器
 
       reload = SysTick->LOAD;                     //获取重装载寄存器值
       ticks = nus * (SystemCoreClock / 1000000);  //计数时间值
       told=SysTick->VAL;                          //获取当前数值寄存器值（开始时数值）
 
       while(1)
       {
              tnow=SysTick->VAL;          //获取当前数值寄存器值
              if(tnow!=told)              //当前值不等于开始值说明已在计数
              {         
 
                     if(tnow<told)             //当前值小于开始数值，说明未计到0
                          tcnt+=told-tnow;     //计数值=开始值-当前值
 
                     else                  //当前值大于开始数值，说明已计到0并重新计数
                            tcnt+=reload-tnow+told;   //计数值=重装载值-当前值+开始值  （已
                                                      //从开始值计到0） 
 
                     told=tnow;                //更新开始值
                     if(tcnt>=ticks)break;     //时间超过/等于要延迟的时间,则退出.
              } 
       }     
}
 


/**
  * @brief  inserts a delay time.
  * @param  nms: specifies the delay time length, in milliseconds.
  * @retval none
  */
void delay_ms(uint16_t nms)
{
	vTaskDelay(nms);
}

void Delay_ms(uint16_t nms)
{
  uint32_t temp = 0;
 while(nms)
 {
    if(nms > STEP_DELAY_MS)
    {
      SysTick->LOAD = (uint32_t)(STEP_DELAY_MS * fac_ms);
      nms -= STEP_DELAY_MS;
    }
    else
    {
      SysTick->LOAD = (uint32_t)(nms * fac_ms);
      nms = 0;
    }
    SysTick->VAL = 0x00;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
    do
    {
      temp = SysTick->CTRL;
    }while((temp & 0x01) && !(temp & (1 << 16)));

    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    SysTick->VAL = 0x00;
  }
	

}
/**
  * @brief  inserts a delay time.
  * @param  sec: specifies the delay time, in seconds.
  * @retval none
  */
void delay_sec(uint16_t sec)
{
  uint16_t index;
  for(index = 0; index < sec; index++)
  {
    delay_ms(500);
    delay_ms(500);
  }
}

/**
  * @}
  */

/**
  * @}
  */

