/*
 ============================================================================
 Name        : c.c
 Author      : Kareem Walid
 Version     :
 Copyright   : Ass1-Ex2-C_Program_To_Print_a_Integer_Entered_by_a_User.png
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
     	int numa,numb;
		printf("Enter value of a: ");
		scanf("%d",&numa);
		printf("Enter value of b: ");
		scanf("%d",&numb);

        numa = numa + numb;
        numb = numa - numb;
        numa = numa - numb;

		printf("\nafter swapping, value of a = %d\n",numa);
		printf("after swapping, value of a = %d\n",numb);

		return EXIT_SUCCESS;
}
