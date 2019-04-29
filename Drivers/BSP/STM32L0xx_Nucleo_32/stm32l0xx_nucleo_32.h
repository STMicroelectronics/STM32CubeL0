/**
  ******************************************************************************
  * @file    stm32l0xx_nucleo_32.h
  * @author  MCD Application Team
  * @brief   This file contains definitions for:
  *          - LEDs and push-button available on STM32L0XX-Nucleo Kit 
  *            from STMicroelectronics
  *          - LCD, joystick and microSD available on Adafruit 1.8" TFT LCD 
  *            shield (reference ID 802)
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright(c) 2016 STMicroelectronics.
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
#ifndef __STM32L0XX_NUCLEO_32_H
#define __STM32L0XX_NUCLEO_32_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"
   

/** @addtogroup BSP
  * @{
  */

/** @addtogroup STM32L0XX_NUCLEO_32 NUCLEO 32
  * @{
  */

/** @defgroup STM32L0XX_NUCLEO_32_Exported_Types Exported Types
  * @{
  */ 
typedef enum 
{
  LED3 = 0,
  LED_GREEN = LED3
} Led_TypeDef;

typedef enum 
{ 
  JOY_NONE  = 0,
  JOY_SEL   = 1,
  JOY_DOWN  = 2,
  JOY_LEFT  = 3,
  JOY_RIGHT = 4,
  JOY_UP    = 5
} JOYState_TypeDef;

/**
  * @}
  */ 

/** @defgroup STM32L0XX_NUCLEO_32_Exported_Constants Exported Constants
  * @{
  */ 

/** 
* @brief	Define for STM32L0XX_NUCLEO_32 board  
  */ 
#if !defined (USE_STM32L0XX_NUCLEO_32)
 #define USE_STM32L0XX_NUCLEO_32
#endif

/** @addtogroup STM32L0XX_NUCLEO_32_LED
  * @{
  */
#define LEDn                               1

#define LED3_PIN                           GPIO_PIN_3
#define LED3_GPIO_PORT                     GPIOB
#define LED3_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOB_CLK_ENABLE()  
#define LED3_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOB_CLK_DISABLE()  

#define LEDx_GPIO_CLK_ENABLE(__INDEX__)    do {LED3_GPIO_CLK_ENABLE(); } while(0)
#define LEDx_GPIO_CLK_DISABLE(__INDEX__)   LED3_GPIO_CLK_DISABLE())
/**
  * @}
  */ 
  


/** @addtogroup STM32L0XX_NUCLEO_32_BUS
  * @{
  */ 
#if defined(HAL_I2C_MODULE_ENABLED)
/*##################### I2C2 ###################################*/
/* User can use this section to tailor I2Cx instance used and associated resources */
/* Definition for I2C1 Pins */
#define BSP_I2C1                        I2C1
#define BSP_I2C1_CLK_ENABLE()           __HAL_RCC_I2C1_CLK_ENABLE()
#define BSP_I2C1_CLK_DISABLE()          __HAL_RCC_I2C1_CLK_DISABLE()
#define BSP_I2C1_FORCE_RESET()          __HAL_RCC_I2C1_FORCE_RESET()
#define BSP_I2C1_RELEASE_RESET()        __HAL_RCC_I2C1_RELEASE_RESET()  

#define BSP_I2C1_SCL_PIN                GPIO_PIN_6    /* PB.6 add wire between D5 and A5 */
#define BSP_I2C1_SDA_PIN                GPIO_PIN_7    /* PB.7 add wire between D4 and A4 */

#define BSP_I2C1_GPIO_PORT              GPIOB      /* GPIOB */
#define BSP_I2C1_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOB_CLK_ENABLE()
#define BSP_I2C1_GPIO_CLK_DISABLE()     __HAL_RCC_GPIOB_CLK_DISABLE() 
#define BSP_I2C1_SCL_SDA_AF             GPIO_AF1_I2C1
  
