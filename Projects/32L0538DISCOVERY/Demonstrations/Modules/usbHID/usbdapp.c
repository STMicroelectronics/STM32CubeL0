/**
  ******************************************************************************
  * @file    usbdapp.c
  * @author  MCD Application Team   
  * @brief   This file provides the USBD application method.
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
#include "usbdapp.h"

/** @addtogroup USB_DEVICE_MODULE
  * @{
  */

/** @defgroup USB_APPLICATION
  * @brief usb application routines 
  * @{
  */

/* External variables --------------------------------------------------------*/
extern USBD_HandleTypeDef USBD_Device;

/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
#define CURSOR_STEP     5

/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint8_t HID_Buffer[4];

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Gets Pointer Data.
  * @param  pbuf: Pointer to report
  * @retval None
  */
void GetPointerData(uint8_t *pbuf)
{
  int8_t  x = 0, y = 0 ;

  if (LINEAR_POSITION < 64)
  {
    /* Mouse Cursor move to the LEFT*/
    x -= CURSOR_STEP;
  }

  else if (LINEAR_POSITION < 128)
  {
    /* Mouse Cursor move to the RIGHT*/
    x += CURSOR_STEP;
  }
  else if (LINEAR_POSITION < 192)
  {
    /* Mouse Cursor move to the UP*/
    y -= CURSOR_STEP;
  }
  else
  {
    /* Mouse Cursor move to the DOWN*/
    y += CURSOR_STEP;
  }

  pbuf[0] = 0;
  pbuf[1] = x;
  pbuf[2] = y;
  pbuf[3] = 0;
}

/**
  * @brief  USB processing
  * @param  status TSL user status
  * @retval None
  */
void USB_process(tsl_user_status_t status)
{
  if (LINEAR_DETECT)
  {
    GetPointerData(HID_Buffer);
    /* send data though IN endpoint*/
    if((HID_Buffer[1] != 0) || (HID_Buffer[2] != 0))
    {
      USBD_HID_SendReport(&USBD_Device, HID_Buffer, 4);
    }
  }
}

/**
  * @}
  */

/**
  * @}
  */
