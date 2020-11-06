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
        static void crear_asignacion(Symbol_table * table, char * op,char * ,char * key);
        static void crear_asignacion2(Symbol_table * tablita, char * op,char * ,char * key);
        static void asignar_tipo(Symbol_table * tablita,char * tipo);
        static bool checkearTipo(Symbol_table * tablita,char * op,char * op2);
        //que acciones tnemos que tener y en donde las llamamos en la gramatica
        static string convertS(char * tipo);
        static void convertS2(char * tipo,char * texto);
        // double juan;
        //int pepe = 2 + juan;
        //get lista de tercetos
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
        static void setUse();
        static void imprimirLista2();
        //END ambitos Lauta


private:

        static int number;

        static void checkexiste(Symbol_table * table,char * op);
        static Terceto getTerceto(int pos);
        static map<int,Terceto> list_tercetos;
};

#endif //COMPILADOR_CHEKEOSGENERACION_H
