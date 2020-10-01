%token ID CTE IF ELSE ENF_IF THEN OUT FUNC RETURN FLOAT WHILE LOOP LONGINT MAYORIGUAL MENORIGUAL IGUAL CADENA DIGITO F_MINUSCLA L_MINUSCULA MAYUSCULA MINUSCULA SIMBOLO_DISTINTO PROC
%start programa
%%
programa:
          sentencias

bloque_sentencia:
	 '{' setencias '}' ';'
	|error ';'

sentencias:
	 sentencia ';'
	|bloque_sentencia ';'
	|sentencias sentencia ';'

sentencia:
	 declarativa
	|ejecutable

declarativa:
	 tipo lista_de_variables
	|procedimiento
	|error ';'

lista_de_variables:
	 lista_de_variables ',' ID
	|ID

ejecutable:
	 ID '=' expresion ';'
	|invocacion_proc ';'
	|sentencia_while ';'
	|setencia_if ';'
	|error ';'

invocacion_proc:
	 ID '(' parametros ')'
	|error ';'

parametros:
	 parametros ',' ID
	|ID

procedimiento:
	PROC ID lista_de_parametros bloque_sentencia {AccionesSintactico::chequeo($3)}
	|error ';'

lista_de_parametros:
	 lista_de_parametros ',' tipo ID
	|tipo ID

sentencia_if:
	 IF '(' condicion ')' bloque_sentencia END_IF
	|IF '(' condicion ')' bloque_sentencia ELSE bloque_sentencia END_IF
	|error ';'

sentencia_while:
	 WHILE '(' condicion ')' LOOP bloque_sentencia
	|WHILE '(' condicion ')' LOOP sentencia
	|error ';'

condicion: //PREGUNTAR QUE ONDA CON LOS BOOLEANOS
	|expresion IGUAL expresion
	|expresion MENORIGUAL expresion
	|expresion MAYORIGUAL expresion
	|expresion SIMBOLO_DISTINTO expresion
	|error ';'

expresion:
	   expresion termino
	  |termino
	  |expresion factor
	  |factor
	  |'(' termino ')'  //PREGUNTAR

termino:
	 factor
	|termino '+' factor
	|termino '-' factor
	|termino '/' factor {AccionesSintactico::notNull($3)}
	|termino '*' factor

factor:
	 ID
	|CTE

tipo:
	 INTEGER
        |UINT
        |LONGINT
        |ULONGINT
        |FLOAT
        |DOUBLE

imprimir:
	OUT '(' CADENA ')'
%%