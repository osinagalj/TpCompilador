#include "Sintactic_analyzer/Sintactic_actions.h"
#include "Output//Logger.h"
#include <fstream>
using namespace std;
int yylex();
void yyerror(const char *);
#include "Sintactic_analyzer/y.tab.cpp"
void createIndexFile();
/*-----------------------------------------------------------------------------------------------*/
/*-----------------------          Global variables          ------------------------------------*/
/*-----------------------------------------------------------------------------------------------*/
string path = "Compilador\\Testing\\program.txt";
string pathOut = "Compilador\\Output\\out.txt";
string pathIndex = "Compilador\\Output\\indexProgram.txt";
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

    createIndexFile();

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

void createIndexFile(){
    ofstream indexFile;
    ifstream Entrada;
    Entrada.open(path,ifstream::in);
    indexFile.open(pathIndex,ofstream::out);
    if(!indexFile.is_open()) {
        cout << "Error al abrir el archivo de código fuente" << endl;
        exit(1);
    }else{
        string line = "";
        int i = 1;
        while(!Entrada.eof()){
            getline(Entrada,line);
            indexFile << to_string(i) + ":      "+ line + "\n";
            i++;
        }

    }
}