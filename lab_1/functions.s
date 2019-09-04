    .section ".text"
    .global addition
    .type addition %functino
addition:
    ADDS r0, r0, r1
    MOV pc, lr
    .end
