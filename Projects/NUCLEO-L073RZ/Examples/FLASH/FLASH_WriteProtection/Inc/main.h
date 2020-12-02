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
#include "stm32l0xx_nucleo.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Base address of the Flash pages */
/* Base address of the Flash pages */
#define ADDR_FLASH_PAGE_0     ((uint32_t)0x08000000) /* Base @ of Page 0, 128 bytes */
#define ADDR_FLASH_PAGE_1     ((uint32_t)0x08000080) /* Base @ of Page 1, 128 bytes */
#define ADDR_FLASH_PAGE_2     ((uint32_t)0x08000100) /* Base @ of Page 2, 128 bytes */
/* ... */
#define ADDR_FLASH_PAGE_1533  ((uint32_t)0x0802FE80) /* Base @ of Page 1533, 128 bytes */
#define ADDR_FLASH_PAGE_1534  ((uint32_t)0x0802FF00) /* Base @ of Page 1534, 128 bytes */
#define ADDR_FLASH_PAGE_1535  ((uint32_t)0x0802FF80) /* Base @ of Page 1535, 128 bytes */
    
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
