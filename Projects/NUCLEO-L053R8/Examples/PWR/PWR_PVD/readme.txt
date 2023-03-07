/**
  @page PWR_PVD PWR Programmable Voltage Detector (PVD) example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    PWR/PWR_PVD/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the PWR Programmable Voltage Detector (PVD) example
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
How to configure the programmable voltage detector by using an external interrupt 
line. External DC supply must be used to supply Vdd.

In this example, EXTI line 16 is configured to generate an interrupt on each rising
or falling edge of the PVD output signal (which indicates that the Vdd voltage is
below the PVD threshold).
In the interrupt routine the LED2 is toggled every time the voltage drops below 
or above the target threshold.

In this example, the PVD detection level set to 2.5V.

If LED2 is toggling successively: This indicates that the system generates an error.

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - PWR/PWR_PVD/Inc/stm32l0xx_conf.h     Library Configuration file
  - PWR/PWR_PVD/Inc/stm32l0xx_it.h       Header for stm32l0xx_it.c
  - PWR/PWR_PVD/Inc/main.h               header file for main.c
  - PWR/PWR_PVD/Src/system_stm32l0xx.c   STM32L0xx system clock configuration file
  - PWR/PWR_PVD/Src/stm32l0xx_it.c       Interrupt handlers
  - PWR/PWR_PVD/Src/main.c               Main program
  - PWR/PWR_PVD/Src/stm32l0xx_hal_msp.c  HAL MSP module

@par Hardware and Software environment

  - This example runs on STM32L051xx, STM32L052xx, STM32L053xx STM32L062xx and 
    STM32L063xx device lines RevZ

  - This example has been tested with STMicroelectronics STM32L053R8-Nucleo board
    and can be easily tailored to any other supported device and development board.

  - STM32L053R8-Nucleo Set-up
    - Remove the jumper JP5
    - Apply an external voltage to the pin4 of CN6 
    - Use LED2 connected to PA.05 pin

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 */
