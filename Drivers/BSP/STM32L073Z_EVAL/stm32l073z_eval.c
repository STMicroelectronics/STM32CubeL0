  /******************************************************************************
  * @file    stm32l073z_eval.c
  * @author  MCD Application Team
  * @brief   This file provides: a set of firmware functions to manage Leds,
  *          push-button and COM ports
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

/* Includes ------------------------------------------------------------------*/
#include "stm32l073z_eval.h"
#include "stm32l073z_eval_io.h"

/** @addtogroup BSP
  * @{
  */

/** @addtogroup STM32L073Z_EVAL
  * @{
  */

/** @defgroup STM32L073Z_EVAL_LOW_LEVEL 
  * @brief This file provides firmware functions to manage Leds, push-buttons, 
  *        COM ports, SD card on SPI and temperature sensor (LM75) available on 
  *        STM32L073Z-EVAL evaluation board from STMicroelectronics.
  * @{
  */ 

/** @defgroup STM32L073Z_EVAL_LOW_LEVEL_Private_TypesDefinitions
  * @{
  */ 
/**
  * @}
  */ 


/** @defgroup STM32L073Z_EVAL_LOW_LEVEL_Private_Defines
  * @{
  */ 
/* LINK LCD */
#define START_BYTE         0x70
#define SET_INDEX          0x00
#define READ_STATUS        0x01
#define LCD_WRITE_REG      0x02
#define LCD_READ_REG       0x03

/* LINK SD Card */
#define SD_DUMMY_BYTE            0xFF
#define SD_NO_RESPONSE_EXPECTED  0x80

/**
  * @brief STM32L073Z EVAL BSP Driver version number
  */
#define __STM32L073Z_EVAL_BSP_VERSION_MAIN   (0x02) /*!< [31:24] main version */
#define __STM32L073Z_EVAL_BSP_VERSION_SUB1   (0x00) /*!< [23:16] sub1 version */
#define __STM32L073Z_EVAL_BSP_VERSION_SUB2   (0x04) /*!< [15:8]  sub2 version */
#define __STM32L073Z_EVAL_BSP_VERSION_RC     (0x00) /*!< [7:0]  release candidate */ 
#define __STM32L073Z_EVAL_BSP_VERSION         ((__STM32L073Z_EVAL_BSP_VERSION_MAIN << 24)\
                                             |(__STM32L073Z_EVAL_BSP_VERSION_SUB1 << 16)\
                                             |(__STM32L073Z_EVAL_BSP_VERSION_SUB2 << 8 )\
                                             |(__STM32L073Z_EVAL_BSP_VERSION_RC))
/**
  * @}
  */ 


/** @defgroup STM32L073Z_EVAL_LOW_LEVEL_Private_Macros
  * @{
  */ 
/**
  * @}
  */


/** @defgroup STM32L073Z_EVAL_LOW_LEVEL_Private_Variables
  * @{
  */
/**
  * @brief LED variables
  */
GPIO_TypeDef* LED_PORT[LEDn] = {LED1_GPIO_PORT,
                                LED2_GPIO_PORT,
                                LED3_GPIO_PORT,
                                LED4_GPIO_PORT};

const uint16_t LED_PIN[LEDn] = {LED1_PIN,
                                LED2_PIN,
                                LED3_PIN,
                                LED4_PIN};
/**
  * @brief BUTTON variables
  */
GPIO_TypeDef* BUTTON_PORT[BUTTONn] = {TAMPER_BUTTON_GPIO_PORT};
const uint16_t BUTTON_PIN[BUTTONn] = {TAMPER_BUTTON_PIN};
const uint8_t BUTTON_IRQn[BUTTONn] = {TAMPER_BUTTON_EXTI_IRQn};


/**
  * @brief COM variables
  */
#ifdef HAL_UART_MODULE_ENABLED
USART_TypeDef* COM_USART[COMn]  = {EVAL_COM1}; 

GPIO_TypeDef* COM_TX_PORT[COMn] = {EVAL_COM1_TX_GPIO_PORT};
 
GPIO_TypeDef* COM_RX_PORT[COMn] = {EVAL_COM1_RX_GPIO_PORT};

const uint16_t COM_TX_PIN[COMn] = {EVAL_COM1_TX_PIN};

const uint16_t COM_RX_PIN[COMn] = {EVAL_COM1_RX_PIN};

const uint16_t COM_TX_AF[COMn]  = {EVAL_COM1_TX_AF};

const uint16_t COM_RX_AF[COMn]  = {EVAL_COM1_RX_AF};

#endif /*HAL_UART_MODULE_ENABLED*/

/**
 * @brief BUS variables
 */
#if defined(HAL_I2C_MODULE_ENABLED)
uint32_t I2c1Timeout = EVAL_I2C1_TIMEOUT_MAX;    /*<! Value of Timeout when I2C1 communication fails */
I2C_HandleTypeDef heval_I2c1;
#endif /* HAL_I2C_MODULE_ENABLED */

#if defined(HAL_SPI_MODULE_ENABLED)
uint32_t SpixTimeout = EVAL_SPIx_TIMEOUT_MAX;    /*<! Value of Timeout when SPI communication fails */
static SPI_HandleTypeDef heval_Spi;
#endif /* HAL_SPI_MODULE_ENABLED */

/**
  * @}
  */ 


/** @defgroup STM32L073Z_EVAL_LOW_LEVEL_Private_FunctionPrototypes
  * @{
  */
#if defined(HAL_I2C_MODULE_ENABLED)
/* I2C1 bus function */
/* Link function for I2C EEPROM, TSENSOR & HDMI_SOURCE peripherals */
static void               I2C1_Init(void);
static void               I2C1_DeInit(void);
static void               I2C1_Error (void);
static void               I2C1_MspInit(I2C_HandleTypeDef *hi2c);
static void               I2C1_MspDeInit(I2C_HandleTypeDef *hi2c);
static void               I2C1_Write(uint8_t Addr, uint8_t Reg, uint8_t Value);
static uint8_t            I2C1_Read(uint8_t Addr, uint8_t Reg);
static HAL_StatusTypeDef  I2C1_WriteBuffer(uint16_t Addr, uint8_t Reg, uint16_t RegSize, uint8_t *pBuffer, uint16_t Length);
static HAL_StatusTypeDef  I2C1_ReadBuffer(uint16_t Addr, uint8_t Reg, uint16_t RegSize, uint8_t *pBuffer, uint16_t Length);
static HAL_StatusTypeDef  I2C1_IsDeviceReady(uint16_t DevAddress, uint32_t Trials);

