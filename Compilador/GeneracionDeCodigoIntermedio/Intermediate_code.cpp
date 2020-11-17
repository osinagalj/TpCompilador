
#include "Intermediate_code.h"
#include "../SymbolTable/Symbol_table.h"
#include <string.h>
#include "../Output/Logger.h"
#include <stdio.h>
#include <string.h>

//------------------------------------------------------------------------------------//
//------------------------------ Check of Type ---------------------------------------//
//------------------------------------------------------------------------------------//

void Intermediate_code::addVariable(char * variable){

    list_variables.push_back(convertToString(variable));
    cout<<"lista: ";
    imprimirLista();
    cout<<endl;

}

bool Intermediate_code::check_type(Symbol_table * tablita, char * key, char * key2){

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
                //Logger::write("Coinciden los tipos");
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
/*Modificada por lauta*/
//Asiga el tipo a toda la lista de variables
void Intermediate_code::declare_variable_list(Symbol_table * tablita, char * type){
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

//Aca quiero sumar las variables para guardar en $$.cadena el resultado, asi vamos llegvando los resultados
char* Intermediate_code::asignarTipo(Symbol_table * symbolTable, char* op, char* op2){
//tipo
    if(op != "error" && op2 != "error"){
        if(check_type(symbolTable,op,op2)){ //suma del mismo tipo
            return op;
        }
    }
    //Caso de que no son iguales
    string s = "error";

    char *cstr = new char[s.length() + 1];
    strcpy(cstr, s.c_str());
    return cstr;
}


//------------------------------------------------------------------------------------//
//----------------------------------- Ambit ------------------------------------------//
//------------------------------------------------------------------------------------//

void Intermediate_code::set_ambit(Symbol_table * symbolTable, char * key){

    string a = key;
    string aux = a + ":" + ambito_actual;
    if(!symbolTable->existVariable(aux)){
        symbolTable->addAmbit(key,ambito_actual);
    }else{
        Logger::write("Error: Redeclaracion de procedimiento");
    }
}

void Intermediate_code::setUse(Symbol_table * tablita, char * key, string use){
    string aux = key;
    aux = aux + ":" + ambito_actual;
    tablita->setUse(aux,use);
}

string Intermediate_code::recortarAmbito(string s){
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

void Intermediate_code::eliminarUltimoAmbito()
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

void Intermediate_code::concatenarAmbito(char * ambito)
{
    ambito_actual = ambito_actual + ":" + convertToString(ambito);
}

void Intermediate_code::concatenarAmbitoAnonimo(string ambit) {
    ambito_actual = ambito_actual + ":" + ambit + "_" + to_string(ambitoAnonimo);
    ambitoAnonimo++;
}
void Intermediate_code::desconcatenarAmbitoAnonimo() {
    eliminarUltimoAmbito();
    ambitoAnonimo--;
}





//------------------------------------------------------------------------------------//
//------------------------------ Other Checks ----------------------------------------//
//------------------------------------------------------------------------------------//
void Intermediate_code::check_shadowing(Symbol_table * tablita, string key){
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

//Chekeo para ver si la variable es al alcance, es decir s iesta definida en el mismo ambito o en alguno ambito padre.
//Nota: si la variable esta en un ambito hermano o hijo tira error
void Intermediate_code::check_scope(Symbol_table * symbolTable, char * key){
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

void Intermediate_code::check_NA(char * pesos7){

    if(Intermediate_code::cantProc > stoi(convertToString(pesos7))){
        cout<< "cantPorc: " + cantProc<< endl;
        cout<< "$7cadena: " + convertToString(pesos7)<< endl;
        Logger::write("Error: Tenes mas procedimientos de los que permite el NA");
    };
    Intermediate_code::cantProc++;
};





//------------------------------------------------------------------------------------//
//------------------------------ Tercetos Operations   -------------------------------//
//------------------------------------------------------------------------------------//


void Intermediate_code::insertar_terceto(string op, string op1, string op2){
    //insertar en la cola?
    //depende el op, hace alguna otra accion
    Terceto t(op,op1,op2);
    list_tercetos.insert({number, t});
    number++;
}
void Intermediate_code::insertar_terceto(Terceto t){
    list_tercetos.insert({number, t});
    number++;
}

void Intermediate_code::modificar_terceto(int numeroTerceto, int numeroCompletar){
    Terceto t=removeTerceto(numeroTerceto);
    int num = number + numeroCompletar;
    string s= to_string(num);
    t.setOp2(s);
    list_tercetos.insert({numeroTerceto, t});;
}

void Intermediate_code::completar_operando3(Terceto t, string operando3){
    t.setOp2(operando3);
    insertar_terceto(t);
}

void Intermediate_code::insertarTercetoIncompleto(Terceto t){
    list_tercetos_sin_completar.push_front(t);
}

Terceto Intermediate_code::getTercetoIncompleto(){
    list<Terceto>::iterator pos = list_tercetos_sin_completar.begin();
    Terceto t;
    if(pos != list_tercetos_sin_completar.end()) {
        t = *pos;
        list_tercetos_sin_completar.pop_front();
        return t;
    }
    return t;
}

Terceto Intermediate_code::removeTerceto(int pos){
    Terceto t;
    t.setOp(list_tercetos.find(pos)->second.getOp());
    t.setOp1(list_tercetos.find(pos)->second.getOp1());
    t.setOp2(list_tercetos.find(pos)->second.getOp2());
    list_tercetos.erase(pos); //elimino el viejo
    return t;
}




//------------------------------------------------------------------------------------//
//------------------------------ Tercetos Generation   -------------------------------//
//------------------------------------------------------------------------------------//
void Intermediate_code::apilar() {
    cout<<number<<endl;
    pila.push_front(number);
}
int Intermediate_code::desapilar() {
    list<int>::iterator pos = pila.begin();
    int numerito= *pos;
    cout<<numerito<<endl;
    pila.pop_front();
    return numerito;
}

void Intermediate_code::expresionMenosTermino(string op, char * pesos3)
{

    if (!flagPre && flagPost){
        //completar tercerto de la pila
        Terceto t = getTercetoIncompleto();
        t = getTercetoIncompleto();
        t.setOp(op);
        t.setOp2(pesos3);
        flagPost = false;
        insertar_terceto(t);
        //Intermediate_code::completar_terceto(Intermediate_code::getNumber()-1,"-",$3.cadena);
    }
    else if (flagPre && !flagPost) {
        //completar tercerto de la pila
        Terceto t = getTercetoIncompleto();
        t.setOp(op);
        t.setOp2(pesos3);
        flagPre=false;
        insertar_terceto(t);
        //Intermediate_code::completar_terceto(Intermediate_code::getNumber()-1,"-",$3.cadena);
    }
    else if (flagPre && flagPost) {
        //completar tercerto de la pila
        Terceto t = getTercetoIncompleto();
        t.setOp(op);
        t.setOp2(pesos3);
        flagPost = false;
        insertar_terceto(t);
        //Intermediate_code::completar_terceto(Intermediate_code::getNumber()-1,"-",$3.cadena);
    }
    else if (!flagPre && !flagPost){
        //insertar el terceto con el number del anterior
        insertar_terceto(op,"["+to_string(number-1)+"]",pesos3);}
}




void Intermediate_code::terminoFactor(char * pesos1) {

    if(!flagPre && !flagPost){
        flagPre=true;
        Terceto t("-",pesos1,"-"); //insertar tercerto incompleto (-,factor,-)
        insertarTercetoIncompleto(t);
    }else if(!flagPre && flagPost){
        Terceto t("-",pesos1,"-");
        insertarTercetoIncompleto(t);
    }
    else if(flagPre && flagPost){
        Terceto t("-",pesos1,"-");

        flagPre = false;
        insertarTercetoIncompleto(t);
    }
}

void Intermediate_code::terminoDivididoFactor(string op , char * pesos3){

    if (!flagPre && flagPost){
        //completar tercerto de la pila
        Terceto t = getTercetoIncompleto();
        t.setOp(op);
        t.setOp2(pesos3);
        flagPost = false;
        insertar_terceto(t);
    }
    else if (flagPre && !flagPost) {
        Terceto t = getTercetoIncompleto();
        t.setOp(op);
        t.setOp2(pesos3);
        flagPre = false;
        insertar_terceto(t);
    }
    else if (flagPre && flagPost) {
        Terceto t = getTercetoIncompleto();
        t.setOp(op);
        t.setOp2(pesos3);
        flagPost = false;
        insertar_terceto(t);
    }
    else if (!flagPre && !flagPost){
        //insertar el terceto con el number del anterior
        insertar_terceto(op,"["+to_string(number-1)+"]",pesos3);}

}




void Intermediate_code::generarAsignacionTercetos(char* pesos1){
    if (Intermediate_code::flagPre && !Intermediate_code::flagPost){
        //modificar terceto incompleto ("=",factor,-) //agrego = al (-,factor,-)
        //Intermediate_code::completar_operando1(Intermediate_code::getNumber()-1,"=");
        Terceto t = getTercetoIncompleto();
        flagPost = false;
        t.setOp("=");
        t.setOp2(t.getOp1());
        t.setOp1(pesos1);
        insertar_terceto(t);
    }
    else if (!flagPre && !flagPost){
        //crear el terceto incompleto con el number de la expresion
        //Intermediate_code::insertar_terceto("=","["+to_string(Intermediate_code::getNumber())+"]","");
        Terceto t("=",pesos1,"["+to_string(number-1)+"]");
        insertar_terceto(t);
    }
    flagPre=false;
    flagPost = false;
}

void Intermediate_code::generar_comparador(string op){
    if (flagPre && !flagPost){
        //modificar terceto incompleto ("==",factor,-) //agrego == al (-,factor,-)
        Terceto t = getTercetoIncompleto();
        flagPost = true;
        t.setOp(op);
        insertarTercetoIncompleto(t);
    }
    else if (!flagPre && !flagPost){
        //crear el terceto incompleto con el number de la expresion
        Terceto t(op,"["+to_string(number-1)+"]","-");
        flagPost = true;
        insertarTercetoIncompleto(t);
    }
}

// CREAR TERCETO INCOMPLETO PARA LA BF
// APILAR EL NUMERO DEL TERCETO INCOMPLETO
//AGREGAR CONSULTAR EL FLAG ACTUAL (POST COMPARADOR), si está en true completar el terceto incompleto.
void Intermediate_code::expresionComparadorExpresion(char * pesos3){
    Logger::write("Condicion igual");

    if (!flagPre && flagPost){
        Terceto t = getTercetoIncompleto(); //descarto
        t = getTercetoIncompleto();
        cout<<t.getOp()<<endl;
        completar_operando3(t,pesos3);
    }
    else if (flagPre && flagPost){
        //hay terceto incompleto pre-comparador y la derecha es un factor, pero se creó un terceto, lo descarto
        Terceto t = getTercetoIncompleto();
        t = getTercetoIncompleto();
        cout<<t.getOp()<<endl;
        completar_operando3(t,pesos3);
    }else if (flagPre && !flagPost){
        //hay terceto incompleto pre-comparador y la derecha es un factor, pero se creó un terceto, lo descarto
        Terceto t = getTercetoIncompleto(); //descarto
        t = getTercetoIncompleto();
        cout<<t.getOp()<<endl;
        completar_operando3(t,"["+to_string(number-1)+"]");
    }
    else{
        Terceto t = getTercetoIncompleto();
        cout<<t.getOp()<<endl;
        completar_operando3(t,"["+to_string(number-1)+"]");
    }
    flagPre = false;
    flagPost = false;
    apilar();
    insertar_terceto("BF","["+to_string(number-1)+"]","");
}











//------------------------------------------------------------------------------------//
//------------------------------ Auxiliary functions ---------------------------------//
//------------------------------------------------------------------------------------//

string Intermediate_code::convertToString(char * variable){

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


void Intermediate_code::imprimirTercetos(){
    for (map<int,Terceto>::iterator it=list_tercetos.begin(); it!=list_tercetos.end(); ++it){
        cout << to_string(it->first)<<".  " << "(" << it->second.getOp() << " , " << it->second.getOp1() << " , " << it->second.getOp2() <<" ) "<<'\n';
    }
}

void Intermediate_code::imprimirLista() {
    list<string>::iterator pos = list_variables.begin();
    while (pos != list_variables.end()){
        cout << *pos + ", ";
        pos++;
    }
}
/*
int Intermediate_code::convertToI(char * str){ //Creo que se puede eliminar
    int i=stoi(convertToString(str));
    return i;
}
 */
















//-----------------------------------------------------------------------------------------------//
/*-------------------------------------NO SE USAN -----------------------------------------------*/
//------------------------------------------------------------------------------------------------//
void Intermediate_code::completar_operando3(int numeroTerceto, string operando3){
    list_tercetos.find(numeroTerceto)->second.setOp(operando3);
}
void Intermediate_code::completar_operando1(int numeroTerceto, string operando1) {
    list_tercetos.find(numeroTerceto)->second.setOp(operando1);
}
void Intermediate_code::completar_terceto(int numeroTerceto, string operando1, string operando3) {
    list_tercetos.find(numeroTerceto)->second.setOp(operando1);
    list_tercetos.find(numeroTerceto)->second.setOp2(operando3);
}

/*
Terceto Intermediate_code::getTerceto(int pos){
    return list_tercetos.find(pos)->second;
    //Terceto t("op","","");
    //return t;
}
 */

bool Intermediate_code::listaVacia(){
    if(list_tercetos_sin_completar.empty()){
        return true;
    }
    else return false;
}

Terceto Intermediate_code::removeTercetoResta(int pos){
    Terceto t;
    t.setOp(list_tercetos.find(pos)->second.getOp());
    t.setOp1(list_tercetos.find(pos)->second.getOp1());
    t.setOp2(list_tercetos.find(pos)->second.getOp2());
    list_tercetos.erase(pos); //elimino el viejo
    number--;
    return t;
}

/*
void Intermediate_code::agregarVariable(string aux) {
    list_variables.push_front(aux);
}
 */