/**
  ******************************************************************************
  * @file    TIM/TIM_DMABurst/Inc/main.h
  * @author  MCD Application Team
  * @brief   Header for main.c module
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"
#include "stm32l0xx_nucleo_32.h"


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Definition of TIM instance */
#define TIMx                             TIM2

/* Definition for TIMx clock resources */
#define TIMx_CLK_ENABLE                  __HAL_RCC_TIM2_CLK_ENABLE
#define DMAx_CLK_ENABLE                  __HAL_RCC_DMA1_CLK_ENABLE

/* Definition for TIMx Pins */
#define TIMx_CHANNEL1_GPIO_CLK_ENABLE    __HAL_RCC_GPIOA_CLK_ENABLE

#define TIMx_GPIO_CHANNEL1_PORT          GPIOA
#define GPIO_PIN_CHANNEL1                GPIO_PIN_0


#define GPIO_AF_TIMx                     GPIO_AF2_TIM2

/* Definition for TIMx's DMA */
#define TIMx_CC1_DMA_REQUEST             DMA_REQUEST_8
#define TIMx_CC1_DMA_INST                DMA1_Channel2

/* Definition for ADCx's NVIC */
#define TIMx_DMA_IRQn                    DMA1_Channel2_3_IRQn
#define TIMx_DMA_IRQHandler              DMA1_Channel2_3_IRQHandler

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */


#endif /* __MAIN_H */
