                  .MODEL SMALL
.STACK 100H  
.DATA
MSG1 DB 'The number is $'
BINARY DW ? 
COUNT DB ?
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
    
    MOV CX,8
    
REVERSE:
    SHR BINARY,1
    JNC ZERO
    JMP ONE
    
 ZERO:
  INC COUNT
  MOV AH,02H
  MOV DL,'0'
  INT 21H
  JMP CONTINUE
  
 ONE:
    MOV AH,02H
    
    
        

    
EXIT:
    MOV AH,4CH
    INT 21H
    
MAIN ENDP
END MAIN   
    
    
    
    