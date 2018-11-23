#ifndef __HW_UART_H__
#define __HW_UART_H__
#define USART1_BASE			0x40013800u
/*----------------------------USART1--------------------------------------*/
#define USART1_CR1			*((volatile unsigned long*)(USART1_BASE + 0x00))
#define UASRT1_CR2			*((volatile unsigned long*)(USART1_BASE + 0x04))
#define UASRT1_CR3			*((volatile unsigned long*)(USART1_BASE + 0x08))
#define UASRT1_BRR			*((volatile unsigned long*)(USART1_BASE + 0x0C))
#define UASRT1_GTPR			*((volatile unsigned long*)(USART1_BASE + 0x10))
#define UASRT1_RTOR			*((volatile unsigned long*)(USART1_BASE + 0x14))
#define UASRT1_RQR			*((volatile unsigned long*)(USART1_BASE + 0x18))
#define UASRT1_ISR			*((volatile unsigned long*)(USART1_BASE + 0x1C))
#define UASRT1_ICR			*((volatile unsigned long*)(USART1_BASE + 0x20))
#define UASRT1_RDR			*((volatile unsigned long*)(USART1_BASE + 0x24))
#define UASRT1_TDR			*((volatile unsigned long*)(USART1_BASE + 0x28))
/*----------------------------USART2--------------------------------------*/

#endif