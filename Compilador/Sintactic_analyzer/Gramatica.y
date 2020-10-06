%token  ID CTE FLOAT LONGINT INT STRING
	IF ELSE END_IF OUT
	GREATER_OR_EQUAL LESS_OR_EQUAL EQUAL DIFFERENT
	WHILE LOOP
	PROC TRUE FALSE SHADOWING NA
	ERROR
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
	      tipo lista_de_variables
	    | procedimiento ';'{Logger::write("Declaracion de procedimiento");}
;

lista_de_variables:
		     ID ',' lista_de_variables {Logger::write("lista_de_variables");}
		   | ID ';'
;

ejecutable:
	     ID '=' expresion ';'{Logger::write("Asignacion");}
	   | ID '='  ';'{Logger::write("Error:Asignacion vacia");}
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
	PROC ID '(' lista_de_parametros ')' NA '=' CTE ',' SHADOWING '=' true_false'{' bloque_sentencia '}'

;

true_false:
	     TRUE
	   | FALSE
;

lista_de_parametros:
	 	      lista_de_parametros ',' tipo ID {Logger::write("lista_de_parametros");}
		    | tipo ID
;

sentencia_if:
	       IF '(' condicion ')' bloque_sentencia END_IF
	     | IF '(' condicion ')' bloque_sentencia ELSE bloque_sentencia END_IF
	     | IF '(' condicion ')' bloque_sentencia END_IF error
;

sentencia_while:
	 	WHILE '(' condicion ')' LOOP '{' bloque_sentencia '}'
;

condicion:
	  | expresion EQUAL expresion {Logger::write("Condicion igual");}
	  | expresion DIFFERENT expresion {Logger::write("Condicion distinto");}
	  | expresion LESS_OR_EQUAL expresion {Logger::write("Condicion menorigual");}
	  | expresion GREATER_OR_EQUAL expresion {Logger::write("Condicion mayorIgual");}
	  | expresion '>' expresion {Logger::write("Condicion de mayor");}
          | expresion '<' expresion {Logger::write("Condicion de menor");}
;

expresion:
	   expresion '+' termino {Logger::write("suma");}
	  |expresion '-' termino {Logger::write("resta");}
	  |termino

;

termino:
	 factor
	|termino '/' factor /*{ if(Sintactic_actions::checkDivisionCero($3)){
					Logger::write("division");
				}else{
					Logger::write("Se dividio por cero");} )}*/
	|termino '*' factor
;

factor:
	 ID
	|CTE
	|'-' CTE {$$ = -1*$2;  Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,$2);}
	|FLOAT
	|'-' FLOAT //{$$ = -1*$2; Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,$2);}
	|LONGINT  //{$$ = -1*$1;; Sintactic_actions::chequearRangoCtePositiva(Lexical_analyzer::symbolTable,$1);}
        |'-' LONGINT {$$ = -1*$2; Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,$2);}
;

tipo:
       INT
     | LONGINT
     | FLOAT
;
imprimir:
	 OUT '(' STRING ')' ';' {Logger::write("Detecto sentencia OUT");}
;


%%