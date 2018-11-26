#ifndef __SW_GPIO_H__
#define __SW_GPIO_H__
#include"hw_gpio.h"
#define INPUT		0x00
#define OUTPUT		0x01
#define ALT			0x02
#define ANALOG		0x03
/*	set mode hoat dong cho chan port A..F,pin 0..15
	0-INPUT
	1-OUTPUT
	2-ALT
	3-ANALOG
*/
void GPIO_setmode(unsigned char port,unsigned char pin,unsigned char mode);
void GPIO_ODRport(unsigned char port,unsigned char data);
void GPIO_setbit(unsigned char port,unsigned char pin);
void GPIO_resetbit(unsigned char port,unsigned char pin);
#endif

