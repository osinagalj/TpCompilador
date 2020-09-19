#include "AccionesSemanticas.h"

/*
void AccionesSemanticas::nuevaLinea(AnalizadorLexico* lexico, char& c){
    lexico->contadorLineas++;
}*/

void asignarLetra(Yylex* lexico, char& c){
    if (c == '\r') return; //En casos de Strings se puede llegar a llamar con Carriage Return, pero lo ignoramos
    //->idk = lexico->idk + c;

}