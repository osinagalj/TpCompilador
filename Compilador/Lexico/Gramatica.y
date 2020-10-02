%token ID CTE IF ELSE END_IF THEN OUT FUNC RETURN ULONGINT FLOAT INTEGER DOUBLE WHILE UINT LOOP LONGINT MAYORIGUAL MENORIGUAL IGUAL CADENA DIGITO F_MINUSCLA L_MINUSCULA MAYUSCULA MINUSCULA SIMBOLO_DISTINTO PROC
%start programa
%%
programa:
          bloque_sentencia
;

bloque_sentencia:
	 sentencia
	|bloque_sentencia sentencia
;

sentencia:
	 declarativa
	|ejecutable
	|imprimir
;
declarativa:
	 tipo lista_de_variables
	|procedimiento ';'

;
lista_de_variables:
	ID ',' lista_de_variables
	|ID ';'
;
ejecutable:
	 ID '=' expresion ';'
	|invocacion_proc
	|sentencia_while ';'
	|sentencia_if

;
invocacion_proc:
	 ID '(' parametros ')' ';'

;
parametros:
	 parametros ',' ID
	|ID
;
procedimiento:
	PROC ID '(' lista_de_parametros ')' bloque_sentencia {AccionesSintactico::chequeo($3)}

;
lista_de_parametros:
	 lista_de_parametros ',' tipo ID
	|tipo ID
;
sentencia_if:
	 IF '(' condicion ')' bloque_sentencia END_IF
	|IF '(' condicion ')' bloque_sentencia ELSE bloque_sentencia END_IF

;
sentencia_while:
	 WHILE '(' condicion ')' LOOP bloque_sentencia

;
condicion: //PREGUNTAR QUE ONDA CON LOS BOOLEANOS
	|expresion IGUAL expresion
	|expresion MENORIGUAL expresion
	|expresion MAYORIGUAL expresion
	|expresion SIMBOLO_DISTINTO expresion

;
expresion:
	   expresion '+' termino
	  |expresion '-' termino
	  |termino

;
termino:
	 factor
	|termino '/' factor {AccionesSintactico::notNull($3)}
	|termino '*' factor
;
factor:
	 ID
	|CTE
;

tipo:
	 INTEGER
        |UINT
        |LONGINT
        |ULONGINT
        |FLOAT
        |DOUBLE
;
imprimir:
	OUT '(' CADENA ')' ';'
;
%%