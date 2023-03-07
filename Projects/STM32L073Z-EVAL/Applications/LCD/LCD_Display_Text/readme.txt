/**
  @page LCD_Display_Text  LCD Display Text example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    LCD/LCD_Display_Text/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the LCD Display Text example.
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

@par Application Description

How to use and configure the embedded LCD glass controller to display 
a simple text and turn on icons.  

After reset the Blink frequency is equal to LCDCLK/128 and LCD Glass display "BK00128".

This Example consists in the display of different types of text, blinking text, rolling text
and various Icons activation (refreshing period is around 2 seconds).

When completed, the text THE END is displayed and the LED4 is blinking.

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - LCD/LCD_Display_Text/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - LCD/LCD_Display_Text/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - LCD/LCD_Display_Text/Inc/main.h                  Header for main.c module  
  - LCD/LCD_Display_Text/Src/stm32l0xx_it.c          Interrupt handlers
  - LCD/LCD_Display_Text/Src/main.c                  Main program
  - LCD/LCD_Display_Text/Src/stm32l0xx_hal_msp.c     HAL MSP file
  - LCD/LCD_Display_Text/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L073xx devices.
    
  - This example has been tested with STMicroelectronics STM32L073Z-EVAL
    board and can be easily tailored to any other supported device
    and development board.  
	
  - Important information : 
    ----------------------
  - The LCD glass is mounted by default on a neutral position , it has to be 
    moved up in LCD position from it's default IO position. (please refer to the board UM)
  - On the RevB board:
	 - The jumpers JP1, JP15, JP17 must be set in LCD position
     - The jumpers JP14, JP16, JP18 must be left open 
  
@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example


 */
