.MODEL SMALL
.STACK 100H
.DATA
MSG2 DB 0DH, 0AH, '1ST Largest Number is $' 
MSG3 DB 0DH, 0AH, '2ND Largest Number is $' 
MSG4 DB 0DH, 0AH, '3RD Largest Number is $'    

NUM1 DB ?,'$'  
NUM2 DB ?,'$'
NUM3 DB ?,'$'

.CODE
MAIN PROC
          MOV AX,@DATA
          MOV DS, AX
          
          MOV AH,1 
          INT 21H
          MOV NUM1, AL 
          
          MOV AH,1 
          INT 21H
          MOV NUM2, AL
          
          MOV AH,1 
          INT 21H
          MOV NUM3, AL
          
          MOV AL,NUM1
          MOV BL,NUM2
          CMP AL,BL
          JGE step2
          JL step1 
          
step1:
          MOV NUM2,AL
          MOV NUM1,BL
          JMP step2
          
step2:
          MOV AL,NUM1
          MOV BL,NUM3
          CMP AL,BL
          JGE step4
          JL step3
          
step3:
          MOV NUM3,AL
          MOV NUM1,BL
          JMP step4
          
step4:
          MOV AL,NUM2
          MOV BL,NUM3
          CMP AL,BL
          JGE step6
          JL step5         
 
step5:
          MOV NUM3,AL
          MOV NUM2,BL
          JMP step6
          
          
step6:
           
          LEA DX, MSG2
          MOV AH,9
          INT 21H   
          
          MOV AH, 2      
          MOV DL, NUM1    
          INT 21H  
          
          LEA DX, MSG3
          MOV AH,9
          INT 21H   
          
          MOV AH, 2      
          MOV DL, NUM2   
          INT 21H
          
          LEA DX, MSG4
          MOV AH,9
          INT 21H   
          
          MOV AH, 2      
          MOV DL, NUM3    
          INT 21H
          
MAIN ENDP
END MAIN