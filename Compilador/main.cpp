#include "Lexico/yylex.h"

int main(){


    string path = "Compilador\\Archivos\\programa.txt";
    //El sintactico lo llama muchas veces
    Yylex analizadorLexico;
   while(!analizadorLexico.end){

        Yylex::Token a = analizadorLexico.getToken(path);
        cout << "ID = " + to_string(a.id) + " ";
        cout << a.lexema+ " ";
        cout << a.warning<<endl;

    }
    //cout<< analizadorLexico.identificador<<endl;
    return 0;
}