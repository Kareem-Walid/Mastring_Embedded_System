/*
 ============================================================================
 Name        : EX4_C_Program_to_Insert_an_element_in_an_array.c
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

	// Decleration and  Initialization
	float Arr[100][100];
	int raw , column;
	float element;
	int r,c;
	int i,j;

	// Scan the raw and columns from user
	printf("Enter The Raw and Columns of the Array: ");
	scanf("%d %d",&raw,&column);

	// scan the elements from user
	printf("Enter The Elements of the Matrix: \n");
	for(i=0;i<=(raw-1);i++)
	{
		for(j=0;j<=(column -1);j++)
		{
			printf("Enter The Element[%d][%d]:",i+1,j+1);
			scanf("%f",&Arr[i][j]);
		}
	}

	// print Entered Matrix
	printf("\n\nThe Entered Matrix:\n");
	for(i=0;i<=(raw-1);i++)
	{
		for(j=0;j<=(column -1);j++)
		{
			printf("%.2f\t",Arr[i][j]);
		}
		printf("\n");
	}
	// take the element and location
	printf("Enter the Element to be Insert: ");
	scanf("%f",&element);
	printf("Enter the Location of the Element R&C: ");
	scanf("%d %d",&r,&c);

	Arr[r-1][c-1] = element;

	printf("\n\nThe Matrix:\n");
	for(i=0;i<=(raw-1);i++)
	{
		for(j=0;j<=(column -1);j++)
		{
			printf("%.2f\t",Arr[i][j]);
		}
		printf("\n");
	}


}
