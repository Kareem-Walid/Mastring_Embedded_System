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
	.file	"app.c"
	.global	string_buffer
	.data
	.align	2
	.type	string_buffer, %object
	.size	string_buffer, 100
string_buffer:
	.ascii	"Learn-In-Depth:Kareem\000"
	.space	78
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	ldr	r0, .L2
	bl	UART_Send_String
	sub	sp, fp, #4
	ldmfd	sp!, {fp, lr}
	bx	lr
.L3:
	.align	2
.L2:
	.word	string_buffer
	.size	main, .-main
	.ident	"GCC: (GNU) 4.7.2"
