/**
  ******************************************************************************
  * @file    stm32l0xx_nucleo_32.c
  * @author  MCD Application Team
  * @brief   This file provides set of firmware functions to manage:
  *          - LEDs and push-button available on STM32L0XX-Nucleo Kit 
  *            from STMicroelectronics
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
#include "stm32l0xx_nucleo_32.h"
    
/** @addtogroup BSP
  * @{
  */ 

/** @addtogroup STM32L0XX_NUCLEO_32 NUCLEO 32
  * @brief This file provides set of firmware functions to manage Leds and push-button
  *        available on STM32L0XX-Nucleo Kit from STMicroelectronics.
  * @{
  */ 

/** @defgroup STM32L0XX_NUCLEO_32_Private_Defines Private Defines
  * @{
  */ 

/**
  * @brief STM32L0XX NUCLEO BSP Driver version number
  */
#define __STM32L0XX_NUCLEO_32_BSP_VERSION_MAIN   (0x01) /*!< [31:24] main version */
#define __STM32L0XX_NUCLEO_32_BSP_VERSION_SUB1   (0x00) /*!< [23:16] sub1 version */
#define __STM32L0XX_NUCLEO_32_BSP_VERSION_SUB2   (0x04) /*!< [15:8]  sub2 version */
#define __STM32L0XX_NUCLEO_32_BSP_VERSION_RC     (0x00) /*!< [7:0]  release candidate */
#define __STM32L0XX_NUCLEO_32_BSP_VERSION         ((__STM32L0XX_NUCLEO_32_BSP_VERSION_MAIN << 24)\
                                             |(__STM32L0XX_NUCLEO_32_BSP_VERSION_SUB1 << 16)\
                                             |(__STM32L0XX_NUCLEO_32_BSP_VERSION_SUB2 << 8 )\
                                             |(__STM32L0XX_NUCLEO_32_BSP_VERSION_RC))

/**
  * @brief LINK SD Card
  */
#define SD_DUMMY_BYTE            0xFF    
#define SD_NO_RESPONSE_EXPECTED  0x80

/**
  * @}
  */ 

/** @defgroup STM32L0XX_NUCLEO_32_Private_Variables Private Variables
  * @{
  */ 
GPIO_TypeDef* LED_PORT[LEDn] = {LED3_GPIO_PORT};
const uint16_t LED_PIN[LEDn] = {LED3_PIN};

/**
 * @brief BUS variables
 */
#if defined(HAL_I2C_MODULE_ENABLED)
uint32_t I2c1Timeout = BSP_I2C1_TIMEOUT_MAX;    /*<! Value of Timeout when I2C1 communication fails */
I2C_HandleTypeDef heval_I2c1;
#endif /* HAL_I2C_MODULE_ENABLED */

#ifdef HAL_SPI_MODULE_ENABLED
uint32_t SpixTimeout = NUCLEO_SPIx_TIMEOUT_MAX; /*<! Value of Timeout when SPI communication fails */
static SPI_HandleTypeDef hnucleo_Spi;
#endif /* HAL_SPI_MODULE_ENABLED */

#ifdef HAL_ADC_MODULE_ENABLED
static ADC_HandleTypeDef hnucleo_Adc;
/* ADC channel configuration structure declaration */
static ADC_ChannelConfTypeDef sConfig;
#endif /* HAL_ADC_MODULE_ENABLED */
/**
  * @}
  */ 

/** @defgroup STM32L0XX_NUCLEO_32_Private_Function_Prototypes Private Function Prototypes
  * @{
  */ 

#ifdef HAL_SPI_MODULE_ENABLED
static void               SPIx_Init(void);
static void               SPIx_Write(uint8_t Value);
static uint32_t           SPIx_Read(void);
static void               SPIx_Error (void);
static void               SPIx_MspInit(SPI_HandleTypeDef *hspi);

