/**
  ******************************************************************************
  * File Name          : user.h
  * Date               : 28/12/2014 12:41:29
  * Description        : This file provides code for the configuration
  *                      of the ADC instances.
  ******************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LcdManagement_H
#define __LcdManagement_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"
	 	 
void lcd_print(int16_t temperature);	
unsigned int IntToBCD(unsigned int inValue);

#ifdef __cplusplus
}
#endif
#endif /*__ LcdManagement_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
