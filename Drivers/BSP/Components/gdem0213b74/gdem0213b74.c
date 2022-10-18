/**
  ******************************************************************************
  * @file    gdem0213b74.c
  * @author  MCD Application Team
  * @brief   This file includes the driver for GDEM0213B74 EPD (E Paper Display).
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

/* Includes ------------------------------------------------------------------*/
#include "gdem0213b74.h"

/** @addtogroup BSP
  * @{
  */

/** @addtogroup Components
  * @{
  */

/** @addtogroup GDEM0213B74
  * @brief      This file provides a set of functions needed to drive the
  *             GDEM0213B74 EPD (E Paper Display).
  * @{
  */

/** @defgroup GDEM0213B74_Private_TypesDefinitions
  * @{
  */
/**
  * @}
  */

/** @defgroup GDEM0213B74_Private_Defines
  * @{
  */
/**
  * @}
  */

/** @defgroup GDEM0213B74_Private_Macros
  * @{
  */
/**
  * @}
  */

/** @defgroup GDEM0213B74_Private_Variables
  * @{
  */

EPD_DrvTypeDef   gdem0213b74_drv =
{
  gdem0213b74_Init,
  gdem0213b74_WritePixel,
  gdem0213b74_SetDisplayWindow,
  gdem0213b74_RefreshDisplay,
  gdem0213b74_CloseChargePump,
  gdem0213b74_GetEpdPixelWidth,
  gdem0213b74_GetEpdPixelHeight,
  gdem0213b74_DrawImage,
};

/**
* @}
*/

/** @defgroup GDEM0213B74_Private_FunctionPrototypes
  * @{
  */
/**
* @}
*/

/** @defgroup GDEM0213B74_Private_Functions
  * @{
  */

/**
  * @brief  Initialize the GDEM0213B74 EPD Component.
  * @param  None
  * @retval None
  */
void gdem0213b74_Init(void)
{
  EPD_IO_Init();

  EPD_IO_Reset_Low();            /* Module reset */ 
  EPD_Delay(10);                 /* At least 10ms delay */
  EPD_IO_Reset_High();
  EPD_Delay(10);                 /* At least 10ms delay */
  EPD_ReadBusy();
  EPD_IO_WriteReg(EPD_REG_18);   /* SWRESET */
  EPD_ReadBusy();
  EPD_IO_WriteReg(EPD_REG_1);    /* Driver output control */
  EPD_IO_WriteData(0xF9);
  EPD_IO_WriteData(0x00);
  EPD_IO_WriteData(0x00);
  EPD_IO_WriteReg(EPD_REG_60);   /* BorderWavefrom */
  EPD_IO_WriteData(0x05);	
  EPD_IO_WriteReg(EPD_REG_33);   /* Display update control */
  EPD_IO_WriteData(0x00);		
  EPD_IO_WriteData(0x80);	
  EPD_IO_WriteReg(EPD_REG_24);   /* Read built-in temperature sensor */
  EPD_IO_WriteData(0x80);	
  EPD_IO_WriteReg(EPD_REG_17);   /* data entry mode */ 
  EPD_IO_WriteData(0x03);
  EPD_IO_WriteReg(EPD_REG_68);   /* set Ram-X address start/end position */
  EPD_IO_WriteData(0x00);
  EPD_IO_WriteData(0x0F);        /* 0x0F-->(15+1)*8=128 */
  EPD_IO_WriteReg(EPD_REG_69);   /* set Ram-Y address start/end position */
  EPD_IO_WriteData(0xF9);        /* 0xF9-->(249+1)=250 */
  EPD_IO_WriteData(0x00);
  EPD_IO_WriteData(0x00);
  EPD_IO_WriteData(0x00); 
  EPD_IO_WriteReg(EPD_REG_78);   /* set RAM x address count to 0 */
  EPD_IO_WriteData(0x00);
  EPD_IO_WriteReg(EPD_REG_79);   /* set RAM y address count to 0X199 */
  EPD_IO_WriteData(0xF9);
  EPD_IO_WriteData(0x00);
  EPD_ReadBusy();
}

/**
  * @brief  Writes 4 dots.
  * @param  HEX_Code: specifies the Data to write.
  * @retval None
  */
void gdem0213b74_WritePixel(uint8_t HEX_Code)
{
  /* Prepare the register to write data on the RAM */
  EPD_IO_WriteReg(EPD_REG_36);

  /* Send the data to write */
  EPD_IO_WriteData(HEX_Code);
}

