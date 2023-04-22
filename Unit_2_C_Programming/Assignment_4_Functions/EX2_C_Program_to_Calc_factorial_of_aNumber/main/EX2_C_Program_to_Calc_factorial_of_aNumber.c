/*
 ============================================================================
 Name        : EX2_C_Program_to_Calc_factorial_of_aNumber.c
 Author      : Kareem Walid
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

long long _Factorial(int Num)
{
	long long result;
	if(Num == 1)
		result = 1;
	else
		result = Num * _Factorial(Num-1);

	return result;
}
int main(void) {

	int num;
	long long fact;
	printf("Enter an a Positive Integer: ");
	scanf("%d",&num);

	fact= _Factorial(num);
	printf("Factorial of %d : %d",num,fact);


}
