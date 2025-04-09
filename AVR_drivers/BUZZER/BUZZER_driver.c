/*
 * BUZZER_driver.c
 *
 * Created: 12/11/2024 12:01:38 AM
 *  Author: sherif
 */ 
#include "DIO_driver.h"



void BUZZER_init(char port , char pin)
{
	setPinDIr(port , pin , 1);
}

//--------------------------------------------------------------------------------------------------------------------------------

void BUZZER_turnOn(char port , char pin)
{
	writePIn(port,pin,1);
}

//--------------------------------------------------------------------------------------------------------------------------------

void BUZZER_turnOff(char port , char pin)
{
	writePIn(port,pin,0);
}