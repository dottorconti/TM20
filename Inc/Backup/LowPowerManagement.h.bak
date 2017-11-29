/**
  ******************************************************************************
  * File Name          : user.h
  * Date               : 28/12/2014 12:41:29
  * Description        : This file provides code for the configuration
  *                      of the ADC instances.
  ******************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LowPowerManagement_H
#define __LowPowerManagement_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"

//#define DEBUG 

/* Time in seconds */	 
#define DEBUG_TIME								5	 
#define STOP_TIME									30	 
#define LOW_BATTERY_STOP_TIME 		150
#define LOW_BATTERY 							600

void GPIO_LowPower_Init(void);
void GPIO_LowPower_DeInit(void);
void SystemClock_User_Config(void);
void Stop_Mode(void);	 
void LowBattery(void);

	 

	
#ifdef __cplusplus
}
#endif
#endif /*__LowPowerManagement_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
