/*
 * PushButton.h
 *
 * Created: 08/09/2022 3:50:14 AM
 *  Author: Fares
 */ 


#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_
#include "../../MCAL/DIO/DIO.h"

/************************************************************************/
/*                              API                                     */
/************************************************************************/

void Button_init(uint8_t Button_PORT,uint8_t Button_PIN);
void Button_read(uint8_t Button_PORT,uint8_t Button_PIN,uint8_t*value);




#endif /* PUSHBUTTON_H_ */