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
        static void crear_asignacion(Symbol_table * table, char * op,char * ,char * key);
        static void crear_asignacion2(Symbol_table * tablita, char * op,char * ,char * key);
        static void asignar_tipo(Symbol_table * tablita,char * tipo,char * variable);
        //que acciones tnemos que tener y en donde las llamamos en la gramatica
        static string convertS(char * tipo);
        static void convertS2(char * tipo);
        // double juan;
        //int pepe = 2 + juan;
        //get lista de tercetos

    private:
        static int number;
        static void checkexiste(Symbol_table * table,char * op);
        static Terceto getTerceto(int pos);
        static map<int,Terceto> list_tercetos;
};

#endif //COMPILADOR_CHEKEOSGENERACION_H
