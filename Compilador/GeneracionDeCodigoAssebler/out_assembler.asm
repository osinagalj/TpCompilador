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
    e@main@procedure_3 DD ?
    float_negative@main DD ? 
    longint_negative@main DD ?
    p1@main@procedure_1 DD ?
    variable_aux@main@procedure_3@WHILE_1@IF_2 DD ?
    w@main DD ? 
    x@main DD ? 
    y@main DD ? 
    z@main DD ? 
    @aux1 DD 5000.000000
    @aux2 DD 3.300000
    @aux3 DD 5000.000000
    @aux4 DD ? 
    @aux5 DD 4.500000
    @aux6 DD 4.200000
    @aux7 DD ? 
    @aux8 DD -7.300000
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
    procedure_1@main ENDP
    procedure_3@main:
        MOV ECX,e@main@procedure_3
        MOV ECX,2
        Label33:
        JG Label51
        MOV ECX,e@main@procedure_3
        ADD ECX,8
        MOV e@main@procedure_3,ECX
        MOV ECX,200
        ADD ECX,3
        MOV variable_aux@main@procedure_3@WHILE_1@IF_2,ECX
        invoke MessageBox, NULL, addr str2, addr str2, MB_OK
        MOV ECX,e@main@procedure_3
        MOV ECX,12
        JMP Label49
        Label45:
        MOV ECX,longint_negative@main
        SUB ECX,1
        MOV longint_negative@main,ECX
        invoke MessageBox, NULL, addr str1, addr str1, MB_OK
        Label49:
        JMP Label33
        Label51:
        ret
START:
    invoke MessageBox, NULL, addr str6, addr str6, MB_OK
    MOV ECX,a@main
    MOV ECX,8
    FLD @aux1
    FSTP x@main
    FLD @aux2
    FLD @aux3
    FADD 
    FSTP @aux4
    FLD @aux4
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
    FLD @aux5
    FLD @aux6
    FADD 
    FSTP @aux7
    FLD @aux7
    FSTP w@main
    FLD @aux8
    FSTP float_negative@main
    MOV ECX,longint_negative@main
    MOV ECX,-715
    invoke MessageBox, NULL, addr str7, addr str7, MB_OK
    invoke MessageBox, NULL, addr str5, addr str5, MB_OK
    CALL procedure_1@main
    invoke MessageBox, NULL, addr str9, addr str9, MB_OK
    invoke MessageBox, NULL, addr str8, addr str8, MB_OK
END START
