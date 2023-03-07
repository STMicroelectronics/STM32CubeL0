/**
  @page TIM_OCActive TIM_OCActive example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    TIM/TIM_OCActive/readme.txt 
  * @author  MCD Application Team
  * @brief   This example shows how to configure the Timer to generate four 
  *          delayed signals.
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

Configuration of the TIM peripheral in Output Compare Active mode 
(when the counter matches the capture/compare register, the corresponding output 
pin is set to its active state).

  The TIM3CLK frequency is set to SystemCoreClock, and the objective is
  to get TIM2 counter clock at 1 KHz so the Prescaler is computed as following:
     - Prescaler = (TIM2CLK / TIM2 counter clock) - 1
   
  SystemCoreClock is set to 32 MHz.

  The TIM2 CCR1 register value is equal to 1000:
  TIM2_CH1 delay = CCR1_Val/TIM2 counter clock  = 1s
  so the TIM2 Channel 1 generates a signal with a delay equal to 1s.

  The TIM2 CCR2 register value is equal to 500:
  TIM2_CH2 delay = CCR2_Val/TIM2 counter clock = 500 ms
  so the TIM2 Channel 2 generates a signal with a delay equal to 500 ms.

  The TIM2 CCR3 register value is equal to 250:
  TIM2_CH3 delay = CCR3_Val/TIM2 counter clock = 250 ms
  so the TIM2 Channel 3 generates a signal with a delay equal to 250 ms.

  The TIM2 CCR4 register value is equal to 125:
  TIM2_CH4 delay = CCR4_Val/TIM2 counter clock = 125 ms
  so the TIM2 Channel 4 generates a signal with a delay equal to 125 ms.

  The delay correspond to the time difference between PA.05 falling edge and
  TIM2_CHx signal rising edges.
@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents  

  - TIM/TIM_OCActive/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - TIM/TIM_OCActive/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - TIM/TIM_OCActive/Inc/main.h                  Header for main.c module  
  - TIM/TIM_OCActive/Src/stm32l0xx_it.c          Interrupt handlers
  - TIM/TIM_OCActive/Src/main.c                  Main program
  - TIM/TIM_OCActive/Src/stm32l0xx_hal_msp.c     HAL MSP file
  - TIM/TIM_OCActive/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L051xx, STM32L052xx, STM32L053xx STM32L062xx and 
    STM32L063xx device lines RevZ
    
  - This example has been tested with STM32L053R8-Nucleo RevC  board and can be
    easily tailored to any other supported device and development board.
   
  - STM32L053R8-Nucleo RevC Set-up 
    - Connect the following pins to an oscilloscope to monitor the different 
      waveforms:
      - Use LED2 connected to PA.05 (Reference)
      - PA.00: (TIM2_CH1) (pin 28 in CN7 connector)
      - PA.01: (TIM2_CH2) (pin 30 in CN7 connector)
      - PB.10: (TIM2_CH3) (pin 25 in CN10 connector)
      - PB.11: (TIM2_CH4) (pin 18 in CN10 connector)


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example 



 */
