//#include "Lexico/Lexico.h"
#include "Sintactico/AccionesSintactico.h"
#include "TablaDeSimbolos/TablaDeSimbolos.h"
#include "Salida/Logger.h"

TablaDeSimbolos * tablaSimbolos;
Lexico * Logger::lexico = nullptr;
Lexico analizadorLexico;
string path = "Compilador\\CasosDePrueba\\programa.txt";
string pathOut = "Compilador\\Salida\\out.txt";


void yyerror(const char *s){
    cout << s << endl;
}
int yylex() {
    Lexico::Token a = analizadorLexico.getToken(path); /* hola $ */
    cout << "token " + a.punteroTS + " " + to_string(a.id) << endl;

    return a.id;
}
#include "Sintactico/y.tab.cpp"

int main(){

    Logger::open(pathOut);
    Logger log;
    Logger::lexico = &analizadorLexico;

    TablaDeSimbolos tabla;
    tablaSimbolos = &tabla;
    analizadorLexico.tablaSimbolos = &tabla;

    yyparse();

    Logger::close();

    return 0;
}