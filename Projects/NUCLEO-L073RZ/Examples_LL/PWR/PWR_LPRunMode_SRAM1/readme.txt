/**
  @page PWR_LPRunMode_SRAM1 PWR standby example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    Examples_LL/PWR/PWR_LPRunMode_SRAM1/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the PWR Low Power Run Mode (SRAM1) example.
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

How to execute code in Low-power run mode from SRAM1.

In the associated software, the system clock is set to 2.097 MHz, an EXTI line
is connected to the User push-button through PC.13 and configured to generate an 
interrupt on falling edge upon key press.

After start-up LED2 is toggling FAST(100-ms blinking period), 
indicates that device is running at 2.097 MHz.

The User push-button can be pressed to set system in LowPowerRun mode (Freq: 65KHz). 
In this case LED2 toggling SLOW(400-ms blinking period).

LED toggling speed is controled by variable "uhLedBlinkSpeed".

@note To measure the current consumption in Run mode, remove JP6 jumper 
      and connect an ampere meter to JP6 to measure IDD current.
      NB: LED2 have an impact on power consumption. 
          Remove LED2 blinking to have a stable power consumption, 
          comment line  "#define USE_LED" in main.c file  

@note This example is executed from SRAM1 to decrease power consumption.
      Flash is deactivated during LowPowerRun mode activation. 
      This example cannot be executed in standalone mode, so using debugger is mandatory to run this example.

@par Directory contents 

  - PWR/PWR_LPRunMode_SRAM1/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - PWR/PWR_LPRunMode_SRAM1/Inc/main.h                  Header for main.c module
  - PWR/PWR_LPRunMode_SRAM1/Inc/stm32_assert.h          Template file to include assert_failed function
  - PWR/PWR_LPRunMode_SRAM1/Src/stm32l0xx_it.c          Interrupt handlers
  - PWR/PWR_LPRunMode_SRAM1/Src/main.c                  Main program
  - PWR/PWR_LPRunMode_SRAM1/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L073xx devices.
    
  - This example has been tested with STMicroelectronics STM32L073RZ-Nucleo Rev C
    board and can be easily tailored to any other supported device
    and development board.

  - STM32L073RZ-Nucleo Rev C Set-up
    - LED2 connected to PA.05 pin
    - User push-button connected to pin PC.13 (External line 15 to 10)

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
