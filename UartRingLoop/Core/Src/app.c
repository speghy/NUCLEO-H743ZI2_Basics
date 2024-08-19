/*
 * app.c
 *
 *  Created on: Aug 6, 2024
 *      Author: Voronin
 */

#include "app.h"
#define SIZE_BF 256
uint8_t BUFFER uart_rx_buf[UART_RX_BUF_SIZE];

uint16_t uart_available(void)
{
	return ((uint16_t)(UART_RX_BUF_SIZE + rx_buffer_head - rx_buffer_tail)) % UART_RX_BUF_SIZE;
}

uint8_t uart_read(void)
{
	if(rx_buffer_head == rx_buffer_tail)
	{
		return 0;
	}
	else
	{
		uint8_t c = uart_rx_buf[rx_buffer_tail];
		rx_buffer_tail = (uint16_t)(rx_buffer_tail + 1) % UART_RX_BUF_SIZE;
		return c;
	}
}

void uart_loop()
{
	 if(uart_available()) // есть ли что-то в приёмном буфере, тогда читаем
	          {
	                  char str[SIZE_BF] = {0,};
	                  uint8_t i = 0;

	                  while(uart_available())
	                  {
	                          str[i++] = uart_read(); // читаем байт

	                          if(i == SIZE_BF - 1)
	                          {
	                                  str[i] = '\0';
	                                  break;
	                          }

	                          //HAL_Delay(1);
	                  }

	                  str[i] = '\0';

	                  HAL_UART_Transmit(&huart3, (uint8_t*)str, strlen(str), 100); // отправляем обратно что получили
	          }
}
