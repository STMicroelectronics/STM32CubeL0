/**
  ******************************************************************************
  * @file    tsl_config.h 
  * @author  MCD Application Team
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
