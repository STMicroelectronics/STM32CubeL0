/**
  ******************************************************************************
  * @file    stm32l152c_discovery.c
  * @author  MCD Application Team
  * @brief   This file provides a set of firmware functions to manage LEDs and 
  *          push-buttons available on stm32l152c_discovery board(MB963) RevC from STMicroelectronics.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */ 
  
/* File Info: ------------------------------------------------------------------

------------------------------------------------------------------------------*/

/* Includes ------------------------------------------------------------------*/
#include "stm32l152c_discovery.h"


/** @addtogroup STM32L152C_DISCOVERY
  * @{
  */   
    
/** @defgroup STM32L152C_DISCOVERY_LOW_LEVEL 
  * @{
  */

/** @defgroup STM32L152C_DISCOVERY_LOW_LEVEL_Private_Defines
  * @{
  */                                
/**
  * @}
  */ 

/** @defgroup STM32L152C_DISCOVERY_LOW_LEVEL_Private_Macros
  * @{
  */ 
/**
  * @}
  */ 

/** @defgroup STM32L152C_DISCOVERY_LOW_LEVEL_Private_Variables
  * @{
  */ 
GPIO_TypeDef* GPIO_PORT[LEDn] = {LED3_GPIO_PORT, LED4_GPIO_PORT};

const uint16_t GPIO_PIN[LEDn] = {LED3_PIN, LED4_PIN};
                                
GPIO_TypeDef* BUTTON_PORT[BUTTONn] = {KEY_BUTTON_GPIO_PORT};

const uint16_t BUTTON_PIN[BUTTONn] = {KEY_BUTTON_PIN};

const uint16_t BUTTON_IRQn[BUTTONn] = {KEY_BUTTON_EXTI_IRQn};
/**
  * @}
  */ 

/** @defgroup STM32L152C_DISCOVERY_LOW_LEVEL_Private_FunctionPrototypes
  * @{
  */ 
/**
  * @}
  */ 

/** @defgroup STM32L152C_DISCOVERY_LOW_LEVEL_Private_Functions
  * @{
  */

/**
  * @brief  Configures LED GPIO.
  * @param  Led: LED to be configured. 
  *          This parameter can be one of the following values:
  *            @arg  LED3
  *            @arg  LED4
  * @retval None
  */
void BSP_LED_Init(Led_TypeDef Led)
{
  GPIO_InitTypeDef  GPIO_InitStruct;
  
  /* Enable the GPIO_LED clock */
  LEDx_GPIO_CLK_ENABLE(Led);

  /* Configure the GPIO_LED pin */
  GPIO_InitStruct.Pin = GPIO_PIN[Led];
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH  ;
  
  HAL_GPIO_Init(GPIO_PORT[Led], &GPIO_InitStruct);
}

/**
  * @brief  Turns selected LED On.
  * @param  Led: LED to be set on 
  *          This parameter can be one of the following values:
  *            @arg  LED2
  * @retval None
  */
void BSP_LED_On(Led_TypeDef Led)
{
  HAL_GPIO_WritePin(GPIO_PORT[Led], GPIO_PIN[Led], GPIO_PIN_SET); 
}

/**
  * @brief  Turns selected LED Off. 
  * @param  Led: LED to be set off
  *          This parameter can be one of the following values:
  *            @arg  LED3
  *            @arg  LED4
  * @retval None
  */
void BSP_LED_Off(Led_TypeDef Led)
{
  HAL_GPIO_WritePin(GPIO_PORT[Led], GPIO_PIN[Led], GPIO_PIN_RESET); 
}

/**
  * @brief  Toggles the selected LED.
  * @param  Led: LED to be toggled
  *          This parameter can be one of the following values:
  *            @arg  LED3
  *            @arg  LED4
  * @retval None
  */
void BSP_LED_Toggle(Led_TypeDef Led)
{
  HAL_GPIO_TogglePin(GPIO_PORT[Led], GPIO_PIN[Led]);
}

/**
  * @brief  Configures button GPIO and EXTI Line.
  * @param  Button: Button to be configured
   *          This parameter should be :
  *            @arg  BUTTON_USER: Key Push Button 
  * @param  Button_Mode: Button mode
  *          This parameter can be one of the following values:
  *            @arg  BUTTON_MODE_GPIO: Button will be used as simple IO
  *            @arg  BUTTON_MODE_EXTI: Button will be connected to EXTI line 
  *                                    with interrupt generation capability  
  * @retval None
  */
void BSP_PB_Init(Button_TypeDef Button, ButtonMode_TypeDef Button_Mode)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  
  /* Enable the BUTTON clock */
  BUTTONx_GPIO_CLK_ENABLE(Button);
  __HAL_RCC_SYSCFG_CLK_ENABLE();
  
  if(Button_Mode == BUTTON_MODE_GPIO)
  {
    /* Configure Button pin as input */
    GPIO_InitStruct.Pin = BUTTON_PIN[Button];
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH  ;
    
    HAL_GPIO_Init(BUTTON_PORT[Button], &GPIO_InitStruct);
  }
  
  if(Button_Mode == BUTTON_MODE_EXTI)
  {
    /* Configure Button pin as input with External interrupt */
    GPIO_InitStruct.Pin = BUTTON_PIN[Button];
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH  ;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
    
    HAL_GPIO_Init(BUTTON_PORT[Button], &GPIO_InitStruct);
    
    /* Enable and set Button EXTI Interrupt to the lowest priority */
    NVIC_SetPriority((IRQn_Type)(BUTTON_IRQn[Button]), 0x03);
    HAL_NVIC_EnableIRQ((IRQn_Type)(BUTTON_IRQn[Button]));
  }
}

/**
  * @brief  Returns the selected button state.
  * @param  Button: Button to be checked
  *          This parameter can be one of the following values:
  *            @arg  BUTTON_USER: Key Push Button
  * @retval The Button GPIO pin value
  */
uint32_t BSP_PB_GetState(Button_TypeDef Button)
{
  return HAL_GPIO_ReadPin(BUTTON_PORT[Button], BUTTON_PIN[Button]);
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

/**
  * @}
  */ 
    
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
