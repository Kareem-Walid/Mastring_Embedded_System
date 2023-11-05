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

uint32 CA_Threshold = 50 ;

extern uint32 US_Distance;
extern uint32 DC_Speed;

/* Pointer to function */
void (*CA_State)();





void US_Set_Distance(int Distance)
{

	US_Distance = Distance;
	(US_Distance <= CA_Threshold) ? (CA_State = STATE(CA_Waiting)): (CA_State = STATE(CA_Driving));
    printf("\nUS --------- Distance = %d -------> CA ",US_Distance);
}




STATE_Define(CA_Waiting)
{
	/* State Name */
	CA_State_Id = CA_Waiting;
	printf("\nCA_Waiting State: Distance =%d ** Speed = %d",US_Distance,DC_Speed);

	/* State Action */
	 DC_Speed = 0;
	 DC_Motor_Speed(DC_Speed);

}


STATE_Define(CA_Driving)
{
	/* State Name */
	CA_State_Id = CA_Driving;
	printf("\nCA_Driving State: Distance =%d  Speed = %d",US_Distance,DC_Speed);

	/* State Action */
	 DC_Speed = 25;
	 DC_Motor_Speed(DC_Speed);
}



