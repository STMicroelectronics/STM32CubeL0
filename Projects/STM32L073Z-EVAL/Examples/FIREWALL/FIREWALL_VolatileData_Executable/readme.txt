/**
  @page FIREWALL_VolatileData_Executable FIREWALL executable volatile data protection example
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    FIREWALL/FIREWALL_VolatileData_Executable/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the FIREWALL executable volatile data segment protection example.
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
 
How to use the Firewall Peripheral to protect a volatile data segment and to define it
as executable.

In the example Firewall initialization, the protected volatile data segment is 
defined as non-shared so that it can't be accessed by non protected code when
the Firewall is closed.



The Firewall-protected memory segment is split in two sub segments ("a" region
and "b" region) defined as follows by the scatter file 


  |___________________________| 
  |                           |   0x20004FFF
  |                           |
  |            RAM            |  
  |                           |
  |___________________________|   0x20003000
  |                           |   0x20002FFF
  |   Volatile data segment   |
  |        "b" region         |
  |           (data)          |  
  |___________________________|  0x20002E00
  |                           |  0x20002DFF
  |   Volatile data segment   |
  |        "a" region         | 
  |          (code)           |     
  |___________________________|  0x20002104
  |___________________________|   
  |                           |  0x20001FFF
  |                           |
  |            ROM            | 
  |                           |  
  |___________________________|  0x20000000
  |                           |

  

 The example unrolls as follows.
 
 The Firewall is first configured such that the volatile data segment is defined
 as executable.
 Protected code (that could be the user application code) located in protected
 volatile data segment (in "a" region) is executed twice and it is verified that
 its processing returns the expected output each time.

 Two different ways to invoke the protected executable data are shown in the
 example, as well as the FPA bit reset when the Firewall is closed to avoid
 any unwanted access to the protected area. 

 
 If the code unrolls as expected, LED1 is turned on.
 If an error occurs (unexpected Firewall reset or any other unexpected
 result), LED1 blinks in transmiting a sequence of three dots, three dashes, three dots.


 The Firewall software reset leads to resort to RTC back-up registers
 to keep track of the code unrolling. The latter are not related to Firewall
 feature but their usage is shown for possible debugging purposes.

 The table below lists them and provides their meaning.

              
 reg.\value   |       0       |             1             |        2
 ------------------------------------------------------------------------------
 RTC->BKP4R   |  Example very |  main() has been started  |        N/A
              |  first start  |    at least one time      |  
 -----------------------------------------------------------------------------                  
 RTC->BKP0R   | Initial value |     Unexpected Firewall   | Uncorrect protected
              |               |           reset           | function first run 
 -----------------------------------------------------------------------------                  
 RTC->BKP1R   | Initial value | Unexpected software reset | Uncorrect protected
              |               | (not Firewall-triggered)  | function second run
 -----------------------------------------------------------------------------                                       

                                                                                                                 

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - FIREWALL/FIREWALL_VolatileData_Executable/Inc/stm32l0xx_conf.h         HAL Configuration file
  - FIREWALL/FIREWALL_VolatileData_Executable/Inc/stm32l0xx_it.h           Header for stm32l0xx_it.c
  - FIREWALL/FIREWALL_VolatileData_Executable/Inc/main.h                   Header file for main.c
  - FIREWALL/FIREWALL_VolatileData_Executable/Inc/protected_vdata_code.h   Header file for protected_vdata_code.c 
  - FIREWALL/FIREWALL_VolatileData_Executable/Src/system_stm32l0xx.c       STM32L0xx system clock configuration file
  - FIREWALL/FIREWALL_VolatileData_Executable/Src/stm32l0xx_it.c           Interrupt handlers
  - FIREWALL/FIREWALL_VolatileData_Executable/Src/main.c                   Main program
  - FIREWALL/FIREWALL_VolatileData_Executable/Src/protected_vdata_code.c         Code to be located in protected volatile data segment
  - FIREWALL/FIREWALL_VolatileData_Executable/Src/protected_volatile_data.c       Data to be located in protected volatile data segment
  - FIREWALL/FIREWALL_VolatileData_Executable/EWARM/stm32l073xx_sram.icf   Scatter file for proper placing in memory            

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
