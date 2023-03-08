#include "ADC.h"
adc_base_config_type adc_Struct;
float OUTPUT_ADC;


void ADC_GPIO_Init(void){
	
	gpio_init_type gpio_Struct;
	crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK,TRUE);
	gpio_default_para_init(&gpio_Struct);
	
	gpio_Struct.gpio_mode =GPIO_MODE_ANALOG;
	gpio_Struct.gpio_pins =GPIO_PINS_1;

	gpio_init(GPIOB,&gpio_Struct);
		
}



void ADC_Init(void){
	ADC_GPIO_Init();
	

	
	crm_periph_clock_enable(CRM_ADC1_PERIPH_CLOCK,TRUE);
	crm_adc_clock_div_set(CRM_ADC_DIV_6);
	
  adc_combine_mode_select(ADC_INDEPENDENT_MODE);
	adc_base_default_para_init(&adc_Struct);
	
  adc_Struct.data_align = ADC_RIGHT_ALIGNMENT;
	adc_Struct.ordinary_channel_length =1;
	adc_Struct.repeat_mode = TRUE;
	adc_Struct.sequence_mode =TRUE;
	
	adc_base_config(ADC1, &adc_Struct);
	
	adc_ordinary_channel_set(ADC1, ADC_CHANNEL_9, 1, ADC_SAMPLETIME_55_5);
	//adc_ordinary_channel_set(ADC1, ADC_CHANNEL_17, 2, ADC_SAMPLETIME_55_5);
	
	adc_ordinary_conversion_trigger_set(ADC1, ADC12_ORDINARY_TRIG_SOFTWARE, TRUE);
	


	adc_enable(ADC1, TRUE);
	//adc_tempersensor_vintrv_enable(TRUE);//打开内部参考电压
	//adc_reset(ADC1);
	adc_calibration_init(ADC1);
  while(adc_calibration_init_status_get(ADC1));
  adc_calibration_start(ADC1);
  while(adc_calibration_status_get(ADC1));
	
}

float ADC_GET_Value(void){
	u16 i;
	float dat=0;
	float vrif =0;
	adc_ordinary_channel_set(ADC1, ADC_CHANNEL_9, 1, ADC_SAMPLETIME_239_5);	
	adc_ordinary_software_trigger_enable(ADC1, TRUE);
	dat=adc_ordinary_conversion_data_get(ADC1);
	

	/*adc_ordinary_channel_set(ADC1, ADC_CHANNEL_17, 1, ADC_SAMPLETIME_239_5);
	adc_ordinary_software_trigger_enable(ADC1, TRUE);
	vrif=adc_ordinary_conversion_data_get(ADC1);
	*/
	
	//dat=(vrif/dat)*1.20;
	dat =(dat*2.5)/4095;

	OUTPUT_ADC=dat;

	
	
	return dat;
}