/* Link functions for EEPROM peripheral */
void                     EEPROM_IO_Init(void);
HAL_StatusTypeDef        EEPROM_IO_WriteData(uint16_t DevAddress, uint16_t MemAddress, uint8_t* pBuffer, uint32_t BufferSize);
HAL_StatusTypeDef        EEPROM_IO_ReadData(uint16_t DevAddress, uint16_t MemAddress, uint8_t* pBuffer, uint32_t BufferSize);
HAL_StatusTypeDef        EEPROM_IO_IsDeviceReady(uint16_t DevAddress, uint32_t Trials);

/* Link functions for Temperature Sensor peripheral */
void                     TSENSOR_IO_Init(void);
void                     TSENSOR_IO_Write(uint16_t DevAddress, uint8_t* pBuffer, uint8_t WriteAddr, uint16_t Length);
void                     TSENSOR_IO_Read(uint16_t DevAddress, uint8_t* pBuffer, uint8_t ReadAddr, uint16_t Length);
uint16_t                 TSENSOR_IO_IsDeviceReady(uint16_t DevAddress, uint32_t Trials);

/* IOExpander IO functions */
void                      MFX_IO_Init(void);
void                      MFX_IO_DeInit(void);
void                      MFX_IO_ITConfig(void);
void                      MFX_IO_EnableWakeupPin(void);
void                      MFX_IO_Wakeup(void);
void                      MFX_IO_Delay(uint32_t Delay);
void                      MFX_IO_Write(uint16_t Addr, uint8_t Reg, uint8_t Value);
uint8_t                   MFX_IO_Read(uint16_t Addr, uint8_t Reg);
uint16_t                  MFX_IO_ReadMultiple(uint16_t Addr, uint8_t Reg, uint8_t *Buffer, uint16_t Length);
/*void            MFX_IO_WriteMultiple(uint8_t Addr, uint8_t Reg, uint8_t *Buffer, uint16_t Length);*/
#endif /* HAL_I2C_MODULE_ENABLED */



#if defined(HAL_SPI_MODULE_ENABLED)
/* SPIx bus function */
static void              SPIx_Init(void);
static void              SPIx_Write(uint8_t Value);
static uint32_t          SPIx_Read(void);
static void              SPIx_Error (void);
static void              SPIx_MspInit(SPI_HandleTypeDef *hspi);
#if defined(HAL_I2C_MODULE_ENABLED)
static void              SPIx_WriteReadData(const uint8_t *DataIn, uint8_t *DataOut, uint16_t DataLegnth);
#endif /* HAL_I2C_MODULE_ENABLED */

/* Link functions for LCD peripheral */
void                     LCD_IO_Init(void);
void                     LCD_IO_WriteMultipleData(uint8_t *pData, uint32_t Size);
void                     LCD_IO_WriteReg(uint8_t Reg);
uint16_t                 LCD_IO_ReadData(uint16_t RegValue);
void                     LCD_Delay(uint32_t delay);

/* Link functions for SD Card peripheral */
void                     SD_IO_Init(void); 
void                     SD_IO_CSState(uint8_t state);
void                     SD_IO_WriteReadData(const uint8_t *DataIn, uint8_t *DataOut, uint16_t DataLength);
uint8_t                  SD_IO_WriteByte(uint8_t Data);
#endif /* HAL_SPI_MODULE_ENABLED */

/**
  * @}
  */ 

/** @defgroup STM32L073Z_EVAL_LOW_LEVEL_Private_Functions
  * @{
  */ 

/**
  * @brief  This method returns the STM32F072B EVAL BSP Driver revision
  * @param  None
  * @retval version : 0xXYZR (8bits for each decimal, R for RC)
  */
uint32_t BSP_GetVersion(void)
{
  return __STM32L073Z_EVAL_BSP_VERSION;
}

/*******************************************************************************
                            GPIO OPERATIONS
*******************************************************************************/
#if defined(HAL_GPIO_MODULE_ENABLED)
/**
  * @brief  Configures LED GPIO.
  * @param  Led: Specifies the Led to be configured. 
  *   This parameter can be one of following parameters:
  *     @arg LED1
  *     @arg LED2
  *     @arg LED3
  *     @arg LED4
  * @retval None
  */
void BSP_LED_Init(Led_TypeDef Led)
{
  GPIO_InitTypeDef  GPIO_InitStruct;
  
  /* Enable the GPIO_LED clock */
  LEDx_GPIO_CLK_ENABLE(Led);

  /* Configure the GPIO_LED pin */
  GPIO_InitStruct.Pin = LED_PIN[Led];
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  
  HAL_GPIO_Init(LED_PORT[Led], &GPIO_InitStruct);
  
  HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_SET);
}

/**
  * @brief  Turns selected LED On.
  * @param  Led: Specifies the Led to be set on. 
  *   This parameter can be one of following parameters:
  *     @arg LED1
  *     @arg LED2
  *     @arg LED3
  *     @arg LED4  
  * @retval None
  */
void BSP_LED_On(Led_TypeDef Led)
{
  HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_RESET);
}

/**
  * @brief  Turns selected LED Off.
  * @param  Led: Specifies the Led to be set off. 
  *   This parameter can be one of following parameters:
  *     @arg LED1
  *     @arg LED2
  *     @arg LED3
  *     @arg LED4 
  * @retval None
  */
void BSP_LED_Off(Led_TypeDef Led)
{
  HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_SET);
}

/**
  * @brief  Toggles the selected LED.
  * @param  Led: Specifies the Led to be toggled. 
  *   This parameter can be one of following parameters:
  *     @arg LED1
  *     @arg LED2
  *     @arg LED3
  *     @arg LED4  
  * @retval None
  */
