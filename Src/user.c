/*
  ******************************************************************************
  * File Name          : user.c
  * Date               : 28/12/2014 12:41:29
  * Description        : 
  *                      
  ******************************************************************************
*/

/*
INTERNAL SENSOR TEMPERATURE (ADC_IN18):

T[°C] = [(130°C - 30°C)/(TS_CAL2 TS_CAL1)]*(TS_DATA - TS_CAL1) 
Where:
• TS_CAL1 calibration @130°C
• TS_CAL2 calibration @30°C
• TS_DATA value ADC

TS_CAL is stored in:
	ts_cal1 = *((uint16_t*)0x1FF8007A);
	ts_cal2 = *((uint16_t*)0x1FF8007E);
	
INTERNAL REFERENCE VOLTAGE (ADC_IN17):
VDDA = 3.3V x VREFINT_CAL / VREFINT_DATA
Where:
• VREFINT_CAL is the VREFINT calibration value
• VREFINT_DATA is the actual VREFINT output value converted by ADC	

VREFINT_CAL is stored in:
 vrefint_cal = *((uint16_t*)0x1FF80078);

For applications where VDDA value is not known, you must use the internal voltage
reference and VDDA can be replaced by the expression provided in the section Calculating
the actual VDDA voltage using the internal reference voltage, resulting in the following
formula:
VCHANNELx = (3.3 V × VREFINT_CAL × ADC_DATAx) / (VREFINT_DATA × FULL_SCALE)


VLCD VOLTAGE MONITORING (ADC_IN16):
The converted digital value is a quarter of the VLCD voltage. To
prevent any unwanted consumption on the battery, it is recommended to enable the bridge
divider only when needed, that is to perform ADC conversions.

*/

#include "user.h"
#include "adcManagement.h"

void InitVariable(void)
{
	conversion = BUSY;
}

//void Error_Handler(void)
//{
//	HAL_NVIC_SystemReset();
//}






//__INLINE void Configure_DBG(void)
//{
//  /* Enable the peripheral clock of DBG register */
//  RCC->APB2ENR |= RCC_APB2ENR_DBGMCUEN;
//  
//  DBGMCU->CR |= DBGMCU_CR_DBG_STOP; /* To be able to debug in stop mode */
//  SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk; /* To enter deep sleep when __WFI() */
//  PWR->CR &=~ PWR_CR_PDDS; /* Select STOP mode */
//}
/**
  * @}
  */

/**
  * @}
  */

/****END OF FILE****/
