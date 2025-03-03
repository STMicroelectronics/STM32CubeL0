/**
  @page TSC_BasicAcquisition_Interrupt Touch-Sensing basic acquisition using interrupt

  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    TSC/TSC_BasicAcquisition_Interrupt/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the TSC basic acquisition interrupt example.
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

Use of he TSC to perform continuous acquisitions 
of two channels in Interrupt mode.

At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system
clock (SYSCLK) to run at 32 MHz.

The TSC peripheral configuration is ensured by the HAL_TSC_Init() function.
This later is calling the HAL_TSC_MspInit()function which core is implementing
the configuration of the needed TSC resources according to the used hardware (CLOCK, 
GPIO and NVIC). You may update this function to change TSC configuration.

The TSC acquisition is then initiated.
When the end of acquisition occurs, the acquired data are affected to the
uhTSCAcquisitionValue[] variable.
Depending of value of uhTSCAcquisitionValue[] under the max threshold values,
the corresponding LEDs are set ON.
These max threshold values can be modified in top of main.c, due to disparity link to board layout quality.

STM32L073Z-EVAL's LEDs are used as follows:
  - LED4, LED3 and LED2 show the touch activity for each channel.
  - LED3 toggles when an error occurs (TSC initialization, TSC start or assert).

@note TSCx instance used and associated resources can be updated in "main.h"
file depending hardware configuration used.

@note TSCx_TS1_MAXTHRESHOLD, TSCx_TS2_MAXTHRESHOLD and TSCx_TS3_MAXTHRESHOLD can be modify 
if expected result is not satisfied.
These values are link to board layout quality.
To calibrate these value, need to check result of uhTSCAcquisitionValue[] when your digits is near or touch the sensor.
The new max threshold for each channel are around 1% under these values.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - TSC/TSC_BasicAcquisition_Interrupt/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - TSC/TSC_BasicAcquisition_Interrupt/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - TSC/TSC_BasicAcquisition_Interrupt/Inc/main.h                  Header for main.c module  
  - TSC/TSC_BasicAcquisition_Interrupt/Src/stm32l0xx_it.c          Interrupt handlers
  - TSC/TSC_BasicAcquisition_Interrupt/Src/main.c                  Main program
  - TSC/TSC_BasicAcquisition_Interrupt/Src/stm32l0xx_hal_msp.c     HAL MSP file 
  - TSC/TSC_BasicAcquisition_Interrupt/Src/system_stm32l0xx.c      STM32L0xx system source file

@par Hardware and Software environment 

  - This example runs on STM32L073VZ devices.
  
  - This example has been tested with STM32L073Z-EVAL board and can be
    easily tailored to any other supported device and development board.

  - The TSC feature needs a HW modification of the PCB. Please refer to the chapter Touch Sensing Slider of 
    the STM32L073Z-EVAL board User Manual.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 */
