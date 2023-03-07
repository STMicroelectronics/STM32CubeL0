 /**
  ******************************************************************************
  * @file    stm32l073z_eval_idd.h
  * @author  MCD Application Team
  * @brief   Header file for stm32l476g_discovery_idd.c module.
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

/** @addtogroup BSP
  * @{
  */
  
/** @addtogroup STM32L073Z_EVAL
  * @{
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32L073Z_EVAL_IDD_H
#define __STM32L073Z_EVAL_IDD_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l073z_eval.h"
/* Include Idd measurement component driver */
#include "../Components/mfxstm32l152/mfxstm32l152.h"
#include "idd.h"
   

/** @addtogroup STM32L073Z_EVAL
  * @{
  */

/**
  * @}
  */

/** @defgroup STM32L073Z_EVAL_IDD_Exported_Types  IDD Exported Types
  * @{
  */
/** @defgroup IDD_Config  IDD Config
  * @{
  */
typedef enum 
{
  IDD_OK = 0,
  IDD_TIMEOUT = 1,
  IDD_ERROR = 0xFF
} 
IDD_StatusTypeDef;
/**
  * @}
  */

/** @defgroup STM32L073Z_EVAL_IDD_Exported_Defines  IDD Exported Defines
  * @{
  */
/**
  * @brief  Shunt values on discovery in milli ohms
  */
#define EVAL_IDD_SHUNT0_VALUE                  ((uint16_t) 1000)     /*!< value in milliohm */
#define EVAL_IDD_SHUNT1_VALUE                  ((uint16_t) 10)       /*!< value in ohm */
#define EVAL_IDD_SHUNT2_VALUE                  ((uint16_t) 100)      /*!< value in ohm */
#define EVAL_IDD_SHUNT3_VALUE                  ((uint16_t) 1000)     /*!< value in ohm */
#define EVAL_IDD_SHUNT4_VALUE                  ((uint16_t) 10000)    /*!< value in ohm */

/**
  * @brief  Shunt stabdelay value
  */

#define EVAL_IDD_SHUNT0_STABDELAY              ((uint16_t) 50)       /*!< value in millisec */
#define EVAL_IDD_SHUNT1_STABDELAY              ((uint16_t) 50)       /*!< value in millisec */
#define EVAL_IDD_SHUNT2_STABDELAY              ((uint16_t) 50)       /*!< value in millisec */
#define EVAL_IDD_SHUNT3_STABDELAY              ((uint16_t) 50)       /*!< value in millisec */
#define EVAL_IDD_SHUNT4_STABDELAY              ((uint16_t) 150)       /*!< value in millisec */


/**
  * @brief  Shunt values on discovery in milli ohms
  */

/**
  * @brief  IDD Ampli Gain on discovery 
  */
#define EVAL_IDD_AMPLI_GAIN                    ((uint16_t) 4990)     /*!< value is gain * 100 */

/**
  * @brief  IDD Vdd Min
  */
#define EVAL_IDD_VDD_MIN                       ((uint16_t) 1700)     /*!< value in millivolt */

/**
  * @}
  */


/** @addtogroup STM32L073Z_EVAL_IDD_Exported_Functions  IDD Exported Functions
  * @{
  */
uint8_t   BSP_IDD_Init(void);
void      BSP_IDD_Reset(void);
void      BSP_IDD_LowPower(void);
void      BSP_IDD_WakeUp(void);
void      BSP_IDD_StartMeasure(void);
void      BSP_IDD_Config(IDD_ConfigTypeDef IddConfig);
void      BSP_IDD_GetValue(uint32_t *IddValue);
void      BSP_IDD_EnableIT(void);
void      BSP_IDD_ClearIT(void);
uint8_t   BSP_IDD_GetITStatus(void);
void      BSP_IDD_DisableIT(void);
uint8_t   BSP_IDD_ErrorGetCode(void);
void      BSP_IDD_ErrorEnableIT(void);
void      BSP_IDD_ErrorClearIT(void);
uint8_t   BSP_IDD_ErrorGetITStatus(void);
void      BSP_IDD_ErrorDisableIT(void);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __STM32L073Z_EVAL_IDD_H */

/**
  * @}
  */   

/**
  * @}
  */   

