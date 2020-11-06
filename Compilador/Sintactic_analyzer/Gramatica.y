%token  ID FLOAT LONGINT INT STRING
	IF ELSE END_IF OUT
	GREATER_OR_EQUAL LESS_OR_EQUAL EQUAL DIFFERENT
	WHILE LOOP
	PROC TRUE FALSE SHADOWING NA
	ERROR
%union {
    int entero = 0;
    char * cadena;
    }

%start programa
%%

programa:
         bloque_sentencia
;

bloque_sentencia:
	 	   sentencia  //se crean tercetos
		 | bloque_sentencia sentencia // se crean tercetos
;

sentencia:
	    declarativa
	  | ejecutable
	  | imprimir
;

declarativa:
	      tipo lista_de_variables {Logger::write("Declaracion de variables");
						chekeosGeneracion::asignar_tipo(Lexical_analyzer::symbolTable,$1.cadena);
	      		      		}
	    | procedimiento ';'{Logger::write("Declaracion de procedimiento");}
	    | lista_de_variables {Logger::write("Error: Falta el tipo en la lista de variables");}
	    // | tipo lista_de_variables asignacion   vemos si se puede mejorar, preguntar al profe si tenemos que permitir esto
	    // int id_3 = 5
;


lista_de_variables:
		     ID ',' lista_de_variables{ char * ambito = "Lista de variables";
		     				chekeosGeneracion::addVariable($1.cadena);
                                                 chekeosGeneracion::convertS2($1.cadena,ambito);
                                                  Lexical_analyzer::symbolTable->setUse($1.cadena,"variable");}
		   | ID ';' {	chekeosGeneracion::addVariable($1.cadena);
		   		char * ambito = "Ultimo ID en lista de variables";
                            	 chekeosGeneracion::convertS2($1.cadena,ambito);
                             Lexical_analyzer::symbolTable->setUse($1.cadena,"variable");}
;

ejecutable:
	     ID '=' expresion ';'{Logger::write("Asignacion");
	      			  chekeosGeneracion::insertar_terceto("=",$1.cadena,$3.cadena);
				  $$.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,$1.cadena,$3.cadena);
	      			  }
	   | ID '='  ';'{Logger::write("Error: Asignacion vacia");}
	   | invocacion_proc {Logger::write("invocacion procedimiento");}
	   | sentencia_while ';'{Logger::write("sentencia while"); chekeosGeneracion::desconcatenarAmbitoAnonimo();}
	   | sentencia_if ';'{Logger::write("sentencia if");chekeosGeneracion::desconcatenarAmbitoAnonimo();}
;

invocacion_proc:
	 ID '(' parametros ')' ';'
;

parametros:
	 parametros ',' ID
	|ID
;

procedimiento:
	 nombre_proc  '(' lista_de_parametros ')' NA '=' LONGINT ',' SHADOWING '=' true_false'{' bloque_sentencia '}' {Sintactic_actions::check_list_parametros();
	    											chekeosGeneracion::eliminarUltimoAmbito();}
	|PROC '(' lista_de_parametros ')' NA '=' LONGINT ',' SHADOWING '=' true_false'{' bloque_sentencia '}' {Logger::write("Error: FALTA ID");chekeosGeneracion::eliminarUltimoAmbito();}
	|nombre_proc '(' lista_de_parametros ')' SHADOWING '=' true_false'{' bloque_sentencia '}' {Logger::write("Error: FALTA ESPECIFICAR VALOR NA");chekeosGeneracion::eliminarUltimoAmbito();}
	|nombre_proc'(' lista_de_parametros ')' NA '=' LONGINT '{' bloque_sentencia '}'  {Logger::write("Error: FALTA ESPECIFICAR VALOR SHADOWING");chekeosGeneracion::eliminarUltimoAmbito();}
	|nombre_proc '(' lista_de_parametros ')' '{' bloque_sentencia '}'  {Logger::write("Error: FALTA ESPECIFICAR LOS VALORES DE NA Y SHADOWING");chekeosGeneracion::eliminarUltimoAmbito();}
;

nombre_proc: PROC ID {	Lexical_analyzer::symbolTable->setUse($2.cadena,"nombre_procedimiento");
			chekeosGeneracion::asignarAmbito(Lexical_analyzer::symbolTable,$2.cadena);
			chekeosGeneracion::concatenarAmbito($2.cadena);}
;

true_false:
	     TRUE
	   | FALSE
;

