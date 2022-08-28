/*
 * Bit_access.h
 *
 * Created: 08/09/2022 3:41:04 AM
 *  Author: Fares
 */ 


#ifndef BITACCESS_H_
#define BITACCESS_H_

/************************************************************************/
/*                          FUNCTION LIKE MACRO                         */
/************************************************************************/
#define SET_BIT(REG,BIT)    (REG|=(1<<BIT))
#define CLEAR_BIT(REG,BIT)  (REG&=~(1<<BIT))
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))
#define GET_BIT(REG,BIT)    ((REG&(1<<BIT))>>BIT)




#endif /* BIT ACCESS_H_ */