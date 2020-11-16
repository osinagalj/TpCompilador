
#include "chekeosGeneracion.h"
#include "../SymbolTable/Symbol_table.h"
#include <string.h>
#include "../Output/Logger.h"
#include <stdio.h>
#include <string.h>
void chekeosGeneracion::insertar_terceto(string op, string op1, string op2){
    //insertar en la cola?
    //depende el op, hace alguna otra accion
    Terceto t(op,op1,op2);
    list_tercetos.insert({number, t});
    number++;
}
int chekeosGeneracion::getNumber(){
    return number;
}
Terceto chekeosGeneracion::getTerceto(int pos){
    return list_tercetos.find(pos)->second;
    //Terceto t("op","","");
    //return t;
}
Terceto chekeosGeneracion::removeTerceto(int pos){
    Terceto t;
    t.setOp(list_tercetos.find(pos)->second.getOp());
    t.setOp1(list_tercetos.find(pos)->second.getOp1());
    t.setOp2(list_tercetos.find(pos)->second.getOp2());
    list_tercetos.erase(pos); //elimino el viejo
    return t;
}
void chekeosGeneracion::modificar_terceto(int numeroTerceto,int numeroCompletar){
    Terceto t=removeTerceto(numeroTerceto);
    int num = number + numeroCompletar;
    string s= to_string(num);
    t.setOp2(s);
    list_tercetos.insert({numeroTerceto, t});;
}



string chekeosGeneracion::convertToString(char * variable){

    string string_key ="";
    int length = 0;
    while (*variable != '\0') {
        length++;
        string_key = string_key + * variable;
        variable++;			                /* go to next letter */
    }
    cout<< "Char *  = " + string_key << endl;
    return string_key;
}



void chekeosGeneracion::addVariable(char * variable){

    list_variables.push_back(convertToString(variable));
    cout<<"lista: ";
    imprimirLista();
    cout<<endl;

}

void chekeosGeneracion::setUse(Symbol_table * tablita,char * key,char * use){
    string aux = key;
    aux = aux + ":" + ambito_actual;
    char *cstr = new char[aux.length() + 1];
    strcpy(cstr, aux.c_str());
    tablita->setUse(cstr,use);
}


/*
void chekeosGeneracion::agregarVariable(string aux) {
    list_variables.push_front(aux);
}
 */
void chekeosGeneracion::imprimirLista() {
    list<string>::iterator pos = list_variables.begin();
    while (pos != list_variables.end()){
        cout << *pos + ", ";
        pos++;
    }
}


string chekeosGeneracion::recortarAmbito(string s){
    unsigned pos = s.size();
    bool find = false;
    while(pos != 0 && !find) {
        if (s[pos] == ':') {
            find = true;
        } else {
            pos--;
        }
    }
    if (!find){
        return "error";
    }
    return s.substr (0,pos);
}



bool chekeosGeneracion::checkearTipo(Symbol_table * tablita,char * key,char * key2){

    string a = key;
    string b = key2;
    if(!(tablita->getRegistry(a).tipoToken == "constante")){
        a = a + ":" + ambito_actual;
    }
    if(!(tablita->getRegistry(b).tipoToken == "constante")){
        b = b + ":" + ambito_actual;
    }
    string aux = b;
    while(a != "error"){
        b = aux;
        while(b != "error"){
            if(tablita->getRegistry(a).Tipo == tablita->getRegistry(b).Tipo) {
                Logger::write("Coinciden los tipos");
                return true;
            }
            b = recortarAmbito(b);
        }
        a = recortarAmbito(a);
    }

    //Si falla el checkeo
    Logger::write("Error: No coinciden los tipos");
    falloEnCompilacion = true;
    return false;

}


//Aca quiero sumar las variables para guardar en $$.cadena el resultado, asi vamos llegvando los resultados
char* chekeosGeneracion::asignarTipo(Symbol_table * symbolTable,char* op, char* op2){
//tipo
    if(op != "error" && op2 != "error"){
        if(checkearTipo(symbolTable,op,op2)){
            cout<<"Suma del mismo tipo"<<endl;
            return op;

        }
    }
    //Caso de que no son iguales
    string s = "error";

    char *cstr = new char[s.length() + 1];
    strcpy(cstr, s.c_str());
    return cstr;
}

