#include <string>
#include <fstream>
#include <iostream>

//#include "../Lexico/Lexico.h"
class Lexico;

using namespace std;

class Logger{

public:
    static void open( const string & logFile);
    static void close();
    // write message
    static void write( const string & message);
    void inic(Lexico* lexico);
    Logger();
private:

    Lexico * lexico2;
    //Lexi
    ofstream fileStream;
    //Logger instance (singleton)
    static Logger instance;
};
