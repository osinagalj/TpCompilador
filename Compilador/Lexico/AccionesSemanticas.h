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
        static void finish_symbol(Lexico* lexico, char& c);
        static void finish_simple_comparator(Lexico* lexico, char& c);
        static void finish_composite_comparator(Lexico* lexico, char& c);

        static void initialize_token(Lexico* lexico, char& c);
        static void finish_identifier(Lexico* lexico, char& c);
        static void discard_character(Lexico* lexico, char& c);
        static void finish_reserved_word(Lexico* lexico, char& c);
        static void add_character(Lexico* lexico, char& c);
        static void finish_longint(Lexico* lexico, char& c);
        static void finish_float(Lexico* lexico, char& c);
        static void finish_constant(Lexico* lexico, char& c);
        static void notificarFinArchivoInesperado(Lexico* lexico, char& c);
        static void error_mensagge(Lexico* lexico, char& c);

    private:



};


#endif //COMPILADOR_ACCIONESSEMANTICAS_H
