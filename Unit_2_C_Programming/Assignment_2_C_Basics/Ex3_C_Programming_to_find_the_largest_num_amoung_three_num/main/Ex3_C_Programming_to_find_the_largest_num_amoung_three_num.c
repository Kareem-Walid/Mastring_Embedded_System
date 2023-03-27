/*
 ============================================================================
 Name        : Ex3_C_Programming_to_find_the_largest_num_amoung_three_num.c
 Author      : Kareem Walid
 Version     :
 Date        : 26/3/2023
 Description : In this program user is asked to enter three numbers and 
               this program will find the largest number among three numbers 
			   entered by user. This program can be solved in more than one way. 
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	  float num1,num2,num3,largest;
	  printf("Enter three numbers:\n");
	  scanf("%f %f %f",&num1,&num2,&num3);
	  largest = num1;
	  if(num2>largest)
	  {
	      largest = num2;
	  }
	  if(num3>largest)
	  {
	      largest = num3;
	  }
	  printf("The largest Number is: %f",largest);

	}

