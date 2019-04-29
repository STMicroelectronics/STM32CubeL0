/**
  @page TIM_PWMOutput TIM_PWMOutput example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    TIM/TIM_PWMOutput/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the TIM PWM output example.
  ******************************************************************************
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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
PWM signal with a frequency equal to 10 KHz and a duty cycle equal to 33.3%:

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

  - This example runs on STM32L053xx devices.
    
  - This example has been tested with STM32L0538-DISCO RevB  board and can be
    easily tailored to any other supported device and development board.
    
  - Connect the following pins to an oscilloscope to monitor the different 
    waveforms:
      - PA.00: (TIM2_CH1) 
      - PB.03: (TIM2_CH2) 
      - PB.10: (TIM2_CH3) 
      - PB.11: (TIM2_CH4) 


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example 


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
