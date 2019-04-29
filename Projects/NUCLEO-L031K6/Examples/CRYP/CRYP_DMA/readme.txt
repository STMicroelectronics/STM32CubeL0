/**
  @page CRYP_DMA  Encrypt and Decrypt data using AES Algo in ECB chaining
   mode using DMA
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    CRYP/CRYP_DMA/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the CRYP AES Algorithm in ECB mode with DMA Example
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

=================================================================================
WARNING :
To run this example, you must use an STM32L041xx device.
By default, the STM32L031K6-Nucleo boards (Nucleo32) are equiped with an STM32L031xx 
device which doesn't support the AES feature.
=================================================================================

How to use the CRYP peripheral to encrypt and decrypt data using the AES-128 
algorithm with ECB chaining mode in DMA mode.

DMA is used to transfer data from memory to the AES processor
input as well as to transfer data from AES processor output to memory.

64-byte buffers are ciphered and deciphered (4 AES blocks)
Ciphering/Deciphering with a 128-bit long key is used with data type set to 8-bit (byte swapping).

This example unrolls as follows: 
- AES Encryption (Plain Data --> Encrypted Data)
- AES Decryption with key derivation (Encrypted Data --> Decrypted Data)

LED3 is used to notify if the Encryption/Decryption failed

The Plain data, encrypted data and decrypted data can be displayed on a PC
HyperTerminal using the UART.

Other option terminal IO mode is only available for EWARM IAR tool chain 
(not available on ARM KEIL or SW4STM32 tool chain): Then the Plain data,
encrypted data and decrypted data can be displayed on debugger terminal IO
by uncomment following line in main file: 
/*#define TERMINAL_IO_OUT*/ 


@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - CRYP/CRYP_DMA/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - CRYP/CRYP_DMA/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - CRYP/CRYP_DMA/Inc/main.h                  Header for main.c module  
  - CRYP/CRYP_DMA/Src/stm32l0xx_it.c          Interrupt handlers
  - CRYP/CRYP_DMA/Src/main.c                  Main program
  - CRYP/CRYP_DMA/Src/stm32l0xx_hal_msp.c     HAL MSP module
  - CRYP/CRYP_DMA/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L041xx devices.

  - This example has been tested with STM32L031K6-Nucleo board with socket using STM32L041xx plugged-in  
    and can be easily tailored to any other supported device and development board.
  
  - Hyperterminal configuration:
    - BaudRate = 115200 baud  
    - Word Length = 8 Bits
    - One Stop Bit
    - No parity
    - Hardware flow control disabled (RTS and CTS signals)
    - Receive and transmit enabled
@note: USUART2(COM1) is mapped on GPIO PA9(TX Arduino D1) and PA10(RX Arduino D0) 

@par How to use it ? 

In order to make the program work, you must do the following:
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