void BSP_LED_Toggle(Led_TypeDef Led)
{
  HAL_GPIO_TogglePin(LED_PORT[Led], LED_PIN[Led]);
}

/**
  * @brief  Configures Tamper Button GPIO or EXTI Line.
  * @param  Button: Button to be configured
  *   This parameter can be one of the following values:
  *     @arg BUTTON_TAMPER: Tamper Push Button 
  * @param  Mode: Button mode
  *   This parameter can be one of the following values:
  *     @arg BUTTON_MODE_GPIO: Button will be used as simple IO 
  *     @arg BUTTON_MODE_EXTI: Button will be connected to EXTI line
  *                            with interrupt generation capability
  * @retval None
  */
void BSP_PB_Init(Button_TypeDef Button, ButtonMode_TypeDef Mode)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  /* Enable the Tamper Clock */
  TAMPERx_GPIO_CLK_ENABLE(Button);

  GPIO_InitStruct.Pin = BUTTON_PIN[Button];
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

  if (Mode == BUTTON_MODE_GPIO)
  {
    /* Configure Button pin as input */
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;

    HAL_GPIO_Init(BUTTON_PORT[Button], &GPIO_InitStruct);
  }

  if (Mode == BUTTON_MODE_EXTI)
  {
    /* Configure Button pin as input with External interrupt */
    GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
    HAL_GPIO_Init(BUTTON_PORT[Button], &GPIO_InitStruct);

    /* Enable and set Button EXTI Interrupt to the lowest priority */
    HAL_NVIC_SetPriority((IRQn_Type)(BUTTON_IRQn[Button]), 0x03, 0x00);
    HAL_NVIC_EnableIRQ((IRQn_Type)(BUTTON_IRQn[Button]));
  }
}

/**
  * @brief  Returns the selected button state.
  * @param  Button: Button to be checked.
  *   This parameter can be one of the following values:
  *     @arg BUTTON_TAMPER: Tamper Push Button
  * @retval The Button GPIO pin value
  */
uint32_t BSP_PB_GetState(Button_TypeDef Button)
{
  return HAL_GPIO_ReadPin(BUTTON_PORT[Button], BUTTON_PIN[Button]);
}

#endif //HAL_GPIO_MODULE_ENABLED

/*******************************************************************************
                            JOYSTICK OPERATIONS
   Note : The joystick uses I2C interface (through MFX)
*******************************************************************************/
#if defined(HAL_I2C_MODULE_ENABLED)
/**
  * @brief  Configures joystick GPIO and EXTI modes.
  * @param  Joy_Mode: Button mode.
  *          This parameter can be one of the following values:
  *            @arg  JOY_MODE_GPIO: Joystick pins will be used as simple IOs
  *            @arg  JOY_MODE_EXTI: Joystick pins will be connected to EXTI line 
  *                                 with interrupt generation capability  
  * @retval IO_OK: if all initializations are OK. Other value if error.
  */
uint8_t BSP_JOY_Init(JOYMode_TypeDef Joy_Mode)
{
  uint8_t ret = 0;
     
  /* Initialize the IO functionalities */
  ret = BSP_IO_Init();
  
  if (ret == IO_OK)
  {
    /* Configure joystick pins in IT mode */
    if(Joy_Mode == JOY_MODE_EXTI)
    {
      /* MFX pins init for Joystick */
      /* Configure IO interrupt acquisition mode */
      BSP_IO_ConfigPin(JOY_ALL_PINS, IO_MODE_IT_LOW_LEVEL_PU);
    }
    else
    {
      BSP_IO_ConfigPin(JOY_ALL_PINS, IO_MODE_INPUT_PU);
    }
  }
  
  return ret; 
}

/**
  * @brief  Returns the current joystick status.
  * @param  None
  * @retval Code of the joystick key pressed
  *          This code can be one of the following values:
  *            @arg  JOY_NONE
  *            @arg  JOY_SEL
  *            @arg  JOY_DOWN
  *            @arg  JOY_LEFT
  *            @arg  JOY_RIGHT
  *            @arg  JOY_UP
  */
JOYState_TypeDef BSP_JOY_GetState(void)
{
  uint16_t tmp = 0;   
  
  /* Read the status joystick pins */
  tmp = BSP_IO_ReadPin(JOY_ALL_PINS);
   
  /* Check the pressed keys */  
  if((tmp & JOY_NONE_PIN) == JOY_NONE)
  {
    return(JOYState_TypeDef) JOY_NONE;
  }
  else if(!(tmp & JOY_SEL_PIN))
  {
    return(JOYState_TypeDef) JOY_SEL;
  }
  else if(!(tmp & JOY_DOWN_PIN))
  {
    return(JOYState_TypeDef) JOY_DOWN;
  } 
  else if(!(tmp & JOY_LEFT_PIN))
  {
    return(JOYState_TypeDef) JOY_LEFT;
  }
  else if(!(tmp & JOY_RIGHT_PIN))
  {
    return(JOYState_TypeDef) JOY_RIGHT;
  }
  else if(!(tmp & JOY_UP_PIN))
  {
    return(JOYState_TypeDef) JOY_UP;
  }
  else
  { 
    return(JOYState_TypeDef) JOY_NONE;
  }  
}
#endif //HAL_I2C_MODULE_ENABLED

/*******************************************************************************
                            UART OPERATIONS
*******************************************************************************/
#if defined(HAL_UART_MODULE_ENABLED)
/**
  * @brief  Configures COM port.
  * @param  COM: Specifies the COM port to be configured.
  *   This parameter can be one of following parameters:    
  *     @arg COM1  
  * @param  huart: pointer to a UART_HandleTypeDef structure that
  *   contains the configuration information for the specified UART peripheral.
  * @retval None
  */
