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
    _a_padre DD ? 
    _b_padre DD ? 
    _c_padre DD ? 
    _w_padre DD ? 
    _w_padre_IF_1 DD ? 
    _x_padre DD ? 
.code
START:
MOV EBX,10
CMP EBX,1
JLE Label6
MOV _a_padre,3
MOV _b_padre,3
JMP Label9
Label6:
MOV ECX,_b_padre
SUB ECX,2
MOV _a_padre,ECX
Label9:
MOV ECX,10
CMP ECX,1
JGE Label15
MOV EAX,_b_padre
ADD EAX,2
MOV _a_padre,EAX
JMP Label18
Label15:
MOV EAX,_b_padre
SUB EAX,2
MOV _a_padre,EAX
Label18:
invoke MessageBox, NULL, addr str1, addr str1, MB_OK
Label20:
JL Label27
MOV EAX,_b_padre
SUB EAX,2
MOV _a_padre,EAX
invoke MessageBox, NULL, addr str2, addr str2, MB_OK
JMP Label20
Label27:
END START
