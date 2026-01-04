.MODEL SMALL
.STACK 100H
.DATA
    CR EQU 0DH
    LF EQU 0AH

    MSG1 DB 'ENTER 3 initials: $'
    MSG2 DB 0DH,0AH,'1ST INITIAL LOWER CASE : $'
    MSG3 DB 0DH,0AH,'2ND INITIAL LOWER  CASE : $'
    MSG4 DB 0DH,0AH,'3RD INITIAL LOWER  CASE : $'
    CHAR1 DB ?,'$'
    CHAR2 DB ?,'$'
    CHAR3 DB ?,'$'
    

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    LEA DX,MSG1
    MOV AH,9
    INT 21H

    MOV AH,1
    INT 21H
    ADD AL,20H
    MOV CHAR1,AL

    MOV AH,1
    INT 21H
    ADD AL,20H
    MOV CHAR2,AL

    MOV AH,1
    INT 21H
    ADD AL,20H
    MOV CHAR3,AL

    LEA DX,MSG2
    MOV AH,9
    INT 21H

    MOV AH,2
    MOV DL,CHAR1
    INT 21H

    LEA DX,MSG3
    MOV AH,9
    INT 21H

    MOV AH,2
    MOV DL,CHAR2
    INT 21H

    LEA DX,MSG4
    MOV AH,9
    INT 21H

    MOV AH,2
    MOV DL,CHAR3
    INT 21H




MAIN ENDP
END MAIN