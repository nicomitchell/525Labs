    .section ".text"
    .global addition
    .type addition %function

    .global subtraction
    .type subtraction %function

    .global multiplication
    .type multiplication %function

    .global division
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