/**
  ******************************************************************************
  * @file    lc_sensor_metering_app.h
  * @author  MCD Application Team   
  * @brief   System information functions
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

#undef GLOBAL
#ifdef MODULE_LC_SENSOR_METERING
#define GLOBAL
#else
#define GLOBAL extern
#endif



/* Includes ------------------------------------------------------------------*/

/** @addtogroup SYSTEM_INFO_MODULE
  * @{
  */

/** @defgroup LC_SENSOR_INFO
  * @brief system info routines 
  * @{
  */

/* external defines -----------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define TIMx                         TIM6
#define TIMx_CLK_ENABLE              __TIM6_CLK_ENABLE

/* Definition for TIMx's NVIC */
#define TIMx_IRQn                    TIM6_DAC_IRQn
#define TIMx_IRQHandler              TIM6_DAC_IRQHandler

#define DACx                            DAC
#define DACx_CLK_ENABLE()               __DAC_CLK_ENABLE()
#define DACx_CHANNEL_GPIO_CLK_ENABLE()  __GPIOA_CLK_ENABLE()


/* External variables --------------------------------------------------------*/
GLOBAL const K_ModuleItem_Typedef LcSensorMeteringModuleItem;
/* Private function prototypes -----------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @}
  */

/**
  * @}
  */
