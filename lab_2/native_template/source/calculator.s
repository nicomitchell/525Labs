.globl add,sub,mult,divide,div2
.type calculator,%function

add:
.fnstart
add r0,r0,r1
bx lr
.fnend

sub:
.fnstart
sub r0,r0,r1
bx lr
.fnend

mult:
.fnstart
mul r0,r0,r1
bx lr
.fnend

divide:
.fnstart
mov r2,r1
mov r1,r0

mov r0,#0

b loop1

loop2:
add r0,r0,#1
sub r1,r1,r2
loop1:
cmp r1,r2
bhs loop2

bx lr
.fnend

div2:
.fnstart
mov r2,r1
mov r1,r0

mov r0,#0

b loop3

loop4:
add r0,r0,#1
sub r1,r1,r2
loop3:
cmp r1,r2
bhs loop4

mov r0,r1

bx lr
.fnend
