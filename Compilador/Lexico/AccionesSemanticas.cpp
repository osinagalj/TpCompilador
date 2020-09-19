#include "AccionesSemanticas.h"
#include "yylex.h"

/*
void AccionesSemanticas::nuevaLinea(AnalizadorLexico* lexico, char& c){
    lexico->contadorLineas++;
}*/

void AccionesSemanticas::asignarLetra(Yylex* lexico, char& c){
    if (c == '\r') return;
    lexico->idk = "kaka";
}