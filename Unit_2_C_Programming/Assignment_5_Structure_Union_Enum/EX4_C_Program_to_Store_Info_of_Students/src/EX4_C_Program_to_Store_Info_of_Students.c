/*
 ============================================================================
 Name        : EX4_C_Program_to_Store_Info_of_Students.c
 Author      : Kareem Walid
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

struct Student{
    unsigned char Name[20];
    unsigned char Roll;
        double Marks;
};


int main()
{
    struct Student  S_Array[10];
    char i=0;

    printf("Enter Info of Students:\n\n");

    for(i=0;i<=9;i++)
    {
    S_Array[i].Roll = i + 1;
    printf("For Roll Num %d\n",S_Array[i].Roll);
    printf("Enter Name:");
    scanf("%s",S_Array[i].Name);
    printf("Enter Marks: ");
    scanf("%lf",&S_Array[i].Marks);
    printf("\n");
    }

    printf("Displaying Info of Students:\n\n");

    for(i=0;i<=9;i++)
    {
    S_Array[i].Roll = i + 1;
    printf("For Roll Num %d\n",S_Array[i].Roll);
    printf("Name: %s",S_Array[i].Name);
    printf("Marks: %lf",S_Array[i].Marks);
    printf("\n");
    }



}

