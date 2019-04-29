/**
  @page TIM_OCToggle TIM_OCToggle example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    TIM/TIM_OCToggle/readme.txt 
  * @author  MCD Application Team
  * @brief   This example shows how to configure the Timer to generate four different 
  *          signals with four different frequencies.
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

Configuration of the TIM peripheral to generate four different 
signals at four different frequencies.

  The TIM2 frequency is set to SystemCoreClock, and the objective is
  to get TIM2 counter clock at 2.1 MHz so the Prescaler is computed as following:
     - Prescaler = (TIM2CLK /TIM2 counter clock) - 1
   
  SystemCoreClock is set to 2 MHz for STM32L0xx Devices.

  The TIM2 CCR1 register value is equal to 5384:
  CC1 update rate = TIM2 counter clock / CCR1_Val = 390 Hz,
  so the TIM2 Channel 1 generates a periodic signal with a frequency equal to 195 Hz.

  The TIM2 CCR2 register value is equal to 2692:
  CC2 update rate = TIM2 counter clock / CCR2_Val = 780 Hz,
  so the TIM2 channel 2 generates a periodic signal with a frequency equal to 390 Hz.

  The TIM2 CCR3 register value is equal to 1346:
  CC3 update rate = TIM2 counter clock / CCR3_Val = 1560 Hz,
  so the TIM2 channel 3 generates a periodic signal with a frequency equal to 780 Hz.

  The TIM2 CCR4 register value is equal to 673:
  CC4 update rate = TIM2 counter clock / CCR4_Val =  3120 Hz,
  so the TIM2 channel 4 generates a periodic signal with a frequency equal to 1560 Hz.

@note PWM signal frequency values mentioned above are theoretical (obtained when the system clock frequency
      is exactly 2 MHz). Since the generated system clock frequency may vary from one board to another observed
      PWM signal frequency might be slightly different.
	  
@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - TIM/TIM_OCToggle/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - TIM/TIM_OCToggle/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - TIM/TIM_OCToggle/Inc/main.h                  Header for main.c module  
  - TIM/TIM_OCToggle/Src/stm32l0xx_it.c          Interrupt handlers
  - TIM/TIM_OCToggle/Src/main.c                  Main program
  - TIM/TIM_OCToggle/Src/stm32l0xx_hal_msp.c     HAL MSP file
  - TIM/TIM_OCToggle/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L011xx devices.
    
  - This example has been tested with STMicroelectronics STM32L011K4-Nucleo 
    board and can be easily tailored to any other supported device 
    and development board.      

  - STM32L011K4-Nucleo Set-up
   Connect the following pins to an oscilloscope to monitor the different waveforms:
      - PA.00: (TIM2_CH1) (connected to PA.00 (pin 12 on CN4))
      - PA.01: (TIM2_CH2) (connected to PA.01 (pin 11 on CN4))
      - PB.00: (TIM2_CH3) (connected to PB.00 (pin 6 on CN3))
      - PB.01: (TIM2_CH4) (connected to PB.01 (pin 9 on CN3))

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example


CH1      _______________________________________                     
    ____|                                       |___________________

CH2      ___________________                     ___________________
   _____|                   |___________________|
   
CH3      _________           _________           _________
   _____|         |_________|         |_________|         |_________
   
CH4      ____      ____      ____      ____      ____      ____    
    ____|    |____|    |____|    |____|    |____|    |____|    |____    


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
