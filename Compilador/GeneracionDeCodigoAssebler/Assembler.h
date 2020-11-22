//

#ifndef COMPILADOR_ASSEMBLER_H
#define COMPILADOR_ASSEMBLER_H

#include <map>
#include <iostream>
#include "../SymbolTable/Symbol_table.h"

#include <list>
#include <fstream>
#include <string>
#include <unordered_map>
#include "../GeneracionDeCodigoIntermedio/Intermediate_code.h"
#include <vector>
using namespace std;

class Assembler {
    public:
        Assembler();
        Assembler(string path);
        void declareLongint(const string & varName);
        void declareFloat(const string & varName);
        void declareString(const string & varName,const string & value);

        void declareSTVariables(Symbol_table * symbolTable);

        void open( const string & logFile);
        void close();
        void write(string message);

        //**NICO**//
        int getCase(string op, string op2);
        bool isVariable(string op);
        bool isConstant(string op);
        bool isRegister(string op);
        void addFloat(string op2, string op3);
        string getRegFree();
        void addInt(Terceto &t);
        void subInt(Terceto &t);
        void mulInt(Terceto &t);
        void asignacion(Terceto &t);
        static int cont_var_aux;
        int quitarCorchetes(string op);
        void generarAssembler(Symbol_table *tablita,list<int> listita);

        //**CHARLY**//
        void asignarRegistro(Terceto &t,string s);
        void liberarRegistro(Terceto &t);
        bool registros[4]={0,0,0,0};

        void BF_int(Terceto  &t);
        void comp_int(Terceto  &t);


        void BI_int(Terceto  t);

        int getNameString(const string & value);
        void invoke_out(Terceto t);
        void seguimiento_registros(Terceto &t);
        void variables_auxiliares(Terceto &t);
        void imprimirLista();
        Terceto searchTerceto(int num);
        void addFloat(Terceto &t);
        void generarCodigoAssembler(Symbol_table *tablita,Terceto & t);
        bool tercetoDeProc(int i,list<int> listita);
    private:
        ofstream  fileStream;

        map<int,Terceto> lista_tercetos;
        int current_string = 1;
        vector<string> vars;
        vector<string> program;
        vector<string> data;
        vector<string> code;
        unordered_map<string, short int> bits;
        list<string> var_strings;

        string space = "";
};


#endif //COMPILADOR_ASSEMBLER_H