/* Maximum Timeout values for flags waiting loops. These timeouts are not based
   on accurate values, they just guarantee that the application will not remain
   stuck if the I2C communication is corrupted.
   You may modify these timeout values depending on CPU frequency and application
   conditions (interrupts routines ...). */   
#define BSP_I2C1_TIMEOUT_MAX            1000

/* I2C TIMING is calculated in case of the I2C Clock source is the SYSCLK = 32 MHz */
/* Set TIMING to 0x009080B5 to reach 100 KHz speed (Rise time = 50ns, Fall time = 10ns) */
#define I2C1_TIMING                      0x009080B5

#endif /* HAL_I2C_MODULE_ENABLED */

#if defined(HAL_SPI_MODULE_ENABLED)
/*###################### SPI1 ###################################*/
#define NUCLEO_SPIx                                 SPI1
#define NUCLEO_SPIx_CLK_ENABLE()                  __HAL_RCC_SPI1_CLK_ENABLE()

#define NUCLEO_SPIx_SCK_AF                          GPIO_AF0_SPI1
#define NUCLEO_SPIx_SCK_GPIO_PORT                   GPIOA
#define NUCLEO_SPIx_SCK_PIN                         GPIO_PIN_11
#define NUCLEO_SPIx_SCK_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOA_CLK_ENABLE()
#define NUCLEO_SPIx_SCK_GPIO_CLK_DISABLE()        __HAL_RCC_GPIOA_CLK_DISABLE()

#define NUCLEO_SPIx_MISO_MOSI_AF                    GPIO_AF0_SPI1
#define NUCLEO_SPIx_MISO_MOSI_GPIO_PORT             GPIOB
#define NUCLEO_SPIx_MISO_MOSI_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOB_CLK_ENABLE()
#define NUCLEO_SPIx_MISO_MOSI_GPIO_CLK_DISABLE()  __HAL_RCC_GPIOB_CLK_DISABLE()
#define NUCLEO_SPIx_MISO_PIN                        GPIO_PIN_4
#define NUCLEO_SPIx_MOSI_PIN                        GPIO_PIN_5
/* Maximum Timeout values for flags waiting loops. These timeouts are not based
   on accurate values, they just guarantee that the application will not remain
   stuck if the SPI communication is corrupted.
   You may modify these timeout values depending on CPU frequency and application
   conditions (interrupts routines ...). */   
#define NUCLEO_SPIx_TIMEOUT_MAX                   1000
#endif /* HAL_SPI_MODULE_ENABLED */
/**
  * @}
  */

/** @addtogroup STM32L0XX_NUCLEO_32_COMPONENT
  * @{
  */

/**
  * @brief  SD Control Lines management
  */
#define SD_CS_LOW()       HAL_GPIO_WritePin(SD_CS_GPIO_PORT, SD_CS_PIN, GPIO_PIN_RESET)
#define SD_CS_HIGH()      HAL_GPIO_WritePin(SD_CS_GPIO_PORT, SD_CS_PIN, GPIO_PIN_SET)

/**
  * @brief  LCD Control Lines management
  */
#define LCD_CS_LOW()      HAL_GPIO_WritePin(LCD_CS_GPIO_PORT, LCD_CS_PIN, GPIO_PIN_RESET)
#define LCD_CS_HIGH()     HAL_GPIO_WritePin(LCD_CS_GPIO_PORT, LCD_CS_PIN, GPIO_PIN_SET)
#define LCD_DC_LOW()      HAL_GPIO_WritePin(LCD_DC_GPIO_PORT, LCD_DC_PIN, GPIO_PIN_RESET)
#define LCD_DC_HIGH()     HAL_GPIO_WritePin(LCD_DC_GPIO_PORT, LCD_DC_PIN, GPIO_PIN_SET)
     
/**
  * @brief  SD Control Interface pins
  */
#define SD_CS_PIN                                 GPIO_PIN_5
#define SD_CS_GPIO_PORT                           GPIOB
#define SD_CS_GPIO_CLK_ENABLE()                 __HAL_RCC_GPIOB_CLK_ENABLE()
#define SD_CS_GPIO_CLK_DISABLE()                __HAL_RCC_GPIOB_CLK_DISABLE()

