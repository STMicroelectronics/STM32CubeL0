/**
  ******************************************************************************
  * @file    Examples_LL/RNG/RNG_GenerateRandomNumbers/Src/main.c
  * @author  MCD Application Team
  * @brief   This example describes how to use RNG peripheral for generating random
  *          numbers using the STM32L0xx RNG LL API.
  *          Peripheral initialization done using LL unitary services functions.
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

/** @addtogroup STM32L0xx_LL_Examples
  * @{
  */

/** @addtogroup RNG_GenerateRandomNumbers
  * @{
  */

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#if (USE_TIMEOUT == 1)
#define RNG_GENERATION_TIMEOUT   20
#endif /* USE_TIMEOUT */

#define    NB_OF_GENERATED_RANDOM_NUMBERS      8       /* Nb of Random numbers generated after eash User button press */

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
#if (USE_TIMEOUT == 1)
uint32_t Timeout = 0; /* Variable used for Timeout management */
#endif /* USE_TIMEOUT */
__IO uint8_t ubButtonPress = 0;

/* Array used for storing generated Random 32bit Numbers */
__IO uint32_t aRandom32bit[NB_OF_GENERATED_RANDOM_NUMBERS];



/* Private function prototypes -----------------------------------------------*/
void     SystemClock_Config(void);
void     Configure_RNG(void);
void     RandomNumbersGeneration(void);
void     LED_Init(void);
void     LED_On(void);
void     LED_Blinking(uint32_t Period);
void     UserButton_Init(void);
void     WaitForUserButtonPress(void);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  /* Configure the system clock to 2.097 MHz */
  SystemClock_Config();

  /* Initialize LED2 */
  LED_Init();

  /* Initialize User push-button in EXTI mode */
  UserButton_Init();

  /* Configure RNG (RNG IP configuration : Clock enabling) */
  Configure_RNG();

  /* Wait for User push-button press to trigger random numbers generation */
  WaitForUserButtonPress();

  /* Generate Random Numbers series */
  RandomNumbersGeneration();

  /* Infinite loop */
  while (1)
  {
  }
}

/**
  * @brief  This function configures RNG Instance.
  * @note   This function is used to :
  *         - Enable peripheral clock for RNG.
  * @param  None
  * @retval None
  */
void Configure_RNG(void)
{
  /*  Enable peripheral clock for RNG                     *********************/
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_RNG);
  
  /* L0xx devices need to enable the VREFINT when using HSI48 */
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
  LL_SYSCFG_VREFINT_EnableHSI48();

  /* Enable HSI48 only if disabled.*/
  if (LL_RCC_HSI48_IsReady() == 0)
  {
    LL_RCC_HSI48_Enable();
#if (USE_TIMEOUT == 1)
    Timeout = LSE_TIMEOUT_VALUE;
#endif /* USE_TIMEOUT */
    while (LL_RCC_HSI48_IsReady() != 1)
    {
#if (USE_TIMEOUT == 1)
      if (LL_SYSTICK_IsActiveCounterFlag()) 
      {
        Timeout --;
      }
      if (Timeout == 0)
      {
        /* LSE activation error */
        LED_Blinking(LED_BLINK_ERROR);
      }  
#endif /* USE_TIMEOUT */
    }
  }

  /*  Choose HSI48 source as the 48 MHz clock is needed for the RNG 
      Linear Feedback Shift Register */
  LL_RCC_SetRNGClockSource(LL_RCC_RNG_CLKSOURCE_HSI48);
}

/**
  * @brief  This function performs several random numbers generation.
  * @note   Generated random numbers are stored in global variable array, so that
  *         generated values could be observed by user by watching variable content
  *         in specific debugger window
  * @param  None
  * @retval None
  */
void RandomNumbersGeneration(void)
{
  register uint8_t index = 0;

  /* Initialize random numbers generation */
  LL_RNG_Enable(RNG);

  /* Generate Random 32bit Numbers */
  for(index = 0; index < NB_OF_GENERATED_RANDOM_NUMBERS; index++)
  {
#if (USE_TIMEOUT == 1)
    Timeout = RNG_GENERATION_TIMEOUT;
#endif /* USE_TIMEOUT */

    /* Wait for DRDY flag to be raised */
    while (!LL_RNG_IsActiveFlag_DRDY(RNG))
    {
#if (USE_TIMEOUT == 1)
      /* Check Systick counter flag to decrement the time-out value */
      if (LL_SYSTICK_IsActiveCounterFlag()) 
      { 
        if(Timeout-- == 0)
        {
          /* Time-out occurred. Set LED to blinking mode */
          LED_Blinking(LED_BLINK_SLOW);
        }
      } 
#endif /* USE_TIMEOUT */
    }

    /* Check if error occurs */
    if (   (LL_RNG_IsActiveFlag_CECS(RNG) )
        || (LL_RNG_IsActiveFlag_SECS(RNG))  )
    {
      /* Clock or Seed Error detected. Set LED to blinking mode (Error type)*/
      LED_Blinking(LED_BLINK_ERROR);
    }
    
    /* Otherwise, no error detected : Value of generated random number could be retrieved
       and stored in dedicated array */
    aRandom32bit[index] = LL_RNG_ReadRandData32(RNG);
  }

  /* Stop random numbers generation */
  LL_RNG_Disable(RNG);

  /* Values of Generated Random numbers are now available in aRandom32bit array.
     LED2 is turned on */
  LED_On();
}

/**
  * @brief  Initialize LED2.
  * @param  None
  * @retval None
  */
