/*
 ============================================================================
 Name        : LIFO_BUFFER.c
 Author      : Kareem Walid
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "stdio.h"
#include "stdlib.h"
#include "LIFO.h"



int main(void) {

	uint32 i , *temp;
	LIFO_BUFFER_t UART_LIFO,I2C_LIFO;

	/*---- Static Allocation ----*/
	LIFO_Init(&UART_LIFO,Buffer,Width);

	printf("\n\n ====== Pushing in the Stack (Static)====== \n\n");
	for(i=0;i<Width;i++)
	{
		LIFO_PUSH(&UART_LIFO,i);
		printf("UART_LIFO_PUSH: %d\n",i);
	}

	/*---- Dynamic allocation ----*/
	uint32* Buffer2 = (uint32) malloc(Width* sizeof(Element_Type));
	LIFO_Init(&I2C_LIFO, Buffer2,Width);
	printf("\n\n ====== Pushing in the Stack (Dynamic)====== \n\n");
	for(i=0;i<Width;i++)
	{
		LIFO_PUSH(&I2C_LIFO,i);
		printf("I2C_LIFO_PUSH: %d\n",i);
	}

	printf("\n\n ====== Pop from the Stack (Static) ====== \n\n");
	for(i=0;i<5;i++)
	{
		LIFO_POP(&UART_LIFO,&temp);
		printf("UART_LIFO_POP: %d \n",*temp);
	}

	printf("\n\n ====== Pop from the Stack (Dynamic)====== \n\n");
	for(i=0;i<5;i++)
	{
		LIFO_POP(&I2C_LIFO,&temp);
		printf("I2C_LIFO_POP: %d \n",*temp);
	}


}
