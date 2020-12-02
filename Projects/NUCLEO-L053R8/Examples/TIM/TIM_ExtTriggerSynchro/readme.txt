/**
  @page TIM_ExtTriggerSynchro TIM External Trigger Synchro example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    TIM/TIM_ExtTriggerSynchro/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the TIM External Trigger Synchro example.  .
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

 Synchronization of TIM peripherals in Cascade mode with an external trigger.
Three timers are used in this example:

  1/TIM2 is configured as Master Timer:
      - Toggle Mode is used
      - The TIM2 Enable event is used as Trigger Output 

  2/TIM2 is configured as Slave Timer for an external Trigger connected to TIM2 
    TI2 pin (TIM2 CH2 configured as input pin):
      - The TIM2 TI2FP2 is used as Trigger Input
      - Rising edge is used to start and stop the TIM2: Gated Mode.

  3/TIM21 is slave for TIM2 and Master for TIM22,
      - Toggle Mode is used
      - The ITR1(TIM2) is used as input trigger 
      - Gated mode is used, so start and stop of slave counter
        are controlled by the Master trigger output signal(TIM2 enable event).
      - The TIM21 enable event is used as Trigger Output. 

  4/TIM22 is slave for TIM21,
      - Toggle Mode is used
      - The ITR2(TIM21) is used as input trigger
      - Gated mode is used, so start and stop of slave counter
        are controlled by the Master trigger output signal(TIM21 enable event).

   The TIM2CLK, TIM21CLK  and TIM22CLK are fixed to 32 MHZ, the Prescaler is 
   equal to 1 so the TIMx clock counter is equal to 16 MHz.

   The Three Timers are running at: 
   TIMx frequency = TIMx clock counter/ 2*(TIMx_Period + 1) = 100 KHz.
   
  The starts and stops of the TIM2 counters are controlled by the external trigger.
  The TIM21 starts and stops are controlled by the TIM2, and the TIM22 starts and 
  stops are controlled by the TIM21.
  
@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents  

  - TIM/TIM_ExtTriggerSynchro/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - TIM/TIM_ExtTriggerSynchro/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - TIM/TIM_ExtTriggerSynchro/Inc/main.h                  Header for main.c module  
  - TIM/TIM_ExtTriggerSynchro/Src/stm32l0xx_it.c          Interrupt handlers
  - TIM/TIM_ExtTriggerSynchro/Src/main.c                  Main program
  - TIM/TIM_ExtTriggerSynchro/Src/stm32l0xx_hal_msp.c     HAL MSP file
  - TIM/TIM_ExtTriggerSynchro/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L051xx, STM32L052xx, STM32L053xx STM32L062xx and 
    STM32L063xx device lines RevZ
    
  - This example has been tested with STM32L053R8-Nucleo RevC  board and can be
    easily tailored to any other supported device and development board.

  - STM32L053R8-Nucleo RevC Set-up 
   - Connect an external trigger to the TIM2 CH2 (PA.1).

    - Connect the following pins to an oscilloscope to monitor the different waveforms:
      - TIM2 CH1 (PA.00) (pin 28 in CN7 connector)
      - TIM21 CH1 (PB.13) (pin 30 in CN10 connector)
      - TIM22 CH1 (PB.04) (pin 27 in CN10 connector)


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example 


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
