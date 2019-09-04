    .section ".text"
    .global addition
    .global subtraction
    .global multiplication
    .global division
    .global remainder

    .type addition %function
    .type subtraction %function
    .type multiplication %function
    .type division %function
    .type remainder %function

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
    loop:
        MOV r3, r0
        SUBS r3, r3, r1
        ADDPL r0, r0, #1
        BPL loop
    MOV pc, lr
    .fnend

remainder:
    .fnstart