
#ifndef COMPILADOR_SINTACTIC_ACTIONS_H
#define COMPILADOR_SINTACTIC_ACTIONS_H
#include <map>
#include <iostream>
#include "../SymbolTable/Symbol_table.h"
using namespace std;

class Sintactic_actions {

    public:
            static int number_of_parameters;
            //Actions
            static void check_list_parametros();
            static void negativizarVar(Symbol_table * table, char * key);
            static void check_limit(Symbol_table * table, char * key);
            static void  check_division_zero(Symbol_table * table, char * key);

    private:
            static string convert_to_string(char * key);
};



#endif //COMPILADOR_SINTACTIC_ACTIONS_H

