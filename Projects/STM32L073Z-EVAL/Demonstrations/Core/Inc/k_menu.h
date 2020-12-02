/**
  ******************************************************************************
  * @file    k_menu.h
  * @author  MCD Application Team
  * @brief   Header for k_module.c file
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
#ifndef __K_MENU_H
#define __K_MENU_H

#ifdef __cplusplus
 extern "C" {
#endif

   
/* Includes ------------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
typedef void (*tExecFunc)(void);
typedef void (*tExecAction)(uint8_t);

typedef struct sMenuItem tMenuItem;
typedef struct sMenu tMenu;
struct sMenuItem
{
  char *pszTitle;
  uint16_t x,y;
  uint8_t SelType;
  uint8_t ModuleId;
  tExecFunc pfExecFunc;
  tExecAction pfActionFunc;
  const tMenu *psSubMenu;
  char *pIconPath;
};

struct sMenu
{
  char* pszTitle;
  const tMenuItem *psItems;
  uint32_t nItems;
  uint32_t nType;
  uint8_t line;
  uint8_t column;
};

enum{
  IDLE_DEMO,
  /* Type de menu */
  TYPE_TEXT,
  TYPE_ICON,
  TYPE_EXEC,
  /* MENU SEL */
  SEL_SUBMENU,
  SEL_MODULE,
  SEL_EXEC,
  SEL_EXIT,
  
  KMENU_RESET,
  KMENU_UPDATE,
};


#define C_MENU_XA           32
#define C_MENU_XB           128
#define C_MENU_XC           224

#define C_MENU_Y_LINE_1     60
#define C_MENU_Y_LINE_2     144

#define C_SQUARE            60

#define     C_ICON_INTERNAL_TITLE_UART         "Uart"
#define     C_ICON_INTERNAL_TITLE_LOW_POWER    "Power"
#define     C_ICON_INTERNAL_TITLE_THERMOMETER  "Temp"
#define     C_ICON_INTERNAL_TITLE_ABOUT        "Help"
#define     C_ICON_INTERNAL_TITLE_PRESSURE     "Pres"
#define     C_ICON_INTERNAL_TITLE_LC           "LC  "

/* Exported macros -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void kMenu_Init(void);
void kMenu_Execute(tMenu psCurrentMenu);
void kMenu_EventHandler(uint16_t GPIO_Pin);
void kMenu_Header(char *string);

#ifdef __cplusplus
}
#endif

#endif /*__K_MODULE_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
