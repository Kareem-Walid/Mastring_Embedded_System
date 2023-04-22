/*
 ============================================================================
 Name        : EX1_Prime_Numbers_Between_tow_Intervals.c
 Author      : Kareem Walid
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void Prime_Numbers(int Num1,int Num2)
{

	int i,INT,flag=0;
	printf("Prime Numbers between %d and %d: ",Num1,Num2);
	for(INT= Num1+1;INT<Num2;INT++)
	{
		for(i=2;i<INT;i++)
		{  flag =0;
		if(INT % i == 0 )
		{
			flag = 1;
			break;
		}
		}

		if(flag == 0)
		{
			printf("%d ",INT);
		}

	}

}




int main(void)
{
	int n1,n2;
	printf("Enter Tow Numbers (Intervals): ");
	scanf("%d %d",&n1,&n2);

	Prime_Numbers(n1,n2);


}
