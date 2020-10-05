#include "Logger.h"
#include "../Lexico/Lexico.h"
Logger Logger::instance;

Logger::Logger(){}

void Logger::open( const string& logFile){
    instance.fileStream.open(logFile.c_str());
}
void Logger::close(){
    instance.fileStream.close();

}
void Logger::write(const string& message){
    ostream& stream =  instance.fileStream ;

    stream << message<< endl;
}
/*
void Logger::lexico(Lexico* lexico, string message ){
    int x = lexico->getLinea();
   cout<<"NUMERO DE LINEA = " + to_string(x)<<endl;
    write(message);

}*/

void Logger::inic(Lexico *lexico) {
    lexico2 = lexico;
    cout<<"LEXICO LINEA XD = " + to_string( lexico2->getLinea());
    write("LEXICO LINEA XD");
}