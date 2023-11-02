/**********************************************************************************************************************
 *  FILE INFORMATION
 *  -----------------------------------------------------------------------------------------------------------------
 *        FILE NAME :  
 *        FILE DATE :  
 *        VERSION:   V1.0
 *        AUTHOR:   KAREEM WALID
 *        BRIEF EXPLANATION: 
 *
 *********************************************************************************************************************/

 /* FILE GUARD */
#ifndef FIFO_H_
#define FIFO_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Platform_Types.h"
#include "FIFO_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define NULL  ((void * )0)



/**********************************************************************************************************************
 *  GLOBAL Enumeration AND STRUCTURES
 *********************************************************************************************************************/

typedef struct
{
	uint32 Length;
	uint32 Count;
	Element_Type* Base;
	Element_Type* Head;
	Element_Type* Tail;

}FIFO_QUEUE_t;

typedef enum{
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL
}LIFO_Status_t;



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

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
LIFO_Status_t FIFO_Init(FIFO_QUEUE_t* FIFO_Que, Element_Type* Queue,uint32 length);

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
LIFO_Status_t FIFO_EnQueue(FIFO_QUEUE_t* FIFO_Que, Element_Type Item );


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
LIFO_Status_t FIFO_DeQueue(FIFO_QUEUE_t* FIFO_Que, Element_Type Item);

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
LIFO_Status_t FIFO_IS_FULL(FIFO_QUEUE_t* FIFO_Que);

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
LIFO_Status_t FIFO_IS_EMPTY(FIFO_QUEUE_t* FIFO_Que);

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
void FIFO_Print(FIFO_QUEUE_t* FIFO_Que);


#endif /* FIFO_H_ */

/**********************************************************************************************************************
 *  END OF FILE: FIFO.h
 *********************************************************************************************************************/
