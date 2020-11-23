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
    str1 DB "ENTRO EN PROC" , 0 
    str2 DB "FIN DE PROGRAMA" , 0 
    str3 DB "INICIO" , 0 
    str4 DB "INVOCO A PROC RECURSIVO" , 0 
    str5 DB "MULTIPLICA BIEN PERRITO SUCIO" , 0 
    p4@main@procedure_1 DD ?
    x@main DD ?
    _procedure_1@main DD 0
    str6 DB "Error: No esta permitida la recursion en un procedimiento" , 0 
.CODE
    procedure_1@main PROC
        CMP _procedure_1@main, 1
        JE Error
        MOV _procedure_1@main, 1
        invoke MessageBox, NULL, addr str1, addr str1, MB_OK
        MOV EBX,x@main
        ADD EBX,1
        MOV x@main,EBX
        MOV EBX,x@main
        CMP EBX,11
        JLE Label11
        invoke MessageBox, NULL, addr str5, addr str5, MB_OK
        JMP Label13
        Label11:
        CALL procedure_1@main
        Label13:
        ret
        procedure_1@main ENDP 
      Error :
        invoke MessageBox, NULL, addr str6, addr str6, MB_OK
        invoke ExitProcess, 0 
START:
    MOV ECX,8
    MOV x@main,ECX
    invoke MessageBox, NULL, addr str3, addr str3, MB_OK
    invoke MessageBox, NULL, addr str4, addr str4, MB_OK
    CALL procedure_1@main
    invoke MessageBox, NULL, addr str2, addr str2, MB_OK
END START
