

.section .vectors
.word 0x20001000


.word _reset              /* 1. Reset        */
.word _Vector_Handler     /* 2. NMI          */
.word _Vector_Handler     /* 3. Hard Fault   */
.word _Vector_Handler     /* 4. MM Fault     */
.word _Vector_Handler     /* 5. Bus Fault    */
.word _Vector_Handler     /* 6. Usage Fault  */
.word _Vector_Handler     /* 7. Reserved     */
.word _Vector_Handler     /* 8. Reserved     */
.word _Vector_Handler     /* 9. Reserved     */
.word _Vector_Handler     /* 10. Reserved    */
.word _Vector_Handler     /* 11. Debug Reserved     */
.word _Vector_Handler     /* 12. Reserved    */
.word _Vector_Handler     /* 13. PendSV      */
.word _Vector_Handler     /* 14. SysTick     */
.word _Vector_Handler     /* 15. IRQ0        */
.word _Vector_Handler     /* 16. IRQ1        */
.word _Vector_Handler     /* 17. IRQ2        */



.section .text
_reset:
    bl  main
	b   .
	
.thumb_func	
_Vector_Handler:
	 b _reset


	 