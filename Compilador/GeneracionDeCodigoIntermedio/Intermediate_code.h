//
// Created by Lautaro on 27/10/2020.
//

#ifndef COMPILADOR_INTERMEDIATE_CODE_H
#define COMPILADOR_INTERMEDIATE_CODE_H
#include <map>
#include <iostream>
#include "../SymbolTable/Symbol_table.h"
#include "Terceto.h"
#include <list>

using namespace std;

class Intermediate_code {

    public:

        static bool falloEnCompilacion; // setear en los chekeos
        static int cantProc;
        static bool shadowing;
        static int ambitoAnonimo;
        static string ambito_actual;
        static list<string> list_variables;
        static list<int> pila;

        //Tipos
        static void addVariable(char * variable);
        static char* asignarTipo(Symbol_table * symbolTable,char* op, char* op2);
        static void declare_variable_list(Symbol_table * tablita,char * tipo); // se asigna el tipo a las variables en list_variables
        static bool check_type(Symbol_table * tablita,char * op,char * op2);
        //Ambitos Lauta
        static void concatenarAmbito(char * ambito);
        static void eliminarUltimoAmbito();
        static void concatenarAmbitoAnonimo(string ambit);
        static void desconcatenarAmbitoAnonimo();

        static void set_ambit(Symbol_table * symbolTable,char * key);
        static void setUse(Symbol_table * tablita,char * key,string use);

        static void check_scope(Symbol_table * symbolTable,char * key);
        static void check_shadowing(Symbol_table * tablita,string key); //private

        //Tercetos
        static void insertar_terceto(string op, string op1, string op2);
        static void insertar_terceto(Terceto t);
        static void insertarTercetoIncompleto(Terceto t);
        static void modificar_terceto(int numeroTerceto, int numeroCompletar);
        static void completar_operando3(Terceto t,string operando3);
        static Terceto removeTerceto(int pos);
        static Terceto getTercetoIncompleto();

        static void apilar();
        static int desapilar();
        static int getNumber();

        //Metodos acciones para generar los tercetos desde la gramatica
        //Se pueden optimizar estos seguramente un poco
        static void generarAsignacionTercetos(char* pesos1);
        static void expresionMenosTermino(string op,char * pesos3);
        static void terminoFactor(char * pesos3);
        static void generar_comparador(string op);
        static void expresionComparadorExpresion(char * pesos3);
        static void terminoDivididoFactor(string op ,char *);

        /*charly*/
        static void check_NA(char * na);
        static int convertToI(char * str);

        /*Imprimir*/
        static void imprimirTercetos();
        static void imprimirLista();

        /*Borrar*/
        static bool listaVacia();
        static void completar_terceto(int numeroTerceto, string operando1,string operando3);
        static void completar_operando1(int numeroTerceto, string operando1);
        static void completar_operando3(int numeroTerceto,string operando3);
        static Terceto removeTercetoResta(int pos);


private:

        static bool flagPre;
        static bool flagPost;
        static int number;
        static list<Terceto> list_tercetos_sin_completar;
        static map<int,Terceto> list_tercetos;

        //Metodos auxiliares
        static string convertToString(char * tipo);
        static string recortarAmbito(string key);
};

#endif //COMPILADOR_INTERMEDIATE_CODE_H


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