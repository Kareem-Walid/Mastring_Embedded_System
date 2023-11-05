
#include <stdint.h>
#include <stdlib.h>

typedef volatile unsigned int    vuint32_t;


#define  RCC_BASE     0x40021000
#define  RCC_IOPAEN   (1<<2)
#define  RCC_APB2ENR  *(volatile uint32_t*)(RCC_BASE + 0x18)


#define  GPIOA_BASE   0x40010800UL
#define  GPIOA_CRH    *(volatile uint32_t*)(GPIOA_BASE + 0x04)
#define  GPIOA_ODR    *(volatile uint32_t*)(GPIOA_BASE + 0x0C)
#define  GPIOA13      (1UL<<13)

typedef union{
	vuint32_t  all_fields;
	struct{
		vuint32_t   reserved:13;
		vuint32_t   P_13:1;
	}Pin;

}R_ODR_t;


volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE + 0x0C);

void*  _sbrk(int Inc)
{
	static  uint8_t* Heap_Ptr = NULL;
            uint8_t* Prev_Heap_Ptr = NULL;
	extern uint32_t _E_BSS;
    extern uint32_t _Heap_End;

	
	
	/* First Time */
	if(Heap_Ptr == NULL)
	{
		Heap_Ptr = (uint8_t*)&_E_BSS;
	}
	
	Prev_Heap_Ptr = Heap_Ptr;
	
	if((Heap_Ptr + Inc ) > (uint8_t*)&_Heap_End)
	{
		return (void*) NULL;
	}
	
	/* Booking Inc size */
	Heap_Ptr += Inc;
	
	return (void*)Prev_Heap_Ptr;
}


int main(void)
{
     int* Ptr = (int*)malloc(4);
	free(Ptr);
	int i;
	RCC_APB2ENR |= RCC_IOPAEN;
	GPIOA_CRH  &= 0xFF0FFFFF;
	GPIOA_CRH  |= 0x00200000;

	

	while(1)
	{
		R_ODR  -> Pin.P_13 = 1;
		for (i=0;i<180000;i++);
		R_ODR  -> Pin.P_13 = 0;
		for (i=0;i<180000;i++);

	}

}
