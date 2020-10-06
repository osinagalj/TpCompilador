#include "SymbolTable.h"

SymbolTable::SymbolTable(){}
//Este lo llamra el LEXICO
void SymbolTable::addSymbol(string key, Registry registro)
{
    auto search = symbol_table.find(key);
    if (search == symbol_table.end()) {
        //Si no existe 'key' en la tabla de símbolos:
        symbol_table.insert({key, registro});
    }

}
/*
//EL sintactico lo consulta
SymbolTable::Registro SymbolTable::getID(string key, Registro reg){
    if(tablaDeSimbolos.find(key) == tablaDeSimbolos.end()){
        SymbolTable::Registro registro;
        registro.id = -1;
        return registro;
    }
    return tablaDeSimbolos.find(key)->second;
}
*/
void SymbolTable::printTable(){
    cout<<endl;
    cout<<"--------------------------IMPRIMIENDO LA TABLA ----------------------------------"<<endl;
    for (map<string,Registry>::iterator it=symbol_table.begin(); it!=symbol_table.end(); ++it)
    {
        cout << it->first << " => " << it->second.id << '\n';
    }
}