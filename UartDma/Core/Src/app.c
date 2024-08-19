/*
 * app.c
 *
 *  Created on: Aug 6, 2024
 *      Author: Voronin
 */

#include "app.h"
#define SIZE_BF 256
uint8_t BUFFER uart_rx_buf[UART_RX_BUF_SIZE];
uint16_t write_index = 0;
uint16_t read_index = 0;
char str[UART_RX_BUF_SIZE + 8] = {0,};

uint16_t uart_available(void)
{
		uint16_t get_count = __HAL_DMA_GET_COUNTER(huart3.hdmarx);
		write_index = get_count * (0 - UART_RX_BUF_SIZE) / UART_RX_BUF_SIZE + UART_RX_BUF_SIZE;
		return write_index - read_index;
}

uint8_t uart_read(void)
{
		uint8_t res = uart_rx_buf[read_index];
		read_index++;

		if(read_index == UART_RX_BUF_SIZE)
		{
			read_index = 0;
			HAL_UART_Receive_DMA(&huart3, (uint8_t*)uart_rx_buf, UART_RX_BUF_SIZE);
		}

		return res;
}

void uart_loop()
{
	if(uart_available())
		{
			uint16_t i = 0;
			char buf[UART_RX_BUF_SIZE + 1] = {0,};

			while(uart_available())
			{
				buf[i++] = uart_read();
				if(i > UART_RX_BUF_SIZE - 1) break;
				HAL_Delay(1);
			}

			snprintf(str, UART_RX_BUF_SIZE + 8, "BUF: %s\n", buf);
			HAL_UART_Transmit(&huart3, (uint8_t*)str, strlen(str), 1000);
		}
}
