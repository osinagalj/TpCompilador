#include "Sintactic_actions.h"

void Sintactic_actions::imprime(string x){
    cout<<x<<endl;
}
/*
void Sintactic_actions::chequearRangoCtePositiva(SymbolTable tablita,string pointer){

}*/

void Sintactic_actions::negativizarVar(SymbolTable * tablita, int yylval){
    cout<<"yylvallll: " + to_string(yylval) << endl;
}

/*
bool Sintactic_actions::checkDivisionCero(string pointer){
    return true;
}*/