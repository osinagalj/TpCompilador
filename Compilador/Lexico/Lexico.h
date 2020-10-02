#ifndef COMPILADOR_YYLEX_H
#define COMPILADOR_YYLEX_H4

#include <iostream>
#include <fstream>
#include "AccionesSemanticas.h"
#include <map>
#include <string>
#include "../TablaDeSimbolos.h"

#define COLUMNA_MINUSCULA 0
#define COLUMNA_MAYUSCULA 1
#define COLUMNA_L_MINUSCULA 2
#define COLUMNA_F_MINUSCULA 3
#define COLUMNA_DIGITO 4
#define SIMBOLO_PUNTO 5
#define SIGNO_MULTIPLICACION 6
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
#define SIGNO_SUMA 20
#define longIdentificador 21

#define ESTADO_FINAL -1
const int  nro_estados = 17;
const int nro_simbolos = 21;

#include "../y.tab.h"
//si no haces el yacc -d Gramatica.y no te genera el tab.h
using namespace std;


class Yylex{
    public:
            Yylex();
             struct Token{
             int id;
             string punteroTS; //clave para el mapa
             };

             struct Registro{

                 string warning;
             };
             Registro registro;
             Token getToken(string pathArchivo);
             string cadena;
             void guardarToken(int id,string punt);
             void tokenEncontrado();
             void agregarEnTabla(string key, TablaDeSimbolos::Registro r);
             void aumentarCaracter(); //si el caracter leido es valido aumentamos
             int getLinea();
             bool end = false;
             int caracteresAvanzados = 0;
             bool encontroToken = false;
             Token t;
             int estadoNuevo;
             TablaDeSimbolos * tablaSimbolos;
             void guardarEnTS(int id);
    private:
            ifstream archivoOrigen;

            void cargarArchivo(string pathArchivo);



            int linea_actual = 1; // para informar errores
            string linea;
            string token = "";

             //indica la celda para conseguir el nuevo estado
            // string tipo="";
            int estadoActual;
            //Matriz de Transicion de estados
            struct Transicion{
                int estado;
                void (*Accion)(Yylex*,char & c);
            };
            Yylex::Transicion matrizAS[nro_estados][nro_simbolos];

            map<string, int> palabrasReservadas;
            void inicializarMatrizAS();
            int identificarCaracter(char carac);


};
#endif //COMPILADOR_YYLEX_H