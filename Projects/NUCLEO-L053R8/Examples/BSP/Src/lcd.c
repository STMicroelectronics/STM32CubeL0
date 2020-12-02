/**
  ******************************************************************************
  * @file    BSP/Src/lcd.c 
  * @author  MCD Application Team
  * @brief   This example code shows how to use the LCD drawing features using 
  *          the Nucleo Adafruit shield driver.
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup STM32L0xx_HAL_Examples
  * @{
  */

/** @addtogroup BSP
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define LCD_FEATURES_NUM                3

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static uint8_t LCD_Feature = 0;

/* Private function prototypes -----------------------------------------------*/
static void LCD_SetHint(void);
static void LCD_Show_Feature(uint8_t feature);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  LCD demo
  * @param  None
  * @retval None
  */
void LCD_demo (void)
{ 
  LCD_SetHint();
  LCD_Feature = 0;
  LCD_Show_Feature (LCD_Feature); 
  
  while (1)
  {
    
    if(CheckForUserInput() > 0)
    {
      if(++LCD_Feature < LCD_FEATURES_NUM)
      {
       LCD_Show_Feature (LCD_Feature); 
      }
      else
      {
        return;
      }
    }
    HAL_Delay(100);
  }
}

/**
  * @brief  Display LCD demo hint
  * @param  None
  * @retval None
  */
static void LCD_SetHint(void)
{
  /* Clear the LCD */ 
  BSP_LCD_Clear(LCD_COLOR_WHITE);
  
  /* Set LCD Demo description */
  BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
  BSP_LCD_FillRect(0, 0, BSP_LCD_GetXSize(), 80);
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
  BSP_LCD_SetBackColor(LCD_COLOR_BLUE); 
  BSP_LCD_SetFont(&Font20);
  BSP_LCD_DisplayStringAt(0, 0, (uint8_t *)"LCD", CENTER_MODE);
  BSP_LCD_SetFont(&Font12);                  
  BSP_LCD_DisplayStringAt(0, 20, (uint8_t *)"This example shows", CENTER_MODE);
  BSP_LCD_DisplayStringAt(0, 35, (uint8_t *)"LCD Features, use", CENTER_MODE);
  BSP_LCD_DisplayStringAt(0, 50, (uint8_t *)"BUTTON to display", CENTER_MODE);
  BSP_LCD_DisplayStringAt(0, 65, (uint8_t *)"next page", CENTER_MODE);
                          
  /* Set the LCD Text Color */
  BSP_LCD_SetTextColor(LCD_COLOR_BLUE);  
  BSP_LCD_DrawRect(1, 82, BSP_LCD_GetXSize() - 3, BSP_LCD_GetYSize()- 84);
  BSP_LCD_DrawRect(2, 83, BSP_LCD_GetXSize() - 5, BSP_LCD_GetYSize()- 86);
 }

/**
  * @brief  Show LCD Features
  * @param  feature : feature index
  * @retval None
  */
static void LCD_Show_Feature(uint8_t feature)
{
  Point Points[]= {{5, 108}, {29, 108}, {29, 132}};
  Point Points2[]= {{36, 108}, {60, 108}, {60, 132}};
  
  BSP_LCD_SetBackColor(LCD_COLOR_WHITE);  
  BSP_LCD_SetTextColor(LCD_COLOR_BLACK);

  switch (feature)
  {
  case 0:
    /* Text alignement Feature */
    BSP_LCD_SetFont(&Font12);
    BSP_LCD_DisplayStringAt(4, BSP_LCD_GetYSize()- 70, (uint8_t *)"Left Text", LEFT_MODE);
    BSP_LCD_DisplayStringAt(4, BSP_LCD_GetYSize()- 45, (uint8_t *)"Center Text", CENTER_MODE);
    BSP_LCD_DisplayStringAt(4, BSP_LCD_GetYSize()- 20, (uint8_t *)"Right Text", RIGHT_MODE);
    break;
    
  case 1:
    /* Text Font Feature */
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_FillRect(4, 84, BSP_LCD_GetXSize() - 8, BSP_LCD_GetYSize()- 88);
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_SetFont(&Font24);
    BSP_LCD_DisplayStringAt(4, BSP_LCD_GetYSize()- 75, (uint8_t *)"Font24", CENTER_MODE);
    BSP_LCD_SetFont(&Font20);
    BSP_LCD_DisplayStringAt(4, BSP_LCD_GetYSize()- 57, (uint8_t *)"Font20", CENTER_MODE);
    BSP_LCD_SetFont(&Font16);
    BSP_LCD_DisplayStringAt(4, BSP_LCD_GetYSize()- 41, (uint8_t *)"Font16", CENTER_MODE);
    BSP_LCD_SetFont(&Font12);    
    BSP_LCD_DisplayStringAt(4, BSP_LCD_GetYSize()- 26, (uint8_t *)"Font12", CENTER_MODE);
    BSP_LCD_SetFont(&Font8);    
    BSP_LCD_DisplayStringAt(4, BSP_LCD_GetYSize()- 13, (uint8_t *)"Font8", CENTER_MODE);
    break;
    
  case 2:
    /* Draw misc. Shapes Feature */
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_FillRect(4, 84, BSP_LCD_GetXSize() - 8, BSP_LCD_GetYSize()- 88);
    
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK); 
    BSP_LCD_DrawRect(5, 88, 25, 13);
    BSP_LCD_FillRect(36, 88, 25, 13); 
    
    BSP_LCD_SetTextColor(LCD_COLOR_GREEN); 
    BSP_LCD_DrawPolygon(Points, 3);
    BSP_LCD_FillPolygon(Points2, 3);
    
    BSP_LCD_SetTextColor(LCD_COLOR_MAGENTA); 
    BSP_LCD_DrawCircle(80, 97, 12);
    BSP_LCD_FillCircle(110, 97, 12);
        
    BSP_LCD_SetTextColor(LCD_COLOR_RED); 
    BSP_LCD_DrawEllipse(80, 130, 8, 16);
    BSP_LCD_FillEllipse(110, 130, 8, 16);
    
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK); 
    BSP_LCD_DrawHLine(75, BSP_LCD_GetYSize() - 9, BSP_LCD_GetXSize() / 3);
    BSP_LCD_DrawLine(5, 154, 60, 136);
    BSP_LCD_DrawLine(5, 136, 60, 154);
    break;
    
//  case 3:
//    /* Draw Bitmap */
//    BSP_LCD_DrawBitmap(20, 100, (uint8_t *)stlogo);
//    HAL_Delay(500);
//    
//    BSP_LCD_DrawBitmap(BSP_LCD_GetXSize()/2 - 40, 100, (uint8_t *)stlogo);
//    HAL_Delay(500);    
//    
//    BSP_LCD_DrawBitmap(BSP_LCD_GetXSize()-100, 100, (uint8_t *)stlogo);
//    HAL_Delay(500);
//
//    BSP_LCD_DrawBitmap(20, BSP_LCD_GetYSize()- 80, (uint8_t *)stlogo);
//    HAL_Delay(500);
//    
//    BSP_LCD_DrawBitmap(BSP_LCD_GetXSize()/2 - 40, BSP_LCD_GetYSize()- 80, (uint8_t *)stlogo);
//    HAL_Delay(500);     
//
//    BSP_LCD_DrawBitmap(BSP_LCD_GetXSize()-100, BSP_LCD_GetYSize()- 80, (uint8_t *)stlogo);
//    HAL_Delay(500);    
//    break;
    
  default:
    break;
  }
}
/**
  * @}
  */

/**
  * @}
  */
     
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