void BSP_COM_Init(COM_TypeDef COM, UART_HandleTypeDef* huart)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  /* Enable GPIO clock */
  COMx_TX_GPIO_CLK_ENABLE(COM);
  COMx_RX_GPIO_CLK_ENABLE(COM);

  /* Enable USART clock */
  COMx_CLK_ENABLE(COM);

  /* Configure USART Tx as alternate function push-pull */
  GPIO_InitStruct.Pin = COM_TX_PIN[COM];
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Alternate = COM_TX_AF[COM];
  HAL_GPIO_Init(COM_TX_PORT[COM], &GPIO_InitStruct);
    
  /* Configure USART Rx as alternate function push-pull */
  GPIO_InitStruct.Pin = COM_RX_PIN[COM];
  GPIO_InitStruct.Alternate = COM_RX_AF[COM];
  HAL_GPIO_Init(COM_RX_PORT[COM], &GPIO_InitStruct);

  /* USART configuration */
  huart->Instance = COM_USART[COM];
  HAL_UART_Init(huart);
}
#endif /* HAL_UART_MODULE_ENABLED */

/*******************************************************************************
                            BUS OPERATIONS
*******************************************************************************/
#if defined(HAL_I2C_MODULE_ENABLED)
/******************************* I2C Routines *********************************/

/**
  * @brief I2C Bus initialization
  * @param None
  * @retval None
  */
static void I2C1_Init(void)
{
  if(HAL_I2C_GetState(&heval_I2c1) == HAL_I2C_STATE_RESET)
  {
    heval_I2c1.Instance              = EVAL_I2C1;
    heval_I2c1.Init.Timing           = I2C1_TIMING;
    heval_I2c1.Init.OwnAddress1      = 0;
    heval_I2c1.Init.AddressingMode   = I2C_ADDRESSINGMODE_7BIT;
    heval_I2c1.Init.DualAddressMode  = I2C_DUALADDRESS_DISABLE;
    heval_I2c1.Init.OwnAddress2      = 0;
    heval_I2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
    heval_I2c1.Init.GeneralCallMode  = I2C_GENERALCALL_DISABLE;
    heval_I2c1.Init.NoStretchMode    = I2C_NOSTRETCH_DISABLE;  

    /* Init the I2C */
    I2C1_MspInit(&heval_I2c1);
    HAL_I2C_Init(&heval_I2c1);
  }
}

/**
  * @brief I2C1 Bus Deinitialization
  * @retval None
  */
static void I2C1_DeInit(void)
{
  if(HAL_I2C_GetState(&heval_I2c1) != HAL_I2C_STATE_RESET)
  {
    /* DeInit the I2C */
    HAL_I2C_DeInit(&heval_I2c1);
    I2C1_MspDeInit(&heval_I2c1);
  }
}
/**
  * @brief  Writes a single data.
  * @param  Addr: I2C address
  * @param  Reg: Register address 
  * @param  Value: Data to be written
  * @retval None
  */
static void I2C1_Write(uint8_t Addr, uint8_t Reg, uint8_t Value)
{
  HAL_StatusTypeDef status = HAL_OK;

  status = HAL_I2C_Mem_Write(&heval_I2c1, Addr, (uint16_t)Reg, I2C_MEMADD_SIZE_8BIT, &Value, 1, 100); 

  /* Check the communication status */
  if(status != HAL_OK)
  {
    /* Execute user timeout callback */
    I2C1_Error();
  }
}

/**
  * @brief  Reads a single data.
  * @param  Addr: I2C address
  * @param  Reg: Register address 
  * @retval Read data
  */
static uint8_t I2C1_Read(uint8_t Addr, uint8_t Reg)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint8_t Value = 0;
  
  status = HAL_I2C_Mem_Read(&heval_I2c1, Addr, Reg, I2C_MEMADD_SIZE_8BIT, &Value, 1, 1000);
  
  /* Check the communication status */
  if(status != HAL_OK)
  {
    /* Execute user timeout callback */
    I2C1_Error();
  }
  return Value;   
}



/**
  * @brief  Reads multiple data on the BUS.
  * @param  Addr  : I2C Address
  * @param  Reg   : Reg Address 
  * @param  RegSize : The target register size (can be 8BIT or 16BIT)
  * @param  pBuffer : pointer to read data buffer
  * @param  Length : length of the data
  * @retval 0 if no problems to read multiple data
  */
static HAL_StatusTypeDef I2C1_ReadBuffer(uint16_t Addr, uint8_t Reg, uint16_t RegSize, uint8_t *pBuffer, uint16_t Length)
{
  HAL_StatusTypeDef status = HAL_OK;
  
  status = HAL_I2C_Mem_Read(&heval_I2c1, Addr, Reg, RegSize, pBuffer, Length, I2c1Timeout);
  
  /* Check the communication status */
  if(status != HAL_OK)
  {
    /* Re-Initiaize the BUS */
    I2C1_Error();
  }
  return status;
}

/**
  * @brief  Checks if target device is ready for communication. 
  * @note   This function is used with Memory devices
  * @param  DevAddress: Target device address
  * @param  Trials: Number of trials
  * @retval HAL status
  */
static HAL_StatusTypeDef I2C1_IsDeviceReady(uint16_t DevAddress, uint32_t Trials)
{ 
  return (HAL_I2C_IsDeviceReady(&heval_I2c1, DevAddress, Trials, I2c1Timeout));
}

/**
  * @brief  Write a value in a register of the device through BUS.
  * @param  Addr: Device address on BUS Bus.  
  * @param  Reg: The target register address to write
  * @param  RegSize: The target register size (can be 8BIT or 16BIT)
  * @param  pBuffer: The target register value to be written 
  * @param  Length: buffer size to be written
  * @retval None
  */
static HAL_StatusTypeDef I2C1_WriteBuffer(uint16_t Addr, uint8_t Reg, uint16_t RegSize, uint8_t *pBuffer, uint16_t Length)
{
  HAL_StatusTypeDef status = HAL_OK;
  
  status = HAL_I2C_Mem_Write(&heval_I2c1, Addr, Reg, RegSize, pBuffer, Length, I2c1Timeout); 
  
  /* Check the communication status */
  if(status != HAL_OK)
  {
    /* Re-Initiaize the BUS */
    I2C1_Error();
  }        
  return status;
}

/**
  * @brief  Manages error callback by re-initializing I2C.
  * @param  None
  * @retval None
  */
static void I2C1_Error(void)
{
  /* De-initialize the I2C communication BUS */
  HAL_I2C_DeInit(&heval_I2c1);
  
  /* Re-Initiaize the I2C communication BUS */
  I2C1_Init();
}

