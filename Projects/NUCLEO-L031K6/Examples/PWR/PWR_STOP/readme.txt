/**
  @page PWR_STOP Power Stop Mode Example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    PWR/PWR_STOP/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the Power Stop Mode example.
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

How to enter the Stop mode and wake up from this mode by using the RTC wakeup 
timer event or an interrupt.

This is achieved using PA.12 (Arduino D2) configured to generate an interrupt on falling edge.
LED3 is ON during RUN mode and OFF during STOP mode.

In the associated software
  - the system clock is set to 2 MHz.
  - the PA.12 (Arduino D2) is configured to generate an interrupt on falling edge.
  - the SysTick is programmed to generate an interrupt each 1 ms. 

Firstly, remove jumper between PA.12 (Arduino D2) and GND and reset the board. LED3 is ON.
The system enters STOP mode after 5s and will wait for a falling edge on PA.12 (Arduino D2). LED3 is OFF. 
Put jumper between PA.12 (Arduino D2) and GND to wake-up the system. 
Then remove it.
Current consumption could be monitored through an ampere-meter.
After the system woken up from STOP, the clock system is reconfigured because the default clock 
after wake up is the MSI.

This behavior is repeated in an infinite loop.
 
    - STOP Mode
    ============ 
          - Regulator in LP mode
          - VREFINT OFF with fast wakeup enabled
          - MSI as SysClk after Wake Up
          - No IWDG
          - Wakeup using EXTI Line (PA.12 (Arduino D2))

@note To measure the current consumption in STOP mode, please refer to 
      @subpage PWR_CurrentConsumption example.

@note This example can not be used in DEBUG mode, this is due to the fact 
      that the Cortex-M0+ core is no longer clocked during low power mode 
      so debugging features are disabled

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.
      
@note  Care must be taken when HAL_RCCEx_PeriphCLKConfig() is used to select the RTC clock source; in this 
       case the Backup domain will be reset in order to modify the RTC Clock source, as consequence RTC  
       registers (including the backup registers) and RCC_BDCR register are set to their reset values.

@par Directory contents 

  - PWR/PWR_STOP/Inc/stm32l0xx_conf.h         HAL Configuration file
  - PWR/PWR_STOP/Inc/stm32l0xx_it.h           Header for stm32l0xx_it.c
  - PWR/PWR_STOP/Inc/main.h                   Header file for main.c
  - PWR/PWR_STOP/Src/system_stm32l0xx.c       STM32L0xx system clock configuration file
  - PWR/PWR_STOP/Src/stm32l0xx_it.c           Interrupt handlers
  - PWR/PWR_STOP/Src/main.c                   Main program
  - PWR/PWR_STOP/Src/stm32l0xx_hal_msp.c      HAL MSP module

@par Hardware and Software environment

  - STM32L031K6-Nucleo Set-up :
    - Use jumper between PA.12 (Arduino D2) and GND when required.
    - Connect an ampere-meter to JP1 instead of the jumper to measure the IDD current.
   
  - This example runs on STM32L031xx and STM32L041xx devices.

  - This example has been tested with STMicroelectronics STM32L031K6-Nucleo
    evaluation board and can be easily tailored to any other supported device 
    and development board.
    
@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
