/**
  ******************************************************************************
  * @file    Font8epd.c
  * @author  MCD Application Team
  * @brief   This file provides text Font8 for STM32L0538-DISCO's EPD driver. 
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
#include "fontsepd.h"

/** @addtogroup BSP
  * @{
  */

/** @addtogroup STM32L0538_DISCOVERY
  * @{
  */

/** @addtogroup FONTS
  * @brief      This file provides text Font8 for STM32L0538-Discovery's EPD driver.
  * @{
  */  

/** @defgroup FONTS_Private_Types
  * @{
  */ 
/**
  * @}
  */ 


/** @defgroup FONTS_Private_Defines
  * @{
  */
/**
  * @}
  */ 


/** @defgroup FONTS_Private_Macros
  * @{
  */
/**
  * @}
  */ 
  

/** @defgroup FONTS_Private_Variables
  * @{
  */
// 
//  Font data for Courier New 12pt (2bytes / 5 lines)
// 

const uint8_t Font8_Table[] = 
{
	// @0 ' ' (5 lines )
	0xff, 0xff, //      
	0xff, 0xff, //      
	0xff, 0xff, //      
	0xff, 0xff, //      
	0xff, 0xff, // 
                    //
                    //
                    //

	// @10 '!' (5 lines )
	0xff, 0xff, //   #    
	0xff, 0xff, //   #  
	0xf3, 0x00, //   # 
	0xff, 0xff, //   #        
	0xff, 0xff, //      
                    //   #
                    //
                    //

	// @20 '"' (5 lines )
	0xff, 0xff, //  ## 
	0xff, 0xf0, //  ##    
	0xff, 0xff, //       
	0xff, 0xf0, //       
	0xff, 0xff, //      
     

	// @30 '#' (5 lines)
	0xcc, 0xcf, //   # #
	0xf0, 0x03, //  # # 
	0xcc, 0xcc, // #####
	0xf0, 0x03, //  # # 
	0xfc, 0xcc, // #####
	            //  # # 
	            // # #  
	            //      

	// @40 '$' (5 lines)
	0xff, 0xff, //   #  
	0xf3, 0xcf, //   ## 
	0xc3, 0x00, //  ##  
	0xfc, 0x33, //   ## 
	0xff, 0xff, //    # 
	            //  ##  
	            //   #  
	            //      

	// @50 '%' (5 lines)
	0xff, 0xff, //   #  
	0xff, 0x3f, //   #  
	0xff, 0x30, //    ##
	0xf0, 0xcf, //  ##  
	0xff, 0xcf, //    # 
	            //    # 
	            //      
	            //      

	// @60 '&' (5 lines)
	0xff, 0xff, //      
	0xf0, 0x3f, //   ###
	0xf3, 0x03, //   #  
	0xf0, 0xf3, //  ##  
	0xf3, 0xf3, //  # # 
	            //  ####
	            //      
	            //      

	// @70 ''' (5 lines)
	0xff, 0xff, //   #  
	0xff, 0xff, //   #  
	0xff, 0xc0, //   #  
	0xff, 0xff, //      
	0xff, 0xff, //     
	            //      
	            //      
	            //      

	// @80 '(' (5 lines)
	0xff, 0xff, //    # 
	0xff, 0xff, //   #  
	0xf0, 0x03, //   #  
	0xcf, 0xfc, //   #  
	0xff, 0xff, //   #  
	            //   #  
                    //    # 
                    //      

	// @90 ')' (5 lines)
	0xff, 0xff, //  #   
	0xcf, 0xfc, //   #  
	0xf0, 0x03, //   #  
	0xff, 0xff, //   #  
	0xff, 0xff, //   #  
	            //   #  
                    //  #   
                    //      

	// @100 '*' (5 lines)
	0xff, 0xff, //   #  
	0xff, 0x33, //  ### 
	0xff, 0xc0, //   #  
	0xff, 0x33, //  # # 
	0xff, 0xff, //      
                    //      
                    //      
                    //      

	// @110 '+' (5 lines)
	0xff, 0x3f, //      
	0xff, 0x3f, //   #  
	0xf0, 0x03, //   #  
	0xff, 0x3f, // #####
	0xff, 0x3f, //   #  
	            //   #  
                    //      
                    //      

	// @120 ',' (5 lines )
	0xff, 0xff, //     
	0xff, 0xff, //      
	0xc3, 0xff, //      
	0xfc, 0xff, //      
	0xff, 0xff, //    # 
	            //   #  
	            //   #  
                    //      

	// @130 '-' (5 lines )
	0xff, 0xff, //      
	0xff, 0x3f, //      
	0xff, 0x3f, //      
	0xff, 0x3f, //  ### 
	0xff, 0xff, //      
	            //      
	            //      
	            //      

	// @140 '.' (5 lines)
	0xff, 0xff, //      
	0xff, 0xff, //      
	0xf3, 0xff, //     
	0xff, 0xff, //      
	0xff, 0xff, //      
	            //   #  
	            //      
                    //      

	// @150 '/' (5 lines)
	0xcf, 0xff, //    # 
	0xf0, 0xff, //   #  
	0xff, 0x03, //   #  
	0xff, 0xfc, //   #  
	0xff, 0xff, //  #   
	            //  #   
	            // #    
	            //      

	// @160 '0' (5 lines)
	0xff, 0xff, //   #  
	0xfc, 0x03, //  # # 
	0xf3, 0xfc, //  # # 
	0xfc, 0x03, //  # # 
	0xff, 0xff, //  # # 
	            //   #  
	            //      
                    //      

	// @170 '1' (5 lines)
	0xf3, 0xff, //  ##  
	0xf3, 0xfc, //   #  
	0xf0, 0x00, //   #  
	0xf3, 0xff, //   #  
	0xf3, 0xff, //   #  
                    // #####
	            //      
                    //      

	// @180 '2' (5 lines)
	0xff, 0xff, //   #  
	0xf0, 0xf3, //  # # 
	0xf3, 0x3C, //    #  
	0xf3, 0xC3, //   #  
	0xff, 0xff, //  #   
	            //  ### 
	            //      
                    //      

	// @190 '3' (5 lines)
	0xff, 0xff, //   #  
	0xf3, 0xf3, //  # # 
	0xf3, 0x3c, //    # 
	0xfc, 0xc3, //   #  
	0xff, 0xff, //    # 
	            //  ##  
                    //      
	            //      

	// @200 '4' (5 lines)
	0xff, 0xff, //    # 
	0xff, 0x0f, //   ## 
	0xf3, 0x33, //  # # 
	0xf0, 0x00, //  ####
	0xf3, 0x3f, //    # 
	            //   ###
	            //      
	            //      

	// @210 '5' (5 lines)
	0xff, 0xff, //  ### 
	0xfc, 0xc0, //  #   
	0xf3, 0xcc, //  ##  
	0xfc, 0x3c, //    # 
	0xff, 0xff, //  # # 
	            //   #  
	            //      
	            //      

	// @220 '6' (5 lines)
	0xff, 0xff, //   ## 
	0xfc, 0x03, //  #   
	0xf3, 0xcc, //  ##  
	0xfc, 0x3c, //  # # 
	0xff, 0xff, //  # # 
	            //  ##  
	            //      
	            //      

	// @230 '7' (5 lines )
	0xff, 0xff, //  ### 
	0xff, 0xf0, //  # # 
	0xf0, 0x3c, //    # 
	0xff, 0xc0, //   #  
	0xff, 0xff, //   #  
                    //   #  
                    //      
	            //      

	// @240 '8' (5 lines )
	0xff, 0xff, //   #  
	0xfc, 0x33, //  # # 
	0xf3, 0xcc, //   #  
	0xfc, 0x33, //  # # 
	0xff, 0xff, //  # # 
	            //   #  
	            //      
	            //      

	// @250 '9' (5 lines)
	0xff, 0xff, //   ## 
	0xf3, 0xc3, //  # # 
	0xf3, 0x3c, //  # # 
	0xfc, 0x03, //   ## 
	0xff, 0xff, //    # 
	            //  ##  
                    //      
	            //      

	// @260 ':' (5 lines)
	0xff, 0xff, //      
	0xff, 0xff, //      
	0xf3, 0xcf, //   #  
	0xff, 0xff, //      
	0xff, 0xff, //      
	            //   #  
	            //      
	            //      

	// @270 ';' (5 lines)
	0xff, 0xff, //      
	0xff, 0xff, //      
	0xf3, 0xff, //    # 
	0xfc, 0xcf, //      
	0xff, 0xff, //    # 
                    //   #  
	            //      
	            //      

	// @280 '<' (5 lines)
	0xff, 0x3f, //      
	0xff, 0x3f, //    # 
	0xfc, 0xcf, //   #  
	0xf3, 0xf3, // ##   
	0xff, 0xff, //   #  
	            //    # 
	            //      
	            //      

	// @290 '=' (5 lines)
	0xff, 0xff, //      
	0xff, 0x33, //  ### 
	0xff, 0x33, //      
	0xff, 0x33, //  ### 
	0xff, 0xff, //      
	            //      
	            //      
	            //      

	// @300 '>' (5 lines)
	0xff, 0xff, //      
	0xf3, 0xf3, //  #   
	0xfc, 0xcf, //   #  
	0xff, 0x3f, //    ##
	0xff, 0x3f, //   #  
	            //  #   
	            //      
	            //      

	// @310 '?' (5 lines)
	0xff, 0xff, //   #  
	0xff, 0xf3, //  # # 
	0xf3, 0x3c, //    # 
	0xff, 0xc3, //   #  
	0xff, 0xff, //      
	            //   #  
	            //      
	            //      

	// @320 '@' (5 lines)
	0xff, 0xff, //   ## 
	0xf0, 0x03, //  #  #
	0xcf, 0xfc, //  #  #
	0xcf, 0x3c, //  # ##
	0xcc, 0x03, //  #  #
                    //  #   
	            //   ###
	            //      

	// @330 'A' (5 lines)
	0xf0, 0xff, //  ##  
	0xf3, 0x0c, //   #  
	0xff, 0x30, //  # # 
	0xf3, 0x0f, //  ### 
	0xf0, 0xff, // #   #
	            // ## ##
                    //      
	            //      

	// @340 'B' (5 lines)
	0xf3, 0xfc, // #### 
	0xf0, 0x00, //  #  #
	0xf3, 0xcc, //  ### 
	0xf3, 0xcc, //  #  #
	0xfc, 0x33, //  #  #
	            // #### 
	            //      
	            //      

	// @350 'C' (5 lines)
	0xff, 0xff, //  ### 
	0xfc, 0x00, //  # # 
	0xf3, 0xfc, //  #   
	0xf3, 0xf0, //  #   
	0xff, 0xff, //  #   
	            //   ## 
                    //      
	            //      

	// @360 'D' (5 lines)
	0xf3, 0xfc, // #### 
	0xf0, 0x00, //  #  #
	0xf3, 0xfc, //  #  #
	0xf3, 0xfc, //  #  #
	0xfc, 0x03, //  #  #
	            // #### 
	            //      
	            //      

	// @370 'E' (5 lines)
	0xf3, 0xfc, // #####
	0xf0, 0x00, //  #  #
	0xf3, 0xcc, //  ##  
	0xf3, 0xfc, //  #   
	0xf0, 0xf0, //  #  #
                    // #####
                    //      
                    //      

	// @380 'F' (5 lines)
	0xf3, 0xfc, // #####
	0xf0, 0x00, //  #  #
	0xf3, 0xcc, //  ##  
	0xff, 0xfc, //  #   
	0xff, 0xf0, //  #   
                    // ###  
                    //      
                    //      

	// @390 'G' (5 lines)
	0xff, 0xff, //  ### 
	0xfc, 0x03, //  #   
	0xf3, 0xfc, //  #   
	0xf0, 0x3c, //  # ##
	0xff, 0x3f, //  # # 
                    //   ## 
                    //      
                    //      

	// @400 'H' (5 lines)
	0xf3, 0xfc, // ### #
	0xf0, 0x00, //  #  #
	0xf3, 0xcc, //  ####
	0xff, 0xcf, //  #  #
	0xf0, 0x00, //  #  #
	            // ### #
	            //      
	            //      

	// @410 'I' (5 lines)
	0xff, 0xff, //  ### 
	0xf3, 0xfc, //   #  
	0xf0, 0x00, //   #  
	0xf3, 0xfc, //   #  
	0xff, 0xff, //   #  
	            //  ### 
	            //      
                    //      

	// @420 'J' (5 lines)
	0xff, 0xff, //   ###
	0xfc, 0x3f, //    # 
	0xf3, 0xfc, //    # 
	0xfc, 0x00, //  # # 
	0xff, 0xfc, //  # # 
	            //   #  
	            //      
                    //      

	// @430 'K' (5 lines)
	0xf3, 0xfc, // ## ##
	0xf0, 0x00, //  # # 
	0xff, 0x0f, //  ##  
	0xf0, 0x30, //  ### 
	0xf3, 0xfc, //  # # 
	            // ## ##
	            //      
	            //      

	// @440 'L' (5 lines)
	0xf3, 0xfc, // ###  
	0xf0, 0x00, //  #   
	0xf3, 0xfc, //  #   
	0xf3, 0xff, //  #   
	0xf0, 0xff, //  #  #
	            // #####
	            //      
	            //      

	// @450 'M' (5 lines)
	0xf0, 0x00, // ## ##
	0xf3, 0xc0, // ## ##
	0xff, 0x3f, // ## ##
	0xf3, 0xc0, // # # #
	0xf0, 0x00, // #   #
	            // ## ##
                    //      
	            //      

	// @460 'N' (5 lines )
	0xf3, 0xfc, // ## ##
	0xf0, 0x00, //  ## #
	0xf3, 0xc3, //  ## #
	0xfc, 0x3c, //  # ##
	0xf0, 0x00, //  # ##
	            // ### #
	            //      
	            //      

	// @470 'O' (5 lines)
	0xff, 0xff, //   ## 
	0xfc, 0x03, //  #  #
	0xf3, 0xfc, //  #  #
	0xf3, 0xfc, //  #  #
	0xfc, 0x03, //  #  #
	            //   ## 
	            //      
	            //      

	// @480 'P' (5 lines)
	0xf3, 0xfc, // #### 
	0xf0, 0x00, //  #  #
	0xf3, 0x3c, //  #  #
	0xff, 0x3c, //  ### 
	0xff, 0xc3, //  #   
	            // ###  
	            //      
	            //      

	// @490 'Q' (5 lines)
	0xff, 0xff, //   ## 
	0xfc, 0x03, //  #  #
	0xf3, 0xfc, //  #  #
	0xf0, 0xfc, //  #  #
	0xf0, 0x00, //  #  #
	            //   ## 
	            //    ##
                    //      

	// @500 'R' (5 lines )
	0xf3, 0xfc, // #### 
	0xf0, 0x00, //  #  #
	0xf3, 0x3c, //  #  #
	0xff, 0x3c, //  ### 
	0xf0, 0xc3, //  #  #
	            // ### #
	            //      
	            //      

	// @510 'S' (5 lines)
	0xff, 0xff, //  ### 
	0xf3, 0xf0, //  # #
	0xf3, 0xcc, //   #  
	0xf0, 0x30, //    # 
	0xff, 0xff, //    # 
	            //  ### 
	            //      
	            //      

	// @520 'T' (5 lines)
	0xff, 0xf0, // #####
	0xf3, 0xfc, // # # #
	0xf0, 0x00, //   #  
	0xf3, 0xfc, //   #  
	0xff, 0xf0, //   #  
	            //  ### 
	            //      
	            //      

	// @530 'U' (5 lines)
	0xff, 0xfc, // ## ##
	0xfc, 0x00, //  #  #
	0xf3, 0xff, //  #  #
	0xf3, 0xfc, //  #  #
	0xfc, 0x00, //  #  #
	            //   ## 
                    //      
                    //      

	// @540 'V' (5 lines)
	0xff, 0xf0, // ## ##
	0xfc, 0x0c, // #   #
	0xf3, 0xff, //  #  #
	0xf0, 0x3c, //  # # 
	0xff, 0xc0, //  # # 
	            //   ## 
                    //      
	            //      

	// @550 'W' (5 lines)
	0xfc, 0x00, // ## ##
	0xf3, 0xfc, // #   #
	0xfc, 0x0f, // # # #
	0xf3, 0xfc, // # # #
	0xfc, 0x00, // # # #
	            //  # # 
	            //      
	            //      

	// @560 'X' (5 lines)
	0xf3, 0xfc, // ## ##
	0xf0, 0xf0, //  # # 
	0xff, 0x0f, //   #  
	0xf0, 0xf0, //   #  
	0xf3, 0xfc, //  # # 
	            // ## ##
	            //      
	            //      

	// @570 'Y' (5 lines)
	0xff, 0xf0, // ## ##
	0xf3, 0xcc, // #   #
	0xf0, 0x3f, //  # # 
	0xf3, 0xcc, //   #  
	0xff, 0xf0, //   #  
                    //  ### 
	            //      
	            //      

	// @580 'Z' (5 lines)
	0xff, 0xff, //  ####  
	0xf0, 0xf0, //  #  #
	0xf3, 0x3c, //    # 
	0xf3, 0xcc, //   #  
	0xf0, 0xf0, //  #  #
                    //  ####
                    //      
                    //      

	// @590 '[' (5 lines)
	0xff, 0xff, //   ## 
	0xff, 0xff, //   #  
	0xc0, 0x00, //   #  
	0xcf, 0xfc, //   #  
        0xff, 0xff, //   #  
	            //   #  
                    //   ## 
	            //      

	// @600 '\' (5 lines)
	0xff, 0xfc, // #    
	0xff, 0xc3, //  #   
	0xf0, 0x3f, //  #   
	0xcf, 0xff, //   #  
	0xff, 0xff, //   #  
	            //   #  
	            //    # 
	            //      

	// @610 ']' (5 lines)
	0xff, 0xff, //  ##  
	0xcf, 0xfc, //   #  
	0xc0, 0x00, //   #  
	0xff, 0xff, //   #  
	0xff, 0xff, //   #  
                    //   #  
	            //  ##  
	            //      

	// @620 '^' (5 lines)
	0xff, 0xff, //   #  
	0xff, 0xcf, //   #  
	0xff, 0xf0, //  # # 
	0xff, 0xcf, //      
	0xff, 0xff, //      
                    //      
                    //      
	            //      

	// @630 '_' (5 lines)
	0x3f, 0xff, //      
	0x3f, 0xff, //      
	0x3f, 0xff, //      
	0x3f, 0xff, //      
	0xff, 0xff, //      
                    //      
	            //      
	            // #####

	// @640 '`' (5 lines)
	0xff, 0xff, //   #  
	0xff, 0xff, //    # 
	0xff, 0xfc, //      
	0xff, 0xf3, //      
	0xff, 0xff, //      
	            //      
	            //      
	            //      

	// @650 'a' (5 lines)
	0xff, 0xff, //      
	0xf0, 0xff, //      
	0xf0, 0xcf, //   ## 
	0xf0, 0x0f, //    # 
	0xf3, 0xff, //  ### 
	            //  ####
	            //      
	            //      

	// @660 'b' (5 lines)
	0xf3, 0xfc, // ##   
	0xf0, 0x00, //  #   
	0xf3, 0xcf, //  ### 
	0xf3, 0xcf, //  #  #
	0xfc, 0x3f, //  #  #
	            // #### 
	            //      
	            //      

	// @670 'c' (5 lines)
	0xff, 0xff, //      
	0xf0, 0x0f, //      
	0xf3, 0xcf, //  ### 
	0xf3, 0xcf, //  #   
	0xff, 0xff, //  #   
	            //  ### 
	            //      
	            //      

	// @680 'd' (5 lines)
	0xff, 0xff, //    ##
	0xfc, 0x3f, //     #
	0xf3, 0xcf, //   ###
	0xf3, 0xcc, //  #  #
	0xf0, 0x00, //  #  #
	            //   ###
	            //      
	            //      

	// @690 'e' (5 lines)
	0xff, 0xff, //      
	0xfc, 0x0f, //      
	0xf3, 0x0f, //  ### 
	0xf3, 0x0f, //  ### 
	0xff, 0xff, //  #   
	            //   ## 
	            //      
	            //      

	// @700 'f' (5 lines)
	0xff, 0xff, //    # 
	0xf3, 0xcf, //   #  
	0xf0, 0x03, //  ### 
	0xf3, 0xcc, //   #  
	0xff, 0xff, //   #  
	            //  ### 
	            //      
	            //      

	// @710 'g' (5 lines)
	0xff, 0xff, //      
	0xfc, 0x3f, //      
	0x33, 0xcf, //   ###
	0x33, 0xcf, //  #  #
	0xc0, 0x0f, //  #  #
	            //   ###
	            //     #
	            //   ## 

	// @720 'h' (5 lines)
	0xf3, 0xfc, // ##   
	0xf0, 0x00, //  #   
	0xf3, 0xcf, //  ### 
	0xff, 0xcf, //  #  #
	0xf0, 0x3f, //  #  #
	            // ### #
	            //      
	            //      

	// @730 'i' (5 lines)
	0xff, 0xff, //   #  
	0xf3, 0xcf, //      
	0xf0, 0x0c, //  ##  
	0xf3, 0xff, //   #  
	0xff, 0xff, //   #  
                    //  ### 
	            //      
	            //      

	// @740 'j' (5 lines)
	0xff, 0xff, //   #  
	0x3f, 0xcf, //      
	0x3f, 0xcc, //  ### 
	0x00, 0x0f, //    # 
	0xff, 0xff, //    # 
	            //    # 
	            //    # 
	            //  ### 

	// @750 'k' (5 lines)
	0xf3, 0xfc, // ##   
	0xf0, 0x00, //  #   
	0xff, 0x3f, //  # ##
	0xf0, 0x0f, //  ### 
	0xf3, 0xcf, //  # # 
                    // ## ##
	            //      
	            //      

	// @760 'l' (5 lines)
	0xff, 0xff, //  ##  
	0xf3, 0xfc, //   #  
	0xf0, 0x00, //   #  
	0xf3, 0xff, //   #  
	0xff, 0xff, //   #  
	            //  ### 
                    //      
	            //      

	// @770 'm' (5 lines)
	0xf0, 0x0f, //      
	0xff, 0xcf, //      
	0xf0, 0x3f, // ## # 
	0xff, 0xcf, // # # #
	0xf0, 0x3f, // # # #
	            // # # #
	            //      
	            //      

	// @780 'n' (5 lines)
	0xf3, 0xcf, //      
	0xf0, 0x0f, //      
	0xff, 0xcf, // #### 
	0xff, 0xcf, //  #  #
	0xf0, 0x3f, //  #  #
	            // ##  #
	            //      
	            //      

	// @790 'o' (5 lines)
	0xff, 0xff, //      
	0xfc, 0x3f, //      
	0xf3, 0xcf, //   ## 
	0xf3, 0xcf, //  #  #
	0xfc, 0x3f, //  #  #
	            //   ## 
	            //      
	            //      

	// @800 'p' (5 lines)
	0x3f, 0xcf, //      
	0x00, 0x0f, //      
	0x33, 0xcf, // #### 
	0xf3, 0xcf, //  #  #
	0xfc, 0x3f, //  #  #
	            //  ### 
	            //  #   
	            // ###  

	// @810 'q' (5 lines)
	0xff, 0xff, //      
	0xfc, 0x3f, //      
	0xf3, 0xcf, //   ###
	0x33, 0x3f, //  #  #
	0x00, 0x0f, //  #  #
	            //   ###
	            //     #
	            //    ##

	// @820 'r' (5 lines)
	0xff, 0xff, //      
	0xf3, 0xcf, //      
	0xf0, 0x0f, //  ####
	0xf3, 0xcf, //   #  
	0xff, 0xcf, //   #  
	            //  ### 
	            //      
                    //      

	// @830 's' (5 lines)
	0xff, 0xff, //      
	0xf3, 0xff, //      
	0xf3, 0x0f, //   ## 
	0xfc, 0xcf, //   #  
	0xff, 0xff, //    # 
                    //  ##  
	            //      
                    //      

	// @840 't' (5 lines)
	0xff, 0xcf, //      
	0xfc, 0x03, //  #   
	0xf3, 0xcf, // #### 
	0xf3, 0xcf, //  #   
	0xfc, 0xff, //  #  #
                    //   ## 
                    //      
                    //      

	// @850 'u' (5 lines)
	0xff, 0xcf, //      
	0xfc, 0x0f, //      
	0xf3, 0xff, // ## ##
	0xf3, 0xcf, //  #  #
	0xf0, 0x0f, //  #  #
	            //   ###
	            //      
	            //      

	// @860 'v' (5 lines)
	0xff, 0xcf, //      
	0xff, 0x0f, //      
	0xf0, 0xff, // ##  #
	0xf0, 0xff, //  #  #
	0xff, 0x0f, //   ## 
	            //   ## 
	            //      
	            //      

	// @870 'w' (5 lines)
	0xfc, 0x0f, //      
	0xf3, 0xcf, //      
	0xfc, 0x3f, // ## ##
	0xf3, 0xcf, // # # #
	0xfc, 0x0f, // # # #
	            //  # # 
	            //      
	            //      

	// @880 'x' (5 lines)
	0xff, 0xff, //      
	0xf3, 0xcf, //      
	0xfc, 0x3f, //  #  #
	0xfc, 0x3f, //   ## 
	0xf3, 0xcf, //   ## 
	            //  #  #
	            //      
	            //      

	// @890 'y' (5 lines)
	0xff, 0xcf, //      
	0x3c, 0x0f, //      
	0x03, 0xff, // ## ##
	0xfc, 0x0f, //  # # 
	0xff, 0xcf, //  # # 
	            //   #  
	            //   #  
	            //  ##  

	// @900 'z' (5 lines)
	0xff, 0xff, //      
	0xf3, 0xcf, //      
	0xf0, 0xcf, //  ####
	0xf3, 0x0f, //    # 
	0xf3, 0xcf, //   # 
	            //  ####
                    //      
	            //      

	// @910 '{' (5 lines)
	0xff, 0xff, //    # 
	0xff, 0x3f, //   #  
	0xf0, 0x03, //   #  
	0xcf, 0xfc, //  ##  
	0xff, 0xff, //   #  
	            //   #  
                    //    # 
	            //      

	// @920 '|' (5 lines)
	0xff, 0xff, //   #  
	0xff, 0xff, //   #  
	0xc0, 0x00, //   #  
        0xff, 0xff, //   #  
	0xff, 0xff, //   #  
	            //   #  
	            //   #  
	            //      

	// @930'}' (5 lines)
	0xff, 0xff, //  #   
	0xcf, 0xfc, //   #  
	0xf0, 0x03, //   #  
	0xff, 0x3f, //   ## 
	0xff, 0xff, //   #  
	            //   #  
                    //  #   
                    //      

	// @940 '~' (5 lines)
	0xff, 0xff, //      
	0xfc, 0xff, //      
        0xff, 0x3f, //      
	0xfc, 0xff, //   # #
	0xff, 0x3f, //  # # 
	            //      
	            //      
	            //      
};

sFONT Font8 = {
  Font8_Table,
  5, /* Width */ //(5 lines)
  2, /* Height */  //(2 bytes/8pixels)
};

/**
  * @}
  */ 


/** @defgroup FONTS_Private_Function_Prototypes
  * @{
  */ 
/**
  * @}
  */ 


/** @defgroup FONTS_Private_Functions
  * @{
  */
    
/**
  * @}
  */
  
/**
  * @}
  */ 

/**
  * @}
  */

/**
  * @}
  */
