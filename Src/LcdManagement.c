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

#include "LcdManagement.h"
#include "user.h"

extern LCD_HandleTypeDef hlcd;

uint16_t temp1, temp2, temp3, print; 

uint8_t oldLCDvalue;

uint16_t lcd_table1[] = 
	{
		/*unita*/
		0x7E60,	// -9
		0x1E00,	// -8
		0x7660,	// -7
		0x7640,	// -6
		0x6E00,	// -5
		0x5E40,	// -4
		0x5A60,	// -3
		0x0E00,	// -2
		0x3E60,	// -1		
		0x3C60, //	0
		0x0C00,	//	1
		0x5860,	//	2
		0x5C40,	//	3
		0x6C00,	//	4
		0x7440,	//	5
		0x7460,	//	6
		0x1C00,	//	7
		0x7C60,	//	8
		0x7C40	//	9
	};
	
uint16_t lcd_table2[] = 
	{
		/*decine*/
		0x819C, //0
		0x8010,	//1
		0x828C,	//2
		0x8298,	//3
		0x8310,	//4
		0x0398,	//5
		0x039C,	//6
		0x8090,	//7
		0x839C,	//8
		0x8398	//9
	};

	
void lcd_print(int16_t temperature)
{
/*
	Valore a 16 BIT = DIGIT2[Valore%10]+DIGIT1[Valore/10]+DIGIT0[(Valore/100)] SE VALORE < 100 
	altrimenti devi fare attenzione all'operazione VALORE/10 che se maggiore di 10 deve ritornare 0
	*/
	
/* Range 10°C to 99°C */
	if ((temperature >= 10)&&(temperature < 100)) 
	{
		temp1 = temperature % 10;
		temp2 = temperature / 10;
		print = lcd_table1[temp1 + 9] + lcd_table2[temp2];
	}
/* Range 0°C to 9°C */
	else if ((temperature < 10)&&(temperature >= 0))
	{
		temp1 = temperature;
		print = lcd_table1[temp1 + 9];
	}
/* Range -9°C to -1°C */
	else if ((temperature > -10)&&(temperature < 0))
	{
		temp1 = (uint16_t)((int16_t)(temperature - (temperature + temperature)));
		print = lcd_table1[9 - temp1];
	}	
/* Range 99°C to 199°C  */	
	else if ((temperature >= 100)&&(temperature < 200)) 
	{
		temp1 = temperature % 10;
		temp2 = temperature / 10;
		if (temp2 >= 10)
		{
			temp2  = temp2 % 10;
		}
		temp3 = temperature / 100;
		print = lcd_table1[temp1 + 9] + lcd_table2[temp2] + lcd_table2[temp3];
	}
/* Range < 9°C */	
	else if ((temperature >= 200)||(temperature <= -10))
	{
		print = lcd_table1[17] + lcd_table2[8];
	}
	if (HAL_LCD_Write(&hlcd, LCD_RAM_REGISTER0, oldLCDvalue, print) != HAL_OK) {Error_Handler();}		
	if (HAL_LCD_UpdateDisplayRequest(&hlcd) != HAL_OK) {Error_Handler();}		
//	oldLCDvalue = temperature;
}



unsigned int IntToBCD(unsigned int inValue) //conversion INT to BCD
{
	unsigned int temp,temp1,temp2,temp3;

	temp1 = (inValue/1000);	// 1
	temp = temp1<<4;	//0x0010
	temp2 = (inValue/100);	// 14
	temp = (temp+(temp2-(temp1*10)))<<4;// 0x0140
	temp3 = (inValue/10);	// 148
	temp = (temp+(temp3-(temp2*10)))<<4;// 0x1480
	temp = (temp+(inValue-(temp3*10)));// 0x1489

	//return ((inValue/10)<<4)+(inValue%10);	//valid only from 0 to 100.
	return temp;
}

/**
  * @}
  */

/**
  * @}
  */

/****END OF FILE****/
