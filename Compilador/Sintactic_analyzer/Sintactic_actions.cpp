#include "Sintactic_actions.h"
#include "../Output/Logger.h"
void Sintactic_actions::imprime(string x){
    cout<< x <<endl;
}
/*
void Sintactic_actions::chequearRangoCtePositiva(Symbol_table tablita,string pointer){

}*/
string Sintactic_actions::convert_to_string(char * key){
    string aux ="";
    int longitud = 0;
    while (*key != '\0') {

        longitud++;
        aux = aux + *key;
        printf( "%c\n", *key );	/* Mostramos la letra actual */
        key++;			/* Vamos a la siguiente letra */
    }
    return aux;

}
void Sintactic_actions::negativizarVar(Symbol_table * tablita, char * key ){

    string aux =convert_to_string(key);
    cout<<"aux = " + aux <<endl;
    Symbol_table::Registry a = tablita->removeSymbol(aux);
    aux = "-" + aux;

   tablita->addSymbol(aux,a);
    cout<<"aux = " + aux <<endl;
}
void Sintactic_actions::check_limit(Symbol_table * tablita, char * key){
    int x = 0;
    string aux = convert_to_string(key);

}
void Sintactic_actions::check_division_zero(Symbol_table * tablita, char * key){

    string aux = convert_to_string(key);
    int y = stoi(aux);
    cout<<"ENTRO EN DIVISION POR CERO, VARIABLE Y = " + to_string(y) + " aux = "+ aux <<endl;
    if(y == 0){
        Logger::write("Error: division por cero");
    }

}

void Sintactic_actions::check_list_parametros(){
    cout<<"se llego al check de parametros"<<endl;
    if(contadorParametro>3)
        Logger::write("Error: Se supero la cantidad maxima de parametros." );

    contadorParametro=0;
}


/*
bool Sintactic_actions::checkDivisionCero(string pointer){
    return true;
}*/