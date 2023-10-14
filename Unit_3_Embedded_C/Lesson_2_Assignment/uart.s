	.cpu arm7tdmi
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"uart.c"
	.text
	.align	2
	.global	UART_Send_String
	.type	UART_Send_String, %function
UART_Send_String:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #12
	str	r0, [fp, #-8]
	b	.L2
.L3:
	ldr	r3, .L4
	ldr	r2, [fp, #-8]
	ldrb	r2, [r2, #0]	@ zero_extendqisi2
	str	r2, [r3, #0]
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L2:
	ldr	r3, [fp, #-8]
	ldrb	r3, [r3, #0]	@ zero_extendqisi2
	cmp	r3, #0
	bne	.L3
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
.L5:
	.align	2
.L4:
	.word	270471168
	.size	UART_Send_String, .-UART_Send_String
	.ident	"GCC: (GNU) 4.7.2"
