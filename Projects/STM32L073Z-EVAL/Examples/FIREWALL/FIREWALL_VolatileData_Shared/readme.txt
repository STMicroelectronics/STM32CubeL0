/**
  @page FIREWALL_VolatileData_Shared FIREWALL Volatile Data sharing example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    FIREWALL/FIREWALL_VolatileData_Shared/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the FIREWALL volatile data segment sharing example.
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
 
How to use the Firewall Peripheral to protect a code segment as well as volatile and
non-volatile data segments.
The volatile data segment is located in SRAM.
The non-volatile data segment is located in Flash memory.

In the example Firewall initialization, the protected volatile data segment is 
first defined as shared so that it can be accessed by non protected code.

For Firewall demonstration's sake, two Firewall sofware resets are purposedly
triggered.
- the first one in accessing the protected non-volatile data segment
- the second one in accessing the protected volatile data segment once 
the sharing feature has been disabled.


The Firewall-protected memory segments are defined as follows

  |                           |
  |                           |
  |___________________________|  0x2000023F
  |                           |
  |   Volatile data segment   |
  |___________________________|  0x20000000
  |                           |
  |                           |
  |                           |  
  |___________________________| 0x080050FF
  |                           |
  | Non-volatile data segment |
  |___________________________| 0x08005000
  |                           |
  |___________________________| 0x080041FF
  |                           |
  |       Code segment        |
  |___________________________| 0x08004000
  |                           |
  

 The example unrolls as follows.
 
 The main() function starts its first run.
 The Firewall is configured such that the volatile data segment is shared
 with non protected code.
 Protected code (that could be the user application code) is executed and it is verified that
 - the array located in the volatile data segment is updated as expected
 - no Firewall reset occurs when unprotected code segment accesses the array.
 
 Next, while the Firewall is closed, a Firewall reset is purposedly triggered
 in accessing an array located in the protected non-volatile data segment.
 
 This leads to a software reset and a second main() run.
 The second run is similar to the first one, the firewall is configured the
 same way but this time, the protected code when called disables the volatile 
 data sharing feature.
 
 A second Firewall reset is purposedly triggered in accessing the no more
 shared array located in the protected volatile data segment.
 
 If the code unrolls as expected, LED1 is turned on.
 If an error occurs (unexpected Firewall reset or any other unexpected
 result), LED1 blinks in transmiting a sequence of three dots, three dashes, three dots.


 The Firewall-triggered software resets lead to resort to RTC back-up registers
 to keep track of the code unrolling. The latter are not related to Firewall
 feature but their usage is shown for possible debugging purposes.

 The table below lists them and provides their meaning.

                
 register\value |        0         |               1              |     2
 ------------------------------------------------------------------------------
 RTC->BKP4R     |   Example very   |      main() first run        |    main() 
                |   first start    |                              |  second run
 ------------------------------------------------------------------------------                  
 RTC->BKP0R     |  Initial value   |   Access to protected        |   VDS has 
                |                  |   volatile data segment      |    been
                |                  |   successful when VDS=1      |    reset
 ------------------------------------------------------------------------------                  
 RTC->BKP1R     |  Initial value   |  Unexpected Firewall reset   |    N/A
 ------------------------------------------------------------------------------                  
 RTC->BKP2R     |  Initial value   | No Firewall reset occurred   |    N/A 
                |                  | when protected non-volatile  |  
                |                  | data were accessed,          |  
                |                  | although reset was expected  |  
 ------------------------------------------------------------------------------                  
 RTC->BKP3R     |  Initial value   | No Firewall reset occurred   |    N/A 
                |                  | when protected volatile      |  
                |                  | data were accessed, although |  
                |                  | reset was expected           |  
 ------------------------------------------------------------------------------                                       
                                      
 When the software detects a Firewall reset with RTC->BKP0R = 2, it infers
 that the code properly behaved, ending up by an expected Firewall software
 reset due to unauthorized access to protected volatile data while the
 Firewall was closed.
                                                                                                                 

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - FIREWALL/FIREWALL_VolatileData_Shared/Inc/stm32l0xx_conf.h         HAL Configuration file
  - FIREWALL/FIREWALL_VolatileData_Shared/Inc/stm32l0xx_it.h           Header for stm32l0xx_it.c
  - FIREWALL/FIREWALL_VolatileData_Shared/Inc/main.h                   Header file for main.c
  - FIREWALL/FIREWALL_VolatileData_Shared/Inc/protected_code.h         Header file for protected_code.c  
  - FIREWALL/FIREWALL_VolatileData_Shared/Src/system_stm32l0xx.c       STM32L0xx system clock configuration file
  - FIREWALL/FIREWALL_VolatileData_Shared/Src/stm32l0xx_it.c           Interrupt handlers
  - FIREWALL/FIREWALL_VolatileData_Shared/Src/main.c                   Main program
  - FIREWALL/FIREWALL_VolatileData_Shared/Src/protected_code.c         Code to be located in protected code segment
  - FIREWALL/FIREWALL_VolatileData_Shared/Src/proprotected_nonvolatile_data.c Data to be located in protected non-volatile data segment
  - FIREWALL/FIREWALL_VolatileData_Shared/Src/protected_volatile_data.c       Data to be located in protected volatile data segment
  - FIREWALL/FIREWALL_VolatileData_Shared/EWARM/stm32l073xx_flash.icf Scatter file for proper placing in memory            

@par Hardware and Software environment


  - This example runs on STM32L073xx devices
      
  - This example has been tested with STMicroelectronics STM32L073Z-EVAL
    evaluation board and can be easily tailored to any other supported device 
    and development board.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
