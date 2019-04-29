/**
  @page LCD_Display_Text  LCD Display Text example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    LCD/LCD_Display_Text/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the LCD Display Text example.
  ******************************************************************************
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
