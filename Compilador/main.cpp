//#include "Lexico/Lexico.h"
#include "Sintactico/AccionesSintactico.h"
#include "SymbolTable/SymbolTable.h"
#include "Salida/Logger.h"
#include <fstream>

using namespace std;


SymbolTable * tablaSimbolos;
Lexico * Logger::lexico = nullptr;
SymbolTable * Lexico::symbolTable= nullptr;

Lexico analizadorLexico;
string path = "Compilador\\CasosDePrueba\\programa.txt";
string pathOut = "Compilador\\Salida\\out.txt";

int yylex();
void yyerror(const char *s);
#include "Sintactico/y.tab.cpp"

void yyerror(const char *s){
    cout << s << endl;
}


int yylex() {

    Lexico::Token current_token = analizadorLexico.getToken(path); /* hola $ */
    cout << "token " + current_token.pointerST + " " + to_string(current_token.id) << endl;

    yylval= stoi(current_token.pointerST);

    return current_token.id;
}


int main(){

    Logger::open(pathOut);
    Logger log;
    Logger::lexico = &analizadorLexico;

    SymbolTable tabla;
    tablaSimbolos = &tabla;
    analizadorLexico.symbolTable = &tabla;
    Lexico::symbolTable = &tabla;

    yyparse();
    tablaSimbolos->printTable();
    Logger::close();

    return 0;
}