/**
  @page HID_Standalone_BCD USB Device Humain Interface (HID) example

  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    USB_Device/HID_Standalone_BCD/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the USB HID BCD example.
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

Use of the USB device application (BCD feature) based on the Human Interface (HID).

The STM32L053xx device integrated battery charger detection circuitry supports USB-IF Battery
Charger Detection, BCD,(revision 1.2). The hpcd.Init.battery_charging_enable in the usbd_conf.c
should be set to 1 to enable the support for BCD.

This example is a part of the USB Device Library package using STM32Cube firmware.

his is a typical example on how to use the STM32L053xx USB FS Device peripheral where the STM32 MCU is
enumerated as a HID device using the native PC Host HID driver.

Battery charger detection will begin automatically when VBUS is detected. The STM32L053xx include the
capability to detect various USB battery chargers and can detect a range of USB battery chargers including a Standard Downstream
Port (SDP), a Charging Downstream Port (CDP), and a Dedicated Charging Port (DCP). For more information
on USB battery charger detection, please see the USB Battery Charging Specification, Revision 1.2 (Note 1).

In this example, we use STM32L0538-DISCO board LEDs to indicate the following connection status events:
-	LED3 for detection of Standard Downstream port (host port without charging capability)
-	LED4 for detection of a Charging Downstream port (host port with charging capability)
-	LED3 and LED4 for detection of Dedicated Charging port (Charger with  short circuit between D+ and D-)

If a DCP is connected (D+/D- are shorted or connected through 200 ohm resistor)
In CDP case we used a HP dock Station: charging port

At the beginning of the main program the HAL_Init() function is called to reset
all the peripherals, initialize the Flash interface and the systick. The user is
provided with the SystemClock_Config()function to configure the system clock (SYSCLK).
In this application the system clock is set to 16 MHz from the HSI (HSI48 is used as USB clock source)

The 48 MHz clock for the USB id derived from the RC48 Clock (HSI48): The HSI48 clock is generated
from an internal 48 MHz RC oscillator, coupled with the clock recovery system (CRS).
The CRS allows automatic trimming of the internal HSI48, synchronized with USB SOF signal at 1KHz rate,
to guarantee its optimal accuracy over the whole device operational range.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The application needs to ensure that the SysTick time base is set to 1 millisecond
      to have correct HAL configuration.

@note To reduce the example footprint, the toolchain dynamic allocation is replaced by a static allocation
      by returning the address of a pre-defined static buffer with the HID class structure size.

@note The built-in USB peripheral of the STM32L0 does not provide a specific interrupt for USB cable
      plug/unplug detection. The correct way to detect the USB cable plug/unplug is to detect the
      availability of the VBUS line using a normal GPIO pin (external interrupt line).

@par Directory contents

  - USB_Device/HID_Standalone_BCD/Src/main.c                  Main program
  - USB_Device/HID_Standalone_BCD/Src/system_stm32l0xx.c      STM32L0xx system clock configuration file
  - USB_Device/HID_Standalone_BCD/Src/stm32l0xx_hal_msp.c     HAL MSP module file
  - USB_Device/HID_Standalone_BCD/Src/tsl_user.c              Touchsensing channels/banks description file
  - USB_Device/HID_Standalone_BCD/Src/stm32l0xx_it.c          Interrupt handlers
  - USB_Device/HID_Standalone_BCD/Src/usbd_conf.c             General low level driver configuration
  - USB_Device/HID_Standalone_BCD/Src/usbd_desc.c             USB device HID descriptor
  - USB_Device/HID_Standalone_BCD/Inc/main.h                  Main program header file
  - USB_Device/HID_Standalone_BCD/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - USB_Device/HID_Standalone_BCD/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - USB_Device/HID_Standalone_BCD/Inc/usbd_conf.h             USB device driver Configuration file
  - USB_Device/HID_Standalone_BCD/Inc/usbd_desc.h             USB device MSC descriptor header file
  - USB_Device/HID_Standalone_BCD/Src/tsl_user.c              TSL user source file
  - USB_Device/HID_Standalone_BCD/Inc/tsl_conf.h              TSL configuration header file
  - USB_Device/HID_Standalone_BCD/Inc/tsl_user.h              TSL user header file


@par Hardware and Software environment

  - This example runs on  STM32L052xx, STM32L053xx STM32L062xx and
    STM32L063xx device lines RevZ.

  - This example has been tested with STM32L0538-DISCO board. It can be
    easily tailored to any other devices.

@par How to use it ?

To use this example, the following steps have to be followed:
 - Open project file.
 - Rebuild all the project and load the image into the target memory
 - Run the example

 @note USB cable should be connected before the beginning of program.


 */
