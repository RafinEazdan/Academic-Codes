.MODEL SMALL
.STACK 100H
.DATA
   MSG1 DB '1ST LARGEST NUMBER: $'
   MSG2 DB '2ND LARGEST NUMBER: $'
   MSG3 DB '3RD LARGEST NUMBER: $' 
   NUM1 DB ?
   NUM2 DB ?
   NUM3 DB ?
   MAX DB ?
   SECMAX DB ?
   THIRMAX DB ?
   
   
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX  
    
    MOV AH,1
    INT 21H
    MOV NUM1,AH 
    
    MOV AH,1
    INT 21H
    MOV NUM2,AH
    
    MOV AH,1
    INT 21H
    MOV NUM3,AH
    
    MOV AL,NUM1
    MOV MAX,AL
    
    MOV AL,NUM2
    CMP AL,MAX
    JG UPDATE_MAX 
    
    MOV AL,NUM3
    CMP AL,MAX
    JG UPDATE_MAX
    
UPDATE_MAX:
    MOV BL,SECMAX
    MOV THIRMAX, BL
    MOV BL,MAX
    MOV SECMAX,BL
    MOV MAX,AL
    JMP CHECK_SECMAX
    
CHECK_SECMAX:
    MOV AL,NUM2
    CMP AL,SECMAX
    JG UPDATE_SECMAX
    
    MOV AL,NUM3
    CMP AL,SECMAX
    JG UPDATE_SECMAX
    JMP CHECK_THIRMAX
    
UPDATE_SECMAX:
    MOV BL,SECMAX
    MOV THIRMAX,BL
    MOV SECMAX,AL
    JMP CHECK_THIRMAX
    
CHECK_THIRMAX:
    MOV AL,NUM3
    CMP AL,THIRMAX
    JG UPDATE_THIRMAX
    
    JMP DISPLAY
    
UPDATE_THIRMAX:
    MOV THIRMAX,AL  

DISPLAY:
    MOV AH, 09H
    MOV DX, OFFSET MSG1
    INT 21H

    MOV AH, 02H     ; DOS function to print a character for MAX
    MOV DL, MAX
    ADD DL, 30H     ; Convert MAX to its ASCII representation
    INT 21H

    ; Display second largest
    MOV AH, 02H
    MOV DL, SECMAX
    ADD DL, 30H
    INT 21H

    ; Display third largest
    MOV AH, 02H
    MOV DL, THIRMAX
    ADD DL, 30H
    INT 21H
    
    
MAIN ENDP
END MAIN     

