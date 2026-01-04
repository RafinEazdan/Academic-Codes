.MODEL SMALL
.STACK 
.DATA
MSG1 DB 10,13,'PRIME$'
MSG2 DB 10,13,'NOT PRIME$'
.CODE
MAIN PROC  
    MOV AX,@DATA
    MOV DS,AX
    
    CALL INDEC
    PUSH AX 
    MOV BH,AL
    JMP CHECK
    
    
    
    CHECK: 
    CMP BH,1
    JLE NOT_PRIME
    
    MOV CX,2
    AND AX,0
    AND DX,0
    
    MOV AL,BH
    DIV CX 
    MOV CX,AX
    
    
    
    ISPRIME:
    
    CMP CX,2
    JL PRIME
    AND AX,0
    AND DX,0
    MOV AL,BH
    DIV CX
    DEC CX
    CMP DX,0
    JE NOT_PRIME
    JMP ISPRIME
    
    
    PRIME:
    LEA DX,MSG1
    MOV AH,9
    INT 21H
    JMP EXIT
    
    
    NOT_PRIME:
    LEA DX,MSG2
    MOV AH,9
    INT 21H 
    JMP EXIT
    
    EXIT:
    MOV AH,4CH
    INT 21H
    MAIN ENDP 


INDEC PROC
    PUSH BX
    PUSH CX
    PUSH DX
    @BEGIN:
    MOV AH,2
    MOV DL,'?'
    INT 21H
    
    XOR CX,CX
    MOV AH,1
    INT 21H
    
    CMP AL,'-'
    JE @MINUS
    CMP AL,'+'
    JMP @REPEAT2
    
    @MINUS:
    MOV CX,1
    
    @PLUS:
    INT 21H
    
    @REPEAT2:
    CMP AL,'0'
    JNGE @NOT_DIGIT
    CMP AL,'9'
    JNLE @NOT_DIGIT
    
    AND AX,000FH
    PUSH AX
    
    MOV AX,10
    MUL BX
    POP BX
    ADD BX,AX
    
    MOV AH,1
    INT 21H
    CMP AL,0DH
    JNE @REPEAT2
    
    MOV AX,BX
    
    OR CX,CX
    JE @EXIT
    NEG AX
    @EXIT:
    POP DX
    POP CX
    POP BX
    RET
    @NOT_DIGIT:
    MOV AH,2
    MOV DL,0DH
    INT 21H
    JMP @BEGIN
INDEC ENDP
END MAIN