/**
  * @brief I2C MSP Initialization
  * @param hi2c: I2C handle
  * @retval None
  */
static void I2C1_MspInit(I2C_HandleTypeDef *hi2c)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  RCC_PeriphCLKInitTypeDef RCC_PeriphCLKInitStruct;

  /*##-1- Set source clock to SYSCLK for I2C1 ################################################*/  
  RCC_PeriphCLKInitStruct.PeriphClockSelection = RCC_PERIPHCLK_I2C1;
  RCC_PeriphCLKInitStruct.I2c1ClockSelection = RCC_I2C1CLKSOURCE_SYSCLK;
  HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphCLKInitStruct);

  /*##-2- Configure the GPIOs ################################################*/  
  
  /* Enable GPIO clock */
  EVAL_I2C1_GPIO_CLK_ENABLE();

  /* Configure I2C SCL & SDA as alternate function  */
  GPIO_InitStruct.Pin       = (EVAL_I2C1_SCL_PIN| EVAL_I2C1_SDA_PIN);
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Pull      = GPIO_NOPULL;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = EVAL_I2C1_SCL_SDA_AF;
  HAL_GPIO_Init(EVAL_I2C1_GPIO_PORT, &GPIO_InitStruct);

  /*##-3- Configure the Eval I2C peripheral #######################################*/ 
  /* Enable I2C clock */
  EVAL_I2C1_CLK_ENABLE();

  /* Force the I2C peripheral clock reset */
  EVAL_I2C1_FORCE_RESET();

  /* Release the I2C peripheral clock reset */
  EVAL_I2C1_RELEASE_RESET();
}

/**
  * @brief I2C1 MSP DeInitialization
  * @param hi2c: I2C2 handle
  * @retval None
  */
static void I2C1_MspDeInit(I2C_HandleTypeDef *hi2c)
{

    /*##-1- Unconfigure the GPIOs ################################################*/
    /* Enable GPIO clock */
    EVAL_I2C1_GPIO_CLK_ENABLE();

    /* Configure I2C Rx/Tx as alternate function  */
    HAL_GPIO_DeInit(EVAL_I2C1_GPIO_PORT, (EVAL_I2C1_SCL_PIN| EVAL_I2C1_SDA_PIN));

    /*##-2- Unconfigure the Discovery I2C2 peripheral ############################*/
    /* Force and release I2C Peripheral */
    EVAL_I2C1_FORCE_RESET();
    EVAL_I2C1_RELEASE_RESET();

    /* Disable Discovery I2C1 clock */
    EVAL_I2C1_RELEASE_RESET();
}

#endif /*HAL_I2C_MODULE_ENABLED*/

#if defined(HAL_SPI_MODULE_ENABLED)
/******************************* SPI Routines *********************************/

/**
  * @brief SPIx Bus initialization
  * @param None
  * @retval None
  */
static void SPIx_Init(void)
{
  if(HAL_SPI_GetState(&heval_Spi) == HAL_SPI_STATE_RESET)
  {
    /* SPI Config */
    heval_Spi.Instance = EVAL_SPIx;
    /* SPI baudrate is set to 16 MHz (PCLK2/SPI_BaudRatePrescaler = 32/2 = 16 MHz) 
    to verify these constraints:
    HX8347D LCD SPI interface max baudrate is  50MHz for write and 6.66MHz for read
    PCLK1 frequency is set to 32 MHz 
    - SD card SPI interface max baudrate is 25MHz for write/read
    */
    heval_Spi.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
    heval_Spi.Init.Direction = SPI_DIRECTION_2LINES;
    heval_Spi.Init.CLKPhase = SPI_PHASE_2EDGE;
    heval_Spi.Init.CLKPolarity = SPI_POLARITY_HIGH;
    heval_Spi.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
    heval_Spi.Init.CRCPolynomial = 7;
    heval_Spi.Init.DataSize = SPI_DATASIZE_8BIT;
    heval_Spi.Init.FirstBit = SPI_FIRSTBIT_MSB;
    heval_Spi.Init.NSS = SPI_NSS_SOFT;
    heval_Spi.Init.TIMode = SPI_TIMODE_DISABLE;
    heval_Spi.Init.Mode = SPI_MODE_MASTER;
    
    SPIx_MspInit(&heval_Spi);
    HAL_SPI_Init(&heval_Spi);
  }
}

/**
  * @brief SPI Read 1 bytes from device
  * @param None
  * @retval Read data
  */
static uint32_t SPIx_Read(void)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint8_t readvalue = 0x0;
  uint8_t writevalue = 0xff;
  
  status = HAL_SPI_TransmitReceive(&heval_Spi, &writevalue, &readvalue, 1, SpixTimeout);

  /* Check the communication status */
  if(status != HAL_OK)
  {
    /* Execute user timeout callback */
    SPIx_Error();
  }

  return (uint32_t) readvalue;
}

/**
  * @brief  SPI Write a byte to device
  * @param  Value: value to be written
  * @retval None
  */
#if defined(HAL_I2C_MODULE_ENABLED)
static void SPIx_WriteReadData(const uint8_t *DataIn, uint8_t *DataOut, uint16_t DataLegnth)
{
  HAL_StatusTypeDef status = HAL_OK;

  status = HAL_SPI_TransmitReceive(&heval_Spi, (uint8_t*) DataIn, DataOut, DataLegnth, SpixTimeout);
    
  /* Check the communication status */
  if(status != HAL_OK)
  {
    /* Execute user timeout callback */
    SPIx_Error();
  }
}
#endif //HAL_I2C_MODULE_ENABLED 
/**
  * @brief SPI Write a byte to device
  * @param Value: value to be written
  * @retval None
  */
static void SPIx_Write(uint8_t Value)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint8_t data;

  status = HAL_SPI_TransmitReceive(&heval_Spi, (uint8_t*) &Value, &data, 1, SpixTimeout);

  /* Check the communication status */
  if(status != HAL_OK)
  {
    /* Execute user timeout callback */
    SPIx_Error();
  }
}

/**
  * @brief SPI error treatment function
  * @param None
  * @retval None
  */
