#ifndef COMPILADOR_ACCIONESSEMANTICAS_H
#define COMPILADOR_ACCIONESSEMANTICAS_H

//#include "yylex.h"// NO SE PUEDE
class Yylex;

class AccionesSemanticas {

    private:

        int numeroCadena = 0;
    public:
        static void entregarToken(Yylex* lexico, char& c);
        static void checkIdentificador(Yylex* lexico, char& c);

    //Identificadores y constantes
        static void asignarLetra(Yylex* lexico, char& c);
        static void agregarCaracter(Yylex* lexico, char& c);

        static void devolverConstante(Yylex* lexico, char& c);
        static void devolverOperador(Yylex* lexico, char& c);

        static void devolverSeparador(Yylex* lexico, char& c);
        static void notificarFinArchivo(Yylex* lexico, char& c);

        static void devolverIgual(Yylex* lexico, char& c);
        static void devolverMayor(Yylex* lexico, char& c);

        static void devolverMayorIgual(Yylex* lexico, char& c);
        static void devolverMenorIgual(Yylex* lexico, char& c);

    static void devolverMenor(Yylex* lexico, char& c);
    static void devolverAsignacion(Yylex* lexico, char& c);

    static void contLinea(Yylex* lexico, char& c);
    static void mensajeWarning(Yylex* lexico, char& c);

    static void mensajeError(Yylex* lexico, char& c);
    static void finCadena(Yylex* lexico, char& c);

    static void checkearRango(Yylex* lexico, char& c);


    //
};


#endif //COMPILADOR_ACCIONESSEMANTICAS_H
