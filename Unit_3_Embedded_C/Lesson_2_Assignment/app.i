# 1 "app.c"
# 1 "<command-line>"
# 1 "app.c"
# 1 "uart.h" 1
# 11 "uart.h"
void UART_Send_String(unsigned char * Pointer_String);
# 2 "app.c" 2

unsigned char string_buffer[100] = "Learn-In-Depth:Kareem";

void main(void)
{

 UART_Send_String(string_buffer);

}
