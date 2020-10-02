#include "TablaDeSimbolos.h"

//Este lo llamra el LEXICO
void TablaDeSimbolos::agregarSimbolo(string key, Registro registro){

    cout<<"ENTRO EN LA TS = " + key<<endl;
        //Registro registro;
        //registro.id = ID;
   /* auto search = tablaDeSimbolos.find(key);
    cout<<"ENTRO EN LA kaka = " + key<<endl;

    if (search == tablaDeSimbolos.end()) {
        //Si no existe 'key' en la tabla de símbolos:
        */
        tablaDeSimbolos.insert(pair<string,Registro>(key, registro));



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
    for (map<string,Registro>::iterator it=tablaDeSimbolos.begin(); it!=tablaDeSimbolos.end(); ++it){
        cout << it->first << " => " << it->second.id << '\n';
    }
}