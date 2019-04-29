/**
  @page DFU_Standalone USB Device Firmware Upgrade (DFU) example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    USB_Device/DFU_Standalone/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the USB DFU example.
  ******************************************************************************
  *
  * Copyright (c) 2016 STMicroelectronics International N.V. All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  @endverbatim

@par Application Description

Compliant implementation of the Device Firmware Upgrade (DFU) 
capability to program the embedded Flash memory through the USB peripheral.

This example uses the DFU capability to upgrade the Application area in the embedded 
flash memory of the STM32L0xx devices. The Internal flash memory is organized as follows:
 - DFU area located in [0x08000000 : USBD_DFU_APP_DEFAULT_ADD-1]: Only read access
 - Application area located in [USBD_DFU_APP_DEFAULT_ADD : Device's end address]: Read, Write, and Erase
   access.

In this application, two operating modes are available:
 1. DFU operating mode: 
    This mode is entered after a MCU reset using the two following methods:
     - The DFU mode is forced by the user by pressing the key button in the STM32L053R8-Nucleo Board .
     - No valid code found in the application area: a code is considered valid if the MSB of the initial
       Main Stack Pointer (MSP) value located in the first address of the application area is equal to 
       0x2000.
      
 2. Run-time application mode: 
    This is the normal run-time behavior. A binary file with basic example which toggles LED2 on the 
    STM32L053R8-Nucleo Board is provided in Binary directory.

At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick. The user is 
provided with the SystemClock_Config()function to configure the system clock (SYSCLK).
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


@note To reduce the example footprint, the toolchain dynamic allocation is replaced by a static allocation
      by returning the address of a pre-defined static buffer with the DFU class structure size.     

Basically, firmware are stored in Hex, S19 or Binary files, but these formats do not contain the 
necessary information to perform the upgrade operation, they contain only the actual data of the program
to be downloaded. While, the DFU operations require more information, like the product identifier, 
vendor identifier, Firmware version and the Alternate setting number (Target ID) of the target to be 
used, this information makes the upgrade targeted and more secure. To add this information, DFU file 
format is used. For more details refer to the "DfuSe File Format Specification" document (UM0391).

To generate a DFU image, download "DFUse Demonstration" tool and use DFU File Manager to convert a 
binary image into a DFU image. This tool is for download from www.st.com
To download a *.dfu image, use "DfuSe Demo" available within "DFUse Demonstration" install directory. 

Please refer to UM0412, DFuSe USB device firmware upgrade STMicroelectronics extension for more details
on the driver installation and PC host user interface.
    
It is possible to fine tune needed USB Device features by modifying defines values in USBD configuration
file “usbd_conf.h” available under the project includes directory, in a way to fit the application
requirements, such as “USBD_DFU_APP_DEFAULT_ADD, specifying the address from where user's application will be downloaded.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on the the SysTick ISR. Thus if HAL_Delay() is called from a peripheral ISR process, the SysTick interrupt 
      must have higher priority (numerically lower) than the peripheral interrupt, Otherwise the caller ISR process 
      will be blocked. To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function or statically
      define it in the HAL configuration file through the "TICK_INT_PRIORITY" define.
      
@note The application needs to ensure that the SysTick time base is set to 1 millisecond
      to have correct HAL configuration.

@note The built-in USB peripheral of the STM32L0 does not provide a specific interrupt for USB cable 
      plug/unplug detection. The correct way to detect the USB cable plug/unplug is to detect the 
      availability of the VBUS line using a normal GPIO pin (external interrupt line).

@par Directory contents 

  - USB_Device/DFU_Standalone/Src/main.c                  Main program
  - USB_Device/DFU_Standalone/Src/system_stm32l0xx.c      STM32L0xx system clock configuration file
  - USB_Device/DFU_Standalone/Src/stm32l0xx_it.c          Interrupt handlers
  - USB_Device/DFU_Standalone/Src/usbd_conf.c             General low level driver configuration
  - USB_Device/DFU_Standalone/Src/usbd_desc.c             USB device descriptor
  - USB_Device/DFU_Standalone/Src/usbd_dfu_flash.c        Internal flash memory management
  - USB_Device/DFU_Standalone/Inc/main.h                  Main program header file
  - USB_Device/DFU_Standalone/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - USB_Device/DFU_Standalone/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - USB_Device/DFU_Standalone/Inc/usbd_conf.h             USB device driver Configuration file
  - USB_Device/DFU_Standalone/Inc/usbd_desc.h             USB device descriptor header file
  - USB_Device/DFU_Standalone/Inc/usbd_dfu_flash.h        Internal flash memory management header file


@par Hardware and Software environment

  - This example runs on STM32L052xx, STM32L053xx STM32L062xx and 
    STM32L063xx device lines RevZ.

  - This example has been tested with STM32L053R8-Nucleo RevC board with a USB shield daughter
   board, and can be easily tailored to any other supported device and development board.

  - STM32L053R8-Nucleo RevC Set-up
      Since there is no USB 2.0 Full speed connector (Type B) on the nucleo board, user has to make 
      his own USB shield daughter board with the a USB connector and plug it on top of the  CN11 and CN12 
      connectors of the STM32L053R8-Nucleo. The USB connector has to be connected to the USB device associated GPIOs
      as follows:
       - DP (D+ of the USB connector) <======> PA12 (Nucleo board)
       - DM (D- of the USB connector) <======> PA11 (Nucleo board)

      To improve EMC performance (noise immunity and signal integrity), it is recommended to connect a 100nF
      ceramic capacitor to the USB VDD pin.


@par How to use it ?

In order to make the program work; you need first to install the "DfuSe Demonstrator" software 
and DFU driver:
 - Install the DFU driver available in "DfuSe Demonstrator" installation directory
 - For Windows 8.1 and later : Update STM32 DFU device driver manually from Windows Device Manager.
   The install of required device driver is available under:
   "Program Files\STMicroelectronics\Software\DfuSe v3.0.5\Bin\Driver\Win8.1" directory.

proceed as follows:
 - Open project file
 - Rebuild all the project and load the image into the target memory
 - Run the example 
 - Open "DfuSe Demo" and download the "STM32L0xx_Nucleo_SysTick_0x08007000.dfu" provided in the Binary
   directory.
 - To run the downloaded application, execute the command "leave the DFU mode" or Reset the 
   board. 

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
