/**
  @page BSP  Example on how to use the BSP drivers
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    BSP/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the BSP example.
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

This example provides a description of how to use the different BSP drivers,
based on the Adafruit 1.8" TFT shield with Joystick and microSD mounted on top
of the STM32 Nucleo board. 

At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system
clock (SYSCLK) to run at 32 MHz.

This example shows how to use the different functionalities of LCD, SD card, 
and joystick by switching between all tests using key button. 

Firstly, use the joystick button to move a pointer inside a rectangle 
(up/down/right/left) and change the pointer color(select).

Secondly, this example shows how to use the different LCD features to display string
with different alignments and fonts and to display different shapes.

Finally, this example shows how to erase, write and read the SD card and also 
compare the written/read data.


@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.


@par Directory contents 

  - BSP/Src/main.c                 Main program
  - BSP/Src/system_stm32l0xx.c     STM32L0xx system clock configuration file
  - BSP/Src/stm32l0xx_it.c         Interrupt handlers 
  - BSP/Src/joystick.c             joystick feature
  - BSP/Src/lcd.c                  LCD drawing features
  - BSP/Src/sd.c                   SD features
  - BSP/Inc/main.h                 Main program header file  
  - BSP/Inc/stm32l0xx_conf.h       Library Configuration file
  - BSP/Inc/stm32l0xx_it.h         Interrupt handlers header file
  - BSP/Inc/lcd_log_conf.h         lcd_log configuration template file
        
        
@par Hardware and Software environment

  - This example runs on STM32L051xx, STM32L052xx, STM32L053xx STM32L062xx and 
    STM32L063xx device lines RevZ
    
  - This example has been tested with STM32L053R8-Nucleo RevC board and can be
    easily tailored to any other supported device and development board.
    
  - A SDSC microSD card (capacity up to 4GB)
    
  - Adafruit 1.8" TFT shield must be connected on CN5,CN6, CN8 and CN9 Arduino connectors, 
    for more details please refer to UM1726.

For more details about the adafruit 1.8" TFT shield, please visit: 
http://www.adafruit.com/blog/2012/04/26/new-product-adafruit-1-8-18-bit-color-tft-shield-wmicrosd-and-joystick/


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
