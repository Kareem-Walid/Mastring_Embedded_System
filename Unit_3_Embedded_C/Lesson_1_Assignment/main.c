
#include "Platform_Types.h"


#define  RCC_BASE     0x40021000
#define  GPIOA_BASE   0x40010800
#define  RCC_APB2ENR  *(volatile uint32*)(RCC_BASE   + 0x18)
#define  GPIOA_CRH    *(volatile uint32*)(GPIOA_BASE + 0x04)
#define  GPIOA_ODR    *(volatile uint32*)(GPIOA_BASE + 0x0C)



#define  RCC_IOPAEN   (1<<2)
#define  GPIOA13      (1UL<<13)



typedef union{
	vuint32  all_fields;
	struct{
		vuint32   reserved:13;
		vuint32   P_13:1;
	}Pin;

}R_ODR_t;


volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE + 0x0C);


int main(void)
{
	// int i;
	RCC_APB2ENR |= RCC_IOPAEN;
	GPIOA_CRH   &= 0xFF0FFFFF;
	GPIOA_CRH   |= 0x00200000;

	while(1)
	{
		R_ODR  -> Pin.P_13 = 1;
	//	for (i=0;i<500000;i++);
	//	R_ODR  -> Pin.P_13 = 0;
	//	for (i=0;i<500000;i++);

	}

}
