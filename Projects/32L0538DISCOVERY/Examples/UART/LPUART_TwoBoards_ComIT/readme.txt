/**
  @page LPUART_TwoBoards_ComIT UART Two Boards Communication IT example

  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    UART/LPUART_TwoBoards_ComIT/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the LPUART Two Boards Communication IT example.
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

LPUART transmission (transmit/receive) in Interrupt mode 
between two boards.

At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system
clock (SYSCLK) to run at 32 MHz.

Then 1st board is waiting for user button key to be pressed. Once done, data 
are transmitted through UART1 in IT mode. 2nd board has configured LPUART1 
to receive data in IT mode. Once data received is completed, 2nd board also 
transmit same characters on LPUART1 which will be received by 1st board.
Both boards compare transmitted data to received ones. If they are same, green 
LED3 is turn on, else LED3 is turn Off.

Warning: As both boards do not behave same way, "TRANSMITTER_BOARD" switch 
compilation exists to determine either software is for 1st transmitter board or 
2nd receiver (then transmitter) board. In other words, 1st board has to be 
flashed with software compiled with switch enable, 2nd board has to be flashed 
with software compiled with switch disable.

LED3 can be used to monitor the transfer status:
 - LED3 turns ON on master board waiting user button to be pressed.
 - LED3 turns OFF on master board waiting the transmission process is complete.
 - LED3 turns ON when the transmission/reception process is correct.    

The LPUART is configured as follow:
    - BaudRate = 9600 baud  
    - Word Length = 8 Bits (7 data bit + 1 parity bit)
    - One Stop Bit
    - None parity
    - Hardware flow control disabled (RTS and CTS signals)
    - Reception and transmission are enabled in the time

@note USARTx/UARTx instance used and associated resources can be updated in "main.h"
file depending hardware configuration used.

@note When the parity is enabled, the computed parity is inserted at the MSB
position of the transmitted data.

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - UART/LPUART_TwoBoards_ComIT/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - UART/LPUART_TwoBoards_ComIT/Inc/stm32l0xx_it.h          IT interrupt handlers header file
  - UART/LPUART_TwoBoards_ComIT/Inc/main.h                  Header for main.c module  
  - UART/LPUART_TwoBoards_ComIT/Src/stm32l0xx_it.c          IT interrupt handlers
  - UART/LPUART_TwoBoards_ComIT/Src/main.c                  Main program
  - UART/LPUART_TwoBoards_ComIT/Src/stm32l0xx_hal_msp.c     HAL MSP module
  - UART/LPUART_TwoBoards_ComIT/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment 

  - This example runs on STM32L053xx devices.
    
  - This example has been tested with STM32L0538-DISCO RevB and can be
    easily tailored to any other supported device and development board.

  - STM32L0538-DISCO RevB Set-up
    - Connect a wire between 1st board PB10 pin (LPUART Tx) 
      to 2nd board PB11 pin (LPUART Rx)
    - Connect a wire between 1st board PB11 pin (LPUART Rx)
      to 2nd board PB10 pin (LPUART Tx)
  
@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
