/**
  @page PWR_STANDBY PWR standby example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    PWR/PWR_STANDBY/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the PWR STANDBY example.
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
  @endverbatim

@par Example Description 
 
How to enter the Standby mode and wake up from this mode by using an external 
reset or the WKUP pin.

This example shows also how to configure the stm32l0xx system to measure 
STANDBY mode current consumption.

In the associated software
  - the system clock is set to 2 MHz.
  - PC.13 is configured to wake up the system after entering Standby mode.
  - the SysTick is programmed to generate an interrupt each 1 ms.
  
The system enters STANDBY mode after 5s and will wait for injecting 3.3V on PC.13
PWR_WAKEUP_PIN2. Current consumption could be monitored through an amperemeter connected to JP10.

    - STANDBY Mode 
    ===============
            - VREFINT OFF with fast wakeup enabled
            - No IWDG
            - Wakeup using PWR_WAKEUP_PIN2 (PC.13)

@note This example can not be used in DEBUG mode, this is due to the fact 
      that the Cortex-M0+ core is no longer clocked during low power mode 
      so debugging features are disabled

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - PWR/PWR_STANDBY/Inc/stm32l0xx_conf.h         HAL Configuration file
  - PWR/PWR_STANDBY/Inc/stm32l0xx_it.h           Header for stm32l0xx_it.c
  - PWR/PWR_STANDBY/Inc/main.h                   Header file for main.c
  - PWR/PWR_STANDBY/Src/system_stm32l0xx.c       STM32L0xx system clock configuration file
  - PWR/PWR_STANDBY/Src/stm32l0xx_it.c           Interrupt handlers
  - PWR/PWR_STANDBY/Src/main.c                   Main program
  - PWR/PWR_STANDBY/Src/stm32l0xx_hal_msp.c      HAL MSP module

@par Hardware and Software environment

  - STM32L073Z-EVAL Set-up
    - Wkup/Tamper push button is connected to PC.13, 
      press it will put PC.13 to 3.3V and awakes the board.
    - Connect an amperemeter to JP10 to measure the IDD current

  - This example runs on STM32L073xx devices
      
  - This example has been tested with STMicroelectronics STM32L073Z-EVAL
    evaluation board and can be easily tailored to any other supported device 
    and development board.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example



 */
