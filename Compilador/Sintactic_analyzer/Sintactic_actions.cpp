#include "Sintactic_actions.h"

void Sintactic_actions::imprime(string x){
    cout<<x<<endl;
}
/*
void Sintactic_actions::chequearRangoCtePositiva(Symbol_table tablita,string pointer){

}*/

void Sintactic_actions::negativizarVar(Symbol_table * tablita, char * cadena ){
    string aux ="";
    int longitud = 0;
    while (*cadena != '\0') {
        longitud++;
        aux = aux + *cadena;
        printf( "%c\n", *cadena );	/* Mostramos la letra actual */
        cadena++;			/* Vamos a la siguiente letra */
    }

    cout<<"aux = " + aux <<endl;
    aux = "-" + aux;
    cout<<"aux = " + aux <<endl;
    Symbol_table::Registry reg;
    reg.id =1;


    Symbol_table::Registry a = tablita->removeSymbol("711");

    tablita->addSymbol(aux,a);
}


/*
bool Sintactic_actions::checkDivisionCero(string pointer){
    return true;
}*/