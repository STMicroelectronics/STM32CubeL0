/**
  ******************************************************************************
  * @file    COMP/COMP_PWMSignalControl/Inc/main.h
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
#include "stm32l0xx_nucleo_32.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* User can use this section to tailor COMPx instance under use and associated
   resources */

/* ## Definition of COMPx related resources ################################# */
/* Definition for COMPx clock resources */
#define COMPx_GPIO_CLK_ENABLE()        __HAL_RCC_GPIOB_CLK_ENABLE()
#define COMPx_GPIO_CLK_DISABLE()       __HAL_RCC_GPIOB_CLK_DISABLE()

/* Definition for COMPx Channel Pin */
#define COMPx_PIN                      GPIO_PIN_5
#define COMPx_GPIO_PORT                GPIOB 

/* Definition for COMPx's NVIC */
#define COMPx_IRQn                     ADC1_COMP_IRQn
#define COMPx_IRQHandler               ADC1_COMP_IRQHandler

/* ## Definition of TIM related resources ################################### */
/* Definition of TIMx clock resources */
#define TIMx                            TIM22
#define TIMx_CLK_ENABLE()               __HAL_RCC_TIM22_CLK_ENABLE()

#define TIMx_FORCE_RESET()              __HAL_RCC_TIM22_FORCE_RESET()
#define TIMx_RELEASE_RESET()            __HAL_RCC_TIM22_RELEASE_RESET()

#define TIMx_IRQn                       TIM22_IRQn
#define TIMx_IRQHandler                 TIM22_IRQHandler

#define TIMx_GPIO_AFx                   GPIO_AF5_TIM22

/* Definition for TIMx Channel Pin */
#define TIMx_GPIO_CLK_ENABLE()        __HAL_RCC_GPIOA_CLK_ENABLE()
#define TIMx_GPIO_CLK_DISABLE()       __HAL_RCC_GPIOA_CLK_DISABLE()

#define TIMx_PIN                      GPIO_PIN_7
#define TIMx_GPIO_PORT                GPIOA 


/* Exported macro ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
