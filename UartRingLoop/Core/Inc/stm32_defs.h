/*
 * stm32_defs.h
 *
 *  Created on: 26 дек. 2022 г.
 *      Author: Rudenko
 */

#ifndef TESTER_TOOLS_STM32_DEFS_H_
#define TESTER_TOOLS_STM32_DEFS_H_
#include "board.h"
#ifndef STM32H7xx_HAL_TIM_H
#include "stm32h7xx_hal_tim.h"
#endif
#ifdef HAL_MODULE_ENABLED

typedef TIM_HandleTypeDef	TIMER_Handle_t;

#endif

#endif /* TESTER_TOOLS_STM32_DEFS_H_ */
