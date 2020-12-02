/**
  @page TIM_OCToggle TIM_OCToggle example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    TIM/TIM_OCToggle/readme.txt 
  * @author  MCD Application Team
  * @brief   This example shows how to configure the Timer to generate four different 
  *          signals with four different frequencies.
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

Configuration of the TIM peripheral to generate four different 
signals at four different frequencies.

  The TIM2 frequency is set to SystemCoreClock, and the objective is
  to get TIM2 counter clock at 2.1 MHz so the Prescaler is computed as following:
     - Prescaler = (TIM2CLK /TIM2 counter clock) - 1
   
  SystemCoreClock is set to 2 MHz for STM32L0xx Devices.

  The TIM2 CCR1 register value is equal to 5384:
  CC1 update rate = TIM2 counter clock / CCR1_Val = 390 Hz,
  so the TIM2 Channel 1 generates a periodic signal with a frequency equal to 195 Hz.

  The TIM2 CCR2 register value is equal to 2692:
  CC2 update rate = TIM2 counter clock / CCR2_Val = 780 Hz,
  so the TIM2 channel 2 generates a periodic signal with a frequency equal to 390 Hz.

  The TIM2 CCR3 register value is equal to 1346:
  CC3 update rate = TIM2 counter clock / CCR3_Val = 1560 Hz,
  so the TIM2 channel 3 generates a periodic signal with a frequency equal to 780 Hz.

  The TIM2 CCR4 register value is equal to 673:
  CC4 update rate = TIM2 counter clock / CCR4_Val =  3120 Hz,
  so the TIM2 channel 4 generates a periodic signal with a frequency equal to 1560 Hz.

@note PWM signal frequency values mentioned above are theoretical (obtained when the system clock frequency
      is exactly 2 MHz). Since the generated system clock frequency may vary from one board to another observed
      PWM signal frequency might be slightly different.
	  
@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - TIM/TIM_OCToggle/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - TIM/TIM_OCToggle/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - TIM/TIM_OCToggle/Inc/main.h                  Header for main.c module  
  - TIM/TIM_OCToggle/Src/stm32l0xx_it.c          Interrupt handlers
  - TIM/TIM_OCToggle/Src/main.c                  Main program
  - TIM/TIM_OCToggle/Src/stm32l0xx_hal_msp.c     HAL MSP file
  - TIM/TIM_OCToggle/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L073xx devices.
    
  - This example has been tested with STMicroelectronics STM32L073Z-EVAL 
    board and can be easily tailored to any other supported device 
    and development board.      

  - STM32L073Z-EVAL Set-up
   Connect the following pins to an oscilloscope to monitor the different waveforms:
      - PA.15: (TIM2_CH1) (connected to PA.15 (pin 21 in CN10 connector))
      - PA.01: (TIM2_CH2) (connected to PA.01 (pin 47 in CN14 connector))
      - PA.02: (TIM2_CH3) (connected to PA.02 (pin 35 in CN10 connector))
      - PA.03: (TIM2_CH4) (connected to PA.03 (pin 33 in CN10 connector))

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example


CH1      _______________________________________                     
    ____|                                       |___________________

CH2      ___________________                     ___________________
   _____|                   |___________________|
   
CH3      _________           _________           _________
   _____|         |_________|         |_________|         |_________
   
CH4      ____      ____      ____      ____      ____      ____    
    ____|    |____|    |____|    |____|    |____|    |____|    |____    


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
