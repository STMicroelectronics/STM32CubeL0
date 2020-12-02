/**
  @page ADC_RegularConversion_Polling conversion using Polling

  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    ADC/ADC_RegularConversion_Polling/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the ADC RegularConversion Polling example.
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

How to use the ADC in Polling mode to convert data through the HAL API.

When an end of conversion occurs the converted data of ADC1 DR register is 
affected to the uwADCxConvertedValue variable .

Since ADC1 clock is PCLK (2 MHz) and sampling time is set to 7.5 cycles, the conversion 
time of 12bit data is 12.5 cycles so the total conversion time is (12.5+7.5)/2000000= 10us(0.1Msps).


@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - ADC/ADC_RegularConversion_Polling/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - ADC/ADC_RegularConversion_Polling/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - ADC/ADC_RegularConversion_Polling/Inc/main.h                  Header for main.c module  
  - ADC/ADC_RegularConversion_Polling/Src/stm32l0xx_it.c          Interrupt handlers
  - ADC/ADC_RegularConversion_Polling/Src/main.c                  Main program
  - ADC/ADC_RegularConversion_Polling/Src/stm32l0xx_hal_msp.c     HAL MSP file 
  - ADC/ADC_RegularConversion_Polling/Src/system_stm32l0xx.c      STM32L0xx system source file

@par Hardware and Software environment 

  - This example runs on STM32L07xx and STM32L08xx devices.
  
  - This example has been tested with STM32L073Z-EVAL board and can be
    easily tailored to any other supported device and development board.

  - Connect an external signal to PA.0.
  - To monitor the conversion result, put uwADCxConvertedValue in the live watch.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
