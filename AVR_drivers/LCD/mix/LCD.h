/*
 *  Author: sherif
 */ 

#ifndef LCD_H_
#define LCD_H_

// function prototypes 
void LCD_init(void);
void LCD_sendChar (char data);
void LCD_sendCmd (char cmd);
void LCD_sendString(char* str);
void LCD_pulseEnable (void);
void LCD_moveCursor (char row , char col);
void LCD_CLR(void);

// LCD mode
#define eight_bit_mode 

// LCD commands 
#define CLRSCR 0x01
#define DISP_ON_CUR_ON   0x0E
#define DISP_ON_CUR_OFF  0x0C
#define DISP_OFF_CUR_OFF 0x08
#define SHIFT_DISP_RIGHT 0x05
#define SHIFT_DISP_LEFT  0x07
#define SHIFT_CUR_RIGHT  0x14
#define SHIFT_CUR_LEFT   0x10

#define HOME 0x02
#define ENTRY_MODE 0x06
#define FOUR_BITS  0x28
#define EIGHT_BITS 0x38

//LCD ports and pins connection 
#define RS  0
#define RW  1
#define EN  2
#define LCD_DATA_PORT  'C'
#define LCD_CONTROL_PORT  'D'


#endif /* LCD_H_ */