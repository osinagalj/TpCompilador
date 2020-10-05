%token  ID CTE FLOAT LONGINT INT
	IF ELSE END_IF OUT
	MAYORIGUAL MENORIGUAL IGUAL DISTINTO CADENA
	WHILE LOOP PROC TRUE FALSE SHADOWING FALSE NA
	ERROR


%start programa

%%
programa:
          bloque_sentencia
;
bloque_sentencia:
	 sentencia {Logger::write("Bloque sentencia");}
	|bloque_sentencia sentencia {Logger::write("Bloque sentencia");}
;
sentencia:
	 declarativa {Logger::write("sentencia ");}
	|ejecutable {Logger::write("sentencia ");}
	|imprimir {Logger::write("sentencia ");}
;
declarativa:
	 tipo lista_de_variables {Logger::write("declarativa");}
	|procedimiento ';'{Logger::write("declarativa");}

;
lista_de_variables:
	ID ',' lista_de_variables {Logger::write("lista_de_variables");}
	|ID ';'{Logger::write("lista_de_variables");}
;
ejecutable:
	 ID '=' expresion ';'{Logger::write("ejecutable");}
	| ID '='  ';'{Logger::write("ejecutable");}
	|invocacion_proc {Logger::write("ejecutable");}
	|sentencia_while ';'{Logger::write("ejecutable");}
	|sentencia_if ';'{Logger::write("ejecutable");}
;
invocacion_proc:
	 ID '(' parametros ')' ';'{Logger::write("invocacion_proc");}
;
parametros:
	 parametros ',' ID {Logger::write("parametros");}
	|ID {Logger::write("parametros");}
;
procedimiento:
	PROC ID '(' lista_de_parametros ')' NA '=' CTE ',' SHADOWING '=' true_false'{' bloque_sentencia '}'  {Logger::write("procedimiento");}

;
true_false:
	     TRUE
	   | FALSE
lista_de_parametros:
	 lista_de_parametros ',' tipo ID {Logger::write("lista_de_parametros");}
	|tipo ID {Logger::write("lista_de_parametros");}

sentencia_if:
	 IF '(' condicion ')' bloque_sentencia END_IF {Logger::write("lista_de_parametros");}
	|IF '(' condicion ')' bloque_sentencia ELSE bloque_sentencia END_IF {Logger::write("lista_de_parametros");}
	|IF '(' condicion ')' bloque_sentencia END_IF error {Logger::write("lista_de_parametros");}
;
sentencia_while:
	 WHILE '(' condicion ')' LOOP '{' bloque_sentencia '}'{Logger::write("lista_de_parametros");}

;
condicion:
	|expresion IGUAL expresion {Logger::write("Condicion igual");}
	|expresion MENORIGUAL expresion {Logger::write("Condicion menorigual");}
	|expresion MAYORIGUAL expresion {Logger::write("Condicion mayorIgual");}
	|expresion DISTINTO expresion {Logger::write("Condicion distinto");}
	|expresion '>' expresion {Logger::write("Condicion de mayor");}
        |expresion '<' expresion {Logger::write("Condicion de menor");}
;
expresion:
	   expresion '+' termino {Logger::write("suma");}
	  |expresion '-' termino {Logger::write("resta");}
	  |termino {Logger::write("termino");}

;
termino:
	 factor{Logger::write("factor");}
	|termino '/' factor /*{if(AccionesSintactico::checkDivisionCero($3){
				Logger::write("division");
				}else{
				Logger::write("Se dividio por cero");} )}*/
	|termino '*' factor {Logger::write("multiplicacion");}

;
factor:
	 ID {Logger::write("ID");}
	|CTE {Logger::write("CTE");}
	|'-' CTE {$$ = -1*$2; Logger::write("- CTE") ; AccionesSintactico::negativizarVar(Lexico::symbolTable,$2);}
	|FLOAT
	|'-' FLOAT //{$$ = -1*$2;Logger::write("- FLOAT") ; AccionesSintactico::negativizarVar(Lexico::symbolTable,$2);}
	|LONGINT  //{$$ = -1*$1;Logger::write("- FLOAT") ; AccionesSintactico::chequearRangoCtePositiva(Lexico::symbolTable,$1);}
        |'-' LONGINT {$$ = -1*$2; Logger::write("- LONGINT"); AccionesSintactico::negativizarVar(Lexico::symbolTable,$2);}
;

tipo:
	 INT {Logger::write("INT");}
        |LONGINT {Logger::write("LONGINT");}
        |FLOAT {Logger::write("FLOAT");}
;
imprimir:
	OUT '(' CADENA ')' ';' {Logger::write("Imprimir out");}
;
%%
