/*
 ============================================================================
 Name        : EX1_C_Program_to_Store_Information.c
 Author      : Kareem Walid
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


struct Student{
	unsigned char Name[20];
	unsigned int  Roll;
	double  Marks;

};

int main(void)
{
	struct Student S;
	printf("Enter Your Name:");
	scanf("%[^\n]%*c",&S.Name);

	printf("Enter Roll Number:");
	scanf("%d",&S.Roll);

	printf("Enter Marks:");
	scanf("%lf",&S.Marks);

	printf("\n\nDisplaying Information \n");
	printf("Name: %s",S.Name);
	printf("\nRoll: %d",S.Roll);
	printf("\nMarks:%0.2lf ",S.Marks);
}
