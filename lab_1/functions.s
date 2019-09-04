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
    ADD r0, r0, r1
    MOV pc, lr
    .end

subtraction:
    SUB r0, r0, r1
    MOV pc, lr
    .end

multiplication:
    MUL r0, r0, r1
    MOV pc, lr
    .end

division:
    MOV pc, lr
    .end