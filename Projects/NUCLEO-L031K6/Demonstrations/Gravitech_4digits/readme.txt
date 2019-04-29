/**
  @page Demo   Demo STM32L031K6-Nucleo
 
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    readme.txt 
  * @author  MCD Application Team
  * @brief   Description of STM32L031K6-Nucleo Demo
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

Demonstration of firmware based on STM32Cube. This example provides firmware to
to help you to discover STM32 Cortex-M devices that are plugged onto an your
STM32NUCLEO_32 board.

At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system clock
(SYSCLK) to run at 2 MHz.
 
 
Below you find the sequence to discover the demonstration :

  This demo needs a Gravitech 4 digits 7 segment nano shield.
  You will find it here : http://www.gravitech.us/7sediforarna.html
  Plug the STM32NUCLEO_32 on top of this shield.
  The demo changes the power mode every 10 seconds and updates the display every second.
  The last digit corresponds to the time.
  The first digit corresponds to the power mode as is described below :
    100X = RUN Mode
    200X = SLEEP Mode
    300X = STOP Mode
    400X = STANDBY Mode
    500X = LPRUN Mode
    600X = LPSLEEP Mode
  For details about the low power modes, please look at the stm32l0xx reference manual.

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. 
      This implies that if HAL_Delay() is called from a peripheral ISR process, 
      then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to
      1 millisecond to have correct HAL operation.

@par Directory contents
 
  - Demonstrations/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - Demonstrations/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - Demonstrations/Inc/main.h                  Header for main.c module
  - Demonstrations/Src/stm32l0xx_it.c          Interrupt handlers
  - Demonstrations/Src/main.c                  Main program
  - Demonstrations/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L031xx devices.
  - This demo has been tested with STM32L031K6-Nucleo board and can be
    easily tailored to any other supported device and development board.
  - Gravitech 4 digits 7 segment nano shield is connected on Arduino nano connectors.

@par How to use it ? 

In order to make the program work, you must do the following :
  - Open your preferred toolchain 
  - Rebuild all files and load your image into target memory
  - Run the example
 
 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
