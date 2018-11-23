#include"hw_stm32f051r8.h"
#include"sw_rcc.h"
#include"sw_gpio.h"
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
void delay(unsigned int t){
	unsigned int t1, t2;
    for (t1 = 0; t1 < t; t1++)
    {
        for (t2 = 0; t2 < 0xFFF; t2++)
        {
          __asm(" nop");
        }
    }
}
int main(){
	RCC_EnClkIOport('C');
	GPIO_setmode('C',8,1);
	GPIO_setmode('C',9,1);
	while(1){
		GPIO_setbit('C',8);
		GPIO_resetbit('C',9);
		delay(0xAA);
		GPIO_resetbit('C',8);
		GPIO_setbit('C',9);
		delay(0xAA);
	}
}

