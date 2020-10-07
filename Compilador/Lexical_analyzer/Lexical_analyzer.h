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
                int (*Action)(Lexical_analyzer*, char & c);
            };
            Lexical_analyzer::Transition matrizAS[nro_estados][nro_simbolos];

            map<string, int> reserved_words ;
            void initializeMatrixSA();
            int identify_character(char carac);




    int (*SA00)(Lexical_analyzer*, char &) = {&Semantic_actions::initialize_token}; //00
    int (*SA01)(Lexical_analyzer*, char &) = {&Semantic_actions::add_character}; //01
    int (*SA02)(Lexical_analyzer*, char &) = {&Semantic_actions::discard_character}; //02
    int (*SA03)(Lexical_analyzer*, char &) = {&Semantic_actions::finish_symbol}; //03
    int (*SA04)(Lexical_analyzer*, char &) = {&Semantic_actions::finish_simple_comparator};
    int (*SA05)(Lexical_analyzer*, char &) = {&Semantic_actions::finish_composite_comparator};
    int (*SA06)(Lexical_analyzer*, char &) = {&Semantic_actions::finish_identifier};
    int (*SA07)(Lexical_analyzer*, char &) = {&Semantic_actions::finish_reserved_word};
    int (*SA08)(Lexical_analyzer*, char &) = {&Semantic_actions::finish_longint};
    int (*SA09)(Lexical_analyzer*, char &) = {&Semantic_actions::finish_float};
    int (*SA10)(Lexical_analyzer*, char &) = {&Semantic_actions::finish_constant};
    int (*SA11)(Lexical_analyzer*, char &) = {&Semantic_actions::eof_unexpected};
    int (*SA12)(Lexical_analyzer*, char &) = {&Semantic_actions::error_mensagge};
    int (*SA13)(Lexical_analyzer*, char &) = {&Semantic_actions:: finalizarDivision};




    int (**matrix_SA[nro_estados][nro_simbolos]) (Lexical_analyzer * lex, char & c)= {
            //             L       M      'l'     'f'      D      '.'      +       *       -      '_'     =       <        >     !      "      /       %       $     Literales   BL,TAB,NL  Otro
            /* 0  */  {  &SA00,  &SA00,  &SA00,  &SA00,  &SA00,  &SA00,  &SA03,  &SA03,  &SA03,  &SA00, &SA01,  &SA01,  &SA01, &SA01, &SA01, &SA01,  &SA00,  &SA03,  &SA03,      &SA02,     &SA00    },
            /* 1  */  {  &SA01,  &SA06,  &SA01,  &SA01,  &SA01,  &SA06,  &SA06,  &SA06,  &SA06,  &SA01, &SA06,  &SA06,  &SA06, &SA06, &SA06, &SA06,  &SA06,  &SA06,  &SA06,      &SA06,     &SA06    },
            /* 2  */  {  &SA07,  &SA01,  &SA07,  &SA07,  &SA07,  &SA07,  &SA07,  &SA07,  &SA07,  &SA01, &SA07,  &SA07,  &SA07, &SA07, &SA07, &SA07,  &SA07,  &SA07,  &SA07,      &SA07,     &SA07    },
            /* 3  */  {  &SA10,  &SA10,  &SA10,  &SA10,  &SA01,  &SA01,  &SA10,  &SA10,  &SA10,  &SA01, &SA10,  &SA10,  &SA10, &SA10, &SA10, &SA10,  &SA10,  &SA10,  &SA10,      &SA10,     &SA10    },
            /* 4  */  {  &SA12,  &SA12,  &SA08,  &SA12,  &SA12,  &SA12,  &SA12,  &SA12,  &SA12,  &SA12, &SA12,  &SA12,  &SA12, &SA12, &SA12, &SA12,  &SA12,  &SA12,  &SA12,      &SA12,     &SA00    },
            /* 5  */  {  &SA09,  &SA09,  &SA09,  &SA01,  &SA01,  &SA09,  &SA09,  &SA09,  &SA09,  &SA09, &SA09,  &SA09,  &SA09, &SA09, &SA09, &SA09,  &SA09,  &SA09,  &SA09,      &SA09,     &SA00    },
            /* 6  */  {  &SA12,  &SA12,  &SA12,  &SA12,  &SA12,  &SA12,  &SA01,  &SA12,  &SA01,  &SA12, &SA12,  &SA12,  &SA12, &SA12, &SA12, &SA12,  &SA12,  &SA12,  &SA12,      &SA12,     &SA12    },
            /* 7  */  {  &SA09,  &SA09,  &SA09,  &SA09,  &SA01,  &SA09,  &SA09,  &SA09,  &SA09,  &SA09, &SA09,  &SA09,  &SA09, &SA09, &SA09, &SA09,  &SA09,  &SA09,  &SA09,      &SA09,     &SA09    },
            //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            /* 8  */  {  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04, &SA05,  &SA04,  &SA04, &SA04, &SA04, &SA04,  &SA04,  &SA04,  &SA04,      &SA04,     &SA04    },
            /* 9  */  {  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04, &SA05,  &SA04,  &SA04, &SA04, &SA04, &SA04,  &SA04,  &SA04,  &SA04,      &SA04,     &SA04    },
            /* 10 */  {  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04, &SA05,  &SA04,  &SA04, &SA04, &SA04, &SA04,  &SA04,  &SA04,  &SA04,      &SA04,     &SA04    },
            /* 11 */  {  &SA12,  &SA12,  &SA12,  &SA12,  &SA12,  &SA12,  &SA12,  &SA12,  &SA12,  &SA12, &SA05,  &SA12,  &SA12, &SA12, &SA12, &SA12,  &SA12,  &SA12,  &SA12,      &SA12,     &SA12    },
            /* 12 */  {  &SA01,  &SA01,  &SA01,  &SA01,  &SA01,  &SA01,  &SA01,  &SA01,  &SA01,  &SA01, &SA01,  &SA01,  &SA01, &SA01, &SA03, &SA01,  &SA01,  &SA11,  &SA01,      &SA01,     &SA01    },
            /* 13 */  {  &SA13,  &SA13,  &SA13,  &SA13,  &SA13,  &SA13,  &SA13,  &SA13,  &SA13,  &SA13, &SA13,  &SA13,  &SA13, &SA13, &SA13, &SA02,  &SA02,  &SA13,  &SA13,      &SA13,     &SA13    },
            /* 14 */  {  &SA02,  &SA02,  &SA02,  &SA02,  &SA02,  &SA02,  &SA02,  &SA02,  &SA02,  &SA02, &SA02,  &SA02,  &SA02, &SA02, &SA02, &SA02,  &SA02,  &SA11,  &SA02,      &SA02,     &SA02    },
            /* 15 */  {  &SA02,  &SA02,  &SA02,  &SA02,  &SA02,  &SA02,  &SA02,  &SA02,  &SA02,  &SA02, &SA02,  &SA02,  &SA02, &SA02, &SA02, &SA02,  &SA02,  &SA11,  &SA02,      &SA02,     &SA02    },

    };

    int state_matrix[nro_estados][nro_simbolos] = {
            //           L   M  'l' 'f'  D  '.'  +   *   -  '_'  =   <    >   !   "   /   %   $   Literales   BL,TAB,NL   Otro
            /* 0  */  {  1,  2,  1,  1,  3,  5,  F,  F,  F,  F, 10,  8,   9, 11, 12, 13,  F,  F,  F,          0,          F    },
            /* 1  */  {  1,  F,  1,  F,  1,  F,  F,  F,  F,  1,  F,  F,   F,  F,  F,  F,  F,  F,  F,          F,          F    },
            /* 2  */  {  F,  2,  F,  F,  F,  F,  F,  F,  F,  2,  F,  F,   F,  F,  F,  F,  F,  F,  F,          F,          F    },
            /* 3  */  {  F,  F,  F,  F,  3,  5,  F,  F,  F,  4,  F,  F,   F,  F,  F,  F,  F,  F,  F,          F,          F    },
            /* 4  */  {  F,  F,  F,  F,  F,  F,  F,  F,  F,  F,  F,  F,   F,  F,  F,  F,  F,  F,  F,          F,          F    },
            /* 5  */  {  F,  F,  F,  6,  5,  F,  F,  F,  F,  F,  F,  F,   F,  F,  F,  F,  F,  F,  F,          F,          F    },
            /* 6  */  {  F,  F,  F,  F,  F,  F,  7,  F,  7,  F,  F,  F,   F,  F,  F,  F,  F,  F,  F,          F,          F    },
            /* 7  */  {  F,  F,  F,  F,  7,  F,  F,  F,  F,  F,  F,  F,   F,  F,  F,  F,  F,  F,  F,          F,          F    },
            /* 8  */  {  F,  F,  F,  F,  F,  F,  F,  F,  F,  F,  F,  F,   F,  F,  F,  F,  F,  F,  F,          F,          F    },
            /* 9  */  {  F,  F,  F,  F,  F,  F,  F,  F,  F,  F,  F,  F,   F,  F,  F,  F,  F,  F,  F,          F,          F    },
            /* 10 */  {  F,  F,  F,  F,  F,  F,  F,  F,  F,  F,  F,  F,   F,  F,  F,  F,  F,  F,  F,          F,          F    },
            /* 11 */  {  F,  F,  F,  F,  F,  F,  F,  F,  F,  F,  F,  F,   F,  F,  F,  F,  F,  F,  F,          F,          F    },
            /* 12 */  { 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  12, 12,  F, 12, 12,  F, 12,         12,         12    },
            /* 13 */  {  F,  F,  F,  F,  F,  F,  F,  F,  F,  F,  F,  F,   F,  F,  F,  F, 14,  F,  F,          F,          F    },
            /* 14 */  { 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  14, 14, 14, 14, 15,  0, 14,         14,         14    },
            /* 15 */  { 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  14, 14, 14,  0, 15,  0, 14,         14,         14    },

    };

};
#endif //COMPILADOR_YYLEX_H
