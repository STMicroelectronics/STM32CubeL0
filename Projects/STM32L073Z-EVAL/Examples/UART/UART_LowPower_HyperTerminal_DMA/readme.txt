/**
  @page UART_LowPower_HyperTerminal_DMA Hyperterminal DMA Example using LPUART 
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    UART/UART_LowPower_HyperTerminal_DMA/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the LPUART Hyperterminal example.
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

LPUART transmission (transmit/receive) in DMA mode 
between a board and an HyperTerminal PC application.

Board: STM32L073Z-EVAL  (Connector : CN7)
Tx Pin: GPIOD_8
Rx Pin: GPIOD_9
   _________________________ 
  |           ______________|                       _______________
  |          |LPUART        |                      | HyperTerminal |
  |          |              |                      |               |
  |          |           TX |______________________|RX             |
  |          |              |                      |               |
  |          |              |     RS232 Cable      |               |             
  |          |              |                      |               |
  |          |           RX |______________________|TX             |          
  |          |              |                      |               |           
  |          |______________|                      |_______________|          
  |                         |                       
  |                         |                    
  |                         |                      
  |                         |                      
  |_STM32_Board_____________|                      



At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system
clock (SYSCLK) to run at 2 MHz.

The UART peripheral configuration is ensured by the HAL_UART_Init() function.
This later is calling the HAL_UART_MspInit()function which core is implementing
the configuration of the needed UART resources according to the used hardware (CLOCK, 
GPIO, DMA and NVIC). You may update this function to change UART configuration.

The UART/Hyperterminal communication is then initiated.
The HAL_UART_Receive_DMA() and the HAL_UART_Transmit_DMA() functions allow respectively 
the reception of Data from Hyperterminal and the transmission of a predefined data 
buffer.

The Asynchronous communication aspect of the UART is clearly highlighted as the  
data buffers transmission/reception to/from Hyperterminal are done simultaneously.

For this example the TxBuffer is predefined and the RxBuffer size is limited to 
10 data by the mean of the RXBUFFERSIZE define in the main.c file.

In a first step the received data will be stored in the RxBuffer buffer and the 
TxBuffer buffer content will be displayed in the Hyperterminal interface.
In a second step the received data in the RxBuffer buffer will be sent back to 
Hyperterminal and displayed.
The end of this two steps are monitored through the HAL_UART_GetState() function
result.

STM32 Eval board's LEDs can be used to monitor the transfer status:
 - LED1 is ON when the transmission process is complete.
 - LED2 is ON when the reception process is complete.
 - LED3 is ON when there is an error in transmission/reception process.  

The UART is configured as follows:
    - BaudRate = 9600 baud  
    - Word Length = 8 Bits (7 data bit + 1 parity bit)
    - One Stop Bit
    - Odd parity
    - Hardware flow control disabled (RTS and CTS signals)
    - Reception and transmission are enabled in the time


@par Directory contents 

  - UART/UART_LowPower_HyperTerminal_DMA/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - UART/UART_LowPower_HyperTerminal_DMA/Inc/stm32l0xx_it.h          DMA interrupt handlers header file
  - UART/UART_LowPower_HyperTerminal_DMA/Inc/main.h                  Header for main.c module  
  - UART/UART_LowPower_HyperTerminal_DMA/Src/stm32l0xx_it.c          DMA interrupt handlers
  - UART/UART_LowPower_HyperTerminal_DMA/Src/main.c                  Main program
  - UART/UART_LowPower_HyperTerminal_DMA/Src/stm32l0xx_hal_msp.c     HAL MSP module
  - UART/UART_LowPower_HyperTerminal_DMA/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L073xx devices.
    
  - This example has been tested with STM32L073Z-EVAL board and can be
    easily tailored to any other supported device and development board.    

  - To use the low power UART, the LCD Glass module must be mounted in I/O position.
  
  - Hyperterminal configuration:
    - Word Length = 7 Bits
    - One Stop Bit
    - Odd parity
    - BaudRate = 9600 baud
    - flow control: None 

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example



 */
