/*
 ============================================================================
 Name        : EX3_C_Program_to_Reverse_aSentence.c
 Author      : Kareem Walid
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>


void Rverse_String(char *ptr)
{
    if(*ptr != '\0')
    {
    Rverse_String(ptr+1);
    printf("%c",*ptr);
    }

}



int main() {

    char string[100];
   printf("Enter a Sentence:");
   scanf("%[^\n]%*c",string);

   Rverse_String(string);
}
