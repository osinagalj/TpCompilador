#include "AccionesSemanticas.h"
#include "yylex.h"


void AccionesSemanticas::inicializarIdentificador(Yylex* lexico, char& c){
    lexico->cadena = c;
    lexico->aumentarCaracter();
}

void AccionesSemanticas::agregarCaracter(Yylex* lexico, char& c){
    lexico->cadena = lexico->cadena + c;
    lexico->aumentarCaracter();
}

void AccionesSemanticas::devolverIdentificador(Yylex* lexico, char& c){
    lexico->tokenEncontrado();
    lexico->guardarToken(25, "hola");
}

void AccionesSemanticas::entregarToken(Yylex* lexico, char& c){
    lexico->tokenEncontrado();
}

void AccionesSemanticas::devolverConstante(Yylex* lexico, char& c){
}

void AccionesSemanticas::devolverOperador(Yylex* lexico, char& c){
}

void AccionesSemanticas::devolverSeparador(Yylex* lexico, char& c){
}

void AccionesSemanticas::devolverAsignacion(Yylex* lexico, char& c){
}

void AccionesSemanticas::devolverIgual(Yylex* lexico, char& c){
}

void AccionesSemanticas::devolverMayor(Yylex* lexico, char& c){
}

void AccionesSemanticas::devolverMayorIgual(Yylex* lexico, char& c){
}

void AccionesSemanticas::devolverMenor(Yylex* lexico, char& c){
}
void AccionesSemanticas::devolverMenorIgual(Yylex* lexico, char& c){
}
void AccionesSemanticas::finCadena(Yylex* lexico, char& c){
}
void AccionesSemanticas::notificarFinArchivo(Yylex* lexico, char& c){
}
void AccionesSemanticas::mensajeWarning(Yylex* lexico, char& c){

}
void AccionesSemanticas::mensajeError(Yylex* lexico, char& c){
}
