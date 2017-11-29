/**
  ******************************************************************************
  * @file    stm32l0xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"
#include "stm32l0xx.h"
#include "stm32l0xx_it.h"

/* USER CODE BEGIN 0 */


#include "user.h"
#include "LowPowerManagement.h"
#include "SensorTemperature.h"
#include "adcManagement.h"



uint8_t channel = 0;

extern GPIO_InitTypeDef GPIO_InitStruct;

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern ADC_HandleTypeDef hadc;
extern LCD_HandleTypeDef hlcd;
extern RTC_HandleTypeDef hrtc;

/******************************************************************************/
/*            Cortex-M0+ Processor Interruption and Exception Handlers         */ 
/******************************************************************************/

/**
* @brief This function handles System tick timer.
*/
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32L0xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32l0xx.s).                    */
/******************************************************************************/

/**
* @brief This function handles RTC global interrupt through EXTI lines 17, 19 and 20 and LSE CSS interrupt through EXTI line 19.
*/
void RTC_IRQHandler(void)
{
  /* USER CODE BEGIN RTC_IRQn 0 */

  /* USER CODE END RTC_IRQn 0 */
  HAL_RTCEx_WakeUpTimerIRQHandler(&hrtc);
  /* USER CODE BEGIN RTC_IRQn 1 */

  /* USER CODE END RTC_IRQn 1 */
}

/**
* @brief This function handles ADC1, COMP1 and COMP2 interrupts (COMP interrupts through EXTI lines 21 and 22).
*/
void ADC1_COMP_IRQHandler(void)
{
  /* USER CODE BEGIN ADC1_COMP_IRQn 0 */

	if( __HAL_ADC_GET_FLAG(&hadc, ADC_FLAG_EOC) != RESET)
		{
			switch (channel)
			{
				case CH_BATT:
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8,GPIO_PIN_RESET);
					u16Battery		= HAL_ADC_GetValue(&hadc);
					conversion 		= BUSY;
					channel++;
				break;
				
				case CH_NTC2:
					u16Ntc2 			= HAL_ADC_GetValue(&hadc);
					conversion 		= BUSY;
					channel++;
				break;
				
				case CH_VREF:
					u16Vref				= HAL_ADC_GetValue(&hadc);
					channel++;
				break;
				
				case PAUSE:
				/* Do nothing */
				break;
				
				default:
				break;		
			}
		}
		
	if( __HAL_ADC_GET_FLAG(&hadc, ADC_FLAG_EOS) != RESET)
		{
			__HAL_ADC_CLEAR_FLAG(&hadc, ADC_FLAG_EOS);
			conversion 		= READY;
			channel 			= CH_BATT;
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8,GPIO_PIN_SET);
/*			
			__HAL_ADC_CLEAR_FLAG(&hadc, ADC_FLAG_OVR);
			__HAL_ADC_CLEAR_FLAG(&hadc, ADC_FLAG_EOSMP);
			ADC1->ISR |= ADC_FLAG_EOS;  //Clear the pending bit
*/
		}			
	
  /* USER CODE END ADC1_COMP_IRQn 0 */
  HAL_ADC_IRQHandler(&hadc);
  /* USER CODE BEGIN ADC1_COMP_IRQn 1 */
		

		
	
		
  /* USER CODE END ADC1_COMP_IRQn 1 */
}

/**
* @brief This function handles LCD global interrupt.
*/
void LCD_IRQHandler(void)
{
  /* USER CODE BEGIN LCD_IRQn 0 */
	__HAL_LCD_CLEAR_FLAG(&hlcd, LCD_FLAG_SOF);
	__HAL_LCD_CLEAR_FLAG(&hlcd, LCD_FLAG_UDD);	
  /* USER CODE END LCD_IRQn 0 */
  /* USER CODE BEGIN LCD_IRQn 1 */

  /* USER CODE END LCD_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
