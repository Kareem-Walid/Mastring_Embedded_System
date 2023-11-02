/**********************************************************************************************************************
 *  FILE INFORMATION
 *  -----------------------------------------------------------------------------------------------------------------
 *        FILE NAME : Linked_List.c
 *        FILE DATE : 31/10/2023
 *        VERSION:   V1.0
 *        AUTHOR:   KAREEM WALID
 *        BRIEF EXPLANATION:
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Linked_List.h"
struct SStudent* gpFirstStudent = NULL;

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
void Add_Student(void)
{
	/* Local Pointer */
	struct SStudent* pNewStudent;
	struct SStudent* pLastStudent;


	/* 1. Create New Record */
	/*a. If the list is empty */
	if(gpFirstStudent == NULL)
	{
		/* i. Create new record */
		pNewStudent= (struct SStudent*)malloc(1 * sizeof(struct SStudent));
		/* ii. Assign gPFirstStudent to it */

		gpFirstStudent = pNewStudent;

	}/* b. if the list contains records*/
	else
	{
		/*i. Navigate until reaching the last record */
		pLastStudent = gpFirstStudent;
		while(pLastStudent->pNextStudent )
		{
			pLastStudent = pLastStudent -> pNextStudent;
		}

		/*ii. Create new record */
		pNewStudent= (struct SStudent*)malloc(1 * sizeof(struct SStudent));
		/*iii. Assign gPFirstStudent to it */

		pLastStudent -> pNextStudent = pNewStudent;

	}

	/* 2. fill the new record*/
	Fill_Record(pNewStudent);

	/* 3. set the new record with NULL */
	pNewStudent -> pNextStudent = NULL;

}

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
static void Fill_Record(struct SStudent* Data_New_Student)
{
	uint8 Temp_Text[40];

	DPRINTF("\n==============================");
	DPRINTF("\nEnter the ID: ");
	gets(Temp_Text);
	Data_New_Student -> Student_Data.ID = atoi(Temp_Text);

	DPRINTF("\nEnter the Name: ");
	gets(Data_New_Student -> Student_Data.Name);

	DPRINTF("\nEnter the Degree: ");
	gets(Temp_Text);
	Data_New_Student -> Student_Data.Degree = atof(Temp_Text);
	DPRINTF("\n==============================");

}


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
static void Print_Record(struct SStudent* pStudent)
{
	DPRINTF("\nID: %d",pStudent ->Student_Data.ID);
	DPRINTF("\nName: %s",pStudent ->Student_Data.Name);
	DPRINTF("\nDegree: %f",pStudent ->Student_Data.Degree);
}


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
void Delete_Student(void)
{
	/* Local variables */
	uint8  Temp_Text[40];
	uint32 Selected_ID;

	/*1. Get ID form user */
	DPRINTF("\nEnter Selected ID: ");
	gets(Temp_Text);
	Selected_ID = atoi(Temp_Text);

	/*2. Loop on all records starting from gpFirstStudent */
	if(gpFirstStudent != NULL)
	{
		struct SStudent* pSelectedStudent = gpFirstStudent;
		struct SStudent* pPreviousStudent = NULL;

		while(pSelectedStudent)
		{
			if(pSelectedStudent -> Student_Data.ID == Selected_ID)
			{

				if(pPreviousStudent)
				{
					pPreviousStudent ->pNextStudent = pSelectedStudent ->pNextStudent;
				}else /*if the list is the first*/
				{
					gpFirstStudent = pSelectedStudent -> pNextStudent;
				}

				free(pSelectedStudent);

			}
			pPreviousStudent = pSelectedStudent;
			pSelectedStudent = pSelectedStudent->pNextStudent;

		}


	}
}


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
void View_All(void)
{
	struct SStudent* pCurrentStudent = gpFirstStudent;
	uint8 counter=0;

	if(gpFirstStudent == NULL)
	{
		DPRINTF("Empty List");
	}else
	{
		while(pCurrentStudent)
		{
			DPRINTF("\n------------------------------");
			DPRINTF("\nRecord number %d", counter+1);
			Print_Record(pCurrentStudent);
			DPRINTF("\n------------------------------");
			pCurrentStudent = pCurrentStudent -> pNextStudent;
			counter ++;
		}

	}
}

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
void Delete_All(void)
{
	struct SStudent* pCurrentStudent = gpFirstStudent;

	if(gpFirstStudent == NULL)
	{
		DPRINTF("Empty List");
	}else
	{
		while(pCurrentStudent)
		{
			struct SStudent* pTempStudent = gpFirstStudent;
			pCurrentStudent = pCurrentStudent -> pNextStudent;
			free(pTempStudent);
		}
		gpFirstStudent = NULL;

	}
}

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
void Get_Nth_Index(void )
{
	uint32 Counter = 0,Index;
	uint8  Temp_Text[40];
	struct SStudent* pCurrentNode = gpFirstStudent;

	DPRINTF("\nEnter Selected Index: ");
	gets(Temp_Text);
	Index = atoi(Temp_Text);


	if(gpFirstStudent != NULL)
	{
		while(Counter != Index)
		{
			pCurrentNode = pCurrentNode ->pNextStudent;
			Counter ++;
		}
		DPRINTF("\nRecord Index %d", Index);
		Print_Record(pCurrentNode);
	}
}

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
void Get_Nth_Index_end(void)
{
	struct SStudent* pMainPtr = gpFirstStudent;
	struct SStudent* pReferancePtr = gpFirstStudent;
	uint8 Temp_Text[40];
	uint32 Index , Counter=1;
	DPRINTF("\nEnter Selected Index from the End: ");
	gets(Temp_Text);
	Index = atoi(Temp_Text);

	while(Counter != Index)
	{
		pReferancePtr = pReferancePtr->pNextStudent;
		Counter++;
	}

	while(pReferancePtr->pNextStudent !=NULL)
	{
		pReferancePtr = pReferancePtr->pNextStudent;
		pMainPtr = pMainPtr->pNextStudent;
	}

	DPRINTF("\nRecord Index from the End %d", Index);
	Print_Record(pMainPtr);

}


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
void Get_Length(void)
{

	uint32 Counter = 1;
	struct SStudent* pCurrentNode = gpFirstStudent;
	if(gpFirstStudent == NULL)
	{

	}else{
		while(pCurrentNode->pNextStudent != NULL)
		{
			pCurrentNode = pCurrentNode->pNextStudent;
			Counter ++;
		}

	}

	DPRINTF("Length of the Node : %d",Counter);
}


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
uint32 Get_Length_2(struct SStudent* pCurrentNode)
{

	if(pCurrentNode  == NULL)
	{
		return 0;
	}else{
		return 1 + Get_Length_2(pCurrentNode->pNextStudent);
	}

}


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
void Get_Middle(void)
{
	struct SStudent* SlowPtr = gpFirstStudent;
	struct SStudent* FastPtr = gpFirstStudent;
	uint8 i;
	while(FastPtr != NULL)
	{
		SlowPtr = SlowPtr ->pNextStudent;
		for(i=1;i<=2;i++)
		{
			FastPtr = FastPtr->pNextStudent;
		}

	}
	Print_Record(SlowPtr);
}



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
void Detect_Loop(void)
{
	struct SStudent* SlowPtr = gpFirstStudent;
	struct SStudent* FastPtr = gpFirstStudent;
	uint8 i,flag =0;
	while(FastPtr->pNextStudent != NULL)
	{
		SlowPtr = SlowPtr ->pNextStudent;
		for(i=1;i<=2;i++)
		{
			if(FastPtr->pNextStudent == NULL) {
				flag = 1;
				break;}
			FastPtr = FastPtr->pNextStudent;
		}
		if(FastPtr == SlowPtr)
		{
			DPRINTF("\nDetected Loop");
			break;
		}
	}

	if(flag==1)
	{
		DPRINTF("\nNo Detected Loop");
	}
}



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
void Reverse_List(void)
{
	struct SStudent* pPreviousNode = NULL;
	struct SStudent* pCurrentNode = gpFirstStudent;
	struct SStudent* pNextNode = NULL;

     while(pCurrentNode != NULL)
     {
    	 pNextNode = pCurrentNode->pNextStudent;
    	 pCurrentNode->pNextStudent = pPreviousNode;
    	 pPreviousNode = pCurrentNode;
    	 pCurrentNode = pNextNode;
     }
     gpFirstStudent  = pPreviousNode;
}

/**********************************************************************************************************************
 *  END OF FILE: Linked_List.c
 *********************************************************************************************************************/
