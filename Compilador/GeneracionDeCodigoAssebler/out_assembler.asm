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
    str1 DB "cadena de caracteres 1" , 0 
    str2 DB "cadena de caracteres 2" , 0 
    a@main DD ?
    b@main DD ?
    c@main DD ?
    d@main DD ?
    e@main@aa DD ? 
    e@main@dd DD ? 
    float_negative@main DD ? 
    float_negative@main@aa@bb DD ? 
    longint_negative@main DD ?
    p1@main@aa DD ? 
    p2@main@aa@bb DD ? 
    p4@main@dd DD ? 
    p5@main@dd DD ? 
    variable_kaka@main@dd@WHILE_1@IF_2 DD ?
    w@main DD ? 
    x@main DD ? 
    y@main DD ? 
    z@main DD ? 
    @aux1 DD ? 
    @aux2 DD 2.000000
    @aux3 DD ? 
    @aux4 DD 5000.000000
    @aux5 DD 3.300000
    @aux6 DD 5000.000000
    @aux7 DD ? 
    @aux8 DD 4.500000
    @aux9 DD 4.200000
    @aux10 DD ? 
    @aux11 DD -7.300000
    str3 DB "Error: Se realizo 2 una division por 0" , 0 
.CODE
    aa@main:
        invoke MessageBox, NULL, addr str1, addr str1, MB_OK
        JMP Label24
        Label21:
        FLD float_negative@main
        FLD 1.000000
        FSUB 
        FSTP @aux1
        FLD @aux1
        FSTP float_negative@main
        Label24:
        ret
    bb@main@aa:
        ret
    dd@main:
        FLD @aux2
        FSTP e@main@dd
        Label30:
        JG Label42
        invoke MessageBox, NULL, addr str2, addr str2, MB_OK
        JMP Label40
        Label37:
        FLD float_negative@main
        FLD 1.000000
        FSUB 
        FSTP @aux3
        FLD @aux3
        FSTP float_negative@main
        Label40:
        JMP Label30
        Label42:
        ret
      Error:
        invoke MessageBox, NULL, addr str3, addr str3, MB_OK
        invoke ExitProcess, 0 
        ret
START:
    MOV EBX,a@main
    MOV EBX,3
    FLD @aux4
    FSTP x@main
    FLD @aux5
    FLD @aux6
    FADD 
    FSTP @aux7
    FLD @aux7
    FSTP w@main
    MOV EAX , 2
    MOV EBX,3
    MUL EBX
    MOV EBX,EAX
    MOV a@main,EBX
    MOV EBX,c@main
    MOV EBX,5
    MOV EBX,a@main
    SUB EBX,2
    MOV b@main,EBX
    FLD @aux8
    FLD @aux9
    FADD 
    FSTP @aux10
    FLD @aux10
    FSTP w@main
    FLD @aux11
    FSTP float_negative@main
    MOV EBX,longint_negative@main
    MOV EBX,-715
    MOV EBX,2
    SUB EBX,-3
    MOV d@main,EBX
END START
