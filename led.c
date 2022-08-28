/*
 * ld.h
 *
 *  Created on: 24 Aug. 2022
 *      Author: henry
 */

#include "led.h"

void LED_Init(LED *dev, GPIO_TypeDef * r_port, GPIO_TypeDef * g_port, GPIO_TypeDef *b_port, uint32_t r_pin, uint32_t g_pin, uint32_t b_pin){
	dev->red_port = r_port;
	dev->green_port = g_port;
	dev->blue_port = b_port;

	dev->red_pin = r_pin;
	dev->green_pin = g_pin;
	dev->blue_pin = b_pin;
}

void set_state(LED *dev, int _state){
	switch(_state){
		case 0: // ERROR LED
			dev->ledSeq[0] = 0;
			dev->ledSeq[1] = 1;
			dev->ledSeq[2] = 1;
			break;
		case 1: // NOMINAL STATE
			dev->ledSeq[0] = 1;
			dev->ledSeq[1] = 0;
			dev->ledSeq[2] = 1;
			break;
		case 2: // WAITING STATE
			dev->ledSeq[0] = 1;
			dev->ledSeq[1] = 1;
			dev->ledSeq[2] = 0;
			break;
		case 3: // CAN ACTIVATED
			dev->ledSeq[0] = 1;
			dev->ledSeq[1] = 0;
			dev->ledSeq[2] = 0;
			break;
		default:
			dev->ledSeq[0] = 1;
			dev->ledSeq[1] = 1;
			dev->ledSeq[2] = 1;
			break;
	}
}

void LED_Out(LED *dev, int _state) {

	set_state(dev, _state);

	HAL_GPIO_WritePin(dev->red_port, dev->red_pin, dev->ledSeq[0]);
	HAL_GPIO_WritePin(dev->green_port, dev->green_pin, dev->ledSeq[1]);
	HAL_GPIO_WritePin(dev->blue_port, dev->blue_pin, dev->ledSeq[2]);
}

void LED_Blink(LED *dev, int _state) {
	set_state(dev, _state);
	HAL_GPIO_WritePin(dev->red_port, dev->red_pin, dev->ledSeq[0]);
	HAL_GPIO_WritePin(dev->green_port, dev->green_pin, dev->ledSeq[1]);
	HAL_GPIO_WritePin(dev->blue_port, dev->blue_pin, dev->ledSeq[2]);

	set_state(dev, 1000);
	HAL_GPIO_WritePin(dev->red_port, dev->red_pin, dev->ledSeq[0]);
	HAL_GPIO_WritePin(dev->green_port, dev->green_pin, dev->ledSeq[1]);
	HAL_GPIO_WritePin(dev->blue_port, dev->blue_pin, dev->ledSeq[2]);
}
