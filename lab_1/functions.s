    .section ".text"
    .global addition
    .global subtraction
    .global multiplication
    .global division
    .global remain

    .type addition %function
    .type subtraction %function
    .type multiplication %function
    .type division %function
    .type remain %function

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
    MOV r3, r0
    MOV r2,#0
    loop:    
        SUBS r3, r3, r1
        ADDPL r2, r2, #1
        BPL loop
    MOV r0, r2
    MOV pc, lr
    .fnend

remain:
    .fnstart
    MOV r3, r0
    MOV r2,#0
    loop_D:    
        SUBS r3, r3, r1
        BPL loop_D
    ADDMI r3, r3, r1
    MOV r0, r3
    MOV pc, lr
    .fnend

