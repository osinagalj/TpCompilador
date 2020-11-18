#include "Assembler.h"


Assembler::Assembler(){}

Assembler::Assembler(string path )
{
        open(path);
        // 32 bit reg
        bits["EAX"] = 32; //En una instrucción, se pueden usar 32, 16 u 8 bits.
        bits["EBX"] = 32;
        bits["ECX"] = 32;
        bits["EDX"] = 32;
        // 16 bit reg
        bits["AX"] = 16; //16 bits menos significativos de EAX
        bits["BX"] = 16; //16 bits menos significativos de EBX
        bits["CX"] = 16; //16 bits menos significativos de ECX
        bits["DX"] = 16; //16 bits menos significativos de EDX

        write(".386");
        write(".model flat, stdcall");
        write("include \\masm32\\include\\masm32rt.inc");
        write("include \\masm32\\include\\windows.inc");
        write("include \\masm32\\include\\kernel32.inc");
        write("include \\masm32\\include\\user32.inc");
        write("includelib \\masm32\\lib\\kernel32.lib");
        write("includelib \\masm32\\lib\\user32.lib");

}


//--------------------------------------------------------------------------------------//
//-------------------------------------- DATA   ----------------------------------------//
//--------------------------------------------------------------------------------------//



void Assembler::declareLongint(const string & varName){

    // initializes it with no initial value
    data.push_back(varName + " DD ?");
    bits[varName] = 32;
    vars.push_back(varName);
    fileStream <<"    "+varName + " DD ? " <<endl;
}

void Assembler::declareFloat(const string &varName){
    // initializes it with no initial value
    data.push_back(varName + " DD ? ");
    bits[varName] = 16;
    vars.push_back(varName);
    fileStream <<"    "+varName + " DD ? "<<endl;
}
void Assembler::declareString(const string & varName){
    data.push_back(varName + " DB 0 ");// faltaria poner el contenido del string tmb
    vars.push_back(varName);
}

void Assembler::declareSTVariables(Symbol_table * st){
    fileStream <<".data"<<endl;
    // ADD all vars to code
    for(auto it = st->symbol_table.begin(); it!= st->symbol_table.end(); it++){
        if(it->second.uso == "variable"){

            //size_t i = it->first.find(":");
            //string name = it->first.substr(0,i);
            string name = it->first;
            if(it->second.Tipo == "Float"){
                declareFloat(name);
            }else{
                declareLongint(name);
            }
        }
    }
}
//----------------------------------------------------------------------------------------//
//---------------------------------- File Operations -------------------------------------//
//----------------------------------------------------------------------------------------//
void Assembler::open( const string& path){
    fileStream.open(path);
    if(!fileStream.is_open()){
        exit(4);
    }
}
void Assembler::close(){
    fileStream.close();
}
void Assembler::write(const string& message){
    fileStream <<message<< endl;
}