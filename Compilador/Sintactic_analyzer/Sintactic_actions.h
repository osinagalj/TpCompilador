
#ifndef COMPILADOR_SINTACTIC_ACTIONS_H
#define COMPILADOR_SINTACTIC_ACTIONS_H
#include <map>
#include <iostream>
#include "../SymbolTable/Symbol_table.h"
using namespace std;
class Sintactic_actions {
private:
    //static bool hereda(TablaSimbolos* tabla, string claseHijo, string clasePadre);
   // static void inicializarVariablesDeObjeto(TablaSimbolos* tabla, string objeto, string clase);
    static string convert_to_string(char * key);

public:
    static int contadorParametro;
    static void imprime(string x);

    //static void chequearRangoCtePositiva(Symbol_table tablita,string pointer);
    static void check_list_parametros();
    static void negativizarVar(Symbol_table * tablita, char * key);
    static void check_limit(Symbol_table * tablita, char * key);
    static void  check_division_zero(Symbol_table * tablita, char * key);
};




#endif //COMPILADOR_SINTACTIC_ACTIONS_H

