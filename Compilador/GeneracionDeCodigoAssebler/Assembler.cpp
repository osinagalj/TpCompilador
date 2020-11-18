#include "Assembler.h"

Assembler Assembler::instance;

Assembler::Assembler(){}

void Assembler::open( const string& logFile){
    instance.fileStream.open(logFile.c_str());
    if(!instance.fileStream.is_open()){
        exit(3);
    }
}
void Assembler::close(){
    instance.fileStream.close();
}
void Assembler::write(const string& message){
    ostream& stream =  instance.fileStream ;
    stream << "KAKA" <<message<< endl;
}