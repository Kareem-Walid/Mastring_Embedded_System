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
#include <stdint.h>

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define STACK_START_SP    0x20001000
extern int main(void);
void Reset_Handler(void);

void Default_Handler(void)
{
	Reset_Handler();
}

void NMI_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;
void Hard_Fault_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;
void MM_Fault_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;
void Bus_Fault_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;
void Usage_Fault_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;

uint32_t vector[] __attribute__ ((section(".vectors"))) = {
	
  (uint32_t)	STACK_START_SP,
  (uint32_t)	&Reset_Handler,
  (uint32_t)	&NMI_Handler,
  (uint32_t)	&Hard_Fault_Handler,
  (uint32_t)	&MM_Fault_Handler,
  (uint32_t)	&Bus_Fault_Handler,
  (uint32_t)	&Usage_Fault_Handler,
};

extern uint32_t _S_DATA;
extern uint32_t _E_DATA;
extern uint32_t _S_BSS;
extern uint32_t _E_BSS;
extern uint32_t _E_TEXT;


void Reset_Handler(void)
{
	uint32_t i;
	/* COPY DATA FROM ROM TO RAM */
	uint32_t DATA_SIZE =(uint8_t*)&_E_DATA - (uint8_t*)&_S_DATA ;
	uint8_t* P_SRC = (uint8_t*)&_E_TEXT;
    uint8_t* P_DES = (uint8_t*)&_S_DATA;
	
	for(i = 0; i< DATA_SIZE;i++)
	{
		*((uint8_t*)P_DES++) = *((uint8_t*)P_SRC++);
	}

    /* INIT BSS WITH ZEROS */
	uint32_t BSS_SIZE = (uint8_t*)&_E_BSS - (uint8_t*)&_S_BSS ;
	P_DES = (uint8_t)&_S_BSS;
	for(i =0; i<BSS_SIZE;i++)
	{
		*((uint8_t*)P_DES++) = ((uint8_t)0);
	}
	
	/*Jumb to the main */
	main();
}