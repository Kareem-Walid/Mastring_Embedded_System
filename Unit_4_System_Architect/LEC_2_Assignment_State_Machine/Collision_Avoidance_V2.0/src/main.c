



#include "State.h"
#include "Collision_Avoidance.h"
#include "US.h"
#include "DC_Motor.h"



void setup()
{

	/*Initialize All Drivers*/
	DC_Init();
	US_Init();
	CA_State = STATE(CA_Waiting);
	US_State = STATE(US_Busy);
	DC_State = STATE(DC_Idle);

}

int main(void)
{
	volatile uint64 i;
    setup();

	while(1)
	{

		US_State();
		CA_State();
		DC_State();
		for(i=0;i<900000;i++);


	}
}
