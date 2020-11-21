.386
.model flat, stdcall
option casemap :none
include \masm32\include\masm32rt.inc
include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\user32.inc
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\user32.lib
.data
    str1 DB "Cadena de c 1" , 0 
    str2 DB "Cadena kaka" , 0 
    a@main DD ? 
    b@main DD ? 
    c@main DD ? 
    w@main DD ? 
    w@main@IF_1 DD ? 
    x@main DD ? 
.code
START:
MOV EBX,10
CMP EBX,1
JLE Label6
MOV ECX,a@main
MOV ECX,b@main
MOV EAX,b@main
MOV EAX,3
JMP Label9
Label6:
MOV EDX,b@main
SUB EDX,2
MOV a@main,EDX
Label9:
MOV EDX,10
CMP EDX,1
JGE Label15
MOV EDX,b@main
ADD EDX,2
MOV a@main,EDX
JMP Label18
Label15:
MOV EDX,b@main
SUB EDX,2
MOV a@main,EDX
Label18:
invoke MessageBox, NULL, addr str1, addr str1, MB_OK
Label20:
JL Label27
MOV EDX,b@main
SUB EDX,2
MOV a@main,EDX
invoke MessageBox, NULL, addr str2, addr str2, MB_OK
JMP Label20
Label27:
END START
