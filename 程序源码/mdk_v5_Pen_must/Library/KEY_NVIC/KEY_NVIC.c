#include "KEY_NVIC.h"

void KEY_Init(void)
{
	gpio_init_type gpio_init_struct;
 
  crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK, TRUE); 
  gpio_default_para_init(&gpio_init_struct);
 
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
  gpio_init_struct.gpio_out_type  = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_mode = GPIO_MODE_INPUT;
  gpio_init_struct.gpio_pins = GPIO_PINS_5|GPIO_PINS_4|GPIO_PINS_6;
  gpio_init_struct.gpio_pull = GPIO_PULL_DOWN;
  gpio_init(GPIOB, &gpio_init_struct);	
	//EXTI_Init();
	
}

void EXTI_Init(void){
	
	exint_init_type exti_Init;
	crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK,TRUE);
	crm_periph_clock_enable(CRM_IOMUX_PERIPH_CLOCK,TRUE);
	
	gpio_exint_line_config(GPIO_PORT_SOURCE_GPIOB,GPIO_PINS_SOURCE4|GPIO_PINS_SOURCE5|GPIO_PINS_SOURCE6);
	
	exint_default_para_init(&exti_Init);
	
	exti_Init.line_enable=TRUE;
	exti_Init.line_mode=EXINT_LINE_INTERRUPUT;
	exti_Init.line_polarity=EXINT_TRIGGER_FALLING_EDGE;
	exti_Init.line_select=EXINT_LINE_4|EXINT_LINE_5|EXINT_LINE_6;
	exint_init(&exti_Init);

  //nvic_priority_group_config(NVIC_PRIORITY_GROUP_4);
  nvic_irq_enable(EXINT4_IRQn, 0, 1);
	nvic_irq_enable(EXINT9_5_IRQn, 0, 2);
	nvic_irq_enable(EXINT9_5_IRQn, 0, 3);
}

void EXINT4_IRQHandler(void)
{
  if(exint_flag_get(EXINT_LINE_4) != RESET)
  {
		if(gpio_input_data_bit_read(GPIOB,GPIO_PINS_4)==0){
			printf("KEY_TRUE\r\n");
		}
    exint_flag_clear(EXINT_LINE_4);
  }
}
void EXINT9_5_IRQHandler(void)
{
  if(exint_flag_get(EXINT_LINE_5) != RESET)
  {
		if(gpio_input_data_bit_read(GPIOB,GPIO_PINS_5)==0){
			printf("KEY_LEFT\r\n");
		}
    exint_flag_clear(EXINT_LINE_5);
  }
	if(exint_flag_get(EXINT_LINE_6) != RESET)
  {
		if(gpio_input_data_bit_read(GPIOB,GPIO_PINS_6)==0){
			printf("KEY_RIGHT\r\n");
		}
    exint_flag_clear(EXINT_LINE_6);
  }
}