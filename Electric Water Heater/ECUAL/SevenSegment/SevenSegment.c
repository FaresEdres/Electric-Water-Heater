/*
 * SevenSegment.c
 *
 * Created: 08/28/2022 5:53:18 PM
 *  Author: LessToxic
 */ 
#include "SevenSegment.h"

#include <util/delay.h>

//Initialize Seven Segment
void Seven_Segment_init()
{
	//Initialize PortA 0->5 as output
	DIO_init(PORT_A,PIN0,OUTPUT);
	DIO_init(PORT_A,PIN1,OUTPUT);
	DIO_init(PORT_A,PIN2,OUTPUT);
	DIO_init(PORT_A,PIN3,OUTPUT);
	DIO_init(PORT_A,PIN4,OUTPUT);
	DIO_init(PORT_A,PIN5,OUTPUT);
}

void Seven_Segment_Enable1()
{
	// Set the Enable1 to 1
	SET_BIT(S7_PORT,S7_Enable1);
}
void Seven_Segment_Enable2()
{
	// Set the Enable2 to 1
	SET_BIT(S7_PORT,S7_Enable2);
}
void Seven_Segment_Disable1()
{
	// Set the Enable1 to 0
	CLEAR_BIT(S7_PORT,S7_Enable1);
}
void Seven_Segment_Disable2()
{
	// Set the Enable2 to 0
	CLEAR_BIT(S7_PORT,S7_Enable2);
}
void Seven_Segment_Write(uint8_t number)
{
	uint8_t unitsDigit=0,tensDigit=0;
	// Get the tens and units digit in the number
	unitsDigit=number%10;
	tensDigit=number /10;
	//display tens digit
	S7_PORT =(tensDigit<<0);
	Seven_Segment_Enable1();
	Seven_Segment_Disable1();
	//display units digit
	S7_PORT =(unitsDigit<<0);
	Seven_Segment_Enable2();
	Seven_Segment_Disable2();
	
	
	
	
}

