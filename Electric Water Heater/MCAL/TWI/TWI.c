/*
 * TWI.c
 *
 * Created: 08/24/2022 8:21:57 PM
 *  Author: LessToxic
 */ 

#include "TWI_config.h"
#include "TWI.h"

/*
void TWI_Init(void)
{
	//ACK OR NACK
	#if TWI_ACK  == ACK
	TWSR|=(1<<TWEA);
	
	#elif TWI_ACK  == NACK
	TWSR&=~(1<<TWEA);
	
	#endif
	
	//reset Status
	TWSR&=0x6F;
	
	//Node Address
	TWAR|=(NODE_ADD<<1);
    //Disable General Call
    TWAR&=~(1<<TWGCE);
	//PRES_1,PRES_4,PRES_16,PRES_64
	TWBR=BITRATE(TWSR);
	//Enable TWI
	TWCR|=(1<<TWEN);
	//Clear Flag
	TWCR|=(1<<TWINT);

}







*/

uint8_t TWI_start(void)
{   //    Clear Flag -Start bit- Enable TWI 
	TWCR= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	//wait flag to be raised
	while (!(TWCR &(1<<TWINT)));
	//check status reg
	if((TWSR& 0xF8)!=TWI_START)
	{
		return NOK;
	}
	else
	{
		return OK;
	}
}

uint8_t TWI_repeated_start(void)
{   //   Clear Flag -Start bit- Enable TWI 
	TWCR =(1<<TWINT)| (1<<TWSTA) |(1<<TWEN);
	//wait flag to be raised
	while (!(TWCR & (1<<TWINT)));
	//check status reg
	if((TWSR & 0xF8)!= TWI_REP_START)
	{
		return NOK;
	}
	else 
	{
		return OK;
	}
	

	
	
	
}

uint8_t TWI_address_select(uint8_t address,uint8_t rw)
{
	uint8_t status;
	
if (rw==WRITE)
{
	TWDR= address+0;
} 
else if (rw==READ)
{
	TWDR= address+1;
}
	//TWDR= (address<<1)|rw;
	//    Clear Flag - Enable TWI 
	TWCR = (1<<TWINT)|(1<<TWEN);
	//wait flag to be raised
	while(!(TWCR&(1<<TWINT)));
	status= TWSR & 0XF8;
	
	if(status== TWI_MT_SLA_W_ACK)
	{
		return OK;
	}
	
	else if(status ==TWI_MT_SLA_W_NACK)
	{
		return OK;
	}
	if(status ==TWI_MR_SLA_R_ACK)
	{
		return OK;
	}
	else if(status ==TWI_MR_SLA_R_NACK)
	{
		return OK;
	}
	else
	{
		return NOK;
	}
}

uint8_t TWI_data_event(uint8_t* data,uint8_t rw, uint8_t ack)
{
	uint8_t status;
	//Sending data
	if(rw==WRITE)
	{
		TWDR= *data;
		TWCR= (1<<TWEN)|(1<<TWINT);
		while (!(TWCR & (1<<TWINT)));
		status=TWSR &0xF8;
		if (status == TWI_MT_W_ACK)
		{
			return OK;
		}
		else if (status==TWI_MT_W_NACK)
		{
			return OK;
		}
		else
		{
			return NOK;

		}
	}
	//Receiving data
	else if (rw==READ)
	{
		if(ack==ACK)
		{
			TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);
		}
	else if(ack==NACK)
	{
		TWCR=(1<<TWEN)|(1<<TWINT);
	}
	while(!(TWCR&(1<<TWINT)));
	*data=TWDR;
	status=TWSR & 0xF8;
	if(status==TWI_MR_DATA_ACK)
	{
		return OK;
	}
	else if(status==TWI_MR_DATA_NACK)
	{
		return OK;
	}
	else
	{
		return NOK;
	}
	} 
	
}
/*void TWI_StopCondition(void)
{
TWCR|=(1<<TWSTA);

while(!(TWCR&(1<<TWINT)));

//Clear Flag
TWCR|=(1<<TWINT);

}
*/
void TWI_stop(void)
{//   Clear Flag -Stop bit- Enable TWI 
	TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
	//wait flag to be raised
	while(TWCR&(1<<TWSTO));
}
/*
void TWI_init(void)
{
	//Prescaler
	#if TWI_PRESCALER == PRES_1
	TWSR&=~(1<<TWPS0);
	TWSR&=~(1<<TWPS1);
	#elif TWI_PRESCALER == PRES_4
	TWSR|=(1<<TWPS0);
	TWSR&=~(1<<TWPS1);
	#elif TWI_PRESCALER == PRES_16
	TWSR&=~(1<<TWPS0);
	TWSR|=(1<<TWPS1);
	#elif TWI_PRESCALER == PRES_64
	TWSR|=(1<<TWPS0);
	TWSR|=(1<<TWPS1);
	#endif

}*/

	//TWI_init();
		/*TWSR=0X00;
	TWBR=BITRATE(TWSR);*/
 /*Master Receive */
/*
	uint8_t data;
	if(TWI_start()==OK)
	{
		if (TWI_address_select(0x10,READ)== OK)
		{
			if (TWI_data_event(&data,READ,NACK)==OK)
			{
				TWI_stop();
			}
		}
	}
	


/* Master Transmit*//*
if(TWI_start()==OK)
{
	if (TWI_address_select(0x10,WRITE)== OK)
	{
		if (TWI_data_event(&data,WRITE,ACK)==OK)
		{
			TWI_stop();
		}
	}
}
*/
 
