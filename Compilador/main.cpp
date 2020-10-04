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


int main(){
    ifstream archivo_salida;
    archivo_salida.open(pathOut,ifstream::in);
    if(archivo_salida.fail()){
        cout << "Error al abrir el archivo de salida" << endl;
        exit(1);
    }else{
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
    }

    return 0;
}