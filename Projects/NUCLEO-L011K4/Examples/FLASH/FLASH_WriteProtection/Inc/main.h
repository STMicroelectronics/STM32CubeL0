/**
  ******************************************************************************
  * @file    FLASH/FLASH_WriteProtection/Inc/main.h
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
#include "stm32l0xx_nucleo_32.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Base address of the Flash pages */
/* Base address of the Flash pages */
#define ADDR_FLASH_PAGE_0     ((uint32_t)0x08000000) /* Base @ of Page 0, 128 bytes */
#define ADDR_FLASH_PAGE_1     ((uint32_t)0x08000080) /* Base @ of Page 1, 128 bytes */
#define ADDR_FLASH_PAGE_2     ((uint32_t)0x08000100) /* Base @ of Page 2, 128 bytes */
#define ADDR_FLASH_PAGE_3     ((uint32_t)0x08000180) /* Base @ of Page 3, 128 bytes */
#define ADDR_FLASH_PAGE_4     ((uint32_t)0x08000200) /* Base @ of Page 4, 128 bytes */
#define ADDR_FLASH_PAGE_5     ((uint32_t)0x08000280) /* Base @ of Page 5, 128 bytes */
#define ADDR_FLASH_PAGE_6     ((uint32_t)0x08000300) /* Base @ of Page 6, 128 bytes */
#define ADDR_FLASH_PAGE_7     ((uint32_t)0x08000380) /* Base @ of Page 7, 128 bytes */
#define ADDR_FLASH_PAGE_8     ((uint32_t)0x08000400) /* Base @ of Page 8, 128 bytes */
#define ADDR_FLASH_PAGE_9     ((uint32_t)0x08000480) /* Base @ of Page 9, 128 bytes */
#define ADDR_FLASH_PAGE_10    ((uint32_t)0x08000500) /* Base @ of Page 10, 128 bytes */
#define ADDR_FLASH_PAGE_11    ((uint32_t)0x08000580) /* Base @ of Page 11, 128 bytes */
#define ADDR_FLASH_PAGE_12    ((uint32_t)0x08000600) /* Base @ of Page 12, 128 bytes */
/* ... */
#define ADDR_FLASH_PAGE_126   ((uint32_t)0x08003F00) /* Base @ of Page 126, 128 bytes */
#define ADDR_FLASH_PAGE_127   ((uint32_t)0x08003F80) /* Base @ of Page 127, 128 bytes */
    
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
