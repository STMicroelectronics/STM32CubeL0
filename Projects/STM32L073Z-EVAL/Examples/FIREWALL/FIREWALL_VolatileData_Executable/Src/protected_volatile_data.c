/**
  ******************************************************************************
  * @file    FIREWALL/FIREWALL_VolatileData_Executable/Src/protected_volatile_data.c
  * @author  MCD Application Team
  * @brief   Definition of array to be located in Firewall protected volatile data segment (in SRAM)
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
  */


/* Includes ------------------------------------------------------------------*/
#include "main.h"

#if defined(__ICCARM__)
#pragma section =".firewall_vdata"
#endif
/* Protected volatile data */

/* The Firewall protects the area from 0x20002100 to  0x20002FFF

  fw_init.VDataSegmentStartAddress    = 0x20002100;
  fw_init.VDataSegmentLength          = 0xF00;   

  The scatter file locates protected_volatile_array in a sub-region starting at 0x20002E00. 
    ...
    define symbol __ICFEDIT_protected_region_SRAM_b_start__    = 0x20002E00;
    define symbol __ICFEDIT_protected_region_SRAM_b_end__      = 0x20002FFF;
    ...
    define region protected_SRAM_b_region    = mem:[from __ICFEDIT_protected_region_SRAM_b_start__   to __ICFEDIT_protected_region_SRAM_b_end__];
    ...
    place in protected_SRAM_b_region   {readwrite section .firewall_vdata };
    ...
        
 */
#if defined(__ICCARM__)
#pragma default_variable_attributes = @ ".firewall_vdata"
#endif 
#if defined(__GNUC__)
uint32_t __attribute__((section(".vdata_protected_data")))  protected_volatile_array[N] = {50, 51, 52, 53, 54, 55, 56, 57, 58, 59};
#else
uint32_t protected_volatile_array[N] = {50, 51, 52, 53, 54, 55, 56, 57, 58, 59};
#endif 


/* Stop placing data in section protected_SRAM_b_region */
#if defined(__ICCARM__)
#pragma default_variable_attributes =
#endif 
