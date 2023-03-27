/*
 ============================================================================
 Name        : Ex6_C_Programming_to_calc_sum_of_natural_nums.c
 Author      : Kareem Walid
 Version     : 1
 Date        : 27/3/2023
 Description : Positive integers 1, 2, 3, 4... are known as natural numbers.
               This program takes a positive integer from user
               (suppose user entered n) then, this program displays
               the value of 1+2+3+......
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num,i =1,sum = 0;
	printf("Enter an Integer:\n");
	scanf("%d",&num);
	// solution 1
	/* for(i = 1; i <= num ; i++ )
	      {
	          sum += i;
	      }*/
	// solution 2
	/* do{
	         sum += i;
	         i++;
	      }while(i <= num); */

	// solution 3
	while(i <= num)
	{
		sum += i;
		i++;
	}
	printf("Sum = %d",sum);

	return 0;
}
