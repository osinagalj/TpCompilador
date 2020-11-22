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
        static string scope ;

        static bool falloEnCompilacion; // setear en los chekeos
        static int cantProc;
        static bool shadowing;
        static int ambitoAnonimo;
        static string ambito_actual;
        static list<string> list_variables;
        static list<int> pila;
        static map<int,Terceto> list_tercetos;

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
        static bool check_scope2(Symbol_table * symbolTable,string & key);
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

        //Metodos acciones para generar los tercetos desde la gramatica
        //Se pueden optimizar estos seguramente un poco
        static void generarAsignacionTercetos(Symbol_table * tablita,char* pesos1);
        static void expresionMenosTermino(Symbol_table * tablita,string op,char * pesos3);
        static void terminoFactor(Symbol_table * tablita,char * pesos3);
        static void generar_comparador(string op);
        static void expresionComparadorExpresion(Symbol_table * tablita,char * pesos3);
        static void terminoDivididoFactor(Symbol_table * tablita,string op ,char *);

        //Metodos para la lista de procedimientos
        static string getTopeProc();
        static void insertarProc();
        static void insertar_terceto_a_proc(Terceto t);
        static bool esVacioPilaProc();
        //static void vaciarProcActual();
        static void apilarProc(string c);
        static void desapilarProc();

        /*charly*/
        static void check_NA(char * na);
        static int convertToI(char * str);
        //lista de procedimientos anidados para NA
        static void agregarAnidado();
        static void quitarAnidado();

        /*Imprimir*/
        static void imprimirTercetos();
        static void imprimirLista();
        static void imprimirListaProc();
        static void imprimirTercetosLista(list<Terceto> lista);
        static int getNumber();

        /*Borrar*/
        static bool listaVacia();
        static void completar_terceto(int numeroTerceto, string operando1,string operando3);
        static void completar_operando1(int numeroTerceto, string operando1);
        static void completar_operando3(int numeroTerceto,string operando3);
        static Terceto removeTercetoResta(int pos);

        static list<int> separarTercetos();
        static map<string,list<Terceto>> procedimientos;
        /*Buscar*/
        //static Terceto searchTerceto(int num);
        static void copiarLista(map<int,Terceto> &lista_tercetos);

        list<int> list_tercetos_ignore;
private:
        //list procedimientos anidados para NA
        static list<int> listProcedimientosAnidados;
        static list<string> pila_procedimientos;
        //static list<Terceto> proc_actual;

        static bool flagPre;
        static bool flagPost;
        static int number;
        static list<Terceto> list_tercetos_sin_completar;


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