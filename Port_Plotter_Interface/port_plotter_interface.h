/*
 * uart_port_plotter_interface.h
 *
 *  Created on: 13 июл. 2023 г.
 *      Author: Морской шакал
 */

#ifndef INC_UART_PORT_PLOTTER_INTERFACE_H_
#define INC_UART_PORT_PLOTTER_INTERFACE_H_

#include "stm32f1xx_hal.h"

#include <stdint.h>

#define USB_ENABLE 1

typedef enum
{
#ifdef HAL_UART_MODULE_ENABLED
	#if USB_ENABLE
		UART_CHANNEL,
		USB_CHANNEL
	#else
		UART_CHANNEL
	#endif
#else
	#ifdef HAL_UART_MODULE_ENABLED
		UART_CHANNEL
	#endif
	#if USB_ENABLE
		USB_CHANNEL
	#endif
#endif
} Channel;

typedef struct
{
#ifdef HAL_UART_MODULE_ENABLED
	UART_HandleTypeDef* huart;
#endif
	uint8_t values_number;
	uint8_t* tx_buffer;
	Channel plotter_channel;
} Port_plotter;

Port_plotter initPortPlotter(uint8_t values_number, Channel plotter_channel, ...);
void sendMessageForPlotter(Port_plotter* plotter, ...);

#endif /* INC_UART_PORT_PLOTTER_INTERFACE_H_ */
