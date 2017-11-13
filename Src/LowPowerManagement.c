/*
  ******************************************************************************
  * File Name          : LowPowerManagement.c
  * Date               : 28/12/2014 12:41:29
  * Description        : 
  *                      
  ******************************************************************************
*/

#include "user.h"
#include "gpio.h"
#include "adc.h"
#include "dma.h"
#include "LowPowerManagement.h"

extern ADC_HandleTypeDef hadc;
extern DMA_HandleTypeDef hdma_adc;
extern UART_HandleTypeDef huart1;
extern RTC_HandleTypeDef hrtc;
extern LCD_HandleTypeDef hlcd;

void Stop_Mode(void)
{
//	__HAL_UART_CLEAR_IT(&huart1, UART_CLEAR_WUF);
//	__HAL_UART_ENABLE_IT(&huart1, UART_IT_WUF);
	__HAL_ADC_DISABLE(&hadc);

//	HAL_PWREx_EnableUltraLowPower();
	HAL_SuspendTick();
	GPIO_LowPower_Init();
	__HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
	__HAL_RTC_WAKEUPTIMER_CLEAR_FLAG(&hrtc, RTC_FLAG_WUTF);
  __HAL_RTC_EXTI_CLEAR_FLAG(RTC_EXTI_LINE_WAKEUPTIMER_EVENT);
	HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
//	HAL_PWREx_DisableUltraLowPower();
	SystemClock_User_Config();
	HAL_ResumeTick();
	GPIO_LowPower_DeInit();

	__HAL_ADC_ENABLE(&hadc);
}

void LowBattery(void)
{
	__HAL_LCD_BLINK_CONFIG(&hlcd, LCD_BLINKMODE_ALLSEG_ALLCOM, LCD_BLINKFREQUENCY_DIV1024);
	HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, LOW_BATTERY_STOP_TIME, RTC_WAKEUPCLOCK_CK_SPRE_16BITS);
}

void SystemClock_User_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;

  __PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV8;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0);

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1|RCC_PERIPHCLK_RTC;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit);

  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);

}
/**
  * @}
  */

/**
  * @}
  */

/****END OF FILE****/
