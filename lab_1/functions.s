    .section ".text"
    .global addition
    .type addition %function
addition:
    ADDS r0, r0, r1
    MOV pc, lr
    .end
