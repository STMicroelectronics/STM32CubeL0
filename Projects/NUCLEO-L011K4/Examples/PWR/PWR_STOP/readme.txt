/**
  @page PWR_STOP Power Stop Mode Example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    PWR/PWR_STOP/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the Power Stop Mode example.
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

How to enter the Stop mode and wake up from this mode by using the RTC wakeup 
timer event or an interrupt.

This is achieved using PA.12 (Arduino D2) configured to generate an interrupt on falling edge.
LED3 is ON during RUN mode and OFF during STOP mode.

In the associated software
  - the system clock is set to 2 MHz.
  - the PA.12 (Arduino D2) is configured to generate an interrupt on falling edge.
  - the SysTick is programmed to generate an interrupt each 1 ms. 

Firstly, remove jumper between PA.12 (Arduino D2) and GND and reset the board. LED3 is ON.
The system enters STOP mode after 5s and will wait for a falling edge on PA.12 (Arduino D2). LED3 is OFF. 
Put jumper between PA.12 (Arduino D2) and GND to wake-up the system. 
Then remove it.
Current consumption could be monitored through an ampere-meter.
After the system woken up from STOP, the clock system is reconfigured because the default clock 
after wake up is the MSI.

This behavior is repeated in an infinite loop.
 
    - STOP Mode
    ============ 
          - Regulator in LP mode
          - VREFINT OFF with fast wakeup enabled
          - MSI as SysClk after Wake Up
          - No IWDG
          - Wakeup using EXTI Line (PA.12 (Arduino D2))

@note To measure the current consumption in STOP mode, please refer to 
      @subpage PWR_CurrentConsumption example.

@note This example can not be used in DEBUG mode, this is due to the fact 
      that the Cortex-M0+ core is no longer clocked during low power mode 
      so debugging features are disabled

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.
      
@note  Care must be taken when HAL_RCCEx_PeriphCLKConfig() is used to select the RTC clock source; in this 
       case the Backup domain will be reset in order to modify the RTC Clock source, as consequence RTC  
       registers (including the backup registers) and RCC_BDCR register are set to their reset values.

@par Directory contents 

  - PWR/PWR_STOP/Inc/stm32l0xx_conf.h         HAL Configuration file
  - PWR/PWR_STOP/Inc/stm32l0xx_it.h           Header for stm32l0xx_it.c
  - PWR/PWR_STOP/Inc/main.h                   Header file for main.c
  - PWR/PWR_STOP/Src/system_stm32l0xx.c       STM32L0xx system clock configuration file
  - PWR/PWR_STOP/Src/stm32l0xx_it.c           Interrupt handlers
  - PWR/PWR_STOP/Src/main.c                   Main program
  - PWR/PWR_STOP/Src/stm32l0xx_hal_msp.c      HAL MSP module

@par Hardware and Software environment

  - STM32L011K4-Nucleo Set-up :
    - Use jumper between PA.12 (Arduino D2) and GND when required.
    - Connect an ampere-meter to JP1 instead of the jumper to measure the IDD current.
   
  - This example runs on STM32L011xx and STM32L021xx devices.

  - This example has been tested with STMicroelectronics STM32L011K4-Nucleo
    evaluation board and can be easily tailored to any other supported device 
    and development board.
    
@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
