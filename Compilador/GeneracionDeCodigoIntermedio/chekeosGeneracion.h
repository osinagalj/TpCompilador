//
// Created by Lautaro on 27/10/2020.
//

#ifndef COMPILADOR_CHEKEOSGENERACION_H
#define COMPILADOR_CHEKEOSGENERACION_H
#include <map>
#include <iostream>
#include "../SymbolTable/Symbol_table.h"
#include "Terceto.h"
#include <list>

using namespace std;

class chekeosGeneracion {

    public:
        //Actions
        static void insertar_terceto(string op, string op1, string op2);
        static Terceto removeTerceto(int pos);

        static void declare_variable_list(Symbol_table * tablita,char * tipo); //declare_variable_list
        static bool checkearTipo(Symbol_table * tablita,char * op,char * op2);

        static void addVariable(char * variable);
        static string convertToString(char * tipo);
        static char* asignarTipo(Symbol_table * symbolTable,char* op, char* op2);

        static void imprimirLista();
        static list<string> list_variables;

        static list<int> pila;
        static void apilar();
        static int desapilar();
        static void modificar_terceto(int numeroTerceto, int numeroCompletar);

        static bool falloEnCompilacion;
        static int getNumber();

        static void imprimirTercetos();




        /**/

        static void insertar_terceto(Terceto t);
        static void crear_asignacion(Symbol_table * table, char * op,char * ,char * key);
        static void crear_asignacion2(Symbol_table * tablita, char * op,char * ,char * key);
        static void asignar_tipo(Symbol_table * tablita,char * tipo);
        //que acciones tnemos que tener y en donde las llamamos en la gramatica
        static string convertS(char * tipo);
        static void convertS2(char * tipo,char * texto);
        // double juan;
        //int pepe = 2 + juan;
        //get lista de tercetos

        /**/














        //Ambitos Lauta
        static int ambitoAnonimo;
        static string ambito_actual;
        static void concatenarAmbito(char * ambito);
        static void asignarAmbitoActual(Symbol_table * tablita,char * key);
        static void eliminarUltimoAmbito();
        static void concatenarAmbitoAnonimo(string ambit);
        static void desconcatenarAmbitoAnonimo();
        static list<string> list_variables_ambito;
        static void asignarAmbito(Symbol_table * symbolTable,char * key);
        static void setUse(Symbol_table * tablita,char * key,char * key2);
        static void imprimirLista2();

        static void estaAlAlcance(Symbol_table * symbolTable,char * key);
    static bool estaAlAlcance2(Symbol_table * symbolTable,char * key, string & tuka);
        static string recortarAmbito(string key);

        //END ambitos Lauta

        static bool shadowing;
        static bool setShadowingFalse();
        static bool getShadowing();
        static void check_shadowing(Symbol_table * tablita,string key);


        /*nico*/
        static void setFlagPre(bool valor);
        static bool getFlagPre();
        static void setFlagPost(bool valor);
        static bool getFlagPost();
        static Terceto removeTercetoResta(int pos);
        static void insertarTercetoIncompleto(Terceto t);
        static Terceto getTercetoIncompleto();
        static void completar_terceto(int numeroTerceto, string operando1,string operando3);
        static void completar_operando1(int numeroTerceto, string operando1);
        static void completar_operando3(int numeroTerceto,string operando3);
        static void completar_operando3(Terceto t,string operando3);
        static bool listaVacia();


    static int cantProc;
    /*nico*/
        static int convertToI(char * str);
private:
        /*nico*/
        static bool flagPre;
        static bool flagPost;
        static int number;
        static list<Terceto> list_tercetos_sin_completar;


        /**/

        static void checkexiste(Symbol_table * table,char * op);
        static Terceto getTerceto(int pos);
        static map<int,Terceto> list_tercetos;
};

#endif //COMPILADOR_CHEKEOSGENERACION_H


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