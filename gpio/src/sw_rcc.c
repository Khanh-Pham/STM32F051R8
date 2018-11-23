#include"sw_rcc.h"
void RCC_EnClkIOport(unsigned char port){
	switch(port){
		case 'A':
		   {	
			RCC_AHBENR |= (1<<17);
			break;
		   }
		case 'B':
			{
			RCC_AHBENR |= (1<<18);
			break;
			}
		case 'C':
			{
			RCC_AHBENR |= (1<<19);
			break;
			}
		case 'D':
			{
			RCC_AHBENR |= (1<<20);
			break;
			}
		case 'E':
			{
			RCC_AHBENR |= (1<<21);
			break;
			}
		case 'F':
			{
			RCC_AHBENR |= (1<<22);
			break;
			}
	 }
}

