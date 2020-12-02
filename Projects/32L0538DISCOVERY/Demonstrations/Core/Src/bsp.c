/**
  ******************************************************************************
  * @file    bsp.c 
  * @author  MCD Application Team
  * @brief   Main program body
  *          This example code shows how to use the Nucleo BSP Drivers
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
#include "bsp.h"


/** @addtogroup CORE
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
/* TSC handler declaration */
TSC_HandleTypeDef TscHandle;
/* USB handler declaration */
USBD_HandleTypeDef USBD_Device;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Initializes LEDs, Button, EPD and LTS.
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
  
  /* Initialize the Touch sensor */
  BSP_TSL_Init();
}

/**
  * @brief  Configure the touch sensor.
  * @param  None 
  * @retval None
  */
void BSP_TSL_Init(void)
{
  /* Configure the TSC peripheral */
  TscHandle.Instance = TSC;
  TscHandle.Init.AcquisitionMode         = TSC_ACQ_MODE_NORMAL;
  TscHandle.Init.CTPulseHighLength       = TSC_CTPH_2CYCLES;
  TscHandle.Init.CTPulseLowLength        = TSC_CTPL_2CYCLES; 
  TscHandle.Init.IODefaultMode           = TSC_IODEF_IN_FLOAT;
  TscHandle.Init.MaxCountInterrupt       = DISABLE;
  TscHandle.Init.MaxCountValue           = TSC_MCV_8191;
  TscHandle.Init.PulseGeneratorPrescaler = TSC_PG_PRESC_DIV32;
  TscHandle.Init.SpreadSpectrum          = DISABLE;
  TscHandle.Init.SpreadSpectrumDeviation = 127;
  TscHandle.Init.SpreadSpectrumPrescaler = TSC_SS_PRESC_DIV1;
  TscHandle.Init.SynchroPinPolarity      = TSC_SYNC_POLARITY_FALLING;
  /* All channel, shield and sampling IOs must be declared below */
  TscHandle.Init.ChannelIOs              = TSC_GROUP1_IO3 | TSC_GROUP2_IO3 | TSC_GROUP3_IO2;
  TscHandle.Init.SamplingIOs             = TSC_GROUP1_IO4 | TSC_GROUP2_IO4 | TSC_GROUP3_IO3;
  TscHandle.Init.ShieldIOs               = 0;
  HAL_TSC_Init(&TscHandle);

  /* Initialize the STMTouch driver */
  tsl_user_Init();
}

/**
  * @brief  Initializes LEDs, Button, and EPD.
  * @param  None 
  * @retval None
  */
void BSP_USB_Init(void)
{
  /* Init Device Library */
  USBD_Init(&USBD_Device, &HID_Desc, 0);
  
  /* Register the HID class */
  USBD_RegisterClass(&USBD_Device, &USBD_HID);
  
  /* Start Device Process */
  USBD_Start(&USBD_Device);
}

/**
  * @}
  */

/**
  * @}
  *
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
