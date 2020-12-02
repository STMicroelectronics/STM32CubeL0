/**
  @page LPTIM_Timeout LPTIM Timeout example with LSE clock source.
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    LPTIM/LPTIM_Timeout/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the LPTIM Timeout example.
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

How to implement, through the HAL LPTIM API, a timeout with the LPTIMER peripheral, to wake up 
the system from a low-power mode. 
  
After reset, The MCU enters in STOP mode.
The first external trigger event will start the timer, any successive trigger event on PB6
(LPTIM_ETR) will reset the counter and the timer will restart. 
The timeout value corresponds to the compare value (37000), if no trigger occurs within the 
expected time frame (1s), the MCU is woken-up by the compare match event and LED3 toggles.
To simplify, after reset :
- If applied external signal frequency signal is < 1Hz, the MCU in woken-up from STOP mode and LED3 toggles after 1s
- If applied external signal frequency signal is > 1Hz, the MCU stays in STOP mode, the LED3 doesn't toggles

In this example the LPTIM is clocked by the LSI (37000 Hz)

  Timeout = (Compare + 1) / LPTIM_Clock
          = (36999 + 1) / 37000
          = 1 s


@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents  

  - LPTIM/LPTIM_Timeout/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - LPTIM/LPTIM_Timeout/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - LPTIM/LPTIM_Timeout/Inc/main.h                  Header for main.c module  
  - LPTIM/LPTIM_Timeout/Src/stm32l0xx_it.c          Interrupt handlers
  - LPTIM/LPTIM_Timeout/Src/main.c                  Main program
  - LPTIM/LPTIM_Timeout/Src/stm32l0xx_hal_msp.c     HAL MSP module
  - LPTIM/LPTIM_Timeout/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L053xx devices.
    
  - This example has been tested with STM32L0538-DISCO RevB  board and can be
    easily tailored to any other supported device and development board.    
  
  - Connect an external signal (Trigger) on (PB.6). 
    System is woken up if the external trigger < 1Hz and LED3 blinks 
    otherwise if the external trigger > 1Hz LED3 do not blink.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example 

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
