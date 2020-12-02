/**
  @page RTC_Alarm RTC Alarm Example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    RTC/RTC_Alarm/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the RTC Alarm example.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  @endverbatim

@par Example Description

Configuration and generation of an RTC alarm using the RTC HAL API.

- At the beginning of the main program the HAL_Init() function is called to reset
  all the peripherals, initialize the Flash interface and the systick.
  Then the SystemClock_Config() function is used to configure the system
  clock (SYSCLK) to run at 2 MHz.

- The RTC peripheral configuration is ensured by the HAL_RTC_Init() function.
  This later is calling the HAL_RTC_MspInit()function which core is implementing
  the configuration of the needed RTC resources according to the used hardware (CLOCK, 
  PWR, RTC clock source and BackUp). You may update this function to change RTC configuration.

- LSE oscillator clock is used as RTC clock source by default.
  The user can use also LSI as RTC clock source. The user uncomment the adequate
  define on the main.h file. 

- HAL_RTC_SetAlarm_IT() function is called to initialize the Alarm feature with
  interrupt mode.
  HAL_RTC_SetDate() and HAL_RTC_SetTime() functions are then called to initialize the
  time and the date.

In this example, the Time is set to 02:20:00 and the Alarm must be generated after
30 seconds on 02:20:30.
  - LED2 is turned ON when the RTC Alarm is generated correctly.
    The current time is updated and displayed on the debugger in aShowTime variable.
  - LED2 is toggling : This indicates that the system generates an error.

@note Using stdio.h may increase the code size, it is optional and intended only to
      ease the example by displaying the date variable (aShowTime) on the debugger.
      By default this option is enabled, user can disable it by commenting
       "#define DISPLAY_ON_DUBUGGER" in main.h file.        
       
        
@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents  

  - RTC/RTC_Alarm/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - RTC/RTC_Alarm/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - RTC/RTC_Alarm/Inc/main.h                  Header for main.c module
  - RTC/RTC_Alarm/Src/stm32l0xx_it.c          Interrupt handlers
  - RTC/RTC_Alarm/Src/main.c                  Main program
  - RTC/RTC_Alarm/Src/stm32l0xx_hal_msp.c     HAL MSP module
  - RTC/RTC_Alarm/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L051xx, STM32L052xx, STM32L053xx STM32L062xx and 
    STM32L063xx device lines RevZ

  - This example has been tested with STM32L053R8-Nucleo RevC  board and can be
    easily tailored to any other supported device and development board.

  - STM32L053R8-Nucleo Set-up
    - Use LED2 connected to PA.05 pin


@par How to use it ?

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
 