void chekeosGeneracion::apilar() {
    cout<<"apilando pa"<<endl;
    cout<<number<<endl;
    pila.push_front(number);
}
int chekeosGeneracion::desapilar() {
    cout<<"desapilando pa"<<endl;
    list<int>::iterator pos = pila.begin();
    int numerito= *pos;
    cout<<numerito<<endl;
    pila.pop_front();
    return numerito;
}

void chekeosGeneracion::imprimirTercetos(){
    for (map<int,Terceto>::iterator it=list_tercetos.begin(); it!=list_tercetos.end(); ++it)
    {//nico
        cout << to_string(it->first)<<".  " << "(" << it->second.getOp() << " , " << it->second.getOp1() << "," << it->second.getOp2() <<" ) "<<'\n';
    }
}



void chekeosGeneracion::concatenarAmbito(char * ambito)
{
    ambito_actual = ambito_actual + ":" + convertToString(ambito);
}


void chekeosGeneracion::eliminarUltimoAmbito()
{
    unsigned pos = ambito_actual.size();
    bool find = false;
    while(pos != 0 && !find){
        if(ambito_actual[pos] == ':'){
            find = true;
        }else{
            pos--;
        }
    }
    ambito_actual = ambito_actual.substr (0,pos);
}

void chekeosGeneracion::concatenarAmbitoAnonimo(string ambit) {
    ambito_actual = ambito_actual + ":" + ambit + "_" + to_string(ambitoAnonimo);
    ambitoAnonimo++;
}
void chekeosGeneracion::desconcatenarAmbitoAnonimo() {
    eliminarUltimoAmbito();
    ambitoAnonimo--;
}

void chekeosGeneracion::check_shadowing(Symbol_table * tablita,string key){
    if(shadowing){
        bool serompio=false;
        string aux3 = key;
        while(aux3.length() > 0 && !serompio){
            aux3 = recortarAmbito(aux3);
            if(aux3!= "error"){
                if(tablita->existVariable(aux3)){
                    cout<<"ERROR: SE REDEFINE UNA VARIABLE CON EL SHADOWIN EN TRUE"<<endl;

                    serompio = true;
                }
            }else{
                serompio = true;
            }

        }

    }
}
/*Modificada por lauta*/
//Asiga el tipo a toda la lista de variables
void chekeosGeneracion::declare_variable_list(Symbol_table * tablita,char * type){
    tablita->clearTable();
    list<string>::iterator pos = list_variables.begin();
    while (pos != list_variables.end()){
        string key = *pos + ":" + ambito_actual;

        char *cstr = new char[key.length() + 1];
        strcpy(cstr, key.c_str());

        check_shadowing(tablita,key);

        if(tablita->existVariable(key) && tablita->getRegistry(key).Tipo.length() == 0){
            tablita->addType(type,key,ambito_actual);
        }else{
            Logger::write("Error: Redeclaracion de variable");
        }
        pos++;
    }
    //Reiniciamos la lista
    list<string> list_variable_aux;
    list_variables = list_variable_aux;
    tablita->clearTable();
}


void chekeosGeneracion::asignarAmbito(Symbol_table * symbolTable,char * key){

    string a = key;
    string aux = a + ":" + ambito_actual;
    if(!symbolTable->existVariable(aux)){
        symbolTable->addAmbit(key,ambito_actual);
    }else{
        Logger::write("Error: Redeclaracion de procedimiento");
    }
}

void chekeosGeneracion::estaAlAlcance(Symbol_table * symbolTable,char * key){
    symbolTable->clearTable();

    string clave = key ; // para que busque si o si las que tienen ambito
    clave = clave + ":";
    string kaka = clave + ambito_actual;
    if(symbolTable->existVariable(kaka)){

        return ;
    }
    string aux = "";
    unsigned pos = kaka.size();

    while(pos != 0){
        if(kaka[pos] == ':'){
            aux = kaka.substr (0,pos);
            if(aux.find(':') == -1){
                if(symbolTable->existVariable(aux)){
                    return ;
                }
            }else{
                string aux2 =  aux;
                if(symbolTable->existVariable(aux2)){
                    return ;
                }
            }

        }
        pos--;
    }
    Logger::write("Error: variable no declarada.");
    return ;
}




