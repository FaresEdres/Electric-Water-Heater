/*
 * DIO.c
 *
 * Created: 08/09/2022 3:49:33 AM
 *  Author: Fares
 */ 

#include "DIO.h"

/*          PIN initialization                 */

void DIO_init(uint8_t PORT,uint8_t PIN,uint8_t direction)
{
	switch (PORT)
	{
	case PORT_A :
	switch (direction)
	{
		case INPUT:
		CLEAR_BIT(DDRA,PIN);
		break;
		case OUTPUT:
		SET_BIT(DDRA,PIN);
		break;
		
		default:
		/* Do Nothing*/
		break;
	}
		break;
	case PORT_B:
	switch (direction)
	{
		case INPUT:
		CLEAR_BIT(DDRB,PIN);
		break;
		case OUTPUT:
		SET_BIT(DDRB,PIN);
		break;
		
		default:
		/* Do Nothing*/
		break;
	}
		break;
	case PORT_C :
	switch (direction)
	{
		case INPUT:
		CLEAR_BIT(DDRC,PIN);
		break;
		case OUTPUT:
		SET_BIT(DDRC,PIN);
		break;
		
		default:
		/* Do Nothing*/
		break;
	}
		break;
	case PORT_D :
	switch (direction)
	{
		case INPUT:
		CLEAR_BIT(DDRD,PIN);
		break;
		case OUTPUT:
		SET_BIT(DDRD,PIN);
		break;
		
		default:
		/* Do Nothing*/
		break;
	}
		
	    break;
		
    default:
	/* Do Nothing*/
	break;
		
	}
	
	
}

/*           Write on specific PIN              */
void DIO_write(uint8_t PORT,uint8_t PIN,uint8_t value)
{
	switch (PORT)
	{
		case PORT_A :
		switch (value)
		{
			case LOW:
			CLEAR_BIT(PORTA,PIN);
			break;
			case HIGH:
			SET_BIT(PORTA,PIN);
			break;
			
			default:
		    /* Do Nothing*/
		    break;
		}
		break;
		case PORT_B:
		switch (value)
		{
			case LOW:
			CLEAR_BIT(PORTB,PIN);
			break;
			case HIGH:
			SET_BIT(PORTB,PIN);
			break;
			
		    default:
		    /* Do Nothing*/
		    break;
		}
		break;
		case PORT_C :
		switch (value)
		{
			case LOW:
			CLEAR_BIT(PORTC,PIN);
			break;
			case HIGH:
			SET_BIT(PORTC,PIN);
			break;
			
			default:
		    /* Do Nothing*/
		    break;
		}
		break;
		case PORT_D :
		switch (value)
		{
			case INPUT:
			CLEAR_BIT(PORTD,PIN);
			break;
			case OUTPUT:
			SET_BIT(PORTD,PIN);
			break;
			
		    default:
		    /* Do Nothing*/
		    break;
		}
		
		break;
		
		default:
		/* Do Nothing*/
	    break;
	}
	
	
}

/*           Toggle specific PIN               */
void DIO_toggle(uint8_t PORT,uint8_t PIN)
{
	switch (PORT)
	{
		case PORT_A :

         TOGGLE_BIT(PORTA,PIN);
		
		break;
		case PORT_B:
		
		TOGGLE_BIT(PORTB,PIN);
	
		break;
		case PORT_C :
		
		TOGGLE_BIT(PORTC,PIN);
		
		break;
		case PORT_D :
		
		TOGGLE_BIT(PORTD,PIN);
		
		break;
		
    	default:
	    /* Do Nothing*/
	    break;
	}
	
	
}

/*           Read specific PIN               */
void DIO_read(uint8_t PORT,uint8_t PIN,uint8_t* value)
{
	switch (PORT)
	{
		case PORT_A :

		*value=GET_BIT(PORTA,PIN);
		
		break;
		case PORT_B:
		
		*value=GET_BIT(PORTB,PIN);
		
		break;
		case PORT_C :
		
		*value=GET_BIT(PORTC,PIN);
		
		break;
		case PORT_D :
		
		*value=GET_BIT(PORTD,PIN);
		
		break;
		
		default:
	    /* Do Nothing*/
	    break;
		

	}
	
	
}