#include <string>
#include <fstream>
#include <iostream>
#include "../Lexical_analyzer/Lexical_analyzer.h"
using namespace std;

class Logger{

    public:

        Logger();
        static void open( const string & logFile);
        static void close();
        static void write( const string & message);
        static Lexical_analyzer * lexico;

    private:

        ofstream fileStream;
        //Logger instance (singleton)
        static Logger instance;
};
