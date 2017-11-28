/**
  ******************************************************************************
  * File Name          : SensorTemperature.h
  * Date               : 28/12/2014 12:41:29
  * Description        : This file provides code for the configuration
  *                      of the ADC instances.
  ******************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SensorTemperature_H
#define __SensorTemperature_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"
	 
/*
*	VISHAY 	NTCLE100E100E3473JB0 	B25/100  4113
*	EPCOS 	B57471V2103J62 				B25/100  3730
*/
 
//#define VISHAY_mC
//#define EPCOS_mC
	#define EPCOS_RES1C
	 
int16_t ReadTemperature(uint16_t adc_value);
uint16_t intTemperature(void);
	 
#ifdef __cplusplus
}
#endif
#endif /*__ SensorTemperature_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
