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
    str5 DB "Invocacion de procedure_1" , 0 
    str6 DB "Se realizaran operaciones aritmeticas" , 0 
    str7 DB "Terminaron de declararse las variables" , 0 
    str8 DB "Terminaron el programa" , 0 
    str9 DB "Termino procedure_1" , 0 
    a@main DD ?
    b@main DD ?
    c@main DD ?
    d@main DD ?
    e@main@procedure_1 DD ?
    e@main@procedure_1@procedure_3 DD ?
    e@main@procedure_3 DD ?
    float_negative@main DD ? 
    hola@main DD ?
    longint_negative@main DD ?
    p1@main@procedure_1 DD ?
    p1@main@procedure_1@procedure_3 DD ?
    variable_aux@main@procedure_3@WHILE_1@IF_2 DD ?
    w@main DD ? 
    x@main DD ? 
    y@main DD ? 
    z@main DD ? 
    @aux1 DD 1.000000
    @aux2 DD ? 
    @aux3 DD 5000.000000
    @aux4 DD 3.300000
    @aux5 DD 5000.000000
    @aux6 DD ? 
    @aux7 DD 4.500000
    @aux8 DD 4.200000
    @aux9 DD ? 
    @aux10 DD -7.300000
    str10 DB "Error: Se realizo 2 una division por 0" , 0 
.CODE
    procedure_1@main PROC
        MOV EBX,5
        ADD EBX,7
        MOV e@main@procedure_1,EBX
        MOV EBX,e@main@procedure_1
        CMP EBX,5
        JGE Label23
        invoke MessageBox, NULL, addr str3, addr str3, MB_OK
        JMP Label27
        Label23:
        MOV ECX,longint_negative@main
        SUB ECX,1
        MOV longint_negative@main,ECX
        invoke MessageBox, NULL, addr str4, addr str4, MB_OK
        Label27:
        MOV ECX,2
        SUB ECX,-3
        MOV d@main,ECX
        ret
        procedure_1@main  ENDP
    procedure_3@main@procedure_1 PROC
        MOV ECX,5
        ADD ECX,7
        MOV e@main@procedure_1@procedure_3,ECX
        ret
        procedure_3@main@procedure_1  ENDP
    procedure_3@main PROC
        MOV ECX,2
        MOV e@main@procedure_3,ECX
        Label37:
        JG Label55
        MOV ECX,e@main@procedure_3
        ADD ECX,8
        MOV e@main@procedure_3,ECX
        MOV ECX,200
        ADD ECX,3
        MOV variable_aux@main@procedure_3@WHILE_1@IF_2,ECX
        invoke MessageBox, NULL, addr str2, addr str2, MB_OK
        MOV ECX,12
        MOV e@main@procedure_3,ECX
        JMP Label53
        Label49:
        FLD @aux1
        FLD float_negative@main
        FADD 
        FSTP @aux2
        FLD @aux2
        FSTP float_negative@main
        invoke MessageBox, NULL, addr str1, addr str1, MB_OK
        Label53:
        JMP Label37
        Label55:
        ret
        procedure_3@main ENDP 
START:
    invoke MessageBox, NULL, addr str6, addr str6, MB_OK
    MOV ECX,8
    MOV a@main,ECX
    FLD @aux3
    FSTP x@main
    FLD @aux4
    FLD @aux5
    FADD 
    FSTP @aux6
    FLD @aux6
    FSTP w@main
    MOV EAX , 2
    MOV ECX,3
    MUL ECX
    MOV ECX,EAX
    MOV a@main,ECX
    MOV ECX,5
    MOV c@main,ECX
    MOV ECX,a@main
    SUB ECX,2
    MOV b@main,ECX
    FLD @aux7
    FLD @aux8
    FADD 
    FSTP @aux9
    FLD @aux9
    FSTP w@main
    FLD @aux10
    FSTP float_negative@main
    MOV ECX,-715
    MOV longint_negative@main,ECX
    invoke MessageBox, NULL, addr str7, addr str7, MB_OK
    invoke MessageBox, NULL, addr str5, addr str5, MB_OK
    CALL procedure_1@main
    invoke MessageBox, NULL, addr str9, addr str9, MB_OK
    invoke MessageBox, NULL, addr str8, addr str8, MB_OK
END START
