#include "Sintactic_analyzer/Sintactic_actions.h"
#include "Output//Logger.h"
#include <fstream>
using namespace std;
int yylex();
void yyerror(const char *);
#include "Sintactic_analyzer/y.tab.cpp"

/*-----------------------           variables             ----------------------------------------*/
string path = "Compilador\\Testing\\program.txt";
string pathOut = "Compilador\\Output\\out.txt";
Lexical_analyzer lexical_analyzer;
int Sintactic_actions::number_of_parameters = 0; //contador para las listas de variables
Lexical_analyzer * Logger::lexico = nullptr;
Symbol_table * Lexical_analyzer::symbolTable= nullptr;

/*-----------------------------------------------------------------------------------------------*/
/*-----------------------                Main                ------------------------------------*/
/*-----------------------------------------------------------------------------------------------*/
int main()
{
    Logger::open(pathOut);
    Logger log;
    Logger::lexico = &lexical_analyzer;

    Symbol_table tabla;
    lexical_analyzer.symbolTable = &tabla;
    Lexical_analyzer::symbolTable = &tabla;
    //Execute parser
    yyparse();
    //Finish
    Logger::close();
    tabla.printTable();

    return 0;
}


/*-----------------------------------------------------------------------------------------------*/
/*-----------------------                Functions           ------------------------------------*/
/*-----------------------------------------------------------------------------------------------*/

void yyerror(const char * text)
{
    cout << text << endl;
}

int yylex()
{
    Lexical_analyzer::Token current_token = lexical_analyzer.getToken(path);                //cout << "----------------Token encontrado: " + current_token.pointerST + "    ID: " + to_string(current_token.id) << endl;
    yylval.cadena= lexical_analyzer.symbolTable->getPointer(current_token.pointerST);       //yylval.cadena= &current_token.pointerST[0];
    return current_token.id;
}