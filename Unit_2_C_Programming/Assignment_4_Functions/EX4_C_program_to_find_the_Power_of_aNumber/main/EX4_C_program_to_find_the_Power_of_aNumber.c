/*
 ============================================================================
 Name        : EX4_C_program_to_find_the_Power_of_aNumber.c
 Author      : Kareem Walid
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

long long _Power(int Base,int Exponent)
{
    long long result;
    if(Exponent == 1)
    result = Base;
    else
    result =  Base * _Power(Base,Exponent-1);

    return result;

}

int main()
{
    int B,E,result;
printf("Enter Base Number:");
scanf("%d",&B);

printf("Enter Exponent Number:");
scanf("%d",&E);

result = _Power(B,E);
printf("%d ^ %d = %d",B,E,result);




}
