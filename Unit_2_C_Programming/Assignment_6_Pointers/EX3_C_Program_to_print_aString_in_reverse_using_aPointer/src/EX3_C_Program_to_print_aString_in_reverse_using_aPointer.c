/*
 ============================================================================
 Name        : EX3_C_Program_to_print_aString_in_reverse_using_aPointer.c
 Author      : Kareem Walid
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
int main() {

	char Arr[30];
	char Arr_rev[30];
	char *ptr= Arr;
	char n,i;

	printf("Print a string in reverse order:\n");
	printf(" ------------------------------ \n");
	printf("Input a string: \n");
	scanf("%s",Arr);
	n = strlen(Arr);
	ptr = ptr + n -1 ;

	for(i=0;i<n;i++)
	{
		Arr_rev[i] = *ptr;
		ptr--;
	}

	printf("Reverse of the string is :\n");
	printf("%s",Arr_rev);
}
