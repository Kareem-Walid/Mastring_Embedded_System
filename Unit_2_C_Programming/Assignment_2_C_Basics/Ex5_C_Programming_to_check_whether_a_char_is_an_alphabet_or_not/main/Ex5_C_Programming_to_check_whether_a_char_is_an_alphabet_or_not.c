/*
 ============================================================================
 Name        : Ex5_C_Programming_to_check_whether_a_char_is_an_alphabet_or_not.c
 Author      : Kareem Walid
 Version     :
 Date        : 26/3/2023
 Description : This program takes a character from user and 
               checks whether that character is an alphabet or not. 
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char  character;
	printf("Enter a Character:\n");
	scanf("%c",&character);
	// solution 1
	/*if((character >= 'A' && character <= 'Z' ) || (character >= 'a' && character <= 'z' ))
	   {
	       printf("%c is an alphabet",character);
	   }else{
	       printf("%c is not an alphabet",character);
	   }*/
	// solution 2
	switch(character)
	{
	case 'A' ... 'Z' :
	case 'a' ... 'z':
	printf("%c is an alphabet",character);
	break;
	default:
		printf("%c is not an alphabet",character);
	}
	return 0;
}
