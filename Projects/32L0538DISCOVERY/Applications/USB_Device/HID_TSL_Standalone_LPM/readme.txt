/**
  @page HID_Standalone_LPM USB Device Humain Interface (HID) example

  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    USB_Device/HID_TSL_Standalone_LPM/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the USB HID LPM example.
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

Use of the USB device application based on the Human Interface (HID) with 
Link Power Management Protocol (LPM).

This example is part of the USB Device Library package using STM32Cube firmware.

STM32L053xx USB FS USB device supports the Link Power Management Protocol (LPM-L1) and complies with the USB 2.0
LPM-L1 ECN. The hpcd.Init.lpm_enable in the usbd_conf.c should be set to 1 to enable the support for LPM-L1
protocol in the USB stack.

LPM-L1 allows a USB host to configure the USB device into inactive state much faster than the normal 
USB suspend mode (L2).
It also provides much faster wake-up times in the order of micro-seconds compared to the generic resume 
by host or upstream resume by device.

When LPM packet is received from Host, STM32 USB will Acknowledge the LPM packet
and it will enter in L1 suspend mode. During USB L1 suspend mode ,system will be
in STOP low power mode.

On Host L1 resume, STM32 will wakeup from STOP and USB resumes operations.

You can test L1 suspend/resume, by running the USBCV3.0 chapter9 for USB2.0 devices 
and select (in debug mode) test "TD9.21: LPM L1 Suspend Resume Test".
Please note that for running USBCV3.0, you'll need a PC with a USB3.0 (xHCI)
host controller (please refer to USBCV3.0 documentation for more informations).

You can find in folder \Projects\USBCV3.0 , the full USBCV3.0 chapter9
test report.

At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick. The user is 
provided with the SystemClock_Config()function to configure the system clock (SYSCLK).
In this application the system clock is set to 16 MHz from the HSI (HSI48 is used as USB clock source)

The 48 MHz clock for the USB id derived from the RC48 Clock (HSI48): The HSI48 clock is generated 
from an internal 48 MHz RC oscillator, coupled with the clock recovery system (CRS). 
The CRS allows automatic trimming of the internal HSI48, synchronized with USB SOF signal at 1KHz rate, 
to guarantee its optimal accuracy over the whole device operational range.    

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on the the SysTick ISR. Thus if HAL_Delay() is called from a peripheral ISR process, the SysTick interrupt 
      must have higher priority (numerically lower) than the peripheral interrupt, Otherwise the caller ISR process 
      will be blocked. To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function or statically
      define it in the HAL configuration file through the "TICK_INT_PRIORITY" define.

@note The application needs to ensure that the SysTick time base is set to 1 millisecond
      to have correct HAL configuration.

@note To reduce the example footprint, the toolchain dynamic allocation is replaced by a static allocation
      by returning the address of a pre-defined static buffer with the HID class structure size.   

@note The built-in USB peripheral of the STM32L0 does not provide a specific interrupt for USB cable 
      plug/unplug detection. The correct way to detect the USB cable plug/unplug is to detect the 
      availability of the VBUS line using a normal GPIO pin (external interrupt line).

@par Directory contents

  - USB_Device/HID_TSL_Standalone_LPM/Src/main.c                  Main program
  - USB_Device/HID_TSL_Standalone_LPM/Src/system_stm32l0xx.c      STM32L0xx system clock configuration file
  - USB_Device/HID_TSL_Standalone_LPM/Src/stm32l0xx_hal_msp.c     HAL MSP module file
  - USB_Device/HID_TSL_Standalone_LPM/Src/tsl_user.c              Touchsensing channels/banks description file
  - USB_Device/HID_TSL_Standalone_LPM/Src/stm32l0xx_it.c          Interrupt handlers
  - USB_Device/HID_TSL_Standalone_LPM/Src/usbd_conf.c             General low level driver configuration
  - USB_Device/HID_TSL_Standalone_LPM/Src/usbd_desc.c             USB device HID descriptor
  - USB_Device/HID_TSL_Standalone_LPM/Inc/main.h                  Main program header file
  - USB_Device/HID_TSL_Standalone_LPM/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - USB_Device/HID_TSL_Standalone_LPM/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - USB_Device/HID_TSL_Standalone_LPM/Inc/usbd_conf.h             USB device driver Configuration file
  - USB_Device/HID_TSL_Standalone_LPM/Inc/usbd_desc.h             USB device MSC descriptor header file
  - USB_Device/HID_TSL_Standalone_LPM/Inc/tsl_conf.h              Touch Sensing configuration file
  - USB_Device/HID_TSL_Standalone_LPM/Inc/tsl_user.h              Header for tsl_user.c module


@par Hardware and Software environment

  - This example runs on  STM32L052xx, STM32L053xx STM32L062xx and 
    STM32L063xx device lines RevZ.

  - This example has been tested with STM32L0538-DISCO board. It can be
    easily tailored to any other devices that embed the TSC peripheral and to
    any other development board supporting touchsensing sensor.

  - STM32L053C8-Discovery Set-up
    - Connect the STM32L053C8-Discovery board to the PC through mini USB cable to the connector
      CN3: to use USB Full Speed (FS)
    - To remote wakeup (suspend stop mode) , user need to press the Key button

@par How to use it ?

To use this example, the following steps have to be followed:
 - Open project file.
 - Rebuild all the project and load the image into the target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
