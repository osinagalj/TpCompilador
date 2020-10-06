#include <string>
#include <fstream>
#include <iostream>

#include "../Lexico/Lexical_analyzer.h"
//class Lexical_analyzer;

using namespace std;

class Logger{

public:
    static void open( const string & logFile);
    static void close();
    static void write( const string & message);
    //static void lex(const Lexical_analyzer * lexico);
    static Lexical_analyzer * lexico;
    Logger();
private:
    //Lexi
    ofstream fileStream;
    //Logger instance (singleton)
    static Logger instance;
};
