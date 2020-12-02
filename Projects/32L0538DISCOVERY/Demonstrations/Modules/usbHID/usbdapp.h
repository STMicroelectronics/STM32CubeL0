/**
  ******************************************************************************
  * @file    usbdapp.h
  * @author  MCD Application Team   
  * @brief   Header for usbdapp.h.c file
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USBDAPP_H
#define __USBDAPP_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_hid.h" 
   
/* Exported constants --------------------------------------------------------*/   
#define CONNECTED                  0x00
#define DISCONNECTED               0x01
   
/* Exported types ------------------------------------------------------------*/

typedef enum
{
  USBD_ERROR_NONE = 0, 
  USBD_ERROR_IO,
  USBD_ERROR_HW, 
  USBD_ERROR_UNKNOWN, 
  
}USBD_ErrorTypdef;


/* Exported macros -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void GetPointerData(uint8_t *pbuf);
void USB_process(tsl_user_status_t status);

#ifdef __cplusplus
}
#endif

#endif /*__USBDAPP_H */

/*************************** End of file ****************************/
