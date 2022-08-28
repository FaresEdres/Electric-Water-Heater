/*
 * ADC_config.h
 *
 * Created: 08/13/2022 12:44:57 PM
 *  Author: LessToxic
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_
/*
voltage reference :
AREF,AVCC,INTERNAL_2_56V  
*/					 
#define ADC_REF  AREF
/*
Prescaler:
PRES_2_0,PRES_2_1,PRES_4,PRES_8,PRES_16,PRES_32,PRES_64,PRES_128
*/
#define ADC_PRES PRES_32
/*
Adjustment:
RIGHT_ADJ,LEFT_ADJ
*/
#define ADC_ADJ  RIGHT_ADJ


#endif /* ADC_CONFIG_H_ */

 
