#include "Assembler.h"
#include <string.h>

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
    fileStream <<"    _"+varName + " DD ? " <<endl;
}

void Assembler::declareFloat(const string &varName){
    // initializes it with no initial value
    data.push_back(varName + " DD ? ");
    bits[varName] = 16;
    vars.push_back(varName);
    fileStream <<"    _"+varName + " DD ? "<<endl;
}
void Assembler::declareString(const string & varName, const string & value){
    data.push_back("str"+to_string(current_string)+" DB " + value + " , 0 ");// faltaria poner el contenido del string tmb
    vars.push_back(varName);
    fileStream <<"    str"+to_string(current_string)+" DB " + value + " , 0 "<<endl;
    current_string++;
}

void Assembler::declareSTVariables(Symbol_table * st){
    fileStream <<".data"<<endl;
    for(auto it = st->symbol_table.begin(); it!= st->symbol_table.end(); it++){
        cout<<"variable = " << it->first <<endl;
        if(it->second.uso == "variable" || it->second.uso == "parametro"){
            string name = it->first;
            if(it->second.Tipo == "Float"){
                declareFloat(name);
            }else{
                declareLongint(name);
            }
        }else if(it->second.uso == "constante"){ //Preguntar si tenemos que definir los strings
            if(it->second.Tipo == "String") {
                cout<<"Inserto por aka"<<endl;
                declareString(it->first,it->first);
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
void Assembler::write(string message){
    fileStream <<message<< endl;
}


//----------------------------------------------------------------------------------------//
//---------------------------------- Aritmethic Operations -------------------------------//
//----------------------------------------------------------------------------------------//

bool Assembler::isConstant(string op){
   if (!isRegister(op) && !isVariable(op)){
       return true;
   }
   if(isRegister(op)){
       cout<<"Es un registro"<<endl;
   }
    if(isVariable(op)){
        cout<<"Es un variable"<<endl;
    }
   return false;
}

bool Assembler::isVariable(string op){
    for(string s : vars){
        if(op == s){
            return true;
        }
    }
    return false;
}

bool Assembler::isRegister(string op){
    if(op.substr(0,1) == "["){
        string result;
        for(char s: op){
            if(s!=']'){
                result=result+s;
            }
        }
        //search result in TS
        //get reg in the Terceto
        return true;
    }
    return false;
}

int Assembler::getCase(string op1, string op2){
    // CASE 1
    if((isConstant(op1) && isVariable(op2)) ||
       (isConstant(op2) && isVariable(op1)) ||
       (isVariable(op1) && isVariable(op2)) ||
       (isConstant(op1) && isConstant(op2))){
        return 1;
    }
    if( (isRegister(op1) && isVariable(op2)) ||
        (isRegister(op1) && isConstant(op2))){
        return 2;
    }
    if((isVariable(op1) && isRegister(op2)) ||
       (isConstant(op1) && isRegister(op2))){
        return 3;
    }
    if(isRegister(op1) && isRegister(op2)){
        return 4;
    }
    return 0;
}

int Assembler::quitarCorchetes(string op){
    return stoi(op.substr(1,op.size()-1));
}

void Assembler::asignacion(Terceto &t){
    if (isVariable(t.getOp2())){
        write("MOV " + t.getOp1() + "," + t.getOp2());
    }else{
        Terceto t2 = Intermediate_code::searchTerceto(quitarCorchetes(t.getOp2()));
        write("MOV _" + t.getOp1() + "," + t2.getOp3());
        liberarRegistro(t2);
    }
}


void Assembler::addInt(Terceto &t) {
    cout<<"------------------ADD INT--------------"<<endl;
    if (getCase(t.getOp1(), t.getOp2()) == 1) {
        cout<<"------------------CASE 1--------------"<<endl;
        //set free reg in the Terceto
        asignarRegistro(t,"ADD");
        write("MOV " + t.getOp3() + "," + t.getOp1());
        write("ADD " + t.getOp3() + "," + t.getOp2());
    } else {
        if (getCase(t.getOp1(), t.getOp2()) == 2){
            cout<<"------------------CASE 2--------------"<<endl;
            //search & get reg Terceto in list_tercetos
            Terceto t2 = Intermediate_code::searchTerceto(quitarCorchetes(t.getOp1()));
            write("ADD " + t2.getOp3() + "," + t.getOp2());
        } else {
            if (getCase(t.getOp1(), t.getOp2()) == 3) {
                cout<<"------------------CASE 3--------------"<<endl;
                //search & get reg Terceto in list_tercetos
                Terceto t2 = Intermediate_code::searchTerceto(quitarCorchetes(t.getOp1()));
                //get reg in the Terceto
                asignarRegistro(t,"ADD");
                write("MOV " + t.getOp3() + "," + t.getOp1());
                //get reg in the Terceto
                write("ADD " + t.getOp3() + "," + t2.getOp3());
                //free reg2 ((LLAMAR AL PROC DE CHARLY)) ((SACAR EL REG DE T2))
                liberarRegistro(t2);
            } else {
                cout<<"------------------CASE 4--------------"<<endl;
                //search & get Terceto in list_tercetos
                Terceto t1 = Intermediate_code::searchTerceto(quitarCorchetes(t.getOp1()));
                Terceto t2 = Intermediate_code::searchTerceto(quitarCorchetes(t.getOp1()));
                write("ADD " + t1.getOp3() + "," + t2.getOp3());
                //free reg2 ((LLAMAR AL PROC DE CHARLY)) ((SACAR EL REG DE T2))
                liberarRegistro(t2);
            }
        }
    }
}

void Assembler::subInt(Terceto &t) {
    cout<<"------------------SUB INT--------------"<<endl;
    if (getCase(t.getOp1(), t.getOp2()) == 1) {
        cout<<"------------------CASE 1--------------"<<endl;
        //set free reg in the Terceto
        asignarRegistro(t,"SUB");
        write("MOV " + t.getOp3() + "," + t.getOp1());
        write("SUB " + t.getOp3() + "," + t.getOp2());
    } else {
        if (getCase(t.getOp1(), t.getOp2()) == 2){
            cout<<"------------------CASE 2--------------"<<endl;
            //search & get reg Terceto in list_tercetos
            Terceto t2 = Intermediate_code::searchTerceto(quitarCorchetes(t.getOp1()));
            write("SUB " + t2.getOp3() + "," + t.getOp2());
        } else {
            if (getCase(t.getOp1(), t.getOp2()) == 3) {
                cout<<"------------------CASE 3--------------"<<endl;
                //search & get reg Terceto in list_tercetos
                Terceto t2 = Intermediate_code::searchTerceto(quitarCorchetes(t.getOp1()));
                //get reg in the Terceto
                asignarRegistro(t,"SUB");
                write("MOV " + t.getOp3() + "," + t.getOp1());
                //get reg in the Terceto
                write("SUB " + t.getOp3() + "," + t2.getOp3());
                //free reg2 ((LLAMAR AL PROC DE CHARLY)) ((SACAR EL REG DE T2))
                liberarRegistro(t2);
            } else {
                cout<<"------------------CASE 4--------------"<<endl;
                //search & get Terceto in list_tercetos
                Terceto t1 = Intermediate_code::searchTerceto(quitarCorchetes(t.getOp1()));
                Terceto t2 = Intermediate_code::searchTerceto(quitarCorchetes(t.getOp1()));
                write("SUB " + t1.getOp3() + "," + t2.getOp3());
                //free reg2 ((LLAMAR AL PROC DE CHARLY)) ((SACAR EL REG DE T2))
                liberarRegistro(t2);
            }
        }
    }
}

/*
void Assembler::addFloat(string op2,string op3) {
    if (getCase(op2, op3) == 1) {
        //string regF = getRegFree();
        write("MOV " + regF + "," + op2);
        write("ADD " + regF + "," + op3);
        write("MOV @aux"+to_string(cont_var_aux)+","+regF ); //i es el contador de variables auxiliares
        cont_var_aux++;
        //add var to Terceto
    } else {
        if (getCase(op2, op3) == 2) {
            //search result in TS
            //get reg in the Terceto
            write("ADD reg , " + op3);
            write("MOV @aux"+to_string(cont_var_aux)+","+"reg"); //i es el contador de variables auxiliares
            cont_var_aux++;
        } else {
            if (getCase(op2, op3) == 3) {
                string regF = getRegFree();
                write("MOV " + regF + "," + op2);
                //search result in TS
                //get reg in the Terceto
                write("ADD " + regF + "," + "reg");
                write("MOV @aux"+to_string(cont_var_aux)+","+regF); //i es el contador de variables auxiliares
                cont_var_aux++;
                //free reg

            } else {
                //search result in TS
                //get reg in the Terceto
                //search result2 in TS
                //get reg2 in the Terceto
                write("ADD reg , reg2");
                write("MOV @aux"+to_string(cont_var_aux)+","+"reg"); //i es el contador de variables auxiliares
                cont_var_aux++;
                //free reg2
            }
        }
    }
}
*/
//**CHARLY**//
void Assembler::asignarRegistro(Terceto &t, string s){
    cout<<"------------------asignar Registro--------------"<<endl;
    /*
    registros[0] (EAX)
    registros[1] (EBX)
    registros[2] (ECX)
    registros[3] (EDX)
    */
    if(s=="MUL" && registros[0]==false && registros[3]==false){
        //todavia no sabemos si ocupa los dos o no
    }
    if(s=="DIV" && registros[0] == false && registros[3] == false){
        //si estan libres asigno al EDX el resto y al EAX el dividendo
        //MOV EAX OP2 (dividendo)
        write("MOV EDX 0");
        write("MOV EAX , " + t.getOp1());
        write("MOV EDX , " + t.getOp2());
    }
    if(s=="ADD"){
        if(registros[1] == false) {
            registros[1] = true;
            t.setOp3("EBX");
        }else {
            if (registros[2] == false) {
                registros[2] = true;
                t.setOp3("ECX");
            }else {
                if (registros[0] == false) {
                    registros[0] = true;
                    t.setOp3("EAX");
                }else{
                    registros[3] = true;
                    t.setOp3("EDX");
                }
            }
        }
    }
    if(s=="SUB"){
        if(registros[1] == false) {
            registros[1] = true;
            t.setOp3("EBX");
        }else{
            if (registros[2] == false) {
                registros[2] = true;
                t.setOp3("ECX");
            }else {
                if (registros[0] == false) {
                    registros[0] = true;
                    t.setOp3("EAX");
                }else{
                    registros[3] = true;
                    t.setOp3("EDX");
                }
            }
        }
    }
    if(s=="COMP"){
        if(registros[1] == false) {
            registros[1] = true;
            t.setOp3("EBX");
        }else{
            if (registros[2] == false) {
                registros[2] = true;
                t.setOp3("ECX");
            }else {
                if (registros[0] == false) {
                    registros[0] = true;
                    t.setOp3("EAX");
                }else{
                    registros[3] = true;
                    t.setOp3("EDX");
                }
            }
        }

    }
}

void Assembler::liberarRegistro(Terceto &t){
    if(t.getOp3() == "EAX")
        registros[0]=0;
    else
        if(t.getOp3() == "EBX")
            registros[1]=0;
        else
            if(t.getOp3() == "ECX")
                registros[2]=0;
            else
                registros[3]=0;
}


void Assembler::BF_int(Terceto  t){
    //COMP
    //BF es JLE en assembler
    cout<<"------------------CASE 2--------------"<<endl;
    //search & get reg Terceto in list_tercetos
    Terceto t2 = Intermediate_code::searchTerceto(quitarCorchetes(t.getOp1()));
    if(t2.getOp() == ">"){
        write("JLE Label" + t.getOp2());
    }
    if(t2.getOp() == "<"){
        write("JGE Label" + t.getOp2());
    }
    if(t2.getOp() == ">="){
        write("JL Label" + t.getOp2());
    }
    if(t2.getOp() == "<="){
        write("JG Label" + t.getOp2());
    }

    //
}

void Assembler::comp_int(Terceto  t){

        cout<<"------------------COMP INT--------------"<<endl;
        if (getCase(t.getOp1(), t.getOp2()) == 1) {
            cout<<"------------------CASE 1--------------"<<endl;
            //set free reg in the Terceto
            asignarRegistro(t,"COMP");
            write("MOV " + t.getOp3() + "," + t.getOp1());
            write("COMP " + t.getOp3() + "," + t.getOp2());
        } else {
            if (getCase(t.getOp1(), t.getOp2()) == 2){
                cout<<"------------------CASE 2--------------"<<endl;
                //search & get reg Terceto in list_tercetos
                Terceto t2 = Intermediate_code::searchTerceto(quitarCorchetes(t.getOp1()));
                write("COMP " + t2.getOp3() + "," + t.getOp2());
            } else {
                if (getCase(t.getOp1(), t.getOp2()) == 3) {
                    cout<<"------------------CASE 3--------------"<<endl;
                    //search & get reg Terceto in list_tercetos
                    Terceto t2 = Intermediate_code::searchTerceto(quitarCorchetes(t.getOp1()));
                    //get reg in the Terceto
                    asignarRegistro(t,"ADD");
                    write("MOV " + t.getOp3() + "," + t.getOp1());
                    //get reg in the Terceto
                    write("COMP " + t.getOp3() + "," + t2.getOp3());
                    //free reg2 ((LLAMAR AL PROC DE CHARLY)) ((SACAR EL REG DE T2))
                    liberarRegistro(t2);
                } else {
                    cout<<"------------------CASE 4--------------"<<endl;
                    //search & get Terceto in list_tercetos
                    Terceto t1 = Intermediate_code::searchTerceto(quitarCorchetes(t.getOp1()));
                    Terceto t2 = Intermediate_code::searchTerceto(quitarCorchetes(t.getOp1()));
                    write("COMP " + t1.getOp3() + "," + t2.getOp3());
                    //free reg2 ((LLAMAR AL PROC DE CHARLY)) ((SACAR EL REG DE T2))
                    liberarRegistro(t2);
                }
            }

    }
}
void Assembler::invoke_out(Terceto t){
    write(t.getOp() + ":");
}
void Assembler::BI_int(Terceto t){

}

constexpr unsigned int str2int(const char* str, int h = 0)
{
    return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}


void Assembler::seguimiento_registros(Terceto t){

    string str = t.getOp();
    char * op = new char[str.length() + 1];
    strcpy(op, str.c_str());

    switch (str2int(op))
    {
        case str2int("+"):
            addInt(t);
            break;
        case str2int("-"):
            subInt(t);
            break;
        case str2int("<"):
            comp_int(t);
            break;
        case str2int(">"):
            comp_int(t);
            break;
        //MUL Y DIV FALTAN
    }
}

void Assembler::variables_auxiliares(Terceto t){

    string str = t.getOp();
    char * op = new char[str.length() + 1];
    strcpy(op, str.c_str());

    switch (str2int(op))
    {
        case str2int("+"):
            addInt(t); //CAMBIAR
            break;
        case str2int("-"):
            subInt(t); //HACER
            break;

        case str2int("<"):
            comp_int(t); //HACER
            break;
        case str2int(">"):
            comp_int(t);
        //MUL Y DIV FALTAN
    }
}

void Assembler::generarAssembler(){
    cout<<"------------------ASSEMBLER--------------"<<endl;
    write(".code");
    for (map<int,Terceto>::iterator it=Intermediate_code::list_tercetos.begin(); it!=Intermediate_code::list_tercetos.end(); ++it){
        Terceto t = it->second;
        string str = t.getOp();
        char * op = new char[str.length() + 1];
        strcpy(op, str.c_str());

        if(str.find("Label") != -1){
            write(t.getOp() + ":");
        }
        switch (str2int(op))
        {

            case str2int("="):
                asignacion(t);
                break;
            case str2int("OUT"):
                cout<<"OUT_"<<endl;
                write("invoke MessageBox, NULL, addr str1, addr str1 , MB_OK");
                break;
            case str2int("BF"):
                cout<<"BF_"<<endl;
                BF_int(t);
                break;

            case str2int("BI"):
                write("JMP Label" + t.getOp1() );
                break;
            case str2int("Call"):
                cout<<"CALL_"<<endl;
                break;

            default:
                if( 5 > 4){ //Depende el tipo xd
                    seguimiento_registros(t);

                }
                else{
                    variables_auxiliares(t);
                }

        }
    }
}
