/*
 ============================================================================
 Name        : EX3_C_Program_To_add_two_nums.c
 Author      : Kareem Walid
 Version     :
 Date        : 26/3/2023
 Description : Write C Program to Add Two Integers
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num1, num2 , sum;
    printf("Enter Two Numbers: ");
    scanf("%d  %d", &num1, &num2);
    sum = num1 + num2;
    printf("sum: %d",sum);
}
