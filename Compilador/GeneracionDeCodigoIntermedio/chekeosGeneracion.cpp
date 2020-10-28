
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
void chekeosGeneracion::convertS2(char * variable){

    string string_key ="";
    int length = 0;
    while (*variable != '\0') {
        length++;
        string_key = string_key + * variable;
        variable++;			                /* go to next letter */
    }
    cout<< "Que me esta imprimiendo = " + string_key << endl;
    cout<<endl;
}

void chekeosGeneracion::asignar_tipo(Symbol_table * tablita,char * tipo,char * variable){
    //checkexiste(table,op);
    cout<<"ASIGNACIONNNNNNNNNNNNNNNNNNN" <<endl;

    cout<<"tipo = " + convertS(tipo) <<endl;
    cout<<"Variableeeeeee = " + convertS(variable) <<endl;

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