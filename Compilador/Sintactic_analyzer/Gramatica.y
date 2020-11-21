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
						Intermediate_code::declare_variable_list(Lexical_analyzer::symbolTable,$1.cadena);
	      		      		}
	    | procedimiento ';'{Logger::write("Declaracion de procedimiento"); Intermediate_code::shadowing = false;}
	    | lista_de_variables {Logger::write("Error: Falta el tipo en la lista de variables");}
	    // | tipo lista_de_variables asignacion   vemos si se puede mejorar, preguntar al profe si tenemos que permitir esto

;


lista_de_variables:
		     ID ',' lista_de_variables{
		     	Intermediate_code::addVariable($1.cadena);
		     	string s = "variable";
                        Intermediate_code::setUse(Lexical_analyzer::symbolTable,$1.cadena,&s[0]);}
		   | ID ';' {
		   	Intermediate_code::addVariable($1.cadena);
		   	string s = "variable";
                        Intermediate_code::setUse(Lexical_analyzer::symbolTable,$1.cadena,&s[0]);}
;

ejecutable:
	     ID '=' expresion ';'{
	    	Logger::write("Asignacion");
	    	$$.cadena = Intermediate_code::asignarTipo(Lexical_analyzer::symbolTable,$1.cadena,$3.cadena);
		Intermediate_code::generarAsignacionTercetos(Lexical_analyzer::symbolTable,$1.cadena);
		}
	   | ID '='  ';'{Logger::write("Error: Asignacion vacia");}
	   | invocacion_proc {Logger::write("invocacion procedimiento");}
	   | sentencia_while ';'{Logger::write("sentencia while"); Intermediate_code::desconcatenarAmbitoAnonimo();}
	   | sentencia_if ';'{Logger::write("sentencia if");Intermediate_code::desconcatenarAmbitoAnonimo();}
;

invocacion_proc:
	 ID '(' parametros ')' ';' {Intermediate_code::check_scope(Lexical_analyzer::symbolTable,$1.cadena);
	 			    Intermediate_code::insertar_terceto("Call",$1.cadena,"");}
;

parametros:
	 parametros ',' ID {Intermediate_code::check_scope(Lexical_analyzer::symbolTable,$3.cadena);}
	|ID {Intermediate_code::check_scope(Lexical_analyzer::symbolTable,$1.cadena);}
;

procedimiento:
	 nombre_proc NA '=' LONGINT ',' SHADOWING '=' true_false'{' bloque_sentencia '}' {
	    	Intermediate_code::eliminarUltimoAmbito();
		Intermediate_code::check_NA($4.cadena);
		Intermediate_code::desapilarProc();
	 }
	|PROC '(' lista_de_parametros ')' NA '=' LONGINT ',' SHADOWING '=' true_false'{' bloque_sentencia '}' {
		Logger::write("Error: FALTA ID");
		Intermediate_code::eliminarUltimoAmbito();
		Intermediate_code::check_NA($7.cadena);
	}
	|nombre_proc '(' lista_de_parametros ')' SHADOWING '=' true_false'{' bloque_sentencia '}' {
		Logger::write("Error: FALTA ESPECIFICAR VALOR NA");
		Intermediate_code::eliminarUltimoAmbito();
	}
	|nombre_proc'(' lista_de_parametros ')' NA '=' LONGINT '{' bloque_sentencia '}'  {
		Logger::write("Error: FALTA ESPECIFICAR VALOR SHADOWING");
		Intermediate_code::eliminarUltimoAmbito();
		Intermediate_code::check_NA($7.cadena);
	}
	|nombre_proc '(' lista_de_parametros ')' '{' bloque_sentencia '}'  {
		Logger::write("Error: FALTA ESPECIFICAR LOS VALORES DE NA Y SHADOWING");
		Intermediate_code::eliminarUltimoAmbito();
	}




nombre_proc: encabezado '(' lista_de_parametros ')' {
			Sintactic_actions::check_list_parametros();
			$$.cadena=$1.cadena;
			}
	    |encabezado '(' ')' {
		$$.cadena=$1.cadena;
	    }
