%token ID CTE IF ELSE END_IF THEN OUT FUNC RETURN ULONGINT FLOAT INT WHILE ERROR LOOP LONGINT MAYORIGUAL MENORIGUAL IGUAL DISTINTO CADENA DIGITO F_MINUSCLA L_MINUSCULA MAYUSCULA MINUSCULA  PROC
%start programa
%%
programa:
          bloque_sentencia
;
bloque_sentencia:
	 sentencia {AccionesSintactico::imprime("bloque_sentencia");}
	|bloque_sentencia sentencia {AccionesSintactico::imprime("bloque_sentencia");}
;
sentencia:
	 declarativa {AccionesSintactico::imprime("declarativa");}
	|ejecutable {AccionesSintactico::imprime("ejecutable");}
	|imprimir {AccionesSintactico::imprime("imprimir");}
;
declarativa:
	 tipo lista_de_variables {AccionesSintactico::imprime("declarativa");}
	|procedimiento ';' {AccionesSintactico::imprime("procedimiento");}

;
lista_de_variables:
	ID ',' lista_de_variables {AccionesSintactico::imprime("lista_variables");}
	|ID ';' {AccionesSintactico::imprime("id de lista");}
;
ejecutable:
	 ID '=' expresion ';'{AccionesSintactico::imprime("expresion");}
	|invocacion_proc {AccionesSintactico::imprime("inv proc");}
	|sentencia_while ';' {AccionesSintactico::imprime("setencia_while");}
	|sentencia_if ';' {AccionesSintactico::imprime("sentencia if");}
;
invocacion_proc:
	 ID '(' parametros ')' ';' {AccionesSintactico::imprime("invocacion proc");}
;
parametros:
	 parametros ',' ID {AccionesSintactico::imprime("parametros");}
	|ID {AccionesSintactico::imprime("id parametros");}
;
procedimiento:
	PROC ID '(' lista_de_parametros ')' '{' bloque_sentencia '}' {AccionesSintactico::imprime("def proc");}
;
lista_de_parametros:
	 lista_de_parametros ',' tipo ID {AccionesSintactico::imprime("lista parametros");}
	|tipo ID {AccionesSintactico::imprime("id listapar");}
;
sentencia_if:
	 IF '(' condicion ')' bloque_sentencia END_IF {AccionesSintactico::imprime("if");}
	|IF '(' condicion ')' bloque_sentencia ELSE bloque_sentencia END_IF {AccionesSintactico::imprime("if else");}

;
sentencia_while:
	 WHILE '(' condicion ')' LOOP '{' bloque_sentencia '}' {AccionesSintactico::imprime("while");}

;
condicion:
	|expresion IGUAL expresion {AccionesSintactico::imprime("igual");}
	|expresion MENORIGUAL expresion {AccionesSintactico::imprime("menorigual");}
	|expresion MAYORIGUAL expresion {AccionesSintactico::imprime("mayorigual");}
	|expresion DISTINTO expresion {AccionesSintactico::imprime("distinto");}

;
expresion:
	   expresion '+' termino {AccionesSintactico::imprime("suma");}
	  |expresion '-' termino {AccionesSintactico::imprime("resta");}
	  |termino {AccionesSintactico::imprime("termino");}

;
termino:
	 factor {AccionesSintactico::imprime("factor");}
	|termino '/' factor {AccionesSintactico::imprime("div");}
	|termino '*' factor {AccionesSintactico::imprime("mult");}
;
factor:
	 ID {AccionesSintactico::imprime("factor");}
	|CTE {AccionesSintactico::imprime("cte");}
;

tipo:
	 INT {AccionesSintactico::imprime("INT");}
        |LONGINT {AccionesSintactico::imprime("LONGINT");}
        |FLOAT {AccionesSintactico::imprime("FLOAT");}
;
imprimir:
	OUT '(' CADENA ')' ';' {AccionesSintactico::imprime("cadena");}
;
%%