lista_de_parametros:
	 	      lista_de_parametros ',' tipo ID {Logger::write("lista_de_variables");
	 	       				       Sintactic_actions::number_of_parameters++;
	 	       				       Lexical_analyzer::symbolTable->setUse($4.cadena,"parametro");
						Lexical_analyzer::symbolTable->addType($3.cadena,$4.cadena,chekeosGeneracion::ambito_actual);}
		    | tipo ID {Sintactic_actions::number_of_parameters++;
				Lexical_analyzer::symbolTable->setUse($2.cadena,"parametro");
				Lexical_analyzer::symbolTable->addType($1.cadena,$2.cadena,chekeosGeneracion::ambito_actual);  }

;
/*
sentencia_if:
	       IF '(' condicion ')' THEN cuerpo_then ELSE cuerpo_else END_IF{Logger::write("Sentencia IF");}
	     | IF '(' condicion ')' THEN cuerpo_then ELSE cuerpo_else {Logger::write("Error: FALTA EL END_IF");}
             | IF '(' condicion ')' THEN cuerpo_then END_IF //CREO QUE ESTO ESTA BIEN (IF SIN ELSE)
	     | '(' condicion ')' THEN cuerpo_then ELSE cuerpo_else END_IF {Logger::write("Error: FALTA EL IF");}
	     //averiguar el tema del error, por ejemplo si falta la condicion
;

cuerpo_then : bloque_sentencia
;

cuerpo_else: bloque_sentencia
;
*/


sentencia_if:
	       encabezado_if cuerpo {Logger::write("Sentencia IF");
	       				    }
	     | '(' condicion ')' cuerpo {Logger::write("Error: FALTA EL IF");}
	     //averiguar el tema del error, por ejemplo si falta la condicion
;
encabezado_if: IF '(' condicion ')' {chekeosGeneracion::concatenarAmbitoAnonimo("IF");}
;

cuerpo :  cuerpo_if  ELSE  cuerpo_else  END_IF {//Desapilar
					    //Completar terceto incompleto con el destino de la BI
					    chekeosGeneracion::modificar_terceto(chekeosGeneracion::desapilar(),0);
					    }
	     |cuerpo_if END_IF{//Desapilar
			    //Completar terceto incompleto con el destino de la BI
			    //chekeosGeneracion::modificar_terceto(chekeosGeneracion::desapilar(),1);
			    }
	     |cuerpo_if ELSE cuerpo_else {Logger::write("Error: FALTA EL END_IF");}
;

cuerpo_if: '{' bloque_sentencia '}' {//desapilar
			//completar terceto incompleto con el destino de la bf
			chekeosGeneracion::modificar_terceto(chekeosGeneracion::desapilar(),1);
			//apilar el numero del terceto incompleto (apilo antes porque sino me paso de rango y no lo encuentra)
			chekeosGeneracion::apilar();
			// crear terceto incompleto para la BI
			chekeosGeneracion::insertar_terceto("BI","","");
			}
;

cuerpo_else: '{' bloque_sentencia '}'
;

/*
sentencia_while:
	 	 WHILE '(' condicion ')' LOOP '{' bloque_sentencia '}' {Logger::write("Sentencia WHILE");}
	 	|'(' condicion ')' LOOP '{' bloque_sentencia '}' {Logger::write("Error: FALTA 'WHILE' EN LA SENTENCIA");}
	 	| WHILE '(' condicion ')' '{' bloque_sentencia '}' {Logger::write("Error: FALTA 'LOOP' EN SENTENCIA WHILE");}
;*/

sentencia_while:
         inicio_while '(' condicion ')' LOOP '{' bloque_sentencia '}' {Logger::write("Sentencia WHILE");
         								//(1)desapilar,
         								//(2)completar terceto incompleto.
         								chekeosGeneracion::modificar_terceto(chekeosGeneracion::desapilar(),1);
         								//(3)Desapilo direccion de inicio y creo el terceto BI al inicio
         								chekeosGeneracion::insertar_terceto("BI",to_string(chekeosGeneracion::desapilar()),"");
         								}
         |'(' condicion ')' LOOP '{' bloque_sentencia '}' {Logger::write("Error: FALTA 'WHILE' EN LA SENTENCIA");}
         | inicio_while '(' condicion ')' '{' bloque_sentencia '}' {Logger::write("Error: FALTA 'LOOP' EN SENTENCIA WHILE");}
;

inicio_while:
        WHILE {chekeosGeneracion::concatenarAmbitoAnonimo("WHILE");
        	//apilar terceto de inicio para saber la BI
        	chekeosGeneracion::apilar();
        }
;

