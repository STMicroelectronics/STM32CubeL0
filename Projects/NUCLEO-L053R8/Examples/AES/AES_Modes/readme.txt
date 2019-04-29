/**
  @page AES_MODES  Use AES to encrypt then to decrypt data
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    AES/AES_Modes/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the AES encryption decryption example.
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

How to configure the AES hardware accelerator to encrypt then to decrypt text
with the different modes ECB, CBC and CTR.

Select the AES modes to be performed by uncommenting the corresponding line inside 
the main.h file.

// #define AES_ECB
// #define AES_CBC
// #define AES_CTR

This example is a basic example using polling on flag, neither interrupt nor 
DMA capability are used.

After encryption, the user presses to Key button to execute the decryption on each mode. 

LED2 is togged to notify if the Encryption/Decryption failed.
LED2 is turned on to notify if the Encryption/Decryption passed.

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents  

  - AES/AES_Modes/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - AES/AES_Modes/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - AES/AES_Modes/Inc/main.h                  Header for main.c module  
  - AES/AES_Modes/Src/stm32l0xx_it.c          Interrupt handlers
  - AES/AES_Modes/Src/main.c                  Main program
  - AES/AES_Modes/Src/system_stm32l0xx.c      STM32L0xx system source file
  - AES/AES_Modes/Src/stm32l0xx_hal_msp.c     HAL MSP module


@par Hardware and Software environment

  - This example runs on STM32L06x devices RevZ
    
  - This example has been tested with STM32L053R8-Nucleo RevC  board and can be
    easily tailored to any other supported device and development board.
  
  - STM32L053R8-Nucleo Set-up
    - Use LED2 connected to PA.05 pin
    - Use KEY push button connected to PC.13 pin
          
@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example 


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
