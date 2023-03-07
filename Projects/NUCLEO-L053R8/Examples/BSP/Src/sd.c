/**
  ******************************************************************************
  * @file    BSP/Src/sd.c 
  * @author  MCD Application Team
  * @brief   This example code shows how to use the SD feature using 
  *          the Nucleo Adafruit shield driver.
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
#include "main.h"

/** @addtogroup STM32L0xx_HAL_Examples
  * @{
  */

/** @addtogroup BSP
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define BLOCK_START_ADDR         0     /* Block start address      */
#define BLOCKSIZE                512   /* Block Size in Bytes      */
#define NUM_OF_BLOCKS            2     /* Total number of blocks   */
#define BUFFER_WORDS_SIZE        ((BLOCKSIZE * NUM_OF_BLOCKS) >> 2) /* Total data size in bytes */

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint32_t aTxBuffer[BUFFER_WORDS_SIZE];
uint32_t aRxBuffer[BUFFER_WORDS_SIZE];

/* Private function prototypes -----------------------------------------------*/
static void SD_SetHint(void);
static void Fill_Buffer(uint32_t *pBuffer, uint32_t uwBufferLenght, uint32_t uwOffset);
static uint8_t Buffercmp(uint32_t* pBuffer1, uint32_t* pBuffer2, uint16_t BufferLength);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  SD Demo
  * @param  None
  * @retval None
  */
void SD_demo(void)
{ 
  uint8_t SD_state = MSD_OK;

  SD_SetHint();
  SD_state = BSP_SD_Init();
  BSP_LCD_SetFont(&Font8);
  
  if(SD_state != MSD_OK)
  {
    BSP_LCD_DisplayStringAt(4, 88, (uint8_t *)"SD Initialization: FAIL", LEFT_MODE);
    BSP_LCD_DisplayStringAt(4, 100, (uint8_t *)"SD Test Aborted", LEFT_MODE);
  }
  else
  {
    BSP_LCD_DisplayStringAt(4, 88, (uint8_t *)"SD Initialization: OK", LEFT_MODE);
    
    SD_state = BSP_SD_Erase(BLOCK_START_ADDR, (BLOCKSIZE * NUM_OF_BLOCKS));
    
    if(SD_state != MSD_OK)
    {
      BSP_LCD_DisplayStringAt(4, 100, (uint8_t *)"SD ERASE: FAILED", LEFT_MODE);
      BSP_LCD_DisplayStringAt(4, 112, (uint8_t *)"SD Test Aborted.", LEFT_MODE);
    }
    else
    {
      BSP_LCD_DisplayStringAt(4, 100, (uint8_t *)"SD ERASE: OK", LEFT_MODE);
      
      /* Fill the buffer to write */
      Fill_Buffer(aTxBuffer, BUFFER_WORDS_SIZE, 0x22FF);
      SD_state = BSP_SD_WriteBlocks(aTxBuffer, BLOCK_START_ADDR, NUM_OF_BLOCKS, BSP_SD_TIMEOUT);
      
      if(SD_state != MSD_OK)
      {
        BSP_LCD_DisplayStringAt(4, 112, (uint8_t *)"SD WRITE: FAILED", LEFT_MODE);
        BSP_LCD_DisplayStringAt(4, 124, (uint8_t *)"SD Test Aborted", LEFT_MODE);
      }
      else
      {
        BSP_LCD_DisplayStringAt(4, 112, (uint8_t *)"SD WRITE: OK", LEFT_MODE);
        SD_state = BSP_SD_ReadBlocks(aRxBuffer, BLOCK_START_ADDR, NUM_OF_BLOCKS, BSP_SD_TIMEOUT);
        if(SD_state != MSD_OK)
        {
          BSP_LCD_DisplayStringAt(4, 124, (uint8_t *)"SD READ: FAILED", LEFT_MODE);
          BSP_LCD_DisplayStringAt(4, 136, (uint8_t *)"SD Test Aborted", LEFT_MODE);
        }
        else
        {
          BSP_LCD_DisplayStringAt(4, 124, (uint8_t *)"SD READ: OK", LEFT_MODE);
          if(Buffercmp(aTxBuffer, aRxBuffer, BUFFER_WORDS_SIZE) > 0)
          {
            BSP_LCD_DisplayStringAt(4, 136, (uint8_t *)"SD COMPARE: FAILED.", LEFT_MODE);
            BSP_LCD_DisplayStringAt(4, 148, (uint8_t *)"SD Test Aborted", LEFT_MODE);
          }
          else
          {
            BSP_LCD_DisplayStringAt(4, 136, (uint8_t *)"SD Test: OK", LEFT_MODE);
          }
        }
      }
    }
  }
  
  while (1)
  {   
    if(CheckForUserInput() > 0)
    {
      return;
    }
  }
}

