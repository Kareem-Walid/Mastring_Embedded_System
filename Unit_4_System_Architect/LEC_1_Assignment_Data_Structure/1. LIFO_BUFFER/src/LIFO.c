/**********************************************************************************************************************
 *  FILE INFORMATION
 *  -----------------------------------------------------------------------------------------------------------------
 *        FILE NAME :  LIFO.c
 *        FILE DATE :  30/10/2023
 *        VERSION:   V1.0
 *        AUTHOR:   KAREEM WALID
 *        BRIEF EXPLANATION: 
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "LIFO.h"


/******************************************************************************
* \Syntax          : LIFO_Status_t LIFO_Init(LIFO_BUFFER_t* LIFO_BUF, uint32* Buf , uint32 length )       
* \Description     : This function responsable on init buffer and  make base and head pointing on the bottom of the buffer (stack)     
*                                                                             
* \Sync\Async      : Asynchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Struct of Buffer Pointers, Buffer , Lenght                     
* \Parameters (out): Status of the buffer                                                       
* \Return value:   : LIFO_NULL,LIFO_NO_ERROR
*******************************************************************************/
LIFO_Status_t LIFO_Init(LIFO_BUFFER_t* LIFO_BUF, uint32* Buf , uint32 length )
{

	/*If using Dynamic Allocation*/
	if(Buf == NULL)
	{
		return 	LIFO_NULL;
	}
    /* Make Base Pointing on the bottom of the buffer */
	LIFO_BUF -> Base = Buf;
	
	    /* Make Head Pointing on the bottom of the buffer */

	LIFO_BUF -> Head = Buf;
	
	LIFO_BUF -> Length = length;
	/*Init means number of elements is zero */                        
	LIFO_BUF -> Count = 0;

	return LIFO_NO_ERROR;

}


/******************************************************************************
* \Syntax          : LIFO_Status_t LIFO_PUSH(LIFO_BUFFER_t* LIFO_BUF, uint32 Data)       
* \Description     :       
*                                                                             
* \Sync\Async      : Asynchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : truct of Buffer Pointers , Data                     
* \Parameters (out): Status of the buffer                                                      
* \Return value:   : LIFO_NULL, LIFO_FULL, LIFO_NO_ERROR                              
*******************************************************************************/
LIFO_Status_t LIFO_PUSH(LIFO_BUFFER_t* LIFO_BUF, uint32 Data)
{
	/* FIFO valid or not */
	if( !LIFO_BUF -> Base || !LIFO_BUF -> Head )
	{
		return LIFO_NULL;
	}

	/* Check if Full */
	if(LIFO_BUF -> Count == LIFO_BUF -> Length)
	{
		return LIFO_FULL;
	}

	/* Push value*/
	*(LIFO_BUF -> Head) = Data;
	LIFO_BUF -> Head ++;
	LIFO_BUF -> Count++;


	return LIFO_NO_ERROR;

}


/******************************************************************************
* \Syntax          : LIFO_Status_t LIFO_POP(LIFO_BUFFER_t* LIFO_BUF, uint32* Data)       
* \Description     :       
*                                                                             
* \Sync\Async      : Asynchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : truct of Buffer Pointers , Data                     
* \Parameters (out): Status of the buffer                                                      
* \Return value:   : LIFO_NULL, LIFO_EMPTY, LIFO_NO_ERROR                              
*******************************************************************************/
LIFO_Status_t LIFO_POP(LIFO_BUFFER_t* LIFO_BUF, uint32* Data)
{
	/* FIFO valid or not */
	if( !LIFO_BUF -> Base || !LIFO_BUF -> Head )
	{
		return LIFO_NULL;
	}

	/* Check if Empty */
	if(LIFO_BUF -> Count == 0)
	{
		return LIFO_EMPTY;
	}

	LIFO_BUF -> Head --;
	*(Data) = (LIFO_BUF -> Head);
	LIFO_BUF -> Count--;
	return LIFO_NO_ERROR;

}

/**********************************************************************************************************************
 *  END OF FILE: LIFO.c
 *********************************************************************************************************************/