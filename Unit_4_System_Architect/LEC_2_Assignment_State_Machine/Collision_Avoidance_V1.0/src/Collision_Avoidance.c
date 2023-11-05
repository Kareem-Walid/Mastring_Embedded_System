/**********************************************************************************************************************
 *  FILE INFORMATION
 *  -----------------------------------------------------------------------------------------------------------------
 *        FILE NAME :  USART_Program.c
 *        FILE DATE :
 *        VERSION:   V1.0
 *        AUTHOR:   KAREEM WALID
 *        BRIEF EXPLANATION:
 *
 *********************************************************************************************************************/
#include "Collision_Avoidance.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
uint32 CA_Speed = 0;
uint32 CA_Distance = 0;
uint32 CA_Threshold = 50 ;


/* Pointer to function */
void (*CA_State)();




STATE_Define(CA_Waiting)
{
	/* State Name */
	CA_State_Id = CA_Waiting;

	/* State Action */
	CA_Speed = 0;
	/* DC_Motor_Speed(CA_Speed);*/
	/* Event Check */
	CA_Distance = US_Get_Distance(45,55,1);
	(CA_Distance <= CA_Threshold) ? (CA_State = STATE(CA_Waiting)): (CA_State = STATE(CA_Driving));
	printf("CA_Waiting State: Distance =%d  Speed = %d \n",CA_Distance,CA_Speed);
}


STATE_Define(CA_Driving)
{
	/* State Name */
	CA_State_Id = CA_Driving;

	/* State Action */
	 CA_Speed = 25;
	/* DC_Motor_Speed(CA_Speed);*/
	/* Event Check */
	CA_Distance = US_Get_Distance(45,55,1);
	(CA_Distance <= CA_Threshold) ? (CA_State = STATE(CA_Waiting)): (CA_State = STATE(CA_Driving));
	printf("CA_Driving State: Distance =%d  Speed = %d \n",CA_Distance,CA_Speed);
}


int US_Get_Distance(uint32 lower, uint32 upper, uint32 Count)
{
	int i;
	for(i=0;i<Count;i++)
	{
		int num = (rand() % (upper - lower +1 )+ lower);
		return num;
	}
}
