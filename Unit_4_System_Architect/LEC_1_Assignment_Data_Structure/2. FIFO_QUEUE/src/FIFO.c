/**********************************************************************************************************************
 *  FILE INFORMATION
 *  -----------------------------------------------------------------------------------------------------------------
 *        FILE NAME :  FIFO.c
 *        FILE DATE :  30/10/2023
 *        VERSION:   V1.0
 *        AUTHOR:   KAREEM WALID
 *        BRIEF EXPLANATION: 
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "FIFO.h"




/******************************************************************************
* \Syntax          : LIFO_Status_t FIFO_Init(FIFO_QUEUE_t* FIFO_Que, Element_Type* Queue,uint32 length)       
* \Description     : This function responsable on init queue for storing data, Pointing Base - Head - Tail on the bottom of the queue
*                    then assign length and make counter equal zero.      
*                                                                             
* \Sync\Async      : Asynchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Struct of Queue Pointers, Queue , the Lenth of the queue                   
* \Parameters (out): Queue Status                                                       
* \Return value    : FIFO_NULL,FIFO_NO_ERROR
*******************************************************************************/
LIFO_Status_t FIFO_Init(FIFO_QUEUE_t* FIFO_Que, Element_Type* Queue,uint32 length)
{

    /* Check if Dynamic Allocation */
	if(Queue == NULL )
	{
		return FIFO_NULL;
	}

    /* Pointing Base on the bottom of the queue */
	FIFO_Que -> Base = Queue;
	/* Pointing Head on the bottom of the queue */
	FIFO_Que -> Head = Queue;
	/* Pointing Tail on the bottom of the queue */
	FIFO_Que -> Tail = Queue;
	
	FIFO_Que -> Length = length;
	/* Couner zero*/
	FIFO_Que -> Count = 0;

	return FIFO_NO_ERROR;

}


/******************************************************************************
* \Syntax          : LIFO_Status_t FIFO_EnQueue(FIFO_QUEUE_t* FIFO_Que, Element Type Item )       
* \Description     : This Function responsable for Enqueue (Pushing) Item (Data) on the queue 
*                                                                             
* \Sync\Async      : Asynchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : struct of the queue pinters, items                      
* \Parameters (out): Queue Status                                                      
* \Return value    : FIFO_NULL,FIFO_FULL,FIFO_NO_ERROR                               
*******************************************************************************/
LIFO_Status_t FIFO_EnQueue(FIFO_QUEUE_t* FIFO_Que, Element_Type Item )
{
	if(!FIFO_Que -> Base || !FIFO_Que -> Head || !FIFO_Que -> Tail )
	{
		return FIFO_NULL;
	}

	/* Check if the fifo is full */
	if(FIFO_IS_FULL(Queue) == FIFO_FULL)
	{
		return FIFO_FULL;
	}

	*(FIFO_Que -> Head) =  Item;
	FIFO_Que -> Count ++;

	/* Circular FIFO*/
	if(FIFO_Que -> Head == (FIFO_Que -> Base + (FIFO_Que -> Length * sizeof(Element_Type))))
	{
		FIFO_Que -> Head == FIFO_Que -> Base;
	}else
	{
		FIFO_Que -> Head ++;
	}

	return FIFO_NO_ERROR;



}


/******************************************************************************
* \Syntax          : LIFO_Status_t FIFO_DeQueue(FIFO_QUEUE_t* FIFO_Que, Element_Type Item)       
* \Description     : This Function responsable for get the item       
*                                                                             
* \Sync\Async      : Asynchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : struct of the queue pinters, items                     
* \Parameters (out): Queue Status                                                      
* \Return value    : FIFO_NULL,FIFO_FULL,FIFO_NO_ERROR                                 
*******************************************************************************/
LIFO_Status_t FIFO_DeQueue(FIFO_QUEUE_t* FIFO_Que, Element_Type Item)
{

	if(!FIFO_Que -> Base || !FIFO_Que -> Head || !FIFO_Que -> Tail )
	{
		return FIFO_NULL;
	}

	/* check if fifo empty */
	if(FIFO_Que -> Count == 0)
	{
		return FIFO_EMPTY;
	}


	/* Circular FIFO*/
	if(FIFO_Que -> Tail == (FIFO_Que -> Base + (FIFO_Que -> Length * sizeof(Element_Type))))
	{
		FIFO_Que -> Tail == FIFO_Que -> Base;
	}else
	{
		FIFO_Que -> Tail ++;
	}

	return FIFO_NO_ERROR;



}

/******************************************************************************
* \Syntax          : LIFO_Status_t FIFO_IS_FULL(FIFO_QUEUE_t* FIFO_Que)       
* \Description     : This function check if the queue full      
*                                                                             
* \Sync\Async      : Asynchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Queue                   
* \Parameters (out): Queue Status                                                      
* \Return value    : FIFO_NULL, FIFO_FULL , FIFO_NO_ERROR                               
*******************************************************************************/
LIFO_Status_t FIFO_IS_FULL(FIFO_QUEUE_t* FIFO_Que)
{
    /* Check on the Fifo */
	if(!FIFO_Que -> Base || !FIFO_Que -> Head || !FIFO_Que -> Tail )
	{
		return FIFO_NULL;
	}
	
	if(FIFO_Que -> Length == FIFO_Que -> Count )
	{
		return FIFO_FULL;
	}

	return FIFO_NO_ERROR;
}

/******************************************************************************
* \Syntax          : LIFO_Status_t FIFO_IS_EMPTY(FIFO_QUEUE_t* FIFO_Que)       
* \Description     : This function check if the queue empty      
*                                                                             
* \Sync\Async      : Asynchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Queue                   
* \Parameters (out): Queue Status                                                      
* \Return value    : FIFO_NULL, FIFO_EMPTY , FIFO_NO_ERROR                               
*******************************************************************************/
LIFO_Status_t FIFO_IS_EMPTY(FIFO_QUEUE_t* FIFO_Que)
{
    /* Check on the Fifo */
	if(!FIFO_Que -> Base || !FIFO_Que -> Head || !FIFO_Que -> Tail )
	{
		return FIFO_NULL;
	}
	
	if(FIFO_Que -> Count == 0 )
	{
		return FIFO_EMPTY;
	}

	return FIFO_NO_ERROR;
}


/******************************************************************************
* \Syntax          : void FIFO_Print(FIFO_QUEUE_t* FIFO_Que)       
* \Description     : This function to print the elements of the queue      
*                                                                             
* \Sync\Async      : Asynchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Queue                     
* \Parameters (out): None                                                      
* \Return value:   :                                  
*******************************************************************************/
void FIFO_Print(FIFO_QUEUE_t* FIFO_Que)
{
    Element_Type* temp;
    uint32 i;

    if(FIFO_IS_EMPTY(FIFO_Que) == FIFO_EMPTY)
    {
    	printf("FIFO Is empty");
    }else
    {
    	temp = FIFO_Que ->Tail;
    	printf("\n ==== FIFO Print =========== \n");
    	for(i=0;i<FIFO_Que -> Count ; i++)
    	{
    		printf("\t %x \n",*temp);
    		temp++;
    	}
    	printf(" ====================== \n");
    }
}

/**********************************************************************************************************************
 *  END OF FILE: FIFO.c
 *********************************************************************************************************************/
