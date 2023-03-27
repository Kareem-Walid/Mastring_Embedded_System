/*
 ============================================================================
 Name        : c.c
 Author      : Kareem Walid
 Version     :
 Date        : 26/3/2023
 Description : Write Source_Code_to_Swap_Two_Numbers_Without_Temp_Variable
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
