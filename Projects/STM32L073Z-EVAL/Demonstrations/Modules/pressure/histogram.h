/**
  ******************************************************************************
  * @file    histogram.h
  * @author  MCD Application Team   
  * @brief   System information functions
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

/** @devgroup HISTOGRAM_DISPLAY
  * @{
  */

#define SIZE_OF_LINE 320

#define CURVE_RANGE  160


typedef struct
{
/*-- Public interface --*/
  /* Display window */
  uint32_t x0;    /* Top left corner */
  uint32_t y0;    /* Top left corner */
  uint32_t xSize; /* window width */
  uint32_t ySize; /* window height */

  /* Description */
  char * xDescr;
  char * yDescr;
  char * title;
  
  /* Histogram array, size and maximum value
     The values can be directly changed by the user at anytime*/
  uint32_t * array;
  uint32_t width;
  uint32_t maxValue;    /* If zero, the Y scaling is calculated to otpimize the display.
                           If not zero this value is used to calculate the Y scaling */

  uint32_t curve_Range;   /* Y range for the curve display */
                        /* The first display point is automatically centered */
                             
                             
/*-- Private context --*/    
  uint32_t graph_x0;    /* Graph Top left corner */
  uint32_t graph_y0;    /* Graph Top left corner */
  uint32_t graph_xSize; /* Graph width */
  uint32_t graph_ySize; /* Graph height */

  uint8_t  curve_tab[SIZE_OF_LINE]; /* Save curvez point to use the cleaning, 
                             use bigger value for larger screen */
  uint8_t  curve_tab2[SIZE_OF_LINE]; /* Save curvez point to use the cleaning, 
                             use bigger value for larger screen */
  uint32_t curve_index; 
  uint32_t curve_FirstPointValue; 
  uint32_t curve_FirstPointValue2; 
  
} HistogramDisplay_Typedef;


/* typedef -----------------------------------------------------------*/

typedef enum {
  HISTO_OK, 
  HISTO_FAIL,
  HISTO_BAD_PARAM,
} HISTO_RETURN;

/* macros ------------------------------------------------------------*/
/* variables ---------------------------------------------------------*/
/* function prototypes -----------------------------------------------*/

HISTO_RETURN HistogramInit(HistogramDisplay_Typedef * pHisto);

HISTO_RETURN HistogramClearData(HistogramDisplay_Typedef * pHisto);
HISTO_RETURN HistogramDisplayData(HistogramDisplay_Typedef * pHisto,  uint32_t color);

HISTO_RETURN HistogramUpdateTitle(HistogramDisplay_Typedef * pHisto);
HISTO_RETURN HistogramUpdateXDescr(HistogramDisplay_Typedef * pHisto);
HISTO_RETURN HistogramUpdateYDescr(HistogramDisplay_Typedef * pHisto);

HISTO_RETURN CurveAddPoint(HistogramDisplay_Typedef * pHisto, uint32_t value, uint32_t value2);
HISTO_RETURN CurveClear(HistogramDisplay_Typedef * pHisto);
HISTO_RETURN CurveZoomIn(HistogramDisplay_Typedef * pHisto);
HISTO_RETURN CurveZoomOut(HistogramDisplay_Typedef * pHisto);
/**
  * @}
  */
