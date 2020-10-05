#ifndef COMPILADOR_SYMBOLTABLE_H
#define COMPILADOR_SYMBOLTABLE_H

#include <iostream>
#include <map>
#include "../Sintactico/y.tab.h"
using namespace std;
class SymbolTable {

    public:
            SymbolTable();
            struct Registro{
                int id;
                //En un futuro agregar el tipo
            };
            void addSymbol(string key, Registro registro);

            //Registro getID(string key, Registro reg);
            void printTable();

    private:
            map<string,Registro> tablaDeSimbolos ; // String es la clave, por ejemplo el identifcador hola
};
#endif //COMPILADOR_SYMBOLTABLE_H
