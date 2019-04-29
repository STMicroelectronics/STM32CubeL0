/**
  @page HID_Standalone_LPM USB Device Humain Interface (HID) example with LPM 
  
  @verbatim
  ******************************************************************************
  * @file    USB_Device/HID_Standalone_LPM/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the USB HID LPM example.
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

At the beginning of the main program the HAL_Init() function is called to reset all the peripherals,
initialize the Flash interface and the systick. The user is provided with the SystemClock_Config()
function to configure the system clock (SYSCLK) to run at 80 MHz. The Full Speed (FS) USB module uses
internally a 48-MHz clock which is coming from a specific output of two PLLs (PLL or PLL SAI) or from MSI

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.
      
For more details about the STM32Cube USB Device library, please refer to UM1734 
"STM32Cube USB Device library".
      
@par Directory contents

  - USB_Device/HID_Standalone_LPM/Src/main.c                  Main program
  - USB_Device/HID_Standalone_LPM/Src/system_stm32l0xx.c      STM32L0xx system clock configuration file
  - USB_Device/HID_Standalone_LPM/Src/stm32l0xx_it.c          Interrupt handlers
  - USB_Device/HID_Standalone_LPM/Src/usbd_conf.c             General low level driver configuration
  - USB_Device/HID_Standalone_LPM/Src/usbd_desc.c             USB device HID descriptor
  - USB_Device/HID_Standalone_LPM/Inc/main.h                  Main program header file
  - USB_Device/HID_Standalone_LPM/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - USB_Device/HID_Standalone_LPM/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - USB_Device/HID_Standalone_LPM/Inc/usbd_conf.h             USB device driver Configuration file
  - USB_Device/HID_Standalone_LPM/Inc/usbd_desc.h             USB device MSC descriptor header file  

	
@par Hardware and Software environment

  - This example runs on STM32L053xx devices.
  - This demo has been tested with STM32L053R8-Nucleo RevC board and can be
    easily tailored to any other supported device and development board.

  - Since there is no USB 2.0 Full speed connector (Type B) on the nucleo board, user has to make 
    his own USB shield daughter board with the a USB connector and plug it on top of the  CN13 
    connectors of the STM32L053R8-Nucleo. The USB connector has to be connected to the USB device associated GPIOs
    as follows:
    - DP (D+ of the USB connector) <======> PA12 (Nucleo board)
    - DM (D- of the USB connector) <======> PA11 (Nucleo board)
    To improve EMC performance (noise immunity and signal integrity), it is recommended to connect a 100nF
	ceramic capacitor to the USB VDD pin.
      
@par How to use it ?

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example
 
 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
  