/* SD IO functions */
void                      SD_IO_Init(void);
HAL_StatusTypeDef         SD_IO_WriteCmd(uint8_t Cmd, uint32_t Arg, uint8_t Crc, uint8_t Response);
HAL_StatusTypeDef         SD_IO_WaitResponse(uint8_t Response);
void                      SD_IO_WriteDummy(void);
void                      SD_IO_WriteByte(uint8_t Data);
uint8_t                   SD_IO_ReadByte(void);

/* LCD IO functions */
void                      LCD_IO_Init(void);
void                      LCD_IO_WriteData(uint8_t Data);
void                      LCD_IO_WriteMultipleData(uint8_t *pData, uint32_t Size);
void                      LCD_IO_WriteReg(uint8_t LCDReg);
void                      LCD_Delay(uint32_t delay);
#endif /* HAL_SPI_MODULE_ENABLED */

#ifdef HAL_ADC_MODULE_ENABLED
static void               ADCx_Init(void);
static void               ADCx_MspInit(ADC_HandleTypeDef *hadc);
#endif /* HAL_ADC_MODULE_ENABLED */
/**
  * @}
  */ 

/** @defgroup STM32L0XX_NUCLEO_32_Private_Functions Private Functions
  * @{
  */ 

/**
  * @brief  This method returns the STM32L0XX NUCLEO BSP Driver revision
  * @retval version : 0xXYZR (8bits for each decimal, R for RC)
  */
uint32_t BSP_GetVersion(void)
{
  return __STM32L0XX_NUCLEO_32_BSP_VERSION;
}

/**
  * @brief  Configures LED GPIO.
  * @param  Led: Specifies the Led to be configured. 
  *   This parameter can be one of following parameters:
  *            @arg  LED3
  * @retval None
  */
void BSP_LED_Init(Led_TypeDef Led)
{
  GPIO_InitTypeDef  GPIO_InitStruct;
  
  /* Enable the GPIO_LED Clock */
  LEDx_GPIO_CLK_ENABLE(Led);

  /* Configure the GPIO_LED pin */
  GPIO_InitStruct.Pin = LED_PIN[Led];
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  
  HAL_GPIO_Init(LED_PORT[Led], &GPIO_InitStruct);
  HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_RESET); 
}

/**
  * @brief  Turns selected LED On.
  * @param  Led: Specifies the Led to be set on. 
  *   This parameter can be one of following parameters:
  *            @arg  LED3
  * @retval None
  */
void BSP_LED_On(Led_TypeDef Led)
{
  HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_SET); 
}

/**
  * @brief  Turns selected LED Off. 
  * @param  Led: Specifies the Led to be set off. 
  *   This parameter can be one of following parameters:
  *            @arg  LED3
  * @retval None
  */
void BSP_LED_Off(Led_TypeDef Led)
{
  HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_RESET); 
}

/**
  * @brief  Toggles the selected LED.
  * @param  Led: Specifies the Led to be toggled. 
  *   This parameter can be one of following parameters:
  *            @arg  LED3
  * @retval None
  */
void BSP_LED_Toggle(Led_TypeDef Led)
{
  HAL_GPIO_TogglePin(LED_PORT[Led], LED_PIN[Led]);
}

/******************************************************************************
                            BUS OPERATIONS
*******************************************************************************/
#if defined(HAL_I2C_MODULE_ENABLED)
/******************************* I2C Routines *********************************/

/**
  * @brief I2C Bus initialization
  * @retval None
  */
