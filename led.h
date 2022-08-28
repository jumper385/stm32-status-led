/*
 * led.h
 *
 *  Created on: 24 Aug. 2022
 *      Author: henry
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "stm32f1xx_hal.h"

typedef struct{
	GPIO_TypeDef *red_port;
	GPIO_TypeDef *green_port;
	GPIO_TypeDef *blue_port;

	uint32_t red_pin;
	uint32_t green_pin;
	uint32_t blue_pin;

	uint8_t ledSeq[3];
}LED;

void LED_Init(LED *dev, GPIO_TypeDef * red_port, GPIO_TypeDef * green_port, GPIO_TypeDef *blue_port, uint32_t red_pin, uint32_t green_pin, uint32_t blue_pin);
void LED_Out(LED *dev, int state);
void LED_Blink(LED *dev, int _state);

#endif /* INC_LED_H_ */
