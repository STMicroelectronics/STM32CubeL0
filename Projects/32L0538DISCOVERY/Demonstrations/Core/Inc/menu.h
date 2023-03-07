/**
  ******************************************************************************
  * @file    menu.h 
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
