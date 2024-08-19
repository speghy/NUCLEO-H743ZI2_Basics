/*
 * board.h
 *
 *  Created on: Jul 30, 2024
 *      Author: Voronin
 */

#ifndef INC_BOARD_H_
#define INC_BOARD_H_
#include "main.h"
#include "stm32h7xx_hal.h"
#define BUFFER		__attribute__ ((section(".buffers")))
#define RAM_D1		__attribute__ ((section(".ram_d1")))
#define FW_VERSION			"0.1"
#define BOARD_NAME			"DUMMY"
#define MONITOR_CHANNELS	0
#define MONITOR_BUFFER_SIZE	0
#define UART_RX_BUF_SIZE	256
#define UART_TX_BUF_SIZE	256
extern UART_HandleTypeDef huart3;
#endif /* INC_BOARD_H_ */
