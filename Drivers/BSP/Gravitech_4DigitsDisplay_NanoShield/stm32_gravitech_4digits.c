/**
  ******************************************************************************
  * @file    stm32_gravitech_4digits.c
  * @author  MCD Application Team
  * @version V1.0.1
  * @date    16-October-2015
  * @brief   This file includes the driver for gravitech 
             7 Segment Display add-on module for Arduino Nano.  
             The module can display up to four digits numbers.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2014 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */ 

/* File Info : -----------------------------------------------------------------
                                   User NOTES
  This gravitech shield is intended to be plugged on the Nucleo_32 boards.
   
  This is a 7 Segment Display add-on module for Arduino Nano. 
  The module can display four digits numbers. 
   
  Features: 
  - Dimensions: 2.25” x 2.18” x 0.48”
  - Long header pins for stackability
  - 4 digits 7segment display
  
  For more details, please visit http://www.gravitech.us/7sediforarna.html 
 
------------------------------------------------------------------------------*/
    
/* Includes ------------------------------------------------------------------*/
#include "stm32_gravitech_4digits.h"

/** @addtogroup BSP
  * @{
  */

/** @addtogroup STM32_ADAFRUIT
  * @{
  */
    
/** @addtogroup STM32_GRAVITECH_4DIGITS
  * @{
  */ 

/** @defgroup STM32_GRAVITECH_4DIGITS_Exported_Functions
  * @{
  */

/**
  * @brief  BSP of the 4 digits 7 Segment Display shield for Arduino Nano - Gravitech.
            init
  * @param  None
  * @retval HAL_StatusTypeDef
  */
HAL_StatusTypeDef BSP_DIGIT4_SEG7_Init(void)
{
  uint8_t control[1] = {0x47};

  /* Init I2C */
  I2C1_Init();
  
  /* Configure the SAA1064 component */
  return I2C1_WriteBuffer(0x70, 0, 1, control, sizeof(control));
}

/**
  * @brief  BSP of the 4 digits 7 Segment Display shield for Arduino Nano - Gravitech.
            Display the value if value belong to [0-9999]
  * @param  None
  * @retval HAL_StatusTypeDef
  */
HAL_StatusTypeDef BSP_DIGIT4_SEG7_Display(uint32_t Value)
{
  const uint8_t lookup[10] = {0x3F,0x06,0x5B,0x4F,0x66,
                              0x6D,0x7D,0x07,0x7F,0x6F};
                              
  uint32_t thousands, hundreds, tens, base;
  HAL_StatusTypeDef status = HAL_ERROR;
  uint8_t d1d2d3d4[4];
  
  if (Value < 10000)
  {
    thousands = Value / 1000;
    hundreds = (Value - (thousands * 1000)) / 100;
    tens = (Value - ((thousands * 1000) + (hundreds * 100))) / 10;
    base = Value - ((thousands * 1000) + (hundreds * 100) + (tens * 10));

    d1d2d3d4[3] = lookup[thousands];
    d1d2d3d4[2] = lookup[hundreds];
    d1d2d3d4[1] = lookup[tens];
    d1d2d3d4[0] = lookup[base];
    
    /* Send the four digits to the SAA1064 component */
    status = I2C1_WriteBuffer(0x70, 1, 1, d1d2d3d4, sizeof(d1d2d3d4));
  }
  
  return status;
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
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
