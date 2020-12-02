/**
  @page RNG_MultiRNG Multiple Random Number Generator example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    RNG/RNG_MultiRNG/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of Multiple Random Number Generator example.
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

Configuration of the RNG using the HAL API. This example uses the RNG to generate 32-bit long random numbers.

At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system
clock (SYSCLK) to run at 2 MHz (Up to 32MHZ possible).

The RNG peripheral configuration is ensured by the HAL_RNG_Init() function.
This later is calling the HAL_RNG_MspInit()function which core is implementing
the configuration of the needed RNG resources according to the used hardware (CLOCK, 
GPIO, DMA and NVIC). You may update this function to change RNG configuration.

After startup, user is asked to press key button.
Multiple Random 32bit numbers are generated as soon as the key is pressed.
The Random numbers are updated and displayed on the debugger in a Random32bit variable.

LED2 will turn ON, if any error is occurred.


@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents  

  - RNG/RNG_MultiRNG/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - RNG/RNG_MultiRNG/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - RNG/RNG_MultiRNG/Inc/main.h                  Header for main.c module
  - RNG/RNG_MultiRNG/Src/stm32l0xx_it.c          Interrupt handlers
  - RNG/RNG_MultiRNG/Src/main.c                  Main program
  - RNG/RNG_MultiRNG/Src/stm32l0xx_hal_msp.c     HAL MSP module 
  - RNG/RNG_MultiRNG/Src/system_stm32l0xx.c      STM32L0xx system source file

     
@par Hardware and Software environment

  - This example runs on STM32L052xx, STM32L053xx STM32L062xx and 
    STM32L063xx device lines RevZ.
    
  - This example has been tested with STM32L053R8-Nucleo RevC board and can be
    easily tailored to any other supported device and development board.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example
    
 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
 