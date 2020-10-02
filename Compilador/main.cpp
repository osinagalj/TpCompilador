#include "Lexico/yylex.h"
#include "AccionesSintactico.h"
#include "TablaDeSimbolos.h"


TablaDeSimbolos * tablaSimbolos;


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
    cout<< "ENTRO 1"<<endl;
   while(!analizadorLexico.end){
       cout<< "ENTRO 2"<<endl;
        Yylex::Token a = analizadorLexico.getToken(path); /* hola $ */
       cout<< "ENTRO 3"<<endl;
        cout << "ID = " + to_string(a.id) + " ";
        cout << a.punteroTS+ " ";
        cout << analizadorLexico.registro.warning;
        cout<<endl;

    }
    cout<< "TABLA DE SIMBOLOS XD"<<endl;
    tablaSimbolos->imprimir();

    return 0;
}