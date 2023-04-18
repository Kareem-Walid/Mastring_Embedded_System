/*
 ============================================================================
 Name        : EX5_C_Program_to_search_an_element_in_array.c
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
	// Declaration and Initialization
	float Arr[100][100];
	int raw , column,flag=0;
	float element;
	int i,j;

	// scan the raw and Columns from User
	printf("Enter The Raw and Columns of the Array: ");
	scanf("%d %d",&raw,&column);

	// Scan the elements of the array
	printf("Enter The Elements of the Matrix: \n");
	for(i=0;i<=(raw-1);i++)
	{
		for(j=0;j<=(column-1);j++)
		{
			printf("Enter The Element[%d][%d]: ",i+1,j+1);
			scanf("%f",&Arr[i][j]);
		}
	}

	// display the entered matrix
	printf("\n\nThe Entered Matrix:\n");
	for(i=0;i<=(raw-1);i++)
	{
		for(j=0;j<=(column -1);j++)
		{
			printf("%.2f\t",Arr[i][j]);
		}
		printf("\n");
	}
	// Scan the Element to be search
	printf("Enter the Element to be Searched: ");
	scanf("%f",&element);

	// search on the Element
	for(i=0;i<=(raw-1);i++)
	{
		for(j=0;j<=(column -1);j++)
		{
			if(Arr[i][j] == element)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 1) break;
	}

	if(flag==1)
	{
		printf("Number found at the Location [%d][%d]",i+1,j+1);
	}else
	{
		printf("ELement Not Found");
	}

}
