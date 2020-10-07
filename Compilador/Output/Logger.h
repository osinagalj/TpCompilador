#include <string>
#include <fstream>
#include <iostream>
#include "../Lexical_analyzer/Lexical_analyzer.h"
using namespace std;

class Logger{

public:
    static void open( const string & logFile);
    static void close();
    static void write( const string & message);
    static Lexical_analyzer * lexico;
    Logger();
private:

    ofstream fileStream;
    //Logger instance (singleton)
    static Logger instance;
};
