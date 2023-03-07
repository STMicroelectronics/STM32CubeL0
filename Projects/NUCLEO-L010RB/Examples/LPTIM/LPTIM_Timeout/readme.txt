/**
  @page LPTIM_Timeout LPTIM Timeout example with LSE clock source

  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    LPTIM/LPTIM_Timeout/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the LPTIM Timeout example.
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

How to implement, through the HAL LPTIM API, a timeout with the LPTIMER peripheral, to wake up
the system from a low-power mode.


The main() function configures the LPTIMER and goes in STOP mode.
In order to start the timer a first trigger is needed on (PC.3)(LPTIM_ETR).
Any successive trigger event on (PC.3) will reset the counter and the timer
will restart. The timeout value corresponds to the compare value (32768).
If after the first trigger no other trigger occurs within the expected time frame,
the MCU is woken-up by the compare match event and LED2 toggles.

In this example the LPTIM is clocked by the LSI

  Timeout = (Compare + 1) / LPTIM_Clock
          = (32767 + 1) / LSI_Clock_Frequency

Once the system is woken up it remains in run mode. The led keeps toggling each time the timer expires.

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents

  - LPTIM/LPTIM_Timeout/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - LPTIM/LPTIM_Timeout/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - LPTIM/LPTIM_Timeout/Inc/main.h                  Header for main.c module
  - LPTIM/LPTIM_Timeout/Src/stm32l0xx_it.c          Interrupt handlers
  - LPTIM/LPTIM_Timeout/Src/main.c                  Main program
  - LPTIM/LPTIM_Timeout/Src/stm32l0xx_hal_msp.c     HAL MSP module
  - LPTIM/LPTIM_Timeout/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L010xB devices.

  - This example has been tested with STMicroelectronics STM32L010RB-Nucleo
    board and can be easily tailored to any other supported device
    and development board.

  - Connect an external trigger (ETR) to PC.3(pin 37 in CN7 connector ).
    LSI clock is around 37 KHz (please refer to Reference Manual)
    LPTIM time-out period is equal to 32768 / 37000 = 0.886 ms (1.13 Hz)

    So, for an LSI clock equal to 37 KHz,
    - If the trigger is higher than 1.13 Hz, the counter is regularly reset, the system stays in STOP mode.
    - If the trigger is lower than 1.13 Hz, the counter expires and the system is woken up.

@par How to use it ?

In order to make the program work, you must do the following :
 - Open your preferred tool chain
 - Rebuild all files and load your image into target memory
 - Run the example


 */
