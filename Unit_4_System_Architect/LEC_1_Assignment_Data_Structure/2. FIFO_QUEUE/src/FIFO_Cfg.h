/**********************************************************************************************************************
 *  FILE INFORMATION
 *  -----------------------------------------------------------------------------------------------------------------
 *        FILE NAME :  FIFO_CFG.h
 *        FILE DATE :  30/10/2023
 *        VERSION:   V1.0
 *        AUTHOR:   KAREEM WALID
 *        BRIEF EXPLANATION: 
 *
 *********************************************************************************************************************/

 /* FILE GUARD */
 #ifndef FIFO_CFG_H_
#define  FIFO_CFG_H_
 
 
 
/* USER CONFIG */
/* Select Element Type (uint8 , uint16 ...)*/
#define   Element_Type   uint8

/* Width of the buffer */
#define Width     5

Element_Type Queue[Width];
 
 
 
 
#endif  /* FIFO_CFG_H_ */

/**********************************************************************************************************************
 *  END OF FILE: FIFO_Cfg.h
 *********************************************************************************************************************/