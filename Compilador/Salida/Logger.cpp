#include "Logger.h"

Logger Logger::instance;

Logger::Logger(){}

void Logger::open( const string& logFile){
    instance.fileStream.open(logFile.c_str());
    if(!instance.fileStream.is_open()){
        exit(2);
    }
}
void Logger::close(){
    instance.fileStream.close();

}
void Logger::write(const string& message){
    ostream& stream =  instance.fileStream ;
    stream << "linea:" + to_string(lexico->get_number_line() - 1) + "  " + message<< endl;
}
