/*
 ============================================================================
 Name        : EX2_C_program_to_find_the_length_of_a_string.c
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
	char str[1024];
	char i=0;

	// take  a string
	printf("Enter a String: ");
	scanf("%[^\n]%*c", str);

	// Calculate the length of string
	while(str[i]!= '\0')
	{
		i++;
	}
	// display the length

	printf("Length of String: %d",i);
}
