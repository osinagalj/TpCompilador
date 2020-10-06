#include "Symbol_table.h"

Symbol_table::Symbol_table(){}
//Este lo llamra el LEXICO
void Symbol_table::addSymbol(string key, Registry registro)
{
    auto search = symbol_table.find(key);
    if (search == symbol_table.end()) {
        //Si no existe 'key' en la tabla de símbolos:
        symbol_table.insert({key, registro});
    }

}
/*
//EL sintactico lo consulta
Symbol_table::Registro Symbol_table::getID(string key, Registro reg){
    if(tablaDeSimbolos.find(key) == tablaDeSimbolos.end()){
        Symbol_table::Registro registro;
        registro.id = -1;
        return registro;
    }
    return tablaDeSimbolos.find(key)->second;
}
*/
void Symbol_table::printTable(){
    cout<<endl;
    cout<<"--------------------------IMPRIMIENDO LA TABLA ----------------------------------"<<endl;
    for (map<string,Registry>::iterator it=symbol_table.begin(); it!=symbol_table.end(); ++it)
    {
        cout << it->first << " => " << it->second.id << '\n';
    }
}

char * Symbol_table::getPuntero(string puntero) {
    _Rb_tree_iterator<pair<const basic_string<char>, Registry>> reg=this->symbol_table.find(puntero);
    char *aux= (char*)&reg->first;
    return aux;
}