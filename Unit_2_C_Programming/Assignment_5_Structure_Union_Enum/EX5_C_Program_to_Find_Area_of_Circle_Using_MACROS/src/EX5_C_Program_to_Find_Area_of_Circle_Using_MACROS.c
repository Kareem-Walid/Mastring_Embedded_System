/*
 ============================================================================
 Name        : EX5_C_Program_to_Find_Area_of_Circle_Using_MACROS.c
 Author      : Kareem Walid
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


#define  PI       3.14
#define  Area(r)    PI * r * r
int main() {

	double r;
	printf("Enter the radius:");
	scanf("%lf",&r);
	printf("Area=%0.2lf",Area(r));
}
