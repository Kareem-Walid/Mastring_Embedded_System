/*
 ============================================================================
 Name        : Ex6_Write.c
 Author      : Kareem Walid
 Version     :
 Date        : 26/3/2023
 Description : Write Source Code to Swap Two Numbers

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
