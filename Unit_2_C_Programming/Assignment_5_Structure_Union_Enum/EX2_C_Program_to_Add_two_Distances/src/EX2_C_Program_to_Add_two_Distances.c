/*
 ============================================================================
 Name        : EX2_C_Program_to_Add_two_Distances.c
 Author      : Kareem Walid
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


struct Dis{
	double foot;
	double Inch;
}Info1,Info2;

int main() {

	printf("Enter info for 1st distance\n");
	printf("Enter Foot:\n");
	scanf("%lf",&Info1.foot);
	printf("Enter inch:\n");
	scanf("%lf",&Info1.Inch);

	printf("Enter info for 2nd distance\n");
	printf("Enter Foot:\n");
	scanf("%lf",&Info2.foot);
	printf("Enter inch:\n");
	scanf("%lf",&Info2.Inch);

	Info1.foot += Info2.foot;
	Info1.Inch += Info2.Inch;

	if(Info1.Inch>=12)
	{
		Info1.foot ++;
		Info1.Inch -= 12;
	}

	printf("Sum of Destance: %0.2lf \"%0.2lf \" ",Info1.foot,Info1.Inch);

}
