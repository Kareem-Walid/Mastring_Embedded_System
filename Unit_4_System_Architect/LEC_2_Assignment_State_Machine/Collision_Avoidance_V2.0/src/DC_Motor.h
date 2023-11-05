/*
 * DC_Motor.h
 *
 *  Created on: Nov 2, 2023
 *      Author: Kareem Walid
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "Platform_Types.h"
#include "State.h"

enum {
	DC_Idle,
	DC_Busy
}DC_State_Id;


STATE_Define(DC_Idle);
STATE_Define(DC_Busy);

void DC_Init(void);
extern void (*DC_State)();

#endif /* DC_MOTOR_H_ */
