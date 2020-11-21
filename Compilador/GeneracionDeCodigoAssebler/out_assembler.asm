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
    str3 DB "Cadena1" , 0 
    str4 DB "Cadena2" , 0 
    str5 DB "cadena de caracteres 8" , 0 
    a@main DD ? 
    b@main DD ? 
    c@main DD ? 
    d@main@procedure_1 DD ? 
    p1@main@procedure_1 DD ? 
    p1@main@procedure_2 DD ? 
    w@main DD ? 
    x@main DD ? 
.code
    procedure_1:
        MOV EBX,a@main
        MOV EBX,1
        MOV ECX,5
        ADD ECX,7
        MOV d@main@procedure_1,
    procedure_2:
        MOV EAX,3
        CMP EAX,2
START:
    invoke MessageBox, NULL, addr str5, addr str5, MB_OK
    JMP Label
    Label3:
    invoke MessageBox, NULL, addr str3, addr str3, MB_OK
    JMP Label8
    Label6:
    invoke MessageBox, NULL, addr str4, addr str4, MB_OK
    Label8:
    invoke MessageBox, NULL, addr str1, addr str1, MB_OK
    MOV EDX,w@main
    MOV EDX,3
    Label11:
    JL Label18
    MOV EDX,w@main
    ADD EDX,1
    MOV w@main,EDX
    invoke MessageBox, NULL, addr str2, addr str2, MB_OK
    JMP Label11
    Label18:
    END START
