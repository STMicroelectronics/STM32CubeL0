/**
  @page PWR_LPSLEEP Low Power sleep Mode Example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    PWR/PWR_LPSLEEP/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the Low Power Sleep Mode example.
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
 
How to enter the Low-power sleep mode and wake up from this mode by using 
an interrupt.

In the associated software, the system clock is set to 2 MHz.
This example shows how to enter the system to LP SLEEP mode and wake-up from this
mode using PA.12 (Arduino D2) configured to generate an interrupt on falling edge.
 
The SysTick is programmed to generate an interrupt each 1 ms and in the SysTick 
interrupt handler, LED3 is toggled in order to indicate whether the MCU is in LP SLEEP mode 
or RUN mode.

Firstly, remove jumper between PA.12 (Arduino D2) and GND
and reset the board.
5 seconds after start-up, the system automatically enters LP SLEEP mode and 
LED3 stops toggling.
Put jumper between PA.12 (Arduino D2) and GND at any time to wake-up the system.
Then remove it.
The software then comes back in RUN mode for 5 sec. before automatically entering LP SLEEP mode again. 

LED3 is used to monitor the system state as follows:
 - LED3 toggling : system in RUN mode
 - LED3 off : system in LP SLEEP mode

These steps are repeated in an infinite loop.

@note Connect an ampere-meter to JP1 instead of the jumper to measure the IDD current.

@note By default, the software resorts to __HAL_FLASH_SLEEP_POWERDOWN_ENABLE() macro
      to power down the Flash in Sleep mode. The user needs to uncomment this line in
      main() function if power consumption figures with Flash still on in LP SLEEP must
      be measured.
      
@note This example can not be used in DEBUG mode due to the fact 
      that the Cortex-M0+ core is no longer clocked during low power mode 
      so debugging features are disabled.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.
      

@par Directory contents 

  - PWR/PWR_LPSLEEP/Inc/stm32l0xx_conf.h         HAL Configuration file
  - PWR/PWR_LPSLEEP/Inc/stm32l0xx_it.h           Header for stm32l0xx_it.c
  - PWR/PWR_LPSLEEP/Inc/main.h                   Header file for main.c
  - PWR/PWR_LPSLEEP/Src/system_stm32l0xx.c       STM32L0xx system clock configuration file
  - PWR/PWR_LPSLEEP/Src/stm32l0xx_it.c           Interrupt handlers
  - PWR/PWR_LPSLEEP/Src/main.c                   Main program

@par Hardware and Software environment

  - This example runs on STM32L031xx devices
    
      
  - This example has been tested with STMicroelectronics STM32L031K6-Nucleo
    board and can be easily tailored to any other supported device 
    and development board.

  - STM32L031K6-Nucleo set-up:
    - LED3 connected to PB.03 pin
    - Use jumper between PA.12 (Arduino D2) and GND when required.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
