
#include "chekeosGeneracion.h"
#include "../SymbolTable/Symbol_table.h"
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

void chekeosGeneracion::completar_terceto(int numeroTerceto, string operando1,string operando3) {
    list_tercetos.find(numeroTerceto)->second.setOp(operando1);
    list_tercetos.find(numeroTerceto)->second.setOp2(operando3);
}
void chekeosGeneracion::insertar_terceto(Terceto t){
    list_tercetos.insert({number, t});
    number++;
}
void chekeosGeneracion::completar_operando1(int numeroTerceto, string operando1) {
    list_tercetos.find(numeroTerceto)->second.setOp(operando1);
}
void chekeosGeneracion::completar_operando3(Terceto t,string operando3){
    t.setOp2(operando3);
    insertar_terceto(t);
}

void chekeosGeneracion::completar_operando3(int numeroTerceto, string operando3){
list_tercetos.find(numeroTerceto)->second.setOp(operando3);
}

string chekeosGeneracion::convertS(char * variable){

    string string_key ="";
    int length = 0;
    while (*variable != '\0') {
        length++;
        string_key = string_key + * variable;
        variable++;			                /* go to next letter */
    }
    return string_key;
}
void chekeosGeneracion::convertS2(char * variable,char * texto){

    cout<<"ambito: "+ convertS(texto) << endl;
    string string_key ="";
    int length = 0;
    while (*variable != '\0') {
        length++;
        string_key = string_key + * variable;
        variable++;			                /* go to next letter */
    }
    cout<< "Char *  = " + string_key << endl;
    cout<<endl;
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

//Asiga el tipo a toda la lista de variables
void chekeosGeneracion::asignar_tipo(Symbol_table * tablita,char * tipo){
    list<string>::iterator pos = list_variables.begin();
    while (pos != list_variables.end()){
        tablita->addType(tipo,*pos,ambito_actual);
        cout << *pos + ", ";
        pos++;
    }
    //Reiniciamos la lista
    list<string> list_variable_aux;
    list_variables = list_variable_aux;

}
void chekeosGeneracion::addVariable(char * variable){

    list_variables.push_back(convertToString(variable));
    cout<<"lista: ";
    imprimirLista();
    cout<<endl;

}
void chekeosGeneracion::setUse(){
    //tablita->addType(tipo,*pos,ambito_actual);
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


#include "../Output/Logger.h"

bool chekeosGeneracion::checkearTipo(Symbol_table * tablita,char * key,char * key2){

    if(tablita->getRegistry(convertToString(key)).Tipo == tablita->getRegistry(convertToString(key2)).Tipo){
        Logger::write("Coinciden los tipos");
        return true;
    }
    //Si falla el checkeo
    Logger::write("Error: No coinciden los tipos");
    falloEnCompilacion = true;
    return false;
}
#include <stdio.h>
#include <string.h>
//Aca quiero sumar las variables para guardar en $$.cadena el resultado, asi vamos llegvando los resultados
char* chekeosGeneracion::asignarTipo(Symbol_table * symbolTable,char* op, char* op2){
//tipo
    cout<<"Sumando operandos"<<endl;
    if(checkearTipo(symbolTable,op,op2)){
        cout<<"Suma del mismo tipo"<<endl;
        return op;
        /*
        string tipo = symbolTable->getRegistry(convertToString(op)).Tipo;
        char *cstr = new char[tipo.length() + 1];
        strcpy(cstr, tipo.c_str());
         */
        //return cstr;

    }
    return op;
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
/*
 Lauta
 **/
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

void chekeosGeneracion::asignarAmbito(Symbol_table * symbolTable,char * key){
    symbolTable->addAmbit(key,ambito_actual); //hacer algun chekeo seguramente
}

void chekeosGeneracion::setFlagPost(bool valor) {
    flagPost=valor;
}
bool chekeosGeneracion::getFlagPost() {
    return flagPost;
}
void chekeosGeneracion::setFlagPre(bool valor) {
    flagPre=valor;
}
bool chekeosGeneracion::getFlagPre() {
    return flagPre;
}



Terceto chekeosGeneracion::removeTercetoResta(int pos){
    Terceto t;
    t.setOp(list_tercetos.find(pos)->second.getOp());
    t.setOp1(list_tercetos.find(pos)->second.getOp1());
    t.setOp2(list_tercetos.find(pos)->second.getOp2());
    list_tercetos.erase(pos); //elimino el viejo
    number--;
    return t;
}

void chekeosGeneracion::insertarTercetoIncompleto(Terceto t){
    list_tercetos_sin_completar.push_front(t);
}

bool chekeosGeneracion::listaVacia(){
    if(list_tercetos_sin_completar.empty()){
        return true;
    }
    else return false;
}

Terceto chekeosGeneracion::getTercetoIncompleto(){
    cout<<"entro a get terceto incompleto"<<endl;
    list<Terceto>::iterator pos = list_tercetos_sin_completar.begin();
    if(pos != list_tercetos_sin_completar.end()) {
        Terceto t = *pos;
        cout << "contenido del terceto incompleto: " << t.getOp() << endl;
        list_tercetos_sin_completar.pop_front();
        return t;
    }
}



/*
 9. ...
10. ( - , a , b )
11. ( + , c , 1 )
12. ( > , [10] , [11] )
13. ( BF , [12] , ?7 )
14. ( + , b , c )
15. ( := , a , [14] )
16. ( BI , ?9, - )
17. ( - , b , c )
18. ( := , a , [17] )
19. FUERA_DEL_IF


 **/