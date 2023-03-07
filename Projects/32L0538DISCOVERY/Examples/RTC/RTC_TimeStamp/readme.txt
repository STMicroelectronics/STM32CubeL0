/**
  @page RTC_TimeStamp RTC time stamp Example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    RTC/RTC_TimeStamp/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the RTC time stamp example.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  @endverbatim

@par Example Description 
 
Configuration of the RTC HAL API to demonstrate the timestamp feature.

- At the beginning of the main program the HAL_Init() function is called to reset 
  all the peripherals, initialize the Flash interface and the systick.
  Then the SystemClock_Config() function is used to configure the system
  clock (SYSCLK) to run at 2 MHz.

The RTC peripheral configuration is ensured by the HAL_RTC_Init() function.
This later is calling the HAL_RTC_MspInit()function which core is implementing
the configuration of the needed RTC resources according to the used hardware (CLK, 
PWR, RTC clock source and BackUp). You may update this function to change RTC configuration.

- LSE oscillator clock is used as RTC clock source by default.
  The user can use also LSI as RTC clock source. The user uncomment the adequate 
  define on the main.h file.

HAL_RTCEx_SetTamper()function is called to initialize the tamper feature.
HAL_RTCEx_SetTimeStamp_IT()function is then called to initialize the time stamp feature 
with interrupt mode. It configures The Time Stamp pin to be falling edge and enables
the time Stamp detection on tamper pin.
HAL_RTC_SetTime()and HAL_RTC_SetDate() functions are then called to initialize the 
time and the date.

The program behaves as follows:

1. After startup the program configure the RTC (Time date) and enable the feature 
   timeStamp. 

2. Applying a low level on the Time Stamp pin (PC13) by pressing to User button, 
   a time stamp event is detedced and the calendar is saved in the time stamp structures.
   Each time the user presses on tamper button, the current time and Time Stamp are updated and displayed 
   on the debugger in aShowTime and aShowTimeStamp variables .
   
- LED3 is toggling : This indicates that the system generates an error.

@note Using stdio.h may increase the code size, it is optional and intended only to
      ease the example by displaying the date variables (aShowTime and aShowTimeStamp) on the debugger.
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

  - RTC/RTC_TimeStamp/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - RTC/RTC_TimeStamp/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - RTC/RTC_TimeStamp/Inc/main.h                  Header for main.c module  
  - RTC/RTC_TimeStamp/Src/stm32l0xx_it.c          Interrupt handlers handlers
  - RTC/RTC_TimeStamp/Src/main.c                  Main program
  - RTC/RTC_TimeStamp/Src/stm32l0xx_hal_msp.c     HAL MSP module
  - RTC/RTC_TimeStamp/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L053xx devices.

  - This example has been tested with STM32L0538-DISCO RevB  board and can be
    easily tailored to any other supported device and development board.

  - STM32L0538-DISCO Set-up
    - connect externally PA0 to PC13 and use KEY push button connected to PA.0 pin as Time Stamp pin.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example



 */
 