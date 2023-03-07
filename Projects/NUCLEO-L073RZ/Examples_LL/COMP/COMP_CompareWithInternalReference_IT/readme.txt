/**
  @page COMP_CompareWithInternalReference_IT COMP example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    Examples_LL/COMP/COMP_CompareWithInternalReference_IT/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the COMP_CompareWithInternalReference_IT example.
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

How to use a comparator peripheral to compare a voltage level applied on a GPIO
pin to the internal voltage reference (VREFINT), in interrupt mode. This example
is based on the STM32L0xx COMP LL API. The peripheral initialization
uses LL unitary service functions for optimization purposes (performance and size).

Example configuration:
Comparator instance COMP1 is configured with input minus set to
internal voltage reference VrefInt (voltage level 1.2V, refer to
device datasheet for min/typ/max values), input plus set to
a GPIO pin (cf pin below) in analog mode.
Comparator interruption is enabled through EXTI line 21 with trigger edge
set to both edges rising and falling.
Comparator is set in mode ultra low power.

Example execution:
From the main program execution, comparator is enabled.
Each time the voltage level applied on GPIO pin (comparator input plus) passes through
VrefInt threshold (comparator input minus), the comparator generates an interruption.
LED is turned on or off depending on comparator output state:
turned on if comparator input plus is higher than input minus,
turned-off otherwise.

Connection needed:
A voltage must be supplied to the analog input pin (cf pin below),
between Vdda=3.3V and 0V. Otherwise this pin can be let floating (but in this
case COMP comparison level will be undetermined).
A wire can be used to connect the GPIO pin (cf pin below) either to ground or
to voltage of power supply Vdda (on board Nucleo: Vdda=3.3V, available on CN7 pin 5).

Other peripheral used:
  1 GPIO for LED
  1 GPIO for analog input: PA.01 (Morpho connector CN7 pin 30)
  EXTI line 21 (connected to COMP1 output)


@par Directory contents 

  - COMP/COMP_CompareWithInternalReference_IT/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - COMP/COMP_CompareWithInternalReference_IT/Inc/main.h                  Header for main.c module
  - COMP/COMP_CompareWithInternalReference_IT/Inc/stm32_assert.h          Template file to include assert_failed function
  - COMP/COMP_CompareWithInternalReference_IT/Src/stm32l0xx_it.c          Interrupt handlers
  - COMP/COMP_CompareWithInternalReference_IT/Src/main.c                  Main program
  - COMP/COMP_CompareWithInternalReference_IT/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L073xx devices.
    
  - This example has been tested with STM32L073RZ-Nucleo Rev C board and can be
    easily tailored to any other supported device and development board.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example


 */
