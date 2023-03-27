/*
 ============================================================================
 Name        : Ex4_C_Programming_to_check_whether_a_num_is_pos_or_neg.c
 Author      : Kareem Walid
 Version     :
 Date        :  26/3/2023
 Description : This program takes a number from user and checks whether that
               number is either positive or negative or zero

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float number;
	printf("Enter a Number: \n");
	scanf("%f",&number);

	if(number == 0)
	{
		printf("You Entered Zero");
	}
	else if(number > 0)
	{
		printf("%f is Positive",number);
	}else
	{
		printf("%f is Negative",number);
	}
}
