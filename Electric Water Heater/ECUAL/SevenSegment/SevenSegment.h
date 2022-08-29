/*
 * SevenSegment.h
 *
 * Created: 08/28/2022 6:03:05 PM
 *  Author: LessToxic
 */ 


#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_
#include "../../MCAL/DIO/DIO.h"
#define S7_A       PIN0
#define S7_B       PIN1
#define S7_C       PIN2
#define S7_D       PIN3
#define S7_Enable1 PIN5 
#define S7_Enable2 PIN4
#define S7_PORT    PORTA
void Seven_Segment_Enable1();
void Seven_Segment_Enable2();
void Seven_Segment_Disable1();
void Seven_Segment_Disable2();
void Seven_Segment_Write(uint8_t number);




#endif /* SEVENSEGMENT_H_ */