/**
  @page COMP_PulseWidthMeasurement COMP Pulse Width measurement example
  
  @verbatim
  ******************** (C) COPYRIGHT 2012 STMicroelectronics *******************
  * @file    COMP/COMP_PulseWidthMeasurement/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the COMP COMP Pulse Width measurement example.
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

How to configure a comparator peripheral to measure pulse width. This method (measuring
signal pulses using a comparator) is useful when an external signal doesn't respect
the VIL and VIH levels.

  - COMP1 is configured as following:
     - Inverting input is internally connected to DAC output
     - Non Inverting input is connected to PA1
     - Output is internally connected to TIM2 Input Capture 4 (IC4)

  - DAC channel is used as a digital threshold for measurement, DAC output
    is internally connected to COMP2 inverting input. 
    DAC is configured in 12-bit right alignment. DAC output = VREF * DOR / 4095
                                                            = 3.3 * 868 / 4095
                                                            = 0.7V

    In this example, the pulse of an external signal of around 0.7V 
    (e.g. high level = 0.8V and low level = 0.6V) can be performed.

  - TIM2 counter is clocked by TIM2CLK = 32MHz, TIM2 channel 4 is configured in
    input capture mode.
    TIM2 counter is captured at each transition detection: rising or falling edges
    (each time COMP1 inverting input crosses DAC output)

  - External signal should be connected to PA1. 
    Pulse is computed in microsecond then displayed on the debugger in uwMeasuredPulse variable.
    Pulse duration shouldn't be higher than 65535 * TIM2CLK = 2.047 ms
    Pulse duration shouldn't be lower than TIM2 ISR processing time / TIM2CLK 
                                         ~ 110 (clock cycle) / 32 MHz = 3 us

@note To have a precise value of the pulse, HSI as a source of clock system should be 
calibrated or use an external clock.

If LED2 is toggling successively: This indicates that the system generates an error.

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents  

  - COMP/COMP_PulseWidthMeasurement/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - COMP/COMP_PulseWidthMeasurement/Inc/stm32l0xx_it.h          DMA interrupt handlers header file
  - COMP/COMP_PulseWidthMeasurement/Inc/main.h                  Header for main.c module  
  - COMP/COMP_PulseWidthMeasurement/Src/stm32l0xx_it.c          DMA interrupt handlers
  - COMP/COMP_PulseWidthMeasurement/Src/main.c                  Main program
  - COMP/COMP_PulseWidthMeasurement/Src/stm32l0xx_hal_msp.c     HAL MSP file
  - COMP/COMP_PulseWidthMeasurement/Src/system_stm32l0xx.c      STM32L0xx system source file
         
@par Hardware and Software environment

  - This example runs on STM32L051xx, STM32L052xx, STM32L053xx STM32L062xx and 
    STM32L063xx device lines RevZ
    
  - This example has been tested with STM32L053R8-Nucleo RevC  board and can be
    easily tailored to any other supported device and development board.

  - STM32L053R8-Nucleo Set-up
    - Use LED2 connected to PA5 pin.
    - Connect an external signal to PA.01 pin (pin A1 in CN8 connector).


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example
  

 */

