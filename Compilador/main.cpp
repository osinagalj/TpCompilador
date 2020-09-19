#include "Lexico/yylex.h"

int main(){

    string path = "Compilador\\Archivos\\programa.txt";
    Yylex analizadorLexico(path);

    //El sintactico lo llama muchas veces
    Yylex::Token a = analizadorLexico.getToken();
    cout<<"andaxd"<<endl;

    cout<< analizadorLexico.identificador<<endl;
    return 0;
}