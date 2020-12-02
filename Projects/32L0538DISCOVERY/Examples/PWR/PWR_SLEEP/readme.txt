/**
  @page PWR_SLEEP Power Sleep Mode Example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    PWR/PWR_SLEEP/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the Power Sleep Mode example.
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
  @endverbatim

@par Example Description

How to enter the Sleep mode and wake up from this mode by using an interrupt.

This example shows also how to configure the STM32L0xx system to measure 
SLEEP mode current consumption.

In the associated software, the system clock is set to 16 MHz, the SysTick is 
programmed to generate an interrupt each 1 ms.

In the associated software
  - the system clock is set to 16 MHz
  - the EXTI_Line0 is configured to generate an interrupt on falling edge.
  - the SysTick is programmed to generate an interrupt each 1 ms. 

The system enters SLEEP mode after 5s and will wait for the Key push button is pressed
to wake up from SLEEP mode. Current consumption could be monitored through an ampermeter.

This behavior is repeated in an infinite loop.
 - LED3 ON: HAL configuration failed (system will go to an infinite loop)
 
    - SLEEP Mode
    ============ 
          - System Running at HSI (16MHz)
          - Flash 1 wait state  
          - Voltage Range 2
          - Code running from Internal FLASH
          - Wakeup using EXTI Line (Key Button PA.00)


 @note This example can not be used in DEBUG mode, this is due to the fact 
       that the Cortex-M0+ core is no longer clocked during low power mode 
       so debugging features are disbaled
       
 @note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
       based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
       a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
       than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
       To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
 @note The example needs to ensure that the SysTick time base is always set to 1 millisecond
       to have correct HAL operation.

@par Directory contents  

  - PWR/PWR_SLEEP/Inc/stm32l0xx_conf.h     Library Configuration file
  - PWR/PWR_SLEEP/Inc/stm32l0xx_it.h       Header for stm32l0xx_it.c
  - PWR/PWR_SLEEP/Inc/main.h               header file for main.c
  - PWR/PWR_SLEEP/Src/system_stm32l0xx.c   STM32L0xx system clock configuration file
  - PWR/PWR_SLEEP/Src/stm32l0xx_it.c       Interrupt handlers
  - PWR/PWR_SLEEP/Src/main.c               Main program
  - PWR/PWR_SLEEP/Src/stm32l0xx_hal_msp.c  HAL MSP module

@par Hardware and Software environment

  - This example runs on STM32L053xx devices.
    
  - This example has been tested with STM32L0538-DISCO RevB  board and can be
    easily tailored to any other supported device and development board.

  - STM32L0538-DISCO Set-up
    - Use LED3 connected to PB.04 pin
    - Use the Key push-button connected to pin PA0 (EXTI_Line0)
    - Disconnect the JP4, then measure the IDD current between the JP4 position 1-2

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
