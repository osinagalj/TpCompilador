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
.code
    aa:
        MOV EBX,a@main
        CMP EBX,14
        JLE Label8
        invoke MessageBox, NULL, addr str1, addr str1, MB_OK
        JMP Label10
        Label8:
        invoke MessageBox, NULL, addr str4, addr str4, MB_OK
        Label10:
        MOV ECX,6
        ADD ECX,3
        MOV c@main,
        MOV EAX,6
        ADD EAX,3
        MOV d@main,
    bb:
        invoke MessageBox, NULL, addr str2, addr str2, MB_OK
    cc:
        invoke MessageBox, NULL, addr str3, addr str3, MB_OK
START:
    invoke MessageBox, NULL, addr str1, addr str1, MB_OK
    JMP Label10
    MOV EDX,6
    ADD EDX,3
    MOV c@main,EDX
    MOV EDX,6
    ADD EDX,3
    MOV d@main,EDX
    invoke MessageBox, NULL, addr str2, addr str2, MB_OK
    MOV EDX,2
    ADD EDX,3
    MOV b@main,EDX
    invoke MessageBox, NULL, addr str3, addr str3, MB_OK
END START