/**********************************************************************************************************************
 *  FILE INFORMATION
 *  -----------------------------------------------------------------------------------------------------------------
 *        FILE NAME :  startup.c
 *        FILE DATE : 28/10/2023 
 *        VERSION:   V1.0
 *        AUTHOR:   KAREEM WALID
 *        BRIEF EXPLANATION: 
 *        
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Platform_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Reserving 1024 Byte located by .bss through unintialized array of 256 element int */
static uint32 STACK_TOP[256];

void Reset_Handler();

extern int main(void);
void Default_Handler(void)
{
	Reset_Handler();
}

void NMI_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;
void Hard_Fault_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;
void MM_Fault_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;
void Bus_Fault_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;
void Usage_Fault_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;


/*Pointer to function*/
void(* const Ptr_Vectors[])()  __attribute__ ((section(".vectors"))) = 
{
(void (*)())	((uint32)STACK_TOP + sizeof(STACK_TOP)),
&Reset_Handler,
&NMI_Handler,
&Hard_Fault_Handler,
&MM_Fault_Handler,
&Bus_Fault_Handler,
&Usage_Fault_Handler

};

extern uint32 _S_DATA;
extern uint32 _E_DATA;
extern uint32 _S_BSS;
extern uint32 _E_BSS;
extern uint32 _E_TEXT;


void Reset_Handler()
{
	uint32 i;
	/* COPY DATA FROM ROM TO RAM */
	uint32 DATA_SIZE =(uint8*)&_E_DATA - (uint8*)&_S_DATA ;
	uint8* P_SRC = (uint8*)&_E_TEXT;
    uint8* P_DES = (uint8*)&_S_DATA;
	
	for(i = 0; i< DATA_SIZE;i++)
	{
		*((uint8*)P_DES++) = *((uint8*)P_SRC++);
	}

    /* INIT BSS WITH ZEROS */
	uint32 BSS_SIZE = (uint8*)&_E_BSS - (uint8*)&_S_BSS ;
	P_DES = (uint8)&_S_BSS;
	for(i =0; i<BSS_SIZE;i++)
	{
		*((uint8*)P_DES++) = ((uint8)0);
	}
	
	/*Jumb to the main */
	main();
}