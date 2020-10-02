#ifndef COMPILADOR_ACCIONESSEMANTICAS_H
#define COMPILADOR_ACCIONESSEMANTICAS_H

#include <iostream>
#include "../TablaDeSimbolos.h"
using namespace std;
//#include "yylex.h"// NO SE PUEDE
class Yylex;


class AccionesSemanticas {

    private:
        int numeroCadena = 0;
    public:
        //nuevas
        static void devolverUnico(Yylex* lexico, char& c);
        static void devolverComparadorSimple(Yylex* lexico, char& c);
        static void devolverComparadorCompuesto(Yylex* lexico, char& c);

        static void inicializarToken(Yylex* lexico, char& c);
        static void devolverIdentificador(Yylex* lexico, char& c);
        static void descartarCaracter(Yylex* lexico, char& c);
        static void devolverReservada(Yylex* lexico, char& c);
        static void agregarCaracter(Yylex* lexico, char& c);
        static void devolverEnteroLargo(Yylex* lexico, char& c);
        static void devolverFloat(Yylex* lexico, char& c);
        static void devolverConstante(Yylex* lexico, char& c);
        static void notificarFinArchivoInesperado(Yylex* lexico, char& c);
        static void mensajeError(Yylex* lexico, char& c);

    private:



};


#endif //COMPILADOR_ACCIONESSEMANTICAS_H
