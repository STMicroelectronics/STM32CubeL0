/**
  @page TouchSensing_Linear  Touch Sensing Linear example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the Touch Sensing Linear example.
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

@par Application Description

Use of the STMTouch driver with 1 linear 
sensor. This example also uses ECS and DTO.

Observed behaviour:

- The LD4 lit each time the linear is touched.
- The LD3 blink frequency follow the linear sensor position when touched.

- The ECS is ON when no touch is detected (all sensors are in the RELEASE state).
  The ECS is always present but its behavior can be modified using some parameters in
  the tsl_conf.h file.

- You can experiment the DTO by touching a sensor for few seconds. The RELEASE state
  is automatically entered and a re-calibration is performed after the timeout is reached.
  This timeout is programmable by the TSLPRM_DTO parameter in the tsl_conf.h file.


@par Directory contents

    - TouchSensing_Linear\Inc\main.h                Header for main.c file
    - TouchSensing_Linear\Inc\stm32l0xx_hal_conf.h  HAL Library configuration file
    - TouchSensing_Linear\Inc\stm32l0xx_it.h        Header for stm32l0xx_it.c file
    - TouchSensing_Linear\Src\stmCriticalSection.h  Header for stmCriticalSection.c file
    - TouchSensing_Linear\Inc\tsl_conf.h            STMTouch driver configuration file
    - TouchSensing_Linear\Inc\tsl_user.h            Header for tsl_user.c file

    - TouchSensing_Linear\Src\main.c                Main program file
    - TouchSensing_Linear\Src\stm32l0xx_hal_msp.c   HAL MSP module file
    - TouchSensing_Linear\Src\stm32l0xx_it.c        Interrupt handlers file
    - TouchSensing_Linear\Src\stmCriticalSection.c  STMStudio lock/unlock mechanism file
    - TouchSensing_Linear\Src\system_stm32l0xx.c    System initialization file
    - TouchSensing_Linear\Src\tsl_user.c            Touchsensing channels/banks description file


@par Hardware and Software environment

  - This example runs on STM32L053xx devices.
    
  - This example has been tested with STM32L0538-DISCO board. It can be
    easily tailored to any other devices that embed the TSC peripheral and to
    any other development board supporting touchsensing sensor.


@par How to use it ? 

In order to make the program work, you must do the following:
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 */