/**
  * @brief  Sets a display window.
  * @param  Xpos: specifies the X bottom left position.
  * @param  Ypos: specifies the Y bottom left position.
  * @param  Width: display window width.
  * @param  Height: display window height.
  * @retval None
*/
void gdem0213b74_SetDisplayWindow(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height)
{
  /* Set Y position and the height */
  EPD_IO_WriteReg(EPD_REG_68);
  EPD_IO_WriteData(Ypos);
  EPD_IO_WriteData(Height);
  /* Set X position and the width */
  EPD_IO_WriteReg(EPD_REG_69);
  EPD_IO_WriteData(Xpos);
  EPD_IO_WriteData(Width);
  /* Set the height counter */
  EPD_IO_WriteReg(EPD_REG_78);
  EPD_IO_WriteData(Ypos);
  /* Set the width counter */
  EPD_IO_WriteReg(EPD_REG_79);
  EPD_IO_WriteData(Xpos);
}

/**
  * @brief  Gets the EPD pixel Width.
  * @param  None
  * @retval The EPD Pixel Width
  */
uint16_t gdem0213b74_GetEpdPixelWidth(void)
{
  return GDEM0213B74_EPD_PIXEL_WIDTH;
}

/**
  * @brief  Gets the EPD pixel Height.
  * @param  None
  * @retval The EPD Pixel Height
  */
uint16_t gdem0213b74_GetEpdPixelHeight(void)
{
  return GDEM0213B74_EPD_PIXEL_HEIGHT;
}

/**
  * @brief  Writes to the selected EPD register.
  * @param  EPD_Reg: Address of the selected register.
  * @param  EPD_RegValue: value to write to the selected register.
  * @retval None
  */
void gdem0213b74_WriteReg(uint8_t EPD_Reg, uint8_t EPD_RegValue)
{
  EPD_IO_WriteReg(EPD_Reg);

  EPD_IO_WriteData(EPD_RegValue);
}

/**
  * @brief  Reads the selected EPD Register.
  * @param  EPD_Reg: address of the selected register
  * @retval EPD Register Value
  */
uint8_t gdem0213b74_ReadReg(uint8_t EPD_Reg)
{
  /* Write 8-bit Index (then Read Reg) */
  EPD_IO_WriteReg(EPD_Reg);

  /* Read 8-bit Reg */
  return (EPD_IO_ReadData());
}

/**
  * @brief  Activates display update sequence.
  * @param  None
  * @retval None
  */
void gdem0213b74_RefreshDisplay(void)
{
  /* Write on the Display update control register */
  EPD_IO_WriteReg(EPD_REG_34);

  /* Display update data sequence option */
  EPD_IO_WriteData(0xF7);

  /* Launching the update: Nothing should interrupt this sequence in order
     to avoid display corruption */
  EPD_IO_WriteReg(EPD_REG_32);
}

/**
  * @brief  Disables the clock and the charge pump.
  * @param  None
  * @retval None
  */
void gdem0213b74_CloseChargePump(void)
{
  /* Write on the Display update control register */
  EPD_IO_WriteReg(EPD_REG_34);

  /* Disable CP then Disable Clock signal */
  EPD_IO_WriteData(0x03);

  /* Launching the update: Nothing should interrupt this sequence in order
     to avoid display corruption */
  EPD_IO_WriteReg(EPD_REG_32);
}

/**
  * @brief  Displays picture..
  * @param  pdata: picture address.
  * @param  Xpos:  Image X position in the EPD
  * @param  Ypos:  Image Y position in the EPD
  * @param  Xsize: Image X size in the EPD
  * @note   Xsize have to be a multiple of 4
  * @param  Ysize: Image Y size in the EPD
  * @retval None
  */
