#ifndef COMPILADOR_YYLEX_H
#define COMPILADOR_YYLEX_H4

#include "Lexical_analyzer_header.h"

class Lexical_analyzer{
    public:
            Lexical_analyzer();
            bool end = false;
            bool token_found = false;
            int actual_state;
            string word;                    // Token not finalized
            static Symbol_table * symbolTable;

            //TOKEN
            struct Token{
                int id;
                string pointerST;           //key of the map
            };
             Token t;
             Token getToken(string path);   //Called by yylex()

             int get_number_line();
             void set_token_found();
             int get_reserved_word();
             void increase_character();     //if the character read is valid we increase
             void save_in_ST(int id);
             void save_token(int id,string punt);
    private:
            ifstream source_file;
            string line;
            int current_line = 1;            // to report errors and warnings
            int current_character = 0;
            int new_state;
            map<string, int> reserved_words ;

            int identify_character(char carac);
            void loadFile(string pathArchivo);


            //MATRIX SA
            int (*SA00)(Lexical_analyzer*, char &) = {&Semantic_actions::initialize_token};             //00
            int (*SA01)(Lexical_analyzer*, char &) = {&Semantic_actions::add_character};                //01
            int (*SA02)(Lexical_analyzer*, char &) = {&Semantic_actions::discard_character};            //02
            int (*SA03)(Lexical_analyzer*, char &) = {&Semantic_actions::finish_symbol};                //03
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

            int (**matrix_SA[nro_estados][nro_simbolos]) (Lexical_analyzer * lexicalAnalyzer, char & c)= {
                //             L       M      'l'     'f'      D      '.'      +       *       -      '_'     =       <        >     !      "      /       %       $     Literales   BL,TAB,NL  Otro
                /* 0  */  {  &SA00,  &SA00,  &SA00,  &SA00,  &SA00,  &SA00,  &SA03,  &SA03,  &SA03,  &SA00, &SA01,  &SA01,  &SA01, &SA01, &SA01, &SA01,  &SA12,  &SA03,  &SA03,      &SA02,     &SA12    },
                /* 1  */  {  &SA01,  &SA06,  &SA01,  &SA01,  &SA01,  &SA06,  &SA06,  &SA06,  &SA06,  &SA01, &SA06,  &SA06,  &SA06, &SA06, &SA06, &SA06,  &SA06,  &SA06,  &SA06,      &SA06,     &SA06    },
                /* 2  */  {  &SA07,  &SA01,  &SA07,  &SA07,  &SA07,  &SA07,  &SA07,  &SA07,  &SA07,  &SA01, &SA07,  &SA07,  &SA07, &SA07, &SA07, &SA07,  &SA07,  &SA07,  &SA07,      &SA07,     &SA07    },
                /* 3  */  {  &SA10,  &SA10,  &SA10,  &SA10,  &SA01,  &SA01,  &SA10,  &SA10,  &SA10,  &SA01, &SA10,  &SA10,  &SA10, &SA10, &SA10, &SA10,  &SA10,  &SA10,  &SA10,      &SA10,     &SA10    },
                /* 4  */  {  &SA12,  &SA12,  &SA08,  &SA12,  &SA12,  &SA12,  &SA12,  &SA12,  &SA12,  &SA12, &SA12,  &SA12,  &SA12, &SA12, &SA12, &SA12,  &SA12,  &SA12,  &SA12,      &SA12,     &SA00    },
                /* 5  */  {  &SA09,  &SA09,  &SA09,  &SA01,  &SA01,  &SA09,  &SA09,  &SA09,  &SA09,  &SA09, &SA09,  &SA09,  &SA09, &SA09, &SA09, &SA09,  &SA09,  &SA09,  &SA09,      &SA09,     &SA00    },
                /* 6  */  {  &SA12,  &SA12,  &SA12,  &SA12,  &SA12,  &SA12,  &SA01,  &SA12,  &SA01,  &SA12, &SA12,  &SA12,  &SA12, &SA12, &SA12, &SA12,  &SA12,  &SA12,  &SA12,      &SA12,     &SA12    },
                /* 7  */  {  &SA09,  &SA09,  &SA09,  &SA09,  &SA01,  &SA09,  &SA09,  &SA09,  &SA09,  &SA09, &SA09,  &SA09,  &SA09, &SA09, &SA09, &SA09,  &SA09,  &SA09,  &SA09,      &SA09,     &SA09    },
                /* 8  */  {  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04, &SA05,  &SA04,  &SA04, &SA04, &SA04, &SA04,  &SA04,  &SA04,  &SA04,      &SA04,     &SA04    },
                /* 9  */  {  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04, &SA05,  &SA04,  &SA04, &SA04, &SA04, &SA04,  &SA04,  &SA04,  &SA04,      &SA04,     &SA04    },
                /* 10 */  {  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04,  &SA04, &SA05,  &SA04,  &SA04, &SA04, &SA04, &SA04,  &SA04,  &SA04,  &SA04,      &SA04,     &SA04    },
                /* 11 */  {  &SA12,  &SA12,  &SA12,  &SA12,  &SA12,  &SA12,  &SA12,  &SA12,  &SA12,  &SA12, &SA05,  &SA12,  &SA12, &SA12, &SA12, &SA12,  &SA12,  &SA12,  &SA12,      &SA12,     &SA12    },
                /* 12 */  {  &SA01,  &SA01,  &SA01,  &SA01,  &SA01,  &SA01,  &SA01,  &SA01,  &SA01,  &SA01, &SA01,  &SA01,  &SA01, &SA01, &SA03, &SA01,  &SA01,  &SA11,  &SA01,      &SA01,     &SA01    },
                /* 13 */  {  &SA13,  &SA13,  &SA13,  &SA13,  &SA13,  &SA13,  &SA13,  &SA13,  &SA13,  &SA13, &SA13,  &SA13,  &SA13, &SA13, &SA13, &SA02,  &SA02,  &SA13,  &SA13,      &SA13,     &SA13    },
                /* 14 */  {  &SA02,  &SA02,  &SA02,  &SA02,  &SA02,  &SA02,  &SA02,  &SA02,  &SA02,  &SA02, &SA02,  &SA02,  &SA02, &SA02, &SA02, &SA02,  &SA02,  &SA11,  &SA02,      &SA02,     &SA02    },
                /* 15 */  {  &SA02,  &SA02,  &SA02,  &SA02,  &SA02,  &SA02,  &SA02,  &SA02,  &SA02,  &SA02, &SA02,  &SA02,  &SA02, &SA02, &SA02, &SA02,  &SA02,  &SA11,  &SA02,      &SA02,     &SA02    },

             };

             int states_matrix_SA[nro_estados][nro_simbolos] = {
            //           L   M  'l' 'f'  D  '.'  +   *   -  '_'  =   <    >   !   "   /   %   $   Literales   BL,TAB,NL   Otro
            /* 0  */  {  1,  2,  1,  1,  3,  5,  F,  F,  F,  F, 10,  8,   9, 11, 12, 13,  F,  F,  F,          0,          F    },
            /* 1  */  {  1,  F,  1,  1,  1,  F,  F,  F,  F,  1,  F,  F,   F,  F,  F,  F,  F,  F,  F,          F,          F    },
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
