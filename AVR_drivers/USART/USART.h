/*
 *  Author: sherif
 */ 


#ifndef USART_H_
#define USART_H_

void USART_init(short baudRate);
void USART_sendData(char data);
signed char USART_receiveData(void);

#endif /* USART_H_ */