void I2C1_Init(void)
{
  if(HAL_I2C_GetState(&heval_I2c1) == HAL_I2C_STATE_RESET)
  {
    heval_I2c1.Instance              = BSP_I2C1;
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
  * @brief  Writes a single data.
  * @param  Addr: I2C address
  * @param  Reg: Register address 
  * @param  Value: Data to be written
  * @retval None
  */
void I2C1_Write(uint8_t Addr, uint8_t Reg, uint8_t Value)
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
uint8_t I2C1_Read(uint8_t Addr, uint8_t Reg)
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
HAL_StatusTypeDef I2C1_ReadBuffer(uint16_t Addr, uint8_t Reg, uint16_t RegSize, uint8_t *pBuffer, uint16_t Length)
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
HAL_StatusTypeDef I2C1_IsDeviceReady(uint16_t DevAddress, uint32_t Trials)
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
HAL_StatusTypeDef I2C1_WriteBuffer(uint16_t Addr, uint8_t Reg, uint16_t RegSize, uint8_t *pBuffer, uint16_t Length)
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
  * @retval None
  */
void I2C1_Error(void)
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
void I2C1_MspInit(I2C_HandleTypeDef *hi2c)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  RCC_PeriphCLKInitTypeDef RCC_PeriphCLKInitStruct;

  /*##-1- Set source clock to SYSCLK for I2C1 ################################################*/  
  RCC_PeriphCLKInitStruct.PeriphClockSelection = RCC_PERIPHCLK_I2C1;
  RCC_PeriphCLKInitStruct.I2c1ClockSelection = RCC_I2C1CLKSOURCE_SYSCLK;
  HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphCLKInitStruct);

  /*##-2- Configure the GPIOs ################################################*/  
  
  /* Enable GPIO clock */
  BSP_I2C1_GPIO_CLK_ENABLE();

  /* Configure I2C SCL & SDA as alternate function  */
  GPIO_InitStruct.Pin       = (BSP_I2C1_SCL_PIN| BSP_I2C1_SDA_PIN);
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Pull      = GPIO_NOPULL;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = BSP_I2C1_SCL_SDA_AF;
  HAL_GPIO_Init(BSP_I2C1_GPIO_PORT, &GPIO_InitStruct);

  /*##-3- Configure the Eval I2C peripheral #######################################*/ 
  /* Enable I2C clock */
  BSP_I2C1_CLK_ENABLE();

  /* Force the I2C peripheral clock reset */
  BSP_I2C1_FORCE_RESET();

  /* Release the I2C peripheral clock reset */
  BSP_I2C1_RELEASE_RESET();
}

#endif /*HAL_I2C_MODULE_ENABLED*/

#ifdef HAL_SPI_MODULE_ENABLED
/**
  * @brief  Initializes SPI MSP.
  * @param  hspi: SPI handle
  * @retval None
  */
static void SPIx_MspInit(SPI_HandleTypeDef *hspi)
{
  GPIO_InitTypeDef  GPIO_InitStruct;  
  
  /*** Configure the GPIOs ***/  
  /* Enable GPIO clock */
  NUCLEO_SPIx_SCK_GPIO_CLK_ENABLE();
  NUCLEO_SPIx_MISO_MOSI_GPIO_CLK_ENABLE();
  
  /* Configure SPI SCK */
  GPIO_InitStruct.Pin = NUCLEO_SPIx_SCK_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull  = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = NUCLEO_SPIx_SCK_AF;
  HAL_GPIO_Init(NUCLEO_SPIx_SCK_GPIO_PORT, &GPIO_InitStruct);

  /* Configure SPI MISO and MOSI */ 
  GPIO_InitStruct.Pin = NUCLEO_SPIx_MOSI_PIN;
  GPIO_InitStruct.Alternate = NUCLEO_SPIx_MISO_MOSI_AF;
  GPIO_InitStruct.Pull  = GPIO_PULLDOWN;
  HAL_GPIO_Init(NUCLEO_SPIx_MISO_MOSI_GPIO_PORT, &GPIO_InitStruct);
  
  GPIO_InitStruct.Pin = NUCLEO_SPIx_MISO_PIN;
  HAL_GPIO_Init(NUCLEO_SPIx_MISO_MOSI_GPIO_PORT, &GPIO_InitStruct);

  /*** Configure the SPI peripheral ***/ 
  /* Enable SPI clock */
  NUCLEO_SPIx_CLK_ENABLE();
}

/**
  * @brief  Initializes SPI HAL.
  * @retval None
  */
