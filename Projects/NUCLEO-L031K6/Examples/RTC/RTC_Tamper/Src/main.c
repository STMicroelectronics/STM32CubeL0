/**
  ******************************************************************************
  * @file    RTC/RTC_Tamper/Src/main.c
  * @author  MCD Application Team
  * @brief   This sample code shows how to use STM32L0xx RTC HAL API to write/read
  *          data to/from RTC Backup data registers and demonstrates the Tamper
  *          detection feature.
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

/** @addtogroup STM32L0xx_HAL_Examples
  * @{
  */

/** @addtogroup RTC_Tamper
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* RTC handler declaration */
RTC_HandleTypeDef RtcHandle;

__IO FlagStatus TamperStatus = RESET;

/* Backup registers table */
uint32_t aBKPDataReg[BACKUP_COUNT] =
{
  RTC_BKP_DR0, RTC_BKP_DR1, RTC_BKP_DR2,
  RTC_BKP_DR3, RTC_BKP_DR4
};


/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  GPIO_InitTypeDef  GPIO_InitStruct;
  uint32_t index = 0;
  RTC_TamperTypeDef  stamperstructure;
  
  /* STM32L0xx HAL library initialization:
       - Configure the Flash prefetch, Flash preread and Buffer caches
       - Systick timer is configured by default as source of time base, but user 
             can eventually implement his proper time base source (a general purpose 
             timer for example or other time source), keeping in mind that Time base 
             duration should be kept 1ms since PPP_TIMEOUT_VALUEs are defined and 
             handled in milliseconds basis.
       - Low Level Initialization
     */
  HAL_Init();

  /* Configure the system clock to 2 MHz */
  SystemClock_Config();

  /* Configure LED3 */
  BSP_LED_Init(LED3);

  /* Configure PA.02 (Arduino A7) button */
  GPIO_InitStruct.Pin = GPIO_PIN_2;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  
  /* Enable GPIOA clock */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  /*##-1- Configure the RTC peripheral #######################################*/
  /* Configure RTC prescaler and RTC data registers */
  /* RTC configured as follows:
      - Hour Format    = Format 24
      - Asynch Prediv  = Value according to source clock
      - Synch Prediv   = Value according to source clock
      - OutPut         = Output Disable
      - OutPutPolarity = High Polarity
      - OutPutType     = Open Drain */
  RtcHandle.Instance            = RTC;
  RtcHandle.Init.HourFormat     = RTC_HOURFORMAT_24;
  RtcHandle.Init.AsynchPrediv   = RTC_ASYNCH_PREDIV;
  RtcHandle.Init.SynchPrediv    = RTC_SYNCH_PREDIV;
  RtcHandle.Init.OutPut         = RTC_OUTPUT_DISABLE;
  RtcHandle.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  RtcHandle.Init.OutPutType     = RTC_OUTPUT_TYPE_OPENDRAIN;
  
  if (HAL_RTC_Init(&RtcHandle) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }

  /*##-2- Configure RTC Tamper ###############################################*/
  stamperstructure.Tamper                       = RTC_TAMPER_3;
  stamperstructure.Trigger                      = RTC_TAMPERTRIGGER_FALLINGEDGE;
  stamperstructure.Filter                       = RTC_TAMPERFILTER_DISABLE;
  stamperstructure.SamplingFrequency            = RTC_TAMPERSAMPLINGFREQ_RTCCLK_DIV32768;
  stamperstructure.PrechargeDuration            = RTC_TAMPERPRECHARGEDURATION_1RTCCLK;
  stamperstructure.TamperPullUp                 = RTC_TAMPER_PULLUP_ENABLE;
  stamperstructure.TimeStampOnTamperDetection   = RTC_TIMESTAMPONTAMPERDETECTION_DISABLE;
  stamperstructure.NoErase                      = RTC_TAMPER_ERASE_BACKUP_ENABLE;
  stamperstructure.MaskFlag                     = RTC_TAMPERMASK_FLAG_DISABLE;
  stamperstructure.Interrupt                    = RTC_TAMPER3_INTERRUPT;

  if (HAL_RTCEx_SetTamper_IT(&RtcHandle, &stamperstructure) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }

  /* Clear the Tamper interrupt pending bit */
  __HAL_RTC_TAMPER_CLEAR_FLAG(&RtcHandle,RTC_FLAG_TAMP3F);

  /*##-3- Write Data on the Back Up registers ################################*/
  for (index = 0; index < BACKUP_COUNT; index++)
  {
    HAL_RTCEx_BKUPWrite(&RtcHandle, aBKPDataReg[index], 0xDF59 + (index * 0x5A));
  }

  /*##-4- Check Data is stored on the Back Up registers ######################*/
  for (index = 0; index < BACKUP_COUNT; index++)
  {
    if (HAL_RTCEx_BKUPRead(&RtcHandle, aBKPDataReg[index]) != (0xDF59 + (index * 0x5A)))
    {
      Error_Handler();
    }
  }

  /* Reset flag after writing of backup register in order to wait for new button press */
  TamperStatus = RESET;

  /*##-5- Wait for the tamper button is pressed ##############################*/
  while (TamperStatus != SET)
  {
    /* Toggle LED3 with a period of 1s */
    BSP_LED_Toggle(LED3);

    /* Delay */
    HAL_Delay(1000);
  }

  /*##-6- Deactivate the tamper                 ##############################*/
  HAL_RTCEx_DeactivateTamper(&RtcHandle, RTC_TAMPER_3);
    
  /*##-7- Check Data is cleared on the Back Up registers #####################*/
  for (index = 0; index < BACKUP_COUNT; index++)
  {
    if (HAL_RTCEx_BKUPRead(&RtcHandle, aBKPDataReg[index]) != 0x00)
    {
      Error_Handler();
    }
  }

  /* Infinite loop */
  while (1)
  {
    /* Turn LED3 on */
    BSP_LED_Toggle(LED3);

    /* Delay */
    HAL_Delay(100);
  }
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = MSI
  *            SYSCLK(Hz)                     = 2000000
  *            HCLK(Hz)                       = 2000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 1
  *            APB2 Prescaler                 = 1
  *            Flash Latency(WS)              = 0
  *            Main regulator output voltage  = Scale3 mode
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  
  /* Enable MSI Oscillator */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_5;
  RCC_OscInitStruct.MSICalibrationValue=0x00;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct)!= HAL_OK)
  {
    /* Initialization Error */
    while(1); 
  }
  
  /* Select MSI as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;  
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0)!= HAL_OK)
  {
    /* Initialization Error */
    while(1); 
  }
  /* Enable Power Control clock */
  __HAL_RCC_PWR_CLK_ENABLE();
  
  /* The voltage scaling allows optimizing the power consumption when the device is 
     clocked below the maximum system frequency, to update the voltage scaling value 
     regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
  
}


/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void Error_Handler(void)
{
  /* Turn LED3 on */
  BSP_LED_On(LED3);
  while (1)
  {
  }
}

/**
  * @brief  Tamper event callback function
  * @param  RTC handle
  * @retval None
  */
void HAL_RTCEx_Tamper3EventCallback(RTC_HandleTypeDef *hrtc)
{
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/**
  * @}
  */
