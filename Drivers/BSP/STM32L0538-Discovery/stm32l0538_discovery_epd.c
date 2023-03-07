/**
  ******************************************************************************
  * @file    stm32l0538_discovery_epd.c
  * @author  MCD Application Team
  * @brief   This file includes the EPD driver for Display Module of 
  *          STM32L0538-DISCO kit (MB1143).
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

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"
#include "stm32l0538_discovery_epd.h"
#include "stm32l0538_discovery.h"
#include "font20epd.c"
#include "font16epd.c"
#include "font12epd.c"
#include "font8epd.c"

/** @addtogroup BSP
  * @{
  */

/** @addtogroup STM32L0538_DISCOVERY
  * @{
  */

/** @defgroup STM32L0538_DISCOVERY_EPD
  * @{
  */

/** @defgroup STM32L0538_DISCOVERY_EPD_Private_TypesDefinitions
  * @{
  */
/**
  * @}
  */

/** @defgroup STM32L0538_DISCOVERY_EPD_Private_Defines
  * @{
  */
/**
  * @}
  */

/** @defgroup STM32L0538_DISCOVERY_EPD_Private_Variables
  * @{
  */
static sFONT           *pFont;
static EPD_DrvTypeDef  *epd_drv;
/**
  * @}
  */

/** @defgroup STM32L0538_DISCOVERY_EPD_Private_FunctionPrototypes
  * @{
  */
static void DrawChar(uint16_t Xpos, uint16_t Ypos, const uint8_t *c);
/**
  * @}
  */

/** @defgroup STM32L0538_DISCOVERY_EPD_Private_Functions
  * @{
  */

/**
  * @brief  Initializes the EPD.
  * @param  None
  * @retval EPD state
  */
uint8_t BSP_EPD_Init(void)
{
  uint8_t ret = EPD_ERROR;

  /* Default value for the Font */
  pFont = &Font16;

#if defined (USE_STM32L0538_DISCO_REV_B03)
  epd_drv = &gdem0213b74_drv;
#else /* USE_STM32L0538_DISCO */
  epd_drv = &gde021a1_drv;
#endif /* USE_STM32L0538_DISCO_REV_B03 */
  /* EPD Init */
  epd_drv->Init();

  /* Clear the EPD screen */
  BSP_EPD_Clear(EPD_COLOR_WHITE);

  /* Initialize the font */
  BSP_EPD_SetFont(&EPD_DEFAULT_FONT);

  ret = EPD_OK;

  return ret;
}

/**
  * @brief  Gets the EPD X size.
  * @param  None
  * @retval EPD X size
  */
uint32_t BSP_EPD_GetXSize(void)
{
  return(epd_drv->GetEpdPixelWidth());
}

/**
  * @brief  Gets the EPD Y size.
  * @param  None   
  * @retval EPD Y size
  */
uint32_t BSP_EPD_GetYSize(void)
{
  return(epd_drv->GetEpdPixelHeight());
}

/**
  * @brief  Sets the Text Font.
  * @param  pFonts: specifies the layer font to be used.
  * @retval None
  */
void BSP_EPD_SetFont(sFONT *pFonts)
{
  pFont = pFonts;
}

/**
  * @brief  Gets the Text Font.
  * @param  None.
  * @retval the used layer font.
  */
sFONT *BSP_EPD_GetFont(void)
{
  return pFont;
}

/**
  * @brief  Clears the hole EPD.
  * @param  Color: Color of the background
  * @retval None
  */
void BSP_EPD_Clear(uint16_t Color)
{
  uint32_t index = 0;
#if defined (USE_STM32L0538_DISCO_REV_B03)
  epd_drv->SetDisplayWindow(1, 0, 250, 31);
  
  for(index = 0; index < 6000; index++)
  {
      epd_drv->WritePixel(Color);
  }
#else /* USE_STM32L0538_DISCO */
  epd_drv->SetDisplayWindow(0, 0, 171, 17);

  for(index = 0; index < 3096; index++)
  {
      epd_drv->WritePixel(Color);
  }
#endif /* USE_STM32L0538_DISCO_REV_B03 */
}

