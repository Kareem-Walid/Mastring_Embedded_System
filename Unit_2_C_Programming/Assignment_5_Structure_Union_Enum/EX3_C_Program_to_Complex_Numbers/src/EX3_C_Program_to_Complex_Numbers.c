/*
 ============================================================================
 Name        : EX3_C_Program_to_Complex_Numbers.c
 Author      : Kareem Walid
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


struct Complex{
    double Real;
    double Img;
}Num1,Num2;

struct Complex Sum(struct Complex Num1 , struct Complex Num2);
int main(void)
{
    struct Complex result;
    printf("Enter 1s Complex Number:\n");
    printf("Enter Real and Img Numbers Respectively:\n");
    scanf("%lf %lf",&Num1.Real, &Num1.Img);

    printf("\nEnter Real and Img Numbers Respectively:\n");
    scanf("%lf %lf",&Num2.Real, &Num2.Img);

  result = Sum(Num1,Num2);
  printf("\nSum=%0.2lf + %0.2lfi",result.Real,result.Img);

}

struct Complex Sum(struct Complex Num1 , struct Complex Num2)
{
  struct  Complex sum;
    sum.Real = Num1.Real + Num2.Real;
    sum.Img = Num1.Img + Num2.Img;
   return sum;
}

