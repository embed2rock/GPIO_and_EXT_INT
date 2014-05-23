/*
 * main.c
 *
 *  Created on: 14/gen/2014
 *      Author: Salvatore De Simone
 */

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_exti.h"
#include "gpioled.h"
#include "interrupt_man.h"

void setup(){
	GPIOLedInit(GPIOCONF_IN,GPIOCONF_OUT,GPIOCONF_MASK);
	init_IntManager();
}

void loop(){
}


int main(){
	setup();
	while(1){
		loop();
	}
}
