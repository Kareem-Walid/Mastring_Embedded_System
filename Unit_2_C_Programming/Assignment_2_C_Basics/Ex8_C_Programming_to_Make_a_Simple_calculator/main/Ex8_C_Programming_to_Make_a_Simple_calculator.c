/*
 ============================================================================
 Name        : Ex8_C_Programming_to_Make_a_Simple_calculator.c
 Author      : Kareem Walid
 Version     :
 Date        : 26/3/2023
 Description : This program takes an arithmetic operator (+, -, *, /) and
               two operands from an user and performs the operation on those
               two operands depending upon the operator entered by user.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float num1 ,num2 , result , flag = 1;
	char op;
	printf("Enter two Numbers:\n");
	scanf("%f %f",&num1,&num2);
	fflush(stdin); fflush(stdout);
	printf("Enter an Operands (+,-,*,/,%):\n");
	scanf("%c",&op);
	switch(op)
	{
	case '+':
		result = num1 + num2;
		break;

	case '-':
		result = num1 - num2;
		break;

	case '*':
		result = num1 * num2;
		break;

	case '/':
		if(num2 != 0 )
		{
			result = num1 / num2;
		}
		break;

	case '%':
		result = (int)num1 % (int)num2 ;
		break;

	default: printf("wrong choice\n"); flag = 0; }

	if (flag == 1)
	{
		printf("%f %c %f = %f",num1,op,num2,result);
	}
}
