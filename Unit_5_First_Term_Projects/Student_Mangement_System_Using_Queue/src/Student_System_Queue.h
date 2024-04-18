
/* FILE GUARD */
#ifndef STUDENT_SYSTEM_QUEUE_H_
#define STUDENT_SYSTEM_QUEUE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "Student_System_Queue_Config.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define  SPACE        32
#define  ASCII_OFFSET 48
#define  DPRINTF(...)    {fflush(stdout);\
		                  fflush(stdin);\
	                      printf(__VA_ARGS__);\
		                  fflush(stdout);\
	                      fflush(stdin);}

/* ----------------------------------------------------------------------------------------------------------------- */



/**********************************************************************************************************************
 *  GLOBAL Enumeration AND STRUCTURES
 *********************************************************************************************************************/

/* Structure for every Student , Every Element in the queue = this structure */
struct {
	char FName[NAME_WIDTH];
	char LName[NAME_WIDTH];
	int Roll;
	float GPA;
	int Credit_Id[COURSES_WIDTH];

}Students[NUMBER_OF_STUDENTS];


typedef enum{
	Queue_Full,
	Queue_Empty,
	Queue_Not_Full_Or_Empty,

}Queue_Status;


typedef enum{
	Roll_Not_Found,
	Roll_Exist,
	GPA_Error,
	GPA_True,
	Course_ID_Exist,
    Course_ID_True,
}Student_State_t;






/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Add_Student_Manually(void);
void Add_Student_File(void);
void Find_Student_From_Roll(void);
void Find_Student_From_Name(void);
void Find_Student_From_Course_ID(void);
void Find_Total_Students(void);
void Delete_Student_by_Roll_Number(void);
void Update_Student_by_Roll_Number(void);
void Display_All_Information(void);



#endif /* STUDENT_SYSTEM_QUEUE_H_ */
