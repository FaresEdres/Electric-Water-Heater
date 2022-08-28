/*
 * LED.c
 *
 * Created: 08/09/2022 3:49:43 AM
 *  Author: Fares
 */ 
#include "LED.h"

//initialize LED's pin as output
void LED_init(uint8_t LED_PORT,uint8_t LED_PIN)
{
	switch (LED_PORT)
	{
		case PORT_A :

		SET_BIT(DDRA,LED_PIN);
		
		break;
		case PORT_B:
		
		SET_BIT(DDRB,LED_PIN);
		
		break;
		case PORT_C :
		
		SET_BIT(DDRC,LED_PIN);
		
		break;
		case PORT_D :
		
		SET_BIT(DDRD,LED_PIN);
		
		break;
		
		default:
	    /* Do Nothing*/
	    break;
	}
	
	
}
void LED_on(uint8_t LED_PORT,uint8_t LED_PIN)
{
	switch (LED_PORT)
	{
		case PORT_A :

		SET_BIT(PORTA,LED_PIN);
		
		break;
		case PORT_B:
		
		SET_BIT(PORTB,LED_PIN);
		
		break;
		case PORT_C :
		
		SET_BIT(PORTC,LED_PIN);
		
		break;
		case PORT_D :
		
		SET_BIT(PORTD,LED_PIN);
		
		break;
		
		default:
	    /* Do Nothing*/
	    break;
	}
	
	
}

void LED_off(uint8_t LED_PORT,uint8_t LED_PIN)
{
	switch (LED_PORT)
	{
		case PORT_A :

		CLEAR_BIT(PORTA,LED_PIN);
		
		break;
		case PORT_B:
		
		CLEAR_BIT(PORTB,LED_PIN);
		
		break;
		case PORT_C :
		
		CLEAR_BIT(PORTC,LED_PIN);
		
		break;
		case PORT_D :
		
		CLEAR_BIT(PORTD,LED_PIN);
		
		break;
		
		default:
	    /* Do Nothing*/
	    break;
	}
	
	
}

void LED_toggle(uint8_t LED_PORT,uint8_t LED_PIN)
{
	switch (LED_PORT)
	{
		case PORT_A :

		TOGGLE_BIT(PORTA,LED_PIN);
		
		break;
		case PORT_B:
		
		TOGGLE_BIT(PORTB,LED_PIN);
		
		break;
		case PORT_C :
		
		TOGGLE_BIT(PORTC,LED_PIN);
		
		break;
		case PORT_D :
		
		TOGGLE_BIT(PORTD,LED_PIN);
		
		break;
		
		default:
	    /* Do Nothing*/
	    break;
	}
	
	
}
