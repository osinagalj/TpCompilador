#ifndef COMPILADOR_SYMBOLTABLE_H
#define COMPILADOR_SYMBOLTABLE_H
#include <iostream>
#include <map>
#include "../Sintactico/y.tab.h"
using namespace std;

class SymbolTable {

    public:
            SymbolTable();
            struct Registry{
                int id;
                //En un futuro agregar el tipo
            };
            void addSymbol(string key, Registry registry);
            void printTable();

    private:
            map<string,Registry> symbol_table ; // String is the key, for ID "hola", "hola" is the key
};

#endif //COMPILADOR_SYMBOLTABLE_H
