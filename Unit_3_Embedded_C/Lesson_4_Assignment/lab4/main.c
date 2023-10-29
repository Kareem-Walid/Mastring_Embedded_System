/**********************************************************************************************************************
 *  FILE INFORMATION
 *  -----------------------------------------------------------------------------------------------------------------
 *        FILE NAME :  main.c
 *        FILE DATE :  28/10/2023
 *        VERSION:   V1.0
 *        AUTHOR:   KAREEM WALID
 *        BRIEF EXPLANATION: make a simple project on Tiva-C TM4C123GXL
          in this project we will toggle 3 led in the kit (green,yellow and red ) with delay
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "PlatForm_Types.h"


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#define  SYSCTL_RCGC2_R       (*((vuint32*)0x400FE108))
#define  GPIO_PORTF_DIR_R     (*((vuint32*)0x40025400))
#define  GPIO_PORTF_DEN_R     (*((vuint32*)0x4002551C))
#define  GPIO_PORTF_DATA_R    (*((vuint32*)0x400253FC))



int main(void)
{
	vuint32 delay_counter;
	SYSCTL_RCGC2_R = 0x20;
	/* Wait */
	for(delay_counter=0;delay_counter<5000;delay_counter++);
	
	GPIO_PORTF_DIR_R |= 1<<3;/* direction of pin3 in portf*/
	GPIO_PORTF_DEN_R |= 1<<3;
	
	while(1)
	{
		GPIO_PORTF_DATA_R |= 1<<3;
		for(delay_counter=0;delay_counter<200000;delay_counter++);
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for(delay_counter=0;delay_counter<200000;delay_counter++);

		
	}
	return 0;
}