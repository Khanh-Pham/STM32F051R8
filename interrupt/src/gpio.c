#include "gpio.h"
/*cac ham enable clock*/
void enClkPA(){
	unsigned int temp;
	temp = read_reg(RCC_AHBENR,~(1u<<17));
	temp = temp | (1u<<17);
	write_reg(RCC_AHBENR,temp);
}
void enClkPB(){
	unsigned int temp;
	temp = read_reg(RCC_AHBENR,~(0x01<<18));
	temp = temp | (1u<<18);
	write_reg(RCC_AHBENR,temp);
}
void enClkPC(){
	unsigned int temp;
	temp = read_reg(RCC_AHBENR,~(1u<<19));
	temp = temp | (1u<<19);
	write_reg(RCC_AHBENR,temp);
}

/*Cac ham output theo ca thanh ghi ODR*/
void outPA(unsigned int value){
	unsigned int temp;
	temp = read_reg(GPIO_A_MODER,0xFF000000);
	temp |= 0x00FFFFFF;
	write_reg(GPIO_A_MODER,temp);
	write_reg(GPIO_A_ODR,value);
}
void outPB(unsigned int value){
	write_reg(GPIO_B_MODER,0x55555555);
	write_reg(GPIO_B_ODR,value);
}
void outPC(unsigned int value){
	write_reg(GPIO_C_MODER,0x55555555);
	write_reg(GPIO_C_ODR,value);
}

/*Cac ham set mode  hoat dong dau ra cho cac chan cua cac port*/
void Init_mode_PA(unsigned char pin,unsigned char value){
	unsigned int temp;
	temp = read_reg(GPIO_A_MODER,~(0x03<<(2*pin)));
	switch(value){
		case 0:
			temp |= (INPUT<<(2*pin));
			break;
		case 1:
			temp |= (OUTPUT<<(2*pin));
			break;
		case 2:
			temp |= (ALT<<(2*pin));
			break;
		case 3:
			temp |=(ANALOG<<(2*pin));
			break;
	}
	write_reg(GPIO_A_MODER,temp);
}
void Init_mode_PB(unsigned char pin,unsigned char value){
	unsigned int temp;
	temp = read_reg(GPIO_B_MODER,~(0x03<<(2*pin)));
	switch(value){
		case 0:
			temp |= (INPUT<<(2*pin));
			break;
		case 1:
			temp |= (OUTPUT<<(2*pin));
			break;
		case 2:
			temp |= (ALT<<(2*pin));
			break;
		case 3:
			temp |=(ANALOG<<(2*pin));
			break;
	}
	write_reg(GPIO_B_MODER,temp);
}
void Init_mode_PC(unsigned char pin,unsigned char value){
	unsigned int temp;
	temp = read_reg(GPIO_C_MODER,~(0x03<<(2*pin)));
	switch(value){
		case 0:
			temp |= (INPUT<<(2*pin));
			break;
		case 1:
			temp |= (OUTPUT<<(2*pin));
			break;
		case 2:
			temp |= (ALT<<(2*pin));
			break;
		case 3:
			temp |=(ANALOG<<(2*pin));
			break;
	}
	write_reg(GPIO_C_MODER,temp);
}
/*cac ham set hoac reset tung bit cu the cua cac port*/
void BSRR_A(unsigned int pin,unsigned char value){
	unsigned int temp;
	/*set dau ra la du lieu 0 hay 1*/
	temp = read_reg(GIPO_A_BSRR,~(0x01u<<pin));/*pin : 0 => 15*/
	if(value == 1){
		temp = temp | (0x01u<<pin);
		write_reg(GIPO_A_BSRR,temp);
	}
	else{
		temp = temp | (1u<<(pin+16));
		write_reg(GIPO_A_BSRR,temp);
	}
}
void BSRR_B(unsigned int pin,unsigned char value){
	unsigned int temp;
	/*set bit dau ra la 0 hay la 1*/
	temp = read_reg(GIPO_B_BSRR,~(1u<<pin));/*pin : 0 => 15*/
	if(value == 1){
		temp = temp | (1u<<pin);
		write_reg(GIPO_B_BSRR,temp);
	}
	else{
		temp = temp | (1u<<(pin+16));
		write_reg(GIPO_B_BSRR,temp);
	}
}
void BSRR_C(unsigned int pin,unsigned char value){
	unsigned int temp;
	/*set bit dau ra la 0 hay la 1*/
	temp = read_reg(GIPO_C_BSRR,~(1u<<pin));/*pin : 0 => 15*/
	if(value == 1){
		temp = temp | (1u<<pin);
		write_reg(GIPO_C_BSRR,temp);
	}
	else{
		temp = temp | (1u<<(pin+16));
		write_reg(GIPO_C_BSRR,temp);
	}
}
/*cac ham doc ve trang thai cua cac chan cua thanh ghi IDR cua cac port*/
unsigned int IDR_PA(unsigned int pin){
	unsigned int status;
	status = read_reg(GPIO_A_IDR,(0x01<<pin));
	return status;
}
unsigned int IDR_PB(unsigned int pin){
	unsigned int status;
	status = read_reg(GPIO_B_IDR,(0x01<<pin));
	return status;
}
unsigned int IDR_PC(unsigned int pin){
	unsigned int status;
	status = read_reg(GPIO_C_IDR,(0x01<<pin));
	return status;
}
