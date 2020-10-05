#ifndef COMPILADOR_YYLEX_H
#define COMPILADOR_YYLEX_H4

#include <iostream>
#include <fstream>
#include "AccionesSemanticas.h"
#include <map>
#include <string>
#include "../TablaDeSimbolos/TablaDeSimbolos.h"

#define Estado0 0
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

#include "../Sintactico/y.tab.h"
//si no haces el yacc -d Gramatica.y no te genera el tab.h
using namespace std;


class Lexico{
    public:
            Lexico();
             struct Token{
                int id;
                 string punteroTS; //clave para el mapa
             };

             struct Registro{
                 //tipo en un futuro
                 string warning;
             };
             Registro registro;
             Token getToken(string pathArchivo);
             string cadena;
             void guardarToken(int id,string punt);
             void set_token_found();
             int getIdPalabraReservada();
             void aumentarCaracter(); //si el caracter leido es valido aumentamos
             int get_number_line();
             bool end = false;

             bool token_found = false;
             Token t;
             int estadoNuevo;
             TablaDeSimbolos * tablaSimbolos;
             void guardarEnTS(int id);
    private:
            ifstream source_file;
            void loadFile(string pathArchivo);

            int actual_line = 1; // para informar errores
            int current_character = 0;
            string line;
            int actual_state;

            //Matriz de Transicion de estados
            struct Transition{
                int state;
                void (*Action)(Lexico*,char & c);
            };
            Lexico::Transition matrizAS[nro_estados][nro_simbolos];

            map<string, int> palabrasReservadas;
            void initializeMatrixSA();
            int identify_character(char carac);


};
#endif //COMPILADOR_YYLEX_H
