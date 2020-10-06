#ifndef COMPILADOR_SYMBOL_TABLE_H
#define COMPILADOR_SYMBOL_TABLE_H
#include <iostream>
#include <map>
#include "../Sintactic_analyzer/y.tab.h"
using namespace std;

class Symbol_table {

    public:
            Symbol_table();
            struct Registry{
                int id;
                //En un futuro agregar el tipo
            };
            void addSymbol(string key, Registry registry);
            void printTable();
            char * getPuntero(string puntero);
    private:
            map<string,Registry> symbol_table ; // String is the key, for ID "hola", "hola" is the key
};

#endif //COMPILADOR_SYMBOL_TABLE_H
