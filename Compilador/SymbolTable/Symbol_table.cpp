#include "Symbol_table.h"

Symbol_table::Symbol_table(){}

void Symbol_table::addSymbol(string key, Registry registro)
{
    auto search = symbol_table.find(key);
    if (search == symbol_table.end()) {
        //Si no existe 'key' en la tabla de símbolos:
        symbol_table.insert({key, registro});
    }

}

char * Symbol_table::getPointer(string pointer)
{
    char * aux  ;
    aux = &pointer[0];
    return aux;
}
char * Symbol_table::getPointer2(string pointer)
{
    char * aux  ;
    aux = &pointer[0];
    return aux;
}

Symbol_table::Registry Symbol_table::removeSymbol(string key)
{

    Registry reg;
    reg.id = symbol_table.find(key)->second.id;
    reg.Tipo = symbol_table.find(key)->second.Tipo;
    this->symbol_table.erase(key); //elimino el viejo

    return reg;
}

void Symbol_table::printTable()
{
    cout<<endl;
    cout<<"--------------------------IMPRIMIENDO LA TABLA ----------------------------------"<<endl;
    for (map<string,Registry>::iterator it=symbol_table.begin(); it!=symbol_table.end(); ++it)
    {
        cout << "Clave: " + it->first << " , Token_id: " << it->second.id << " Tipo: " << it->second.Tipo <<'\n';
    }
}

void Symbol_table::addType(string type, string key){

    Symbol_table::Registry  r = removeSymbol(key);

    r.Tipo = type;
    symbol_table.insert({key, r});

}
Symbol_table::Registry Symbol_table::getRegistry(string key){
    return symbol_table.find(key)->second;
}