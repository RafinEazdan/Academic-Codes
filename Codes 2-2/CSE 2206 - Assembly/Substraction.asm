.model small
.stack 100h
.data
m1 db '1ST DIGIT: $' 
m2 db 10,13,'2ND DIGIT:  $'
m3 db 10,13,'THE SUBSTRACTION OF $'
m4 db ' AND $'
m5 db ' IS $'
n1 db ?
n2 db ?
res db ?

.code
main proc
    mov ax,@data
    mov ds,ax  
    mov ah,9
    lea dx,m1
    int 21h
      
    mov ah,1
    int 21h
    mov n1,al 
    mov ah,9
    lea dx,m2
    int 21h
    mov ah,1
    int 21h
    mov n2,al 
    mov bl,n1
    sub bl,n2
    add bl,48      

    mov ah,9
    lea dx,m3
    int 21h
    
    mov ah,2
    mov dl,n1
    int 21h

    mov ah,9
    lea dx,m4
    int 21h

    mov ah,2
    mov dl,n2
    int 21h

    mov ah,9
    lea dx,m5
    int 21h 
    mov ah,2
    mov dl,bl
    int 21h
     
main endp
end main