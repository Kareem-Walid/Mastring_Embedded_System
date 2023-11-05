




#include "Collision_Avoidance.h"


void setup()
{

	/*Initialize All Drivers*/

	CA_State = STATE(CA_Waiting);
}

int main(void)
{
	volatile uint32 i;
    setup();

	while(1)
	{

		CA_State();
		for(i=0;i<300000;i++);


	}
}
