/*
 * Timer.h
 *
 * Created: 08/10/2022 6:24:43 AM
 *  Author: Fares
 */ 


#ifndef TIMER_H_
#define TIMER_H_

/************************************************************************/
/*                            MACRO                                     */
/************************************************************************/

/* TCCR0 */
#define CS00  0
#define CS01  1
#define CS02  2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0  7

/* TIMSK */
#define TOIE0 0
#define OCIE0 1
#define TOIE2 6
#define OCIE2 7

/* TIFR */
#define TOV0 0
#define OCF0 1
#define TOV2 6
#define OCF2 7

/* TCCR2 */
#define CS20  0
#define CS21  1
#define CS22  2
#define WGM21 3
#define COM20 4
#define COM21 5
#define WGM20 6
#define FOC2  7



#endif /* TIMER_H_ */