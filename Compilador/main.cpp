#include "Lexico/yylex.h"
#include "AccionesSintactico.h"


int yylex();
void yyerror(const char *s);
#include "y.tab.c"

Yylex analizadorLexico;
string path = "Compilador\\Archivos\\programa.txt";

void yyerror(const char *s){
    cout << s << endl;
}
int yylex(){
    Yylex::Token a = analizadorLexico.getToken(path); /* hola $ */
    return a.id;
}


int main(){



    //El sintactico lo llama muchas veces

   while(!analizadorLexico.end){

        Yylex::Token a = analizadorLexico.getToken(path); /* hola $ */

        cout << "ID = " + to_string(a.id) + " ";
        cout << a.punteroTS+ " ";
        cout << analizadorLexico.registro.warning;
        cout<<endl;

    }
    //cout<< analizadorLexico.identificador<<endl;
    return 0;
}