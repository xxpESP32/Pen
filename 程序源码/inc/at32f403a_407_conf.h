#ifndef __AT32F403A_407_CONF_H
#define __AT32F403A_407_CONF_H

#ifdef __cplusplus
extern "C" {
#endif



#if !defined  HEXT_VALUE
#define HEXT_VALUE               ((uint32_t)12000000) /*!< value of the high speed exernal crystal in hz */
#endif


#define HEXT_STARTUP_TIMEOUT     ((uint16_t)0x3000) /*!< time out for hext start up */
#define HICK_VALUE               ((uint32_t)8000000) /*!< value of the high speed internal clock in hz */

/* module define -------------------------------------------------------------*/
#define CRM_MODULE_ENABLED
#define TMR_MODULE_ENABLED
#define RTC_MODULE_ENABLED
#define BPR_MODULE_ENABLED
#define GPIO_MODULE_ENABLED
#define I2C_MODULE_ENABLED
#define USART_MODULE_ENABLED
#define PWC_MODULE_ENABLED
#define CAN_MODULE_ENABLED
#define ADC_MODULE_ENABLED
#define DAC_MODULE_ENABLED
#define SPI_MODULE_ENABLED
#define DMA_MODULE_ENABLED
#define DEBUG_MODULE_ENABLED
#define FLASH_MODULE_ENABLED
#define CRC_MODULE_ENABLED
#define WWDT_MODULE_ENABLED
#define WDT_MODULE_ENABLED
#define EXINT_MODULE_ENABLED
#define SDIO_MODULE_ENABLED
#define XMC_MODULE_ENABLED
#define USB_MODULE_ENABLED
#define ACC_MODULE_ENABLED
#define MISC_MODULE_ENABLED
#define EMAC_MODULE_ENABLED

/* includes ------------------------------------------------------------------*/
#ifdef CRM_MODULE_ENABLED
#include "at32f403a_407_crm.h"
#endif
#ifdef TMR_MODULE_ENABLED
#include "at32f403a_407_tmr.h"
#endif
#ifdef RTC_MODULE_ENABLED
#include "at32f403a_407_rtc.h"
#endif
#ifdef BPR_MODULE_ENABLED
#include "at32f403a_407_bpr.h"
#endif
#ifdef GPIO_MODULE_ENABLED
#include "at32f403a_407_gpio.h"
#endif
#ifdef I2C_MODULE_ENABLED
#include "at32f403a_407_i2c.h"
#endif
#ifdef USART_MODULE_ENABLED
#include "at32f403a_407_usart.h"
#endif
#ifdef PWC_MODULE_ENABLED
#include "at32f403a_407_pwc.h"
#endif
#ifdef CAN_MODULE_ENABLED
#include "at32f403a_407_can.h"
#endif
#ifdef ADC_MODULE_ENABLED
#include "at32f403a_407_adc.h"
#endif
#ifdef DAC_MODULE_ENABLED
#include "at32f403a_407_dac.h"
#endif
#ifdef SPI_MODULE_ENABLED
#include "at32f403a_407_spi.h"
#endif
#ifdef DMA_MODULE_ENABLED
#include "at32f403a_407_dma.h"
#endif
#ifdef DEBUG_MODULE_ENABLED
#include "at32f403a_407_debug.h"
#endif
#ifdef FLASH_MODULE_ENABLED
#include "at32f403a_407_flash.h"
#endif
#ifdef CRC_MODULE_ENABLED
#include "at32f403a_407_crc.h"
#endif
#ifdef WWDT_MODULE_ENABLED
#include "at32f403a_407_wwdt.h"
#endif
#ifdef WDT_MODULE_ENABLED
#include "at32f403a_407_wdt.h"
#endif
#ifdef EXINT_MODULE_ENABLED
#include "at32f403a_407_exint.h"
#endif
#ifdef SDIO_MODULE_ENABLED
#include "at32f403a_407_sdio.h"
#endif
#ifdef XMC_MODULE_ENABLED
#include "at32f403a_407_xmc.h"
#endif
#ifdef ACC_MODULE_ENABLED
#include "at32f403a_407_acc.h"
#endif
#ifdef MISC_MODULE_ENABLED
#include "at32f403a_407_misc.h"
#endif
#ifdef USB_MODULE_ENABLED
#include "at32f403a_407_usb.h"
#endif
#ifdef EMAC_MODULE_ENABLED
#include "at32f403a_407_emac.h"
#endif

/**
  * @}
  */

  /**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif
