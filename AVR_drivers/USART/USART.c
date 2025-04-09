/*
 *  Author: sherif
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "STD_macros.h"

void USART_init(short baudRate)
{ 
	// set the baud rate 
	short UBRR = ((F_CPU/(16*baudRate))-1) ;
	UBRRH = UBRR>>8 ;
	UBRRL = UBRR ;
	//enable USART sender & receiver 
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	// no parity bit & 8 bit char size & 1 stop bit 
	UCSRC = 0x86 ;	
}

/*--------------------------------------------------------------------------------*/

void USART_sendData(char data)
{
	UDR = data ;
	while(READ_BIT(UCSRA,TXC)==0);        //  until transmition complete
}

/*--------------------------------------------------------------------------------*/

signed char USART_receiveData(void)
{
	char data ;
	while(READ_BIT(UCSRA,RXC)==0);
	data = UDR ;
	if(READ_BIT(UCSRA,FE)==1)
	{
		data = -1;
	}
	if(READ_BIT(UCSRA,DOR)==1)
	{
		data = -1;
	}
	if(READ_BIT(UCSRA,PE)==1)
	{
		data = -1;
	}
	return data ;
}