condicion:
		// CREAR TERCETO INCOMPLETO PARA LA BF
		// APILAR EL NUMERO DEL TERCETO INCOMPLETO
	   expresion EQUAL expresion {Logger::write("Condicion igual");
	   			     $$.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,$1.cadena,$3.cadena);
				     chekeosGeneracion::insertar_terceto("==",$1.cadena,$3.cadena);
	   			     chekeosGeneracion::apilar();
	   			     chekeosGeneracion::insertar_terceto("BF",to_string(chekeosGeneracion::getNumber()-1),"");}
	  | expresion DIFFERENT  {Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
	  | expresion DIFFERENT expresion {Logger::write("Condicion distinto");
	  				  $$.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,$1.cadena,$3.cadena);
	  				  chekeosGeneracion::insertar_terceto("!=",$1.cadena,$3.cadena);
	  				  chekeosGeneracion::apilar();
				          chekeosGeneracion::insertar_terceto("BF",to_string(chekeosGeneracion::getNumber()-1),"");}
	  | expresion LESS_OR_EQUAL  {Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
	  | expresion LESS_OR_EQUAL expresion {Logger::write("Condicion menorigual");
	  				      $$.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,$1.cadena,$3.cadena);
	  				      chekeosGeneracion::insertar_terceto("<=",$1.cadena,$3.cadena);
	  				      chekeosGeneracion::apilar();
					      chekeosGeneracion::insertar_terceto("BF",to_string(chekeosGeneracion::getNumber()-1),"");}
	  | expresion GREATER_OR_EQUAL {Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
	  | expresion GREATER_OR_EQUAL expresion {Logger::write("Condicion mayorIgual");
	  					$$.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,$1.cadena,$3.cadena);
	  					chekeosGeneracion::insertar_terceto(">=",$1.cadena,$3.cadena);
	  					chekeosGeneracion::apilar();
					        chekeosGeneracion::insertar_terceto("BF",to_string(chekeosGeneracion::getNumber()-1),"");}
	  | expresion '>' expresion {Logger::write("Condicion de mayor");
	  			    $$.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,$1.cadena,$3.cadena);
	  			    chekeosGeneracion::insertar_terceto(">",$1.cadena,$3.cadena);
	  			    chekeosGeneracion::apilar();
				    chekeosGeneracion::insertar_terceto("BF",to_string(chekeosGeneracion::getNumber()-1),"");}
	  | expresion '>' {Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
          | expresion '<' expresion {Logger::write("Condicion de menor");
                                    $$.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,$1.cadena,$3.cadena);
                                    chekeosGeneracion::insertar_terceto("<",$1.cadena,$3.cadena);
                                    chekeosGeneracion::apilar();
				    chekeosGeneracion::insertar_terceto("BF",to_string(chekeosGeneracion::getNumber()-1),"");}
          | expresion '<' {Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
;

expresion:
	   expresion '+' termino {Logger::write("suma");
				  $$.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,$1.cadena,$3.cadena);
	   			}
	  |expresion '-' termino {Logger::write("resta");
	  		 	  $$.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,$1.cadena,$3.cadena);}
	  |termino {$$.cadena = $1.cadena;}

;

termino:
	 factor {$$.cadena = $1.cadena; }
	|termino '/' factor { Sintactic_actions::check_division_zero(Lexical_analyzer::symbolTable,$3.cadena);
			      $$.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,$1.cadena,$3.cadena);}
	|termino '*' factor { $$.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,$1.cadena,$3.cadena);}
;

factor:
	 ID	{ char * ambito = "ambito id";
	 	  chekeosGeneracion::convertS2($1.cadena,ambito);
	 	  $$.cadena= $1.cadena;}
	|FLOAT {$$.cadena= $1.cadena;}
	|'-' FLOAT {$$.cadena= Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,$2.cadena);}
	|LONGINT { Sintactic_actions::check_limit(Lexical_analyzer::symbolTable,$1.cadena);
		   $$.cadena= $1.cadena;}
        |'-' LONGINT { $$.cadena=Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,$2.cadena);}
;

tipo:
       INT { string s = "Int"; $$.cadena = &s[0];}
     | LONGINT { string s = "Longint"; $$.cadena = &s[0];}
     | FLOAT { string s = "Float"; $$.cadena = &s[0];}
;

imprimir:
	  OUT '(' STRING ')' ';' {Logger::write("Detecto sentencia OUT");}
	 |'(' STRING ')' ';' {Logger::write("Error: SE ESPERABA OUT PREVIAMENTE PARA IMPRIMIR");}
	 |OUT '(' ')' ';' {Logger::write("Error: SE ESPERABA CADENA EN LA SENTENCIA OUT");}
;
%%