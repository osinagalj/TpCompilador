#include "Sintactic_actions.h"
#include "../Output/Logger.h"

string Sintactic_actions::convert_to_string(char * key){
    string string_key ="";
    int length = 0;
    while (*key != '\0') {
        length++;
        string_key = string_key + * key;
        key++;			                /* go to next letter */
    }
    return string_key;
}
#include <string.h>
char* Sintactic_actions::negativizarVar(Symbol_table * tablita, char * key )
{
    cout<<"Negativiando la var" <<endl;
    string aux =convert_to_string(key);

    Symbol_table::Registry a = tablita->removeSymbol(aux);
    cout<<"id = " << a.id <<" tipo: " << a.Tipo <<endl;
    aux = "-" + aux;

    tablita->addSymbol(aux,a);

    char *cstr = new char[aux.length() + 1];
    strcpy(cstr, aux.c_str());
    return cstr;
}

void Sintactic_actions::check_limit(Symbol_table * tablita, char * key)
{
    string aux = convert_to_string(key);
    double x = stod(aux);
    if(x == 2147483648){
        Logger::write("Warning: variable LONGINT fuera de rango.");
    }

}

void Sintactic_actions::check_division_zero(Symbol_table * tablita, char * key)
{
    string aux = convert_to_string(key);
    int y = stoi(aux);
    if(y == 0){
        Logger::write("Error: division por cero");
    }
}

void Sintactic_actions::check_list_parametros()
{
    if(number_of_parameters>3)
        Logger::write("Error: Se supero la cantidad maxima de parametros." );
    number_of_parameters = 0;
}
