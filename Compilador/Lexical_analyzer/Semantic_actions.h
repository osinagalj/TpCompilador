#ifndef COMPILADOR_SEMANTIC_ACTIONS_H
#define COMPILADOR_SEMANTIC_ACTIONS_H
#include <iostream>
#include "../SymbolTable/Symbol_table.h"
using namespace std;


class Lexical_analyzer;

class Semantic_actions {

    public:
        //add character
        static void initialize_token(Lexical_analyzer* lexico, char& c);
        static void add_character(Lexical_analyzer* lexico, char& c);
        //discrad character
        static void discard_character(Lexical_analyzer* lexico, char& c);
        //finish token
        static void finalizarDivision(Lexical_analyzer* lexico, char& c);
        static void finish_symbol(Lexical_analyzer* lexico, char& c);
        static void finish_simple_comparator(Lexical_analyzer* lexico, char& c);
        static void finish_composite_comparator(Lexical_analyzer* lexico, char& c);
        static void finish_identifier(Lexical_analyzer* lexico, char& c);
        static void finish_reserved_word(Lexical_analyzer* lexico, char& c);
        static void finish_longint(Lexical_analyzer* lexico, char& c);
        static void finish_float(Lexical_analyzer* lexico, char& c);
        static void finish_constant(Lexical_analyzer* lexico, char& c);
        //errors
        static void eof_unexpected(Lexical_analyzer* lexico, char& c);
        static void error_mensagge(Lexical_analyzer* lexico, char& c);

    private:



};


#endif //COMPILADOR_SEMANTIC_ACTIONS_H
