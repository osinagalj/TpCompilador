#include "Logger.h"

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