static void SPIx_Init(void)
{
  if(HAL_SPI_GetState(&hnucleo_Spi) == HAL_SPI_STATE_RESET)
  {
    /* SPI Config */
    hnucleo_Spi.Instance = NUCLEO_SPIx;
      /* SPI baudrate is set to 8 MHz maximum (PCLK2/SPI_BaudRatePrescaler = 32/4 = 8 MHz) 
       to verify these constraints:
          - ST7735 LCD SPI interface max baudrate is 15MHz for write and 6.66MHz for read
            Since the provided driver doesn't use read capability from LCD, only constraint 
            on write baudrate is considered.
          - SD card SPI interface max baudrate is 25MHz for write/read
          - PCLK2 max frequency is 32 MHz 
       */ 
    hnucleo_Spi.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
    hnucleo_Spi.Init.Direction = SPI_DIRECTION_2LINES;
    hnucleo_Spi.Init.CLKPhase = SPI_PHASE_2EDGE;
    hnucleo_Spi.Init.CLKPolarity = SPI_POLARITY_HIGH;
    hnucleo_Spi.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
    hnucleo_Spi.Init.CRCPolynomial = 7;
    hnucleo_Spi.Init.DataSize = SPI_DATASIZE_8BIT;
    hnucleo_Spi.Init.FirstBit = SPI_FIRSTBIT_MSB;
    hnucleo_Spi.Init.NSS = SPI_NSS_SOFT;
    hnucleo_Spi.Init.TIMode = SPI_TIMODE_DISABLE;
    hnucleo_Spi.Init.Mode = SPI_MODE_MASTER;
    
    SPIx_MspInit(&hnucleo_Spi);
    HAL_SPI_Init(&hnucleo_Spi);
  }
}

/**
  * @brief  SPI Read 4 bytes from device
  * @retval Read data
*/
static uint32_t SPIx_Read(void)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t readvalue = 0;
  uint32_t writevalue = 0xFFFFFFFF;
  
  status = HAL_SPI_TransmitReceive(&hnucleo_Spi, (uint8_t*) &writevalue, (uint8_t*) &readvalue, 1, SpixTimeout);
  
  /* Check the communication status */
  if(status != HAL_OK)
  {
    /* Execute user timeout callback */
    SPIx_Error();
  }

  return readvalue;
}

/**
  * @brief  SPI Write a byte to device
  * @param  Value: value to be written
  * @retval None
  */
static void SPIx_Write(uint8_t Value)
{
  HAL_StatusTypeDef status = HAL_OK;

  status = HAL_SPI_Transmit(&hnucleo_Spi, (uint8_t*) &Value, 1, SpixTimeout);
    
  /* Check the communication status */
  if(status != HAL_OK)
  {
    /* Execute user timeout callback */
    SPIx_Error();
  }
}

/**
  * @brief  SPI error treatment function
  * @retval None
  */
static void SPIx_Error (void)
{
  /* De-initialize the SPI communication BUS */
  HAL_SPI_DeInit(&hnucleo_Spi);
  
  /* Re-Initiaize the SPI communication BUS */
  SPIx_Init();
}

/******************************************************************************
                            LINK OPERATIONS
*******************************************************************************/

/********************************* LINK SD ************************************/
/**
  * @brief  Initializes the SD Card and put it into StandBy State (Ready for 
  *         data transfer).
  * @retval None
  */
