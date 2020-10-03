%token ID CTE IF ELSE END_IF THEN OUT FUNC RETURN ULONGINT FLOAT INTEGER DOUBLE WHILE UINT LOOP LONGINT MAYORIGUAL MENORIGUAL IGUAL DISTINTO CADENA DIGITO F_MINUSCLA L_MINUSCULA MAYUSCULA MINUSCULA  PROC
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
	ID ',' lista_de_variables {AccionesSintactico::imprime("lista variables");}
	|ID ';' {AccionesSintactico::imprime("identificador");}
;
ejecutable:
	 ID '=' expresion ';' {AccionesSintactico::imprime("ejecutable");}
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
	PROC ID '(' lista_de_parametros ')' bloque_sentencia
;
lista_de_parametros:
	 lista_de_parametros ',' tipo ID
	|tipo ID
;
sentencia_if:
	 IF '(' condicion ')' bloque_sentencia END_IF {AccionesSintactico::imprime("IF");}
	|IF '(' condicion ')' bloque_sentencia ELSE bloque_sentencia END_IF {AccionesSintactico::imprime("ELSE IF");}

;
sentencia_while:
	 WHILE '(' condicion ')' LOOP bloque_sentencia

;
condicion:
	|expresion IGUAL expresion
	|expresion MENORIGUAL expresion
	|expresion MAYORIGUAL expresion
	|expresion DISTINTO expresion

;
expresion:
	   expresion '+' termino
	  |expresion '-' termino
	  |termino

;
termino:
	 factor
	|termino '/' factor
	|termino '*' factor
;
factor:
	 ID {AccionesSintactico::imprime("factor");}
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