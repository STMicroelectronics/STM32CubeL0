/**
  ******************************************************************************
  * @file    DMA/DMA_FLASHToRAM/Inc/main.h 
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
/* DMA Stream parameters definitions. You can modify these parameters to select
   a different DMA Stream and/or channel.
   But note that only DMA1 Streams are capable of Memory to Memory transfers. */
#define DMA_CHANNEL               DMA1_Channel1 
#define DMA_CHANNEL_IRQ           DMA1_Channel1_IRQn
#define DMA_CHANNEL_IRQHANDLER    DMA1_Channel1_IRQHandler

#define BUFFER_SIZE              32
  
/* Exported macro ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
