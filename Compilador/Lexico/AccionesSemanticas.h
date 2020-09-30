#ifndef COMPILADOR_ACCIONESSEMANTICAS_H
#define COMPILADOR_ACCIONESSEMANTICAS_H

//#include "yylex.h"// NO SE PUEDE
class Yylex;


class AccionesSemanticas {

    private:
        int numeroCadena = 0;
    public:
        static void inicializarToken(Yylex* lexico, char& c);
        static void devolverIdentificador(Yylex* lexico, char& c);
        static void descartarComentario(Yylex* lexico, char& c);
        static void devolverReservada(Yylex* lexico, char& c);
        static void agregarCaracter(Yylex* lexico, char& c);
        static void devolverSuma(Yylex* lexico, char& c);
        static void devolverResta(Yylex* lexico, char& c);
        static void devolverDivision(Yylex* lexico, char& c);
        static void devolverEnteroLargo(Yylex* lexico, char& c);
        static void devolverFloat(Yylex* lexico, char& c);
        static void devolverConstante(Yylex* lexico, char& c);
        static void devolverOperador(Yylex* lexico, char& c);
        static void devolverLiteral(Yylex* lexico, char& c);
        static void notificarFinArchivoInesperado(Yylex* lexico, char& c);

        static void entregarFinArchivo(Yylex* lexico, char& c);
        static void devolverAsignacion(Yylex* lexico, char& c);
        //Comparadores
        static void devolverDistinto(Yylex* lexico, char& c);
        static void devolverIgual(Yylex* lexico, char& c);
        static void devolverMayor(Yylex* lexico, char& c);
        static void devolverMayorIgual(Yylex* lexico, char& c);
        static void devolverMenor(Yylex* lexico, char& c);
        static void devolverMenorIgual(Yylex* lexico, char& c);
        static void finCadena(Yylex* lexico, char& c);

        //Mensajes de alerta
        static void mensajeWarning(Yylex* lexico, char& c);
        static void mensajeError(Yylex* lexico, char& c);

};


#endif //COMPILADOR_ACCIONESSEMANTICAS_H
