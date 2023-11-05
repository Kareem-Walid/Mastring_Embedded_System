#ifndef US_H_
#define US_H_

#include "Platform_Types.h"
#include "State.h"


enum {
	US_Busy
}US_State_Id;

void (*US_State)();

void US_Init(void);
STATE_Define(US_Busy);
int Randome_Distance(uint32 lower, uint32 upper, uint32 Count);


#endif /* US_H_ */
