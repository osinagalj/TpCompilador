%token ID CTE IF ELSE END_IF THEN OUT FUNC RETURN ULONGINT FLOAT INTEGER DOUBLE WHILE UINT LOOP LONGINT MAYORIGUAL MENORIGUAL IGUAL DISTINTO CADENA DIGITO F_MINUSCLA L_MINUSCULA MAYUSCULA MINUSCULA  PROC
%start programa
%%
programa:
          bloque_sentencia  {AccionesSintactico::imprime();}
;
bloque_sentencia:
	 sentencia {AccionesSintactico::imprime();}
	|bloque_sentencia sentencia {AccionesSintactico::imprime();}
;
sentencia:
	 declarativa {AccionesSintactico::imprime();}
	|ejecutable {AccionesSintactico::imprime();}
	|imprimir {AccionesSintactico::imprime();}
;
declarativa:
	 tipo lista_de_variables {AccionesSintactico::imprime();}
	|procedimiento ';' {AccionesSintactico::imprime();}

;
lista_de_variables:
	ID ',' lista_de_variables {AccionesSintactico::imprime();}
	|ID ';' {AccionesSintactico::imprime();}
;
ejecutable:
	 ID '=' expresion ';'{AccionesSintactico::imprime();}
	|invocacion_proc {AccionesSintactico::imprime();}
	|sentencia_while ';' {AccionesSintactico::imprime();}
	|sentencia_if {AccionesSintactico::imprime();}
;
invocacion_proc:
	 ID '(' parametros ')' ';' {AccionesSintactico::imprime();}

;
parametros:
	 parametros ',' ID {AccionesSintactico::imprime();}
	|ID {AccionesSintactico::imprime();}
;
procedimiento:
	PROC ID '(' lista_de_parametros ')' bloque_sentencia {AccionesSintactico::imprime();}
;
lista_de_parametros:
	 lista_de_parametros ',' tipo ID {AccionesSintactico::imprime();}
	|tipo ID {AccionesSintactico::imprime();}
;
sentencia_if:
	 IF '(' condicion ')' bloque_sentencia END_IF {AccionesSintactico::imprime();}
	|IF '(' condicion ')' bloque_sentencia ELSE bloque_sentencia END_IF {AccionesSintactico::imprime();}

;
sentencia_while:
	 WHILE '(' condicion ')' LOOP bloque_sentencia {AccionesSintactico::imprime();}

;
condicion:
	|expresion IGUAL expresion {AccionesSintactico::imprime();}
	|expresion MENORIGUAL expresion {AccionesSintactico::imprime();}
	|expresion MAYORIGUAL expresion {AccionesSintactico::imprime();}
	|expresion DISTINTO expresion {AccionesSintactico::imprime();}

;
expresion:
	   expresion '+' termino {AccionesSintactico::imprime();}
	  |expresion '-' termino {AccionesSintactico::imprime();}
	  |termino {AccionesSintactico::imprime();}

;
termino:
	 factor {AccionesSintactico::imprime();}
	|termino '/' factor {AccionesSintactico::imprime();}
	|termino '*' factor {AccionesSintactico::imprime();}
;
factor:
	 ID {AccionesSintactico::imprime();}
	|CTE {AccionesSintactico::imprime();}
;

tipo:
	 INTEGER {AccionesSintactico::imprime();}
        |UINT {AccionesSintactico::imprime();}
        |LONGINT {AccionesSintactico::imprime();}
        |ULONGINT {AccionesSintactico::imprime();}
        |FLOAT {AccionesSintactico::imprime();}
        |DOUBLE {AccionesSintactico::imprime();}
;
imprimir:
	OUT '(' CADENA ')' ';' {AccionesSintactico::imprime();}
;
%%