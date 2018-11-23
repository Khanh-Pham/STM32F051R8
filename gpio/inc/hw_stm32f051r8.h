#ifndef __HW_STM32F051R8_H__
#define __HW_STM32F051R8_H__
#include"hw_rcc.h"
#include"hw_gpio.h"
#define NVIC_ISER					0xE000E100u
#define NVIC_ICER					0xE000E180u
#define NVIC_ISPR					0xE000E200u
#define NVIC_ICPR					0xE000E280u
/*---------------reg set priority--------------*/
#define NVIC_PRI0					0xE000E400u
#define NVIC_PRI1					0xE000E404u
#define NVIC_PRI2					0xE000E408u
#define NVIC_PRI3					0xE000E40Cu
#define NVIC_PRI4					0xE000E410u
#define NVIC_PRI5					0xE000E414u
#define NVIC_PRI6					0xE000E418u
#define NVIC_PRI7					0xE000E41Cu
#endif

