/**
  @page TIM_PWMOutput TIM_PWMOutput example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    TIM/TIM_PWMOutput/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the TIM PWM output example.
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

Configuration of the TIM peripheral in PWM (pulse width modulation) mode.

The TIM2CLK frequency is set to SystemCoreClock  (Hz), to get TIM2 counter
clock at 16 MHz the Prescaler is computed as following:
   - Prescaler = (TIM2CLK / TIM2 counter clock) - 1

SystemCoreClock is set to 32 MHz for STM32L0xx Devices.

The TIM2 generates 4 PWM signals at 10 KHz:

    TIM2_Output Frequency = TIM2 counter clock/(ARR + 1)
                          = 16 MHz / 1600
                          = 10 KHz
                        
The TIM2 CCR1 register value is equal to 1200, so the TIM2 Channel 1 generates a 
PWM signal with a frequency equal to 10 KHz and a duty cycle equal to 75%:

    TIM2 Channel1 duty cycle = (TIM2_CCR1/ TIM2_ARR + 1)* 100 = 75%

The TIM2 CCR2 register value is equal to 800, so the TIM2 Channel 2 generates a 
PWM signal with a frequency equal to 10 KHz and a duty cycle equal to 50%:

    TIM2 Channel2 duty cycle = (TIM2_CCR2/ TIM2_ARR + 1)* 100 = 50%

The TIM2 CCR3 register value is equal to 533, so the TIM2 Channel 3 generates a 
PWM signal with a frequency equal to 10 KHz and a duty cycle equal to 37.5%:

    TIM2 Channel3 duty cycle = (TIM2_CCR3/ TIM2_ARR + 1)* 100 = 33.3%

The TIM2 CCR4 register value is equal to 400, so the TIM2 Channel 4 generates a 
PWM signal with a frequency equal to 10 KHz and a duty cycle equal to 25%:

    TIM2 Channel4 duty cycle = (TIM2_CCR4/ TIM2_ARR + 1)* 100 = 25%


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

  - TIM/TIM_PWMOutput/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - TIM/TIM_PWMOutput/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - TIM/TIM_PWMOutput/Inc/main.h                  Header for main.c module  
  - TIM/TIM_PWMOutput/Src/stm32l0xx_it.c          Interrupt handlers
  - TIM/TIM_PWMOutput/Src/main.c                  Main program
  - TIM/TIM_PWMOutput/Src/stm32l0xx_hal_msp.c     HAL MSP module
  - TIM/TIM_PWMOutput/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L051xx, STM32L052xx, STM32L053xx STM32L062xx and 
    STM32L063xx device lines RevZ
    
  - This example has been tested with STM32L053R8-Nucleo RevC  board and can be
    easily tailored to any other supported device and development board.
    
  - Connect the following pins to an oscilloscope to monitor the different 
    waveforms:
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
