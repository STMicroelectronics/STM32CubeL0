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

This example shows also how to configure the STM32L0xx system to measure 
LP SLEEP mode current consumption.

The Low power sleep mode is entered by configuring the voltage regulator in low power
mode, and by executing the WFI (wait for interrupt) or WFE (wait for event) instructions. In
this mode, the Flash memory is not available but the RAM memory remains available.

In this example, the WFI instruction is used to enter Low power sleep mode, any 
peripheral interrupt acknowledged by the nested vectored interrupt controller (NVIC) 
can wake up the device from Low power sleep mode.

In the associated software
  - the system clock is set to 32 KHz.
  - External lines 4 to 15 is configured to generate an interrupt on falling edge.

 @note In Low power sleep mode, the system frequency should not exceed MSI range1.
 @note Low power sleep mode can only be entered when VCORE is in range 2. 

The system enters LP SLEEP mode by pressing the User push-button and will wait 
for the same button to be pressed to wake up from LP SLEEP mode. Current consumption 
could be monitored through an amperemeter.

This behaviour is repeated in an infinite loop.
 - LED2 ON during 1 second: indicates that device is in run mode, 
   then LED is turned off to be able to measure current and make a comparison
   versus low power sleep mode.
 - LED2 ON continuously: HAL configuration failed (system will go to an infinite loop)

    - Low Power Sleep Mode
    =======================
          - Regulator in LP mode
          - System Running at MSI (~32KHz)
          - Flash 0 wait state  
          - Voltage Range 2
          - Code running from Internal FLASH
          - All peripherals OFF
          - VDD from 1.65V to 3.6V
          - Wakeup using EXTI Line (User push-button PC.13)     

@note Debug using ST-Link is not possible during the execution of this example 
      because communication between ST-link and the device under test is done through UART.
      All GPIO pins are disabled (set to analog input mode), except one GPIO for User push-button,
      to reduce current consumption, including UART I/O pins.
      
          
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
      
@par Directory contents 

  - PWR/PWR_LPSLEEP/Inc/stm32l0xx_conf.h         HAL Configuration file
  - PWR/PWR_LPSLEEP/Inc/stm32l0xx_it.h           Header for stm32l0xx_it.c
  - PWR/PWR_LPSLEEP/Inc/main.h                   Header file for main.c
  - PWR/PWR_LPSLEEP/Src/system_stm32l0xx.c       STM32L0xx system clock configuration file
  - PWR/PWR_LPSLEEP/Src/stm32l0xx_it.c           Interrupt handlers
  - PWR/PWR_LPSLEEP/Src/main.c                   Main program

@par Hardware and Software environment

  - This example runs on STM32L07xx and STM32L08xx devices
    
      
  - This example has been tested with STMicroelectronics STM32L073RZ-Nucleo Rev C
    evaluation board and can be easily tailored to any other supported device 
    and development board.

  - STM32L073RZ-Nucleo Rev C Set-up
    - Use the User push-button connected to pin PC.13 (External lines 4 to 15)
    - Connect an amperemeter to JP6 to measure the IDD current

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
