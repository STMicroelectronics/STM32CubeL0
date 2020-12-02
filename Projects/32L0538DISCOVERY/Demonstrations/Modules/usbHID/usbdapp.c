/**
  ******************************************************************************
  * @file    usbdapp.c
  * @author  MCD Application Team   
  * @brief   This file provides the USBD application method.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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

/*************************** End of file ****************************/
