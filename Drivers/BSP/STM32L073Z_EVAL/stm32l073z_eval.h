/**
  ******************************************************************************
  * @file    stm32l073z_eval.h
  * @author  MCD Application Team
  * @brief   This file contains definitions for STM32L073Z_EVAL's Leds, push-buttons
  *          and COM port hardware resources.
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
#ifndef __STM32L073Z_EVAL_H
#define __STM32L073Z_EVAL_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"
#include "stdlib.h"

/** @addtogroup BSP
  * @{
  */

/** @addtogroup STM32L073Z_EVAL
  * @{
  */

/** @addtogroup STM32L073Z_EVAL_LOW_LEVEL
  * @{
  */

/** @defgroup STM32L073Z_EVAL_LOW_LEVEL_Exported_Types
  * @{
  */

/**
 * @brief LED Types Definition
 */
typedef enum
{
  LED1 = 0,
  LED2 = 1,
  LED3 = 2,
  LED4 = 3,
  /* Color led aliases */
  LED_GREEN  = LED1,
  LED_ORANGE = LED2,
  LED_RED    = LED3,
  LED_BLUE   = LED4
}Led_TypeDef;

/**
 * @brief BUTTON Types Definition
 */
typedef enum 
{
  BUTTON_TAMPER = 0,
  BUTTON_KEY    = BUTTON_TAMPER,
  BUTTON_USER   = BUTTON_TAMPER
}Button_TypeDef;

typedef enum 
{  
  BUTTON_MODE_GPIO = 0,
  BUTTON_MODE_EXTI = 1
}ButtonMode_TypeDef;


typedef enum 
{  
  JOY_MODE_GPIO = 0,
  JOY_MODE_EXTI = 1
}JOYMode_TypeDef;

/**
 * @brief JOYSTICK Types Definition
 */
typedef enum 
{ 
  JOY_NONE  = 0,
  JOY_SEL   = 1,
  JOY_DOWN  = 2,
  JOY_LEFT  = 3,
  JOY_RIGHT = 4,
  JOY_UP    = 5
}JOYState_TypeDef;

/**
 * @brief COM Types Definition
 */
typedef enum 
{
  COM1 = 0
}COM_TypeDef;

/**
  * @}
  */ 

/** @defgroup STM32L073Z_EVAL_LOW_LEVEL_Exported_Constants
  * @{
  */ 

/** 
  * @brief  Define for STM32L073Z_EVAL board  
  */ 
#if !defined (USE_STM32L073Z_EVAL)
 #define USE_STM32L073Z_EVAL
#endif

/** @addtogroup STM32L073Z_EVAL_LOW_LEVEL_LED
  * @{
  */
#define LEDn                             4

#define LED1_PIN                         GPIO_PIN_4
#define LED1_GPIO_PORT                   GPIOE
#define LED1_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOE_CLK_ENABLE()
#define LED1_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOE_CLK_DISABLE()
  
#define LED2_PIN                         GPIO_PIN_5
#define LED2_GPIO_PORT                   GPIOE
#define LED2_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOE_CLK_ENABLE()
#define LED2_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOE_CLK_DISABLE()
  
#define LED3_PIN                         GPIO_PIN_1
#define LED3_GPIO_PORT                   GPIOD
#define LED3_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOD_CLK_ENABLE()
#define LED3_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOD_CLK_DISABLE()
  
#define LED4_PIN                         GPIO_PIN_7
#define LED4_GPIO_PORT                   GPIOE
#define LED4_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOE_CLK_ENABLE()
#define LED4_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOE_CLK_DISABLE()

#define LEDx_GPIO_CLK_ENABLE(__LED__)    do { if ((__LED__) == LED1) LED1_GPIO_CLK_ENABLE(); else \
                                              if ((__LED__) == LED2) LED2_GPIO_CLK_ENABLE(); else \
                                              if ((__LED__) == LED3) LED3_GPIO_CLK_ENABLE(); else \
                                              if ((__LED__) == LED4) LED4_GPIO_CLK_ENABLE();} while(0)

#define LEDx_GPIO_CLK_DISABLE(__LED__)   (((__LED__) == LED1) ? LED1_GPIO_CLK_DISABLE() :\
                                          ((__LED__) == LED2) ? LED2_GPIO_CLK_DISABLE() :\
                                          ((__LED__) == LED3) ? LED3_GPIO_CLK_DISABLE() :\
                                          ((__LED__) == LED4) ? LED4_GPIO_CLK_DISABLE() : 0 )

