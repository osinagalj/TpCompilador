#ifndef COMPILADOR_SEMANTIC_ACTIONS_H
#define COMPILADOR_SEMANTIC_ACTIONS_H
#include <iostream>
#include "../SymbolTable/Symbol_table.h"
using namespace std;


class Lexical_analyzer;

class Semantic_actions {

    public:
        //add character
        static int initialize_token(Lexical_analyzer* lexico, char& c);
        static int add_character(Lexical_analyzer* lexico, char& c);
        //discrad character
        static int discard_character(Lexical_analyzer* lexico, char& c);
        //finish token
        static int finalizarDivision(Lexical_analyzer* lexico, char& c);
        static int finish_symbol(Lexical_analyzer* lexico, char& c);
        static int finish_simple_comparator(Lexical_analyzer* lexico, char& c);
        static int finish_composite_comparator(Lexical_analyzer* lexico, char& c);
        static int finish_identifier(Lexical_analyzer* lexico, char& c);
        static int finish_reserved_word(Lexical_analyzer* lexico, char& c);
        static int finish_longint(Lexical_analyzer* lexico, char& c);
        static int finish_float(Lexical_analyzer* lexico, char& c);
        static int finish_constant(Lexical_analyzer* lexico, char& c);
        //errors
        static int eof_unexpected(Lexical_analyzer* lexico, char& c);
        static int error_mensagge(Lexical_analyzer* lexico, char& c);

    private:



};


#endif //COMPILADOR_SEMANTIC_ACTIONS_H
