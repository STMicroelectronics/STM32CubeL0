/**
  @page CRYP_AESModes  Encrypt and Decrypt data using AES Algo in ECB/CBC/CTR
  chaining modes with all possible key sizes.
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    CRYP/CRYP_AESModes/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the CRYP AES Algorithm in all modes and all key sizes
             Example
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

=================================================================================
WARNING :
To run this example, you must use an STM32L021xx device.
By default, the STM32L011K4-Nucleo boards (Nucleo32) are equipped with an STM32L011xx 
device which doesn't support the AES feature.
=================================================================================

How to use the CRYP peripheral to encrypt and decrypt data using AES in chaining
modes (ECB, CBC, CTR).

In this example, the following key size is used: 128.

For this example, a firmware is used to interface with the Crypto peripheral
in polling mode.

This example behaves as follows:

1. ECB mode:
   - AES128 ECB encryption
   - AES128 ECB decryption
2. CBC mode:
   - AES128 CBC encryption
   - AES128 CBC decryption
3. CTR mode:
   - AES128 CTR encryption
   - AES128 CTR decryption


The Plain data, encrypted data and decrypted data can be displayed on a PC
HyperTerminal using the UART.

  
@par Directory contents 

  - CRYP/CRYP_AESModes/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - CRYP/CRYP_AESModes/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - CRYP/CRYP_AESModes/Inc/main.h                  Header for main.c module  
  - CRYP/CRYP_AESModes/Src/stm32l0xx_it.c          Interrupt handlers
  - CRYP/CRYP_AESModes/Src/main.c                  Main program
  - CRYP/CRYP_AESModes/Src/stm32l0xx_hal_msp.c     HAL MSP module
  - CRYP/CRYP_AESModes/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L021xx devices.

  - This example has been tested with STM32L011K4-Nucleo board with socket using STM32L021xx plugged-in  
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



 */
