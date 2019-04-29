/**
  ******************************************************************************
  * @file    stm32l073z_eval_idd.c
  * @author  MCD Application Team
  * @brief   This file includes the Idd measurement driver for
  *          STM32L073Z-Eval board.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright(c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm32l073z_eval_idd.h"
#include "stm32l073z_eval_io.h"

/** @addtogroup BSP
  * @{
  */

/** @addtogroup STM32L073Z_EVAL
  * @{
  */
  
/** @defgroup STM32L073Z_EVAL_BOARD_IDD STM32L073Z_EVAL_BOARD Idd
  * @brief This file includes the Idd driver for STM32L32L073Z_EVAL board.
  *        It allows user to measure MCU Idd current on board, especially in 
  *        different low power modes.
  * @{
  */ 

/** @defgroup STM32L073Z_EVAL_BOARD_IDD_Private_Defines IDD Private Defines
  * @{
  */
  
/**
  * @}
  */


/** @defgroup STM32L073Z_EVAL_BOARD_IDD_Private_Variables IDD Private Variables
  * @{
  */ 
static IDD_DrvTypeDef *IddDrv = NULL;

/**
  @verbatim
  @endverbatim
*/


/**
  * @}
  */

/** @defgroup STM32L073Z_EVAL_BOARD_IDD_Private_Functions IDD Private Functions
  * @{
  */

/**
  * @}
  */ 

/** @defgroup STM32L073Z_EVAL_BOARD_IDD_Exported_Functions IDD Exported Functions
  * @{
  */ 

/**
  * @brief  Configures IDD measurement component.
  * @param  None
  * @retval IDD_OK if no problem during initialization
  */
uint8_t BSP_IDD_Init(void)
{
  IDD_ConfigTypeDef iddconfig = {0};
  uint8_t mfxstm32l152_id = 0;
  uint8_t ret = 0;

  /* Read ID and verify if the MFX is ready */
  mfxstm32l152_id = mfxstm32l152_idd_drv.ReadID(IDD_I2C_ADDRESS);
  
  if((mfxstm32l152_id == MFXSTM32L152_ID_1) || (mfxstm32l152_id == MFXSTM32L152_ID_2))
  {
    
    /* Initialize the TS driver structure */
    IddDrv = &mfxstm32l152_idd_drv;
    
    /* Initialize the Idd driver */
    if(IddDrv->Init != NULL)
    {
      IddDrv->Init(IDD_I2C_ADDRESS);
    }

    /* Configure Idd component with default values */
    iddconfig.AmpliGain = EVAL_IDD_AMPLI_GAIN;
    iddconfig.VddMin = EVAL_IDD_VDD_MIN;
    iddconfig.Shunt0Value = EVAL_IDD_SHUNT0_VALUE;
    iddconfig.Shunt1Value = EVAL_IDD_SHUNT1_VALUE;
    iddconfig.Shunt2Value = EVAL_IDD_SHUNT2_VALUE;
    iddconfig.Shunt3Value = EVAL_IDD_SHUNT3_VALUE;
    iddconfig.Shunt4Value = EVAL_IDD_SHUNT4_VALUE;
    iddconfig.Shunt0StabDelay = EVAL_IDD_SHUNT0_STABDELAY;
    iddconfig.Shunt1StabDelay = EVAL_IDD_SHUNT1_STABDELAY;
    iddconfig.Shunt2StabDelay = EVAL_IDD_SHUNT2_STABDELAY;
    iddconfig.Shunt3StabDelay = EVAL_IDD_SHUNT3_STABDELAY;
    iddconfig.Shunt4StabDelay = EVAL_IDD_SHUNT4_STABDELAY;
    iddconfig.ShuntNbOnBoard = MFXSTM32L152_IDD_SHUNT_NB_5;
    iddconfig.ShuntNbUsed = MFXSTM32L152_IDD_SHUNT_NB_5;
    iddconfig.VrefMeasurement = MFXSTM32L152_IDD_VREF_AUTO_MEASUREMENT_ENABLE;
    iddconfig.Calibration = MFXSTM32L152_IDD_AUTO_CALIBRATION_ENABLE;
    iddconfig.PreDelayUnit = MFXSTM32L152_IDD_PREDELAY_20_MS;
    iddconfig.PreDelayValue = 0x7F;
    iddconfig.MeasureNb = 100;
    iddconfig.DeltaDelayUnit= MFXSTM32L152_IDD_DELTADELAY_0_5_MS;
    iddconfig.DeltaDelayValue = 10;

    BSP_IDD_Config(iddconfig);

    ret = IDD_OK;
  }
  else
  {
    ret = IDD_ERROR;
  }
 
  return ret;
}

/**
  * @brief  Reset Idd measurement component.
  * @retval None
  */
void BSP_IDD_Reset(void)
{
    uint8_t mfxstm32l152_id = 0;

    /* Read ID and verify if the MFX is ready */
    mfxstm32l152_id = mfxstm32l152_idd_drv.ReadID(IDD_I2C_ADDRESS);

    if((mfxstm32l152_id == MFXSTM32L152_ID_1) || (mfxstm32l152_id == MFXSTM32L152_ID_2))
    {
        /* Initialize the TS driver structure */
        IddDrv = &mfxstm32l152_idd_drv;
        if(IddDrv->Reset != NULL)
        {
            IddDrv->Reset(IDD_I2C_ADDRESS);
        }
    }
}

/**
  * @brief  Turn Idd measurement component in low power (standby/sleep) mode
  * @retval None
  */
void BSP_IDD_LowPower(void)
{
  if(IddDrv->LowPower != NULL)
  {
   IddDrv->LowPower(IDD_I2C_ADDRESS);
  }
}

/**
  * @brief  Start Measurement campaign 
  * @param  None
  * @retval None
  */
void BSP_IDD_StartMeasure(void)
{
  if(IddDrv->Start != NULL)
  {
    IddDrv->Start(IDD_I2C_ADDRESS);
  }
}

/**
  * @brief  Configure Idd component
  * @param  IddConfig: structure of idd parameters
  * @retval None
  */
void BSP_IDD_Config(IDD_ConfigTypeDef IddConfig)
{  
  if(IddDrv->Config != NULL)
  {
    IddDrv->Config(IDD_I2C_ADDRESS, IddConfig);
  }
}

/**
  * @brief  Get Idd current value.
  * @param  IddValue: Pointer on u32 to store Idd. Value unit is 10 nA.
  * @retval None
  */
void BSP_IDD_GetValue(uint32_t *IddValue)
{
  if(IddDrv->GetValue != NULL)
  {
    IddDrv->GetValue(IDD_I2C_ADDRESS, IddValue);
  }
}

/**
  * @brief  Enable Idd interrupt that warn end of measurement
  * @param  None
  * @retval None
  */
void BSP_IDD_EnableIT(void)
{
  if(IddDrv->EnableIT != NULL)
  {
    IddDrv->EnableIT(IDD_I2C_ADDRESS);
  }
}

/**
  * @brief  Clear Idd interrupt that warn end of measurement
  * @param  None
  * @retval None
  */
void BSP_IDD_ClearIT(void)
{
  if(IddDrv->ClearIT != NULL)
  {
   IddDrv->ClearIT(IDD_I2C_ADDRESS);
  }
}

/**
  * @brief  Get Idd interrupt status
  * @param  Return 
  * @retval None
  */
uint8_t BSP_IDD_GetITStatus(void)
{
  if(IddDrv->GetITStatus != NULL)
  {
    return (IddDrv->GetITStatus(IDD_I2C_ADDRESS));
  }
  else
  {
    return IDD_ERROR;
  }
}

/**
  * @brief  Disable Idd interrupt that warn end of measurement
  * @param  None
  * @retval None
  */
void BSP_IDD_DisableIT(void)
{
  if(IddDrv->DisableIT != NULL)
  {
    IddDrv->DisableIT(IDD_I2C_ADDRESS);
  }
}

/**
  * @brief  Get Error Code .
  * @param  None.
  * @retval Error code or error
  */
uint8_t BSP_IDD_ErrorGetCode(void)
{

  if(IddDrv->ErrorGetSrc != NULL)
  {
    if((IddDrv->ErrorGetSrc(IDD_I2C_ADDRESS) & MFXSTM32L152_IDD_ERROR_SRC) != RESET)
    {
      if(IddDrv->ErrorGetCode != NULL)
      {
       return IddDrv->ErrorGetCode(IDD_I2C_ADDRESS);
      }
      else
      {
        return IDD_ERROR;
      }
    }
    else
    {
      return IDD_ERROR;
    }
  }
  else
  {
    return IDD_ERROR;
  }

}


/**
  * @brief  Enable error interrupt that warn end of measurement
  * @param  None
  * @retval None
  */
void BSP_IDD_ErrorEnableIT(void)
{
  if(IddDrv->ErrorEnableIT != NULL)
  {
    IddDrv->ErrorEnableIT(IDD_I2C_ADDRESS);
  }
}

/**
  * @brief  Clear Error interrupt that warn end of measurement
  * @param  None
  * @retval None
  */
void BSP_IDD_ErrorClearIT(void)
{
  if(IddDrv->ErrorClearIT != NULL)
  {
    IddDrv->ErrorClearIT(IDD_I2C_ADDRESS);
  }
}

/**
  * @brief  Get Error interrupt status
  * @param  Return 
  * @retval None
  */
uint8_t BSP_IDD_ErrorGetITStatus(void)
{
  if(IddDrv->ErrorGetITStatus != NULL)
  {
    return (IddDrv->ErrorGetITStatus(IDD_I2C_ADDRESS));
  }
  else
  {
    return 0;
  }
}

/**
  * @brief  Disable Error interrupt 
  * @param  None
  * @retval None
  */
void BSP_IDD_ErrorDisableIT(void)
{
  if(IddDrv->ErrorDisableIT != NULL)
  {
    IddDrv->ErrorDisableIT(IDD_I2C_ADDRESS);
  }
}

/**
  * @brief  Wakes up Idd measurement component.
  * @retval None
  */
void BSP_IDD_WakeUp(void)
{
  /* Set Wakeup pin to high to wakeup Idd measurement compont form standby mode */
  HAL_GPIO_WritePin(IDD_WAKEUP_GPIO_PORT, IDD_WAKEUP_PIN, GPIO_PIN_SET);

  /* Wait */
  HAL_Delay(1);

  /* Set gpio pin basck to low */
  HAL_GPIO_WritePin(IDD_WAKEUP_GPIO_PORT, IDD_WAKEUP_PIN, GPIO_PIN_RESET);
}


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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

