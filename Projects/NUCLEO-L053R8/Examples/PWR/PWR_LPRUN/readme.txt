/**
  @page PWR_LPRUN Low Power run Mode Example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    PWR/PWR_LPRUN/readme.txt
  * @author  MCD Application Team
  * @brief   This example shows how to use STM32L0xx PWR HAL API to enter the
  *          system to Low Power Run mode and exit from this mode using Key 
  *          push button.
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

How to enter and exit the Low-power run mode.

This example shows also how to configure the STM32L0xx system to measure 
LP Run mode current consumption.

In the associated software, the system clock is set to 32 KHz.

 @note This mode is achieved with the multispeed internal (MSI) RC oscillator set 
       to the lowspeed clock (max 131 kHz), execution from SRAM or Flash memory, 
       and internal regulator in low-power mode to minimize the regulator's 
       operating current.

In the associated software    
  - the system clock is set to 32 KHz
  - the Key push button (PC13) is used to enter and exit the Low Power Run mode.

The system enters LP RUN mode by pressing User push button (PC.13) and will wait 
for the same button to be pressed to exit LP RUN mode. Current consumption could 
be monitored through an amperemeter.

This behavior is repeated in an infinite loop.
 - LED2 ON: HAL configuration failed (system will go to an infinite loop)
 
    - Low Power Run Mode from FLASH
    ================================
          - Regulator in LP mode
          - System Running at MSI (~32KHz)
          - Flash 0 wait state  
          - MSI Range 0
          - Voltage Range 2
          - Code running from Internal FLASH
          - All peripherals OFF
          - Wakeup using Key Button PC.13

 @note This example can not be used in DEBUG mode, this is due to the fact 
       that the Cortex-M0+ core is no longer clocked during low power mode 
       so debugging features are disabled


@par Directory contents  

  - PWR/PWR_LPRUN/Inc/stm32l0xx_conf.h     Library Configuration file
  - PWR/PWR_LPRUN/Inc/stm32l0xx_it.h       Header for stm32l0xx_it.c
  - PWR/PWR_LPRUN/Inc/main.h               header file for main.c
  - PWR/PWR_LPRUN/Src/system_stm32l0xx.c   STM32L0xx system clock configuration file
  - PWR/PWR_LPRUN/Src/stm32l0xx_it.c       Interrupt handlers
  - PWR/PWR_LPRUN/Src/main.c               Main program
  - PWR/PWR_LPRUN/Src/stm32l0xx_hal_msp.c  HAL MSP module

@par Hardware and Software environment

  - This example runs on STM32L051xx, STM32L052xx, STM32L053xx STM32L062xx and 
    STM32L063xx device lines RevZ
    
  - This example has been tested with STM32L053R8-Nucleo RevC  board and can be
    easily tailored to any other supported device and development board.

  - STM32L053R8-Nucleo Set-up
    - Use LED2 connected to PA.05 pin
    - Use the Key push-button connected to pin PC13
    - Connect an amperemeter to JP6 to measure the IDD current

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
