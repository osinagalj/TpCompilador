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
                string Tipo = "no-type";
                string uso = "no-defined";
                string tipoToken = "no-defined";
                //otros:

            };
            string scope = "@";

            /*lauta*/
            bool existVariable(string key);
            void clearTable();
            void addType2(string type,string key,string ambit); //Modifique esto para los ambitos
            /* */

            void setUse(string key,string use);
            void addAmbit(string key,string ambit);
            Registry getRegistry(string key);
            void addType(string type,string key,string ambit); //Modifique esto para los ambitos
            Registry removeSymbol(string key);
            void addSymbol(string key, Registry registry);

            void printTable();

        map<string,Registry> symbol_table ; // String is the key, for ID "hola", "hola" is the key

private:

};

#endif //COMPILADOR_SYMBOL_TABLE_H
