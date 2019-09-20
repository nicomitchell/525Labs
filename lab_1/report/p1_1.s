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
	.file	"p1_1.c"
	.text
	.global	var1
	.data
	.type	var1, %object
	.size	var1, 1
var1:
	.byte	1
	.global	var2
	.type	var2, %object
	.size	var2, 1
var2:
	.byte	2
	.global	var3
	.align	2
	.type	var3, %object
	.size	var3, 4
var3:
	.word	3
	.global	var4
	.align	2
	.type	var4, %object
	.size	var4, 4
var4:
	.word	4
	.global	num
	.section	.rodata
	.align	2
	.type	num, %object
	.size	num, 4
num:
	.word	-10
	.global	wave
	.data
	.align	2
	.type	wave, %object
	.size	wave, 10
wave:
	.ascii	"goodbye!!!"
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
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	sub	sp, sp, #12
	add	r7, sp, #0
	movs	r3, #5
	str	r3, [r7, #4]
	b	.L2
.L3:
	ldr	r3, .L9
.LPIC0:
	add	r3, pc
	ldrsb	r3, [r3]
	uxtb	r2, r3
	ldr	r3, .L9+4
.LPIC1:
	add	r3, pc
	ldrsb	r3, [r3]
	uxtb	r3, r3
	smulbb	r3, r2, r3
	uxtb	r3, r3
	sxtb	r2, r3
	ldr	r3, .L9+8
.LPIC2:
	add	r3, pc
	strb	r2, [r3]
	ldr	r3, .L9+12
.LPIC3:
	add	r3, pc
	movs	r2, #1
	strb	r2, [r3]
	ldr	r3, .L9+16
.LPIC4:
	add	r3, pc
	ldrsb	r3, [r3]
	uxtb	r3, r3
	lsls	r3, r3, #1
	uxtb	r3, r3
	sxtb	r2, r3
	ldr	r3, .L9+20
.LPIC5:
	add	r3, pc
	strb	r2, [r3]
	ldr	r3, .L9+24
.LPIC6:
	add	r3, pc
	movs	r2, #0
	strb	r2, [r3]
	ldr	r3, [r7, #4]
	subs	r3, r3, #1
	str	r3, [r7, #4]
.L2:
	ldr	r3, [r7, #4]
	cmp	r3, #0
	bgt	.L3
.L4:
	ldr	r3, .L9+28
.LPIC7:
	add	r3, pc
	ldr	r3, [r3]
	subs	r3, r3, #1
	ldr	r2, .L9+32
.LPIC8:
	add	r2, pc
	str	r3, [r2]
	ldr	r3, .L9+36
.LPIC9:
	add	r3, pc
	ldr	r3, [r3]
	cmp	r3, #0
	bne	.L4
	b	.L8
.L7:
	ldr	r3, .L9+40
.LPIC10:
	add	r3, pc
	ldrb	r2, [r3]	@ zero_extendqisi2
	ldr	r3, .L9+44
.LPIC11:
	add	r3, pc
	strb	r2, [r3]
	b	.L6
.L8:
	ldr	r3, .L9+48
.LPIC12:
	add	r3, pc
	ldr	r3, [r3]
	cmp	r3, #3
	beq	.L7
.L6:
	nop
	adds	r7, r7, #12
	mov	sp, r7
	@ sp needed
	ldr	r7, [sp], #4
	bx	lr
.L10:
	.align	2
.L9:
	.word	var1-(.LPIC0+4)
	.word	var1-(.LPIC1+4)
	.word	var1-(.LPIC2+4)
	.word	var1-(.LPIC3+4)
	.word	var1-(.LPIC4+4)
	.word	var1-(.LPIC5+4)
	.word	var1-(.LPIC6+4)
	.word	var4-(.LPIC7+4)
	.word	var4-(.LPIC8+4)
	.word	var4-(.LPIC9+4)
	.word	var2-(.LPIC10+4)
	.word	var2-(.LPIC11+4)
	.word	var3-(.LPIC12+4)
	.size	main, .-main
	.ident	"GCC: (Ubuntu 8.3.0-6ubuntu1~18.10.1) 8.3.0"
	.section	.note.GNU-stack,"",%progbits
