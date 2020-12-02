/**
  @page TIM_DMA TIM_DMA example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    TIM/TIM_DMA/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the TIM DMA example.
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

Use of the DMA with TIMER Update request 
to transfer data from memory to TIMER Capture Compare Register 3 (TIMx_CCR3).

  The following configuration values are used in this example:
  
    - TIM2CLK = SystemCoreClock 
    - Prescaler = 0 
    - TIM2 counter clock = SystemCoreClock
    - SystemCoreClock is set to 32M MHz for STM32L0xx

  The objective is to configure TIM2 channel 3 to generate a PWM (Pulse Width
  Modulation) signal with a frequency equal to 17.57 KHz, and a variable duty
  cycle that is changed by the DMA after each Update DMA request.

The PWM waveform can be displayed using an oscilloscope.


@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents  

  - TIM/TIM_DMA/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - TIM/TIM_DMA/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - TIM/TIM_DMA/Inc/main.h                  Header for main.c module  
  - TIM/TIM_DMA/Src/stm32l0xx_it.c          Interrupt handlers
  - TIM/TIM_DMA/Src/main.c                  Main program
  - TIM/TIM_DMA/Src/stm32l0xx_hal_msp.c     HAL MSP module
  - TIM/TIM_DMA/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L053xx devices.
    
  - This example has been tested with STM32L0538-DISCO RevB  board and can be
    easily tailored to any other supported device and development board.

  - Connect the following pin to an oscilloscope to monitor TIM2_CH3 output:
      - PB.10: (TIM2_CH3)


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example 


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
