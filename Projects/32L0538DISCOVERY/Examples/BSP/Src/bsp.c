/**
  ******************************************************************************
  * @file    bsp.c 
  * @author  MCD Application Team
  * @brief   Main program body
  *          This example code shows how to use the Nucleo BSP Drivers
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
  *******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "bsp.h"
#include "main.h"
#include "../Src/menu_res.c"

/** @addtogroup STM32l0xx_HAL_Examples
  * @{
  */

/** @defgroup BSP
  * @brief BSP routines
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Initializes LEDs, Button and EPD.
  * @param  None 
  * @retval None
  */
void Bsp_Init(void)
{
  /* Configure LED3 and LED4 */
  BSP_LED_Init(LED3);
  BSP_LED_Init(LED4);

  /* Initialize the User button */
  BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_EXTI);

  /* Initialize the EPD */
  BSP_EPD_Init();
}

/**
  * @brief  Display main demo messages
  * @param  None
  * @retval None
  */
void Display_DemoDescription(void)
{
#if defined (USE_STM32L0538_DISCO_REV_B03)
  BSP_EPD_Clear(EPD_COLOR_WHITE);
  BSP_EPD_SetFont(&Font16);
  BSP_EPD_DrawImage(1, 1, 72, 172, Background_pic);
  BSP_EPD_DisplayStringAt(40, 9, (uint8_t*)"STM32L053", CENTER_MODE);
  BSP_EPD_SetFont(&Font12);
  BSP_EPD_DisplayStringAt(40, 5, (uint8_t*)"BSP Example", CENTER_MODE);
  BSP_EPD_SetFont(&Font8);
  BSP_EPD_DisplayStringAt(30, 1, (uint8_t*)"Push Key Button to start example", CENTER_MODE); 
  BSP_EPD_RefreshDisplay();
#else /* USE_STM32L0538_DISCO */
  BSP_EPD_Clear(EPD_COLOR_WHITE);
  BSP_EPD_SetFont(&Font16);
  BSP_EPD_DrawImage(1, 1, 72, 172, Background_pic);
  BSP_EPD_DisplayStringAt(35, 13, (uint8_t*)"STM32L053", CENTER_MODE);
  BSP_EPD_SetFont(&Font12);
  BSP_EPD_DisplayStringAt(35, 8, (uint8_t*)"BSP Example", CENTER_MODE);
  BSP_EPD_SetFont(&Font8);
  BSP_EPD_DisplayStringAt(35, 4, (uint8_t*)"Push Key Button", CENTER_MODE);
  BSP_EPD_DisplayStringAt(35, 2, (uint8_t*)"to start example", CENTER_MODE); 
  BSP_EPD_RefreshDisplay();
#endif /* USE_STM32L0538_DISCO_REV_B03 */
}

/**
  * @brief  EPD demo
  * @param  None
  * @retval None
  */
