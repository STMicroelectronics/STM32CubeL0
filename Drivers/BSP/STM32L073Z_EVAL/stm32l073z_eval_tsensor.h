/**
  ******************************************************************************
  * @file    stm32l073z_eval_tsensor.h
  * @author  MCD Application Team
  * @brief   This file contains all the functions prototypes for the
  *          stm32l073z_eval_tsensor.c firmware driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright(c) 2016 STMicroelectronics.
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
#ifndef __STM32L073Z_EVAL_TSENSOR_H
#define __STM32L073Z_EVAL_TSENSOR_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l073z_eval.h"
#include "../Components/stlm75/stlm75.h"

/** @addtogroup BSP
  * @{
  */

/** @addtogroup STM32L073Z_EVAL
  * @{
  */

/** @addtogroup STM32L073Z_EVAL_TSENSOR
  * @{
  */

/** @defgroup STM32L073Z_EVAL_TSENSOR_Exported_Types Exported Types
  * @{
  */

/**
  * @brief  TSENSOR Status
  */
typedef enum
{
  TSENSOR_OK = 0,
  TSENSOR_ERROR
}TSENSOR_Status_TypDef;

/**
  * @}
  */

/** @defgroup STM32L073Z_EVAL_TSENSOR_Exported_Constants Exported Constants
  * @{
  */
/* Temperature Sensor hardware I2C address */
#define TSENSOR_I2C_ADDRESS_A01 0x90
#define TSENSOR_I2C_ADDRESS_A02 0x92

/* Maximum number of trials use for STTS751_IsReady function */
#define TSENSOR_MAX_TRIALS      50

/**
  * @}
  */

/** @defgroup STM32L073Z_EVAL_I2C_TSENSOR_Exported_Functions
  * @{
  */
uint32_t BSP_TSENSOR_Init(void);
uint8_t  BSP_TSENSOR_ReadStatus(void);
float    BSP_TSENSOR_ReadTemp(void);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __STM32L073Z_EVAL_TSENSOR_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
