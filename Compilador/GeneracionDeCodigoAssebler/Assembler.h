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
        void write( const string & message);



    private:
        ofstream  fileStream;

        vector<string> vars;
        vector<string> program;
        vector<string> data;
        vector<string> code;

        unordered_map<string, short int> bits;

};


#endif //COMPILADOR_ASSEMBLER_H
