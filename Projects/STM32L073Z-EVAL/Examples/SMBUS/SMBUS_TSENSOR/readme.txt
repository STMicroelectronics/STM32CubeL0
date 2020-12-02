/**
  @page SMBUS_TSENSOR SMBUS Temperature Sensor example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    SMBUS/SMBUS_TSENSOR/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the SMBUS Temperature Sensor example.
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

SMBUS data buffer transmission/reception using an interrupt. The STM32 microcontroller
communicates with an SMBUS temperature sensor.

   __________________________________________________________________________                        
  |           ______________                        ______________           |
  |          | I2C1         |                      |   TSENSOR    |          |
  |          |              |                      |              |          |
  |          |      SCL(PB6)|______________________|CLOCK         |          |
  |          |              |                      |              |          |
  |          |              |                      |              |          |
  |          |              |                      |              |          |
  |          |      SDA(PB7)|______________________|DATA          |          |
  |          |              |                      |              |          |
  |          |SMB alert(PB5)|______________________|EVENT         |          |
  |          |______________|                      |______________|          |
  |      __                                                                  |
  |     |__|                                                                 |
  |     Wkup/Tamper push-button                                                                  |
  |                                                                          |
  |__________________________________________________________________________|
      STM32L073Z-EVAL

At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system
clock (SYSCLK) to run at 32 MHz.

The temperature sensor configuration is ensured by TSENSOR_Init() which verify that
temperature sensor is ready to communicate by calling TSENSOR_IsReady(), then
set the configuration using HAL_SMBUS_Master_Transmit_IT() and HAL_SMBUS_EnableAlert_IT()

The SMBUS peripheral configuration is ensured by the HAL_SMBUS_Init()
and HAL_SMBUS_IsDeviceReady() called respectively in TSENSOR_Init() function.
This later is calling the HAL_SMBUS_MspInit()function which core is implementing
the configuration of the needed SMBUS resources according to the used hardware (CLOCK, 
GPIO and NVIC). You may update this function to change SMBUS configuration.

The SMBUS/Temperature Sensor communication is then initiated.

Then at each loop in main program a read and a display on LCD of the current temperature
is done each second.
An specific warning message is display on LCD in case of an alert from temperature sensor
is detected.

This management is perform using the TSENSOR_ReadTemp()and TSENSOR_ReadStatus() functions 
allow respectively the read of the current temperature and get the temperature sensor status.

STM32L073Z-EVAL's Messages and LEDs can be used to monitor the temperature sensor status:
 - LED_RED is ON when there is an error during communication with the temperature sensor.
 - Please refer to http://www.st.com/web/en/resource/technical/document/datasheet/CD00153511.pdf
 Figure 5. OS output temperature response diagram.
 In case of the Temperature high or low limit exceeded, this blink warning message is display on the LCD
 until alert limit disappear :
                                       Temperature Limit
                                       has been exceeded

@note TSENSOR_SMBUS instance used and associated resources can be updated in "stm32l0xx_tsensor.c"
and "main.h" files depending hardware configuration used.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - SMBUS/SMBUS_TSENSOR/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - SMBUS/SMBUS_TSENSOR/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - SMBUS/SMBUS_TSENSOR/Inc/main.h                  Header for main.c module  
  - SMBUS/SMBUS_TSENSOR/Inc/stm32l0xx_tsensor.h     Temperature Sensor driver header file
  - SMBUS/SMBUS_TSENSOR/Src/stm32l0xx_it.c          Interrupt handlers
  - SMBUS/SMBUS_TSENSOR/Src/main.c                  Main program
  - SMBUS/SMBUS_TSENSOR/Src/system_stm32l0xx.c      STM32L0xx system source file
  - SMBUS/SMBUS_TSENSOR/Src/stm32l0xx_hal_msp.c     HAL MSP file    
  - SMBUS/SMBUS_TSENSOR/Src/stm32l0xx_tsensor.c     Temperature Sensor driver file

@par Hardware and Software environment

  - This example runs on STM32L073xx devices.
  - This example has been tested with STM32L073Z-EVAL board and can be
    easily tailored to any other supported device and development board.    
  - Requirements: the LCD glass(MB979) has to moved down in IO position on CN10 
    and CN14 connectors for correct application behaviour. 
    
@note Unplug board to perform complete reset of temperature sensor. 
    
@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
