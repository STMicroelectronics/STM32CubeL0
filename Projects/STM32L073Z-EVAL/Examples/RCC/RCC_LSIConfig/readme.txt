/**
  @page RCC_LSIConfig RCC Clock Config example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    RCC/RCC_LSIConfig/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the RCC Clock Config example.
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

Enabling/disabling of the low-speed internal (LSI) RC oscillator (about 40 KHz)
at run time, using the RCC HAL API.

Board: STM32L073Z-EVAL (embeds a STM32L073VZ device)
Microcontroller Clock Output MCO1 Pin:PA.08

   _________________________                   _______________________ 
  |        ______CN10_______|                 |  _______________      |
  |       |RCC              |                 | |               | O   |
  |       |                 |                 | |   _   _   _   | O   |
  |       |(pin 23) MCO(PA8)|_________________| | _| |_| |_| |_ | --  |
  |       |                 |                 | |_______________| --  |    
  |       |                 |                 |                       |
  |       |                 |                 |_oscilloscope__________|
  |       |                 |                    
  |       |                 | 
  |       |_________________|  
  |                         |
  |                         |
  |_STM32_Board ____________|


In this example, after startup SYSCLK is configured using the PLL with
MSI as clock source, the Wkup/Tamper push-button (connected to EXTI_Line4-15)
is used to enable/disable LSI:
each time the Wkup/Tamper push-button is pressed, EXTI_Line4-15 interrupt is generated and the ISR
enables the LSI when it is off, disables it when it is on.

When only one LED is available on the Board
LED1 is toggling as follows according to LSI activation:
- when LSI is on, LED1 is emitting a double flash every half-second
- when LSI is off, LED1 is fast-toggling (every 100 ms) 

When 4 LEDs are available on the board
- when LSI is off, LED1 is toggling (every 300 ms)
- when LSI is on, LED3 is toggling (every 300 ms)

LSI clock waveform is available on the MCO1 pin PA.08 and can be captured
on an oscilloscope.

In case of configuration error, LED1 is slowly toggling (1 sec. period).

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - RCC/RCC_LSIConfig/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - RCC/RCC_LSIConfig/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - RCC/RCC_LSIConfig/Inc/main.h                  Header for main.c module  
  - RCC/RCC_LSIConfig/Src/stm32l0xx_it.c          Interrupt handlers
  - RCC/RCC_LSIConfig/Src/main.c                  Main program
  - RCC/RCC_LSIConfig/Src/system_stm32l0xx.c      STM32L0xx system source file

@par Hardware and Software environment

  - This example runs on STM32L073xx devices.
    
  - This example has been tested with STM32L073Z-EVAL 
    board and can be easily tailored to any other supported device
    and development board.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
