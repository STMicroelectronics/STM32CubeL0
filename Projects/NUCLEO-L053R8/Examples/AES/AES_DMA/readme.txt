/**
  @page AES_DMA  Encrypt and Decrypt data using AES Algo in ECB chaining
   mode using DMA
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    AES/AES_DMA/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the AES Algorithm in ECB mode with DMA Example
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

How to use the AES peripheral to encrypt and decrypt data using AES Algorithm
with ECB chaining mode.

For this example, DMA is used to transfer data from memory to the AES processor
input and also to transfer data from AES processor output to memory.

The data to be encrypted is a 256-bit data (8 words), which correspond to
2x AES-128 Blocks.

This example behaves as below: 
- AES Encryption (Plain Data --> Encrypted Data)
- AES Key preparation for decryption (Encryption Key --> Decryption Key)
- AES Decryption (Encrypted Data --> Decrypted Data)

LED2 is used to notify if the Encryption/Decryption failed

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents  

  - AES/AES_DMA/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - AES/AES_DMA/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - AES/AES_DMA/Inc/main.h                  Header for main.c module  
  - AES/AES_DMA/Src/stm32l0xx_it.c          Interrupt handlers
  - AES/AES_DMA/Src/main.c                  Main program
  - AES/AES_DMA/Src/stm32l0xx_hal_msp.c     HAL MSP module
  - AES/AES_DMA/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L06x devices RevZ
    
  - This example has been tested with STM32L053R8-Nucleo RevC  board and can be
    easily tailored to any other supported device and development board.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example 



 */