/**
  * @}
  */ 

/** @addtogroup STM32446E_EVAL_LOW_LEVEL_BUTTON
  * @{
  */ 
/* Joystick pins are connected to IO Expander (accessible through I2C1 interface) */ 
#define BUTTONn                          3 

/**
 * @brief Tamper push-button
 */
#define TAMPER_BUTTON_PIN                GPIO_PIN_13
#define TAMPER_BUTTON_GPIO_PORT          GPIOC
#define TAMPER_BUTTON_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOC_CLK_ENABLE()
#define TAMPER_BUTTON_GPIO_CLK_DISABLE() __HAL_RCC_GPIOC_CLK_DISABLE()
#define TAMPER_BUTTON_EXTI_IRQn          EXTI4_15_IRQn

#define TAMPERx_GPIO_CLK_ENABLE(__BUTTON__)    do { if(__BUTTON__ == BUTTON_TAMPER ) TAMPER_BUTTON_GPIO_CLK_ENABLE(); } while (0)

#define TAMPERx_GPIO_CLK_DISABLE(__BUTTON__)   (((__BUTTON__) == BUTTON_TAMPER) ? TAMPER_BUTTON_GPIO_CLK_DISABLE(): 0 )

/**
  * @brief Joystick Pins definition 
  */ 
#define JOY_SEL_PIN                    IO_PIN_0
#define JOY_DOWN_PIN                   IO_PIN_1
#define JOY_LEFT_PIN                   IO_PIN_2
#define JOY_RIGHT_PIN                  IO_PIN_3
#define JOY_UP_PIN                     IO_PIN_4
#define JOY_NONE_PIN                   JOY_ALL_PINS
#define JOY_ALL_PINS                   (IO_PIN_0 | IO_PIN_1 | IO_PIN_2 | IO_PIN_3 | IO_PIN_4)

/**
 * @brief MFFX IRQ OUT Pin
 */
#define MFX_IRQOUT_PIN            GPIO_PIN_6 
#define MFX_IRQOUT_PORT           GPIOE
#define MFX_IRQOUT_CLK_ENABLE()   __HAL_RCC_GPIOE_CLK_ENABLE()
#define MFX_IRQOUT_CLK_DISABLE()  __HAL_RCC_GPIOE_CLK_DISABLE()
#define MFX_IRQOUT_EXTI_IRQn      EXTI4_15_IRQn


/**
  * @brief MFX Irq Out Pin
  */
#define MFX_IRQ_OUT_PIN                WAKEUP_BUTTON_PIN


#define SD_DETECT_PIN                    IO_PIN_5

/* Exported constant IO ------------------------------------------------------*/

/* Ilario: normally with MFX, it should be the same  address for IO and TS. 
   To be verifies.
   The MFX_I2C_ADDR input pin selects the MFX I2C device address 
        MFX_I2C_ADDR input pin     MFX I2C device address
            0                           b: 1000 010x    (0x84)
            1                           b: 1000 011x    (0x86)
   This input is sampled during the MFX firmware startup.  */

#define IO_I2C_ADDRESS                   0x84  /*mfx MFX_I2C_ADDR 0*/
#define IO_I2C_ADDRESS_2                 0x86  /*mfx MFX_I2C_ADDR 1*/
#define TS_I2C_ADDRESS                   0x84  /*mfx MFX_I2C_ADDR 0*/
#define TS_I2C_ADDRESS_2                 0x86  /*mfx MFX_I2C_ADDR 1*/

/* Define used to measure the current */
#define IDD_I2C_ADDRESS                         ((uint16_t) 0x84)

/** @addtogroup STM32L073Z_EVAL_LOW_LEVEL_COM
  * @{
  */
#define COMn                            1

/**
 * @brief Definition for COM port1, connected to USART2
 */ 
#define EVAL_COM1                       USART2
#define EVAL_COM1_CLK_ENABLE()          __HAL_RCC_USART2_CLK_ENABLE()
#define EVAL_COM1_CLK_DISABLE()         __HAL_RCC_USART2_CLK_DISABLE()

