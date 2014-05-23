/*
 * interrupt_man.c
 *
 *  Created on: 22/mag/2014
 *      Author: raidenfox
 */


#include "interrupt_man.h"

void init_IntManager(){
	/*
	 *
	  uint8_t NVIC_IRQChannel; -> Definisce il canale di interruzioni che puo essere
	   	   	   	   	   	   	   	   abilitato o meno
  	  uint8_t NVIC_IRQChannelPreemptionPriority; -> Specifica il livello di priorità del
  	  	  	  	  	  	  	  	  	  	  	  	  	  canale (da 0 a 15)
  	  uint8_t NVIC_IRQChannelSubPriority;  -> Specifica una sottopriorità del canale
  	  	  	  	  	  	  	  	  	  	  	  specificato (da 0 a 15)
    	FunctionalState NVIC_IRQChannelCmd;  -> Specifica se il canale
  	  	  	  	  	  	  	  	  	  	  	  	  	  è abilitato o meno
	 */
	NVIC_InitTypeDef   NVIC_InitStructure;

	/*
	 *
	  uint32_t EXTI_Line; -> Specifica la linea di int esterne da abilitare o disabilitare
  	  EXTIMode_TypeDef EXTI_Mode; -> Specifica il modo (evento o interruzione)
  	  EXTITrigger_TypeDef EXTI_Trigger; -> Specifica l'evento di trigger per l'attivazione
  	  	  	  	  	  	  	  	  	  	  	 dell'interruzione
  	  FunctionalState EXTI_LineCmd; -> Specifica se la linea di int esterna è abilitata o
  	  	  	  	  	  	  	  	  	  	  disabilitata
	 */
	EXTI_InitTypeDef   EXTI_InitStructure;


	  /* Enable SYSCFG clock */
	  /* Una delle sue funzioni è:
	   * Managing the external interrupt line connection to the GPIOs */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

	  /* Definisce il porto C linea 3 come linea di int esterne
	   * selezionando prima il porto C e poi il pin
	   * NECESSARIO PER IL MULTIPLEXING DELLA LINEA DI INTERRUZIONE*/
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource3);


	// Configurazione della struttura per le int esterne
	/* Configurazione effettuata
	 * Scelta la linea 3 per le int dal pin selezionato
	 * Abilitato il modo interrupt
	 * Scelta la variazione 0->1 (rising)
	 * Abilitata la linea di interruzione 3
	 */
	EXTI_InitStructure.EXTI_Line = EXTI_Line3;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	// Setta la configurazione scelta
	EXTI_Init(&EXTI_InitStructure);

	/* Enable and set EXTI Line0 Interrupt to the lowest priority */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void EXTI3_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line3) != RESET)
  {
		GPIO_SetBits(GPIOC,GPIO_Pin_1);
 }
  else GPIO_ResetBits(GPIOC,GPIO_Pin_1);
}
