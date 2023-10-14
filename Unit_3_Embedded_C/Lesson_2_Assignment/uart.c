
#include "uart.h"

#define  USART0_Base_Address     ((unsigned int*)0x101f1000)
#define  UART0DR     *((volatile unsigned int * const)USART0_Base_Address)




void UART_Send_String(unsigned char * Pointer_String)
{
	
	while ( *Pointer_String != '\0')
	{
		
		UART0DR = (unsigned int*)(*Pointer_String);
		Pointer_String ++;
	}
}