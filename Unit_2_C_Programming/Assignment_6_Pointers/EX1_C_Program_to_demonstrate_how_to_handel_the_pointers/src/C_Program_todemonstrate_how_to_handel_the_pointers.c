/*
 ============================================================================
 Name        : EX1_C_Program_todemonstrate_how_to_handel_the_pointers.c
 Author      : Kareem Walid
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int m = 29;

	printf("Address of m: 0x%x \n",&m);
	printf("Value of m: %d \n\n",m);

	int *ab = &m;
	printf("Now ab is assigned with the address of m \n");
	printf("Address of pointer ab : 0x%x\n ",ab);
	printf("Content of pointer ab: %d \n\n",*ab);

	m = 34;
	printf("The value of m assigned to 34 now \n");
	printf("Address of pointer ab :0x%x \n",ab);
	printf("Content of pointer ab: %d \n\n",*ab);

	*ab = 7;
	printf("The pointer variable ab is assigned with the value 7 now \n");
	printf("Address of m : 0x%x \n",&m);
	printf("value of m : %d \n",m);


}
