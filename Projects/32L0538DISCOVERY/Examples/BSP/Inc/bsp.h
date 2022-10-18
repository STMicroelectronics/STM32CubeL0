/**
  ******************************************************************************
  * @file    bsp.h 
  * @author  MCD Application Team
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_H
#define __BSP_H

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* define for the linear */
/* Exported macros -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void Bsp_Init(void);
void Bsp_EPD(void);
void Display_DemoDescription(void);

#ifdef __cplusplus
}
#endif

#endif /* __BSP_H */
