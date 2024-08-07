/**
  @page PWR_LPSLEEP Low Power sleep Mode Example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    PWR/PWR_LPSLEEP/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the Low Power Sleep Mode example.
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

How to enter the Low-power sleep mode and wake up from this mode by using 
an interrupt.

This example shows also how to configure the STM32L0xx system to measure 
LP SLEEP mode current consumption.

The Low power sleep mode is entered by configuring the voltage regulator in low power
mode, and by executing the WFI (wait for interrupt) or WFE (wait for event) instructions. In
this mode, the Flash memory is not available but the RAM memory remains available.

In this example, the WFI instruction is used to enter Low power sleep mode, any 
peripheral interrupt acknowledged by the nested vectored interrupt controller (NVIC) 
can wake up the device from Low power sleep mode.

In the associated software
  - the system clock is set to 32 KHz.
  - the EXTI_Line13 is configured to generate an interrupt on falling edge.

 @note In Low power sleep mode, the system frequency should not exceed MSI range1.
 @note Low power sleep mode can only be entered when VCORE is in range 2. 

The system enters LP SLEEP mode by pressing the User push button and will wait 
for the same button to be pressed to wake up from LP SLEEP mode. Current consumption 
could be monitored through an amperemeter.

This behavior is repeated in an infinite loop.
 - LED2 ON: HAL configuration failed (system will go to an infinite loop)
 
    - Low Power Sleep Mode
    =======================
          - Regulator in LP mode
          - System Running at MSI (~32KHz)
          - Flash 0 wait state  
          - Voltage Range 2
          - Code running from Internal FLASH
          - All peripherals OFF
          - VDD from 1.65V to 3.6V
          - Wakeup using EXTI Line (Key Button PC.13)     

 @note This example can not be used in DEBUG mode, this is due to the fact 
       that the Cortex-M0+ core is no longer clocked during low power mode 
       so debugging features are disabled


@par Directory contents  

  - PWR/PWR_LPSLEEP/Inc/stm32l0xx_conf.h     Library Configuration file
  - PWR/PWR_LPSLEEP/Inc/stm32l0xx_it.h       Header for stm32l0xx_it.c
  - PWR/PWR_LPSLEEP/Inc/main.h               header file for main.c
  - PWR/PWR_LPSLEEP/Src/system_stm32l0xx.c   STM32L0xx system clock configuration file
  - PWR/PWR_LPSLEEP/Src/stm32l0xx_it.c       Interrupt handlers
  - PWR/PWR_LPSLEEP/Src/main.c               Main program
  - PWR/PWR_LPSLEEP/Src/stm32l0xx_hal_msp.c  HAL MSP module

@par Hardware and Software environment

  - This example runs on STM32L051xx, STM32L052xx, STM32L053xx STM32L062xx and 
    STM32L063xx device lines RevZ
    
  - This example has been tested with STM32L053R8-Nucleo RevC  board and can be
    easily tailored to any other supported device and development board.

  - STM32L053R8-Nucleo Set-up
    - Use LED2 connected to PA.05 pin
    - Use the Key push-button connected to pin PC13 (EXTI_Line13)
    - Connect an amperemeter to JP6 to measure the IDD current

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example



 */
