/**
  @page COMP_Interrupt COMP Interrupt example
  
  @verbatim
  ******************** (C) COPYRIGHT 2012 STMicroelectronics *******************
  * @file    COMP/COMP_Interrupt/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the COMP Interrupt example.
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

How to use a comparator peripheral to compare a voltage level applied on a GPIO
pin to the the internal voltage reference (VREFINT), in interrupt mode.

When the comparator input (connected to PA1) crosses (either rising or falling edges)
the internal reference voltage VREFINT (1.22V), the comparator 1 generates an interrupt 
and toggles LED2.

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

  - COMP/COMP_Interrupt/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - COMP/COMP_Interrupt/Inc/stm32l0xx_it.h          DMA interrupt handlers header file
  - COMP/COMP_Interrupt/Inc/main.h                  Header for main.c module  
  - COMP/COMP_Interrupt/Src/stm32l0xx_it.c          DMA interrupt handlers
  - COMP/COMP_Interrupt/Src/main.c                  Main program
  - COMP/COMP_Interrupt/Src/stm32l0xx_hal_msp.c     HAL MSP file
  - COMP/COMP_Interrupt/Src/system_stm32l0xx.c      STM32L0xx system source file
         
@par Hardware and Software environment

  - This example runs on STM32L051xx, STM32L052xx, STM32L053xx STM32L062xx and 
    STM32L063xx device lines RevZ
    
  - This example has been tested with STM32L053R8-Nucleo RevC  board and can be
    easily tailored to any other supported device and development board.

  - STM32L053R8-Nucleo Set-up
    - Use LED2 connected to PA5 pin.
    - Apply an external variable voltage on PA1 (pin A1 in CN8 connector) with average voltage 1.22V.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example
  
 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

