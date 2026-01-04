    PRESERVE8
    THUMB       

    AREA    RESET, DATA, READONLY
    EXPORT  __Vectors

__Vectors
    DCD  0x20001000 
    DCD  Reset_Handler  ; reset vector
    ALIGN

    AREA    MYCODE, CODE, READONLY

    ENTRY
    EXPORT Reset_Handler
    Reset_Handler

    MOV R0, #50      ; R0 = p = 50
    MOV R1, #10      ; R1 = x = 10

WHILE_LOOP
    CMP R0, #0       ; Compare p (R0) with 0
    BEQ END_LOOP     ; If p == 0, exit the loop

    SUB R0, R0, #10  ; p = p - 10
    SUB R1, R1, #1   ; x = x - 1

    B WHILE_LOOP     ; Repeat the loop
END_LOOP  

    END
