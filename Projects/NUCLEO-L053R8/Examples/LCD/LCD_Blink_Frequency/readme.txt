/**
  @page LCD_Blink_Frequency LCD Blink frequency example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    LCD/LCD_Blink_Frequency/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the LCD Blink Frequency example.
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

How to use the embedded LCD glass controller and how to set the LCD 
blink mode and blinking frequency.
 
After Reset the Blink frequency is equal to LCDCLK/16 and LCD Glass display "BK0016"
string. By pressing on the Key button (PA.00)the Blink frequency is incremented 
and the message displayed on the Pacific Display LCD glass is proportional 
to the blink frequency.

In this example, 7 different Blink frequency are used:
   - The Blink frequency = fLcd/16
   - The Blink frequency = fLcd/32
   - The Blink frequency = fLcd/64
   - The Blink frequency = fLcd/128
   - The Blink frequency = fLcd/256
   - The Blink frequency = fLcd/512
   - The Blink frequency = fLcd/1024


@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents  

  - LCD/LCD_Blink_Frequency/Inc/stm32l0xx_hal_conf.h          HAL configuration file
  - LCD/LCD_Blink_Frequency/Inc/stm32l0xx_it.h                Interrupt handlers header file
  - LCD/LCD_Blink_Frequency/Inc/main.h                        Header for main.c module
  - LCD/LCD_Blink_Frequency/Inc/stm32l152c_discovery.h        stm32l152c discovery header file
  - LCD/LCD_Blink_Frequency/Inc/stm32l152c_discovery_lcd.h    stm32l152c discovery lcd glass header file
  - LCD/LCD_Blink_Frequency/Src/stm32l0xx_it.c                Interrupt handlers
  - LCD/LCD_Blink_Frequency/Src/main.c                        Main program
  - LCD/LCD_Blink_Frequency/Src/system_stm32l0xx.c            STM32L0xx system source file
  - LCD/LCD_Blink_Frequency/Src/stm32l152c_discovery.c        stm32l152c discovery source file
  - LCD/LCD_Blink_Frequency/Src/stm32l152c_discovery_lcd.c    stm32l152c discovery lcd glass source file
  - LCD/LCD_Blink_Frequency/Src/stm32l0xx_hal_msp.c           HAL MSP module
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
