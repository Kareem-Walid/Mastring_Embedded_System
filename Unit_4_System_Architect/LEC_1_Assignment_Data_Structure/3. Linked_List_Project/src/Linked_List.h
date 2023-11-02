/**********************************************************************************************************************
 *  FILE INFORMATION
 *  -----------------------------------------------------------------------------------------------------------------
 *        FILE NAME : Linked_List.h
 *        FILE DATE : 31/10/2023
 *        VERSION:   V1.0
 *        AUTHOR:   KAREEM WALID
 *        BRIEF EXPLANATION:
 *
 *********************************************************************************************************************/
 /* FILE GUARD */
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Platform_Types.h"



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
// #define NULL  ((void * )0)
/* Solve Bug of printf and scanf in Eclips */

#define    DPRINTF(...)     {fflush(stdout);\
                             fflush(stdin);\
							 printf(__VA_ARGS__);\
							 fflush(stdout);\
							 fflush(stdin);}

/**********************************************************************************************************************
 *  GLOBAL Enumeration AND STRUCTURES
 *********************************************************************************************************************/

struct SData{
	uint32 ID;
	uint8  Name[45];
	float  Degree;
};

struct SStudent{
	struct SData Student_Data;
	struct SStudent* pNextStudent;
};


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/******************************************************************************
 * \Syntax          : void Add_Student(void)
 * \Description     : Add Student to list
 *
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Add_Student(void);

/******************************************************************************
 * \Syntax          : static void Fill_Record(struct SStudent* Data_New_Student)
 * \Description     : This Function used to fill the record from the user.
 *
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   :
 *******************************************************************************/
static void Fill_Record(struct SStudent* Data_New_Student);

/******************************************************************************
 * \Syntax          : static void Print_Record(struct SStudent* pStudent)
 * \Description     : This Function used to print(Display) the record from the user.
 *
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   :
 *******************************************************************************/
static void Print_Record(struct SStudent* pStudent);

/******************************************************************************
 * \Syntax          : void Delete_Student(void)
 * \Description     : This Function used to Delete student
 *
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   :
 *******************************************************************************/
void Delete_Student(void);
/******************************************************************************
 * \Syntax          : void View_All(void)
 * \Description     : This function used to display all list.
 *
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   :
 *******************************************************************************/
void View_All(void);

/******************************************************************************
 * \Syntax          : void Delete_All(void)
 * \Description     : This function used to delete all list.
 *
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   :
 *******************************************************************************/
void Delete_All(void);
/******************************************************************************
 * \Syntax          : void Get_Nth_Index(void)
 * \Description     : This function used to get nth Index of the list.
 *
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   :
 *******************************************************************************/
void Get_Nth_Index(void);

/******************************************************************************
 * \Syntax          : void Get_Nth_Index_end(void)
 * \Description     : This function used to get nth Index of the list from the end.
 *
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   :
 *******************************************************************************/
void Get_Nth_Index_end(void);

/******************************************************************************
 * \Syntax          : void Get_Length(void)
 * \Description     : This Function Used to get Length of the list by using (Iterative Solution.)
 *
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   :
 *******************************************************************************/
void Get_Length(void);

/******************************************************************************
 * \Syntax          : void Get_Length_2(void)
 * \Description     : This Function Used to get Length of the list by using (Recursive Solution .)
 *
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
uint32 Get_Length_2(struct SStudent* pCurrentNode);

/******************************************************************************
 * \Syntax          : void Get_Middle(void)
 * \Description     : This Function Used to get the middle if of the list.
 *
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Get_Middle(void);

/******************************************************************************
 * \Syntax          : void Detect_Loop(void)
 * \Description     : This Function Used to Detect loop
 *
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Detect_Loop(void);

/******************************************************************************
 * \Syntax          : void Reverse_List(void)
 * \Description     : This Function Used to Reverse List
 *
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Reverse_List(void);

#endif /* LINKED_LIST_H_ */
/**********************************************************************************************************************
 *  END OF FILE: Linked_List.h
 *********************************************************************************************************************/
