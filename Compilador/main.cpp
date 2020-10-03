#include "Lexico/Lexico.h"
#include "Sintactico/AccionesSintactico.h"
#include "TablaDeSimbolos/TablaDeSimbolos.h"


TablaDeSimbolos * tablaSimbolos;


int yylex();
void yyerror(const char *s);
#include "Sintactico/y.tab.c"

Lexico analizadorLexico;
string path = "Compilador\\Archivos\\programa.txt";

void yyerror(const char *s){
    cout << s << endl;
}
int yylex(){
    Lexico::Token a = analizadorLexico.getToken(path); /* hola $ */
    cout << "token " + a.punteroTS + " " +to_string(a.id)<<endl;
    return a.id;
}


int main(){

    //El sintactico lo llama muchas veces
    TablaDeSimbolos tabla;
    tablaSimbolos = &tabla;
    analizadorLexico.tablaSimbolos = &tabla;
 /*
   while(!analizadorLexico.end){

        Lexico::Token a = analizadorLexico.getToken(path);

        cout << "ID = " + to_string(a.id) + " ";
        cout << a.punteroTS + " ";
        cout<<endl;

    }
    tablaSimbolos->imprimir();
   */
    yyparse();
    return 0;
}