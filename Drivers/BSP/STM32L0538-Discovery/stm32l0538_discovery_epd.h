/**
  ******************************************************************************
  * @file    stm32l0538_discovery_epd.h
  * @author  MCD Application Team
  * @brief   This file contains all the functions prototypes for the 
  *          stm32l0538_discovery_epd.c driver.
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
#ifndef __STM32L0538_DISCOVERY_EPD_H
#define __STM32L0538_DISCOVERY_EPD_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "../Components/gde021a1/gde021a1.h"
#include "fontsepd.h"

/** @addtogroup BSP
  * @{
  */

/** @addtogroup STM32L0538_DISCOVERY
  * @{
  */

/** @defgroup STM32L053_DISCOVERY_EPD
  * @{
  */


/** @defgroup STM32L0538_DISCOVERY_EPD_Exported_Types
  * @{
  */
typedef enum
{
  EPD_OK = 0,
  EPD_ERROR = 1,
  EPD_TIMEOUT = 2
} EPD_StatusTypeDef;

/**
  * @brief  Line mode structures definition
  */
typedef enum
{
  CENTER_MODE             = 0x01,    /*!< Center mode */
  RIGHT_MODE              = 0x02,    /*!< Right mode  */
  LEFT_MODE               = 0x03     /*!< Left mode   */
} Text_AlignModeTypdef;

/**
  * @}
  */

/** @defgroup STM32L0538_DISCOVERY_EPD_Exported_Constants
  * @{
  */

/**
  * @brief  EPD color
  */
#define EPD_COLOR_BLACK         0x00
#define EPD_COLOR_DARKGRAY      0x55
#define EPD_COLOR_LIGHTGRAY     0xAA
#define EPD_COLOR_WHITE         0xFF

/**
  * @brief EPD default font
  */
#define EPD_DEFAULT_FONT         Font12

/**
  * @}
  */

/** @defgroup STM32L0538_DISCOVERY_EPD_Exported_Functions
  * @{
  */
uint8_t  BSP_EPD_Init(void);
uint32_t BSP_EPD_GetXSize(void);
uint32_t BSP_EPD_GetYSize(void);

void     BSP_EPD_SetFont(sFONT *pFonts);
sFONT    *BSP_EPD_GetFont(void);

void     BSP_EPD_Clear(uint16_t Color);

void     BSP_EPD_DisplayStringAtLine(uint16_t Line, uint8_t *ptr);
void     BSP_EPD_DisplayStringAt(uint16_t Xpos, uint16_t Ypos, uint8_t *pText, Text_AlignModeTypdef mode);
void     BSP_EPD_DisplayChar(uint16_t Xpos, uint16_t Ypos, uint8_t Ascii);

void     BSP_EPD_DrawHLine(uint16_t Xpos, uint16_t Ypos, uint16_t Length);
void     BSP_EPD_DrawVLine(uint16_t Xpos, uint16_t Ypos, uint16_t Length);
void     BSP_EPD_DrawRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height);
void     BSP_EPD_FillRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height);

void     BSP_EPD_RefreshDisplay(void);

void     BSP_EPD_CloseChargePump(void);

void     BSP_EPD_DrawImage(uint16_t Xpos, uint16_t Ypos, uint16_t Xsize, uint16_t Ysize, uint8_t *pdata);

#ifdef __cplusplus
}
#endif

#endif /* __STM32L0538_DISCOVERY_EPD_H */

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

/*********************** (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