#define EVAL_COM1_TX_PIN                GPIO_PIN_5
#define EVAL_COM1_TX_GPIO_PORT          GPIOD
#define EVAL_COM1_TX_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOD_CLK_ENABLE()
#define EVAL_COM1_TX_GPIO_CLK_DISABLE() __HAL_RCC_GPIOD_CLK_DISABLE()
#define EVAL_COM1_TX_AF                 GPIO_AF0_USART2

#define EVAL_COM1_RX_PIN                GPIO_PIN_6
#define EVAL_COM1_RX_GPIO_PORT          GPIOD
#define EVAL_COM1_RX_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOD_CLK_ENABLE()
#define EVAL_COM1_RX_GPIO_CLK_DISABLE() __HAL_RCC_GPIOD_CLK_DISABLE()
#define EVAL_COM1_RX_AF                 GPIO_AF0_USART2

#define EVAL_COM1_CTS_PIN               GPIO_PIN_3
#define EVAL_COM1_CTS_GPIO_PORT         GPIOD
#define EVAL_COM1_CTS_GPIO_CLK_ENABLE() __HAL_RCC_GPIOD_CLK_ENABLE()
#define EVAL_COM1_CTS_GPIO_CLK_DISABLE() __HAL_RCC_GPIOD_CLK_DISABLE()
#define EVAL_COM1_CTS_AF                GPIO_AF0_USART2

#define EVAL_COM1_RTS_PIN               GPIO_PIN_4
#define EVAL_COM1_RTS_GPIO_PORT         GPIOD
#define EVAL_COM1_RTS_GPIO_CLK_ENABLE() __HAL_RCC_GPIOD_CLK_ENABLE()
#define EVAL_COM1_RTS_GPIO_CLK_DISABLE() __HAL_RCC_GPIOD_CLK_DISABLE()
#define EVAL_COM1_RTS_AF                GPIO_AF0_USART2
   
#define EVAL_COM1_IRQn                  USART2_IRQn

#define COMx_CLK_ENABLE(__COM__)        do {if (__COM__ == COM1) EVAL_COM1_CLK_ENABLE(); } while (0)
#define COMx_CLK_DISABLE(__COM__)       (((__COM__) == COM1) ? EVAL_COM1_CLK_DISABLE() : 0)

#define COMx_TX_GPIO_CLK_ENABLE(__COM__) do { if(__COM__ == COM1) EVAL_COM1_TX_GPIO_CLK_ENABLE(); } while (0)
#define COMx_TX_GPIO_CLK_DISABLE(__COM__) (((__COM__) == COM1) ? EVAL_COM1_TX_GPIO_CLK_DISABLE() : 0)

#define COMx_RX_GPIO_CLK_ENABLE(__COM__) do { if(__COM__ == COM1) EVAL_COM1_RX_GPIO_CLK_ENABLE(); } while (0)
#define COMx_RX_GPIO_CLK_DISABLE(__COM__) (((__COM__) == COM1) ? EVAL_COM1_RX_GPIO_CLK_DISABLE() : 0)

#define COMx_CTS_GPIO_CLK_ENABLE(__COM__)cdo { if(__COM__ == COM1) EVAL_COM1_CTS_GPIO_CLK_ENABLE();}
#define COMx_CTS_GPIO_CLK_DISABLE(__COM__) (((__COM__) == COM1) ? EVAL_COM1_CTS_GPIO_CLK_DISABLE() : 0) while (0)

// #define COMx_RTS_GPIO_CLK_ENABLE(__COM__) (((__COM__) == COM1) ? EVAL_COM1_RTS_GPIO_CLK_ENABLE() : 0)
#define COMx_RTS_GPIO_CLK_ENABLE(__COM__)  do { if(__COM__ == COM1) EVAL_COM1_RTS_GPIO_CLK_ENABLE(); } while (0)
#define COMx_RTS_GPIO_CLK_DISABLE(__COM__) (((__COM__) == COM1) ? EVAL_COM1_RTS_GPIO_CLK_DISABLE() : 0)
/**
  * @}
  */

/** @addtogroup STM32L073Z_EVAL_LOW_LEVEL_BUS
  * @{
  */
#if defined(HAL_I2C_MODULE_ENABLED)
/*##################### I2C2 ###################################*/
/* User can use this section to tailor I2Cx instance used and associated resources */
/* Definition for I2C1 Pins */
#define EVAL_I2C1                        I2C1
#define EVAL_I2C1_CLK_ENABLE()           __HAL_RCC_I2C1_CLK_ENABLE()
#define EVAL_I2C1_CLK_DISABLE()          __HAL_RCC_I2C1_CLK_DISABLE()
#define EVAL_I2C1_FORCE_RESET()          __HAL_RCC_I2C1_FORCE_RESET()
#define EVAL_I2C1_RELEASE_RESET()        __HAL_RCC_I2C1_RELEASE_RESET()  

