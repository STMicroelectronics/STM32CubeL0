/**
  @page TIM_OnePulse TIM One Pulse example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    TIM/TIM_OnePulse/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the TIM One Pulse example.      
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

Use of the TIM peripheral to generate a single pulse when 
an external signal rising edge is received on the timer input pin.


Clock setup for TIM3
================================

  TIM3CLK = SystemCoreClock = 2 MHz.
  
  Prescaler = (TIM3CLK /TIM3 counter clock) - 1
  
  The prescaler value is computed in order to have TIM3 counter clock 
  set at 2000000 Hz.
  
  The Autoreload value is 65535 (TIM3->ARR), so the maximum frequency value to 
  trigger the TIM3 input is 2000000/65535 [Hz].
 
Configuration of TIM3 in One Pulse Mode
===================================================
 
  - The external signal is connected to TIM3_CH2 pin (PA.07), 
    and a rising edge on this input is used to trigger the Timer.
  - The One Pulse signal is output on TIM3_CH1 (PA.06).

  The delay value is fixed to:
   - Delay =  CCR1/TIM3 counter clock 
           = 16383 / 2000000 [sec]
           
  The pulse value is fixed to : 
   - Pulse value = (TIM_Period - TIM_Pulse)/TIM3 counter clock  
                 = (65535 - 16383) / 2000000 [sec]

  The one pulse waveform can be displayed using an oscilloscope and it looks
  like this.
  
                               ____
                               |   |
  CH2 _________________________|   |__________________________________________
 
                                             ___________________________
                                            |                           |
  CH1 ______________________________________|                           |_____
                               <---Delay----><------Pulse--------------->
  


@par Directory contents 

  - TIM/TIM_OnePulse/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - TIM/TIM_OnePulse/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - TIM/TIM_OnePulse/Inc/main.h                  Header for main.c module  
  - TIM/TIM_OnePulse/Src/stm32l0xx_it.c          Interrupt handlers
  - TIM/TIM_OnePulse/Src/main.c                  Main program
  - TIM/TIM_OnePulse/Src/stm32l0xx_hal_msp.c     HAL MSP file
  - TIM/TIM_OnePulse/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

   - This example runs on STM32L073xx devices.
   - In this example, the clock is set to 2 MHz.
    
  - This example has been tested with STM32L073Z-EVAL board and can be
    easily tailored to any other supported device and development board.

  - STM32L073Z-EVAL Set-up
   - Connect the external signal to the TIM3_CH2 pin (PA.07) (CN10 pin39)
   - Connect the TIM3_CH1 pin(PA.06) (CN10 pin41) to an oscilloscope to monitor the waveform.  
   - WARNING : -On STM32L073Z-EVAL Board Rev A (MB1168), PA.06 and PA.07 are inverted.
               -On STM32L073Z-EVAL Board Rev B (MB1168),JP1 must be set on LCD position.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example 


 */
