/**
  ******************************************************************************
  * @file    Examples_LL/UTILS/UTILS_ReadDeviceInfo/Src/main.c
  * @author  MCD Application Team
  * @brief   This example describes how to read UID, Device ID and Revision ID 
  *          through the STM32L0xx UTILS LL API.
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

/** @addtogroup STM32L0xx_LL_Examples
  * @{
  */

/** @addtogroup UTILS_ReadDeviceInfo
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Buffer used for displaying different UTILS info */
uint8_t aShowDeviceID[30]    = {0};
uint8_t aShowRevisionID[30]  = {0};
uint8_t aShowUIDWord0[32]    = {0};
uint8_t aShowUIDWord1[32]    = {0};
uint8_t aShowUIDWord2[32]    = {0};

/* Private function prototypes -----------------------------------------------*/
void     GetMCUInfo(void);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  /* Get different information available in the MCU */
  GetMCUInfo();
  
  /* Infinite loop */
  while (1)
  {
  }
}

/**
  * @brief  Get different information available in the MCU (Device ID, Revision ID & UID)
  * @param  None
  * @retval None
  */
void GetMCUInfo(void)
{
  /* Display Device ID in string format */
  sprintf((char*)aShowDeviceID,"Device ID = 0x%lX", LL_DBGMCU_GetDeviceID());
  
  /* Display Revision ID in string format */
  sprintf((char*)aShowRevisionID,"Revision ID = 0x%lX", LL_DBGMCU_GetRevisionID());

  /* Display UID Word0 */
  sprintf((char*)aShowUIDWord0,"UID Word0 = 0x%lX", LL_GetUID_Word0());
  
  /* Display UID Word1 */
  sprintf((char*)aShowUIDWord1,"UID Word1 = 0x%lX", LL_GetUID_Word1());
  
  /* Display UID Word2 */
  sprintf((char*)aShowUIDWord2,"UID Word2 = 0x%lX", LL_GetUID_Word2());

}

/**
  * @}
  */

/**
  * @}
  */
