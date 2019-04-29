/**
  @page Demo   Demo STM32L053C8-Discovery
 
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    readme.txt 
  * @author  MCD Application Team
  * @brief   Description of STM32L053C8-Discovery Demo
  ******************************************************************************
  *
  * Copyright (c) 2016 STMicroelectronics International N.V. All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  @endverbatim

@par Demo Description

Demonstration firmware based on STM32Cube. This example helps you to discover
STM32 Cortex-M devices that are plugged onto your STM32 Discovery board.

At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system clock
(SYSCLK) to run at 16 MHz using the HSI as clock source.

Below you find the sequence to discover the demonstration :

  - Connect the STM32L0538-Discovery RevB board to a PC with a 'USB type A to Mini-B' cable
    through USB connector CN1 to power the board. Then red led LD1 (COM) and
    LD2 (PWR) light up.

  - The two signal LEDs blink continously.

  - A first display, for 2s, on the e-paper display (EPD) screen is showing the 
    name of the board and the demonstration firmware version. Then the main menu
    is displayed.

  - To select one of the two applications use the linear sensor. The upper side is for
    the USB mouse Demo and the lower one is for Idd measurement Demo. 
    
    1. USB mouse Demo: connect a second USB cable type A to mini-B between CN3 and
       the PC, then see the mouse cursor movement according linear sensor position.
       Each part of the linear sensor corresponds to a secific mouse movement 
       direction(Right, Left, Up, Down).
       Press User Button B1 to go back to the main menu.
       
       @note HSI48 is used as USB clock source. The 48 MHz clock for the USB is 
             derived from the RC48 Clock (HSI48): The HSI48 clock is generated 
             from an internal 48 MHz RC oscillator, coupled with the clock recovery
             system (CRS). The CRS allows automatic trimming of the internal HSI48,
             synchronized with USB SOF signal at 1KHz rate, to guarantee its optimal
             accuracy over the whole device operational range.   
      
    2. Idd measurement Demo: displays on EPD the MCU Idd consumption of the power 
       modes. Each part of the linear sensor corresponds to a power mode.
       The modes are: Run mode, Sleep mode, LP Sleep mode and Stop mode.
         - For the low power modes(Sleep, LP Sleep and Stop) the display of the Idd 
           consumption is preceded by entering the MCU on the related LP mode and 
           turning off the LEDs indicating that the MCU is in LP mode.
         - Press User Button B1 to go back to the main menu.  


@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. 
      This implies that if HAL_Delay() is called from a peripheral ISR process, 
      then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to
      1 millisecond to have correct HAL operation.


@par Hardware and Software environment

  - This example runs on STM32L053xx devices..
    
  - This example has been tested with STM32L053C8-Discovery RevB board and can be
    easily tailored to any other supported device and development board.
    
  - Ensure that both CN4 jumpers are set to on (Discovery mode)
    and JP4 is in the ON position.   


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Once the image is loaded, power off the Discovery board by unplugging the power cable 
   then power on the board again.
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
                                                          