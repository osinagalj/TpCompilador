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
    str1 DB "MULTIPLICA BIEN PERRITO SUCIO" , 0 
    str2 DB "MULTIPLICA BIEN PERRITO SUCIO2" , 0 
    str3 DB "MULTIPLICA BIEN PERRITO SUCIO3" , 0 
    str4 DB "NO MULTIPLICA BIEN PERRITO SUCIO" , 0 
    a@main DD ?
    b@main DD ?
    c@main DD ?
    d@main DD ?
    p1@main@aa DD ? 
    p1@main@aa@bb DD ? 
    p1@main@cc DD ? 
    w@main DD ?
    x@main DD ? 
    y@main DD ? 
    z@main DD ? 
    @aux1 DD ? 
    @aux2 DD ? 
    @aux3 DD 5.0
.CODE
    aa:
        MOV EBX,6
        ADD EBX,3
        MOV c@main,EBX
        MOV EBX,6
        ADD EBX,3
        MOV d@main,EBX
        MOV EBX,a@main
        CMP EBX,14
        JLE Label15
        invoke MessageBox, NULL, addr str1, addr str1, MB_OK
        JMP Label17
        Label15:
        invoke MessageBox, NULL, addr str4, addr str4, MB_OK
        Label17:
    bb:
        invoke MessageBox, NULL, addr str2, addr str2, MB_OK
    cc:
        invoke MessageBox, NULL, addr str3, addr str3, MB_OK
START:
    FLD @aux3
        FSTP z@main
    FLD z@main
    FLD 3.000000
    FADD 
    FSTP @aux1
    FLD @aux1
    FSTP x@main
    FLD x@main
    FLD z@main
    FSUB 
    FSTP @aux2
    FLD @aux2
    FSTP y@main
END START