/**
  * @brief  LCD Control Interface pins
  */
#define LCD_CS_PIN                                 GPIO_PIN_6
#define LCD_CS_GPIO_PORT                           GPIOB
#define LCD_CS_GPIO_CLK_ENABLE()                 __HAL_RCC_GPIOB_CLK_ENABLE()
#define LCD_CS_GPIO_CLK_DISABLE()                __HAL_RCC_GPIOB_CLK_DISABLE()
    
/**
  * @brief  LCD Data/Command Interface pins
  */
#define LCD_DC_PIN                                 GPIO_PIN_9
#define LCD_DC_GPIO_PORT                           GPIOA
#define LCD_DC_GPIO_CLK_ENABLE()                 __HAL_RCC_GPIOA_CLK_ENABLE()
#define LCD_DC_GPIO_CLK_DISABLE()                __HAL_RCC_GPIOA_CLK_DISABLE()

#if defined(HAL_ADC_MODULE_ENABLED)
/*##################### ADC1 ###################################*/
/**
  * @brief  ADC Interface pins
  *         used to detect motion of Joystick available on Adafruit 1.8" TFT shield
  */
#define NUCLEO_ADCx                                 ADC1
#define NUCLEO_ADCx_CLK_ENABLE()                  __HAL_RCC_ADC1_CLK_ENABLE()

#define NUCLEO_ADCx_GPIO_PORT                       GPIOB
#define NUCLEO_ADCx_GPIO_PIN                        GPIO_PIN_0
#define NUCLEO_ADCx_GPIO_CLK_ENABLE()             __HAL_RCC_GPIOB_CLK_ENABLE()
#define NUCLEO_ADCx_GPIO_CLK_DISABLE()            __HAL_RCC_GPIOB_CLK_ENABLE()

#endif /* HAL_ADC_MODULE_ENABLED */
/**
  * @}
  */

/** @defgroup STM32L0XX_NUCLEO_32_Exported_Macros Exported Macros
  * @{
  */  
/**
  * @}
  */ 

/** @defgroup STM32L0XX_NUCLEO_32_Internal_Functions Internal Functions
  * @{
  */
#if defined(HAL_I2C_MODULE_ENABLED)
/* I2C1 bus function */
/* Link function for I2C peripherals */
void               I2C1_Init(void);
void               I2C1_Error (void);
void               I2C1_MspInit(I2C_HandleTypeDef *hi2c);  
void               I2C1_Write(uint8_t Addr, uint8_t Reg, uint8_t Value);
uint8_t            I2C1_Read(uint8_t Addr, uint8_t Reg);
HAL_StatusTypeDef  I2C1_WriteBuffer(uint16_t Addr, uint8_t Reg, uint16_t RegSize, uint8_t *pBuffer, uint16_t Length);
HAL_StatusTypeDef  I2C1_ReadBuffer(uint16_t Addr, uint8_t Reg, uint16_t RegSize, uint8_t *pBuffer, uint16_t Length);
HAL_StatusTypeDef  I2C1_IsDeviceReady(uint16_t DevAddress, uint32_t Trials);
#endif /* HAL_I2C_MODULE_ENABLED */
/**
  * @}
  */

/** @defgroup STM32L0XX_NUCLEO_32_Exported_Functions Exported Functions
  * @{
  */
uint32_t         BSP_GetVersion(void);  
void             BSP_LED_Init(Led_TypeDef Led);
void             BSP_LED_On(Led_TypeDef Led);
void             BSP_LED_Off(Led_TypeDef Led);
void             BSP_LED_Toggle(Led_TypeDef Led);                 
#if defined(HAL_ADC_MODULE_ENABLED)
uint8_t          BSP_JOY_Init(void);
JOYState_TypeDef BSP_JOY_GetState(void);
#endif /* HAL_ADC_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */ 

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __STM32L0XX_NUCLEO_32_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

