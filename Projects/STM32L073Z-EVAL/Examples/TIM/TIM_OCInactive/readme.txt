/**
  @page TIM_OCInactive TIM_OCInactive example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    TIM/TIM_OCInactive/readme.txt 
  * @author  MCD Application Team
  * @brief   This example shows how to configure the Timer to generate four 
  *          delayed signals.
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

Configuration of the TIM peripheral in Output Compare Inactive mode 
with the corresponding Interrupt requests for each channel.

  The TIM2 frequency is set to SystemCoreClock, and the objective is
  to get TIM2 counter clock at 10 kHz so the Prescaler is computed as following:
     - Prescaler = (TIM2CLK /TIM2 counter clock) - 1
   
  SystemCoreClock is set to 2 MHz for STM32L0xx Devices.

  The TIM2 CCR1 register value is equal to 10000:
  TIM2_CH1 delay = CCR1_Val/TIM2 counter clock  = 1s
  so the TIM2 Channel 1 generates a signal with a delay equal to 1s.

  The TIM2 CCR2 register value is equal to 5000:
  TIM2_CH2 delay = CCR2_Val/TIM2 counter clock = 500 ms
  so the TIM2 Channel 2 generates a signal with a delay equal to 500 ms.

  The TIM2 CCR3 register value is equal to 2500:
  TIM2_CH3 delay = CCR3_Val/TIM2 counter clock = 250 ms
  so the TIM2 Channel 3 generates a signal with a delay equal to 250 ms.

  The TIM2 CCR4 register value is equal to 1250:
  TIM2_CH4 delay = CCR4_Val/TIM2 counter clock = 125 ms
  so the TIM2 Channel 4 generates a signal with a delay equal to 125 ms.

  While the counter is lower than the Output compare registers values, which 
  determines the Output delay, the PC.05, PC.06, PC.08 and PC.09 pin are turned ON. 

  When the counter value reaches the Output compare registers values, the Output 
  Compare interrupts are generated and, in the handler routine, these pins are turned OFF.
  
@note Delay values mentioned above are theoretical (obtained when the system clock frequency 
      is exactly 2 MHz). Since the generated system clock frequency may vary from one board to another observed
      delay might be slightly different.
	  
@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - TIM/TIM_OCInactive/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - TIM/TIM_OCInactive/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - TIM/TIM_OCInactive/Inc/main.h                  Header for main.c module  
  - TIM/TIM_OCInactive/Src/stm32l0xx_it.c          Interrupt handlers
  - TIM/TIM_OCInactive/Src/main.c                  Main program
  - TIM/TIM_OCInactive/Src/stm32l0xx_hal_msp.c     HAL MSP file
  - TIM/TIM_OCInactive/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L073xx devices.
    
  - This example has been tested with STMicroelectronics STM32L073Z-EVAL 
    board and can be easily tailored to any other supported device 
    and development board.      

  - STM32L073Z-EVAL Set-up
   Connect the following pins to an oscilloscope to monitor the different waveforms:
      - PC.05: wave form of (TIM2_CH1) (pin 11 in CN14 connector)
      - PC.06: wave form of (TIM2_CH2) (pin 13 in CN14 connector)
      - PC.08: wave form of (TIM2_CH3) (pin 17 in CN14 connector)
      - PC.09: wave form of (TIM2_CH4) (pin 19 in CN14 connector)

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example


  PC.05 
              ______________________________________________________
 _____________|                                                     |________________
              <---------------------- 1sec------------------------->
  PC.06 
              ____________________________
 _____________|                           |__________________________________________
              <------------500ms---------->
  PC.08   
              __________________
 _____________|                 |____________________________________________________
              <----250ms------->
 
  PC.09 
              ____________
 _____________|           |___________________________________________________________
              <--125ms--->
           

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
