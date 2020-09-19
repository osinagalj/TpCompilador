#include "AccionesSemanticas.h"
#include "yylex.h"


void AccionesSemanticas::inicializarIdentificador(Yylex* lexico, char& c){
    lexico->identificador = c;
}
void AccionesSemanticas::agregarLetra(Yylex* lexico, char& c){
    lexico->identificador = lexico->identificador + c;
}

void AccionesSemanticas::devolverIdentificador(Yylex* lexico, char& c){
}
void AccionesSemanticas::entregarToken(Yylex* lexico, char& c){
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
