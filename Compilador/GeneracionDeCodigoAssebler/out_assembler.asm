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
    str1 DB "Entro en ELSE del while" , 0 
    str2 DB "Entro en IF del while" , 0 
    str3 DB "Entro en el primer IF" , 0 
    str4 DB "Entro en primer ELSE" , 0 
    str5 DB "Se realizaran operaciones aritmeticas" , 0 
    str6 DB "Terminaron de declararse las variables" , 0 
    str7 DB "Terminaron el programa" , 0 
    a@main DD ?
    aux@main@aa@bb DD ?
    b@main DD ?
    c@main DD ?
    d@main DD ?
    e@main@aa DD ?
    e@main@dd DD ? 
    float_negative@main DD ? 
    longint_negative@main DD ?
    p2@main@aa@bb DD ? 
    p4@main@dd DD ? 
    p5@main@dd DD ? 
    variable_aux@main@dd@WHILE_1@IF_2 DD ?
    w@main DD ? 
    x@main DD ? 
    y@main DD ? 
    z@main DD ? 
    @aux1 DD 2.000000
    @aux2 DD 9.000000
    @aux3 DD 8.000000
    @aux4 DD ? 
    @aux5 DD 5000.000000
    @aux6 DD 3.300000
    @aux7 DD 5000.000000
    @aux8 DD ? 
    @aux9 DD 4.500000
    @aux10 DD 4.200000
    @aux11 DD ? 
    @aux12 DD -7.300000
    str8 DB "Error: Se realizo 2 una division por 0" , 0 
.CODE
    aa@main:
        MOV EBX,5
        ADD EBX,7
        MOV e@main@aa,EBX
        MOV EBX,e@main@aa
        CMP EBX,5
        JGE Label27
        invoke MessageBox, NULL, addr str3, addr str3, MB_OK
        JMP Label31
        Label27:
        MOV ECX,longint_negative@main
        SUB ECX,1
        MOV longint_negative@main,ECX
        invoke MessageBox, NULL, addr str4, addr str4, MB_OK
        Label31:
        ret
    bb@main@aa:
        MOV ECX,aux@main@aa@bb
        MOV ECX,longint_negative@main
        ret
    dd@main:
        FLD @aux1
        FSTP e@main@dd
        FLD @aux2
        FSTP p4@main@dd
        Label39:
        JG Label56
        FLD @aux3
        FLD e@main@dd
        FADD 
        FSTP @aux4
        FLD @aux4
        FSTP e@main@dd
        MOV ECX,200
        ADD ECX,3
        MOV variable_aux@main@dd@WHILE_1@IF_2,ECX
        invoke MessageBox, NULL, addr str2, addr str2, MB_OK
        JMP Label54
        Label50:
        MOV ECX,longint_negative@main
        SUB ECX,1
        MOV longint_negative@main,ECX
        invoke MessageBox, NULL, addr str1, addr str1, MB_OK
        Label54:
        JMP Label39
        Label56:
        ret
      Error:
        invoke MessageBox, NULL, addr str8, addr str8, MB_OK
        invoke ExitProcess, 0 
        ret
START:
    invoke MessageBox, NULL, addr str5, addr str5, MB_OK
    MOV ECX,a@main
    MOV ECX,0
    MOV EDX ,0
    MOV EAX , 7
    MOV ECX,a@main
    CMP a@main, 0
    JE Error
    DIV ECX
    MOV b@main,ECX
    FLD @aux5
    FSTP x@main
    FLD @aux6
    FLD @aux7
    FADD 
    FSTP @aux8
    FLD @aux8
    FSTP w@main
    MOV EAX , 2
    MOV ECX,3
    MUL ECX
    MOV ECX,EAX
    MOV a@main,ECX
    MOV ECX,c@main
    MOV ECX,5
    MOV ECX,a@main
    SUB ECX,2
    MOV b@main,ECX
    FLD @aux9
    FLD @aux10
    FADD 
    FSTP @aux11
    FLD @aux11
    FSTP w@main
    FLD @aux12
    FSTP float_negative@main
    MOV ECX,longint_negative@main
    MOV ECX,-715
    MOV ECX,2
    SUB ECX,-3
    MOV d@main,ECX
    invoke MessageBox, NULL, addr str6, addr str6, MB_OK
    invoke MessageBox, NULL, addr str7, addr str7, MB_OK
END START
