/**
  @page COMP_AnalogWatchdog Independent Watchdog Example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    COMP/COMP_AnalogWatchdog/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the Independent Watchdog Example.
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

How to use a pair of comparator peripherals to compare a voltage level applied on
a GPIO pin to two thresholds: the internal voltage reference (VREFINT) and a fraction
of the internal voltage reference (VREFINT/4), in interrupt mode.

  - The upper threshold is set to VREFINT = 1.22V
  - The lower threshold is set to VREFINT/4 = 1.22V/4 = 0.305V
  - The input voltage is configured to be connected to PB.04

If the input voltage is above the higher threshold, LD2 toggles quickly.
If the input voltage is under the lower threshold, LD2 toggles slowly.
If the input voltage is within the thresholds, the MCU remains in STOP mode.

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents  

  - COMP/COMP_AnalogWatchdog/Inc/stm32l0xx_hal_conf.h    HAL configuration file 
  - COMP/COMP_AnalogWatchdog/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - COMP/COMP_AnalogWatchdog/Inc/main.h                  Header for main.c module
  - COMP/COMP_AnalogWatchdog/Src/stm32l0xx_it.c          Interrupt handlers
  - COMP/COMP_AnalogWatchdog/Src/main.c                  Main program
  - COMP/COMP_AnalogWatchdog/Src/stm32l0xx_hal_msp.c     HAL MSP module 
  - COMP/COMP_AnalogWatchdog/Src/system_stm32l0xx.c	     STM32L0xx system source file
     
@par Hardware and Software environment

  - This example runs on STM32L051xx, STM32L052xx, STM32L053xx STM32L062xx and 
    STM32L063xx device lines RevZ
    
  - This example has been tested with STM32L053R8-Nucleo RevC board and can be
    easily tailored to any other supported device and development board. 
        
  - STM32L053R8-Nucleo Set-up
    
       - Use LED2 connected to PA.5 pin
       - Apply an external voltage on COMP2 non inverting input PB.04 (pin D5 in CN9 connector)


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example
 
   

 */
 