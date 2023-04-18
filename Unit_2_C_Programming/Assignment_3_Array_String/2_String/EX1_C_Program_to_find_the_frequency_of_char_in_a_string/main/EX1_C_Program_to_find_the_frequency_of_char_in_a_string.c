/*
 ============================================================================
 Name        : EX1_C_Program_to_find_the_frequency_of_char_in_a_string.c
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
	char i=0,counter=0;
	char ch;

	// take  a string and a char form user
	printf("Enter a String: ");
	scanf("%[^\n]%*c", str);
	printf("Enter a char: ");
	scanf("%c",&ch);
	// Calculate the frequency of the char
	while(str[i]!= '\0')
	{
		if(str[i]== ch)
		{
			counter++;
		}
		i++;
	}
	// display the frequency

	printf("Frequency of %c : %d",ch,counter);
}
}
