#include "TablaDeSimbolos.h"

TablaDeSimbolos::TablaDeSimbolos(){}
//Este lo llamra el LEXICO
void TablaDeSimbolos::agregarSimbolo(string key, Registro registro){

    auto search = tablaDeSimbolos.find(key);
    if (search == tablaDeSimbolos.end()) {
        //Si no existe 'key' en la tabla de símbolos:
        tablaDeSimbolos.insert({key, registro});
    }

}

//EL sintactico lo consulta
TablaDeSimbolos::Registro TablaDeSimbolos::getID(string key, Registro reg){
    if(tablaDeSimbolos.find(key) == tablaDeSimbolos.end()){
        TablaDeSimbolos::Registro registro;
        registro.id = -1;
        return registro;
    }
    return tablaDeSimbolos.find(key)->second;
}

void TablaDeSimbolos::imprimir(){
    cout<<endl;
    cout<<"IMPRIMIENDO LA TABLA ----------------------------------"<<endl;
    for (map<string,Registro>::iterator it=tablaDeSimbolos.begin(); it!=tablaDeSimbolos.end(); ++it){
        cout << it->first << " => " << it->second.id << '\n';
    }
}