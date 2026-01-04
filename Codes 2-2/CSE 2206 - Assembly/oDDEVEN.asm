.MODEL SMALL
.STACK 100H  
.DATA
MSG1 DB 'The number is $'
MSG2 DB 0DH,0AH,'EVEN$'
MSG3 DB 0DH,0AH,'ODD$'
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS,AX
    
    XOR BX,BX
    MOV AH,1
    INT 21H
    
WHILE_:
    CMP AL,0DH
    JE END_WHILE_
    AND AL,0FH
    SHL BX,1
    OR BL,AL
    INT 21H
    JMP WHILE_
END_WHILE_: 
    LEA DX,MSG1
    MOV AH,9
    INT 21H
    
    TEST BL,1
    JZ EVEN
    JMP ODD
    
EVEN:
    LEA DX,MSG2
    MOV AH,9
    INT 21H
    JMP EXIT
    
ODD:
    LEA DX,MSG3
    MOV AH,9
    INT 21H
    
EXIT:
    MOV AH,4CH
    INT 21H
    
MAIN ENDP
END MAIN   
    
    
    
    