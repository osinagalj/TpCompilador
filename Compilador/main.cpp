#include "Lexico/Lexico.h"
#include "AccionesSintactico.h"
#include "TablaDeSimbolos.h"


TablaDeSimbolos * tablaSimbolos;


int yylex();
void yyerror(const char *s);
#include "y.tab.c"

Lexico analizadorLexico
;
string path = "Compilador\\Archivos\\programa.txt";

void yyerror(const char *s){
    cout << s << endl;
}
int yylex(){
    Lexico::Token a = analizadorLexico.getToken(path); /* hola $ */
    return a.id;
}


int main(){

    //El sintactico lo llama muchas veces
    TablaDeSimbolos tabla;
    tablaSimbolos = &tabla;

    analizadorLexico.tablaSimbolos = &tabla;

   while(!analizadorLexico.end){

        Lexico::Token a = analizadorLexico.getToken(path); /* hola $ */

        cout << "ID = " + to_string(a.id) + " ";
        cout << a.punteroTS + " ";
        cout << analizadorLexico.registro.warning;
        cout<<endl;

    }
    tablaSimbolos->imprimir();

    return 0;
}