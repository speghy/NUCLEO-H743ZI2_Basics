/*
 * app.h
 *
 *  Created on: Aug 6, 2024
 *      Author: Voronin
 */

#ifndef INC_APP_H_
#define INC_APP_H_
#include "board.h"
#include "ring_buf.h"

extern uint8_t BUFFER uart_rx_buf[UART_RX_BUF_SIZE];
extern uint8_t BUFFER uart_tx_buf[UART_TX_BUF_SIZE];
extern volatile uint16_t rx_buffer_head;
extern volatile uint16_t rx_buffer_tail;
extern uint16_t uart_available(void);
extern void uart_loop();
#endif /* INC_APP_H_ */
