/**
  @page ADC_DMA_Transfer ADC DMA Transfer example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    ADC/ADC_DMA_Transfer/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the ADC DMA Transfer example.
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

How to configure and use the ADC to convert an external analog input and get 
the result using a DMA transfer through the HAL API.
  
The ADC is configured to continuously convert channel0, resolution is set to 12
bit right alignment with a software start.
In order to reduce power consumption, the low frequency mode is enabled since
the ADC clock is PCLK clock (this mode can be enabled only if ADC clock is lower
than 2.8MHz), combined with AutoWait feature (new conversion is started only
when previous conversion is completed).

DMA1-Channel1-Request0 is configured in Circular mode to transfer continuously
the content of the ADC_DR (Data Register) to aResultDMA which handles the
conversion result.

  
@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents  

  - ADC/ADC_DMA_Transfer/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - ADC/ADC_DMA_Transfer/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - ADC/ADC_DMA_Transfer/Inc/main.h                  Header for main.c module  
  - ADC/ADC_DMA_Transfer/Src/stm32l0xx_it.c          Interrupt handlers
  - ADC/ADC_DMA_Transfer/Src/main.c                  Main program
  - ADC/ADC_DMA_Transfer/Src/stm32l0xx_hal_msp.c     HAL MSP file
  - ADC/ADC_DMA_Transfer/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L051xx, STM32L052xx, STM32L053xx STM32L062xx and 
    STM32L063xx device lines RevZ
    
  - This example has been tested with STM32L053R8-Nucleo RevC  board and can be
    easily tailored to any other supported device and development board.

  - Connect an external signal to PA.0 (A0 Arduino connector).
  - To monitor the conversion result, put aResultDMA in the live watch.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example 


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
