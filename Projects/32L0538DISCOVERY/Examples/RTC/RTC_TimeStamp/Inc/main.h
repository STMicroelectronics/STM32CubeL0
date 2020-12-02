/**
  ******************************************************************************
  * @file    RTC/RTC_TimeStamp/Inc/main.h 
  * @author  MCD Application Team
  * @brief   Header for main.c module
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
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"
#include "stm32l0538_discovery.h"
#include <stdio.h>

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define  BACKUP_COUNT 5
/* Defines related to Clock configuration */    
/* Uncomment to enable the adequate Clock Source */
#define RTC_CLOCK_SOURCE_LSI
/*#define RTC_CLOCK_SOURCE_LSE*/

/* Comment to disable displaying the time on the debugger */
#define DISPLAY_ON_DUBUGGER

#ifdef RTC_CLOCK_SOURCE_LSI
  #define RTC_ASYNCH_PREDIV    0x7C
  #define RTC_SYNCH_PREDIV     0x0127
#endif

#ifdef RTC_CLOCK_SOURCE_LSE
  #define RTC_ASYNCH_PREDIV  0x7F
  #define RTC_SYNCH_PREDIV   0x00FF
#endif

/* User can use this section to tailor I2Cx/I2Cx instance used and associated
   resources */
/* Definition for I2Cx clock resources */
#define I2Cx                              I2C1
#define I2Cx_CLK_ENABLE()                __HAL_RCC_I2C1_CLK_ENABLE()
#define I2Cx_CLK_DISABLE()               __HAL_RCC_I2C1_CLK_DISABLE()
#define I2Cx_SDA_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOB_CLK_ENABLE()
#define I2Cx_SCL_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOB_CLK_ENABLE()

#define I2Cx_FORCE_RESET()               __HAL_RCC_I2C1_FORCE_RESET()
#define I2Cx_RELEASE_RESET()             __HAL_RCC_I2C1_RELEASE_RESET()

/* Definition for I2Cx Pins */
#define I2Cx_SCL_PIN                    GPIO_PIN_8
#define I2Cx_SCL_GPIO_PORT              GPIOB
#define I2Cx_SCL_AF                     GPIO_AF4_I2C1
#define I2Cx_SDA_PIN                    GPIO_PIN_9
#define I2Cx_SDA_GPIO_PORT              GPIOB
#define I2Cx_SDA_AF                     GPIO_AF4_I2C1

/* Definition for I2Cx's NVIC */
#define I2Cx_IRQn                    I2C1_IRQn
#define I2Cx_IRQHandler              I2C1_IRQHandler
  
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void Error_Handler(void);
#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
