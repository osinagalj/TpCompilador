//#include "Lexico/Lexico.h"
#include "Sintactico/AccionesSintactico.h"
#include "SymbolTable/SymbolTable.h"
#include "Salida/Logger.h"

SymbolTable * tablaSimbolos;
Lexico * Logger::lexico = nullptr;
Lexico analizadorLexico;
string path = "Compilador\\CasosDePrueba\\programa.txt";
string pathOut = "Compilador\\Salida\\out.txt";


void yyerror(const char *s){
    cout << s << endl;
}
int yylex() {
    Lexico::Token current_token = analizadorLexico.getToken(path); /* hola $ */
    cout << "token " + current_token.pointerST + " " + to_string(current_token.id) << endl;

    return current_token.id;
}
#include "Sintactico/y.tab.cpp"

int main(){

    Logger::open(pathOut);
    Logger log;
    Logger::lexico = &analizadorLexico;

    SymbolTable tabla;
    tablaSimbolos = &tabla;
    analizadorLexico.symbolTable = &tabla;

    yyparse();
    tablaSimbolos->printTable();
    Logger::close();

    return 0;
}