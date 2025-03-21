/**
  ******************************************************************************
  * @file    usbdevice_res.c
  * @author  MCD Application Team   
  * @brief   USB Device resources
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
  *******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

/** @addtogroup USB_DEVICE_MODULE
  * @{
  */

/** @defgroup USB_DEVICE_RES
  * @brief usb device resources 
  * @{
  */
#if defined (USE_STM32L0538_DISCO_REV_B03)
//#define x_width 23
//#define x_height 200
static uint8_t FullSlider_pic[] = {
0X00,0X00,0X00,0X00,0X00,
0X00,0XF8,0XFF,0X0F,0X08,
0X00,0X08,0X08,0X00,0X08,
0X08,0X00,0X08,0X18,0X00,
0X08,0X18,0X00,0X08,0X18,
0X00,0X08,0X18,0X00,0X08,
0X18,0X00,0X08,0X18,0X00,
0X08,0X18,0X00,0X08,0X18,
0X00,0X08,0X18,0X00,0X08,
0X18,0X00,0X08,0X18,0X00,
0X08,0X38,0X00,0X08,0X38,
0X00,0X08,0X38,0X00,0X08,
0X38,0X00,0X08,0X38,0X00,
0X08,0X38,0X00,0X08,0X38,
0X00,0X08,0X38,0X00,0X08,
0X38,0X00,0X08,0X38,0X00,
0X08,0X38,0X00,0X08,0X38,
0X00,0X08,0X38,0X00,0X08,
0X38,0X00,0X08,0X38,0X00,
0X08,0X78,0X00,0X08,0X78,
0X00,0X08,0X78,0X00,0X08,
0X78,0X00,0X08,0X78,0X00,
0X08,0X78,0X00,0X08,0X78,
0X00,0X08,0X78,0X00,0X08,
0X78,0X00,0X08,0XF8,0XFF,
0X0F,0XF8,0XFF,0X0F,0XF8,
0X00,0X08,0XF8,0X00,0X08,
0XF8,0X00,0X08,0XF8,0X00,
0X08,0XF8,0X00,0X08,0XF8,
0X00,0X08,0XF8,0X00,0X08,
0XF8,0X00,0X08,0XF8,0X00,
0X08,0XF8,0X00,0X08,0XF8,
0X00,0X08,0XF8,0X00,0X08,
0XF8,0X00,0X08,0XF8,0X00,
0X08,0XF8,0X00,0X08,0XF8,
0X01,0X08,0XF8,0X01,0X08,
0XF8,0X01,0X08,0XF8,0X01,
0X08,0XF8,0X01,0X08,0XF8,
0X01,0X08,0XF8,0X01,0X08,
0XF8,0X01,0X08,0XF8,0X01,
0X08,0XF8,0X01,0X08,0XF8,
0X01,0X08,0XF8,0X01,0X08,
0XF8,0X03,0X08,0XF8,0X03,
0X08,0XF8,0X03,0X08,0XF8,
0X03,0X08,0XF8,0X03,0X08,
0XF8,0X03,0X08,0XF8,0X03,
0X08,0XF8,0X03,0X08,0XF8,
0X03,0X08,0XF8,0X03,0X08,
0XF8,0X03,0X08,0XF8,0X03,
0X08,0XF8,0X03,0X08,0XF8,
0X03,0X08,0XF8,0X03,0X08,
0XF8,0X07,0X08,0XF8,0X07,
0X08,0XF8,0X07,0X08,0XF8,
0X07,0X08,0XF8,0X07,0X08,
0XF8,0X07,0X08,0XF8,0XFF,
0X0F,0XF8,0XFF,0X0F,0XF8,
0X07,0X08,0XF8,0X07,0X08,
0XF8,0X07,0X08,0XF8,0X0F,
0X08,0XF8,0X0F,0X08,0XF8,
0X0F,0X08,0XF8,0X0F,0X08,
0XF8,0X0F,0X08,0XF8,0X0F,
0X08,0XF8,0X0F,0X08,0XF8,
0X0F,0X08,0XF8,0X0F,0X08,
0XF8,0X0F,0X08,0XF8,0X0F,
0X08,0XF8,0X0F,0X08,0XF8,
0X1F,0X08,0XF8,0X1F,0X08,
0XF8,0X1F,0X08,0XF8,0X1F,
0X08,0XF8,0X1F,0X08,0XF8,
0X1F,0X08,0XF8,0X1F,0X08,
0XF8,0X1F,0X08,0XF8,0X1F,
0X08,0XF8,0X1F,0X08,0XF8,
0X1F,0X08,0XF8,0X1F,0X08,
0XF8,0X1F,0X08,0XF8,0X1F,
0X08,0XF8,0X1F,0X08,0XF8,
0X3F,0X08,0XF8,0X3F,0X08,
0XF8,0X3F,0X08,0XF8,0X3F,
0X08,0XF8,0X3F,0X08,0XF8,
0X3F,0X08,0XF8,0X3F,0X08,
0XF8,0X3F,0X08,0XF8,0X3F,
0X08,0XF8,0X3F,0X08,0XF8,
0X3F,0X08,0XF8,0X7F,0X08,
0XF8,0X7F,0X08,0XF8,0X7F,
0X08,0XF8,0X7F,0X08,0XF8,
0X7F,0X08,0XF8,0X7F,0X08,
0XF8,0XFF,0X0F,0XF8,0XFF,
0X0F,0XF8,0X7F,0X08,0XF8,
0X7F,0X08,0XF8,0X7F,0X08,
0XF8,0X7F,0X08,0XF8,0X7F,
0X08,0XF8,0X7F,0X08,0XF8,
0X7F,0X08,0XF8,0XFF,0X08,
0XF8,0XFF,0X08,0XF8,0XFF,
0X08,0XF8,0XFF,0X08,0XF8,
0XFF,0X08,0XF8,0XFF,0X08,
0XF8,0XFF,0X08,0XF8,0XFF,
0X08,0XF8,0XFF,0X08,0XF8,
0XFF,0X08,0XF8,0XFF,0X08,
0XF8,0XFF,0X08,0XF8,0XFF,
0X09,0XF8,0XFF,0X09,0XF8,
0XFF,0X09,0XF8,0XFF,0X09,
0XF8,0XFF,0X09,0XF8,0XFF,
0X09,0XF8,0XFF,0X09,0XF8,
0XFF,0X09,0XF8,0XFF,0X09,
0XF8,0XFF,0X09,0XF8,0XFF,
0X09,0XF8,0XFF,0X09,0XF8,
0XFF,0X09,0XF8,0XFF,0X09,
0XF8,0XFF,0X09,0XF8,0XFF,
0X0B,0XF8,0XFF,0X0B,0XF8,
0XFF,0X0B,0XF8,0XFF,0X0B,
0XF8,0XFF,0X0B,0XF8,0XFF,
0X0B,0XF8,0XFF,0X0B,0XF8,
0XFF,0X0B,0XF8,0XFF,0X0B,
0XF8,0XFF,0X0B,0XF8,0XFF,
0X0B,0XF8,0XFF,0X0F,0XF8,
0XFF,0X0F,0XF8,0XFF,0X0F,
0XF8,0XFF,0X0F,0XF8,0XFF,
0X0F,0XF8,0XFF,0X0F,0XF8,
0XFF,0X0F,0XF8,0XFF,0X0F,
0XF8,0XFF,0X0F,0XF8,0XFF,
0X0F,0XF8,0XFF,0X0F,0X00,
0X00,0X00,0X00,0X00,0X00,
};
#else /* USE_STM32L0538_DISCO */

