/*
 ============================================================================
 Name        : EX4_C_program_to_print_the_elelments_of_an_array_in_reverse_order.c
 Author      : Kareem Walid
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {


	int ARR[15];
	int *P = ARR;
	char elements , i;
	printf("Input the Numbers if elements of array (max 15)\n");
	scanf("%d",&elements);

	for(i=0;i<elements;i++)
	{
		printf("Element[%d]:",i+1);
		scanf("%d",P++);
		printf("\n");
	}

	printf("The Elements of Array in Reverse order are:\n");
	for(i=elements-1;i>=0;i--)
	{
		printf("Element[%d]: %d\n",i+1,*--P);
	}
}

