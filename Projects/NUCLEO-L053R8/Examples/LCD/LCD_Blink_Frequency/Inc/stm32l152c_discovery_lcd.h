 /**
  ******************************************************************************
  * @file    stm32l152_discovery_lcd.h
  * @author  Microcontroller Division
  * @brief   This file contains all the functions prototypes for the glass LCD
  *          firmware driver.
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
#ifndef __STM32L152_DISCOVERY_LCD_H
#define __STM32L152_DISCOVERY_LCD_H

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"

/* Define for scrolling sentences*/
#define SCROLL_SPEED  	200
#define SCROLL_SPEED_L  400
#define SCROLL_NUM    	10

/* Define for character '.' */
#define POINT_OFF      0
#define POINT_ON       1

/* Define for caracter ":" */
#define COLUMN_OFF     0
#define COLUMN_ON      1

/* Element values correspond to LCD Glass BAR Level. */
#define BARLEVEL_OFF    0
#define BARLEVEL_1_4    1
#define BARLEVEL_1_2    2
#define BARLEVEL_3_4    3
#define BARLEVEL_FULL   4

#define DOT             0x8000 /* for add decimal point in string */
#define DOUBLE_DOT      0x4000 /* for add decimal point in string */

/* Code for 'µ' character */
#define C_UMAP          0x6084

/* Code for 'm' character */
#define C_MMAP          0xB210

/* Code for 'n' character */
#define C_NMAP          0x2210

/* Constant code for '*' character */
#define STAR            0xA0DD

/* Constant code for '-' character */
#define C_MINUS         0xA000

/* Constant code for '+' character */
#define C_PLUS          0xA014

/* Constant code for '/' */
#define C_SLATCH        0x00C0

/* Constant code for ° */
#define C_PERCENT_1     0xEC00

/* Constant code  for small o */
#define C_PERCENT_2     0xB300

#define C_FULL          0xFFDD

void BSP_LCD_GLASS_Init(void);
void BSP_LCD_GLASS_WriteChar(uint8_t* ch, uint8_t Point, uint8_t Column,uint8_t Position);
void BSP_LCD_GLASS_Clear(void);
void BSP_LCD_GLASS_DisplayString(uint8_t* ptr);
void BSP_LCD_GLASS_DisplayStrDeci(uint16_t* ptr);
void BSP_LCD_GLASS_BarLevelConfig(uint8_t BarLevel);
void BSP_LCD_GLASS_ScrollSentence(uint8_t* ptr, uint16_t nScroll, uint16_t ScrollSpeed);

#endif /* ____STM32L152_DISCOVERY_LCD_H */
