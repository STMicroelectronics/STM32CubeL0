/**
  ******************************************************************************
  * @file    power.h 
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
#ifndef __IDD_POWER_H
#define __IDD_POWER_H

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "stm32l0xx_hal.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void Idd_Run_process(void);
void Idd_Sleep_process(void);
void Idd_LPSleep_process(void);
void Idd_Stop_process(void);

#endif /* __IDD_POWER_H */
