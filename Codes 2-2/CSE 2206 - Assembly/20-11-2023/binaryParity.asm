.MODEL SMALL
.STACK 100H 
.DATA

MSG1 DB 'The inputted binary number is $'
MSG2 DB 10,13,'EVEN$'
MSG3 DB 10,13,'ODD$'

.CODE

MAIN PROC 
    MOV AX, @DATA
    MOV DS, AX
          
    XOR BX, BX 
    MOV AH, 1 
    INT 21H 

WHILE:
    CMP AL, 0DH 
    JE END_WHILE
    AND AL, 0FH
    SHL BX, 1 
    OR BL, AL 
    INT 21H 
    JMP WHILE

END_WHILE:
    LEA DX, MSG1
    MOV AH, 9
    INT 21H 

    TEST BL, 1
    JZ PRINT_EVEN
    JMP PRINT_ODD 

PRINT_EVEN: 
    LEA DX, MSG2
    MOV AH, 9
    INT 21H
    JMP EXIT 

PRINT_ODD:
    LEA DX, MSG3
    MOV AH, 9
    INT 21H 

EXIT:
    MOV AH, 4CH
    INT 21H

MAIN ENDP
END MAIN