void SD_IO_Init(void)
{
  GPIO_InitTypeDef  GPIO_InitStruct;
  uint8_t counter;

  /* SD_CS_GPIO Periph clock enable */
  SD_CS_GPIO_CLK_ENABLE();

  /* Configure SD_CS_PIN pin: SD Card CS pin */
  GPIO_InitStruct.Pin = SD_CS_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(SD_CS_GPIO_PORT, &GPIO_InitStruct);

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

/**
  * @brief  Writes a byte on the SD.
  * @param  Data: byte to send.
  * @retval None
  */
void SD_IO_WriteByte(uint8_t Data)
{
  /* Send the byte */
  SPIx_Write(Data);
}

/**
  * @brief  Reads a byte from the SD.
  * @retval The received byte.
  */
uint8_t SD_IO_ReadByte(void)
{
  uint8_t data = 0;
  
  /* Get the received data */
  data = SPIx_Read();

  /* Return the shifted data */
  return data;
}

/**
  * @brief  Sends 5 bytes command to the SD card and get response
  * @param  Cmd: The user expected command to send to SD card.
  * @param  Arg: The command argument.
  * @param  Crc: The CRC.
  * @param  Response: Expected response from the SD card
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef SD_IO_WriteCmd(uint8_t Cmd, uint32_t Arg, uint8_t Crc, uint8_t Response)
{
  uint32_t counter = 0x00;
  uint8_t frame[6];

  /* Prepare Frame to send */
  frame[0] = (Cmd | 0x40);         /* Construct byte 1 */
  frame[1] = (uint8_t)(Arg >> 24); /* Construct byte 2 */
  frame[2] = (uint8_t)(Arg >> 16); /* Construct byte 3 */
  frame[3] = (uint8_t)(Arg >> 8);  /* Construct byte 4 */
  frame[4] = (uint8_t)(Arg);       /* Construct byte 5 */
  frame[5] = (Crc);                /* Construct byte 6 */
  
  /* SD chip select low */
  SD_CS_LOW();
    
  /* Send Frame */
  for (counter = 0; counter < 6; counter++)
  {
    SD_IO_WriteByte(frame[counter]); /* Send the Cmd bytes */
  }

  if(Response != SD_NO_RESPONSE_EXPECTED)
  {
    return SD_IO_WaitResponse(Response);
  }
  
  return HAL_OK;
}

/**
  * @brief  Waits response from the SD card
  * @param  Response: Expected response from the SD card
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef SD_IO_WaitResponse(uint8_t Response)
{
  uint32_t timeout = 0xFFFF;

  /* Check if response is got or a timeout is happen */
  while ((SD_IO_ReadByte() != Response) && timeout)
  {
    timeout--;
  }

  if (timeout == 0)
  {
    /* After time out */
    return HAL_TIMEOUT;
  }
  else
  {
    /* Right response got */
    return HAL_OK;
  }
}

/**
  * @brief  Sends dummy byte with CS High
  * @retval None
  */
void SD_IO_WriteDummy(void)
{
  /* SD chip select high */
  SD_CS_HIGH();
  
  /* Send Dummy byte 0xFF */
  SD_IO_WriteByte(SD_DUMMY_BYTE);
}

/********************************* LINK LCD ***********************************/
/**
  * @brief  Initializes the LCD
  * @retval None
  */
void LCD_IO_Init(void)
{
  GPIO_InitTypeDef  GPIO_InitStruct;
   
  /* LCD_CS_GPIO and LCD_DC_GPIO Periph clock enable */
  LCD_CS_GPIO_CLK_ENABLE();
  LCD_DC_GPIO_CLK_ENABLE();
  
  /* Configure LCD_CS_PIN pin: LCD Card CS pin */
  GPIO_InitStruct.Pin = LCD_CS_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(LCD_CS_GPIO_PORT, &GPIO_InitStruct);

  /* Configure LCD_DC_PIN pin: LCD Card DC pin */
  GPIO_InitStruct.Pin = LCD_DC_PIN;
  HAL_GPIO_Init(LCD_DC_GPIO_PORT, &GPIO_InitStruct);
  
  /* LCD chip select high */
  LCD_CS_HIGH();
  
  /* LCD SPI Config */
  SPIx_Init();
}

/**
  * @brief  Writes command to select the LCD register.
  * @param  LCDReg: Address of the selected register.
  * @retval None
  */
void LCD_IO_WriteReg(uint8_t LCDReg)
{
  /* Reset LCD control line CS */
  LCD_CS_LOW();
  
  /* Set LCD data/command line DC to Low */
  LCD_DC_LOW();
    
  /* Send Command */
  SPIx_Write(LCDReg);
  
  /* Deselect : Chip Select high */
  LCD_CS_HIGH();
}

/**
  * @brief  Writes data to select the LCD register.
  *         This function must be used after st7735_WriteReg() function
  * @param  Data: data to write to the selected register.
  * @retval None
  */
void LCD_IO_WriteData(uint8_t Data)
{
  /* Reset LCD control line CS */
  LCD_CS_LOW();
  
  /* Set LCD data/command line DC to High */
  LCD_DC_HIGH();

  /* Send Data */
  SPIx_Write(Data);
  
  /* Deselect : Chip Select high */
  LCD_CS_HIGH();
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
  
  /* Reset LCD control line CS */
  LCD_CS_LOW();
  
  /* Set LCD data/command line DC to High */
  LCD_DC_HIGH();

  if (Size == 1)
  {
    /* Only 1 byte to be sent to LCD - general interface can be used */
    /* Send Data */
    SPIx_Write(*pData);
  }
  else
  {
    /* Several data should be sent in a raw */
    /* Direct SPI accesses for optimization */
    for (counter = Size; counter != 0; counter--)
    {
      while(((hnucleo_Spi.Instance->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE)
      {
      }  
      /* Need to invert bytes for LCD*/
      *((__IO uint8_t*)&hnucleo_Spi.Instance->DR) = *(pData+1);
      
      while(((hnucleo_Spi.Instance->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE)
      {
      }  
      *((__IO uint8_t*)&hnucleo_Spi.Instance->DR) = *pData;
      counter--;
      pData += 2;
    }
    
    /* Wait until the bus is ready before releasing Chip select */ 
    while(((hnucleo_Spi.Instance->SR) & SPI_FLAG_BSY) != RESET)
    {
    }  
  } 
  /* Deselect : Chip Select high */
  LCD_CS_HIGH();
}

/**
  * @brief  Wait for loop in ms.
  * @param  Delay in ms.
  * @retval None
  */
void LCD_Delay(uint32_t Delay)
{
  HAL_Delay(Delay);
}
#endif /* HAL_SPI_MODULE_ENABLED */

/******************************* LINK JOYSTICK ********************************/
#ifdef HAL_ADC_MODULE_ENABLED
/**
  * @brief  Initializes ADC MSP.
  * @param  hadc: ADC peripheral
  * @retval None
  */
static void ADCx_MspInit(ADC_HandleTypeDef *hadc)
{
  GPIO_InitTypeDef  GPIO_InitStruct;
  
  /*** Configure the GPIOs ***/  
  /* Enable GPIO clock */
  NUCLEO_ADCx_GPIO_CLK_ENABLE();
  
  /* Configure ADC1 Channel8 as analog input */
  GPIO_InitStruct.Pin = NUCLEO_ADCx_GPIO_PIN ;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  HAL_GPIO_Init(NUCLEO_ADCx_GPIO_PORT, &GPIO_InitStruct);

  /*** Configure the ADC peripheral ***/ 
  /* Enable ADC clock */
  NUCLEO_ADCx_CLK_ENABLE(); 
}

/**
  * @brief  Initializes ADC HAL.
  * @retval None
  */
static void ADCx_Init(void)
{
  if(HAL_ADC_GetState(&hnucleo_Adc) == HAL_ADC_STATE_RESET)
  {
    /* ADC Config */
    hnucleo_Adc.Instance = NUCLEO_ADCx;
    hnucleo_Adc.Init.OversamplingMode      = DISABLE;
    hnucleo_Adc.Init.ClockPrescaler        = ADC_CLOCK_SYNC_PCLK_DIV2; /* (must not exceed 16MHz) */
    hnucleo_Adc.Init.LowPowerAutoPowerOff  = DISABLE;
    hnucleo_Adc.Init.LowPowerFrequencyMode = ENABLE;
    hnucleo_Adc.Init.LowPowerAutoWait      = ENABLE;
    hnucleo_Adc.Init.Resolution            = ADC_RESOLUTION_12B;
    hnucleo_Adc.Init.SamplingTime          = ADC_SAMPLETIME_1CYCLE_5;
    hnucleo_Adc.Init.ScanConvMode          = ADC_SCAN_DIRECTION_FORWARD;
    hnucleo_Adc.Init.DataAlign             = ADC_DATAALIGN_RIGHT;
    hnucleo_Adc.Init.ContinuousConvMode    = DISABLE;
    hnucleo_Adc.Init.DiscontinuousConvMode = DISABLE;
    hnucleo_Adc.Init.ExternalTrigConvEdge  = ADC_EXTERNALTRIGCONVEDGE_NONE;
    hnucleo_Adc.Init.EOCSelection          = ADC_EOC_SINGLE_CONV;
    hnucleo_Adc.Init.DMAContinuousRequests = DISABLE;    
    
    ADCx_MspInit(&hnucleo_Adc);
    HAL_ADC_Init(&hnucleo_Adc);
  }
}

/**
  * @brief  Configures joystick available on adafruit 1.8" TFT shield 
  *         managed through ADC to detect motion.
  * @retval Joystickstatus (0=> success, 1=> fail) 
  */
uint8_t BSP_JOY_Init(void)
{
  uint8_t status = 1;
   
  ADCx_Init();
   
  /* Start ADC calibration */
  HAL_ADCEx_Calibration_Start(&hnucleo_Adc, ADC_SINGLE_ENDED);
  
  /* Select Channel 0 to be converted */
  sConfig.Channel = ADC_CHANNEL_8;    
  status = HAL_ADC_ConfigChannel(&hnucleo_Adc, &sConfig);
  
  /* Return Joystick initialization status */
  return status;
}

/**
  * @brief  Returns the Joystick key pressed.
  * @note   To know which Joystick key is pressed we need to detect the voltage
  *         level on each key output
  *           - None  : 3.3 V / 4095
  *           - SEL   : 1.055 V / 1308
  *           - DOWN  : 0.71 V / 88
  *           - LEFT  : 3.0 V / 3720 
  *           - RIGHT : 0.595 V / 737
  *           - UP    : 1.65 V / 2046
  * @retval JOYState_TypeDef: Code of the Joystick key pressed.
  */
JOYState_TypeDef BSP_JOY_GetState(void)
{
  JOYState_TypeDef state;
  uint16_t  KeyConvertedValue = 0;
  
 /* Start the conversion process */
  HAL_ADC_Start(&hnucleo_Adc);
  
  /* Wait for the end of conversion */
  if (HAL_ADC_PollForConversion(&hnucleo_Adc, 10) != HAL_TIMEOUT)
  {
    /* Get the converted value of regular channel */
    KeyConvertedValue = HAL_ADC_GetValue(&hnucleo_Adc);
  }
 
  if((KeyConvertedValue > 2010) && (KeyConvertedValue < 2090))
  {
    state = JOY_UP;
  }
  else if((KeyConvertedValue > 680) && (KeyConvertedValue < 780))
  {
    state = JOY_RIGHT;
  }
  else if((KeyConvertedValue > 1270) && (KeyConvertedValue < 1350))
  {
    state = JOY_SEL;
  }
  else if((KeyConvertedValue > 50) && (KeyConvertedValue < 130))
  {
    state = JOY_DOWN;
  }
  else if((KeyConvertedValue > 3570) && (KeyConvertedValue < 3800))
  {
    state = JOY_LEFT;
  }
  else
  {
    state = JOY_NONE;
  }
  
  /* Loop while a key is pressed */
  if(state != JOY_NONE)
  { 
    KeyConvertedValue = HAL_ADC_GetValue(&hnucleo_Adc);  
  }
  /* Return the code of the Joystick key pressed */
  return state;
}
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
