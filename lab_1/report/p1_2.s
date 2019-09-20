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
	.file	"p1_2.c"
	.text
	.comm	var,4,4
	.align	1
	.global	swap
	.arch armv7-a
	.syntax unified
	.thumb
	.thumb_func
	.fpu vfpv3-d16
	.type	swap, %function
swap:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	sub	sp, sp, #20
	add	r7, sp, #0
	str	r0, [r7, #4]
	str	r1, [r7]
	ldr	r3, [r7, #4]
	ldr	r3, [r3]
	str	r3, [r7, #12]
	ldr	r3, [r7]
	ldr	r2, [r3]
	ldr	r3, [r7, #4]
	str	r2, [r3]
	ldr	r3, [r7]
	ldr	r2, [r7, #12]
	str	r2, [r3]
	nop
	adds	r7, r7, #20
	mov	sp, r7
	@ sp needed
	ldr	r7, [sp], #4
	bx	lr
	.size	swap, .-swap
	.align	1
	.global	main
	.syntax unified
	.thumb
	.thumb_func
	.fpu vfpv3-d16
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r4, r7, lr}
	sub	sp, sp, #20
	add	r7, sp, #0
	ldr	r4, .L5
.LPIC0:
	add	r4, pc
	ldr	r3, .L5+4
	ldr	r3, [r4, r3]
	ldr	r3, [r3]
	str	r3, [r7, #12]
	movs	r3, #10
	str	r3, [r7, #4]
	movs	r3, #20
	str	r3, [r7, #8]
	add	r2, r7, #8
	adds	r3, r7, #4
	mov	r1, r2
	mov	r0, r3
	bl	swap(PLT)
	movs	r3, #0
	mov	r0, r3
	ldr	r3, .L5+4
	ldr	r3, [r4, r3]
	ldr	r2, [r7, #12]
	ldr	r3, [r3]
	cmp	r2, r3
	beq	.L4
	bl	__stack_chk_fail(PLT)
.L4:
	adds	r7, r7, #20
	mov	sp, r7
	@ sp needed
	pop	{r4, r7, pc}
.L6:
	.align	2
.L5:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC0+4)
	.word	__stack_chk_guard(GOT)
	.size	main, .-main
	.ident	"GCC: (Ubuntu 8.3.0-6ubuntu1~18.10.1) 8.3.0"
	.section	.note.GNU-stack,"",%progbits
