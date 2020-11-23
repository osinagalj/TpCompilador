.386
.model flat, stdcall
option casemap :none
include \masm32\include\masm32rt.inc
include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\user32.inc
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\user32.lib

.DATA
    str1 DB "CORRIENDO LA WEA2" , 0 
    str2 DB "MULTIPLICA BIEN PERRITO SUCIO" , 0 
    str3 DB "MULTIPLICA BIEN PERRITO SUCIO2" , 0 
    str4 DB "MULTIPLICA BIEN PERRITO SUCIO3" , 0 
    str5 DB "NO MULTIPLICA BIEN PERRITO SUCIO" , 0 
    a@main DD ?
    b@main DD ?
    c@main DD ?
    d@main DD ?
    p1@main@aa DD ? 
    p1@main@aa@bb DD ? 
    p1@main@aa@bb@bb DD ? 
    p1@main@cc DD ? 
    w@main DD ?
    x@main DD ? 
    y@main DD ? 
    z@main DD ? 
    @aux1 DD 5.000000
    @aux2 DD 6.000000
    @aux3 DD 3.000000
    @aux4 DD ? 
    str6 DB "Error: Se realizo 2 una division por 0" , 0 
.CODE
    aa@main:
        MOV EBX,6
        ADD EBX,3
        MOV c@main,EBX
        MOV EBX,6
        ADD EBX,3
        MOV d@main,EBX
        MOV EBX,a@main
        CMP EBX,14
        JLE Label17
        invoke MessageBox, NULL, addr str2, addr str2, MB_OK
        JMP Label19
        Label17:
        invoke MessageBox, NULL, addr str5, addr str5, MB_OK
        Label19:
        ret
    bb@main@aa:
        invoke MessageBox, NULL, addr str3, addr str3, MB_OK
        ret
    bb@main@aa@bb:
        invoke MessageBox, NULL, addr str3, addr str3, MB_OK
        ret
    cc@main:
        invoke MessageBox, NULL, addr str4, addr str4, MB_OK
        ret
    noError:
        invoke MessageBox, NULL, addr str6, addr str6, MB_OK
        ret
START:
    invoke MessageBox, NULL, addr str1, addr str1, MB_OK
    FLD @aux1
    FSTP z@main
    FLD @aux2
    FLD @aux3
    FADD 
    FSTP @aux4
    FLD @aux4
    FSTP x@main
    MOV ECX,b@main
    MOV ECX,1
    MOV EDX ,0
    MOV EAX , 8
    MOV ECX,b@main
    CMP b@main, 0
    JE noError
    DIV ECX
    MOV a@main,ECX
END START
