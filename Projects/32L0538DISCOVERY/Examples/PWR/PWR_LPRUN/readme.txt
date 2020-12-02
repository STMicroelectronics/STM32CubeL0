/**
  @page PWR_LPRUN Low Power run Mode Example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    PWR/PWR_LPRUN/readme.txt
  * @author  MCD Application Team
  * @brief   This example shows how to use STM32L0xx PWR HAL API to enter the
  *          system to Low Power Run mode and exit from this mode using Key 
  *          push button.
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

How to enter and exit the Low-power run mode.

This example shows also how to configure the STM32L0xx system to measure 
LP Run mode current consumption.

In the associated software, the system clock is set to 32 KHz.

 @note This mode is achieved with the multispeed internal (MSI) RC oscillator set 
       to the lowspeed clock (max 131 kHz), execution from SRAM or Flash memory, 
       and internal regulator in low-power mode to minimize the regulator's 
       operating current.

In the associated software    
  - the system clock is set to 32 KHz
  - the Key push button (PA.00) is used to enter and exit the Low Power Run mode.

The system enters LP RUN mode by pressing User push button (PA.00) and will wait 
for the same button to be pressed to exit LP RUN mode. Current consumption could 
be monitored through an ampermeter.

This behavior is repeated in an infinite loop.
 - LED3 ON: HAL configuration failed (system will go to an infinite loop)
 
    - Low Power Run Mode from FLASH
    ================================
          - Regulator in LP mode
          - System Running at MSI (~32KHz)
          - Flash 0 wait state  
          - MSI Range 0
          - Voltage Range 2
          - Code running from Internal FLASH
          - All peripherals OFF
          - Wakeup using Key Button PA.00

 @note This example can not be used in DEBUG mode, this is due to the fact 
       that the Cortex-M0+ core is no longer clocked during low power mode 
       so debugging features are disbaled


@par Directory contents  

  - PWR/PWR_LPRUN/Inc/stm32l0xx_conf.h     Library Configuration file
  - PWR/PWR_LPRUN/Inc/stm32l0xx_it.h       Header for stm32l0xx_it.c
  - PWR/PWR_LPRUN/Inc/main.h               header file for main.c
  - PWR/PWR_LPRUN/Src/system_stm32l0xx.c   STM32L0xx system clock configuration file
  - PWR/PWR_LPRUN/Src/stm32l0xx_it.c       Interrupt handlers
  - PWR/PWR_LPRUN/Src/main.c               Main program
  - PWR/PWR_LPRUN/Src/stm32l0xx_hal_msp.c  HAL MSP module

@par Hardware and Software environment

  - This example runs on STM32L053xx devices.
    
  - This example has been tested with STM32L0538-DISCO RevB  board and can be
    easily tailored to any other supported device and development board.

  - STM32L0538-DISCO Set-up
    - Use LED3 connected to PB.04 pin
    - Use the Key push-button connected to pin PA.00
    - Disconnect the JP4, then measure the IDD current between the JP4 position 1-2.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