void LED_Init(void)
{
  /* Enable the LED2 Clock */
  LED2_GPIO_CLK_ENABLE();

  /* Configure IO in output push-pull mode to drive external LED2 */
  LL_GPIO_SetPinMode(LED2_GPIO_PORT, LED2_PIN, LL_GPIO_MODE_OUTPUT);
  /* Reset value is LL_GPIO_OUTPUT_PUSHPULL */
  //LL_GPIO_SetPinOutputType(LED2_GPIO_PORT, LED2_PIN, LL_GPIO_OUTPUT_PUSHPULL);
  /* Reset value is LL_GPIO_SPEED_FREQ_LOW */
  //LL_GPIO_SetPinSpeed(LED2_GPIO_PORT, LED2_PIN, LL_GPIO_SPEED_FREQ_LOW);
  /* Reset value is LL_GPIO_PULL_NO */
  //LL_GPIO_SetPinPull(LED2_GPIO_PORT, LED2_PIN, LL_GPIO_PULL_NO);
}

/**
  * @brief  Turn-on LED2.
  * @param  None
  * @retval None
  */
void LED_On(void)
{
  /* Turn LED2 on */
  LL_GPIO_SetOutputPin(LED2_GPIO_PORT, LED2_PIN);
}

/**
  * @brief  Set LED2 to Blinking mode for an infinite loop (toggle period based on value provided as input parameter).
  * @param  Period : Period of time (in ms) between each toggling of LED
  *   This parameter can be user defined values. Pre-defined values used in that example are :
  *     @arg LED_BLINK_FAST : Fast Blinking
  *     @arg LED_BLINK_SLOW : Slow Blinking
  *     @arg LED_BLINK_ERROR : Error specific Blinking
  * @retval None
  */
void LED_Blinking(uint32_t Period)
{
  /* Toggle LED2 in an infinite loop */
  while (1)
  {
    LL_GPIO_TogglePin(LED2_GPIO_PORT, LED2_PIN);  
    LL_mDelay(Period);
  }
}

/**
  * @brief  Configures User push-button in GPIO or EXTI Line Mode.
  * @param  None 
  * @retval None
  */
void UserButton_Init(void)
{
  /* Enable the BUTTON Clock */
  USER_BUTTON_GPIO_CLK_ENABLE();
  
  /* Configure GPIO for BUTTON */
  LL_GPIO_SetPinMode(USER_BUTTON_GPIO_PORT, USER_BUTTON_PIN, LL_GPIO_MODE_INPUT);
  LL_GPIO_SetPinPull(USER_BUTTON_GPIO_PORT, USER_BUTTON_PIN, LL_GPIO_PULL_NO);

  /* Connect External Line to the GPIO*/
  USER_BUTTON_SYSCFG_SET_EXTI();

  /* Enable a rising trigger External lines 4 to 15 Interrupt */
  USER_BUTTON_EXTI_LINE_ENABLE();
  USER_BUTTON_EXTI_FALLING_TRIG_ENABLE();

  /* Configure NVIC for USER_BUTTON_EXTI_IRQn */
  NVIC_SetPriority(USER_BUTTON_EXTI_IRQn, 0x03);  
  NVIC_EnableIRQ(USER_BUTTON_EXTI_IRQn); 
}

/**
  * @brief  Wait for User push-button press to start transfer.
  * @param  None 
  * @retval None
  */
  /*  */
void WaitForUserButtonPress(void)
{
  while (ubButtonPress == 0)
  {
    LL_GPIO_TogglePin(LED2_GPIO_PORT, LED2_PIN);
    LL_mDelay(LED_BLINK_FAST);
  }
  
  /* Turn LED2 off */
  LL_GPIO_ResetOutputPin(LED2_GPIO_PORT, LED2_PIN);
}


/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = MSI
  *            SYSCLK(Hz)                     = 2097000
  *            HCLK(Hz)                       = 2097000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 1
  *            APB2 Prescaler                 = 1
  *            Flash Latency(WS)              = 0
  *            Main regulator output voltage  = Scale3 mode
  * @retval None
  */
void SystemClock_Config(void)
{
  /* MSI configuration and activation */
  LL_RCC_PLL_Disable();
  /* Set new latency */
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);

  LL_RCC_MSI_Enable();
  while(LL_RCC_MSI_IsReady() != 1) 
  {
  };
  LL_RCC_MSI_SetRange(LL_RCC_MSIRANGE_5);  
  LL_RCC_MSI_SetCalibTrimming(0x0);

  /* Sysclk activation  */
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_MSI);
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_MSI) 
  {
  };
  
  /* Set APB1 & APB2 prescaler*/
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);

  /* Set systick to 1ms in using frequency set to 2MHz */
  LL_Init1msTick(2097000);

  /* Update CMSIS variable (which can be updated also through SystemCoreClockUpdate function) */
  LL_SetSystemCoreClock(2097000);  

  /* Enable Power Control clock */
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);
  /* The voltage scaling allows optimizing the power consumption when the device is 
     clocked below the maximum system frequency, to update the voltage scaling value 
     regarding system frequency refer to product datasheet.  */
  LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE3);
}


/******************************************************************************/
/*   IRQ HANDLER TREATMENT Functions                                          */
/******************************************************************************/
/**
  * @brief  Function to manage User push-button
  * @param  None
  * @retval None
  */
void UserButton_Callback(void)
{
  /* Update User push-button variable : to be checked in waiting loop in main program */
  ubButtonPress = 1;
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
     ex: printf("Wrong parameters value: file %s on line %d", file, line) */

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
