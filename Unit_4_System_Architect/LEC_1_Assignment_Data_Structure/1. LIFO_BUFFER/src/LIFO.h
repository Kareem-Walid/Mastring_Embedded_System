/**********************************************************************************************************************
 *  FILE INFORMATION
 *  -----------------------------------------------------------------------------------------------------------------
 *        FILE NAME : LIFO.h 
 *        FILE DATE : 30/10/2023  
 *        VERSION:   V1.0
 *        AUTHOR:   KAREEM WALID
 *        BRIEF EXPLANATION: 
 *
 *********************************************************************************************************************/

 /* FILE GUARD */
#ifndef   _LIFO_H_
#define   _LIFO_H_


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Platform_Types.h"
#include "LIFO_Cfg.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define  NULL  ((void *)0)



/**********************************************************************************************************************
 *  GLOBAL Enumeration AND STRUCTURES
 *********************************************************************************************************************/
/*TYPE DEFINITIONS */
typedef struct {
	uint32 Length;
	uint32 Count;
	uint32* Base;
	uint32* Head;
	
}LIFO_BUFFER_t;

typedef enum {
	LIFO_NO_ERROR,
	LIFO_FULL,
	LIFO_EMPTY,
	LIFO_NULL

}LIFO_Status_t;



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : LIFO_Status_t LIFO_Init(LIFO_BUFFER_t* LIFO_BUF, uint32* Buf , uint32 length )       
* \Description     : This function responsable on init buffer and  make base and head pointing on the button of the buffer (stack)     
*                                                                             
* \Sync\Async      : Asynchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Struct of Buffer Pointers, Buffer , Lenght                     
* \Parameters (out): Status of the buffer                                                       
* \Return value:   : LIFO_NULL,LIFO_NO_ERROR
*******************************************************************************/
LIFO_Status_t LIFO_Init(LIFO_BUFFER_t* LIFO_BUF, uint32* Buf , uint32 length );

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
LIFO_Status_t LIFO_PUSH(LIFO_BUFFER_t* LIFO_BUF, uint32 Data);


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
LIFO_Status_t LIFO_POP(LIFO_BUFFER_t* LIFO_BUF, uint32* Data);


#endif  /* _LIFO_H_ */

/**********************************************************************************************************************
 *  END OF FILE: LIFO.h
 *********************************************************************************************************************/


