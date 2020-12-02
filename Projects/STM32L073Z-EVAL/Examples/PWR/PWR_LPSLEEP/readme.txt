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
  - EXTI_Line4-15 is configured to generate an interrupt on falling edge.

 @note In Low power sleep mode, the system frequency should not exceed MSI range1.
 @note Low power sleep mode can only be entered when VCORE is in range 2. 

The system enters LP SLEEP mode by pressing the Wkup/Tamper push-button and will wait 
for the same button to be pressed to wake up from LP SLEEP mode. Current consumption 
could be monitored through an amperemeter.

This behaviour is repeated in an infinite loop.
 - LED3 ON during 1 second: indicates that device is in run mode, 
   then LED is turned off to be able to measure current and make a comparison
   versus low power sleep mode.
 - LED3 ON continuously: HAL configuration failed (system will go to an infinite loop)

    - Low Power Sleep Mode
    =======================
          - Regulator in LP mode
          - System Running at MSI (~32KHz)
          - Flash 0 wait state  
          - Voltage Range 2
          - Code running from Internal FLASH
          - All peripherals OFF
          - VDD from 1.65V to 3.6V
          - Wakeup using EXTI Line (Wkup/Tamper push-button PC.13)     

@note Debug using ST-Link is not possible during the execution of this example 
      because communication between ST-link and the device under test is done through UART.
      All GPIO pins are disabled (set to analog input mode), except one GPIO for Wkup/Tamper push-button,
      to reduce current consumption, including UART I/O pins.
      
          
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
      
@par Directory contents 

  - PWR/PWR_LPSLEEP/Inc/stm32l0xx_conf.h         HAL Configuration file
  - PWR/PWR_LPSLEEP/Inc/stm32l0xx_it.h           Header for stm32l0xx_it.c
  - PWR/PWR_LPSLEEP/Inc/main.h                   Header file for main.c
  - PWR/PWR_LPSLEEP/Src/system_stm32l0xx.c       STM32L0xx system clock configuration file
  - PWR/PWR_LPSLEEP/Src/stm32l0xx_it.c           Interrupt handlers
  - PWR/PWR_LPSLEEP/Src/main.c                   Main program

@par Hardware and Software environment

  - This example runs on STM32L07xx and STM32L08xx devices
    
      
  - This example has been tested with STMicroelectronics STM32L073Z-EVAL
    evaluation board and can be easily tailored to any other supported device 
    and development board.

  - STM32L073Z-EVAL Set-up
    - Use the Wkup/Tamper push-button connected to pin PC.13 (EXTI_Line4-15)
    - Connect an amperemeter to JP10 to measure the IDD current

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
