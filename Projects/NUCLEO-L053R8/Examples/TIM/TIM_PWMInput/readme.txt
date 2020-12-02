/**
  @page TIM_PWMInput TIM_PWMInput example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    TIM/TIM_PWMInput/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the TIM PWM input example.
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

Use of the TIM peripheral to measure an external signal frequency and 
duty cycle.

The TIM2CLK frequency is set to SystemCoreClock (Hz), the Prescaler is 0 so the 
counter clock is SystemCoreClock (Hz).
SystemCoreClock is set to 32 MHz for STM32L0xx Devices.

TIM2 is configured in PWM Input Mode: the external signal is connected to 
TIM2 Channel2 used as input pin.
To measure the frequency and the duty cycle we use the TIM2 CC2 interrupt request,
so In the TIM2_IRQHandler routine, the frequency and the duty cycle of the external 
signal are computed.

The "uwFrequency" variable contains the external signal frequency:
TIM2 counter clock = SystemCoreClock
Frequency = TIM2 counter clock / TIM2_CCR2 in Hz.

The "uwDutyCycle" variable contains the external signal duty cycle:
DutyCycle = [(TIM2_CCR + 1)1*100]/(TIM2_CCR2 + 1) in %.

The minimum frequency value that can be measured is (TIM2 counter clock / CCR MAX)
                                         = 32.000.000/ 65535
                                         = 489 Hz
@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents  

  - TIM/TIM_PWMInput/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - TIM/TIM_PWMInput/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - TIM/TIM_PWMInput/Inc/main.h                  Header for main.c module  
  - TIM/TIM_PWMInput/Src/stm32l0xx_it.c          Interrupt handlers
  - TIM/TIM_PWMInput/Src/main.c                  Main program
  - TIM/TIM_PWMInput/Src/stm32l0xx_hal_msp.c     HAL MSP module
  - TIM/TIM_PWMInput/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L051xx, STM32L052xx, STM32L053xx STM32L062xx and 
    STM32L063xx device lines RevZ
    
  - This example has been tested with STM32L053R8-Nucleo RevC  board and can be
    easily tailored to any other supported device and development board.
   
   - Connect the external signal to be measured to TIM2_CH2 pin (PA.01)(pin 30 in CN7 connector).


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example 


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
