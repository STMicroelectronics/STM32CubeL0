/**
  ******************************************************************************
  * @file    COMP/COMP_PWMSignalControl/Src/stm32l0xx_hal_msp.c
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

/** @defgroup COMP_PWMSignalControl
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* COMP handler declared in "main.c" file */
extern COMP_HandleTypeDef     hcomp1;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup HAL_MSP_Private_Functions
  * @{
  */

/**
  * @brief COMP MSP Initialization 
  *        This function configures the hardware resources used in this example:
  *           - Peripheral's clock enable
  * @param hcomp: COMP handle pointer
  * @retval None
  */
void HAL_COMP_MspInit(COMP_HandleTypeDef* hcomp)
{
  GPIO_InitTypeDef       GPIO_InitStruct;

  /*##-1- Enable peripherals and GPIO Clocks #################################*/

  /* Enable GPIO clock */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  
  /*##-2- Configure peripheral GPIO ##########################################*/ 
  /* COMP1 Analog GPIO pin configuration */
  GPIO_InitStruct.Pin   = GPIO_PIN_1;
  GPIO_InitStruct.Mode  = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull  = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  
}

/**
  * @brief LPTIM MSP Initialization 
  *        This function configures the hardware resources used in this example:
  *           - Peripheral's clock enable
  * @param hlptim: LPTIM handle pointer
  * @retval None
  */
void HAL_LPTIM_MspInit(LPTIM_HandleTypeDef *hlptim)
{
  GPIO_InitTypeDef     GPIO_InitStruct;
    
  /* Enable LPTIM clock */
  __HAL_RCC_LPTIM1_CLK_ENABLE();
  
  /* Force the CRYP Periheral Clock Reset */  
  __HAL_RCC_LPTIM1_FORCE_RESET(); 
  
  /* Release the CRYP Periheral Clock Reset */  
  __HAL_RCC_LPTIM1_RELEASE_RESET();
  
  /* GPIO configuration: LPTim OUT pin: PC1 */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  GPIO_InitStruct.Pin = GPIO_PIN_1 ;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF0_LPTIM1;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
    
}

/**
  * @brief  DeInitializes the COMP MSP.
  * @param  hcomp: pointer to a COMP_HandleTypeDef structure that contains
  *         the configuration information for the specified COMP.  
  * @retval None
  */
void HAL_COMP_MspDeInit(COMP_HandleTypeDef* hcomp)
{
  /*##-1- Reset peripherals ##################################################*/
  /* Disable COMP1 clock */
  __HAL_RCC_SYSCFG_CLK_DISABLE();
  /* Disable GPIO clock */
  __HAL_RCC_GPIOA_CLK_DISABLE();

  /*##-2- Disable peripherals and GPIO  ######################################*/
  /* De-Initialize COMP1 */
  HAL_COMP_DeInit(&hcomp1);
  /* De-initialize the GPIO pin */
  HAL_GPIO_DeInit(GPIOA, GPIO_PIN_1);
}

/**
  * @brief  DeInitializes the LPTIM MSP.
  * @param  hcomp: pointer to a LPTIM_HandleTypeDef structure that contains
  *         the configuration information for the specified LPTIM.  
  * @retval None
  */
void HAL_LPTIM_MspDeInit(LPTIM_HandleTypeDef *hlptim)
{   
  /* Disable LPTIM clock */
  __HAL_RCC_LPTIM1_CLK_DISABLE();
    
  /* Disable GPIOC clock */
  __HAL_RCC_GPIOC_CLK_DISABLE();    
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