;
encabezado:
	PROC ID{
		Intermediate_code::apilarProc($2.cadena);
        	Intermediate_code::insertarProc();
		$$.cadena=$2.cadena;
		string s = "nombre_proc";
		Intermediate_code::setUse(Lexical_analyzer::symbolTable,$2.cadena,&s[0]);
		Intermediate_code::concatenarAmbito($2.cadena);
		Intermediate_code::set_ambit(Lexical_analyzer::symbolTable,$2.cadena);
		Intermediate_code::agregarAnidado();
	}
;

true_false:
	     TRUE { Intermediate_code::shadowing = true;}
	   | FALSE { Intermediate_code::shadowing = false;}
;

lista_de_parametros:
	 	      lista_de_parametros ',' tipo ID {
	 	      	   Logger::write("lista_de_variables");
	 	     	   Sintactic_actions::number_of_parameters++;

	 	 	   Intermediate_code::setUse(Lexical_analyzer::symbolTable,$4.cadena,"parametro");
			   Lexical_analyzer::symbolTable->addType2($3.cadena,$4.cadena,Intermediate_code::ambito_actual);
		      }
		    | tipo ID {
		    	   Sintactic_actions::number_of_parameters++;
			   Intermediate_code::setUse(Lexical_analyzer::symbolTable,$2.cadena,"parametro");
			   Lexical_analyzer::symbolTable->addType2($1.cadena,$2.cadena,Intermediate_code::ambito_actual);
		      }
;

sentencia_if:
	       encabezado_if cuerpo {Logger::write("Sentencia IF");}
	     | '(' condicion ')' cuerpo {Logger::write("Error: FALTA EL IF");} //averiguar el tema del error, por ejemplo si falta la condicion

;

encabezado_if: IF '(' condicion ')' {Intermediate_code::concatenarAmbitoAnonimo("IF");}
;

cuerpo :  cuerpo_if  ELSE  cuerpo_else  END_IF {//Desapilar
					    //Completar terceto incompleto con el destino de la BI
					    Intermediate_code::modificar_terceto(Intermediate_code::desapilar(),0);
					    Intermediate_code::insertar_terceto("Label"+to_string(Intermediate_code::getNumber()),"IF","");
					    }
	     |cuerpo_if END_IF{//Desapilar
			    //Completar terceto incompleto con el destino de la BI
			    //Intermediate_code::modificar_terceto(Intermediate_code::desapilar(),1);
			    }
	     |cuerpo_if ELSE cuerpo_else {Logger::write("Error: FALTA EL END_IF");}
;

cuerpo_if: '{' bloque_sentencia '}' {//desapilar
			//completar terceto incompleto con el destino de la bf
			Intermediate_code::modificar_terceto(Intermediate_code::desapilar(),1);
			//apilar el numero del terceto incompleto (apilo antes porque sino me paso de rango y no lo encuentra)
			Intermediate_code::apilar();
			// crear terceto incompleto para la BI
			Intermediate_code::insertar_terceto("BI","","");
			Intermediate_code::insertar_terceto("Label"+to_string(Intermediate_code::getNumber()),"IF","");
			}
;

cuerpo_else: '{' bloque_sentencia '}'
;



sentencia_while:
         inicio_while '(' condicion ')' LOOP '{' bloque_sentencia '}' {Logger::write("Sentencia WHILE");
         								//(1)desapilar,
         								//(2)completar terceto incompleto.
         								Intermediate_code::modificar_terceto(Intermediate_code::desapilar(),1);
         								//(3)Desapilo direccion de inicio y creo el terceto BI al inicio
         								Intermediate_code::insertar_terceto("BI",to_string(Intermediate_code::desapilar()),"");
									Intermediate_code::insertar_terceto("Label"+to_string(Intermediate_code::getNumber()),"WHILE","");

         								}
         |'(' condicion ')' LOOP '{' bloque_sentencia '}' {Logger::write("Error: FALTA 'WHILE' EN LA SENTENCIA");}
         | inicio_while '(' condicion ')' '{' bloque_sentencia '}' {Logger::write("Error: FALTA 'LOOP' EN SENTENCIA WHILE");}
;

inicio_while:
        	WHILE {
        		Intermediate_code::concatenarAmbitoAnonimo("WHILE");
        		//apilar terceto de inicio para saber la BI
        		Intermediate_code::apilar();
        		Intermediate_code::insertar_terceto("Label"+to_string(Intermediate_code::getNumber()),"WHILE","");
        	}
