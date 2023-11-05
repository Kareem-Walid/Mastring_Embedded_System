
#include "US.h"

uint32 US_Distance = 0;

extern void (*US_State)();



void US_Init(void)
{
	printf("\nUS Initialization  Done");
}


STATE_Define(US_Busy)
{
	/* State Name */
	US_State_Id = US_Busy;

	/* State Action */
	US_Distance = Randome_Distance(45,55,1);
	printf("\nUS Busy State -- Distance = %d",US_Distance);
	US_Set_Distance(US_Distance);
	US_State = STATE(US_Busy);
}

int Randome_Distance(uint32 lower, uint32 upper, uint32 Count)
{
	int i;
	for(i=0;i<Count;i++)
	{
		int num = (rand() % (upper - lower +1 )+ lower);
		return num;
	}

}
