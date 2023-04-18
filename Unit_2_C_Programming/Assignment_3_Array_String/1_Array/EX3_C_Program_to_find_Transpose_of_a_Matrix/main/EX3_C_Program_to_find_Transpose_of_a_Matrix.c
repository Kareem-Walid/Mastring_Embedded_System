/*
 ============================================================================
 Name        : EX3_C_Program_to_find_Transpose_of_a_Matrix.c
 Author      : Kareem Walid
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// Declaration and Initializaion
	float Arr[10][10];
	float Arr_Transpose[10][10];
	int raw , column;
	int i,j;

	// Scan the raws and columns from user
	printf("Enter The Raw and Columns of the Array: ");
	scanf("%d %d",&raw,&column);

	// take the elements of the array
	printf("Enter The Elements of the Matrix: \n");

	for(i=0;i<=(raw-1);i++)
	{
		for(j=0;j<=(column -1);j++)
		{
			printf("Enter The Element[%d][%d]: ",i+1,j+1);
			scanf("%f",&Arr[i][j]);
		}
	}
	// transpose the elemnts
	for(i=0;i<=(column -1);i++)
	{
		for(j=0;j<=(raw -1);j++)
		{
			Arr_Transpose[i][j] = Arr[j][i];
		}
	}

	// print the enterd matrix
	printf("\n\nThe Entered Matrix:\n");
	for(i=0;i<=(raw-1);i++)
	{
		for(j=0;j<=(column -1);j++)
		{
			printf("%.2f\t",Arr[i][j]);
		}
		printf("\n");
	}

	// print the transposed matrix
	printf("\n\nTranspose of Matrix:\n");
	for(i=0;i<=(column -1);i++)
	{
		for(j=0;j<=(raw -1);j++)
		{
			printf("%.2f\t",Arr_Transpose[i][j]);
		}
		printf("\n");
	}


}
