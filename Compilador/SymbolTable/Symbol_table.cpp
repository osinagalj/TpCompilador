#include "Symbol_table.h"
#include "../Sintactic_analyzer/y.tab.h"
Symbol_table::Symbol_table(){}

void Symbol_table::addSymbol(string key, Registry registro)
{
    /*
    string prueba = "esteessech:elpepe";
    size_t  k = prueba.find(':');
    string prueba2 = prueba.substr(0,k);
    */
    auto search = symbol_table.find(key);
    if (search == symbol_table.end()) {
        //Si no existe 'key' en la tabla de símbolos:
        symbol_table.insert({key, registro});
    }

}
void Symbol_table::printTable()
{
    cout<<endl;
    cout<<"--------------------------IMPRIMIENDO LA TABLA ----------------------------------"<<endl;
    for (map<string,Registry>::iterator it=symbol_table.begin(); it!=symbol_table.end(); ++it)
    {
        cout << "Clave: " + it->first <<  " |Token_id: " << it->second.id << " |Tipo: " << it->second.Tipo << " |Token_uso: " << it->second.uso<<'\n';
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
    reg.id = ID; //se lo hardcodeo para ahorrar tiempo
    reg.Tipo = symbol_table.find(key)->second.Tipo;
    reg.uso = symbol_table.find(key)->second.uso;
    reg.tipoToken = symbol_table.find(key)->second.tipoToken;

    this->symbol_table.erase(key); //elimino el viejo

    return reg;
}

void Symbol_table::addType(string type, string key,string ambit){

    Symbol_table::Registry  r = removeSymbol(key);
    //r.ambito = ambit;
    //key = key + ":" + ambit;
    r.Tipo = type;
    symbol_table.insert({key, r});

}
void Symbol_table::addType2(string type, string key,string ambit){
    cout<<"ADDTYPE2"<<endl;
    cout<<"type"<<type<<endl;
    cout<<key<<endl;
    cout<<ambit<<endl;
    cout<<"AAntes"<<endl;
   // printTable();
    key = key + ":" + ambit;
    Symbol_table::Registry  r = removeSymbol(key);
    //r.ambito = ambit;

    r.Tipo = type;
    symbol_table.insert({key, r});
    cout<<"Desoures"<<endl;
    //printTable();

}

void Symbol_table::addAmbit(string key,string ambit){
    Symbol_table::Registry  r = removeSymbol(key);
    //r.ambito = ambit;
    key = key + ":" + ambit;
    symbol_table.insert({key, r});
}

Symbol_table::Registry Symbol_table::getRegistry(string key){
    return symbol_table.find(key)->second;
}

void Symbol_table::setUse(string key,string use){
    Symbol_table::Registry  r = removeSymbol(key);
    r.uso = use;
    symbol_table.insert({key, r});
}

#include <list>
void Symbol_table::clearTable(){

    list<string> numm ;
    for (auto it=symbol_table.begin(); it!=symbol_table.end(); ++it)
    {
        if(it->second.tipoToken == "id"){
            numm.push_front(it->first);
        }

    }

    for (auto itnum = numm.begin(); itnum != numm.end();itnum++){
        auto it = symbol_table.find(*itnum);
        symbol_table.erase(it);
    }

}

/*lauta*/



bool Symbol_table::existVariable(string key){
    auto itr = symbol_table.find(key);
    if(itr != symbol_table.end()){
        return true;
    }
    return false;
}
/**/