/**
  * @brief  Displays one character.
  * @param  Xpos: start column address.
  * @param  Ypos: the Line where to display the character shape.
  * @param  Ascii: character ascii code, must be between 0x20 and 0x7E.
  * @retval None
  */
void BSP_EPD_DisplayChar(uint16_t Xpos, uint16_t Ypos, uint8_t Ascii)
{
  Ascii -= 32;
  
  DrawChar(Xpos, Ypos, &pFont->table[Ascii * ((pFont->Height) * (pFont->Width))]);
}

/**
  * @brief  Displays characters on the EPD.
  * @param  Xpos: X position
  * @param  Ypos: Y position
  * @param  Text: Pointer to string to display on EPD
  * @param  Mode: Display mode
  *          This parameter can be one of the following values:
  *            @arg  CENTER_MODE
  *            @arg  RIGHT_MODE
  *            @arg  LEFT_MODE  
  * @retval None
  */
void BSP_EPD_DisplayStringAt(uint16_t Xpos, uint16_t Ypos, uint8_t *Text, Text_AlignModeTypdef Mode)
{
  uint16_t refcolumn = 1, i = 0;
  uint32_t size = 0, xsize = 0; 
  uint8_t  *ptr = Text;
  
  /* Get the text size */
  while (*ptr++) size ++ ;
  
  /* Characters number per line */
  xsize = (BSP_EPD_GetXSize()/pFont->Width);
  
  switch (Mode)
  {
  case CENTER_MODE:
    {
      refcolumn = Xpos + ((xsize - size)* pFont->Width) / 2;
      break;
    }
  case LEFT_MODE:
    {
      refcolumn = Xpos;
      break;
    }
  case RIGHT_MODE:
    {
      refcolumn =  - Xpos + ((xsize - size)*pFont->Width);
      break;
    }    
  default:
    {
      refcolumn = Xpos;
      break;
    }
  }
  
  /* Send the string character by character on EPD */
  while ((*Text != 0) & (((BSP_EPD_GetXSize() - (i*pFont->Width)) & 0xFFFF) >= pFont->Width))
  {
    /* Display one character on EPD */
    BSP_EPD_DisplayChar(refcolumn, Ypos, *Text);
    /* Decrement the column position by 16 */
    refcolumn += pFont->Width;
    /* Point on the next character */
    Text++;
    i++;
  }
}

/**
  * @brief  Displays a character on the EPD.
  * @param  Line: Line where to display the character shape
  *          This parameter can be one of the following values:
  *            @arg  0..8: if the Current fonts is Font8
  *            @arg  0..5: if the Current fonts is Font12
  *            @arg  0..3: if the Current fonts is Font16
  *            @arg  0..2: if the Current fonts is Font20
  * @param  ptr: Pointer to string to display on EPD
  * @retval None
  */
void BSP_EPD_DisplayStringAtLine(uint16_t Line, uint8_t *ptr)
{
  BSP_EPD_DisplayStringAt(0, LINE(Line), ptr, LEFT_MODE);
}

/**
  * @brief  Draws an horizontal line.
  * @param  Xpos: X position 
  * @param  Ypos: Y position
  * @param  Length: line length
  * @retval None
  */
void BSP_EPD_DrawHLine(uint16_t Xpos, uint16_t Ypos, uint16_t Length)
{
  uint32_t index = 0;

  epd_drv->SetDisplayWindow(Xpos, Ypos, Xpos + Length, Ypos);

  for(index = 0; index < Length; index++)
  {
    /* Prepare the register to write data on the RAM */
    epd_drv->WritePixel(0x3F);
  }
}

/**
  * @brief  Draws a vertical line.
  * @param  Xpos: X position
  * @param  Ypos: Y position
  * @param  Length: line length.
  * @retval None
  */
void BSP_EPD_DrawVLine(uint16_t Xpos, uint16_t Ypos, uint16_t Length)
{
  uint32_t index = 0;
  
  epd_drv->SetDisplayWindow(Xpos, Ypos, Xpos, Ypos + Length);
  
  for(index = 0; index < Length; index++)
  {
    /* Prepare the register to write data on the RAM */
    epd_drv->WritePixel(0x00);
  }
}

