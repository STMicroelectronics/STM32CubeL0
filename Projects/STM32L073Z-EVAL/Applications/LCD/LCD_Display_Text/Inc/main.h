/**
  ******************************************************************************
  * @file    LCD/LCD_Display_Text/Inc/main.h 
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
#include <stdio.h>
#include <string.h>
#include "stm32l0xx_hal.h"
#include "stm32l073z_eval.h"
#include "stm32l073z_eval_io.h"
#include "stm32l073z_eval_glass_lcd.h"
#include "stm32l073z_eval_tsensor.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void TSENSOR_demo (void);
uint8_t CheckForUserInput(void);

#endif /* __MAIN_H */
