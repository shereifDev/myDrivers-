/*
 * _7SEGMENT_driver.c
 *
 * Created: 12/11/2024 11:25:45 AM
 *  Author: sherif
 */ 
#include "DIO_driver.h"



void sevenSeg_init (char port)
{
	setPortDir(port,0b01111111);
}

//--------------------------------------------------------------------------------------------------------------------------------

void sevenSeg_displayNum (char port , char num)
{
	if (num==0)
	{
		writePort(port,0b0111111);
	}
	else if (num==1)
	{
		writePort(port,0b0000110);
	}
	else if (num==2)
	{
		writePort(port,0b1011011);
	}
	else if (num==3)
	{
		writePort(port,0b1001111);
	}
	else if (num==4)
	{
		writePort(port,0x66);
	}
	else if (num==5)
	{
		writePort(port,0x6d);
	}
	else if (num==6)
	{
		writePort(port,0x7d);
	}
	else if (num==7)
	{
		writePort(port,0x47);
	}
	else if (num==8)
	{
		writePort(port,0x7f);
	}
	else if (num==9)
	{
		writePort(port,0x6f);
	}
}


//--------------------------------------------------------------------------------------------------------------------------------

void sevenSeg_displayNum2 (char port , char num)
{
	
 char arr[]={ 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f,0x77,0x7f,0x39,0x3f,0x79,0x71};
	 writePort(port,arr[num]);
}

//--------------------------------------------------------------------------------------------------------------------------------

void BCD_init (char port , char nibble)
{
	switch(nibble)
	{
		case 'l':
		case 'L':
		setLowNibbleDir(port,0b1111);
		break;
		
		case 'h':
		case 'H':
		setHighNibbleDir(port,0b1111);
		break;
	}
}

//--------------------------------------------------------------------------------------------------------------------------------

void BCD_displayNum (char port , char nipple , char num)
{
	switch(nipple)
	{
		case 'l':
		case 'L':
		writeLowNibble(port,num);
		break;
		
		case 'h':
		case 'H':
		writeHighNibble(port,num);
		break;
	}
}