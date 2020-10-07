%token  ID FLOAT LONGINT INT STRING
	IF ELSE END_IF OUT
	GREATER_OR_EQUAL LESS_OR_EQUAL EQUAL DIFFERENT
	WHILE LOOP
	PROC TRUE FALSE SHADOWING NA
	ERROR
%union {
    int entero=0;
    char * cadena;
    }

%start programa
%%

programa:
         bloque_sentencia
;

bloque_sentencia:
	 	   sentencia
		 | bloque_sentencia sentencia
;

sentencia:
	    declarativa
	  | ejecutable
	  | imprimir
;

declarativa:
	      tipo lista_de_variables {Logger::write("Declaracion de variables");}
	    | procedimiento ';'{Logger::write("Declaracion de procedimiento");}
	    | lista_de_variables {Logger::write("Error: Falta el tipo en la lista de variables");}
;

lista_de_variables:
		     ID ',' lista_de_variables
		   | ID ';'
;

ejecutable:
	     ID '=' expresion ';'{Logger::write("Asignacion");}
	   | ID '='  ';'{Logger::write("Error: Asignacion vacia");}
	   | invocacion_proc {Logger::write("invocacion procedimiento");}
	   | sentencia_while ';'{Logger::write("sentencia while");}
	   | sentencia_if ';'{Logger::write("sentencia if");}
;

invocacion_proc:
	 ID '(' parametros ')' ';'
;

parametros:
	 parametros ',' ID
	|ID
;

procedimiento:
	 PROC ID '(' lista_de_parametros ')' NA '=' LONGINT ',' SHADOWING '=' true_false'{' bloque_sentencia '}' {Sintactic_actions::check_list_parametros();}
	|PROC '(' lista_de_parametros ')' NA '=' LONGINT ',' SHADOWING '=' true_false'{' bloque_sentencia '}' {Logger::write("Error: FALTA ID");}
	|PROC ID '(' lista_de_parametros ')' SHADOWING '=' true_false'{' bloque_sentencia '}' {Logger::write("Error: FALTA ESPECIFICAR VALOR NA");}
	|PROC ID '(' lista_de_parametros ')' NA '=' LONGINT '{' bloque_sentencia '}'  {Logger::write("Error: FALTA ESPECIFICAR VALOR SHADOWING");}
	|PROC ID '(' lista_de_parametros ')' '{' bloque_sentencia '}'  {Logger::write("Error: FALTA ESPECIFICAR LOS VALORES DE NA Y SHADOWING");}
;

true_false:
	     TRUE
	   | FALSE
;

lista_de_parametros:
	 	      lista_de_parametros ',' tipo ID {Logger::write("lista_de_variables"); Sintactic_actions::number_of_parameters++;}
		    | tipo ID {Sintactic_actions::number_of_parameters++;}
;

sentencia_if:
	       IF '(' condicion ')' bloque_sentencia END_IF {Logger::write("Sentencia IF");}
	     | IF '(' condicion ')' bloque_sentencia {Logger::write("Error: FALTA END_IF");}
	     | IF '(' condicion ')' bloque_sentencia ELSE bloque_sentencia END_IF {Logger::write("Sentencia IF-ELSE");}
	     | IF '(' condicion ')' bloque_sentencia ELSE bloque_sentencia {Logger::write("Error: FALTA END_IF");}
	     | '(' condicion ')' bloque_sentencia END_IF {Logger::write("Error: FALTA EL IF");}

;

sentencia_while:
	 	 WHILE '(' condicion ')' LOOP '{' bloque_sentencia '}' {Logger::write("Sentencia WHILE");}
	 	|'(' condicion ')' LOOP '{' bloque_sentencia '}' {Logger::write("Error: FALTA 'WHILE' EN LA SENTENCIA");}
	 	| WHILE '(' condicion ')' '{' bloque_sentencia '}' {Logger::write("Error: FALTA 'LOOP' EN SENTENCIA WHILE");}
;

condicion:
	   expresion EQUAL expresion {Logger::write("Condicion igual");}
	  | expresion DIFFERENT  {Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
	  | expresion DIFFERENT expresion {Logger::write("Condicion distinto");}
	  | expresion LESS_OR_EQUAL  {Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
	  | expresion LESS_OR_EQUAL expresion {Logger::write("Condicion menorigual");}
	  | expresion GREATER_OR_EQUAL {Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
	  | expresion GREATER_OR_EQUAL expresion {Logger::write("Condicion mayorIgual");}
	  | expresion '>' expresion {Logger::write("Condicion de mayor");}
	  | expresion '>' {Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
          | expresion '<' expresion {Logger::write("Condicion de menor");}
          | expresion '<' {Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
;

expresion:
	   expresion '+' termino {Logger::write("suma");}
	  |expresion '-' termino {Logger::write("resta");}
	  |termino

;

termino:
	 factor
	|termino '/' factor { Sintactic_actions::check_division_zero(Lexical_analyzer::symbolTable,$3.cadena);}
	|termino '*' factor
;

factor:
	 ID
	|FLOAT
	|'-' FLOAT { Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,$2.cadena);}
	|LONGINT { Sintactic_actions::check_limit(Lexical_analyzer::symbolTable,$1.cadena);}
        |'-' LONGINT { Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,$2.cadena);}
;

tipo:
       INT
     | LONGINT
     | FLOAT
;

imprimir:
	  OUT '(' STRING ')' ';' {Logger::write("Detecto sentencia OUT");}
	 |'(' STRING ')' ';' {Logger::write("Error: SE ESPERABA OUT PREVIAMENTE PARA IMPRIMIR");}
	 |OUT '(' ')' ';' {Logger::write("Error: SE ESPERABA CADENA EN LA SENTENCIA OUT");}
;
%%