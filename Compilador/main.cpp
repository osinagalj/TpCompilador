#include "Lexico/Lexico.h"
#include "Sintactico/AccionesSintactico.h"
#include "TablaDeSimbolos/TablaDeSimbolos.h"


TablaDeSimbolos * tablaSimbolos;


int yylex();
void yyerror(const char *s);
#include "Sintactico/y.tab.cpp"

Lexico analizadorLexico;
string path = "Compilador\\CasosDePrueba\\programa.txt";
string pathOut = "Compilador\\Salida\\out.txt";

void yyerror(const char *s){
    cout << s << endl;
}
int yylex(){


    Lexico::Token a = analizadorLexico.getToken(path); /* hola $ */
    cout << "token " + a.punteroTS + " " +to_string(a.id)<<endl;

    return a.id;
}

void open_file(string path,ifstream origen){

}
int main(){
    ofstream myfile;
    myfile.open (pathOut);
    myfile << "OLA.\n";
    myfile.close();

     //El sintactico lo llama muchas veces
        TablaDeSimbolos tabla;
        tablaSimbolos = &tabla;
        analizadorLexico.tablaSimbolos = &tabla;

    yyparse();



    return 0;
}