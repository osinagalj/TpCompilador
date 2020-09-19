#include "Lexico/yylex.h"

int main(int argc, char* argv[]){
    //Path lauta
    string path = "C:\\Users\\Lautaro\\Desktop\\Facultad\\Compiladores\\TPcursada\\TpCompilador\\Compilador\\Archivos\\programa.txt";
    //Path nico
    //string path= "C:\\Users\\nicol\\CLionProjects\\tpParaleloCompi\\texto.txt";

    Yylex analizadorLexico(path);

    //El sintactico lo llama muchas veces
    Yylex::Token a = analizadorLexico.getToken();
    cout<<"andaxd"<<endl;
    return 0;
}