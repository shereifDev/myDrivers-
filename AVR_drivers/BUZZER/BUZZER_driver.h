/*
 * BUZZER_driver.h
 *
 * Created: 12/11/2024 12:01:51 AM
 *  Author: sherif
 */ 


#ifndef BUZZER_DRIVER_H_
#define BUZZER_DRIVER_H_

void BUZZER_init(char port , char pin);
void BUZZER_turnOn(char port , char pin);
void BUZZER_turnOff(char port , char pin);

#endif /* BUZZER_DRIVER_H_ */