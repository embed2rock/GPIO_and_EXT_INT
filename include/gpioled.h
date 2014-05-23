/*
 * gpioled.h
 *
 *  Created on: 22/mag/2014
 *      Author: raidenfox
 */


#ifndef GPIOLED_H_
#define GPIOLED_H_

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_exti.h"

// Define per definire la configurazione di I/O del porto GPIO abilitato
#define LEDCONF_EMPTY ((uint16_t)0x0000)
#define GPIOCONF_IN (GPIO_Pin_3)
#define GPIOCONF_OUT (GPIO_Pin_0 | GPIO_Pin_1)

// Define che scrive solo su alcuni dei pin del porto GPIO abilitato
#define GPIOCONF_MASK GPIO_Pin_0



void GPIOLedInit(uint16_t,uint16_t,uint16_t);


#endif /* GPIOLED_H_ */
