/**
  ******************************************************************************
  * @file    COMP/COMP_AnalogWatchdog/Src/stm32l0xx_hal_msp.c 
  * @author  MCD Application Team
  * @brief   HAL MSP module.
  *          This file template is located in the HAL folder and should be copied 
  *          to the user folder.
  *    
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
#include "stm32l0xx_it.h"

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
GPIO_InitTypeDef   GPIO_InitStructure;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup HAL_MSP_Private_Functions
  * @{
  */
    
/**
* @brief   COMP MSP Init
* @param  hcomp : COMP handle
* @retval None
*/
void HAL_COMP_MspInit(COMP_HandleTypeDef *hcomp)
{      
  
  /* GPIOB Peripheral clock enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();
  
  /* Configure PAB4 in analog mode: PB4 is connected to COMP2 non inverting input */
  GPIO_InitStructure.Pin   = GPIO_PIN_4;
  GPIO_InitStructure.Mode  = GPIO_MODE_ANALOG; 
  GPIO_InitStructure.Pull  = GPIO_NOPULL;
  GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);
  
  /*## Configure the NVIC for COMP1 and COMP2 ###########################################*/
  HAL_NVIC_SetPriority(ADC1_COMP_IRQn,0,0);
  
  /* Enable the COMP1 and COMP2 global Interrupt */
  HAL_NVIC_EnableIRQ(ADC1_COMP_IRQn); 
}

/**
* @brief   COMP MSP DeInit
* @param  hcomp : COMP handle
* @retval None
*/
void HAL_COMP_MspDeInit(COMP_HandleTypeDef *hcomp)
{  
  __HAL_RCC_SYSCFG_CLK_DISABLE();
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
