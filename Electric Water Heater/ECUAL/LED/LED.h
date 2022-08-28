/*
 * LED.h
 *
 * Created: 08/09/2022 3:49:54 AM
 *  Author: Fares
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO/DIO.h"

/************************************************************************/
/*                              API                                     */
/************************************************************************/

void LED_init(uint8_t LED_PORT,uint8_t LED_PIN);
void LED_on(uint8_t LED_PORT,uint8_t LED_PIN);
void LED_off(uint8_t LED_PORT,uint8_t LED_PIN);
void LED_toggle(uint8_t LED_PORT,uint8_t LED_PIN);




#endif /* LED_H_ */