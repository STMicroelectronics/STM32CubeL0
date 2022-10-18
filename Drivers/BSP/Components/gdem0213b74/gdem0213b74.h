/**
  ******************************************************************************
  * @file    gdem0213b74.h
  * @author  MCD Application Team
  * @brief   This file contains all the functions prototypes for the gdem0213b74.c
  *          driver.
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
#ifndef __GDEM0213B74_H
#define __GDEM0213B74_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "../Common/epd.h"

/** @addtogroup BSP
  * @{
  */

/** @addtogroup Components
  * @{
  */

/** @addtogroup GDEM0213B74
  * @{
  */

/** @defgroup GDEM0213B74_Exported_Types
  * @{
  */

/**
  * @}
  */

/** @defgroup GDEM0213B74_Exported_Constants
  * @{
  */

/**
  * @brief  GDEM0213B74 Size
  */
#define  GDEM0213B74_EPD_PIXEL_WIDTH    ((uint16_t)250)
#define  GDEM0213B74_EPD_PIXEL_HEIGHT   ((uint16_t)32)

/**
  * @brief  GDEM0213B74 Registers
  */
#define EPD_REG_1             0x01   /* Driver Output Control */
#define EPD_REG_3             0x03   /* Gate driving voltage control */
#define EPD_REG_4             0x04   /* Source driving Voltage control */
#define EPD_REG_8             0x08   /* Initial Code Setting OTP Program */
#define EPD_REG_9             0x09   /* Write Register for Initial Code Setting */
#define EPD_REG_10            0x0A   /* Read Register for Initial Code Setting */
#define EPD_REG_12            0x0C   /* Booster Soft Start Control */
#define EPD_REG_16            0x10   /* Deep Sleep mode setting */
#define EPD_REG_17            0x11   /* Data Entry Mode Setting */
#define EPD_REG_18            0x12   /* SWRESET */
#define EPD_REG_24            0x18   /* Temperature Sensor Control */
#define EPD_REG_26            0x1A   /* Temperature Sensor Control (Write to Temp Register) */
#define EPD_REG_32            0x20   /* Master activation */
#define EPD_REG_33            0x21   /* Display update control 1 */
#define EPD_REG_34            0x22   /* Display update control 2 */
#define EPD_REG_36            0x24   /* write RAM (Black White) */
#define EPD_REG_38            0x26   /* write RAM (Red) */
#define EPD_REG_44            0x2C   /* Write VCOM Register */
#define EPD_REG_45            0x2D   /* OTP register Read for Display Option */
#define EPD_REG_47            0x2F   /* Status Bit Read */
#define EPD_REG_48            0x30   /* Program WS OTP */
#define EPD_REG_50            0x32   /* Write LUT register */
#define EPD_REG_57            0x39   /* OTP Program Mode */
#define EPD_REG_60            0x3C   /* Select Border waveform */
#define EPD_REG_68            0x44   /* Set RAM X - Address Start / End Position */
#define EPD_REG_69            0x45   /* Set RAM Y - Address Start / End Position */
#define EPD_REG_78            0x4E   /* Set RAM X Address Counter */
#define EPD_REG_79            0x4F   /* Set RAM Y Address Counter */

/**
  * @}
  */

/** @defgroup SPI_EPD_Exported_Functions
  * @{
  */
void     gdem0213b74_Init(void);
void     gdem0213b74_WriteReg(uint8_t EPD_Reg, uint8_t EPD_RegValue);
uint8_t  gdem0213b74_ReadReg(uint8_t EPD_Reg);

void     gdem0213b74_WritePixel(uint8_t HEX_Code);

void     gdem0213b74_DrawImage(uint16_t Xpos, uint16_t Ypos, uint16_t Xsize, uint16_t Ysize, uint8_t *pdata);
void     gdem0213b74_RefreshDisplay(void);
void     gdem0213b74_CloseChargePump(void);

void     gdem0213b74_SetDisplayWindow(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height);
uint16_t gdem0213b74_GetEpdPixelWidth(void);
uint16_t gdem0213b74_GetEpdPixelHeight(void);

/* EPD driver structure */
extern EPD_DrvTypeDef   gdem0213b74_drv;

/* EPD IO functions */
void      EPD_IO_Init(void);
void      EPD_IO_WriteData(uint16_t RegValue);
void      EPD_IO_WriteReg(uint8_t Reg);
uint16_t  EPD_IO_ReadData(void);
void      EPD_Delay (uint32_t delay);
void      EPD_ReadBusy(void);
void      EPD_IO_Reset_Low(void);
void      EPD_IO_Reset_High(void);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __GDEM0213B74_H */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

