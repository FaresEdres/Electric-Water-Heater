/*
 * Register.h
 *
 * Created: 08/09/2022 4:22:41 AM
 *  Author: Fares
 */ 


#ifndef REGISTER_H_
#define REGISTER_H_
/***************************************/
/*               PORT                  */
/***************************************/

/*              PORTA                  */
#define PORTA  *((volatile uint8_t *)0X3B)
#define DDRA   *((volatile uint8_t *)0X3A)
#define PINA   *((volatile uint8_t *)0X39)

/*              PORTB                  */
#define PORTB  *((volatile uint8_t *)0X38)
#define DDRB   *((volatile uint8_t *)0X37)
#define PINB   *((volatile uint8_t *)0X36)

/*              PORTC                  */
#define PORTC  *((volatile uint8_t *)0X35)
#define DDRC   *((volatile uint8_t *)0X34)
#define PINC   *((volatile uint8_t *)0X33)

/*              PORTD                  */
#define PORTD  *((volatile uint8_t *)0X32)
#define DDRD   *((volatile uint8_t *)0X31)
#define PIND   *((volatile uint8_t *)0X30)


/***************************************/
/*              TIMER                  */

#define TIFR     *((volatile uint8_t *)0X58)
/***************************************/
/*              TIMER0                 */
#define TCCR0    *((volatile uint8_t *)0X53)
#define TCNT0    *((volatile uint8_t *)0X52)
/*              TIMER2                */
#define TCCR2    *((volatile uint8_t *)0X45)
#define TCNT2    *((volatile uint8_t *)0X44)



/***************************************/
/*              INTERRUPT              */
/***************************************/

#define MCUCR    *((volatile uint8_t *)0X55)
#define MCUCSR   *((volatile uint8_t *)0X54)
#define GICR     *((volatile uint8_t *)0X5B)
#define GIFR     *((volatile uint8_t *)0X5A)
#define SREG     *((volatile uint8_t *)0X5F)
#define TIMSK    *((volatile uint8_t *)0X59)



/***************************************/
/*                ADC                  */
/***************************************/
#define SFIOR    *((volatile uint8_t *)0X50)
#define ADMUX    *((volatile uint8_t *)0X27)
#define ADCSRA   *((volatile uint8_t *)0X26)
#define ADCH     *((volatile uint8_t *)0X25)
#define ADCL     *((volatile uint8_t *)0X24)
 
#endif /* REGISTER_H_ */