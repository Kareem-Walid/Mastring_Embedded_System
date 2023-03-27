/*
 ============================================================================
 Name        : Ex7_C_Programming_to_Find_Factorial_of_a_Number.c
 Author      : Kareem Walid
 Version     :
 Date        : 27/3/2023
 Description : For any positive number n, its factorial is given by:
               factorial 1*2*3*4....n
               If a number is negative, factorial does not exist and
               factorial of 0 is 1.
               This program takes an integer from a user.
               If user enters negative integer, this program will display
               error message and if user enters non-negative integer,
               this program will display the factorial of that number.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int num , i , fact =1 ;
	printf("Enter an Number:");
	scanf("%d",&num);

	if(num < 0)
	{
		printf("Error !!! Factorial of Negative number does not exist");
	}else if( num == 0)
	{
		printf("Factorial = 1 ");
	}else{

		for(i=1; i<=num;i++)
		{
			fact *= i;
		}
		printf("Factorial = %d",fact);

	}

}
