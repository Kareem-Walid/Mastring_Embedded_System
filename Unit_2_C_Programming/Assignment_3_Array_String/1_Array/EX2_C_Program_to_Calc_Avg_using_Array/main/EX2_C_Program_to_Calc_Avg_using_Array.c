/*
 ============================================================================
 Name        : EX2_C_Program_to_Calc_Avg_using_Array.c
 Author      : Kareem Walid
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// Declaration and Initialization
	int n ,i;
	float Arr[1024];
	float sum=0,Avg;

	// scan number of data from user
	printf("Enter The Number Of data: ");
	scanf("%d",&n);

	// scan data from user and calculate sum
	for(i=0;i<=(n-1);i++)
	{
		printf("\nEnter Data Number %d:",i+1);
		scanf("%f",&Arr[i]);
		sum = sum + Arr[i];
	}


	// get the avg of the data
	Avg = sum / n;

	// printf the Avg
	printf("\n\nThe Avg is: %.2f",Avg);

}
