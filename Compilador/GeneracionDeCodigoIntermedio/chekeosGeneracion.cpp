
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

void  chekeosGeneracion::crear_asignacion(Symbol_table * table, char * op,char * ,char * key){

    //checkexiste(table,op);
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