;

condicion:

	   expresion comparador expresion {
	           $$.cadena = Intermediate_code::asignarTipo(Lexical_analyzer::symbolTable,$1.cadena,$3.cadena);
		   Intermediate_code::expresionComparadorExpresion(Lexical_analyzer::symbolTable,$3.cadena);
	   }
	  | expresion comparador  {Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
;
comparador:
	EQUAL {Intermediate_code::generar_comparador("==");}
	|DIFFERENT{Intermediate_code::generar_comparador("!=");}
	|LESS_OR_EQUAL { Intermediate_code::generar_comparador("<=");}
	|GREATER_OR_EQUAL {Intermediate_code::generar_comparador(">=");}
	|'>' {Intermediate_code::generar_comparador(">");}
	|'<' {Intermediate_code::generar_comparador("<");}
;


expresion:
	   expresion '+' termino {
	    	$$.cadena = Intermediate_code::asignarTipo(Lexical_analyzer::symbolTable,$1.cadena,$3.cadena);
		Intermediate_code::expresionMenosTermino(Lexical_analyzer::symbolTable,"+",$3.cadena);
	   }

	  |expresion '-' termino {
		$$.cadena = Intermediate_code::asignarTipo(Lexical_analyzer::symbolTable,$1.cadena,$3.cadena);
		Intermediate_code::expresionMenosTermino(Lexical_analyzer::symbolTable,"-",$3.cadena);
	   }

	  |termino {$$.cadena = $1.cadena;}

;

termino:
	 factor{
	 	$$.cadena= $1.cadena;
		Intermediate_code::terminoFactor(Lexical_analyzer::symbolTable,$1.cadena);
	 }

	|termino '/' factor {
			      Sintactic_actions::check_division_zero(Lexical_analyzer::symbolTable,$3.cadena);
       			      $$.cadena = Intermediate_code::asignarTipo(Lexical_analyzer::symbolTable,$1.cadena,$3.cadena);
			      Intermediate_code::terminoDivididoFactor(Lexical_analyzer::symbolTable,"/",$3.cadena);
	 }

	|termino '*' factor {
	    			Sintactic_actions::check_division_zero(Lexical_analyzer::symbolTable,$3.cadena);
           			 $$.cadena = Intermediate_code::asignarTipo(Lexical_analyzer::symbolTable,$1.cadena,$3.cadena);
				Intermediate_code::terminoDivididoFactor(Lexical_analyzer::symbolTable,"*",$3.cadena);
	}
;
factor:
	 ID {
	     $$.cadena= $1.cadena;
	     Intermediate_code::check_scope(Lexical_analyzer::symbolTable,$1.cadena);
	 }

	|FLOAT {
	     $$.cadena= $1.cadena;
	     Intermediate_code::check_scope(Lexical_analyzer::symbolTable,$1.cadena);
	}

	|'-' FLOAT {
	     Intermediate_code::check_scope(Lexical_analyzer::symbolTable,$2.cadena);
	     $$.cadena= Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,$2.cadena);
	}

	|LONGINT {
		Intermediate_code::check_scope(Lexical_analyzer::symbolTable,$1.cadena);
		Sintactic_actions::check_limit(Lexical_analyzer::symbolTable,$1.cadena);
		$$.cadena= $1.cadena;
	}
        |'-' LONGINT { Intermediate_code::check_scope(Lexical_analyzer::symbolTable,$2.cadena);
        	$$.cadena=Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,$2.cadena);}
;

tipo:
       INT { string s = "Int"; $$.cadena = &s[0];}
     | LONGINT { string s = "Longint"; $$.cadena = &s[0];}
     | FLOAT { string s = "Float"; $$.cadena = &s[0];}
;

imprimir:
	  OUT '(' STRING ')' ';' {Logger::write("Detecto sentencia OUT");
	  			Intermediate_code::insertar_terceto("OUT",$3.cadena,"");

	  				}
	 |'(' STRING ')' ';' {Logger::write("Error: SE ESPERABA OUT PREVIAMENTE PARA IMPRIMIR");}
	 |OUT '(' ')' ';' {Logger::write("Error: SE ESPERABA CADENA EN LA SENTENCIA OUT");}
;
%%