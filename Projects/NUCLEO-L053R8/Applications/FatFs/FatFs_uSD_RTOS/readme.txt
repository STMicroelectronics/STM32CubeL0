/**
  @page FatFs_uSD_RTOS   FatFs with uSD card drive in RTOS mode example
 
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the FatFs with uSD card drive in RTOS mode example
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  @endverbatim

@par Application Description

How to use STM32Cube firmware with FatFs middleware component as a generic FAT
file system module. This example develops an application exploiting FatFs
features, with a microSD drive in RTOS mode configuration.

At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system clock
(SYSCLK) to run at 32 MHz.

The application is based on writing and reading back a text file from a drive,
it creates a normal priority thread and it's performed using FatFs APIs to 
access the FAT volume as described in the following steps: 

 - Link the uSD disk I/O driver;
 - Register the file system object (mount) to the FatFs module for the uSD drive;
 - Create and Open new text file object with write access;
 - Write data to the text file;
 - Close the open text file;
 - Open text file object with read access;
 - Read back data from the text file;
 - Close the open text file;
 - Check on read data from text file;
 - Unlink the uSD disk I/O driver.

It is worth noting that the application manages any error occurred during the 
access to FAT volume, when using FatFs APIs. Otherwise, user can check the 
application status through "DemoState" variable value or check if the
written text file is available on the uSD card.

It is possible to fine tune needed FatFs features by modifying defines values 
in FatFs configuration file “ffconf.h” available under the project includes 
directory, in a way to fit the application requirements. 

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents
 
  - FatFs/FatFs_uSD_RTOS/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - FatFs/FatFs_uSD_RTOS/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - FatFs/FatFs_uSD_RTOS/Inc/main.h                  Header for main.c module
  - FatFs/FatFs_uSD_RTOS/Inc/ffconf.h                FAT file system module configuration file   
  - FatFs/FatFs_uSD_RTOS/Inc/sd_diskio.h             FatFs uSD diskio header file
  - FatFs/FatFs_uSD_RTOS/Src/stm32l0xx_it.c          Interrupt handlers
  - FatFs/FatFs_uSD_RTOS/Src/main.c                  Main program
  - FatFs/FatFs_uSD_RTOS/Src/sd_diskio.c             FatFs uSD diskio driver implementation
  - FatFs/FatFs_uSD_RTOS/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L051xx, STM32L052xx, STM32L053xx STM32L062xx and 
    STM32L063xx device lines RevZ
    
  - This example has been tested with STM32L053R8-Nucleo RevC board and can be
    easily tailored to any other supported device and development board.
     
  - A SDSC microSD card (capacity up to 4GB)
    
  - Adafruit 1.8" TFT shield must be connected on CN5,CN6, CN8 and CN9 Arduino connectors, 
    for more details please refer to UM1726.

For more details about the adafruit 1.8" TFT shield, please visit: 
http://www.adafruit.com/blog/2012/04/26/new-product-adafruit-1-8-18-bit-color-tft-shield-wmicrosd-and-joystick/


@par How to use it ? 

In order to make the program work, you must do the following:
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
 
