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
  - the EXTI_Line0 is configured to generate an interrupt on falling edge.

 @note In Low power sleep mode, the system frequency should not exceed MSI range1.
 @note Low power sleep mode can only be entered when VCORE is in range 2. 

The system enters LP SLEEP mode by pressing the User push button and will wait 
for the same button to be pressed to wake up from LP SLEEP mode. Current consumption 
could be monitored through an ampermeter.

This behavior is repeated in an infinite loop.
 - LED3 ON: HAL configuration failed (system will go to an infinite loop)
 
    - Low Power Sleep Mode
    =======================
          - Regulator in LP mode
          - System Running at MSI (~32KHz)
          - Flash 0 wait state  
          - Voltage Range 2
          - Code running from Internal FLASH
          - All peripherals OFF
          - VDD from 1.65V to 3.6V
          - Wakeup using EXTI Line (Key Button PA.00)     

 @note This example can not be used in DEBUG mode, this is due to the fact 
       that the Cortex-M0+ core is no longer clocked during low power mode 
       so debugging features are disbaled


@par Directory contents  

  - PWR/PWR_LPSLEEP/Inc/stm32l0xx_conf.h     Library Configuration file
  - PWR/PWR_LPSLEEP/Inc/stm32l0xx_it.h       Header for stm32l0xx_it.c
  - PWR/PWR_LPSLEEP/Inc/main.h               header file for main.c
  - PWR/PWR_LPSLEEP/Src/system_stm32l0xx.c   STM32L0xx system clock configuration file
  - PWR/PWR_LPSLEEP/Src/stm32l0xx_it.c       Interrupt handlers
  - PWR/PWR_LPSLEEP/Src/main.c               Main program
  - PWR/PWR_LPSLEEP/Src/stm32l0xx_hal_msp.c  HAL MSP module

@par Hardware and Software environment

  - This example runs on STM32L053xx devices.
    
  - This example has been tested with STM32L0538-DISCO REVB board and can be
    easily tailored to any other supported device and development board.

  - STM32L0538-DISCO Set-up
    - Use LED3 connected to PB.04 pin
    - Use the Key push-button connected to pin PA.00 (EXTI_Line0)
    - Put the JP4 to position 2-3, then measure the IDD current
      between the JP4 position 1-2.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
