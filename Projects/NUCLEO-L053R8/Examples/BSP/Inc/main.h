/**
  ******************************************************************************
  * @file    BSP/Inc/main.h 
  * @author  MCD Application Team
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
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
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stdio.h"
#include "stm32l0xx_nucleo.h"
#include "stm32_adafruit_sd.h"
#include "stm32_adafruit_lcd.h"

/* Exported types ------------------------------------------------------------*/
typedef struct
{
  void   (*DemoFunc)(void);
  uint8_t DemoName[50]; 
  uint32_t DemoIndex;
}BSP_DemoTypedef;

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define COUNT_OF_EXAMPLE(x)    (sizeof(x)/sizeof(BSP_DemoTypedef))

/* Exported functions ------------------------------------------------------- */
void Joystick_demo (void);
void LCD_demo(void);
void SD_demo(void);
uint8_t CheckForUserInput(void);

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
