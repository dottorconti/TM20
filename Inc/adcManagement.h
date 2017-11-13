/**
  ******************************************************************************
  * File Name          : adcManagement.h
  * Date               : 28/12/2014 12:41:29
  * Description        : This file provides code for the configuration
  *                      of the ADC instances.
  ******************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __adcManagement_H
#define __adcManagement_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"

	 
#define CH_BATT 0	 
#define CH_NTC2 1
#define CH_VREF 2	
#define PAUSE		3
#define BOOST_VOLTAGE 3.F	 
	 
	 
uint16_t ReadVref(uint16_t Vreference);
uint16_t ReadVoltage(uint16_t Vbatt);
	 


extern 	uint16_t 	vRefInt_cal; 
	 
/*	Real Value		*/
extern 	uint16_t 	vRef;
extern 	int16_t 	i16Celsius;
extern	uint16_t 	VoltageValue;

/*	Digital Value	*/
extern uint16_t 	u16Battery;
extern uint16_t 	u16Ntc2;
extern uint16_t 	u16Vref;

typedef enum enum_conversion_status
{
	BUSY		= 0x00,
	READY 	= 0x01,
	WAIT		= 0x02,
	ERR			= 0x05
}conversion_enum;

extern conversion_enum conversion;

#ifdef __cplusplus
}
#endif
#endif /*__ adcManagement_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