static void SPIx_Error (void)
{
  /* De-initialize the SPI communication BUS */
  HAL_SPI_DeInit(&heval_Spi);
  
  /* Re- Initiaize the SPI communication BUS */
  SPIx_Init();
}

/**
  * @brief SPI MSP Init
  * @param hspi: SPI handle
  * @retval None
  */
static void SPIx_MspInit(SPI_HandleTypeDef *hspi)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  /* Enable SPI clock  */
  EVAL_SPIx_CLK_ENABLE();
  
  /* enable EVAL_SPI gpio clocks */
  EVAL_SPIx_SCK_GPIO_CLK_ENABLE();
  EVAL_SPIx_MISO_GPIO_CLK_ENABLE();
  EVAL_SPIx_MOSI_GPIO_CLK_ENABLE();
  EVAL_SPIx_MOSI_DIR_GPIO_CLK_ENABLE();  
  
  /* configure SPI SCK */
  GPIO_InitStruct.Pin       = EVAL_SPIx_SCK_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull      = GPIO_NOPULL;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = EVAL_SPIx_SCK_AF;
  HAL_GPIO_Init(EVAL_SPIx_SCK_GPIO_PORT, &GPIO_InitStruct);
  
  /* configure SPI MOSI */
  GPIO_InitStruct.Pin       = EVAL_SPIx_MOSI_PIN;
  GPIO_InitStruct.Alternate = EVAL_SPIx_MOSI_AF;
  HAL_GPIO_Init(EVAL_SPIx_MOSI_GPIO_PORT, &GPIO_InitStruct);
  
  /* configure SPI MISO  */
  GPIO_InitStruct.Pin       = EVAL_SPIx_MISO_PIN;
  GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
  GPIO_InitStruct.Alternate = EVAL_SPIx_MISO_AF;
  HAL_GPIO_Init(EVAL_SPIx_MISO_GPIO_PORT, &GPIO_InitStruct);
  
  /* Set PB.2 as Out PP, as direction pin for MOSI */
  GPIO_InitStruct.Pin       = EVAL_SPIx_MOSI_DIR_PIN;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_MEDIUM     ;
  GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull      = GPIO_NOPULL;  
  HAL_GPIO_Init(EVAL_SPIx_MOSI_DIR_GPIO_PORT, &GPIO_InitStruct);
  
  /* MOSI DIRECTION as output */
  HAL_GPIO_WritePin(EVAL_SPIx_MOSI_DIR_GPIO_PORT, EVAL_SPIx_MOSI_DIR_PIN, GPIO_PIN_SET);
  
  /* Force the SPI peripheral clock reset */
  EVAL_SPIx_FORCE_RESET();

  /* Release the SPI peripheral clock reset */
  EVAL_SPIx_RELEASE_RESET();
}

#endif /*HAL_SPI_MODULE_ENABLED*/

/******************************************************************************
LINK OPERATIONS
*******************************************************************************/

#if defined(HAL_SPI_MODULE_ENABLED)
/********************************* LINK LCD ***********************************/

/**
  * @brief  Configures the LCD_SPI interface.
  * @param  None
  * @retval None
  */
void LCD_IO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  /* Configure the LCD Control pins ------------------------------------------*/
  LCD_NCS_GPIO_CLK_ENABLE();
    
  /* Configure NCS in Output Push-Pull mode */
  GPIO_InitStruct.Pin     = LCD_NCS_PIN;
  GPIO_InitStruct.Mode    = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull    = GPIO_PULLUP;
  GPIO_InitStruct.Speed   = GPIO_SPEED_FREQ_LOW     ;
  HAL_GPIO_Init(LCD_NCS_GPIO_PORT, &GPIO_InitStruct);
    
  /* Set or Reset the control line */
  LCD_CS_LOW();
  LCD_CS_HIGH();

  SPIx_Init();
}

/**
  * @brief  Write register value.
  * @param  pData Pointer on the register value
  * @param  Size Size of byte to transmit to the register
  * @retval None
  */
