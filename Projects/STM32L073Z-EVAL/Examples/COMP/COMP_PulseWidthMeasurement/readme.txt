/**
  @page COMP_PulseWidthMeasurement COMP Pulse Width measurement example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    COMP/COMP_PulseWidthMeasurement/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the COMP COMP Pulse Width measurement example.
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

How to configure a comparator peripheral to measure pulse width. This method (measuring
signal pulses using a comparator) is useful when an external signal doesn't respect
the VIL and VIH levels.

  - COMP1 is configured as following:
     - Inverting input is internally connected to DAC output, used as a digital 
       threshold for measurement: voltage level can be tuned using
       defined label "COMP_THRESHOLD_MV" (set to 1V by default in this example).
     - Non Inverting input is connected to pin PA.01
     - Output is internally connected to TIM2 Input Capture 4 (IC4)

  - TIM2 counter is used for pulse width measurement.
     - Timer frequency can be tuned using defined label "TIMER_FREQUENCY_HZ" (unit: Hz).
       Frequency the highest (maximum TIM2CLK PCLK1), accuracy pitch the lowest. 
       Maximum pulse length measurable is 65535*pitch
       (if timer set to 100kHz, pulse length measurable is min=10us, max=650ms)
     - TIM2 channel 4 is configured in input capture mode.
       TIM2 counter is captured at each transition detection: rising and falling edges
       (each time COMP1 inverting input crosses non-inverting input connected to DAC output)

Board settings:
  - STM32L073Z-EVAL Set-up
      @note This example run in stand alone mode.
    - Generation of the input signal for pulse width measurement:
      - if user has a signal generator: Provide the signal on COMP1 non-inverting input (pin PA.01)
      - if user has not a signal generator: a DAC spare channel is used to generate a periodic signal
       (signal 100Hz with pulses of 2 ms, frequency can be tuned using defined label "TIMER_FOR_SIGNAL_TEST_FREQUENCY_KHZ" and pulses using variable "Waveform_8bits")
        Into the code, label definition "DAC_SPARE_CHANNEL_FOR_SIGNAL_TEST" must be uncommented.
        Connect a wire between DAC channel (pin PA.05) and COMP1 non-inverting input (pin PA.01).
        => Using this predefined signal with pulse width 2ms, LED1 should be turned-on (disconnect pin PA.01 and the LED should be turned-off).

STM32L073Z-EVAL board's LEDs are used to monitor the program execution status:
 - Normal operation: LED1 is turned-on/off in function of ADC conversion
   result.
    - Turn-off if pulse width is out of range 2ms +- 0.5ms
    - Turn-on if pulse width is within range 2ms +- 0.5ms
 - Error: In case of error, LED3 is toggling at a frequency of 1Hz.
 


@note To have a precise value of the pulse, HSI as a source of clock system should be 
calibrated or use an external clock.


@note Care must be taken when using HAL_Delay(), this function provides 
      accurate delay (in milliseconds) based on variable incremented in SysTick ISR. 
      This implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower) than the 
      peripheral interrupt. Otherwise the caller ISR process will be blocked. 
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set 
      to 1 millisecond to have correct HAL operation.

@par Directory contents 

  - COMP/COMP_PulseWidthMeasurement/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - COMP/COMP_PulseWidthMeasurement/Inc/stm32l0xx_it.h          COMP interrupt handlers header file
  - COMP/COMP_PulseWidthMeasurement/Inc/main.h                  Header for main.c module
  - COMP/COMP_PulseWidthMeasurement/Src/stm32l0xx_it.c          COMP interrupt handlers
  - COMP/COMP_PulseWidthMeasurement/Src/main.c                  Main program
  - COMP/COMP_PulseWidthMeasurement/Src/stm32l0xx_hal_msp.c     HAL MSP file 
  - COMP/COMP_PulseWidthMeasurement/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment 

  - This example runs on STM32L073xx devices.

  - This example has been tested with STM32L073Z-EVAL board and can be
    easily tailored to any other supported device and development board.
    
  - In this example, the clock is set to 2 MHz.
    
  - For this example, the LCD glass should be removed. 

  - For this example, the jumpers JP1, JP2 and CN2 should be removed.  

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */