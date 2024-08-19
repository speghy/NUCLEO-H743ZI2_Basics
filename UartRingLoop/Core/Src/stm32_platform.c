/*
 * stm32_platform.c
 *
 *  Created on: 26 дек. 2022 г.
 *      Author: Rudenko
 */

#include "board.h"

#ifdef HAL_MODULE_ENABLED
#include "stm32_defs.h"

uint32_t GetMsTick()
{
    return HAL_GetTick();
}


HAL_StatusTypeDef TIMER_Base_Start_IT(TIMER_Handle_t* TIMx)
{
	return HAL_TIM_Base_Start_IT(TIMx);
}

void GPIO_Pin_Write(GPIO_TypeDef* port, uint16_t pin, GPIO_PinState value)
{
	HAL_GPIO_WritePin(port, pin, value);
}

GPIO_PinState GPIO_Pin_Read(GPIO_TypeDef* port, uint16_t pin)
{
	return HAL_GPIO_ReadPin(port, pin);
}

#endif
