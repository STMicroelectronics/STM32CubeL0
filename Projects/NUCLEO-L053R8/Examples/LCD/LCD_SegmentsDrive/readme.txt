/**
  @page LCD_SegmentsDrive LCD Segments Drive example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    LCD/LCD_SegmentsDrive/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the LCD Segments Drive example.
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

How to use the embedded LCD glass controller to drive the on-board 
LCD glass by Pacific Display Devices.

The goal of this example is to display a "STM32L" string on LCD glass in scrolling
mode. The scrolling number is fixed to 10 repetition and the speed is fixed to 200ms.


@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents  

  - LCD/LCD_SegmentsDrive/Inc/stm32l0xx_hal_conf.h          HAL configuration file
  - LCD/LCD_SegmentsDrive/Inc/stm32l0xx_it.h                Interrupt handlers header file
  - LCD/LCD_SegmentsDrive/Inc/main.h                        Header for main.c module
  - LCD/LCD_SegmentsDrive/Inc/stm32l152c_discovery.h        stm32l152c discovery header file
  - LCD/LCD_SegmentsDrive/Inc/stm32l152c_discovery_lcd.h    stm32l152c discovery lcd glass header file
  - LCD/LCD_SegmentsDrive/Src/stm32l0xx_it.c                Interrupt handlers
  - LCD/LCD_SegmentsDrive/Src/main.c                        Main program
  - LCD/LCD_SegmentsDrive/Src/system_stm32l0xx.c            STM32L0xx system source file
  - LCD/LCD_SegmentsDrive/Src/stm32l152c_discovery.c        stm32l152c discovery source file
  - LCD/LCD_SegmentsDrive/Src/stm32l152c_discovery_lcd.c    stm32l152c discovery lcd glass source file
  - LCD/LCD_SegmentsDrive/Src/stm32l0xx_hal_msp.c           HAL MSP module
@par Hardware and Software environment

  - This example runs on STM32L053xx  and STM32L063xx device lines RevZ
    
 - This example has been tested with STM32L152C DISCOVERY RevC(STM32L152C device 
    changed with STM32L053).
    It can be easily tailored to any other supported device and development board.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example 



 */