/**
  * @brief  Draws a rectangle.
  * @param  Xpos: X position
  * @param  Ypos: Y position
  * @param  Height: rectangle height
  * @param  Width: rectangle width
  * @retval None
  */
void BSP_EPD_DrawRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height)
{
  /* Draw horizontal lines */
  BSP_EPD_DrawHLine(Xpos, Ypos, Width);
  BSP_EPD_DrawHLine(Xpos, (Ypos + Height), (Width + 1));
  
  /* Draw vertical lines */
  BSP_EPD_DrawVLine(Xpos, Ypos, Height);
  BSP_EPD_DrawVLine((Xpos + Width), Ypos , Height);
}

/**
  * @brief  Displays a full rectangle.
  * @param  Xpos: X position.
  * @param  Ypos: Y position.
  * @param  Height: display rectangle height.
  * @param  Width: display rectangle width.
  * @retval None
  */
void BSP_EPD_FillRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height)
{
  uint16_t index = 0;

  /* Set the rectangle */
  epd_drv->SetDisplayWindow(Xpos, Ypos, (Xpos + Width), (Ypos + Height));

  for(index = 0; index < 3096; index++)
  {
    epd_drv->WritePixel(0xFF);
  }
}

/**
  * @brief  Draws an Image.
  * @param  Xpos: X position in the EPD
  * @param  Ypos: Y position in the EPD
  * @param  Xsize: X size in the EPD
  * @param  Ysize: Y size in the EPD
  * @param  pdata: Pointer to the Image address
  * @retval None
  */
void BSP_EPD_DrawImage(uint16_t Xpos, uint16_t Ypos, uint16_t Xsize, uint16_t Ysize, uint8_t *pdata)
{
  /* Set display window */
  epd_drv->SetDisplayWindow(Xpos, Ypos, (Xpos+Ysize-1), (Ypos+(Xsize/4)-1));
  
  if(epd_drv->DrawImage != NULL)
  {
    epd_drv->DrawImage(Xpos, Ypos, Xsize, Ysize, pdata);
  }
  epd_drv->SetDisplayWindow(0, 0, BSP_EPD_GetXSize(), BSP_EPD_GetYSize());
}

/**
  * @brief  Disables the clock and the charge pump.
  * @param  None
  * @retval None
  */
void BSP_EPD_CloseChargePump(void)
{
  /* Close charge pump */
  epd_drv->CloseChargePump();

  /* Add a 400 ms delay */
  EPD_Delay(400);
}

/**
  * @brief  Updates the display from the data located into the RAM.
  * @param  None
  * @retval None
  */
void BSP_EPD_RefreshDisplay(void)
{
  /* Refresh display sequence */
  epd_drv->RefreshDisplay();

  /* Poll on the BUSY signal and wait for the EPD to be ready */
  while (HAL_GPIO_ReadPin(EPD_BUSY_GPIO_PORT, EPD_BUSY_PIN) != (uint16_t)RESET);

  /*  EPD reset pin management */
  EPD_RESET_HIGH();

  /* Add a 10 ms Delay after EPD pin Reset */
  EPD_Delay(10);
}

/*******************************************************************************
                            Static Functions
*******************************************************************************/

/**
  * @brief  Draws a character on EPD.
  * @param  Xpos: specifies the X position, can be a value from 0 to 171
  * @param  Ypos: specifies the Y position, can be a value from 0 to 17
  * @param  c: pointer to the character data
  * @retval None
  */
static void  DrawChar(uint16_t Xpos, uint16_t Ypos, const uint8_t *c)
{
  uint32_t index = 0;
  uint32_t data_length = 0;
  uint16_t height = 0;
  uint16_t width = 0;

  width  = pFont->Width;
  height = pFont->Height;
  
  /* Set the Character display window */
  epd_drv->SetDisplayWindow(Xpos, Ypos, (Xpos + width - 1), (Ypos + height - 1));
  
  data_length = (height * width);
    
  for(index = 0; index < data_length; index++)
  {
    epd_drv->WritePixel(c[index]);
  }
}

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
