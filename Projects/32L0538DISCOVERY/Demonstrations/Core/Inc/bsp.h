/**
  ******************************************************************************
  * @file    bsp.h 
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
void BSP_TSL_Init(void);
void BSP_USB_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* __BSP_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
