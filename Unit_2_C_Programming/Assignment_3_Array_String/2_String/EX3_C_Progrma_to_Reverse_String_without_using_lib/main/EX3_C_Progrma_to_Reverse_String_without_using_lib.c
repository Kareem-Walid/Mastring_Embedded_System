/*
 ============================================================================
 Name        : EX3_C_Progrma_to_Reverse_String_without_using_lib.c
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
	char str[100];
	char temp;
	char i=0,l;

	// take  a string
	printf("Enter a String: ");
	scanf("%[^\n]%*c", str);

	l = strlen(str) -1 ;

	// Reverse the entered string
	for(i=0;i<l;i++,l--)
	{
		temp = str[i];
		str[i] = str[l];
		str[l]= temp;
	}

	// display the length

	printf("Reversed String is: %s",str);

}
