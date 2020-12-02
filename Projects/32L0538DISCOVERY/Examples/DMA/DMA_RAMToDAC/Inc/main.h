/**
  ******************************************************************************
  * @file    DMA/DMA_RAMToDAC/Inc/main.h 
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

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
/* User can use this section to tailor DAC Channel used and associated 
   resources */
/* Definition for DAC clock resources */
#define DACx_CHANNEL1_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOA_CLK_ENABLE()
#define DMAx_CLK_ENABLE()                __HAL_RCC_DMA1_CLK_ENABLE()  

#define DACx_FORCE_RESET()               __HAL_RCC_DAC_FORCE_RESET()
#define DACx_RELEASE_RESET()             __HAL_RCC_DAC_RELEASE_RESET()
     
/* Definition for DACx Channel1 Pin */
#define DACx_CHANNEL1_PIN                GPIO_PIN_4
#define DACx_CHANNEL1_GPIO_PORT          GPIOA

/* Definition for DACx's Channel1 */
#define DACx_CHANNEL1                    DAC_CHANNEL_1

/* Definition for DACx's DMA Channel1 */
#define DACx_DMA_CHANNEL1                DMA1_Channel2
#define DACx_DMA_REQUEST1                DMA_REQUEST_9

/* Definition for DACx's NVIC */
#define DACx_DMA_IRQn1                   DMA1_Channel2_3_IRQn
#define DACx_DMA_IRQHandler1             DMA1_Channel2_3_IRQHandler

#define BUFFER_SIZE                      32
  
/* Exported macro ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
