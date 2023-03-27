/*
 ============================================================================
 Name        : Ex5_C_Program_to_Find_ASCII_Value_of_a_Character.c
 Author      : Kareem Walid
 Version     :
 Date        : 26/3/2023
 Description : Write C Program to Find ASCII Value of a Character
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char cha;
	printf("Enter a character: ");
	scanf("%c",&cha);
	printf("ASCII value of %c = %d",cha,cha);
	return EXIT_SUCCESS;
}
