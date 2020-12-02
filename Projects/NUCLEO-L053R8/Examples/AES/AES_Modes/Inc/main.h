/**
  ******************************************************************************
  * @file    AES/AES_Modes/Inc/main.h 
  * @author  MCD Application Team
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"
#include "stm32l0xx_nucleo.h"
#include "string.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Define AES MODE  ----------------------------------------------------------*/
/* Uncomment the line below if you will use the ECB Mode */
#define AES_ECB 
/* Uncomment the line below if you will use the CBC Mode */
#define AES_CBC
/* Uncomment the line below if you will use the CTR Mode */
#define AES_CTR

#if !defined (AES_ECB) && !defined (AES_CBC) && !defined (AES_CTR)
 #error "Please select first the AES MODE"
#endif

/* Set the timeout value */
#define  TIMEOUT_VALUE   0xFF

#define AES_TEXT_SIZE     64 /* 16 x 4 */
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
