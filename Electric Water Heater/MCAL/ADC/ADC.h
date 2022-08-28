/*
 * ADC.h
 *
 * Created: 08/13/2022 12:16:46 PM
 *  Author: Fares
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "../../Utilities/BitAccess.h"
#include "../../Utilities/Datatype.h"
#include "../../Utilities/Register.h"
#include "../../Utilities/Interrupt.h"
#include "../../Utilities/Timer.h"

/* ADMUX */
#define MUX0  0
#define MUX1  1
#define MUX2  2 
#define MUX3  3 
#define MUX4  4
#define ADLAR 5
#define REFS0 6
#define REFS1 7

/* ADCSRA */

#define ADPS0  0
#define ADPS1  1
#define ADPS2  2
#define ADIE   3
#define ADIF   4
#define ADATE  5
#define ADSC   6
#define ADEN   7

/* SFIOR */
#define ADTS0  5
#define ADTS1  6
#define ADTS2  7

/************************************************************************/
/*                      Prescaler                                       */
/************************************************************************/
#define PRES_2_0  0
#define PRES_2_1  1
#define PRES_4    2
#define PRES_8    3
#define PRES_16   4
#define PRES_32   5
#define PRES_64   6
#define PRES_128  7

/************************************************************************/
/*                      Voltage Reference                               */
/************************************************************************/
#define AVCC            0
#define AREF            1
#define INTERNAL_2_56V  2

/************************************************************************/
/*                         ADJUSTMENT                                   */
/************************************************************************/
#define RIGHT_ADJ 0
#define LEFT_ADJ  1

/************************************************************************/
/*                          AutoTrigger                                 */
/************************************************************************/
#define FreeRunningMode          0
#define AnalogComparator         1
#define ADC_EXT_INT_0            3 
#define CTC_0                    4    
#define ADC_Timer_0_OVF          5  
#define CTC_B                    6      
#define ADC_Timer_1_OVF          8
#define Timer_1_Capture_Event    9




/************************************************************************/
/*                          API                                         */
/************************************************************************/
void ADC_init(uint8_t PORT,uint8_t PIN);
void ADC_read(uint16_t* u16Read);
void ADC_selectChannel(uint8_t channel);
void ADC_startConversion(void);
/*
selectAutoTrigger:
Pass one of these argument
--------------------------
FreeRunningMode,AnalogComparator,ADC_EXT_INT_0,CTC_0,ADC_Timer_0_OVF,CTC_B,ADC_Timer_1_OVF,Timer_1_Capture_Event     
*/
void ADC_selectAutoTrigger(uint8_t Trigger);

#endif /* ADC_H_ */