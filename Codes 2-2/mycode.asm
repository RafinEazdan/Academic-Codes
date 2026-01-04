 .MODEL SMALL
.STACK 100H
.DATA
CR EQU 0DH
LF EQU 0AH
MSG1 DB 'Enter 1st digit: $'
MSG2 DB CR, LF, 'Enter 2nd digit: $'
MSG3 DB CR, LF, 'The subtraction of $' 
MSG6 DB    'and $'
MSG4 DB '$'
MSG5 DB ' is $  '
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    LEA DX, MSG1
    MOV AH, 9
    INT 21H

    MOV AH, 1
    INT 21H
    SUB AL, '0'  ; Convert ASCII to numeric value
    MOV BL, AL

    LEA DX, MSG2
    MOV AH, 9
    INT 21H

    MOV AH, 1
    INT 21H
    SUB AL, '0'  ; Convert ASCII to numeric value
    MOV CL, AL

    LEA DX, MSG3
    MOV AH,BL
    MOV AH, 9
    INT 21H 
    
    LEA DX,MSG6
    MOV AH,CL
    MOV AH,9
    INT 21H

    SUB BL, CL  ; Subtract the digits
    ADD BL, '0'  ; Convert result to ASCII
    MOV DL, BL
    MOV AH, 2
    INT 21H

    LEA DX, MSG4
    MOV AH, 9
    INT 21H

    MOV DL, CL
    MOV AH, 2
    INT 21H

    LEA DX, MSG5
    MOV AH, 9
    INT 21H

    MOV DL, BL
    MOV AH, 2
    INT 21H

    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN