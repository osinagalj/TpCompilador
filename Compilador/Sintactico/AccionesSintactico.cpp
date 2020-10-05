#include "AccionesSintactico.h"

void AccionesSintactico::imprime(string x){
    cout<<x<<endl;
}
/*
void AccionesSintactico::chequearRangoCtePositiva(SymbolTable tablita,string pointer){

}*/

void AccionesSintactico::negativizarVar(SymbolTable * tablita,int yylval){
    cout<<"yylvallll: " + to_string(yylval) << endl;
}

/*
bool AccionesSintactico::checkDivisionCero(string pointer){
    return true;
}*/