#ifndef COMPILADOR_YYLEX_H
#define COMPILADOR_YYLEX_H4

#include <iostream>
#include <fstream>
#include "AccionesSemanticas.h"
using namespace std;
#include <map>


#define MINUSCULA 0
#define MAYUSCULA 1
#define L_MINUSCULA 2
#define F_MINUSCULA 3
#define DIGITO 4
#define SIMBOLO_PUNTO 5
#define SIGNO_OPERADOR 6
#define SIGNO_RESTA 7
#define GUION_BAJO 8
#define COMPARADOR_IGUAL 9
#define COMPARADOR_MENOR 10
#define COMPARADOR_MAYOR 11
#define SIMBOLO_DISTINTO 12
#define COMILLA 13
#define SIGNO_DIVISION 14
#define SIMBOLO_PORCENTAJE 15
#define LITERALES 16
#define BL_TAB_NL 17
#define SIMBOLO_FIN_DE_ARCHIVO 18
#define OTRO 19


const int  nro_estados = 16;
const int nro_simbolos = 20;

//#include "y.tab.h"

class Yylex{
    public:
        Yylex(string pathArchivo);
        struct Token{
            int id;
            string puntero;
        };
        Token getToken();
        void analizarCodigo();
        string idk;

    private:

        ifstream archivoOrigen;
        void cargarArchivo(string pathArchivo);

        Token t;
        int posicionEnLinea = 0;
        int linea_actual = 0; // para informar errores

        struct Transicion{
            int estado;
            void (*Accion)(Yylex*,char & c);
        };

        bool encontroToken = false;

        Yylex::Transicion matrizAS[nro_estados][nro_simbolos];
        void inicializarMatrizAS();

         string linea;
         string token = "";

         int caracteresAvanzados = 0;
         int estadoNuevo; //indica a que estado me estoy moviendo
         // string tipo="";

        int identificarCaracter(char carac);

        map<string, int> palabrasReservadas;
};
#endif //COMPILADOR_YYLEX_H
