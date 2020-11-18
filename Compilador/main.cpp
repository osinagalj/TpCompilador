#include "Sintactic_analyzer/Sintactic_actions.h"
#include "Output/Logger.h"
#include <fstream>
#include "GeneracionDeCodigoIntermedio/Intermediate_code.h" //cambiar
#include <string.h>
using namespace std;
int yylex();
void yyerror(const char *);
#include "Sintactic_analyzer/y.tab.cpp"
void createIndexFile();
/*-----------------------------------------------------------------------------------------------*/
/*-----------------------          Global variables          ------------------------------------*/
/*-----------------------------------------------------------------------------------------------*/
string path = "Compilador\\Testing\\program.txt";
//string path = "Compilador\\Testing\\bug_shadowing";
//string path = "Compilador\\Testing\\bug_scope";
string pathOut = "Compilador\\Output\\out.txt";
string pathIndex = "Compilador\\Output\\indexProgram.txt";
Lexical_analyzer lexical_analyzer;
int Sintactic_actions::number_of_parameters = 0; //contador para las listas de variables
int Intermediate_code::number = 1;
bool Intermediate_code::falloEnCompilacion = false;
list<string> Intermediate_code::list_variables;
list<int> Intermediate_code::pila;
map<int,Terceto> Intermediate_code::list_tercetos;
Lexical_analyzer * Logger::lexico = nullptr;
Symbol_table * Lexical_analyzer::symbolTable= nullptr;
//lauta
string Intermediate_code::ambito_actual = "main";
int Intermediate_code::ambitoAnonimo = 1;

bool Intermediate_code::shadowing = false;

bool Intermediate_code::flagPre=false;
bool Intermediate_code::flagPost=false;
list<Terceto> Intermediate_code::list_tercetos_sin_completar;

list<string> Intermediate_code::pila_procedimientos;
//list<Terceto> Intermediate_code::proc_actual;
map<string,list<Terceto>> Intermediate_code::procedimientos;

list<int> Intermediate_code::listProcedimientosAnidados;



/*charly*/
int Intermediate_code::cantProc = 0;
/*-----------------------------------------------------------------------------------------------*/
/*-----------------------                Main                ------------------------------------*/
/*-----------------------------------------------------------------------------------------------*/
int main(int argc,char** argv)
{
    if (argc > 1){
        path = argv[1];
    }else{
        cout << "No se ingreso ninguna direccion de archivo, se utilizara la direccion del archivo de texto por defecto en la ruta: " + path  << endl << endl;
    }
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
    tabla.clearTable();
    tabla.printTable();
    Intermediate_code::imprimirTercetos();
    Intermediate_code::imprimirListaProc();
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
    cout<<"str = " + str<<endl;
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
