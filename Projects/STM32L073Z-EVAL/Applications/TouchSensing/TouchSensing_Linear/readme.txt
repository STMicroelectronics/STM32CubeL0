/**
  @page TouchSensing 1 linear sensor example
 
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    TouchSensing\TouchSensing_Linear\readme.txt
  * @author  MCD Application Team
  * @brief   Description of the TouchSensing 1 linear sensor example.
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

- The LED3, LED2 and LED1 follow the linear sensor position when touched.
- The LED4 blinks each time the ECS process is finished.
- The LED3 blinks continuously in case of error.

- On the LCD are also displayed:
  * The ECS state (ON/OFF).
  * The linear sensor state (RELEASE, DETECT, ...) and the position (0 to 15).
  * The delta value of the three channels composing the linear sensor.

- The ECS is ON when no touch is detected (all sensors are in the RELEASE state).
  The ECS is always present but its behavior can be modified using some parameters in
  the tsl_conf.h file.

- You can experiment the DTO by touching a sensor for few seconds. The RELEASE state
  is automatically entered and a re-calibration is performed after the timeout is reached.
  This timeout is programmable by the TSLPRM_DTO parameter in the tsl_conf.h file.

@par Project Directory contents

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

  - This example runs on STM32L073VZ devices.
    
  - This example has been tested with STM32L073Z-EVAL board. It can be
    easily tailored to any other devices that embed the TSC peripheral and to
    any other development board supporting touchsensing sensor.
    
  - Important information : 
    ----------------------
  - The Touch sensing slider is exclusive with LCD glass.
  - On the RevB board:
  - The solder-bridges SB6, SB8, SB11, SB17, SB24, SB15, SB7 and SB10 must be closed
  - The solder-bridges SB5, SB14, SB12, SB18, SB22, SB16, SB13 and SB9 must be opened 
  - please refer to MB1168 user manual for details.
     
@par How to use it ?

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example
 

 */