#define EVAL_I2C1_SCL_PIN                GPIO_PIN_6    /* PB.6 */
#define EVAL_I2C1_SDA_PIN                GPIO_PIN_7    /* PB.7 */

#define EVAL_I2C1_GPIO_PORT              GPIOB      /* GPIOB */
#define EVAL_I2C1_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOB_CLK_ENABLE()
#define EVAL_I2C1_GPIO_CLK_DISABLE()     __HAL_RCC_GPIOB_CLK_DISABLE() 
#define EVAL_I2C1_SCL_SDA_AF             GPIO_AF1_I2C1
  
/* Maximum Timeout values for flags waiting loops. These timeouts are not based
   on accurate values, they just guarantee that the application will not remain
   stuck if the I2C communication is corrupted.
   You may modify these timeout values depending on CPU frequency and application
   conditions (interrupts routines ...). */   
#define EVAL_I2C1_TIMEOUT_MAX            1000

/* I2C TIMING is calculated in case of the I2C Clock source is the SYSCLK = 32 MHz */
/* Set TIMING to 0x009080B5 to reach 100 KHz speed (Rise time = 50ns, Fall time = 10ns) */
#define I2C1_TIMING                      0x009080B5

#endif /* HAL_I2C_MODULE_ENABLED */

#if defined(HAL_SPI_MODULE_ENABLED)
/**
  * @brief  Definition for SPI Interface pins (SPI1 used)
  */
#define EVAL_SPIx                             SPI1
#define EVAL_SPIx_CLK_ENABLE()                __HAL_RCC_SPI1_CLK_ENABLE()
#define EVAL_SPIx_CLK_DISABLE()               __HAL_RCC_SPI1_CLK_DISABLE()
#define EVAL_SPIx_FORCE_RESET()               __HAL_RCC_SPI1_FORCE_RESET()
#define EVAL_SPIx_RELEASE_RESET()             __HAL_RCC_SPI1_RELEASE_RESET()
                                              
#define EVAL_SPIx_SCK_PIN                     GPIO_PIN_13    /* PE.13 */
#define EVAL_SPIx_SCK_GPIO_PORT               GPIOE          /* GPIOE */
#define EVAL_SPIx_SCK_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOE_CLK_ENABLE()
#define EVAL_SPIx_SCK_GPIO_CLK_DISABLE()      __HAL_RCC_GPIOE_CLK_DISABLE()
#define EVAL_SPIx_SCK_AF                      GPIO_AF2_SPI1
                                              
#define EVAL_SPIx_MISO_PIN                    GPIO_PIN_14    /* PE.14 */
#define EVAL_SPIx_MISO_GPIO_PORT              GPIOE          /* GPIOE */
#define EVAL_SPIx_MISO_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOE_CLK_ENABLE()
#define EVAL_SPIx_MISO_GPIO_CLK_DISABLE()      __HAL_RCC_GPIOE_CLK_DISABLE()
#define EVAL_SPIx_MISO_AF                     GPIO_AF2_SPI1

#define EVAL_SPIx_MOSI_PIN                    GPIO_PIN_15    /* PE.15 */
#define EVAL_SPIx_MOSI_GPIO_PORT              GPIOE          /* GPIOE */
#define EVAL_SPIx_MOSI_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOE_CLK_ENABLE()
#define EVAL_SPIx_MOSI_GPIO_CLK_DISABLE()     __HAL_RCC_GPIOE_CLK_DISABLE()
#define EVAL_SPIx_MOSI_AF                     GPIO_AF2_SPI1

#define EVAL_SPIx_MOSI_DIR_PIN                GPIO_PIN_9     /* PH.09 */
#define EVAL_SPIx_MOSI_DIR_GPIO_PORT          GPIOH          /* GPIO H */
#define EVAL_SPIx_MOSI_DIR_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOH_CLK_ENABLE()
#define EVAL_SPIx_MOSI_DIR_GPIO_CLK_DISABLE() __HAL_RCC_GPIOH_CLK_DISABLE()

