#ifndef __GPIO_H__
#define __GPIO_H__
#include "hw_stm32f051r8.h"
/*cac ham enable clock cho gpio*/
void enClkPA();
void enClkPB();
void enClkPC();

/*cac ham khoi tao mode dau ra cho cac thanh ghi
value: 0-INPUT
	   1-OUTPUT
	   2-ALT
	   3-ANALOG*/
void Init_mode_PA(unsigned char pin,unsigned char value);
void Init_mode_PB(unsigned char pin,unsigned char value);
void Init_mode_PC(unsigned char pin,unsigned char value);
/*Cac ham output cho ca thanh ghi*/
void outPA(unsigned int value);
void outPB(unsigned int value);
void outPC(unsigned int value);
/*cac ham set va reset tung bit cho cac thanh ghi*/
void BSRR_A(unsigned int pin,unsigned char value);
void BSRR_B(unsigned int pin,unsigned char value);
void BSRR_C(unsigned int pin,unsigned char value);
/*cac ham doc trang thai input(IDR) cua cac port*/
unsigned int IDR_PA(unsigned int pin);
unsigned int IDR_PB(unsigned int pin);
unsigned int IDR_PC(unsigned int pin);
#endif