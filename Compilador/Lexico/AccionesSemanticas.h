#ifndef COMPILADOR_ACCIONESSEMANTICAS_H
#define COMPILADOR_ACCIONESSEMANTICAS_H

#include <iostream>
#include "../SymbolTable/SymbolTable.h"



using namespace std;
//#include "Lexico.h"// NO SE PUEDE
class Lexico;


class AccionesSemanticas {

    private:
        int numeroCadena = 0;
    public:
        //nuevas
        static void devolverUnico(Lexico* lexico, char& c);
        static void devolverComparadorSimple(Lexico* lexico, char& c);
        static void devolverComparadorCompuesto(Lexico* lexico, char& c);

        static void inicializarToken(Lexico* lexico, char& c);
        static void devolverIdentificador(Lexico* lexico, char& c);
        static void descartarCaracter(Lexico* lexico, char& c);
        static void devolverReservada(Lexico* lexico, char& c);
        static void agregarCaracter(Lexico* lexico, char& c);
        static void devolverEnteroLargo(Lexico* lexico, char& c);
        static void devolverFloat(Lexico* lexico, char& c);
        static void devolverConstante(Lexico* lexico, char& c);
        static void notificarFinArchivoInesperado(Lexico* lexico, char& c);
        static void mensajeError(Lexico* lexico, char& c);

    private:



};


#endif //COMPILADOR_ACCIONESSEMANTICAS_H
