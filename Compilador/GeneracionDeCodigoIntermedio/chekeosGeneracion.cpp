
#include "chekeosGeneracion.h"
#include "../SymbolTable/Symbol_table.h"

void chekeosGeneracion::insertar_terceto(string op, string op1, string op2){
    //insertar en la cola?
    //depende el op, hace alguna otra accion
    Terceto t(op,op1,op2);
    //list_tercetos.insert({number, t});
}

Terceto chekeosGeneracion::getTerceto(int pos){
    //return list_tercetos.find(pos)->second;
    Terceto t("op","","");
    return t;
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
void chekeosGeneracion::setUse(){
    //tablita->addType(tipo,*pos,ambito_actual);
}

void chekeosGeneracion::imprimirLista() {
    list<string>::iterator pos = list_variables.begin();
    while (pos != list_variables.end()){
        cout << *pos + ", ";
        pos++;
    }
}

/*
void chekeosGeneracion::asignar_tipo(Symbol_table * tablita,char * tipo){
    list<string>::iterator pos = list_variables.begin();
while (pos != list_variables.end()){
tablita->addType(tipo,*pos,ambito_actual);
cout << *pos + ", ";
pos++;
}*/


void chekeosGeneracion::addVariable(char * variable){

    list_variables.push_back(convertToString(variable));
    cout<<"lista: ";
    imprimirLista();
    cout<<endl;

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

    }
    return op;
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




/*
    FLOAT variable1;                                // variable1.main

    PROC aa ()
    {
        FLOAT variable2;                            //variable2.main.aa
        PROC bb (){
            FLOAT variable3;                        //variable3.main.aa.bb

        };
        PROC ee (){
            FLOAT variable3;
        };
    }

    PROC dd (){
        FLOAT variable5;                            //variable2.main.dd

    }
//Osea como diferencio si un proc es hermano de otro, o es padre?

 Pasos-
    - Detecto variable4;
    - Concateno variable:main:1
    -
 * */

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