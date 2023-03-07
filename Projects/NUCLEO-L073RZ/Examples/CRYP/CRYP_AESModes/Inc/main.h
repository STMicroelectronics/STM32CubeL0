/**
  ******************************************************************************
  * @file    CRYP/CRYP_AESModes/Inc/main.h
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
