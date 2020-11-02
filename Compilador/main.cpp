#include "Sintactic_analyzer/Sintactic_actions.h"
#include "Output/Logger.h"
#include <fstream>
#include "GeneracionDeCodigoIntermedio/chekeosGeneracion.h" //cambiar
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
int chekeosGeneracion::number = 0;
bool chekeosGeneracion::falloEnCompilacion = false;
list<string> chekeosGeneracion::list_variables;
Lexical_analyzer * Logger::lexico = nullptr;
Symbol_table * Lexical_analyzer::symbolTable= nullptr;

/*-----------------------------------------------------------------------------------------------*/
/*-----------------------                Main                ------------------------------------*/
/*-----------------------------------------------------------------------------------------------*/


/* Name Mangling
 *  //Ambito A
 *  int x;
 *  void fun(){
 *      //Ambito B
 *      if(){
 *          //Ambito D
 *          int z;
 *          x:= 25 + z;
 *      }
 *  }
 *
    Buscar x:A:B:D
        No está  Buscar x:A:B
                No está  Buscar x:A 

    Buscar z:A:B:D
 *
 * --Tenemos que tener una variable ambito, y concatenarla cada vez que se entre en un nuevo ambito.
 * -- metodo de concatenar el ambito
 * -- metodo de eliminar el ultimo ambito, para cuando se sale del ambito
 */

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
#include <stdio.h>
#include <string.h>

int yylex()
{
    Lexical_analyzer::Token current_token = lexical_analyzer.getToken(path);                //cout << "----------------Token encontrado: " + current_token.pointerST + "    ID: " + to_string(current_token.id) << endl;
    string str = current_token.pointerST;       //yylval.cadena= &current_token.pointerST[0];

    char *cstr = new char[str.length() + 1];
    strcpy(cstr, str.c_str());
    yylval.cadena = cstr;
    //yylval.cadena= lexical_analyzer.symbolTable->getPointer(current_token.pointerST);
    //    char * aux  ;
    //    aux = &pointer[0];
    //    return aux;

    return current_token.id;
}

void createIndexFile()
{
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