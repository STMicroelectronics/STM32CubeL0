/**
  ******************************************************************************
  * @file    tsl_config.h 
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
#ifndef __TSL_CONFIG_H
#define __TSL_CONFIG_H

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"
#include "tsl_user.h"

/* Private define ------------------------------------------------------------*/
  /* Defines for Lilnear Touch */
#define LINEAR_DETECT ((MyLinRots[0].p_Data->StateId == TSL_STATEID_DETECT) || \
                       (MyLinRots[0].p_Data->StateId == TSL_STATEID_DEB_RELEASE_DETECT))
#define LINEAR_POSITION (MyLinRots[0].p_Data->Position)

#define LINEAR_RAWPOSITION (MyLinRots[0].p_Data->RawPosition)
#define LINEAR_TOUCHDETECT (MyLinRots[0].p_Data->StateId == TSL_STATEID_DEB_RELEASE_DETECT)

/* Private variables ---------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */ 
void TSL_Config(void);

#endif /* __MAIN_H */
