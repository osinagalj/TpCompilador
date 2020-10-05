#ifndef COMPILADOR_YYLEX_H
#define COMPILADOR_YYLEX_H4

#include <iostream>
#include <fstream>
#include "AccionesSemanticas.h"
#include <map>
#include <string>
#include "../SymbolTable/SymbolTable.h"


#define COLUMN_LOWERCASE 0
#define COLUMN_UPPERCASE 1
#define COLUMN_LOWERCASE_L 2
#define COLUMN_LOWERCASE_F 3
#define COLUMN_DIGIT 4
#define COLUMN_DOT 5                    //'.'
#define COLUMN_MULTIPLICATION 6
#define COLUMN_SUBTRACTION 7            //"-"
#define COLUMN_UNDERSCORE 8             //"_"
#define COLUMN_EQUAL 9
#define COLUMN_LESS 10
#define COLUMN_GREATER 11
#define COLUMN_COLUMN_DIFFERENT 12      //"!"
#define COLUMN_QUOTE 13                 //'"'
#define COLUMN_DIVISION 14
#define COLUMN_PERCENTAGE 15
#define COLUMN_LITERALS 16
#define COLUMN_BL_TAB_NL 17
#define COLUMN_END_FILE 18              //'$' for this case
#define OTHER 19
#define COLUMN_SUM 20

#define longIdentificador 21 //XQ NO ES 20?????????????????

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
                string pointerST; //clave para el mapa
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
             int new_state;
             SymbolTable * symbolTable;
             void saveInST(int id);
    private:
            ifstream source_file;
            void loadFile(string pathArchivo);

            int current_line = 1; // para informar errores
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
