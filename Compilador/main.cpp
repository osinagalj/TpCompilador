#include "Lexico/Lexico.h"
#include "Sintactico/AccionesSintactico.h"
#include "TablaDeSimbolos/TablaDeSimbolos.h"


TablaDeSimbolos * tablaSimbolos;


int yylex();
void yyerror(const char *s);
#include "Sintactico/y.tab.cpp"

Lexico analizadorLexico;
string path = "Compilador\\CasosDePrueba\\programa.txt";
string pathOut = "out.txt";

void yyerror(const char *s){
    cout << s << endl;
}
int yylex(){


    Lexico::Token a = analizadorLexico.getToken(path); /* hola $ */
    cout << "token " + a.punteroTS + " " +to_string(a.id)<<endl;

    return a.id;
}


int main(){
/*
   ofstream archivo_salida;
    archivo_salida.open(path,ofstream::out);
    if(archivo_salida.is_open()){
        cout << "abrio el archivo de salida" << endl;
        exit(1);
    }else{
        cout << "Error al abrir el archivo de salida" << endl;
    }*/
        //El sintactico lo llama muchas veces
        TablaDeSimbolos tabla;
        tablaSimbolos = &tabla;
        analizadorLexico.tablaSimbolos = &tabla;
/*
    while(!analizadorLexico.end) {
        Lexico::Token a = analizadorLexico.getToken(path);
        cout << "token " + a.punteroTS + " " + to_string(a.id) << endl;
    }

*/
    yyparse();



    return 0;
}