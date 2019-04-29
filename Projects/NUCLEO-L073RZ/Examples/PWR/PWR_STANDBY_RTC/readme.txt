/**
  @page PWR_Standby PWR_STANDBY_RTC example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    PWR/PWR_STANDBY_RTC/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the PWR STANDBY example.
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
 
How to enter the Standby mode and wake-up from this mode by using an external 
reset or the RTC wakeup timer.

This example shows also how to configure the STM32L0xx system to measure 
STANDBY mode with RTC current consumption.

In the associated software, the system clock is set to 2 MHz, the SysTick is 
programmed to generate an interrupt each 1 ms.
The Low Speed Internal (LSI) clock is used as RTC clock source by default.

In the associated software
  - the system clock is set to 2 MHz.
  - the EXTI_Line20 connected internally to the RTC Wakeup event is configured
    to generate an interrupt on rising edge each 4s.
  - the SysTick is programmed to generate an interrupt each 1 ms. 

The system enters STANDBY mode after 5s and will wait for the RTC Wakeup timer event to be
generated each 4s. Current consumption could be monitored through an amperemeter (JP6).
After wake-up from STANDBY mode, program execution restarts in the same way as after
a RESET, the RTC configuration (clock source, prescaler,...). As result there is 
no need to configure the RTC.

The above scenario is repeated in an infinite loop.
 - LED2 ON: HAL configuration failed (system will go to an infinite loop)
 
    - STANDBY Mode with RTC clocked by LSI
    ===================================  
            - RTC Clocked by LSI
            - VREFINT OFF with fast wakeup enabled
            - No IWDG
            - Automatic Wakeup using RTC wakeup timer (after ~4s)

@note This example can not be used in DEBUG mode, this is due to the fact 
      that the Cortex-M0+ core is no longer clocked during low power mode 
       so debugging features are disabled

@note Care must be taken when HAL_RCCEx_PeriphCLKConfig() is used to select 
      the RTC clock source; in this case the Backup domain will be reset in  
      order to modify the RTC Clock source, as consequence RTC registers (including 
      the backup registers) and RCC_CSR register are set to their reset values.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.
      
@par Directory contents 

  - PWR/PWR_STANDBY_RTC/Inc/stm32l0xx_conf.h         HAL Configuration file
  - PWR/PWR_STANDBY_RTC/Inc/stm32l0xx_it.h           Header for stm32l0xx_it.c
  - PWR/PWR_STANDBY_RTC/Inc/main.h                   Header file for main.c
  - PWR/PWR_STANDBY_RTC/Src/system_stm32l0xx.c       STM32L0xx system clock configuration file
  - PWR/PWR_STANDBY_RTC/Src/stm32l0xx_it.c           Interrupt handlers
  - PWR/PWR_STANDBY_RTC/Src/main.c                   Main program
  - PWR/PWR_STANDBY_RTC/Src/stm32l0xx_hal_msp.c  HAL MSP module

@par Hardware and Software environment

  - This example runs on STM32L07xx and STM32L08xx devices
    
      
  - This example has been tested with STMicroelectronics STM32L073RZ-Nucleo Rev C
    evaluation board and can be easily tailored to any other supported device 
    and development board.

  - STM32L073RZ-Nucleo Rev C Set-up
    - Connect an amperemeter to JP6 to measure the IDD current

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
