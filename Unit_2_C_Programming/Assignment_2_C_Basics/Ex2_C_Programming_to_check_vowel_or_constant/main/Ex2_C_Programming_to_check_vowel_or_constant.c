/*
 ============================================================================
 Name        : Ex2_C_Programming_to_check_vowel_or_constant.c
 Author      : Kareem Walid
 Version     :
 Date        : 26/3/2023
 Description : Alphabets a, e, i, o and u are known as vowels and 
               all alphabets except these characters are known as consonants. 
			   This program asks user to enter a character and checks whether 
			   that character is vowel or not. 

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char chara;
	printf("Enter an alphabet: \n");
	scanf("%c",&chara);
	if( chara == 'A' || chara == 'a' ||
		chara == 'E' || chara == 'e' ||
		chara == 'I' || chara == 'i' ||
		chara == 'O' || chara == 'o' ||
		chara == 'U' || chara == 'u' )

	{
		printf("%c is Vowel",chara);
	}else{
		printf("%c is Constant",chara);
	}
}
