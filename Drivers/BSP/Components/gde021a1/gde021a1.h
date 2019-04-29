/**
  ******************************************************************************
  * @file    gde021a1.h
  * @author  MCD Application Team
  * @brief   This file contains all the functions prototypes for the gde021a1.c
  *          driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2014 STMicroelectronics.
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
#ifndef __GDE021A1_H
#define __GDE021A1_H

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

/** @addtogroup GDE021A1
  * @{
  */

/** @defgroup GDE021A1_Exported_Types
  * @{
  */

/**
  * @}
  */

/** @defgroup GDE021A1_Exported_Constants
  * @{
  */

/**
  * @brief  GDE021A1 Size
  */
#define  GDE021A1_EPD_PIXEL_WIDTH    ((uint16_t)172)
#define  GDE021A1_EPD_PIXEL_HEIGHT   ((uint16_t)18)

/**
  * @brief  GDE021A1 Registers
  */
#define EPD_REG_0             0x00   /* Status Read */
#define EPD_REG_1             0x01   /* Driver Output Control */
#define EPD_REG_3             0x03   /* Gate driving voltage control */
#define EPD_REG_4             0x04   /* Source driving coltage control */
#define EPD_REG_7             0x07   /* Display Control */
#define EPD_REG_11            0x0B   /* Gate and Sorce non overlap period COntrol */
#define EPD_REG_15            0x0F   /* Gate scan start */
#define EPD_REG_16            0x10   /* Deep Sleep mode setting */
#define EPD_REG_17            0x11   /* Data Entry Mode Setting */
#define EPD_REG_18            0x12   /* SWRESET */
#define EPD_REG_26            0x1A   /* Temperature Sensor Control (Write to Temp Register) */
#define EPD_REG_27            0x1B   /* Temperature Sensor Control(Read from Temp Register) */
#define EPD_REG_28            0x1C   /* Temperature Sensor Control(Write Command  to Temp sensor) */
#define EPD_REG_29            0x1D   /* Temperature Sensor Control(Load temperature register with temperature sensor reading) */
#define EPD_REG_32            0x20   /* Master activation */
#define EPD_REG_33            0x21   /* Display update */
#define EPD_REG_34            0x22   /* Display update control 2 */
#define EPD_REG_36            0x24   /* write RAM */
#define EPD_REG_37            0x25   /* Read RAM */
#define EPD_REG_40            0x28   /* VCOM sense */
#define EPD_REG_41            0x29   /* VCOM Sense duration */
#define EPD_REG_42            0x2A   /* VCOM OTP program */
#define EPD_REG_44            0x2C   /* Write VCOMregister */
#define EPD_REG_45            0x2D   /* Read OTP registers */
#define EPD_REG_48            0x30   /* Program WS OTP */
#define EPD_REG_50            0x32   /* Write LUT register */
#define EPD_REG_51            0x33   /* Read LUT register */
#define EPD_REG_54            0x36   /* Program OTP selection */
#define EPD_REG_55            0x37   /* Proceed OTP selection */
#define EPD_REG_58            0x3A   /* Set dummy line pulse period */
#define EPD_REG_59            0x3B   /* Set Gate line width */
#define EPD_REG_60            0x3C   /* Select Border waveform */
#define EPD_REG_68            0x44   /* Set RAM X - Address Start / End Position */
#define EPD_REG_69            0x45   /* Set RAM Y - Address Start / End Position */
#define EPD_REG_78            0x4E   /* Set RAM X Address Counter */
#define EPD_REG_79            0x4F   /* Set RAM Y Address Counter */
#define EPD_REG_240           0xF0   /* Booster Set Internal Feedback Selection */
#define EPD_REG_255           0xFF   /* NOP */

/**
  * @}
  */

/** @defgroup SPI_EPD_Exported_Functions
  * @{
  */
void     gde021a1_Init(void);
void     gde021a1_WriteReg(uint8_t EPD_Reg, uint8_t EPD_RegValue);
uint8_t  gde021a1_ReadReg(uint8_t EPD_Reg);

void     gde021a1_WritePixel(uint8_t HEX_Code);

void     gde021a1_DrawImage(uint16_t Xpos, uint16_t Ypos, uint16_t Xsize, uint16_t Ysize, uint8_t *pdata);
void     gde021a1_RefreshDisplay(void);
void     gde021a1_CloseChargePump(void);

void     gde021a1_SetDisplayWindow(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height);
uint16_t gde021a1_GetEpdPixelWidth(void);
uint16_t gde021a1_GetEpdPixelHeight(void);

/* EPD driver structure */
extern EPD_DrvTypeDef   gde021a1_drv;

/* EPD IO functions */
void      EPD_IO_Init(void);
void      EPD_IO_WriteData(uint16_t RegValue);
void      EPD_IO_WriteReg(uint8_t Reg);
uint16_t  EPD_IO_ReadData(void);
void      EPD_Delay (uint32_t delay);
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __GDE021A1_H */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
