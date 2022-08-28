/*
 * TWI.h
 *
 * Created: 08/24/2022 8:21:48 PM
 *  Author: LessToxic
 */ 


#ifndef TWI_H_
#define TWI_H_
#include <math.h>
#include "../../Utilities/BitAccess.h"
#include "../../Utilities/Datatype.h"
#include "../../Utilities/Register.h"
#include "../../Utilities/Interrupt.h"
#include "../../Utilities/Timer.h"

#define F_CPU 1000000U
//Max TWI clock 4khz
#define SCL_CLK 400000U





#define TWBR *((volatile uint8_t*)0x20)
#define TWSR *((volatile uint8_t*)0x21)
#define TWAR *((volatile uint8_t*)0x22)
#define TWDR *((volatile uint8_t*)0x23)
#define TWCR *((volatile uint8_t*)0x56)


/* TWCR */
#define TWIE 0
#define TWEN 2
#define TWWC 3
#define TWSTO 4
#define TWSTA 5
#define TWEA 6
#define TWINT 7

/* TWSR */
#define TWPS0 0
#define TWPS1 1

/*TWAR*/
#define TWGCE 0
/* prescaler */
#define PRES_1   0
#define PRES_4   1
#define PRES_16  2
#define PRES_64  3

/*R&W*/
#define WRITE    0
#define READ     1
/*ACK*/
#define ACK      0
#define NACK     1

/*Calculate Bitrate */
#define BITRATE(TWSR)  ((F_CPU/SCL_CLK)-16)/(2*pow(4,TWSR&((1<<TWPS0)|(1<<TWPS1))))

/*TWI Status Bits */
// START condition has been transmitted 
#define TWI_START 0x08

// START condition has been transmitted
#define TWI_REP_START 0x10

// SLA+W has been transmitted;ACK has been received
#define TWI_MT_SLA_W_ACK 0x18

//SLA+W has been transmitted; NOT ACK has been received
#define TWI_MT_SLA_W_NACK 0x20
//Data byte has been transmitted;ACK has been received
#define TWI_MT_W_ACK 0x28
        
//Data byte has been transmitted;NOT ACK has been received
#define TWI_MT_W_NACK 0x30
//  Data byte has been received;ACK has been returned
#define TWI_MR_DATA_ACK 0x50

//Data byte has been received;NOT ACK has been returned
#define TWI_MR_DATA_NACK 0x58

//SLA+R has been transmitted;ACK has been received
#define TWI_MR_SLA_R_ACK 0x40

//SLA+R has been transmitted;NOT ACK has been received
#define TWI_MR_SLA_R_NACK 0x48
//Error handling
typedef enum EN_TWI_Error_t{
	OK,NOK
	}EN_TWI_Error_t;

uint8_t TWI_start(void);
uint8_t TWI_address_select(uint8_t address,uint8_t rw);
uint8_t TWI_repeated_start(void);
void TWI_stop(void);
void TWI_init(void);
#endif /* TWI_H_ */