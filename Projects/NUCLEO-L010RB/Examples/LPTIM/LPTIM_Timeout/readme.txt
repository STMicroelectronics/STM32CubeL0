/**
  @page LPTIM_Timeout LPTIM Timeout example with LSE clock source

  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    LPTIM/LPTIM_Timeout/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the LPTIM Timeout example.
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

How to implement, through the HAL LPTIM API, a timeout with the LPTIMER peripheral, to wake up
the system from a low-power mode.


The main() function configures the LPTIMER and goes in STOP mode.
In order to start the timer a first trigger is needed on (PC.3)(LPTIM_ETR).
Any successive trigger event on (PC.3) will reset the counter and the timer
will restart. The timeout value corresponds to the compare value (32768).
If after the first trigger no other trigger occurs within the expected time frame,
the MCU is woken-up by the compare match event and LED2 toggles.

In this example the LPTIM is clocked by the LSI

  Timeout = (Compare + 1) / LPTIM_Clock
          = (32767 + 1) / LSI_Clock_Frequency

Once the system is woken up it remains in run mode. The led keeps toggling each time the timer expires.

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents

  - LPTIM/LPTIM_Timeout/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - LPTIM/LPTIM_Timeout/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - LPTIM/LPTIM_Timeout/Inc/main.h                  Header for main.c module
  - LPTIM/LPTIM_Timeout/Src/stm32l0xx_it.c          Interrupt handlers
  - LPTIM/LPTIM_Timeout/Src/main.c                  Main program
  - LPTIM/LPTIM_Timeout/Src/stm32l0xx_hal_msp.c     HAL MSP module
  - LPTIM/LPTIM_Timeout/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L010xB devices.

  - This example has been tested with STMicroelectronics STM32L010RB-Nucleo
    board and can be easily tailored to any other supported device
    and development board.

  - Connect an external trigger (ETR) to PC.3(pin 37 in CN7 connector ).
    LSI clock is around 37 KHz (please refer to Reference Manual)
    LPTIM time-out period is equal to 32768 / 37000 = 0.886 ms (1.13 Hz)

    So, for an LSI clock equal to 37 KHz,
    - If the trigger is higher than 1.13 Hz, the counter is regularly reset, the system stays in STOP mode.
    - If the trigger is lower than 1.13 Hz, the counter expires and the system is woken up.

@par How to use it ?

In order to make the program work, you must do the following :
 - Open your preferred tool chain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
