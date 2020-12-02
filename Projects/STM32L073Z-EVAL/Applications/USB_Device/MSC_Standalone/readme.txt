/**
  @page MSC_Standalone USB Device Mass Storage (MSC) example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    USB_Device/MSC_Standalone/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the USB Device MSC example.
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

Use of the USB device application based on the Mass Storage Class (MSC).

This example is a part of the USB Device Library package using STM32Cube firmware.

This is a typical example on how to use the STM32L0xx USB Device peripheral to communicate with a PC
Host using the Bulk Only Transfer (BOT) and Small Computer System Interface (SCSI) transparent commands,
while the microSD card is used as storage media. The STM32 MCU is enumerated as a MSC device using the
native PC Host MSC driver to which the STM32L073Z-EVAL board is connected.

Caution : In the current version of FW package, SD-HC format is not supported (please use a up to 2GB card) 

At the beginning of the main program the HAL_Init() function is called to reset all the peripherals,
initialize the Flash interface and the systick. The user is provided with the SystemClock_Config()
function to configure the system clock (SYSCLK).
In this application the system clock is set depending on the USB clock source 
  - 32 MHz from the PLL(HSE), when PLL is used as USB clock source
  - 16 MHz from the HSI, when HSI48 is used as USB clock source

The 48 MHz clock for the USB can be derived from one of the two following sources:
  – PLL clock(clocked by the HSE): If the USB uses the PLL as clock source, the PLL VCO clock must be programmed
    to output 96 MHz frequency (USBCLK = PLLVCO/2).
  – RC48 Clock (HSI48): The HSI48 clock is generated from an internal 48 MHz RC oscillator, coupled with
    the clock recovery system (CRS). 
    The CRS allows automatic trimming of the internal HSI48, synchronized with USB SOF signal at 1KHz rate, 
    to guarantee its optimal accuracy over the whole device operational range.    
User can select USB clock from HSI48 or PLL through macro defined in main.h
(USE_USB_CLKSOURCE_CRSHSI48 and USE_USB_CLKSOURCE_PLL).

When the application is started, the user has just to plug the USB cable into a PC host and the device
is automatically detected. A new removable drive appears in the system window and write/read/format
operations can be performed as with any other removable drive.

@note The application needs to ensure that the SysTick time base is set to 1 millisecond
      to have correct HAL configuration.

@note To reduce the example footprint, the toolchain dynamic allocation is replaced by a static allocation
      by returning the address of a pre-defined static buffer with the MSC class structure size.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The built-in USB peripheral of the STM32L0 does not provide a specific interrupt for USB cable 
      plug/unplug detection. The correct way to detect the USB cable plug/unplug is to detect the 
      availability of the VBUS line using a normal GPIO pin (external interrupt line).

@par Directory contents

  - USB_Device/MSC_Standalone/Src/main.c                  Main program
  - USB_Device/MSC_Standalone/Src/system_stm32l0xx.c      STM32L0xx system clock configuration file
  - USB_Device/MSC_Standalone/Src/stm32l0xx_it.c          Interrupt handlers
  - USB_Device/MSC_Standalone/Src/usbd_conf.c             General low level driver configuration
  - USB_Device/MSC_Standalone/Src/usbd_desc.c             USB device MSC descriptor
  - USB_Device/MSC_Standalone/Src/ubsd_storage.c          Media Interface Layer
  - USB_Device/MSC_Standalone/Inc/main.h                  Main program header file
  - USB_Device/MSC_Standalone/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - USB_Device/MSC_Standalone/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - USB_Device/MSC_Standalone/Inc/usbd_conf.h             USB device driver Configuration file
  - USB_Device/MSC_Standalone/Inc/usbd_desc.h             USB device MSC descriptor header file
  - USB_Device/MSC_Standalone/Inc/ubsd_storage.h          Media Interface Layer header file   

	
@par Hardware and Software environment

  - This example runs on STM32L073xx devices.

  - This example has been tested with a STM32L073Z-EVAL board and can be 
    easily tailored to any other supported device and development board.

  - STM32L073Z-EVAL Set-up
    - Insert a (up to 2GB) microSD card into the STM32L073Z-EVAL uSD slot (CN13)
    - Connect the STM32L073Z-EVAL board to the PC through 'USB Type micro A-Male
      to A-Male' cable to the connector CN9

@par How to use it ?

In order to make the program work, you must do the following:
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