void Bsp_EPD(void)
{
#if defined (USE_STM32L0538_DISCO_REV_B03)
  /* Shows text font configuration */
  BSP_EPD_Clear(EPD_COLOR_WHITE);
  BSP_EPD_SetFont(&Font20);
  BSP_EPD_DisplayStringAt(1, 10, (uint8_t*)"Font 20", LEFT_MODE);
  BSP_EPD_SetFont(&Font16);
  BSP_EPD_DisplayStringAt(70, 7, (uint8_t*)"Font 16", LEFT_MODE);
  BSP_EPD_SetFont(&Font12);
  BSP_EPD_DisplayStringAt(150, 4, (uint8_t*)"Font 12", LEFT_MODE);
  BSP_EPD_SetFont(&Font8);
  BSP_EPD_DisplayStringAt(200, 0, (uint8_t*)"Font 8", LEFT_MODE);
  BSP_EPD_RefreshDisplay();
  HAL_Delay(2000);
  
  /* Shows Line mode structures */
  BSP_EPD_Clear(EPD_COLOR_WHITE);
  BSP_EPD_SetFont(&Font16);
  BSP_EPD_DisplayStringAt(0, 10, (uint8_t*)"Line mode structures", CENTER_MODE);
  BSP_EPD_DrawRect(10, 10, 220, 4);
  BSP_EPD_DrawRect(1, 0, 246, 15);
  BSP_EPD_SetFont(&Font12);
  BSP_EPD_DisplayStringAt(2, 4, (uint8_t*)"LEFT_MODE", LEFT_MODE);
  BSP_EPD_DisplayStringAt(2, 4, (uint8_t*)"CENTER_MODE", CENTER_MODE);
  BSP_EPD_DisplayStringAt(2, 4, (uint8_t*)"RIGHT_MODE", RIGHT_MODE);
  BSP_EPD_RefreshDisplay();
  HAL_Delay(2000);
  
  /* Draws Images */
  BSP_EPD_Clear(EPD_COLOR_WHITE);
  BSP_EPD_DrawImage(1, 0, 72, 172, Background_pic);
  BSP_EPD_DrawImage(190, 0, 48, 48, Mouse_pic);
  BSP_EPD_DrawImage(150, 0, 48, 26, Batery_pic);
  BSP_EPD_DrawImage(80, 0, 16, 60, Slider_pic);
  BSP_EPD_DisplayStringAt(20, 12, (uint8_t*)"Draw Images", CENTER_MODE);
  BSP_EPD_RefreshDisplay();
  HAL_Delay(2000);
#else /* USE_STM32L0538_DISCO */

  /* Shows text font configuration */
  BSP_EPD_Clear(EPD_COLOR_WHITE);
  BSP_EPD_SetFont(&Font20);
  BSP_EPD_DisplayStringAt(1, 12, (uint8_t*)"Font 20", LEFT_MODE);
  BSP_EPD_SetFont(&Font16);
  BSP_EPD_DisplayStringAt(40, 7, (uint8_t*)"Font 16", LEFT_MODE);
  BSP_EPD_SetFont(&Font12);
  BSP_EPD_DisplayStringAt(100, 4, (uint8_t*)"Font 12", LEFT_MODE);
  BSP_EPD_SetFont(&Font8);
  BSP_EPD_DisplayStringAt(140, 0, (uint8_t*)"Font 8", LEFT_MODE);
  BSP_EPD_RefreshDisplay();
  HAL_Delay(2000);
  
  /* Shows Line mode structures */
  BSP_EPD_Clear(EPD_COLOR_WHITE);
  BSP_EPD_SetFont(&Font12);
  BSP_EPD_DisplayStringAt(0, 12, (uint8_t*)"Line mode structures", CENTER_MODE);
  BSP_EPD_DrawRect(10, 11, 150, 5);
  BSP_EPD_SetFont(&Font8);
  BSP_EPD_DisplayStringAt(1, 4, (uint8_t*)"LEFT_MODE", LEFT_MODE);
  BSP_EPD_DisplayStringAt(1, 4, (uint8_t*)"CENTER_MODE", CENTER_MODE);
  BSP_EPD_DisplayStringAt(1, 4, (uint8_t*)"RIGHT_MODE", RIGHT_MODE);
  BSP_EPD_RefreshDisplay();
  HAL_Delay(2000);
  
  /* Draws Images */
  BSP_EPD_Clear(EPD_COLOR_WHITE);
  BSP_EPD_SetFont(&Font12);
  BSP_EPD_DrawImage(1, 0, 72, 172, Background_pic);
  BSP_EPD_DrawImage(80, 0, 48, 48, Mouse_pic);
  BSP_EPD_DrawImage(140, 0, 48, 26, Batery_pic);
  BSP_EPD_DisplayStringAt(30, 13, (uint8_t*)"Draw Images", CENTER_MODE);
  BSP_EPD_RefreshDisplay();
  HAL_Delay(2000);
#endif /* USE_STM32L0538_DISCO_REV_B03 */
}

/**
  * @}
  */

/**
  * @}
  *
  */
