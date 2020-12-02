/**
  @page COMP_PWMSignalControl COMP PWM Signal Control example
  
  @verbatim
  ******************** (C) COPYRIGHT 2012 STMicroelectronics *******************
  * @file    COMP/COMP_PWMSignalControl/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the COMP PWM Signal Control example.
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
  
How to configure a comparator peripheral to automatically hold the TIMER PWM output
in the safe state (low level) as soon as the comparator output is set to a high
level.

  - COMP1 is configured as following:
     - Inverting input is internally connected to VREFINT = 1.22V
     - Output is internally connected to LPTIM 
     
     
LPTIM generates a PWM at the lowest power consumption, using the output signal of 
Comparator.

  - While PA1 is higher than VREFINT (1.22V), PWM signal is displayed on PC1.
  - While PA1 is lower than VREFINT, PC1 is in low level.
  
The Autorelaod equal to 99 so the output frequency (OutputFrequency) will
be equal to the external counter clock (InputFrequency) divided by (99+1).

  OutputFrequency = InputFrequency / (Autoreload + 1)
                  = InputFrequency / 100

Pulse value equal to 49 and the duty cycle (DutyCycle) is computed as follow:

  DutyCycle = 1 - [(PulseValue + 1)/ (Autoreload + 1)]
  DutyCycle = 50%

  - External square signal should be connected to PA1 (Inverting input of COMP1),
    when the amplitude is higher than 1.22V, PWM signal is displayed on PC1, otherwise PC1 is in low level.

  - Connect an oscilloscope to LPTIM PC1 to display waveforms.
                         
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

  - COMP/COMP_PWMSignalControl/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - COMP/COMP_PWMSignalControl/Inc/stm32l0xx_it.h          DMA interrupt handlers header file
  - COMP/COMP_PWMSignalControl/Inc/main.h                  Header for main.c module  
  - COMP/COMP_PWMSignalControl/Src/stm32l0xx_it.c          DMA interrupt handlers
  - COMP/COMP_PWMSignalControl/Src/main.c                  Main program
  - COMP/COMP_PWMSignalControl/Src/stm32l0xx_hal_msp.c     HAL MSP file
  - COMP/COMP_PWMSignalControl/Src/system_stm32l0xx.c      STM32L0xx system source file
         
@par Hardware and Software environment

  - This example runs on STM32L051xx, STM32L052xx, STM32L053xx STM32L062xx and 
    STM32L063xx device lines RevZ
    
  - This example has been tested with STM32L053R8-Nucleo RevC  board and can be
    easily tailored to any other supported device and development board.

  - STM32L053R8-Nucleo Set-up
    - Use LED2 connected to PA5 pin.
    - Connect an external signal to PA.01 pin (pin A1 in CN8 connector).
    - Connect the scope to PC1 (pin 36 in CN7 connector or pin A4 in CN8 connector) to display the PWM signal.
       
@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example
  
 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

