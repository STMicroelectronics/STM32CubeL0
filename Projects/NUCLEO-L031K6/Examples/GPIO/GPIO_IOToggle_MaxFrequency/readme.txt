/**
  @page GPIO_IOToggle_MaxFrequency GPIO IO Toggle Max Frequency example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    GPIO/GPIO_IOToggle_MaxFrequency/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the GPIO IO Toggle example.
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

How to configure and use GPIOs.

In order to be as fast as possible, GPIOA (Pin0) is accessed directly through 
its hardware registers inside an infinite loop.
 
You can check on the oscilloscope the value of GPIOA (Pin0) output on CN4 (Pin12) 

In this example, HCLK is configured at 32 MHz.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - GPIO/GPIO_IOToggle_MaxFrequency/Inc/stm32l0xx_hal_conf.h HAL configuration file
  - GPIO/GPIO_IOToggle_MaxFrequency/Inc/stm32l0xx_it.h       Interrupt handlers header file
  - GPIO/GPIO_IOToggle_MaxFrequency/Inc/main.h               Header for main.c module  
  - GPIO/GPIO_IOToggle_MaxFrequency/Src/stm32l0xx_it.c       Interrupt handlers
  - GPIO/GPIO_IOToggle_MaxFrequency/Src/main.c               Main program
  - GPIO/GPIO_IOToggle_MaxFrequency/Src/system_stm32l0xx.c   STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L031xx devices.
    
  - This example has been tested with STM32L031K6-Nucleo board and can be
    easily tailored to any other supported device and development board.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
