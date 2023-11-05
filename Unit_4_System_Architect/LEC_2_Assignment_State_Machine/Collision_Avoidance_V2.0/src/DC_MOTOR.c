

#include "DC_Motor.h"

uint32 DC_Speed = 0;
void (*DC_State)();



void DC_Init(void)
{
	printf("\nDC Initialization Done ");
}

STATE_Define(DC_Idle)
{
	/*State Name */
	DC_State_Id = DC_Idle;

	printf("\nDC_Idle State --- Speed = %d",DC_Speed);

}


STATE_Define(DC_Busy)
{
	/*State Name */
	DC_State_Id = DC_Busy;
	printf("\nDC_Busy State --- Speed = %d",DC_Speed);
	DC_State = STATE(DC_Idle);

}

void DC_Motor_Speed(int Speed)
{
	DC_Speed = Speed;
	DC_State = STATE(DC_Busy);
	printf("\nCA ------ Speed = %d --------> DC",DC_Speed);

}
