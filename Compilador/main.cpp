//#include "Lexical_analyzer/Lexical_analyzer.h"
#include "Sintactico/Sintactic_actions.h"
#include "SymbolTable/Symbol_table.h"
#include "Output//Logger.h"
#include <fstream>
using namespace std;
int yylex();
void yyerror(const char *s);
#include "Sintactico/y.tab.cpp"

/*-----------------------           variables             ----------------------------------------*/
string path = "Compilador\\Testing\\program.txt";
string pathOut = "Compilador\\Output\\out.txt";
Lexical_analyzer lexical_analyzer;
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

    yyparse();
    //tablaSimbolos->printTable();
    Logger::close();

    return 0;
}


/*-----------------------------------------------------------------------------------------------*/
/*-----------------------                Functions           ------------------------------------*/
/*-----------------------------------------------------------------------------------------------*/

void yyerror(const char *s)
{
    cout << s << endl;
}

int yylex()
{
    Lexical_analyzer::Token current_token = lexical_analyzer.getToken(path);
    cout << "token " + current_token.pointerST + " " + to_string(current_token.id) << endl;
    return current_token.id;
}