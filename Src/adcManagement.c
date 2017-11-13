/*
  ******************************************************************************
  * File Name          : adcManagement.c
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

#include "adcManagement.h"

/*	Real Value		*/
uint16_t vRef;
uint16_t 	VoltageValue;
int16_t		i16Celsius;

/*	Digital Value	*/
uint16_t 	vRefInt_cal;
uint16_t u16Battery;
uint16_t u16Ntc2;
uint16_t u16Vref;

uint16_t ReadVoltage(uint16_t Vbatt)
{
	return (uint16_t)(((float)(Vbatt * vRef)/4096)/**2*/);
}

uint16_t ReadVref(uint16_t Vreference)
{
	vRefInt_cal = *((uint16_t*)0x1FF80078);
	return (uint16_t)(float)(((BOOST_VOLTAGE * vRefInt_cal)/(Vreference))*1000);
}

/**
  * @}
  */

/**
  * @}
  */

/****END OF FILE****/
