/**
  ******************************************************************************
  * @file    stm32l152c_discovery.h
  * @author  MCD Application Team
  * @brief   This file contains definitions for STM32L152C_DISCOVERY's LEDs and 
  *          push-buttons hardware resources.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2013 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */ 
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32L152C_DISCOVERY_H
#define __STM32L152C_DISCOVERY_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"

/** @addtogroup STM32L152C_DISCOVERY
  * @{
  */
      
/** @addtogroup STM32L152C_DISCOVERY_LOW_LEVEL
  * @{
  */ 

/** @defgroup STM32L152C_DISCOVERY_LOW_LEVEL_Exported_Types
  * @{
  */
typedef enum 
{
  LED3 = 0,
  LED4 = 1  
} Led_TypeDef;

typedef enum 
{  
  BUTTON_USER = 0,
} Button_TypeDef;

typedef enum 
{  
  BUTTON_MODE_GPIO = 0,
  BUTTON_MODE_EXTI = 1
} ButtonMode_TypeDef;  


/**
  * @}
  */ 

/** @defgroup STM32L152C_DISCOVERY_LOW_LEVEL_Exported_Constants
  * @{
  */ 

/** 
  * @brief  Define for STM32L152C_DISCOVERY board  
  */ 
#if !defined (USE_STM32L152C_DISCOVERY)
 #define USE_STM32L152C_DISCOVERY
#endif

/** @addtogroup STM32L152C_DISCOVERY_LOW_LEVEL_LED
  * @{
  */
#define LEDn                               2

#define LED3_PIN                           GPIO_PIN_7
#define LED3_GPIO_PORT                     GPIOB
#define LED3_GPIO_CLK_ENABLE()             __HAL_RCC_GPIOB_CLK_ENABLE()  
#define LED3_GPIO_CLK_DISABLE()            __HAL_RCC_GPIOB_CLK_DISABLE()
  
#define LED4_PIN                           GPIO_PIN_6
#define LED4_GPIO_PORT                     GPIOB
#define LED4_GPIO_CLK_ENABLE()             __HAL_RCC_GPIOB_CLK_ENABLE()  
#define LED4_GPIO_CLK_DISABLE()            __HAL_RCC_GPIOB_CLK_DISABLE()

#define LEDx_GPIO_CLK_ENABLE(__INDEX__)   do { if (__INDEX__ == 0) LED3_GPIO_CLK_ENABLE(); \
                                               else LED4_GPIO_CLK_ENABLE();} while (0)
#define LEDx_GPIO_CLK_DISABLE(__INDEX__)  (((__INDEX__) == 0) ? LED3_GPIO_CLK_DISABLE() :\
                                           LED4_GPIO_CLK_DISABLE())
                                         
/**
  * @}
  */ 
  
/** @addtogroup STM32L152C_DISCOVERY_LOW_LEVEL_BUTTON
  * @{
  */  
#define BUTTONn                            1



/**
  * @brief Key push-button
  */
#define KEY_BUTTON_PIN                       GPIO_PIN_0
#define KEY_BUTTON_GPIO_PORT                 GPIOA
#define KEY_BUTTON_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOA_CLK_ENABLE()   
#define KEY_BUTTON_GPIO_CLK_DISABLE()        __HAL_RCC_GPIOA_CLK_DISABLE()  
#define KEY_BUTTON_EXTI_LINE                 GPIO_PIN_0
#define KEY_BUTTON_EXTI_IRQn                 EXTI0_1_IRQn

#define BUTTONx_GPIO_CLK_ENABLE(__INDEX__)   KEY_BUTTON_GPIO_CLK_ENABLE()
                                              

#define BUTTONx_GPIO_CLK_DISABLE(__INDEX__)   KEY_BUTTON_GPIO_CLK_DISABLE()
                                               
/**
  * @}
  */ 
  

/* Exported constant ---------------------------------------------------------*/



/**
  * @}
  */ 

/**
  * @}
  */ 
  
/** @defgroup STM32L152C_DISCOVERY_LOW_LEVEL_Exported_Macros
  * @{
  */  
/**
  * @}
  */ 


/** @defgroup STM32L152C_DISCOVERY_LOW_LEVEL_Exported_Functions
  * @{
  */
void             BSP_LED_Init(Led_TypeDef Led);
void             BSP_LED_On(Led_TypeDef Led);
void             BSP_LED_Off(Led_TypeDef Led);
void             BSP_LED_Toggle(Led_TypeDef Led);
void             BSP_PB_Init(Button_TypeDef Button, ButtonMode_TypeDef Button_Mode);
uint32_t         BSP_PB_GetState(Button_TypeDef Button);
/**
  * @}
  */

/**
  * @}
  */ 

#ifdef __cplusplus
}
#endif

#endif /* __STM32L152C_DISCOVERY_H */
