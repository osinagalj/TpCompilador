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
                string ambito = "no-defined";
                string uso = "no-defined";
                string tipoToken = "no-defined";
                //otros:
                //Pasaje forma_de_pasaje; // no va

            };

            /*lauta*/
            bool existVariable(string key);
            void clearTable();
            bool estaAlAlcance(string key);

            void addType2(string type,string key,string ambit); //Modifique esto para los ambitos
            /* */

            void setUse(char * key,char * use);
            void addAmbit(string key,string ambit);
            Registry getRegistry(string key);
            void addType(string type,string key,string ambit); //Modifique esto para los ambitos
            Registry removeSymbol(string key);
            void addSymbol(string key, Registry registry);
            void addSymbol2(string key, Registry registry);
            void printTable();
            char * getPointer(string puntero);
            char * getPointer2(string puntero);
    private:
            map<string,Registry> symbol_table ; // String is the key, for ID "hola", "hola" is the key
};

#endif //COMPILADOR_SYMBOL_TABLE_H
