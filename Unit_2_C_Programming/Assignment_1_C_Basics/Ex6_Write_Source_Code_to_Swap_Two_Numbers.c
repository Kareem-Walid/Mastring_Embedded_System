/*
 ============================================================================
 Name        : Ex6_Write.c
 Author      : Kareem Walid
 Version     :
 Copyright   : Ass1-Ex2-C_Program_To_Print_a_Integer_Entered_by_a_User.png
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float numa,numb,temp;
	printf("Enter value of a: ");
	scanf("%f",&numa);
	printf("Enter value of b: ");
	scanf("%f",&numb);
	temp = numa;
	numa = numb;
	numb = temp;
	printf("\nafter swapping, value of a = %f\n",numa);
	printf("after swapping, value of a = %f\n",numb);

	return EXIT_SUCCESS;
}
