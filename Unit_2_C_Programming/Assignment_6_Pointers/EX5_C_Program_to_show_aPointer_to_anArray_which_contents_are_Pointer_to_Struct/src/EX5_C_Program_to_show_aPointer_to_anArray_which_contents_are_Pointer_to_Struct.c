/*
 ============================================================================
 Name        : EX5_C_Program_to_show_aPointer_to_anArray_which_contents_are_Pointer_to_Struct.c
 Author      : Kareem Walid
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


struct SEmp{

	char name[20];
	int ID;
};

int main(void){

	char i;
	struct SEmp Emp1= {"Kareem",1002};
	struct SEmp Emp2= {"Walid",1005};
	struct SEmp Emp3= {"Mabrouk",1008};
	struct SEmp Emp4= {"Mohamed",1010};

	struct SEmp (* ARR[4]) = {&Emp1,&Emp2,&Emp3,&Emp4};
	struct SEmp * (*PTR)[4]= &ARR;

	printf("OUTPUT\n");
	printf("----------------------\n");
	for(i=0;i<4;i++)
	{
		printf("Employee %d Name: %s\n",i+1,(**(*PTR+i)).name);
		printf("Employee %d ID: %d\n",i+1,(**(*PTR+i)).ID);
	}


}
