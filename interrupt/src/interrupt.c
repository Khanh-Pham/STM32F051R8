#include "interrupt.h"
void Init_Interrupt(){
	unsigned int temp;
/*thiết lập ngắt cho ngoại vi*/
	temp = read_reg(EXTI_IMR,~(0x01<<0));
	temp = temp | (0x01<<0);
	write_reg(EXTI_IMR,temp);
	//set sườn bắt ngắt
	temp = read_reg(EXTI_RTSR,~(0x01<<0));
	temp = temp | (0x01<<0);
	write_reg(EXTI_RTSR,temp);
	//set mode cài chọn muxing chon PA pin 0
	temp = read_reg(SYSCFG_EXTICR1,~(0x0F<<0));
	temp = temp | (0x00<<0);
	write_reg(SYSCFG_EXTICR1,temp);
/*thiết lập mức ưu tiên*/
	// set mức ưu tiên
	temp = read_reg(NVIC_PRI,~(0xFF<<8));
	temp = temp | (0x01<<14);
	write_reg(NVIC_PRI,temp);
	//enable trong NVIC
	temp = read_reg(NVIC_ISER,~(0x01<<5));
	temp = temp | (0x01<<5);
	write_reg(NVIC_ISER,temp);
/*bật ngắt toàn cục*/
	__asm("cpsie i");
}