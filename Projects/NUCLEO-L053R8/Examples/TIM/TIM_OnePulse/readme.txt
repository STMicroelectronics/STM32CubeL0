/**
  @page TIM_OnePulse TIM_OnePulse example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    TIM/TIM_OnePulse/readme.txt 
  * @author  MCD Application Team
  * @brief   This example shows how to configure the TIM HAL API to generate
  *          a one pulse signal
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

Use of the TIM peripheral to generate a single pulse when 
an external signal rising edge is received on the timer input pin.

  TIM2CLK = SystemCoreClock, we want to get TIM2 counter clock at 16 MHz:
             - Prescaler = (TIM2CLK / TIM2 counter clock) - 1

  SystemCoreClock is set to 32 MHz.

  The Autoreload value is 65535 (TIM2->ARR), so the maximum frequency value to 
  trigger the TIM2 input is 16000000/65535 = 244 Hz.

  The TIM2 is configured as follows: 
  The One Pulse mode is used, the external signal is connected to TIM2 CH2 pin (PA.01), 
  the rising edge is used as active edge, the One Pulse signal is output 
  on TIM2_CH1 (PA.00).

  The TIM_Pulse defines the delay value, the delay value is fixed to:
  delay =  CCR1/TIM4 counter clock = 16383 / 16000000 = 1.023 ms. 
  The (TIM_Period - TIM_Pulse) defines the One Pulse value, the pulse value is fixed to:
  One Pulse value = (TIM_Period - TIM_Pulse)/TIM4 counter clock 
                  = (65535 - 16383) / 16000000 = 3.072 ms.

The one pulse waveform can be displayed using an oscilloscope.

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents  

  - TIM/TIM_OnePulse/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - TIM/TIM_OnePulse/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - TIM/TIM_OnePulse/Inc/main.h                  Header for main.c module  
  - TIM/TIM_OnePulse/Src/stm32l0xx_it.c          Interrupt handlers
  - TIM/TIM_OnePulse/Src/main.c                  Main program
  - TIM/TIM_OnePulse/Src/stm32l0xx_hal_msp.c     HAL MSP file
  - TIM/TIM_OnePulse/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L051xx, STM32L052xx, STM32L053xx STM32L062xx and 
    STM32L063xx device lines RevZ
    
  - This example has been tested with STM32L053R8-Nucleo RevC  board and can be
    easily tailored to any other supported device and development board.
   
  - STM32L053R8-Nucleo RevC Set-up 
   - Connect the external signal to the TIM2_CH2 pin (PA.01)(pin 30 in CN7 connector)
   - Connect the TIM2_CH1 (PA.00) (pin 28 in CN7 connector) pin to an oscilloscope
     to monitor the waveform.   

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example 


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
