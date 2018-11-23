#include "hw_stm32f051r8.h"
#include "gpio.h"
#include "delay.h"
#include "interrupt.h"
unsigned int state = 0;
void SystemInit(){	
}
void EXTI0_1_IRQHandler(){
	unsigned int temp;
	temp = read_reg(EXTI_PR,(1<<0));
	if(1==temp){
		if(state==1){
			BSRR_C(9,1);
			state = 0;
		}
		else{
			BSRR_C(9,0);
			state = 1;
		}
	}
	//xóa cờ ngắt
	write_reg(EXTI_PR,(1<<0));
	write_reg(NVIC_ICPR,(1<<5));
}
int main(){
	enClkPA();
	enClkPC();
	Init_mode_PA(0,0);
	Init_mode_PC(8,1);
	Init_mode_PC(9,1);
	Init_Interrupt();
	while(1){
		BSRR_C(8,1);
		delay(0xFF);
		BSRR_C(8,0);
		delay(0xFF);
	}
	return 0;
}
