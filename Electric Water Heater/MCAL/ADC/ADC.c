/*
 * ADC.c
 *
 * Created: 08/13/2022 12:16:28 PM
 *  Author: Fares
 */ 

#include "ADC.h"
#include "ADC_config.h"
void ADC_init(uint8_t PORT,uint8_t PIN)
{
/************************************************************************/
/*                      Prescaler                                       */
/************************************************************************/

	#if   ADC_PRES == PRES_2_0
	  CLEAR_BIT(ADCSRA,ADPS0);
	  CLEAR_BIT(ADCSRA,ADPS1);
	  CLEAR_BIT(ADCSRA,ADPS2);
	#elif ADC_PRES == PRES_2_1
	    SET_BIT(ADCSRA,ADPS0);
	    CLEAR_BIT(ADCSRA,ADPS1);
	    CLEAR_BIT(ADCSRA,ADPS2);
	#elif ADC_PRES == PRES_4
	    CLEAR_BIT(ADCSRA,ADPS0);
	    SET_BIT(ADCSRA,ADPS1);
	    CLEAR_BIT(ADCSRA,ADPS2);
	#elif ADC_PRES == PRES_8
	    SET_BIT(ADCSRA,ADPS0);
	    SET_BIT(ADCSRA,ADPS1);
	    CLEAR_BIT(ADCSRA,ADPS2);
	#elif ADC_PRES == PRES_16
	    CLEAR_BIT(ADCSRA,ADPS0);
	    CLEAR_BIT(ADCSRA,ADPS1);
	    SET_BIT(ADCSRA,ADPS2);
	#elif ADC_PRES == PRES_32
		 SET_BIT(ADCSRA,ADPS0);
		 CLEAR_BIT(ADCSRA,ADPS1);
		 SET_BIT(ADCSRA,ADPS2);
	#elif ADC_PRES == PRES_64
	    CLEAR_BIT(ADCSRA,ADPS0);
	    SET_BIT(ADCSRA,ADPS1);
	    SET_BIT(ADCSRA,ADPS2);	
	#elif ADC_PRES == PRES_128
	    SET_BIT(ADCSRA,ADPS0);
	    SET_BIT(ADCSRA,ADPS1);
	    SET_BIT(ADCSRA,ADPS2);
	#endif
	
/************************************************************************/
/*                      Voltage Reference                               */
/************************************************************************/		

	#if   ADC_REF == AREF
	  CLEAR_BIT(ADMUX,REFS0);
	  CLEAR_BIT(ADMUX,REFS1);
	#elif ADC_REF == AVCC
	  SET_BIT(ADMUX,REFS0);
	  CLEAR_BIT(ADMUX,REFS1);	
	#elif ADC_REF == INTERNAL_2_56V
	  SET_BIT(ADMUX,REFS0);
	  SET_BIT(ADMUX,REFS1);
    #endif

/************************************************************************/
/*                         ADJUSTMENT                                   */
/************************************************************************/		
	#if ADC_ADJ == RIGHT_ADJ
	  CLEAR_BIT (ADMUX,ADLAR);
	#elif ADC_ADJ== LEFT_ADJ
      SET_BIT(ADMUX,ADLAR);
    #endif
	
/************************************************************************/
/*                         Enable ADC                                   */
/************************************************************************/
	   SET_BIT(ADCSRA,ADEN);
}
void ADC_read(uint16_t *u16Read)
{
	#if ADC_ADJ==RIGHT_ADJ
	  *u16Read=ADCL;
	  *u16Read=(uint16_t)ADCH<<8;
	#elif ADC_ADJ==LEFT_ADJ
      *u16Read=(uint16_t)ADCH<<2;
	  *u16Read=ADCL>>6;
	  
   #endif
	
}

void ADC_selectChannel(uint8_t channel)
{
	if(channel<=32)
	{
	 CLEAR_BIT(ADMUX,MUX0);
	 CLEAR_BIT(ADMUX,MUX1);
	 CLEAR_BIT(ADMUX,MUX2);
	 CLEAR_BIT(ADMUX,MUX3);
	 CLEAR_BIT(ADMUX,MUX4);
	
	 ADMUX|=channel;
	}
	
}
void ADC_startConversion(void)
{
	
	SET_BIT(ADCSRA,ADSC);
}

void ADC_selectAutoTrigger(uint8_t Trigger)
{
	if(Trigger<=7)
	{
	
	SFIOR &= 0X1F;
	SFIOR  = Trigger<<5;
	SET_BIT(ADCSRA,ADATE);
	}
}