void LCD_IO_WriteMultipleData(uint8_t *pData, uint32_t Size)
{
  uint32_t counter = 0;
  __IO uint32_t data = 0;

  /* Reset LCD control line(/CS) and Send data */  
  LCD_CS_LOW();

  /* Send Start Byte */
  SPIx_Write(START_BYTE | LCD_WRITE_REG);

  if (Size == 1)
  {
    /* Only 1 byte to be sent to LCD - general interface can be used */
    /* Send Data */
    SPIx_Write(*pData);
  }
  else
  {
    for (counter = Size; counter != 0; counter--)
    {
      while(((heval_Spi.Instance->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE)
      {
      }  
      /* Need to invert bytes for LCD*/
      *((__IO uint8_t*)&heval_Spi.Instance->DR) = *(pData+1);
    
      while(((heval_Spi.Instance->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE)
      {
      }  
      *((__IO uint8_t*)&heval_Spi.Instance->DR) = *pData;
      counter--;
      pData += 2;
    }
    
    /* Wait until the bus is ready before releasing Chip select */ 
    while(((heval_Spi.Instance->SR) & SPI_FLAG_BSY) != RESET)
    {
    }
  }

  /* Empty the Rx fifo */
  data = *(&heval_Spi.Instance->DR);
  UNUSED(data);  /* Remove GNU warning */

  /* Reset LCD control line(/CS) and Send data */  
  LCD_CS_HIGH();
}

/**
  * @brief  register address.
  * @param  Reg
  * @retval None
  */
void LCD_IO_WriteReg(uint8_t Reg) 
{
  /* Reset LCD control line(/CS) and Send command */
  LCD_CS_LOW();
  
  /* Send Start Byte */
  SPIx_Write(START_BYTE | SET_INDEX);
  
  /* Write 16-bit Reg Index (High Byte is 0) */
  SPIx_Write(0x00);
  SPIx_Write(Reg);
  
  /* Deselect : Chip Select high */
  LCD_CS_HIGH();
}

/**
  * @brief  Read register value.
  * @param  Reg
  * @retval None
  */
uint16_t LCD_IO_ReadData(uint16_t Reg) 
{
  uint32_t readvalue = 0;

  /* Send Reg value to Read */
  LCD_IO_WriteReg(Reg);

  /* Reset LCD control line(/CS) and Send command */
  LCD_CS_LOW();
  
  /* Send Start Byte */
  SPIx_Write(START_BYTE | LCD_READ_REG);

  /* Read Upper Byte */
  SPIx_Write(0xFF);
  readvalue = SPIx_Read();
  readvalue = readvalue << 8;
  readvalue |= SPIx_Read();
  
  HAL_Delay(10);

  /* Deselect : Chip Select high */
  LCD_CS_HIGH();
  return readvalue;
}

/**
  * @brief  Wait for loop in ms.
  * @param  Delay in ms.
  * @retval None
  */
void LCD_Delay (uint32_t Delay)
{
  HAL_Delay(Delay);
}

#endif /*HAL_SPI_MODULE_ENABLED*/

/*******************************************************************************
                        SD Card  OPERATIONS
*******************************************************************************/
#if defined(HAL_SPI_MODULE_ENABLED) && defined(HAL_I2C_MODULE_ENABLED)

/**
  * @brief  Initializes the SD Card and put it into StandBy State (Ready for 
  *         data transfer).
  * @param  None
  * @retval None
  */
void SD_IO_Init(void)
{
  GPIO_InitTypeDef  GPIO_InitStruct;
  uint8_t counter;

  /* SD_CS_GPIO and SD_DETECT_GPIO Periph clock enable */
  SD_CS_GPIO_CLK_ENABLE();
 
  /* Configure SD_CS_PIN pin: SD Card CS pin */
  GPIO_InitStruct.Pin = SD_CS_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM     ;
  HAL_GPIO_Init(SD_CS_GPIO_PORT, &GPIO_InitStruct);

  /* Configure SD_DETECT_PIN pin: SD Card detect pin (Via MFX) */
  if (BSP_IO_Init() == IO_OK)
  {
    BSP_IO_ConfigPin(SD_DETECT_PIN, IO_MODE_INPUT_PU);
  }

  /*------------Put SD in SPI mode--------------*/
  /* SD SPI Config */
  SPIx_Init();

  /* SD chip select high */
  SD_CS_HIGH();
  
  /* Send dummy byte 0xFF, 10 times with CS high */
  /* Rise CS and MOSI for 80 clocks cycles */
  for (counter = 0; counter <= 9; counter++)
  {
    /* Send dummy byte 0xFF */
    SD_IO_WriteByte(SD_DUMMY_BYTE);
  }
}


void SD_IO_CSState(uint8_t val)
{
  if(val == 1) 
  {
    SD_CS_HIGH();
  }
  else
  {
    SD_CS_LOW();
  }
}

/**
  * @brief  Write a byte on the SD.
  * @param  Data: byte to send.
  * @retval None
  */
void SD_IO_WriteReadData(const uint8_t *DataIn, uint8_t *DataOut, uint16_t DataLength)
{
//  /* SD chip select low */
//  SD_CS_LOW();
  /* Send the byte */
  SPIx_WriteReadData(DataIn, DataOut, DataLength);
}

/**
  * @brief  Writes a byte on the SD.
  * @param  Data: byte to send.
  * @retval None
  */
uint8_t SD_IO_WriteByte(uint8_t Data)
{
  uint8_t tmp;
//  /* SD chip select low */
//  SD_CS_LOW();
//    
  /* Send the byte */
  SPIx_WriteReadData(&Data,&tmp,1);
  return tmp;
}

#endif /* HAL_SPI_MODULE_ENABLED && HAL_I2C_MODULE_ENABLED*/

/*******************************************************************************
                            MFX OPERATIONS
*******************************************************************************/
#if defined(HAL_I2C_MODULE_ENABLED)
/**
  * @brief  Initializes IOE low level.
  * @param  None
  * @retval None
  */
void MFX_IO_Init(void)
{
  I2C1_Init();
}

/**
  * @brief  Deinitializes MFX low level.
  * @retval None
  */
void MFX_IO_DeInit(void)
{
  I2C1_DeInit();
}

/**
  * @brief  Configures IOE low level interrupt.
  * @param  None
  * @retval None
  */
void MFX_IO_ITConfig(void)
{
  static uint8_t MFX_IO_IT_Enabled = 0;
  GPIO_InitTypeDef  GPIO_InitStruct;
  
  if(MFX_IO_IT_Enabled == 0)
  {
    MFX_IO_IT_Enabled = 1;
    /* Enable the GPIO EXTI clock */
    MFX_IRQOUT_CLK_ENABLE();
    __HAL_RCC_SYSCFG_CLK_ENABLE();

    GPIO_InitStruct.Pin   = MFX_IRQOUT_PIN;
    GPIO_InitStruct.Pull  = GPIO_PULLUP;     
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;   
    GPIO_InitStruct.Mode  = GPIO_MODE_IT_RISING;
    HAL_GPIO_Init(MFX_IRQOUT_PORT, &GPIO_InitStruct);
    
    /* Enable and set GPIO EXTI Interrupt to the lowest priority */
    HAL_NVIC_SetPriority((IRQn_Type)(MFX_IRQOUT_EXTI_IRQn), 0x03, 0x00);
    HAL_NVIC_EnableIRQ((IRQn_Type)(MFX_IRQOUT_EXTI_IRQn));
    
  }
}

/**
  * @brief  Configures MFX wke up  pin.
  * @retval None
  */
void MFX_IO_EnableWakeupPin(void)
{
  GPIO_InitTypeDef  GPIO_InitStruct;

  /* Enable wakeup gpio clock */
  IDD_WAKEUP_GPIO_CLK_ENABLE();

  /* MFX wakeup pin configuration */
  GPIO_InitStruct.Pin   = IDD_WAKEUP_PIN;
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Pull  = GPIO_NOPULL;
  HAL_GPIO_Init(IDD_WAKEUP_GPIO_PORT, &GPIO_InitStruct);
}

/**
  * @brief  Wakeup MFX.
  * @retval None
  */
void MFX_IO_Wakeup(void)
{
  /* Set Wakeup pin to high to wakeup Idd measurement component from standby mode */
  HAL_GPIO_WritePin(IDD_WAKEUP_GPIO_PORT, IDD_WAKEUP_PIN, GPIO_PIN_SET);

  /* Wait */
  HAL_Delay(1);

  /* Set gpio pin basck to low */
  HAL_GPIO_WritePin(IDD_WAKEUP_GPIO_PORT, IDD_WAKEUP_PIN, GPIO_PIN_RESET);
}

/**
  * @brief  IOE writes single data.
  * @param  Addr: I2C address
  * @param  Reg: Register address 
  * @param  Value: Data to be written
  * @retval None
  */
void MFX_IO_Write(uint16_t Addr, uint8_t Reg, uint8_t Value)
{
  I2C1_Write((uint8_t)Addr, Reg, Value);
}

/**
  * @brief  IOE reads single data.
  * @param  Addr: I2C address
  * @param  Reg: Register address 
  * @retval Read data
  */
uint8_t MFX_IO_Read(uint16_t Addr, uint8_t Reg)
{
  return I2C1_Read((uint8_t)Addr, Reg);
}

/**
  * @brief  IOE reads multiple data.
  * @param  Addr: I2C address
  * @param  Reg: Register address 
  * @param  Buffer: Pointer to data buffer
  * @param  Length: Length of the data
  * @retval Number of read data
  */
uint16_t MFX_IO_ReadMultiple(uint16_t Addr, uint8_t Reg, uint8_t *Buffer, uint16_t Length)
{
 return I2C1_ReadBuffer((uint8_t)Addr, (uint16_t)Reg, I2C_MEMADD_SIZE_8BIT, Buffer, Length);
}

/**
  * @brief  IOE writes multiple data.
  * @param  Addr: I2C address
  * @param  Reg: Register address 
  * @param  Buffer: Pointer to data buffer
  * @param  Length: Length of the data
  * @retval None
  */
/*
void MFX_IO_WriteMultiple(uint16_t Addr, uint8_t Reg, uint8_t *Buffer, uint16_t Length)
{
  I2C1_WriteMultiple((uint8_t)Addr, (uint16_t)Reg, I2C_MEMADD_SIZE_8BIT, Buffer, Length);
}
*/

/**
  * @brief  IOE delay 
  * @param  Delay: Delay in ms
  * @retval None
  */
void MFX_IO_Delay(uint32_t Delay)
{
  HAL_Delay(Delay);
}



/********************************* LINK I2C EEPROM *****************************/
/**
  * @brief  Initializes peripherals used by the I2C EEPROM driver.
  * @param  None
  * @retval None
  */
void EEPROM_IO_Init(void)
{
  I2C1_Init();
}

/**
  * @brief  Write data to I2C EEPROM driver
  * @param  DevAddress: Target device address
  * @param  MemAddress: Internal memory address
  * @param  pBuffer: Pointer to data buffer
  * @param  BufferSize: Amount of data to be sent
  * @retval HAL status
  */
HAL_StatusTypeDef EEPROM_IO_WriteData(uint16_t DevAddress, uint16_t MemAddress, uint8_t* pBuffer, uint32_t BufferSize)
{
  return (I2C1_WriteBuffer(DevAddress, MemAddress, I2C_MEMADD_SIZE_16BIT, pBuffer, BufferSize));
}

/**
  * @brief  Read data from I2C EEPROM driver
  * @param  DevAddress: Target device address
  * @param  MemAddress: Internal memory address
  * @param  pBuffer: Pointer to data buffer
  * @param  BufferSize: Amount of data to be read
  * @retval HAL status
  */
HAL_StatusTypeDef EEPROM_IO_ReadData(uint16_t DevAddress, uint16_t MemAddress, uint8_t* pBuffer, uint32_t BufferSize)
{
  return (I2C1_ReadBuffer(DevAddress, MemAddress, I2C_MEMADD_SIZE_16BIT, pBuffer, BufferSize));
}

/**
  * @brief  Checks if target device is ready for communication. 
  * @note   This function is used with Memory devices
  * @param  DevAddress: Target device address
  * @param  Trials: Number of trials
  * @retval HAL status
  */
HAL_StatusTypeDef EEPROM_IO_IsDeviceReady(uint16_t DevAddress, uint32_t Trials)
{ 
  return (I2C1_IsDeviceReady(DevAddress, Trials));
}

/********************************* LINK I2C TEMPERATURE SENSOR *****************************/
/**
  * @brief  Initializes peripherals used by the I2C Temperature Sensor driver.
  * @param  None
  * @retval None
  */
void TSENSOR_IO_Init(void)
{
  I2C1_Init();
}

/**
  * @brief  Writes one byte to the TSENSOR.
  * @param  DevAddress: Target device address
  * @param  pBuffer: Pointer to data buffer
  * @param  WriteAddr: TSENSOR's internal address to write to.
  * @param  Length: Number of data to write
  * @retval None
  */
void TSENSOR_IO_Write(uint16_t DevAddress, uint8_t* pBuffer, uint8_t WriteAddr, uint16_t Length)
{
  I2C1_WriteBuffer(DevAddress, WriteAddr, I2C_MEMADD_SIZE_8BIT, pBuffer, Length);
}

/**
  * @brief  Reads one byte from the TSENSOR.
  * @param  DevAddress: Target device address
  * @param  pBuffer : pointer to the buffer that receives the data read from the TSENSOR.
  * @param  ReadAddr : TSENSOR's internal address to read from.
  * @param  Length: Number of data to read
  * @retval None
  */
void TSENSOR_IO_Read(uint16_t DevAddress, uint8_t* pBuffer, uint8_t ReadAddr, uint16_t Length)
{
  I2C1_ReadBuffer(DevAddress, ReadAddr, I2C_MEMADD_SIZE_8BIT, pBuffer, Length);
}

/**
  * @brief  Checks if Temperature Sensor is ready for communication. 
  * @param  DevAddress: Target device address
  * @param  Trials: Number of trials
  * @retval HAL status
  */
uint16_t TSENSOR_IO_IsDeviceReady(uint16_t DevAddress, uint32_t Trials)
{ 
  return (I2C1_IsDeviceReady(DevAddress, Trials));
}

#endif /* HAL_I2C_MODULE_ENABLED */

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
    
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
