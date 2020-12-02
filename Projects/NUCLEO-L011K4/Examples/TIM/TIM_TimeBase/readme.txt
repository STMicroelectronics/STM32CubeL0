/**
  @page TIM_TimeBase Timebase example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    TIM/TIM_TimeBase/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the TIM Timebase example
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

Configuration of the TIM peripheral to generate a timebase of 
one second with the corresponding interrupt request.

    In this example TIM2 input clock (TIM2CLK) is set to APB1 clock (PCLK1),
    since APB1 prescaler is equal to 1, TIM2CLK = PCLK1 = HCLK = SystemCoreClock
    
    To get TIM2 counter clock at 10 KHz, the timer Prescaler is computed as follow :
    Prescaler = (TIM2CLK / TIM2 counter clock) - 1
    Prescaler = (SystemCoreClock/10 KHz) - 1

SystemCoreClock is set to 2 MHz for STM32L0xx Devices.

The TIM2 ARR register value is equal to 2500 - 1, 
Update rate = TIM2 counter clock / (Period + 1) = 1 Hz,
So the TIM2 generates an interrupt each 1 s

When the counter value reaches the auto-reload register value, the TIM update 
interrupt is generated and, in the handler routine, pin GPIOB.3 (connected to LED3 on board STM32L011K4-Nucleo)
is toggled at the following frequency: 0.5Hz.


@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - TIM/TIM_TimeBase/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - TIM/TIM_TimeBase/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - TIM/TIM_TimeBase/Inc/main.h                  Header for main.c module  
  - TIM/TIM_TimeBase/Src/stm32l0xx_it.c          Interrupt handlers
  - TIM/TIM_TimeBase/Src/main.c                  Main program
  - TIM/TIM_TimeBase/Src/stm32l0xx_hal_msp.c     HAL MSP file
  - TIM/TIM_TimeBase/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L011xx devices.
  - In this example, the clock is set to 2 MHz.
    
  - This example has been tested with STMicroelectronics STM32L011K4-Nucleo
    board and can be easily tailored to any other supported device
    and development board.      

  - STM32L011K4-Nucleo Set-up
    - Use LED3 connected to GPIOB.3 pin and connect them on an oscilloscope 
      to show the Time Base signal.  


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
