/*
 ============================================================================
 Name        : Ex1_C_Programming_to_check_whether_a_num_is_even_or_odd.c
 Author      : Kareem Walid
 Version     :
 Copyright   : Ass1-Ex2-C_Program_To_Print_a_Integer_Entered_by_a_User.png
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int number;
	printf("Enter an integer you want to check:");
	scanf("%d",&number);

	if((number % 2) == 0)
	{
		printf("%d is Even",number);
	}else
	{
		printf("\n%d is Odd",number);
	}

}
