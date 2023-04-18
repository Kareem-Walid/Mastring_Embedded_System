/*
 ============================================================================
 Name        : EX1_Example_on_MultiDimentsional_Array.c
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
	int i,j;
	float Array_A[2][2];
	float Array_B[2][2];
	float Array_Sum[2][2];

	// scant 1st Array from User
	printf("Enter the Elements of the 1st Array: ");
	for(i=0;i<=1;i++)
	{
		for(j=0;j<=1;j++)
		{
			printf("\nEnter Element of Array  A [%d][%d]:",i+1,j+1);
			scanf("%f",&Array_A[i][j]);
		}
	}

	// Scan 2n Array from User
	printf("\n\nEnter the Elements of the 2nd Array:");
	for(i=0;i<=1;i++)
	{
		for(j=0;j<=1;j++)
		{
			printf("\nEnter Element of Array  B [%d][%d]:",i+1,j+1);
			scanf("%f",&Array_B[i][j]);
		}
	}



	// Calculate the sum of tow Matrices and store in new matrix
	for(i=0;i<=1;i++)
	{
		for(j=0;j<=1;j++)
		{
			Array_Sum[i][j] = Array_A[i][j] + Array_B[i][j];
		}
	}


    // print The output Matrix
	printf("\n\nThe sum of Matrices:\n");
	printf("%.2f\t%.2f\n",Array_Sum[0][0],Array_Sum[0][1]);
	printf("%.2f\t%.2f\n",Array_Sum[1][0],Array_Sum[1][1]);



}