//#define x_width 28
//#define x_height 146
static uint8_t FullSlider_pic[] = {
0x00, 0x00, 0x00, 0xf0, 
0x00, 0x00, 0x00, 0xf0, 
0x00, 0x00, 0x00, 0xf0, 
0x00, 0x00, 0x00, 0xf0, 
0x00, 0x00, 0x00, 0xf0, 
0xc0, 0xff, 0x7f, 0xf0, 
0xc0, 0x00, 0x40, 0xf0, 
0xc0, 0x00, 0x40, 0xf0, 
0xc0, 0x00, 0x40, 0xf0, 
0xc0, 0x00, 0x40, 0xf0, 
0xc0, 0x00, 0x40, 0xf0, 
0xc0, 0x01, 0x40, 0xf0, 
0xc0, 0x01, 0x40, 0xf0, 
0xc0, 0x01, 0x40, 0xf0, 
0xc0, 0x01, 0x40, 0xf0, 
0xc0, 0x01, 0x40, 0xf0, 
0xc0, 0x01, 0x40, 0xf0, 
0xc0, 0x01, 0x40, 0xf0, 
0xc0, 0x01, 0x40, 0xf0, 
0xc0, 0x01, 0x40, 0xf0, 
0xc0, 0x03, 0x40, 0xf0, 
0xc0, 0x03, 0x40, 0xf0, 
0xc0, 0x03, 0x40, 0xf0, 
0xc0, 0x03, 0x40, 0xf0, 
0xc0, 0x03, 0x40, 0xf0, 
0xc0, 0x03, 0x40, 0xf0, 
0xc0, 0x03, 0x40, 0xf0, 
0xc0, 0x03, 0x40, 0xf0, 
0xc0, 0x03, 0x40, 0xf0, 
0xc0, 0x03, 0x40, 0xf0, 
0xc0, 0x03, 0x40, 0xf0, 
0xc0, 0x07, 0x40, 0xf0, 
0xc0, 0x07, 0x40, 0xf0, 
0xc0, 0x07, 0x40, 0xf0, 
0xc0, 0x07, 0x40, 0xf0, 
0xc0, 0x07, 0x40, 0xf0, 
0xc0, 0x07, 0x40, 0xf0, 
0xc0, 0x07, 0x40, 0xf0, 
0xc0, 0xff, 0x7f, 0xf0, 
0xc0, 0x07, 0x40, 0xf0, 
0xc0, 0x07, 0x40, 0xf0, 
0xc0, 0x07, 0x40, 0xf0, 
0xc0, 0x0f, 0x40, 0xf0, 
0xc0, 0x0f, 0x40, 0xf0, 
0xc0, 0x0f, 0x40, 0xf0, 
0xc0, 0x0f, 0x40, 0xf0, 
0xc0, 0x0f, 0x40, 0xf0, 
0xc0, 0x0f, 0x40, 0xf0, 
0xc0, 0x0f, 0x40, 0xf0, 
0xc0, 0x0f, 0x40, 0xf0, 
0xc0, 0x0f, 0x40, 0xf0, 
0xc0, 0x0f, 0x40, 0xf0, 
0xc0, 0x1f, 0x40, 0xf0, 
0xc0, 0x1f, 0x40, 0xf0, 
0xc0, 0x1f, 0x40, 0xf0, 
0xc0, 0x1f, 0x40, 0xf0, 
0xc0, 0x1f, 0x40, 0xf0, 
0xc0, 0x1f, 0x40, 0xf0, 
0xc0, 0x1f, 0x40, 0xf0, 
0xc0, 0x1f, 0x40, 0xf0, 
0xc0, 0x1f, 0x40, 0xf0, 
0xc0, 0x1f, 0x40, 0xf0, 
0xc0, 0x3f, 0x40, 0xf0, 
0xc0, 0x3f, 0x40, 0xf0, 
0xc0, 0x3f, 0x40, 0xf0, 
0xc0, 0x3f, 0x40, 0xf0, 
0xc0, 0x3f, 0x40, 0xf0, 
0xc0, 0x3f, 0x40, 0xf0, 
0xc0, 0x3f, 0x40, 0xf0, 
0xc0, 0x3f, 0x40, 0xf0, 
0xc0, 0x3f, 0x40, 0xf0, 
0xc0, 0x3f, 0x40, 0xf0, 
0xc0, 0xff, 0x7f, 0xf0, 
0xc0, 0x7f, 0x40, 0xf0, 
0xc0, 0x7f, 0x40, 0xf0, 
0xc0, 0x7f, 0x40, 0xf0, 
0xc0, 0x7f, 0x40, 0xf0, 
0xc0, 0x7f, 0x40, 0xf0, 
0xc0, 0x7f, 0x40, 0xf0, 
0xc0, 0x7f, 0x40, 0xf0, 
0xc0, 0x7f, 0x40, 0xf0, 
0xc0, 0x7f, 0x40, 0xf0, 
0xc0, 0xff, 0x40, 0xf0, 
0xc0, 0xff, 0x40, 0xf0, 
0xc0, 0xff, 0x40, 0xf0, 
0xc0, 0xff, 0x40, 0xf0, 
0xc0, 0xff, 0x40, 0xf0, 
0xc0, 0xff, 0x40, 0xf0, 
0xc0, 0xff, 0x40, 0xf0, 
0xc0, 0xff, 0x40, 0xf0, 
0xc0, 0xff, 0x40, 0xf0, 
0xc0, 0xff, 0x40, 0xf0, 
0xc0, 0xff, 0x41, 0xf0, 
0xc0, 0xff, 0x41, 0xf0, 
0xc0, 0xff, 0x41, 0xf0, 
0xc0, 0xff, 0x41, 0xf0, 
0xc0, 0xff, 0x41, 0xf0, 
0xc0, 0xff, 0x41, 0xf0, 
0xc0, 0xff, 0x41, 0xf0, 
0xc0, 0xff, 0x41, 0xf0, 
0xc0, 0xff, 0x41, 0xf0, 
0xc0, 0xff, 0x41, 0xf0, 
0xc0, 0xff, 0x43, 0xf0, 
0xc0, 0xff, 0x7f, 0xf0, 
0xc0, 0xff, 0x43, 0xf0, 
0xc0, 0xff, 0x43, 0xf0, 
0xc0, 0xff, 0x43, 0xf0, 
0xc0, 0xff, 0x43, 0xf0, 
0xc0, 0xff, 0x43, 0xf0, 
0xc0, 0xff, 0x43, 0xf0, 
0xc0, 0xff, 0x43, 0xf0, 
0xc0, 0xff, 0x43, 0xf0, 
0xc0, 0xff, 0x43, 0xf0, 
0xc0, 0xff, 0x47, 0xf0, 
0xc0, 0xff, 0x47, 0xf0, 
0xc0, 0xff, 0x47, 0xf0, 
0xc0, 0xff, 0x47, 0xf0, 
0xc0, 0xff, 0x47, 0xf0, 
0xc0, 0xff, 0x47, 0xf0, 
0xc0, 0xff, 0x47, 0xf0, 
0xc0, 0xff, 0x47, 0xf0, 
0xc0, 0xff, 0x47, 0xf0, 
0xc0, 0xff, 0x47, 0xf0, 
0xc0, 0xff, 0x4f, 0xf0, 
0xc0, 0xff, 0x4f, 0xf0, 
0xc0, 0xff, 0x4f, 0xf0, 
0xc0, 0xff, 0x4f, 0xf0, 
0xc0, 0xff, 0x4f, 0xf0, 
0xc0, 0xff, 0x4f, 0xf0, 
0xc0, 0xff, 0x4f, 0xf0, 
0xc0, 0xff, 0x4f, 0xf0, 
0xc0, 0xff, 0x4f, 0xf0, 
0xc0, 0xff, 0x4f, 0xf0, 
0xc0, 0xff, 0x7f, 0xf0, 
0xc0, 0xff, 0x7f, 0xf0, 
0xc0, 0xff, 0x7f, 0xf0, 
0xc0, 0xff, 0x7f, 0xf0, 
0xc0, 0xff, 0x7f, 0xf0, 
0x00, 0x00, 0x00, 0xf0, 
0x00, 0x00, 0x00, 0xf0, 
0x00, 0x00, 0x00, 0xf0, 
0x00, 0x00, 0x00, 0xf0, 
0x00, 0x00, 0x00, 0xf0, 
0x00, 0x00, 0x00, 0xf0, 
0x00, 0x00, 0x00, 0xf0, 
0x00, 0x00, 0x00, 0xf0, 
};
#endif /* USE_STM32L0538_DISCO_REV_B03 */
/**
  * @}
  */

/**
  * @}
  */
