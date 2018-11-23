#include "delay.h"
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