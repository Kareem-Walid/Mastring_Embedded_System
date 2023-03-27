 /*
  =======================================
  Name: Ex4_C_Program_to_Multiply_two_Floating_Point_Numbers
  Author : Kareem Walid
  Date: 26/3/2022
  Description : Write C Program to Multiply two Floating Point Numbers

  =======================================
  */
#include <stdio.h>

int main(void)
{
	float num1,num2,sum;
	printf("Enter two numbers: ");
	scanf("%f%f",&num1,&num2);
	sum = num1 * num2;
	printf("%f",sum);

}

