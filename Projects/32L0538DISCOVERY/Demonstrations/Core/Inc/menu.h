/**
  ******************************************************************************
  * @file    menu.h 
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
#ifndef __MENU_H
#define __MENU_H

/* Includes ------------------------------------------------------------------*/
#include "tsl_config.h"
#include "bsp.h"

/* Exported types ------------------------------------------------------------*/
typedef enum {
  BACKGROUND_MENU = 0,
  MAIN_MENU,  
  MODULE_MENU,
  USB_MENU,
  PWR_MENU,
}MENU_Select_State;

/* Exported constants --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */ 
void Menu_Process(void);
void SystemClock_Config(void);
void USBClock_Enable(void);
void USBClock_Disable(void);
void IDD_SaveContext(void);
void IDD_RestoreContext(void);

#ifdef __cplusplus
}
#endif

#endif /* __BSP_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
