/**
  @page PWR_Standby PWR_STANDBY example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    PWR/PWR_Standby/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the PWR STANDBY example.
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

How to enter the Standby mode and wake up from this mode by using an external 
reset or the WKUP pin.

This example shows also how to configure the STM32L0xx system to measure 
STANDBY mode current consumption.

In the associated software, the system clock is set to 2 MHz, the SysTick is 
programmed to generate an interrupt each 1 ms.

In the associated software
  - the system clock is set to 2 MHz
  - Wake Up Pin 1 is configured to wake up the system after entering Standby mode
  - the SysTick is programmed to generate an interrupt each 1 ms.
  
The system enters STANDBY mode after 5s and will wait for injecting 3.3V on PA.0
wake up Pin 1. Current consumption could be monitored through an amperemeter.

The above scenario is repeated in an infinite loop.

To reach the right MCU power consumption in run mode you must:
  - Remove solder Bridge SB17 to disconnect the User Push-Button(B1) from VDD (~3µA).
  - Comment the BSP_LED_Init(LED2) line in main.c file (~11µA)
  
LED2 ON: HAL configuration failed (system will go to an infinite loop)


    - STANDBY Mode 
    ===============
            - VREFINT OFF with fast wakeup enabled
            - No IWDG
            - Wakeup using WakeUp Pin 1 (PA.0)


@note This example can not be used in DEBUG mode, this is due to the fact 
      that the Cortex-M0+ core is no longer clocked during low power mode 
      so debugging features are disabled
      
@note To update the example to use PWR_WAKEUP_PIN2 as wake up source from standby mode,
      you must remove the solder bridge SB17 in order to disconnect wake up pin 2(PC13) from VDD.

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents  

  - PWR/PWR_STANDBY/Inc/stm32l0xx_conf.h     Library Configuration file
  - PWR/PWR_STANDBY/Inc/stm32l0xx_it.h       Header for stm32l0xx_it.c
  - PWR/PWR_STANDBY/Inc/main.h               header file for main.c
  - PWR/PWR_STANDBY/Src/system_stm32l0xx.c   STM32L0xx system clock configuration file
  - PWR/PWR_STANDBY/Src/stm32l0xx_it.c       Interrupt handlers
  - PWR/PWR_STANDBY/Src/main.c               Main program
  - PWR/PWR_STANDBY/Src/stm32l0xx_hal_msp.c  HAL MSP module

@par Hardware and Software environment

  - This example runs on STM32L051xx, STM32L052xx, STM32L053xx STM32L062xx and 
    STM32L063xx device lines RevZ
    
  - This example has been tested with STM32L053R8-Nucleo RevC  board and can be
    easily tailored to any other supported device and development board.

  - STM32L053R8-Nucleo Set-up
    - Use LED2 connected PA.05 pin
    - connect PA0 (pin 28 in CN7 connector) to 3.3v to wake up from standby mode.
    - Connect an amperemeter to JP6 to measure the IDD current

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
