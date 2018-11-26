#include"sw_interrupt.h"
void It_init(){
	EXTI_IMR |= (1<<0);
	SYSCFG_EXTICR1 |= (0x0<<0);
	EXTI_RTSR |= (1<<0);
	// enable NVIC
	NVIC_PRI1 |= (0x00<<14);
	NVIC_ISER |= (1<<5);
	__asm("cpsie i");
}

