/**
  ******************************************************************************
  * @file    IWDG/IWDG_WindowMode/Src/stm32l0xx_hal_msp.c
  * @author  MCD Application Team
  * @brief   HAL MSP module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup STM32L0xx_HAL_Examples
  * @{
  */

/** @defgroup HAL_MSP
  * @brief HAL MSP module.
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup HAL_MSP_Private_Functions
  * @{
  */

/**
  * @brief IWDG MSP Initialization 
  *        This function configures the hardware resources used in this example: 
  *           - Peripheral's clock enable 
  *           - LSI enable 
  * @param hwwdg: IWDG handle pointer
  * @retval None
  */
void HAL_IWDG_MspInit(IWDG_HandleTypeDef* hiwdg)
{
  __HAL_RCC_PWR_CLK_ENABLE(); 

  HAL_PWR_EnableBkUpAccess();
  
  /*## Enable peripherals and GPIO Clocks ####################################*/
  /* RCC LSI clock enable */
  __HAL_RCC_LSI_ENABLE();
  
  /* Wait till LSI is ready */
  while (__HAL_RCC_GET_FLAG(RCC_FLAG_LSIRDY) == RESET)
  {} 
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
