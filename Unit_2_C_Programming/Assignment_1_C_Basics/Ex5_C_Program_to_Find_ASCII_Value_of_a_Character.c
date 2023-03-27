/*
 ============================================================================
 Name        : Ex5_C_Program_to_Find_ASCII_Value_of_a_Character.c
 Author      : Kareem Walid
 Version     :
 Copyright   : Ass1-Ex2-C_Program_To_Print_a_Integer_Entered_by_a_User.png
 Description : Hello World in C, Ansi-style
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
