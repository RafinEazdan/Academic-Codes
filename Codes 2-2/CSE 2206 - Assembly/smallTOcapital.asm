.MODEL SMALL
.STACK 100H
.DATA
    MSG1 DB '?$'
    MSG2 DB 0DH,0AH,'$'
    
    CHAR1 DB ?,'$'
    CHAR2 DB ?,'$'
    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    LEA DX,MSG1
    MOV AH,9
    INT 21H 
    
    MOV AH,1
    INT 21H
    SUB AL,20H
    MOV CHAR1,AL
    
    MOV AH,1
    INT 21H
    SUB AL,20H
    MOV CHAR2,AL 
    
    LEA DX,MSG2
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,CHAR1 
    INT 21H
    
    MOV AH,2
    MOV DL,CHAR2
    INT 21H
    
MAIN ENDP
END MAIN
    