#include <string>
#include <fstream>
#include <iostream>

#include "../Lexico/Lexico.h"
//class Lexico;

using namespace std;

class Logger{

public:
    static void open( const string & logFile);
    static void close();
    static void write( const string & message);
    //static void lex(const Lexico * lexico);
    static Lexico * lexico;
    Logger();
private:
    //Lexi
    ofstream fileStream;
    //Logger instance (singleton)
    static Logger instance;
};
