.MODEL SMALL
.STACK 100H
.DATA
    STR         DB 'Enter the binary number (max 8-bit) : $'
    STR2        DB 0DH, 0AH, 'Reversed binary number : $'
    STR_OUT     DB 0DH, 0AH, 'Number of 0s : $'

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    LEA DX, STR
    MOV AH, 9
    INT 21H

    XOR BL, BL    ; clear the bl register
    MOV CX, 8
    MOV AH, 1

INPUT:
    INT 21H
    CMP AL, 0DH
    JZ  END_INPUT
    AND AL, 01H
    SHL BL, 1
    OR  BL, AL
    LOOP INPUT

END_INPUT:
    MOV AL, BL
    MOV CX, 8

REVERSE_LOOP:
    SHL AL, 1
    RCR BL, 1
    LOOP REVERSE_LOOP

    LEA DX, STR2
    MOV AH, 9
    INT 21H

    MOV CX, 8
    MOV AH, 2

OUTPUT_REVERSE:
    ROL BL, 1
    JC SET_CARRY
    MOV DL, '0'
    JMP DISPLAY

SET_CARRY:
    MOV DL, '1'

DISPLAY:
    INT 21H
    LOOP OUTPUT_REVERSE

    XOR CX, CX           
    MOV CX, 8           
    MOV BX, 0            

COUNT_ZEROS:
    ROL BL, 1           
    JNC CONTINUE_COUNT   
    INC BX               

CONTINUE_COUNT:
    LOOP COUNT_ZEROS     


    LEA DX, STR_OUT
    MOV AH, 9
    INT 21H

    MOV AH, 2
    ADD BL, '0'          
    MOV DL, BL           
    
    INT 21H

    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN
