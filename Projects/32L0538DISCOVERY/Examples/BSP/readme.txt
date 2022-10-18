/**
  @page BSP  Example on how to use the BSP drivers
 
  @verbatim
  ******************** (C) COPYRIGHT 2022 STMicroelectronics *******************
  * @file    BSP/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of STM32L0538-Discovery BSP example
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  @endverbatim

@par Example Description

This example provides a description of how to use the different BSP drivers.

This example provides 2 project configurations:
- STM32L0538-Discovery RevB03
- STM32L0538-Discovery

At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system clock
(SYSCLK) to run at 16 MHz using the HSI as clock source.

- A first display, on the e-paper display (EPD) screen is showing the 
    name of the board and the example. Push the User Key push-button to start the example:
    
### EPD (E-Paper Display) ###
This example shows how to use the different EPD features to display string
with different fonts, different line mode structures and to draw images.
LED3 is on when the example is running.

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. 
      This implies that if HAL_Delay() is called from a peripheral ISR process, 
      then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to
      1 millisecond to have correct HAL operation.


@par Hardware and Software environment

  - This example runs on STM32L053xx devices.
    
  - This example has been tested with STM32L0538-Discovery RevB board and can be
    easily tailored to any other supported device and development board.

  - Ensure that both CN4 jumpers are set to on (Discovery mode)
    and JP4 is in the ON position.   

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 */
                                                          