/**
  @page ADC_RegularConversion_Interrupt conversion using Interrupt
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    ADC/ADC_RegularConversion_Interrupt/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the ADC RegularConversion Interrupt example.
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

How to use the ADC in interrupt mode to convert data through the HAL API.
  
The ADC is configured to continuously convert channel0, resolution is set to 12
bit right alignment with a software start.
Each time an end of conversion occurs an interrupt is generated and the converted 
data of ADC1 DR register is affected to the uwADCxConvertedValue variable in the 
ADC conversion complete call back function.

In order to reduce power consumption, the low frequency mode is enabled since
the ADC clock is PCLK clock (this mode can be enabled only if ADC clock is lower
than 2.8MHz), combined with AutoWait feature (new conversion is started only
when previous conversion is completed).
  
@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents  

  - ADC/ADC_RegularConversion_Interrupt/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - ADC/ADC_RegularConversion_Interrupt/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - ADC/ADC_RegularConversion_Interrupt/Inc/main.h                  Header for main.c module  
  - ADC/ADC_RegularConversion_Interrupt/Src/stm32l0xx_it.c          Interrupt handlers
  - ADC/ADC_RegularConversion_Interrupt/Src/main.c                  Main program
  - ADC/ADC_RegularConversion_Interrupt/Src/stm32l0xx_hal_msp.c     HAL MSP module
  - ADC/ADC_RegularConversion_Interrupt/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L053xx devices.
    
  - This example has been tested with STM32L0538-DISCO RevB  board and can be
    easily tailored to any other supported device and development board.

  - Connect an external signal to PA.0.
  - To monitor the conversion result, put uwADCxConvertedValue in the live watch.
    To convert the read value in volts, here is the equation to apply :
    Voltage = uhADCxConvertedValue * (Vref+ - Vref-) / (2^12 - 1) = uhADCxConvertedValue * 3.3 / 4095 as Vref+ = 3.3V, Vref- = 0V and resolution is 12 bits

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example 


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
