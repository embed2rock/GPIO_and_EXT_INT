/*
 * gpioled.c
 *
 *  Created on: 22/mag/2014
 *      Author: raidenfox
 */
#include "gpioled.h"

void GPIOLedInit(uint16_t GPIOP_IN,uint16_t GPIOP_OUT,uint16_t GPIOP_MASK){
	// Assegna il clock sul porto AHB1 (e quindi anche su GPIO H)
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	/*
	 * Definisce una struct con i parametri di un singolo PIN del GPIO
	uint32_t GPIO_Pin;
  	GPIOMode_TypeDef GPIO_Mode;
    GPIOSpeed_TypeDef GPIO_Speed;
    GPIOOType_TypeDef GPIO_OType;
    GPIOPuPd_TypeDef GPIO_PuPd;
   */
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_DeInit(GPIOC);

	// Riempie ogni parametro precedente
	// della struct GPIO_InitStruct con il suo valore di default.
	GPIO_StructInit(&GPIO_InitStructure);

	// Setta le caratteristiche dei pin della configurazione di GPIO

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_Pin = (uint16_t) GPIOP_IN;
	// Conferma la configurazione
	GPIO_Init(GPIOC,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Pin = (uint16_t) GPIOP_OUT;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;


	// Conferma la configurazione
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	GPIO_SetBits(GPIOC,GPIOP_MASK);

}
