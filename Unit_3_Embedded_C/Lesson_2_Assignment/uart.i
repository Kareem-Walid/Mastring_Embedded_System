# 1 "uart.c"
# 1 "<command-line>"
# 1 "uart.c"

# 1 "uart.h" 1
# 11 "uart.h"
void UART_Send_String(unsigned char * Pointer_String);
# 3 "uart.c" 2







void UART_Send_String(unsigned char * Pointer_String)
{

 while ( *Pointer_String != '\0')
 {

  *((volatile unsigned int * const)((unsigned int*)0x101f1000)) = (unsigned int*)(*Pointer_String);
  Pointer_String ++;
 }
}