/**
  * @brief  Display SD Demo Hint
  * @param  None
  * @retval None
  */
static void SD_SetHint(void)
{
  /* Clear the LCD */ 
  BSP_LCD_Clear(LCD_COLOR_WHITE);
  
  /* Set LCD Demo description */
  BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
  BSP_LCD_FillRect(0, 0, BSP_LCD_GetXSize(), 80);
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
  BSP_LCD_SetBackColor(LCD_COLOR_BLUE); 
  BSP_LCD_SetFont(&Font24);
  BSP_LCD_DisplayStringAt(0, 0, (uint8_t *)"SD", CENTER_MODE);
  BSP_LCD_SetFont(&Font12);
  BSP_LCD_DisplayStringAt(0, 20, (uint8_t *)"This example shows", CENTER_MODE);
  BSP_LCD_DisplayStringAt(0, 35, (uint8_t *)"how to write and", CENTER_MODE);
  BSP_LCD_DisplayStringAt(0, 50, (uint8_t *)"read data on the" , CENTER_MODE);
  BSP_LCD_DisplayStringAt(0, 65, (uint8_t *)"microSD card ", CENTER_MODE);
  
    /* Set the LCD Text Color */
  BSP_LCD_SetTextColor(LCD_COLOR_BLUE);  
  BSP_LCD_DrawRect(1, 82, BSP_LCD_GetXSize() - 3, BSP_LCD_GetYSize()- 84);
  BSP_LCD_DrawRect(2, 83, BSP_LCD_GetXSize() - 5, BSP_LCD_GetYSize()- 86); 
  BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
  BSP_LCD_SetBackColor(LCD_COLOR_WHITE); 
 }

/**
  * @brief  Fills buffer with user predefined data.
  * @param  pBuffer: pointer on the buffer to fill
  * @param  uwBufferLenght: size of the buffer to fill
  * @param  uwOffset: first value to fill on the buffer
  * @retval None
  */
static void Fill_Buffer(uint32_t *pBuffer, uint32_t uwBufferLenght, uint32_t uwOffset)
{
  uint32_t tmpIndex = 0;

  /* Put in global buffer different values */
  for (tmpIndex = 0; tmpIndex < uwBufferLenght; tmpIndex++ )
  {
    pBuffer[tmpIndex] = tmpIndex + uwOffset;
  }
}

/**
  * @brief  Compares two buffers.
  * @param  pBuffer1, pBuffer2: buffers to be compared.
  * @param  BufferLength: buffer's length
  * @retval 1: pBuffer identical to pBuffer1
  *         0: pBuffer differs from pBuffer1
  */
static uint8_t Buffercmp(uint32_t* pBuffer1, uint32_t* pBuffer2, uint16_t BufferLength)
{
  while (BufferLength--)
  {
    if (*pBuffer1 != *pBuffer2)
    {
      return 1;
    }

    pBuffer1++;
    pBuffer2++;
  }

  return 0;
}
/**
  * @}
  */ 

/**
  * @}
  */
