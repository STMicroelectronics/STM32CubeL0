/**
  ******************************************************************************
  * @file    AES/AES_Modes/Inc/main.h 
  * @author  MCD Application Team
  * @brief   Header for main.c module
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
