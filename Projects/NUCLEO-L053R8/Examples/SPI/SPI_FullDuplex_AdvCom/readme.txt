/**
  @page SPI_FullDuplex_AdvCom SPI Full Duplex Polling example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    SPI/SPI_FullDuplex_AdvCom/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the SPI Full Duplex Polling example.
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

@par Example Description 

Configuration of the HAL SPI API to transmit/receive a data buffer using Interrupt mode 
in an advanced communication mode:
The master board always sends the command to the slave before performing any transmission; 
the slave board sends back an acknowledgement before proceeding.

- Hardware Description

The communication is done with 2 boards through SPI.
   _________________________                        _________________________
  |           ______________|                      |______________           |
  |          |SPI2          |                      |          SPI2|          |
  |          |              |                      |              |          |
  |          |     CLK(PB13)|______________________|(PB13)CLK     |          |
  |          |              |                      |              |          |
  |          |    MISO(PB14)|______________________|(PB14)MISO    |          |
  |          |              |                      |              |          |
  |          |    MOSI(PB15)|______________________|(PB15)MOSI    |          |
  |          |              |                      |              |          |
  |          |    NSS (PB12)|______________________|(PB12)NSS     |          |
  |          |              |                      |              |          |
  |          |______________|                      |______________|          |
  |      __                 |                      |      __                 |
  |     |__|                |                      |     |__|                |
  |     USER                |                      |     USER                |
  |                      GND|______________________|GND                      |
  |                         |                      |                         |
  |_STM32L0 ________________|                      |_STM32L0 ________________|



At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system
clock (SYSCLK) to run at 2 MHz.

The SPI peripheral configuration is ensured by the HAL_SPI_Init() function.
This later is calling the HAL_SPI_MspInit()function which core is implementing
the configuration of the needed SPI resources according to the used hardware (CLOCK & 
GPIO). You may update this function to change SPI configuration.

The SPI communication is then initiated.
On Master side: LED2 is ON waiting for end user to press button key.
Then, Master enters in while loop calling 2 functions Master_Read_Data and 
Master_Write_Data. Each of them can be decomposed in 2 steps:
- sending command (write or read) to slave and number of requested bytes to be 
read or write.
- executing command (read or write)
Each of these steps need acknowledge from slave.
If Read command is performed, received buffer is compared with the one supposed 
to be received.

Slave directly goes in while loop and call spi receive function to wait for 
master clock and characters to be received.
When done, Slave computes command and data lenght to determine if command is 
known. If yes acknowledge bytes are send else non-acknowledge bytes are sent.
In case command is valid, Slave pursues by executing command.
If Read command is performed, received buffer is compared with the one supposed 
to be received
Then acknowledge is again sent to Master.

If the Master board is used, the "#define MASTER_BOARD" must be uncommented.
If the Slave board is used the "#define MASTER_BOARD" must be commented.
If Interrupt mode is choosen, "#define SPI_MODE_IT" must be uncommented

LED2 can be used to monitor the transfer status:
 - LED2 turns ON on master board waiting user button to be pressed.
 - LED2 toggles on Master side at end of each loop
 - LED2 stops toggling when there is an error in transmission/reception process.
  

@note SPIx instance used and associated resources can be updated in "main.h"
       file depending hardware configuration used.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - SPI/SPI_FullDuplex_AdvCom/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - SPI/SPI_FullDuplex_AdvCom/Inc/stm32l0xx_it.h          SPI interrupt handlers header file
  - SPI/SPI_FullDuplex_AdvCom/Inc/main.h                  Header for main.c module  
  - SPI/SPI_FullDuplex_AdvCom/Src/stm32l0xx_it.c          SPI interrupt handlers
  - SPI/SPI_FullDuplex_AdvCom/Src/main.c                  Main program
  - SPI/SPI_FullDuplex_AdvCom/Src/system_stm32l0xx.c      STM32L0xx system source file
  - SPI/SPI_FullDuplex_AdvCom/Src/stm32l0xx_hal_msp.c     HAL MSP file
  

@par Hardware and Software environment  
  - This example runs on STM32L051xx, STM32L052xx, STM32L053xx STM32L062xx and 
    STM32L063xx device lines RevZ
    
  - This example has been tested with STM32L0xx-NUCLEO RevC and can be
    easily tailored to any other supported device and development board.

  - TM32L0xx-NUCLEO RevC Set-up
    - Connect Master board PB12 to Slave Board PB12
    - Connect Master board PB13 to Slave Board PB13
    - Connect Master board PB14 to Slave Board PB14
    - Connect Master board PB15 to Slave Board PB15
    - Connect Master board GND  to Slave Board GND
    - SB35 ON
    - SB44 OFF
    - SB28 ON
    - SB39 OFF
    - SB25 ON
    - SB36 OFF

 - in main.h
    o Uncomment "#define MASTER_BOARD" and load the project in Master Board
    o Comment "#define MASTER_BOARD" and load the project in Slave Board
    o Uncomment "#define SPI_MODE_IT" if you want to perform Interrupt 
    transfer.


@par How to use it ? 
In order to make the program work, you must do the following :
- Open your preferred toolchain 
- Rebuild all files and load your image into target memory
- Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
 
