/**
  @page PWR_PVD PWR Programmable Voltage Detector (PVD) example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    PWR/PWR_PVD/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the PWR Programmable Voltage Detector (PVD) example
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
How to configure the programmable voltage detector by using an external interrupt 
line. External DC supply must be used to supply Vdd.

In this example, EXTI line 16 is configured to generate an interrupt on each rising
or falling edge of the PVD output signal (which indicates that the Vdd voltage is
below the PVD threshold).
In the interrupt routine the LED3 is toggled every time the voltage drops below 
or above the target threshold.

In this example, the PVD detection level set to 2.5V.

If LED3 is toggling successively: This indicates that the system generates an error.
To use this test, program must be flashed and executed using an external power supply :
  - Unconnect ST-link USB connector
  - Connect an external power supply between GND and 3V_O pin on P2 connector
  - Apply a 3,3V power supply voltage (never apply a power supply greater than 3,3V to avoid damages)
  - Decrease power supply voltage to around 2,5V
  - LED3 must blinks when power supply voltage is around 2,5V

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - PWR/PWR_PVD/Inc/stm32l0xx_conf.h     Library Configuration file
  - PWR/PWR_PVD/Inc/stm32l0xx_it.h       Header for stm32l0xx_it.c
  - PWR/PWR_PVD/Inc/main.h               header file for main.c
  - PWR/PWR_PVD/Src/system_stm32l0xx.c   STM32L0xx system clock configuration file
  - PWR/PWR_PVD/Src/stm32l0xx_it.c       Interrupt handlers
  - PWR/PWR_PVD/Src/main.c               Main program
  - PWR/PWR_PVD/Src/stm32l0xx_hal_msp.c  HAL MSP module

@par Hardware and Software environment

  - This example runs on STM32L053xx devices.

  - This example has been tested with STMicroelectronics STM32L0538-DISCO REVB board
    and can be easily tailored to any other supported device and development board.

  - STM32L0538-DISCO Set-up
    - Remove the jumper JP4
    - Apply an external voltage to the pin5 (VDD) of P2 
    - Use LED3 connected to PB.04 pin

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