/* Maximum Timeout values for flags waiting loops. These timeouts are not based
   on accurate values, they just guarantee that the application will not remain
   stuck if the SPI communication is corrupted.
   You may modify these timeout values depending on CPU frequency and application
   conditions (interrupts routines ...). */   
#define EVAL_SPIx_TIMEOUT_MAX                 1000

#endif /* HAL_SPI_MODULE_ENABLED */
/**
  * @}
  */

/** @addtogroup STM32303C_EVAL_LOW_LEVEL_COMPONENT
  * @{
  */
/*##################### LCD ###################################*/
/**
  * @brief  LCD Control pins 
  */ 
#define LCD_NCS_PIN                     GPIO_PIN_10 /* PD. 10 */
#define LCD_NCS_GPIO_PORT               GPIOE       /* GPIOE */
#define LCD_NCS_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOE_CLK_ENABLE()
#define LCD_NCS_GPIO_CLK_DISABLE()      __HAL_RCC_GPIOE_CLK_DISABLE()  

/* Chip Select macro definition */
#define LCD_CS_LOW()                    HAL_GPIO_WritePin(LCD_NCS_GPIO_PORT, LCD_NCS_PIN, GPIO_PIN_RESET)
#define LCD_CS_HIGH()                   HAL_GPIO_WritePin(LCD_NCS_GPIO_PORT, LCD_NCS_PIN, GPIO_PIN_SET)


/*##################### Idd ##########################*/
/**
  * @brief  Idd current measurement interface pins
  */
#define IDD_INT_GPIO_PORT                       GPIOC                       /* GPIOC */
#define IDD_INT_GPIO_CLK_ENABLE()               __HAL_RCC_GPIOC_CLK_ENABLE()
#define IDD_INT_GPIO_CLK_DISABLE()              __HAL_RCC_GPIOC_CLK_DISABLE()
#define IDD_INT_PIN                             GPIO_PIN_13                  /* PC.13 */
#define IDD_INT_EXTI_IRQn                       EXTI15_10_IRQn

#define IDD_WAKEUP_GPIO_PORT                    GPIOA                       /* GPIOA */
#define IDD_WAKEUP_GPIO_CLK_ENABLE()            __HAL_RCC_GPIOA_CLK_ENABLE()
#define IDD_WAKEUP_GPIO_CLK_DISABLE()           __HAL_RCC_GPIOA_CLK_DISABLE()
#define IDD_WAKEUP_PIN                          GPIO_PIN_4                  /* PA.04 */

/** 
  ##################### SD ###################################*/  
/**
  * @brief SD card Control pin  
  */
#define SD_CS_PIN                       GPIO_PIN_0              /* PD.00 */
#define SD_CS_GPIO_PORT                 GPIOD                   /* GPIOD */
#define SD_CS_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOD_CLK_ENABLE()
#define SD_CS_GPIO_CLK_DISABLE()        __HAL_RCC_GPIOD_CLK_DISABLE()

/* Chip Select macro definition */
#define SD_CS_LOW()                     HAL_GPIO_WritePin(SD_CS_GPIO_PORT, SD_CS_PIN, GPIO_PIN_RESET)
#define SD_CS_HIGH()                    HAL_GPIO_WritePin(SD_CS_GPIO_PORT, SD_CS_PIN, GPIO_PIN_SET)  

/**
  * @}
  */

/** @defgroup STM32L073Z_EVAL_LOW_LEVEL_Exported_Functions
  * @{
  */
uint32_t          BSP_GetVersion(void);
void              BSP_LED_Init(Led_TypeDef Led);
void              BSP_LED_On(Led_TypeDef Led);
void              BSP_LED_Off(Led_TypeDef Led);
void              BSP_LED_Toggle(Led_TypeDef Led);
void              BSP_PB_Init(Button_TypeDef Button, ButtonMode_TypeDef Button_Mode);
uint32_t          BSP_PB_GetState(Button_TypeDef Button);
uint8_t           BSP_JOY_Init(JOYMode_TypeDef Joy_Mode);
JOYState_TypeDef  BSP_JOY_GetState(void);
#if defined(HAL_UART_MODULE_ENABLED)
void              BSP_COM_Init(COM_TypeDef COM, UART_HandleTypeDef* huart);
#endif /* HAL_UART_MODULE_ENABLED */

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

#endif /* __STM32L073Z_EVAL_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
