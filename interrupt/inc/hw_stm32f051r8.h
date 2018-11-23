#ifndef __HW_STM32F051R8_H__
#define __HW_STM32F051R8_H__

/*macro doc ghi cac bit trong 1 thanh ghi*/
#define	write_reg(add,val)			*((unsigned long int *)(add)) = val
#define read_reg(add,mask)			*((unsigned long int *)(add)) & mask
/*thanh ghi khoi tao clock cho GPIO cua stm32*/
#define RCC_BASE					0x40021000u
#define RCC_AHBENR					(RCC_BASE + 0x14)
/*cac thanh ghi GIPO cho 5 port*/
/*goc dia chi cac thanh ghi GPIO*/
#define	GIPO_A_BASE 				0x48000000u
#define	GIPO_B_BASE 				0x48000400u
#define	GIPO_C_BASE 				0x48000800u
#define	GIPO_D_BASE 				0x48000C00u
#define	GIPO_E_BASE 				0x48001000u
#define	GIPO_F_BASE 				0x48001400u
/*khai bao cac thanh ghi set mode hoat dong cho cac chan GPIO cua cac port*/
#define GPIO_A_MODER				(GIPO_A_BASE + 0x00u)
#define GPIO_B_MODER				(GIPO_B_BASE + 0x00u)
#define GPIO_C_MODER				(GIPO_C_BASE + 0x00u)
#define GPIO_D_MODER				(GIPO_D_BASE + 0x00u)
#define GPIO_E_MODER				(GIPO_E_BASE + 0x00u)
#define GPIO_F_MODER				(GIPO_F_BASE + 0x00u)
/*cac tuy chon mode hoat dong cua cac pin trong mot thanh ghi*/
#define INPUT						0x00u
#define OUTPUT						0x01u
#define ALT							0x02u
#define ANALOG						0x03u
/*khai bao cac trang thai hoat dong co tro treo hoac ho cuc output type resgister*/
#define GPIO_A_OTYPER				(GIPO_A_BASE + 0x04u)
#define GPIO_B_OTYPER				(GIPO_B_BASE + 0x04u)
#define GPIO_C_OTYPER				(GIPO_C_BASE + 0x04u)
#define GPIO_D_OTYPER				(GIPO_D_BASE + 0x04u)
#define GPIO_E_OTYPER				(GIPO_E_BASE + 0x04u)
#define GPIO_F_OTYPER				(GIPO_F_BASE + 0x04u)
/*Khai bao cac thanh ghi cho phep tro keo len(pull up) hoac tro keo xuong(pull down)*/
#define GPIO_A_PUPDR				(GIPO_A_BASE + 0x0Cu)
#define GPIO_B_PUPDR				(GIPO_B_BASE + 0x0Cu)
#define GPIO_C_PUPDR				(GIPO_C_BASE + 0x0Cu)
#define GPIO_D_PUPDR				(GIPO_D_BASE + 0x0Cu)
#define GPIO_E_PUPDR				(GIPO_E_BASE + 0x0Cu)
#define GPIO_F_PUPDR				(GIPO_F_BASE + 0x0Cu)
/*cac mode chon cho pull up or pull down*/
#define PULL_UP						0x01u
#define PULL_DOWN					0x02u
/*cac thanh ghi input data*/
#define GPIO_A_IDR					(GIPO_A_BASE + 0x10u)
#define GPIO_B_IDR					(GIPO_B_BASE + 0x10u)
#define GPIO_C_IDR					(GIPO_C_BASE + 0x10u)
#define GPIO_D_IDR					(GIPO_D_BASE + 0x10u)
#define GPIO_E_IDR					(GIPO_E_BASE + 0x10u)
#define GPIO_F_IDR					(GIPO_F_BASE + 0x10u)
/*Cac thanh ghi set trang thai dau ra cho ca  1 port*/
#define GPIO_A_ODR 					(GIPO_A_BASE + 0x14u)
#define GPIO_B_ODR 					(GIPO_B_BASE + 0x14u)
#define GPIO_C_ODR 					(GIPO_C_BASE + 0x14u)
#define GPIO_D_ODR 					(GIPO_D_BASE + 0x14u)
#define GPIO_E_ODR 					(GIPO_E_BASE + 0x14u)
#define GPIO_F_ODR 					(GIPO_F_BASE + 0x14u)
/*cac thanh ghi cho phep set hoac reset bit cua tung thanh ghi*/
#define GIPO_A_BSRR					(GIPO_A_BASE + 0x18u)
#define GIPO_B_BSRR					(GIPO_B_BASE + 0x18u)
#define GIPO_C_BSRR					(GIPO_C_BASE + 0x18u)
#define GIPO_D_BSRR					(GIPO_D_BASE + 0x18u)
#define GIPO_E_BSRR					(GIPO_E_BASE + 0x18u)
#define GIPO_F_BSRR					(GIPO_F_BASE + 0x18u)
/*EXTI*/
#define EXTI_BASE					0x40010400u
#define EXTI_IMR					(EXTI_BASE   + 0x00u)
#define EXTI_EMR					(EXTI_BASE   + 0x04u)
#define EXTI_RTSR					(EXTI_BASE   + 0x08u)
#define EXTI_FTSR					(EXTI_BASE	 + 0x0Cu)
#define EXTI_SWIER					(EXTI_BASE	 + 0x10u)
#define EXTI_PR						(EXTI_BASE   + 0x14u)
/*SYSCFG*/
#define SYSCFG_BASE					0x40010000u
#define SYSCFG_EXTICR1				(SYSCFG_BASE + 0x08u)
/*NVIC*/
#define NVIC_ISER					0xE000E100u
#define NVIC_ICER					0xE000E180u
#define NVIC_ISPR					0xE000E200u
#define NVIC_ICPR					0xE000E280u
#define NVIC_PRI					0xE000E404u


#endif