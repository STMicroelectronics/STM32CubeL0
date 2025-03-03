/**
  ******************************************************************************
  * @file    GPIO/GPIO_IOToggle_MaxFrequency/Src/main.c
  * @author  MCD Application Team
  * @brief   This example describes how to configure and use GPIOs through
  *          the STM32L0xx HAL API.
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

/** @addtogroup GPIO_IOToggle_MaxFrequency
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static GPIO_InitTypeDef  GPIO_InitStruct;

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

  /* STM32L0xx HAL library initialization:
       - Configure the Flash prefetch
       - Systick timer is configured by default as source of time base, but user 
         can eventually implement his proper time base source (a general purpose 
         timer for example or other time source), keeping in mind that Time base 
         duration should be kept 1ms since PPP_TIMEOUT_VALUEs are defined and 
         handled in milliseconds basis.
       - Low Level Initialization
     */
  HAL_Init();

  /* Configure the system clock to 32 MHz */
  SystemClock_Config();
  
   /* -1- Enable GPIOE Clock (to be able to program the configuration registers) */
  __HAL_RCC_GPIOE_CLK_ENABLE();

  /* -2- Configure PE5 (GPIOE-5) in output push-pull mode */
  GPIO_InitStruct.Pin = (GPIO_PIN_5);
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH  ;
  
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /* -3- Toggle PE5 (GPIOE-5) in an infinite loop */
  while (1)
  {
    /*Set PE5 (GPIOE-5)*/
    GPIOE->BSRR = GPIO_PIN_5;
     /*Reset PE5 (GPIOE-5)*/
    GPIOE->BRR = GPIO_PIN_5 ;
       /*Set PE5 (GPIOE-5)*/
    GPIOE->BSRR = GPIO_PIN_5;
     /*Reset PE5 (GPIOE-5)*/
    GPIOE->BRR = GPIO_PIN_5 ;
       /*Set PE5 (GPIOE-5)*/
    GPIOE->BSRR = GPIO_PIN_5;
     /*Reset PE5 (GPIOE-5)*/
    GPIOE->BRR = GPIO_PIN_5 ;
       /*Set PE5 (GPIOE-5)*/
    GPIOE->BSRR = GPIO_PIN_5;
     /*Reset PE5 (GPIOE-5)*/
    GPIOE->BRR = GPIO_PIN_5 ;
       /*Set PE5 (GPIOE-5)*/
    GPIOE->BSRR = GPIO_PIN_5;
     /*Reset PE5 (GPIOE-5)*/
    GPIOE->BRR = GPIO_PIN_5 ;
       /*Set PE5 (GPIOE-5)*/
    GPIOE->BSRR = GPIO_PIN_5;
     /*Reset PE5 (GPIOE-5)*/
    GPIOE->BRR = GPIO_PIN_5 ;
       /*Set PE5 (GPIOE-5)*/
    GPIOE->BSRR = GPIO_PIN_5;
     /*Reset PE5 (GPIOE-5)*/
    GPIOE->BRR = GPIO_PIN_5 ;
       /*Set PE5 (GPIOE-5)*/
    GPIOE->BSRR = GPIO_PIN_5;
     /*Reset PE5 (GPIOE-5)*/
    GPIOE->BRR = GPIO_PIN_5 ;
       /*Set PE5 (GPIOE-5)*/
    GPIOE->BSRR = GPIO_PIN_5;
     /*Reset PE5 (GPIOE-5)*/
    GPIOE->BRR = GPIO_PIN_5 ;
       /*Set PE5 (GPIOE-5)*/
    GPIOE->BSRR = GPIO_PIN_5;
     /*Reset PE5 (GPIOE-5)*/
    GPIOE->BRR = GPIO_PIN_5 ;

  }



}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 32000000
  *            HCLK(Hz)                       = 32000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 1
  *            APB2 Prescaler                 = 1
  *            Flash Latency(WS)              = 1
  *            Main regulator output voltage  = Scale1 mode
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct ={0};
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  
  /* Enable Power Control clock */
  __HAL_RCC_PWR_CLK_ENABLE();
  
  /* The voltage scaling allows optimizing the power consumption when the device is 
     clocked below the maximum system frequency, to update the voltage scaling value 
     regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  
  /* Enable HSE Oscillator */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLSource   = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLState    = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLMUL      = RCC_PLL_MUL8;
  RCC_OscInitStruct.PLL.PLLDIV      = RCC_PLL_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct)!= HAL_OK)
  {
    /* Initialization Error */
    while(1); 
  }
  
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;  
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1)!= HAL_OK)
  {
    /* Initialization Error */
    while(1); 
  }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */

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
