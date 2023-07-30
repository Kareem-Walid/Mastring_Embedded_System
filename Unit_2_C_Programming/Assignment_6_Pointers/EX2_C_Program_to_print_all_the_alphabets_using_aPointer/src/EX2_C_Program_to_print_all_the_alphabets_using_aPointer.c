/*
 ============================================================================
 Name        : EX2_C_Program_to_print_all_the_alphabets_using_aPointer.c
 Author      : Kareem Walid
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char letters[27];
	char *Ptr;
	Ptr = letters;
	char i;

	for(i=0;i<26;i++)
	{
		*Ptr = 'A' + i;
		Ptr++;
	}

	Ptr = letters;

	printf("The Alphabets are:\n");

	for(i=0;i<26;i++)
	{
		printf("%c\n",*Ptr);
		Ptr++;
	}


}
