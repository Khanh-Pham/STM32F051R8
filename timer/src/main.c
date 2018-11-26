#include"hw_stm32f051r8.h"
#include"sw_rcc.h"
#include"sw_gpio.h"
#include"sw_interrupt.h"
#include"sw_delay.h"
int main(){
	RCC_HSE_init();
	systick_init();
	RCC_EnClkIOport('C');
	GPIO_setmode('C',9,1);
	while(1){
		GPIO_setbit('C',9);
		delay_ms(500);
		GPIO_resetbit('C',9);
		delay_ms(500);
		}
	return 0;
}
void RCC_IRQHandler(){
	//RCC_CIR->HSERDYF(bit 3)
	if((RCC_CIR & (1<<3))!=0){
		//RCC_CIR->HSERDYC(bit 19) xoa co ngat
		RCC_CIR |= (1<<19);
		//chuyen doi thanh muc HSEON(bit[1:0])
		RCC_CFGR &= ~(0x3<<0);
		RCC_CFGR |= (0x01<<0);
		__asm("cpsid i");//tat cac ngat toan cuc
	}
}
void SystemInit(){
	RCC_CR |= 0x00000001u;
    RCC_CFGR &= 0xF8FFB80Cu;
  /* Reset HSEON, CSSON and PLLON bits */
    RCC_CR &= 0xFEF6FFFFu;
  /* Reset HSEBYP bit */
    RCC_CR &= 0xFFFBFFFFu;
  /* Reset PLLSRC, PLLXTPRE and PLLMUL[3:0] bits */
  	RCC_CFGR &= 0xFFC0FFFFu;
  /* Reset PREDIV[3:0] bits */
    RCC_CFGR &= 0xFFFFFFF0u;
  //   Reset USART1SW[1:0], I2C1SW, CECSW and ADCSW bits 
    RCC_CFGR3 &= 0xFFFFFEACu;
  /* Reset USART1SW[1:0], I2C1SW, USBSW and ADCSW bits */
    RCC_CFGR3 &= 0xFFFFFE6Cu;
   // Set default USB clock to PLLCLK, since there is no HSI48 
    RCC_CFGR3 |= 0x00000080u; 
   // /* Reset HSI14 bit */
    RCC_CR2 &= 0xFFFFFFFEu;
   // Disable all interrupts 
    RCC_CIR = 0x00000000u;
}

