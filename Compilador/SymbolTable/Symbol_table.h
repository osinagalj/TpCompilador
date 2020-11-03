#ifndef COMPILADOR_SYMBOL_TABLE_H
#define COMPILADOR_SYMBOL_TABLE_H
#include <iostream>
#include <map>

using namespace std;


enum Pasaje {copia_valor,referencia};
enum Uso  {variable, nombre_de_procedimiento, nombre_de_parametro};//nombre de una clase?
//Incorporar un atributo Uso en la Tabla de Símbolos, indicando el uso del identificador en el programa (variable,
//nombre de procedimiento, nombre de parámetro, etc.).


class Symbol_table {

    public:
            Symbol_table();
            struct Registry{
                int id;
                //En un futuro agregar el tipo
                string Tipo = "no-type";
                string ambito = "";
                Uso Uso;
                //otros:
                Pasaje forma_de_pasaje;

            };

            //Lauta ambito//

            //end lauta ambito

            Registry getRegistry(string key);
            void addType(string type,string key,string ambit);
            Registry removeSymbol(string key);
            void addSymbol(string key, Registry registry);
            void printTable();
            char * getPointer(string puntero);
            char * getPointer2(string puntero);
    private:
            map<string,Registry> symbol_table ; // String is the key, for ID "hola", "hola" is the key
};

#endif //COMPILADOR_SYMBOL_TABLE_H
