/**
  @page LPTIM_PWM_LSE LPTIM PWM Low Power example with LSE clock source.
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    LPTIM/LPTIM_PWM_LSE/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the LPTIM PWM LSE example.
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

How to configure and use, through the HAL LPTIM API, the LPTIM peripheral using LSE 
as counter clock, to generate a PWM signal, in a low-power mode. 
  
The counter clock is LSE (32.768 KHz), Autoreload equal to 99 so the output
frequency (FrequencyOutput) will be equal to 327.680.

  FrequencyOutput = Counter Clock Frequency / (Autoreload + 1)
                  = 32768 / 100
                  = 327.680 Hz

Pulse value equal to 49 and the duty cycle (DutyCycle) is computed as follow:

  DutyCycle = 1 - ((PulseValue + 1)/ (Autoreload + 1))
  DutyCycle = 50%

To minimize the power consumption, after starting generating the PWM signal,
the MCU enters in STOP mode. Note that GPIOs are configured in Low Speed to
enhance the consumption. 


@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents  

  - LPTIM/LPTIM_PWM_LSE/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - LPTIM/LPTIM_PWM_LSE/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - LPTIM/LPTIM_PWM_LSE/Inc/main.h                  Header for main.c module  
  - LPTIM/LPTIM_PWM_LSE/Src/stm32l0xx_it.c          Interrupt handlers
  - LPTIM/LPTIM_PWM_LSE/Src/main.c                  Main program
  - LPTIM/LPTIM_PWM_LSE/Src/stm32l0xx_hal_msp.c     HAL MSP module
  - LPTIM/LPTIM_PWM_LSE/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L053xx devices.
    
  - This example has been tested with STM32L0538-DISCO RevB  board and can be
    easily tailored to any other supported device and development board.
    
  
  - Connect (PB.2) to an oscilloscope to monitor the LPTIM output waveform.
  
  - LSE oscillator must be mounted on the board, else this example does not work.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example 


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
