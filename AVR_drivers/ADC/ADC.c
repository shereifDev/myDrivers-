/*
 * ADC.c
 *
 * Created: 2/1/2025 1:31:49 AM
 *  Author: sherif
 */ 

#include <avr/io.h>
#include "DIO_driver.h"
#include "STD_macros.h"
#define REF_VOLT 2.56


void ADC_init (void)
{
	SET_BIT(ADCSRA,ADEN);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
}

//--------------------------------------------------------------------------------------------------------------------------------

short ADC_readVal(void)
{
	short val;
	SET_BIT(ADCSRA,ADSC);
	while(READ_BIT(ADCSRA,ADSC)==1);
	val = ADCL ;
	val|=(ADCH<<8);
	return val ;
}

//--------------------------------------------------------------------------------------------------------------------------------

char temperature (void)
{
	
	short volt,temp ;
	volt = ((REF_VOLT*ADC_readVal())/1024)*1000;  
 	temp = volt/10 ;
	return temp ;	
}