void gdem0213b74_DrawImage(uint16_t Xpos, uint16_t Ypos, uint16_t Xsize, uint16_t Ysize, uint8_t *pdata)
{
  uint32_t i, j = 0;
  uint8_t pixels_4 = 0;
  uint8_t pixels_4_grey[4] = {0};
  uint8_t nb_4_pixels, data_res = 0;

  /* Prepare the register to write data on the RAM */
  EPD_IO_WriteReg(EPD_REG_36);

  /* X size is a multiple of 8 */
  if ((Xsize % 8) == 0)
  {
    for (i= 0; i< ((((Ysize) * (Xsize/4)))/2) ; i++)
    {
      /* Get the current data */
      pixels_4 = pdata[i];
      if (pixels_4 !=0)
      {
        /* One byte read codes 8 pixels in 1-bit bitmap */
        for (nb_4_pixels = 0; nb_4_pixels < 2; nb_4_pixels++)
        {
          /* Processing 8 pixels */
          /* Preparing the 4 pixels coded with 4 grey level per pixel
             from a monochrome xbm file */
          for (j= 0; j<4; j++)
          {
            if (((pixels_4) & 0x01) == 1)
            {
              /* Two LSB is coding black in 4 grey level */
              pixels_4_grey[j] &= 0xFC;
            }
            else
            {
              /* Two LSB is coded white in 4 grey level */
              pixels_4_grey[j] |= 0x03;
            }
            pixels_4 = pixels_4 >> 1;
          }

          /* Processing 4 pixels */
          /* Format the data to have the Lower pixel number sent on the MSB for the SPI to fit with the RAM
             EPD topology */
          data_res = pixels_4_grey[0] << 6 | pixels_4_grey[1] << 4 | pixels_4_grey[2] << 2 | pixels_4_grey[3] << 0;

          /* Send the data to the EPD's RAM through SPI */
          EPD_IO_WriteData(data_res);
        }
      }
      else
      {
        /* 1 byte read from xbm files is equivalent to 8 pixels in the
           other words 2 bytes to be transferred */
        EPD_IO_WriteData(0xFF);
        EPD_IO_WriteData(0xFF);
      }
    }
  }

  /* X size is a multiple of 4 */
  else
  {
    for (i= 0; i< ((((Ysize) * ((Xsize/4)+1))/2)) ; i++)
    {
      /* Get the current data */
      pixels_4 = pdata[i];
      if (((i+1) % (((Xsize/4)+1)/2)) != 0)
      {
        if (pixels_4 !=0)
        {
          /* One byte read codes 8 pixels in 1-bit bitmap */
          for (nb_4_pixels = 0; nb_4_pixels < 2; nb_4_pixels++)
          {
            /* Processing 8 pixels */
            /* Preparing the 4 pixels coded with 4 grey level per pixel
               from a monochrome xbm file */
            for (j= 0; j<4; j++)
            {
              if (((pixels_4) & 0x01) == 1)
              {
                /* Two LSB is coding black in 4 grey level */
                pixels_4_grey[j] &= 0xFC;
              }
              else
              {
                /* Two LSB is coded white in 4 grey level */
                pixels_4_grey[j] |= 0x03;
              }
              pixels_4 = pixels_4 >> 1;
            }

            /* Processing 4 pixels */
            /* Format the data to have the Lower pixel number sent on the MSB for the SPI to fit with the RAM
               EPD topology */
            data_res = pixels_4_grey[0] << 6 | pixels_4_grey[1] << 4 | pixels_4_grey[2] << 2 | pixels_4_grey[3] << 0;

            /* Send the data to the EPD's RAM through SPI */
            EPD_IO_WriteData(data_res);
          }
        }
        else if (pixels_4 == 0)
        {
          /* One byte read from xbm files is equivalent to 8 pixels in the
             other words Two bytes to be transferred */
          EPD_IO_WriteData(0xFF);
          EPD_IO_WriteData(0xFF);
        }
      }

      else if (((i+1) % (((Xsize/4)+1)/2)) == 0)
      {
        if (pixels_4 !=0xf0)
        {
          /* Processing 8 pixels */
          /* Preparing the 4 pixels coded with 4 grey level per pixel
             from a monochrome xbm file */
          for (j= 0; j<4; j++)
          {
            if (((pixels_4) & 0x01) == 1)
            {
              /* 2 LSB is coding black in 4 grey level */
              pixels_4_grey[j] &= 0xFC;
            }
            else
            {
              /* 2 LSB is coded white in 4 grey level */
              pixels_4_grey[j] |= 0x03;
            }
            pixels_4 = pixels_4 >> 1;
          }

          /* Processing 4 pixels */
          /* Format the data to have the Lower pixel number sent on the MSB for the SPI to fit with the RAM
             EPD topology */
          data_res = pixels_4_grey[0] << 6 | pixels_4_grey[1] << 4 | pixels_4_grey[2] << 2 | pixels_4_grey[3] << 0;

          /* Send the data to the EPD's RAM through SPI */
          EPD_IO_WriteData(data_res);
        }
        else if (pixels_4 == 0xf0)
        {
          /* One byte to be transferred */
          EPD_IO_WriteData(0xFF);
        }
      }
    }
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

