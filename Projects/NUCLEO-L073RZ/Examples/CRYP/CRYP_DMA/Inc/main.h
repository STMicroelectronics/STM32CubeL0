/**
  ******************************************************************************
  * @file    CRYP/CRYP_DMA/Inc/main.h
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
#include "stm32l0xx_nucleo.h"
#include "stdio.h"
#include "string.h"


/* Exported types ------------------------------------------------------------*/
/* COM Types Definition */
typedef enum { COM1 = 0}COM_TypeDef;

/* Exported constants --------------------------------------------------------*/
#define  TIMEOUT_VALUE 0xFFFF

/* Definition for COM port1, connected to USART1 */ 
#define COMn                            1

#define BSP_COM1                       USART1
#define BSP_COM1_CLK_ENABLE()          __HAL_RCC_USART1_CLK_ENABLE()
#define BSP_COM1_CLK_DISABLE()         __HAL_RCC_USART1_CLK_DISABLE()

#define BSP_COM1_FORCE_RESET()         __HAL_RCC_USART1_FORCE_RESET()
#define BSP_COM1_RELEASE_RESET()       __HAL_RCC_USART1_RELEASE_RESET()
  
#define BSP_COM1_TX_PIN                GPIO_PIN_9
#define BSP_COM1_TX_GPIO_PORT          GPIOA
#define BSP_COM1_TX_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOA_CLK_ENABLE()
#define BSP_COM1_TX_GPIO_CLK_DISABLE() __HAL_RCC_GPIOA_CLK_DISABLE()
#define BSP_COM1_TX_AF                 GPIO_AF4_USART1

#define BSP_COM1_RX_PIN                GPIO_PIN_10
#define BSP_COM1_RX_GPIO_PORT          GPIOA
#define BSP_COM1_RX_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOA_CLK_ENABLE()
#define BSP_COM1_RX_GPIO_CLK_DISABLE() __HAL_RCC_GPIOA_CLK_DISABLE()
#define BSP_COM1_RX_AF                 GPIO_AF4_USART1

#define BSP_COM1_IRQn                  USART1_IRQn

#define COMx_CLK_ENABLE(__COM__)        (((__COM__) == COM1) ? BSP_COM1_CLK_ENABLE() : 0)
#define COMx_CLK_DISABLE(__COM__)       (((__COM__) == COM1) ? BSP_COM1_CLK_DISABLE() : 0)

#define COMx_TX_GPIO_CLK_ENABLE(__COM__) do { if(__COM__ == COM1) BSP_COM1_TX_GPIO_CLK_ENABLE(); } while (0)
#define COMx_TX_GPIO_CLK_DISABLE(__COM__) (((__COM__) == COM1) ? BSP_COM1_TX_GPIO_CLK_DISABLE() : 0)

#define COMx_RX_GPIO_CLK_ENABLE(__COM__) do { if(__COM__ == COM1) BSP_COM1_RX_GPIO_CLK_ENABLE(); } while (0)
#define COMx_RX_GPIO_CLK_DISABLE(__COM__) (((__COM__) == COM1) ? BSP_COM1_RX_GPIO_CLK_DISABLE() : 0)





/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void              BSP_COM_Init(COM_TypeDef COM, UART_HandleTypeDef* huart);

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
