.386
.MODEL flat, stdcall
option casemap :none
include \masm32\include\masm32rt.inc
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
    @aux1 DD 5.000000
    @aux2 DD 6.000000
    @aux3 DD 3.000000
    @aux4 DD ? 
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
        JLE Label13
        invoke MessageBox, NULL, addr str1, addr str1, MB_OK
        JMP Label15
        Label13:
        invoke MessageBox, NULL, addr str4, addr str4, MB_OK
        Label15:
    bb:
        invoke MessageBox, NULL, addr str2, addr str2, MB_OK
    cc:
        invoke MessageBox, NULL, addr str3, addr str3, MB_OK
START:
    FLD @aux1
    FSTP z@main
    FLD @aux2
    FLD @aux3
    FADD 
    FSTP @aux4
    FLD @aux4
    FSTP x@main
END START