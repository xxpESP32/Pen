
#include "at32f403a_407_int.h"
#include "FreeRTOS.h"
#include "task.h"

#define  EXTEND_SRAM  0xFE //ʹ��224K
#define  EXTEND_SRAM  0xFF //ʹ��96K

void SysTick_Handler(void)
{
#if (INCLUDE_xTaskGetSchedulerState == 1 )
if (xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED) 
	{
#endif 
  xPortSysTickHandler();
#if (INCLUDE_xTaskGetSchedulerState == 1 )
 }
#endif
	
}
void extend_sram(void)
{
  if(((USD->eopb0) & 0xFF) != EXTEND_SRAM)
  {
    /* FLASH���� */  
    flash_unlock();

    /* ����ѡ���ֽ� */
    flash_user_system_data_erase();

    /* ����SRAM��С*/
    flash_user_system_data_program((uint32_t)&USD->eopb0, EXTEND_SRAM);

    /* ϵͳ��λ������Ч */
    nvic_system_reset();
  }
}



void NMI_Handler(void)
{
}

/**
  * @brief  this function handles hard fault exception.
  * @param  none
  * @retval none
  */
void HardFault_Handler(void)
{
  /* go to infinite loop when hard fault exception occurs */
  while(1)
  {
  }
}

/**
  * @brief  this function handles memory manage exception.
  * @param  none
  * @retval none
  */
void MemManage_Handler(void)
{
  /* go to infinite loop when memory manage exception occurs */
  while(1)
  {
  }
}

/**
  * @brief  this function handles bus fault exception.
  * @param  none
  * @retval none
  */
void BusFault_Handler(void)
{
  /* go to infinite loop when bus fault exception occurs */
  while(1)
  {
  }
}

/**
  * @brief  this function handles usage fault exception.
  * @param  none
  * @retval none
  */
void UsageFault_Handler(void)
{
  /* go to infinite loop when usage fault exception occurs */
  while(1)
  {
  }
}

/**
  * @brief  this function handles svcall exception.
  * @param  none
  * @retval none
  */
/*void SVC_Handler(void)
{
}*/

/**
  * @brief  this function handles debug monitor exception.
  * @param  none
  * @retval none
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  this function handles pendsv_handler exception.
  * @param  none
  * @retval none
  */
/*void PendSV_Handler(void)
{
}*/

/**
  * @brief  this function handles systick handler.
  * @param  none
  * @retval none
  */


/**
  * @}
  */

/**
  * @}
  */
