/*
 * PushButton.c
 *
 * Created: 08/09/2022 3:50:26 AM
 *  Author: Fares
 */ 
#include "PushButton.h"

//initialize Button's pin as output
void Button_init(uint8_t Button_PORT,uint8_t Button_PIN)
{
	switch (Button_PORT)
	{
		case PORT_A :

		CLEAR_BIT(DDRA,Button_PIN);
		
		break;
		case PORT_B:
		
		CLEAR_BIT(DDRB,Button_PIN);
		
		break;
		case PORT_C :
		
		CLEAR_BIT(DDRC,Button_PIN);
		
		break;
		case PORT_D :
		
		CLEAR_BIT(DDRD,Button_PIN);
		
		break;
		
		default:
	    /* Do Nothing*/
	    break;
	}
	
	
}

//read Button's pin value
void Button_read(uint8_t Button_PORT,uint8_t Button_PIN,uint8_t*value)
{
	switch (Button_PORT)
	{
		case PORT_A :

		*value=GET_BIT(PORTA,Button_PIN);
		
		break;
		case PORT_B:
		
		*value=GET_BIT(PORTB,Button_PIN);
		
		break;
		case PORT_C :
		
		*value=GET_BIT(PORTC,Button_PIN);
		
		break;
		case PORT_D :
		
		*value=GET_BIT(PORTD,Button_PIN);
		
		break;
		
		default:
	    /* Do Nothing*/
	    break;
	}
	
	
}