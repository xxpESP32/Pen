/**
  **************************************************************************
  * @file     rtc.h
  * @version  v2.1.2
  * @date     2022-08-16
  * @brief    this file provides template for calendar api.
  **************************************************************************
  *                       Copyright notice & Disclaimer
  *
  * The software Board Support Package (BSP) that is made available to
  * download from Artery official website is the copyrighted work of Artery.
  * Artery authorizes customers to use, copy, and distribute the BSP
  * software and its related documentation for the purpose of design and
  * development in conjunction with Artery microcontrollers. Use of the
  * software is governed by this copyright notice and the following disclaimer.
  *
  * THIS SOFTWARE IS PROVIDED ON "AS IS" BASIS WITHOUT WARRANTIES,
  * GUARANTEES OR REPRESENTATIONS OF ANY KIND. ARTERY EXPRESSLY DISCLAIMS,
  * TO THE FULLEST EXTENT PERMITTED BY LAW, ALL EXPRESS, IMPLIED OR
  * STATUTORY OR OTHER WARRANTIES, GUARANTEES OR REPRESENTATIONS,
  * INCLUDING BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.
  *
  **************************************************************************
  */

#ifndef __RTC_H
#define __RTC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "at32f403a_407.h"

/** @addtogroup AT32F403A_periph_examples
  * @{
  */

/** @addtogroup 403A_RTC_calendar
  * @{
  */

/** @defgroup RTC_calendar_type
  * @{
  */

typedef struct
{
  uint16_t year;       /*!< specifies the years of calendar.   */
   uint8_t  month;      /*!< specifies the months of calendar.  */
   uint8_t  date;       /*!< specifies the date of calendar.    */
   uint8_t  hour;       /*!< specifies the hours of calendar.   */
   uint8_t  min;        /*!< specifies the minutes of calendar. */
   uint8_t  sec;        /*!< specifies the second of calendar.  */
   uint8_t  week;       /*!< specifies the weeks of calendar.   */
} calendar_type;

/**
  * @}
  */

extern calendar_type calendar;
//extern const char weekday_table[7][10] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
/** @defgroup RTC_calendar_exported_functions
  * @{
  */

uint8_t rtc_init            (calendar_type *calendar);
uint8_t rtc_time_set        (calendar_type *calendar);
uint8_t rtc_alarm_clock_set (calendar_type *calendar);
void    rtc_time_get        (void);
void alarm_init(void);
void RTC_Init(void);
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
