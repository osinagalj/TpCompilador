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
        write("option casemap :none");
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

void Assembler::declareString(const string & varName, const string & value){
    data.push_back("str"+to_string(current_string)+" DB " + value + " , 0 ");// faltaria poner el contenido del string tmb
    vars.push_back(varName);
    fileStream <<"    str"+to_string(current_string)+" DB " + value + " , 0 "<<endl;

    var_strings.push_back(value);
    current_string++;
}

void Assembler::declareFloat(const string &varName){
    // initializes it with no initial value
    data.push_back(varName + " DD ? ");
    bits[varName] = 16;
    vars.push_back(varName);
    fileStream <<"    "+varName + " DD ? "<<endl;
}

void Assembler::declareSTVariables(Symbol_table * st){
    fileStream <<".DATA"<<endl;
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
    fileStream <<space + message<< endl;
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
Terceto Assembler::searchTerceto(int num) {
    map<int,Terceto>::iterator it=lista_tercetos.begin();
    for (int i=1; i<num;i++){
        it++;
    }
    return it->second;
}

int Assembler::quitarCorchetes(string op){
    cout<<"OP del stoi = " << op <<endl;
    return stoi(op.substr(1,op.size()-1));
}

void Assembler::asignacion(Terceto &t){


    if (isVariable(t.getOp2()) || isConstant(t.getOp2())){
        asignarRegistro(t,"ADD");
        write("MOV " + t.getOp3() + "," + t.getOp1());
        write("MOV " + t.getOp3() + "," + t.getOp2());
        liberarRegistro(t);
    }else{
        cout<<"fue a buscar el terceto: " + t.getOp2()<<endl;
        Terceto t2 = searchTerceto(quitarCorchetes(t.getOp2()));
        cout<<"se trajo el terceto: " + t2.getOp() + t2.getOp1() + t2.getOp2() + t2.getOp3()<<endl;
        write("MOV " + t.getOp1() + "," + t2.getOp3());
        liberarRegistro(t2);
    }

}

void Assembler::asignacionFloat(Terceto &t){

    if (isVariable(t.getOp2()) || isConstant(t.getOp2())){
        asignarRegistro(t,"ADD");
        write("MOV " + t.getOp3() + "," + t.getOp2());
        write("MOV " + t.getOp1() + "," + t.getOp3());
        liberarRegistro(t);
    }else{
        cout<<"fue a buscar el terceto: " + t.getOp2()<<endl;
        Terceto t2 = searchTerceto(quitarCorchetes(t.getOp2()));
        cout<<"se trajo el terceto: " + t2.getOp() + t2.getOp1() + t2.getOp2() + t2.getOp3()<<endl;
        asignarRegistro(t,"ADD");
        write("MOV " + t.getOp3() + "," + t2.getOp3());
        write("MOV " + t.getOp1() + "," + t.getOp3());
        liberarRegistro(t);
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
            Terceto t2 = searchTerceto(quitarCorchetes(t.getOp1()));
            write("ADD " + t2.getOp3() + "," + t.getOp2());
        } else {
            if (getCase(t.getOp1(), t.getOp2()) == 3) {
                cout<<"------------------CASE 3--------------"<<endl;
                //search & get reg Terceto in list_tercetos
                Terceto t2 = searchTerceto(quitarCorchetes(t.getOp2()));
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
                Terceto t1 = searchTerceto(quitarCorchetes(t.getOp1()));
                Terceto t2 = searchTerceto(quitarCorchetes(t.getOp2()));
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
            Terceto t2 = searchTerceto(quitarCorchetes(t.getOp1()));
            write("SUB " + t2.getOp3() + "," + t.getOp2());
        } else {
            if (getCase(t.getOp1(), t.getOp2()) == 3) {
                cout<<"------------------CASE 3--------------"<<endl;
                //search & get reg Terceto in list_tercetos
                Terceto t2 = searchTerceto(quitarCorchetes(t.getOp2()));
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
                Terceto t1 = searchTerceto(quitarCorchetes(t.getOp1()));
                Terceto t2 = searchTerceto(quitarCorchetes(t.getOp1()));
                write("SUB " + t1.getOp3() + "," + t2.getOp3());
                //free reg2 ((LLAMAR AL PROC DE CHARLY)) ((SACAR EL REG DE T2))
                liberarRegistro(t2);
            }
        }
    }
}

void Assembler:: mulInt(Terceto &t){
    cout<<"------------------MUL INT--------------"<<endl;
    if (getCase(t.getOp1(), t.getOp2()) == 1) { //const y variable
        cout<<"------------------CASE 1--------------"<<endl;
        //set free reg in the Terceto
        asignarRegistro(t,"MUL");
        write("MOV " + t.getOp3() + "," + t.getOp2());
        write("MUL " + t.getOp3());
        write("MOV " + t.getOp3() + "," + "EAX");

    } else {
        if (getCase(t.getOp1(), t.getOp2()) == 2){ //registro y variable
            cout<<"------------------CASE 2--------------"<<endl;
            Terceto t1 = searchTerceto(quitarCorchetes(t.getOp1()));

            if(registros[0]==false && registros[3]==false) {
                t.setOp3(t1.getOp3());
                write("MOV EAX , " + t.getOp2());
                write("MUL " + t.getOp3());
                write("MOV " + t.getOp3() + "," + "EAX");
            }
        } else {
            if (getCase(t.getOp1(), t.getOp2()) == 3) { //variable y registro
                cout<<"------------------CASE 3--------------"<<endl;
                Terceto t1 = searchTerceto(quitarCorchetes(t.getOp2()));
                if(registros[0]==false && registros[3]==false) {
                    t.setOp3(t1.getOp3());
                    write("MOV EAX , " + t.getOp1());
                    write("MUL " + t.getOp3());
                    write("MOV " + t.getOp3() + "," + "EAX");
                }
            } else {  //registro y registro
                cout<<"------------------CASE 4--------------"<<endl;
                //search & get Terceto in list_tercetos
                Terceto t1 = searchTerceto(quitarCorchetes(t.getOp1()));
                Terceto t2 = searchTerceto(quitarCorchetes(t.getOp2()));

                if(registros[0]==false && registros[3]==false) {
                    write("MOV EAX , " + t2.getOp3());
                    liberarRegistro(t2);
                    write("MUL " + t1.getOp3());
                    write("MOV " + t1.getOp3() + "," + "EAX");
                    t.setOp3(t1.getOp3());
                }

            }
        }
    }
}

void Assembler::divInt(Terceto &t) {
    cout<<"------------------DIV INT--------------"<<endl;
    if (getCase(t.getOp1(), t.getOp2()) == 1) {//const y variable
        cout<<"------------------CASE 1--------------"<<endl;
        //set free reg in the Terceto
        asignarRegistro(t,"DIV");
        write("MOV " + t.getOp3() + "," + t.getOp2());
        //controlar si el t.getOp3 es distinto de 0
        write("DIV " + t.getOp3());

    } else {//registro y variable
        if (getCase(t.getOp1(), t.getOp2()) == 2){
            cout<<"------------------CASE 2--------------"<<endl;
            //search & get reg Terceto in list_tercetos
            Terceto t2 = searchTerceto(quitarCorchetes(t.getOp1()));

            if(registros[0] == false && registros[3] == false){
                t.setOp3(t2.getOp3());
                write("MOV EDX ,0");
                write("MOV EAX , " + t2.getOp3());
                //controlar que t.getop2() no sea 0
                write("MOV " + t.getOp3() +  " , " + t.getOp2());
                write("DIV " + t.getOp3());
            }

        } else { //variable y registro
            if (getCase(t.getOp1(), t.getOp2()) == 3) {
                cout<<"------------------CASE 3--------------"<<endl;
                //search & get reg Terceto in list_tercetos
                Terceto t2 = searchTerceto(quitarCorchetes(t.getOp2()));
                //get reg in the Terceto
                if(registros[0] == false && registros[3] == false){
                    write("MOV EDX ,0");
                    write("MOV EAX , " + t.getOp1());
                    t.setOp3(t2.getOp3());
                    //controlar que t.getOp3 no de 0
                    write("DIV " + t.getOp3());
                }
            } else {  //registro y registro
                cout<<"------------------CASE 4--------------"<<endl;
                //search & get Terceto in list_tercetos
                Terceto t1 = searchTerceto(quitarCorchetes(t.getOp1()));
                Terceto t2 = searchTerceto(quitarCorchetes(t.getOp2()));
                if(registros[0] == false && registros[3] == false){
                    t.setOp3(t2.getOp3());
                    write("MOV EDX ,0");
                    write("MOV EAX , " + t1.getOp3());
                    liberarRegistro(t1);
                    //controlar que t.getop3() no sea 0
                    write("DIV " + t.getOp3());
                }
            }
        }
    }
}

void Assembler::addFloat(Terceto &t) {
    cout<<"------------------ADD FLOAT--------------"<<endl;
    if (getCase(t.getOp1(), t.getOp2()) == 1) {
        cout<<"------------------CASE 1--------------"<<endl;
        string new_aux="@aux"+to_string(cont_var_aux);
        asignarRegistro(t,"ADD");
        write("MOV " + t.getOp3() + "," + t.getOp1());
        write("ADD " + t.getOp3() + "," + t.getOp2());
        write("MOV "+ new_aux +","+t.getOp3() ); //i es el contador de variables auxiliares
        liberarRegistro(t);
        t.setOp3(new_aux);
        cont_var_aux++;

    } else {
        if (getCase(t.getOp1(), t.getOp2()) == 2) {
            cout<<"------------------CASE 2--------------"<<endl;
            string new_aux="@aux"+to_string(cont_var_aux);
            //search result in TS
            Terceto t2 = searchTerceto(quitarCorchetes(t.getOp1()));
            write("ADD" +t2.getOp3()+", " + t.getOp2());
            write("MOV "+ new_aux +","+t2.getOp3()); //i es el contador de variables auxiliares
            cont_var_aux++;
            liberarRegistro(t);
            t.setOp3(new_aux);
        } else {
            if (getCase(t.getOp1(), t.getOp2()) == 3) {
                cout<<"------------------CASE 3--------------"<<endl;
                string new_aux="@aux"+to_string(cont_var_aux);
                Terceto t2 = searchTerceto(quitarCorchetes(t.getOp2()));
                write("ADD " + t2.getOp3() + "," + t.getOp1());
                write("MOV "+ new_aux +","+t2.getOp3()); //i es el contador de variables auxiliares
                cont_var_aux++;
                liberarRegistro(t2);
                t2.setOp3(new_aux);

            } else {
                cout<<"------------------CASE 4--------------"<<endl;
                string new_aux="@aux"+to_string(cont_var_aux);
                cont_var_aux++;
                //search result in TS
                 Terceto t1 = searchTerceto(quitarCorchetes(t.getOp1()));
                //search result2 in TS
                 Terceto t2 = searchTerceto(quitarCorchetes(t.getOp2()));
                write("ADD t1.getOp3(), t2.getOp3()");
                write("MOV "+ new_aux +","+t1.getOp3()); //i es el contador de variables auxiliares
                liberarRegistro(t1);
                liberarRegistro(t2);
                t1.setOp3(new_aux);
            }
        }
    }
}

void Assembler::subFloat(Terceto &t) {
    cout<<"------------------SUB FLOAT--------------"<<endl;
    if (getCase(t.getOp1(), t.getOp2()) == 1) {
        cout<<"------------------CASE 1--------------"<<endl;
        string new_aux="@aux"+to_string(cont_var_aux);
        asignarRegistro(t,"ADD");
        write("MOV " + t.getOp3() + "," + t.getOp1());
        write("SUB " + t.getOp3() + "," + t.getOp2());
        write("MOV "+ new_aux +","+t.getOp3() ); //i es el contador de variables auxiliares
        liberarRegistro(t);
        t.setOp3(new_aux);
        cont_var_aux++;

    } else {
        if (getCase(t.getOp1(), t.getOp2()) == 2) {
            cout<<"------------------CASE 2--------------"<<endl;
            string new_aux="@aux"+to_string(cont_var_aux);
            //search result in TS
            Terceto t2 = searchTerceto(quitarCorchetes(t.getOp1()));
            write("SUB" + t2.getOp3()+ ", " + t.getOp2());
            write("MOV "+ new_aux +","+t2.getOp3()); //i es el contador de variables auxiliares
            cont_var_aux++;
            liberarRegistro(t);
            t.setOp3(new_aux);
        } else {
            if (getCase(t.getOp1(), t.getOp2()) == 3) {
                cout<<"------------------CASE 3--------------"<<endl;
                string new_aux="@aux"+to_string(cont_var_aux);
                Terceto t2 = searchTerceto(quitarCorchetes(t.getOp2()));
                write("SUB " + t2.getOp3() + "," + t.getOp1());
                write("MOV "+ new_aux +","+t2.getOp3()); //i es el contador de variables auxiliares
                cont_var_aux++;
                liberarRegistro(t2);
                t2.setOp3(new_aux);

            } else {
                cout<<"------------------CASE 4--------------"<<endl;
                string new_aux="@aux"+to_string(cont_var_aux);
                cont_var_aux++;
                //search result in TS
                Terceto t1 = searchTerceto(quitarCorchetes(t.getOp1()));
                //search result2 in TS
                Terceto t2 = searchTerceto(quitarCorchetes(t.getOp2()));
                write("SUB t1.getOp3(), t2.getOp3()");
                write("MOV "+ new_aux +","+t1.getOp3()); //i es el contador de variables auxiliares
                liberarRegistro(t1);
                liberarRegistro(t2);
                t1.setOp3(new_aux);
            }
        }
    }
}

//CHARLY//
void Assembler::asignarRegistro(Terceto &t, string s){
    cout<<"------------------asignar Registro--------------"<<endl;
    /*
    registros[0] (EAX)
    registros[1] (EBX)
    registros[2] (ECX)
    registros[3] (EDX)
    */
    if(s=="MUL" && registros[0]==false && registros[3]==false) {
        //todavia no sabemos si ocupa los dos o no
        //carga el registro EAX con uno de los productos a multiplicar y luego el terceto con el registro que tiene que contener el otro multiplicador de la multiplicacion
        if (registros[1] == false) {
            registros[1] = true;
            write("MOV EAX , " + t.getOp1());
            t.setOp3("EBX");
            //afuera se hace:
            //write("MOV EBX , " + t.getOp2) (esto si no es un registro ya antes) sino hago write("MUL" EBX)
        } else {
            if (registros[2] == false) {
                registros[2] = true;
                write("MOV EAX , " + t.getOp1());
                t.setOp3("ECX");
            }
        }
    }
    if(s=="DIV" && registros[0] == false && registros[3] == false) {
        //si estan libres asigno al EDX el resto y al EAX el dividendo
        //MOV EAX OP2 (dividendo)
        write("MOV EDX ,0");
        write("MOV EAX , " + t.getOp1());
        if (registros[1] == false) {
            registros[1] = true;
            t.setOp3("EBX");

        } else {
            if (registros[2] == false) {
                registros[2] = true;
                t.setOp3("ECX");
            }
        }
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
    if(s=="CMP"){
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



void Assembler::invoke_out(Terceto t){
    write("invoke MessageBox, NULL, addr str"+ to_string(getNameString(t.getOp1())) + ", addr str"+ to_string(getNameString(t.getOp1())) + ", MB_OK");
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

int Assembler::getNameString(const string & value){
    int i = 0;
    for(string s: var_strings){
        i++;
        if(s == value){
            return i;
        }
    }
    return 0;
}

void Assembler::BF_int(Terceto  &t){
    //COMP
    //BF es JLE en assembler
    cout<<"------------------CASE 2--------------"<<endl;
    //search & get reg Terceto in list_tercetos
    cout<<endl;
    cout<<"CONTENIDO DE BF " << t.getOp1() <<endl;
    Terceto t2 = searchTerceto(quitarCorchetes(t.getOp1()));
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

    cout<<"Termino BF"<<endl;
    //
}

void Assembler::comp_int(Terceto  &t){

        cout<<"------------------COMP INT--------------"<<endl;
        if (getCase(t.getOp1(), t.getOp2()) == 1) {
            cout<<"------------------CASE 1--------------"<<endl;
            //set free reg in the Terceto
            asignarRegistro(t,"CMP");
            write("MOV " + t.getOp3() + "," + t.getOp1());
            write("CMP " + t.getOp3() + "," + t.getOp2());
        } else {
            if (getCase(t.getOp1(), t.getOp2()) == 2){
                cout<<"------------------CASE 2--------------"<<endl;
                //search & get reg Terceto in list_tercetos
                Terceto t2 = searchTerceto(quitarCorchetes(t.getOp1()));
                write("CMP " + t2.getOp3() + "," + t.getOp2());
            } else {
                if (getCase(t.getOp1(), t.getOp2()) == 3) {
                    cout<<"------------------CASE 3--------------"<<endl;
                    //search & get reg Terceto in list_tercetos
                    Terceto t2 = searchTerceto(quitarCorchetes(t.getOp1()));
                    //get reg in the Terceto
                    asignarRegistro(t,"ADD");
                    write("MOV " + t.getOp3() + "," + t.getOp1());
                    //get reg in the Terceto
                    write("CMP " + t.getOp3() + "," + t2.getOp3());
                    //free reg2 ((LLAMAR AL PROC DE CHARLY)) ((SACAR EL REG DE T2))
                    liberarRegistro(t2);
                } else {
                    cout<<"------------------CASE 4--------------"<<endl;
                    //search & get Terceto in list_tercetos
                    Terceto t1 = searchTerceto(quitarCorchetes(t.getOp1()));
                    Terceto t2 = searchTerceto(quitarCorchetes(t.getOp1()));
                    write("CMP " + t1.getOp3() + "," + t2.getOp3());
                    //free reg2 ((LLAMAR AL PROC DE CHARLY)) ((SACAR EL REG DE T2))
                    liberarRegistro(t2);
                }
            }

    }
}

void Assembler::BI_int(Terceto t){

}

constexpr unsigned int str2int(const char* str, int h = 0)
{
    return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}


void Assembler::seguimiento_registros(Terceto &t){

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
        case str2int("*"):
            mulInt(t);
            break;
        case str2int("/"):
            divInt(t);
            break;
        case str2int("<"):
            comp_int(t);
            break;
        case str2int(">"):
            comp_int(t);
            break;
        case str2int("="):
            cout<<"ASIGNACION_"<<endl;
            asignacion(t);
            break;
        //MUL Y DIV FALTAN
    }
}

void Assembler::variables_auxiliares(Terceto &t){

    string str = t.getOp();
    char * op = new char[str.length() + 1];
    strcpy(op, str.c_str());

    switch (str2int(op))
    {
        case str2int("+"):
            addFloat(t);
            break;
        case str2int("-"):
            subFloat(t);
            break;
        case str2int("<"):

            break;
        case str2int(">"):

            break;
        case str2int("="):
            asignacionFloat(t);
            break;
        //MUL Y DIV FALTAN
    }
}

void Assembler::imprimirLista(){
    //cout<< "---------------------- LISTA DE PROCEDIMIENTOS-------------------------"<<endl;
    for (map<int,Terceto>::iterator it=lista_tercetos.begin(); it!=lista_tercetos.end(); ++it){
        cout <<"Nombre del proc: "+ to_string(it->first) <<endl;
        cout<< it->second.getOp()+ " " + it->second.getOp1() + " " +it->second.getOp2() + " " +it->second.getOp3()<<endl;
    }
}


void Assembler::generarCodigoAssembler(Symbol_table *tablita, Terceto & t){
    string str = t.getOp();
    char * op = new char[str.length() + 1];
    strcpy(op, str.c_str());

    if(str.find("Label") != -1){
        write(t.getOp() + ":");
    }
    switch (str2int(op))
    {

        case str2int("OUT"):
            cout<<"OUT_"<<endl;
            invoke_out(t);
            break;
        case str2int("BF"):
            cout<<"BF_"<<endl;
            BF_int(t);
            break;

        case str2int("BI"):
            cout<<"BI_"<<endl;
            write("JMP Label" + t.getOp1());

            break;
        case str2int("Call"):
            cout<<"CALL_"<<endl;
            break;

        default:
            string tipo = tablita->getRegistry(t.getOp1()).Tipo;
            if( tipo == "Longint"){ //Depende el tipo xd
                seguimiento_registros(t);
            }
            else if( tipo == "Float"){
                variables_auxiliares(t);
            }else{
                cout<<"los casos que faltan agregar"<<endl;
            }

    }
}

bool Assembler::tercetoDeProc(int i,list<int> listita){
   // cout<<"TERCETOPRO= "<< endl;
    for(list<int>::iterator it = listita.begin(); it != listita.end(); it++){
        //cout<<"*it= "<<*it<< "  i="<<i<< endl;
        if(*it == i){
            return true;
        }
    }
    return false;
}

void Assembler::generarAssembler(Symbol_table *tablita,list<int> listita){
    Intermediate_code::copiarLista(lista_tercetos);
    cout<<"------------------ASSEMBLER--------------"<<endl;
    write(".CODE");
    cout<<"TAMAÑO DE IGNORE "<<to_string(listita.size())<<endl;
    space = "    ";
    for (map<int,Terceto>::iterator it=lista_tercetos.begin(); it!=lista_tercetos.end(); ++it){
        space = "        ";
        if(tercetoDeProc(it->first,listita)){

            if(it->second.getOp()=="inicio_PROC"){
                space = "    ";
                write(it->second.getOp1()+ ":");
            }
            generarCodigoAssembler(tablita,it->second);
        }
    }
    space ="";
    write("START:");
    space = space + "    ";
    for (map<int,Terceto>::iterator it=lista_tercetos.begin(); it!=lista_tercetos.end(); ++it){
        if(!tercetoDeProc(it->first,listita)){
            generarCodigoAssembler(tablita,it->second);
        }
    }
    space ="";
    write("END START");
}
