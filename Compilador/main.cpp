#include "Lexico/yylex.h"

int main(){

    string path = "Compilador\\Archivos\\programa.txt";
    //El sintactico lo llama muchas veces
    Yylex analizadorLexico;
    for (int i=0; i<10; i++) {
        Yylex::Token a = analizadorLexico.getToken(path);
        cout << a.id + " ";
        cout << a.lexema+ " ";
        cout << a.warning<<endl;
    }
    //cout<< analizadorLexico.identificador<<endl;
    return 0;
}