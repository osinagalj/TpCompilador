#ifndef COMPILADOR_YYLEX_H
#define COMPILADOR_YYLEX_H4

#include "Lexical_analyzer_header.h"

class Lexical_analyzer{
    public:
            Lexical_analyzer();
             struct Token{
                int id;
                string pointerST; //clave para el mapa
             };

             Token getToken(string path);
             string word;
             void save_token(int id,string punt);
             void set_token_found();
             int get_reserved_word();
             void increase_character(); //si el caracter leido es valido aumentamos
             int get_number_line();
             bool end = false;
             bool token_found = false;
             Token t;

             static Symbol_table * symbolTable;
             void save_in_ST(int id);
    private:
            ifstream source_file;
            void loadFile(string pathArchivo);

            int current_line = 1; // para informar errores
            int current_character = 0;
            string line;
            int actual_state;
            int new_state;
            //Matriz de Transicion de estados
            struct Transition{
                int state;
                void (*Action)(Lexical_analyzer*, char & c);
            };
            Lexical_analyzer::Transition matrizAS[nro_estados][nro_simbolos];

            map<string, int> reserved_words ;
            void initializeMatrixSA();
            int identify_character(char carac);


};
#endif //COMPILADOR_YYLEX_H
