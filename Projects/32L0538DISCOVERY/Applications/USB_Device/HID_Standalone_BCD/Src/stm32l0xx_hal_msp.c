/**
  ******************************************************************************
  * @file    USB_Device/HID_Standalone_BCD/Src/stm32l0xx_hal_msp.c
  * @author  MCD Application Team
  * @brief   HAL MSP module.
  *         
  @verbatim
 ===============================================================================
                     ##### How to use this driver #####
 ===============================================================================
    [..]


  @endverbatim
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Initializes the Global MSP.
  * @param  None
  * @retval None
  */
void HAL_MspInit(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  /*##-1- Enable TSC and GPIO clocks #########################################*/
  __HAL_RCC_TSC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*##-2- Configure Sampling Capacitor IOs (Alternate-Function Open-Drain) ###*/
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Pull      = GPIO_NOPULL;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_LOW     ;
  GPIO_InitStruct.Alternate = GPIO_AF3_TSC;
  /* Channel Sampling Capacitor IO : TSC_GROUP1_IO4 = PA3, TSC_GROUP2_IO4 = PA7 */
  GPIO_InitStruct.Pin       = GPIO_PIN_3 | GPIO_PIN_7;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  /* Channel Sampling Capacitor IO : TSC_GROUP3_IO3 = PB1 */
  GPIO_InitStruct.Pin       = GPIO_PIN_1;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
  
  /*##-3- Configure Channel IOs (Alternate-Function Output PP) ######*/
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull      = GPIO_NOPULL;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_LOW     ;
  GPIO_InitStruct.Alternate = GPIO_AF3_TSC;
  /* Channel IO = TSC_GROUP1_IO3 = PA2 */
  /* Channel IO = TSC_GROUP2_IO3 = PA6 */
  GPIO_InitStruct.Pin       = GPIO_PIN_2 | GPIO_PIN_6;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  /* Channel IO = TSC_GROUP3_IO2 = PB0 */
  GPIO_InitStruct.Pin       = GPIO_PIN_0;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

/**
  * @brief  DeInitializes the Global MSP.
  * @param  None  
  * @retval None
  */
void HAL_MspDeInit(void)
{
  /*##-1- Reset peripherals ##################################################*/
  __HAL_RCC_TSC_FORCE_RESET();
  __HAL_RCC_TSC_RELEASE_RESET();

  /*##-2- Disable peripherals and GPIO Clocks ################################*/
  /* De-initialize the TSC GPIO pins */
  HAL_GPIO_DeInit(GPIOA, GPIO_PIN_2);
  HAL_GPIO_DeInit(GPIOA, GPIO_PIN_3);
  HAL_GPIO_DeInit(GPIOA, GPIO_PIN_4);
  HAL_GPIO_DeInit(GPIOA, GPIO_PIN_6);
  HAL_GPIO_DeInit(GPIOA, GPIO_PIN_7);
  HAL_GPIO_DeInit(GPIOB, GPIO_PIN_0);
  HAL_GPIO_DeInit(GPIOB, GPIO_PIN_1);
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
