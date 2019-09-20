	.arch armv7-a
	.eabi_attribute 28, 1
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"p1_3b.c"
	.text
	.section	.rodata
	.align	2
.LC0:
	.ascii	"Next Character= %c\012\000"
	.text
	.align	1
	.global	main
	.arch armv7-a
	.syntax unified
	.thumb
	.thumb_func
	.fpu vfpv3-d16
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	add	r7, sp, #0
	movs	r0, #65
	bl	next_char(PLT)
	mov	r3, r0
	mov	r1, r3
	ldr	r3, .L2
.LPIC0:
	add	r3, pc
	mov	r0, r3
	bl	printf(PLT)
	nop
	pop	{r7, pc}
.L3:
	.align	2
.L2:
	.word	.LC0-(.LPIC0+4)
	.size	main, .-main
	.ident	"GCC: (Ubuntu 8.3.0-6ubuntu1~18.10.1) 8.3.0"
	.section	.note.GNU-stack,"",%progbits
