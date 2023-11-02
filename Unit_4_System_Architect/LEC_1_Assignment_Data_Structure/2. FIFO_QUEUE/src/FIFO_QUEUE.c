/*
 ============================================================================
 Name        : FIFO_QUEUE.c
 Author      : Kareem Walid
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "FIFO.h"

int main(void){

	FIFO_QUEUE_t FIFO_UART;
	int i , temp;

	/* Static Allocation */
	if(FIFO_Init(&FIFO_UART,Queue,5) == FIFO_NO_ERROR )
	{
		printf("FIFO Initialization Done\n\n");
	}

	for(i=0; i<5; i++)
	{
		printf("FIFO Enqueue %x \n",i);
		if(FIFO_EnQueue(&FIFO_UART,i) == FIFO_NO_ERROR)
			printf("FIFO enqueue Done \n");
		else
			printf("FIFO enqueue failed \n");

	}

	FIFO_Print(&FIFO_UART);



}


