#include "uart.h"

unsigned char string_buffer[100] = "Learn-In-Depth:Kareem";

void main(void)
{
	
	UART_Send_String(string_buffer);
	
}