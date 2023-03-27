/*
 ============================================================================
 Name        : Ex1_C_Programming_to_check_whether_a_num_is_even_or_odd.c
 Author      : Kareem Walid
 Version     :
 Date        :  26/3/2023
 Description : Numbers perfectly divisible by 2 are known even numbers 
               and numbers which are not divisible by 2 are called odd numbers.
			   This program takes an integer from user and checks whether that
			   number is even or odd and displays the result. 
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
