/**
  @page TIM_TimeBase Timebase example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    TIM/TIM_TimeBase/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the TIM Timebase example
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

Configuration of the TIM peripheral to generate a timebase of 
one second with the corresponding interrupt request.

The TIMxCLK (TIM6CLK) frequency is SystemCoreClock (Hz), to get TIMx (TIM6)
counter clock at 10 KHz so the Prescaler is computed as following:
   - Prescaler = (TIMxCLK / TIMx counter clock) - 1

SystemCoreClock is set to 32MHz for STM32L0xx Devices.

The TIMx ARR register value is equal to 10000 - 1, 
Update rate = TIMx counter clock / (Period + 1) = 1 Hz,
So the TIMx generates an interrupt each 1 s.

When the counter value reaches the auto-reload register value, the TIM update 
interrupt is generated and, in the handler routine, LED2 (PA.5) is toggled with
the following frequency:

  o LED2 (PA5) : 0.5 Hz


@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents  

  - TIM/TIM_TimeBase/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - TIM/TIM_TimeBase/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - TIM/TIM_TimeBase/Inc/main.h                  Header for main.c module  
  - TIM/TIM_TimeBase/Src/stm32l0xx_it.c          Interrupt handlers
  - TIM/TIM_TimeBase/Src/main.c                  Main program
  - TIM/TIM_TimeBase/Src/stm32l0xx_hal_msp.c     HAL MSP file
  - TIM/TIM_TimeBase/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L051xx, STM32L052xx, STM32L053xx STM32L062xx and 
    STM32L063xx device lines RevZ
    
  - This example has been tested with STM32L053R8-Nucleo RevC  board and can be
    easily tailored to any other supported device and development board.



@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example 

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
