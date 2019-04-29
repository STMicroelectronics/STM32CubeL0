/**
  @page FreeRTOS_LowPower_LPTIM FreeRTOS Low Power LPTIM example
 
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    FreeRTOS/FreeRTOS_LowPower_LPTIM/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the FreeRTOS low power example.
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
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *
  ******************************************************************************
  @endverbatim

@par Application Description

How to enter MCU in the STOP mode when all RTOS tasks are suspended.

This example creates one thread that toggle a LED then blocks for 1 sec . Blocking for a 
finite period allows the kernel to stop the tick interrupt and place the STM32 into stop mode.

In this example, non-used GPIO's are configured to analog, thus helping to reduce 
the power consumption of the device.

The RTOS tick is suppressed while the MCU is in the low power state.
The LPTIM is used as clock source for both RTOS and HAL ticks.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      

@note The FreeRTOS heap size configTOTAL_HEAP_SIZE defined in FreeRTOSConfig.h is set according 
      to the OS resources memory requirements of the application with +10% margin and rounded to 
	  the upper Kbyte boundary.

For more details about FreeRTOS implementation on STM32Cube, please refer to UM1722 "Developing Applications 
on STM32Cube with RTOS".


@par Directory contents
    - FreeRTOS/FreeRTOS_LowPower_LPTIM/Inc/main.h                                  main config file
    - FreeRTOS/FreeRTOS_LowPower_LPTIM/Inc/stm32l0xx_hal_conf.h                    HAL Configuration file
    - FreeRTOS/FreeRTOS_LowPower_LPTIM/Inc/stm32l0xx_it.h                          Header for stm32l0xx_it.c
    - FreeRTOS/FreeRTOS_LowPower_LPTIM/Inc/FreeRTOSConfig.h                        FreeRTOS Configuration file
    - FreeRTOS/FreeRTOS_LowPower_LPTIM/Inc/stm32l0xx_timebase_lptim.h              RTOS time base using LPTIM header file
    - FreeRTOS/FreeRTOS_LowPower_LPTIM/Src/main.c                                  main program file
	- FreeRTOS/FreeRTOS_LowPower_LPTIM/Src/low_power_tick_management_LPTIM.c       RTOS low power tick management
   	- FreeRTOS/FreeRTOS_LowPower_LPTIM/Src/stm32l0xx_timebase_lptim.c              Time base using LPTIM 
    - FreeRTOS/FreeRTOS_LowPower_LPTIM/Src/stm32l0xx_it.c                          STM32 Interrupt handlers

@par Hardware and Software environment

  - This example runs on STM32L053xx devices.
    
  - This example has been tested with a STM32L053R8-Nucleo Rev C board embedding
    a STM32L053R8T6 device and can be easily tailored to any other supported device 
    and development board.


@par How to use it ?

In order to make the program work, you must do the following:
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example
 
 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
