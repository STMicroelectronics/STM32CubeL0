/**
  @page PWR_STANDBY PWR STANDBY example

  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    PWR/PWR_STANDBY/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the PWR Standby example.
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

In the associated software, the system clock is set to 2 MHz.
The SysTick is programmed to generate an interrupt each 1 ms and in the SysTick
interrupt handler, LED2 is toggled in order to indicate whether the MCU is in Standby or Run mode.

After a reset (or wake-up from STANDBY mode), LED2 is ON and MCU is in RUN mode.
The system enters STANDBY mode after 5s, LED2 is OFF.
A rising edge on wakeup pin WKUP1 PA.00 (connector CN8 pin A0 or CN7 pin 28) will
wake-up the system from STANDBY.
Alternatively, an external RESET of the board will lead to a system wake-up as well.
The LED2 restarts blinking in order to indicate the system was resumed from Standby mode.
These steps are repeated in an infinite loop.

LED2 is used to monitor the system state as follows:
 - LED2 toggling: system in Run mode
 - LED2 off : system in Standby mode


@note To measure the current consumption in Standby mode, remove JP6 jumper
      and connect an amperemeter to JP6 to measure IDD current.

@note This example can not be used in DEBUG mode due to the fact
      that the Cortex-M0+ core is no longer clocked during low power mode
      so debugging features are disabled.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.


@par Directory contents

  - PWR/PWR_STANDBY/Inc/stm32l0xx_hal_conf.h     HAL Configuration file
  - PWR/PWR_STANDBY/Inc/stm32l0xx_it.h           Header for stm32l0xx_it.c
  - PWR/PWR_STANDBY/Inc/main.h                   Header file for main.c
  - PWR/PWR_STANDBY/Src/system_stm32l0xx.c       STM32L0xx system clock configuration file
  - PWR/PWR_STANDBY/Src/stm32l0xx_it.c           Interrupt handlers
  - PWR/PWR_STANDBY/Src/main.c                   Main program
  - PWR/PWR_STANDBY/Src/stm32l0xx_hal_msp.c      HAL MSP module

@par Hardware and Software environment

  - This example runs on STM32L010RB devices


  - This example has been tested with STMicroelectronics STM32L010RB-Nucleo
    board and can be easily tailored to any other supported device
    and development board.

  - STM32L010RB-Nucleo Set-up
    - LED2 connected to PA.05 pin
    - Put a wire between PA.00 (connector CN8 pin A0 or CN7 pin 28) and 5V to generate
      a rising edge on PWR_WAKEUP_PIN1.

@par How to use it ?

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example



 */
