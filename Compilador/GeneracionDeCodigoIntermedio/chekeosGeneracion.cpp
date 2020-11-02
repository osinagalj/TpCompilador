
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

void chekeosGeneracion::asignar_tipo(Symbol_table * tablita,char * tipo){
    list<string>::iterator pos = list_variables.begin();
    while (pos != list_variables.end()){
        tablita->addType(tipo,*pos);
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



void chekeosGeneracion::checkearTipo(Symbol_table * tablita,char * op,char * op2){


    //Si falla el checkeo
    falloEnCompilacion = true;
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