    .section ".text"
    .global addition
    .global subtraction
    .global multiplication
    .global division

    .type addition %function
    .type subtraction %function
    .type multiplication %function
    .type division %function

addition:
    .fnstart
    ADD r0, r0, r1
    MOV pc, lr
    .fnend

subtraction:
    .fnstart
    SUB r0, r0, r1
    MOV pc, lr
    .fnend

multiplication:
    .fnstart
    MUL r0, r0, r1
    MOV pc, lr
    .fnend

division:
    .fnstart
    MOV pc, lr
    .fnend

