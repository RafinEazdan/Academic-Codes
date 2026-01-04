.MODEL SMALL 
.STACK 100H 
.DATA
        CNT  DB 0
        CNTT DB 0
        MSG1 DB "ENTER NUMBER:$"
        MSG2 DB "REVERSE:$"
        MSG3 DB "TOTAL ZERO:$"
.CODE
MAIN PROC
                MOV  AX,@DATA
                MOV  DS,AX
                MOV  AH,9
                LEA  DX,MSG1
                INT  21H
                XOR  BX,BX
        loops:    
                MOV  AH,1
                INT  21H
                CMP  AL,0DH
                JE   END_loops
                SUB  AL,48
                CMP  AL,1
                JE   PORE
                INC  CNTT
        PORE:   
                SHL  BX,1
                OR   BL,AL
                INC  CNT
                JMP  loops

        END_loops:
                MOV  AH,2
                MOV  DL,0DH
                INT  21H
                MOV  DL,0AH
                INT  21H
                XOR  CH,CH
                MOV  CL,CNT
                MOV  AH,9
                LEA  DX,MSG2
                INT  21H
        loops2:   
                RCR  BX,1
                JC   OUTPUT1
                MOV  AH,2
                MOV  DL,'0'
                INT  21H
                JMP  LST
        OUTPUT1:
                MOV  AH,2
                MOV  DL,'1'
                INT  21H
        LST:    
                LOOP loops2
                MOV  AH,2
                MOV  DL,0DH
                INT  21H
                MOV  DL,0AH
                INT  21H
                MOV  AH,9
                LEA  DX,MSG3
                INT  21H
                ADD  CNTT,48
                MOV  AH,2
                MOV  DL,CNTT
                INT  21H
                MOV  AH,4CH
                INT  21H
MAIN ENDP
END MAIN