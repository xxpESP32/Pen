

#ifndef __AT32F403A_407_BOARD_H
#define __AT32F403A_407_BOARD_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stdio.h"
#include "at32f403a_407.h"

/** @addtogroup AT32F403A_407_board
  * @{
  */

/** @addtogroup BOARD
  * @{
  */

/** @defgroup BOARD_pins_definition
  * @{
  */

/**
  * this header include define support list:
  * 1. at-start-f403a v1.x board
  * 2. at-start-f407 v1.x board
  * if define AT_START_F403A_V1, the header file support at-start-f403a v1.x board
  * if define AT_START_F407_V1, the header file support at-start-f407 v1.x board
  */

#if !defined (AT_START_F403A_V1)&& !defined (AT_START_F407_V1)
#error "please select first the board at-start device used in your application (in at32f403a_407_board.h file)"
#endif

/******************** define led ********************/
typedef enum
{
  LED2                                   = 0,
  LED3                                   = 1,
  LED4                                   = 2
} led_type;

#define LED_NUM                          3

#if defined (AT_START_F403A_V1) || defined (AT_START_F407_V1)
#define LED2_PIN                         GPIO_PINS_0
#define LED2_GPIO                        GPIOA
#define LED2_GPIO_CRM_CLK                CRM_GPIOA_PERIPH_CLOCK

#define LED3_PIN                         GPIO_PINS_1
#define LED3_GPIO                        GPIOA
#define LED3_GPIO_CRM_CLK                CRM_GPIOA_PERIPH_CLOCK

#define LED4_PIN                         GPIO_PINS_2
#define LED4_GPIO                        GPIOA
#define LED4_GPIO_CRM_CLK                CRM_GPIOA_PERIPH_CLOCK
#endif

/**************** define print uart ******************/
#define PRINT_UART                       USART1
#define PRINT_UART_CRM_CLK               CRM_USART1_PERIPH_CLOCK
#define PRINT_UART_TX_PIN                GPIO_PINS_9
#define PRINT_UART_TX_GPIO               GPIOA
#define PRINT_UART_TX_GPIO_CRM_CLK       CRM_GPIOA_PERIPH_CLOCK
#define PRINT_UART_RX_PIN                GPIO_PINS_10;

extern u8 DMA_Buff[1028];
extern u8 DMA_Buff_1[1028];
extern u8 GBK_BUF_Flag;
/******************* define button *******************/
typedef enum
{
  USER_BUTTON                            = 0,
  NO_BUTTON                              = 1
} button_type;

#define USER_BUTTON_PIN                  GPIO_PINS_2
#define USER_BUTTON_PORT                 GPIOB
#define USER_BUTTON_CRM_CLK              CRM_GPIOB_PERIPH_CLOCK

/**
  * @}
  */

/** @defgroup BOARD_exported_functions
  * @{
  */

/******************** functions ********************/
void at32_board_init(void);
void DMA_USART_Init(u32 pddr,u32 mddr,u16 buff_size);
/* led operation function */
void at32_led_init(led_type led);
void at32_led_on(led_type led);
void at32_led_off(led_type led);
void at32_led_toggle(led_type led);

/* button operation function */
void at32_button_init(void);
button_type at32_button_press(void);
uint8_t at32_button_state(void);

/* delay function */
void delay_init(void);
void delay_us(uint32_t nus);
void delay_ms(uint16_t nms);
void delay_sec(uint16_t sec);
void Delay_ms(uint16_t nms);
/* printf uart init function */
void uart_print_init(uint32_t baudrate);
void Delay_US(uint32_t nus);
/**
  * @}
  */

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

