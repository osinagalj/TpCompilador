//

#ifndef COMPILADOR_ASSEMBLER_H
#define COMPILADOR_ASSEMBLER_H

#include <map>
#include <iostream>
#include "../SymbolTable/Symbol_table.h"

#include <list>
#include <fstream>

using namespace std;

class Assembler {
    public:
        Assembler();

        static void open( const string & logFile);
        static void close();
        static void write( const string & message);



private:
    ofstream fileStream;
    //Logger instance (singleton)
    static Assembler instance;
};


#endif //COMPILADOR_ASSEMBLER_H
