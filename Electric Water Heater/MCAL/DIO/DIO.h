/*
 * DIO.h
 *
 * Created: 08/09/2022 3:49:25 AM
 *  Author: Fares
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../Utilities/BitAccess.h"
#include "../../Utilities/Datatype.h"
#include "../../Utilities/Register.h"
#include "../../Utilities/Interrupt.h"
#include "../../Utilities/Timer.h"

/***************************************/
/*            MACRO                    */
/***************************************/


/**************PORT*********************/
enum port
{
	PORT_A ,PORT_B,PORT_C,PORT_D 
};

/****************PIN********************/
enum pin
{
	PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7
};

/**********DIRECTION STATE**************/
enum DDR_state
{
	INPUT,OUTPUT
};
	
/**********VOLTAGE STATE*****************/
enum voltage_state
{
	LOW,HIGH
};	

/***************************************/
/*       FUNCTION PROTOTYPE            */
/***************************************/
void DIO_init(uint8_t PORT,uint8_t PIN,uint8_t direction);
void DIO_write(uint8_t PORT,uint8_t PIN,uint8_t value);
void DIO_toggle(uint8_t PORT,uint8_t PIN);
void DIO_read(uint8_t PORT,uint8_t PIN,uint8_t* value);


#endif /* DIO_H_ */