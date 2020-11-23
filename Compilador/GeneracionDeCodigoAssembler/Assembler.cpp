#include "Assembler.h"
#include <string.h>

Assembler::Assembler(){}

Assembler::Assembler(string path ){
        open(path);
}


//--------------------------------------------------------------------------------------//
//-------------------------------------- DATA   ----------------------------------------//
//--------------------------------------------------------------------------------------//

void Assembler::writeAssembler(){



    fileStream << ".386" << endl;
    fileStream << ".model flat, stdcall" << endl;
    fileStream << "option casemap :none" << endl;
    fileStream << "include \\masm32\\include\\masm32rt.inc" << endl;
    fileStream << "include \\masm32\\include\\windows.inc" << endl;
    fileStream << "include \\masm32\\include\\kernel32.inc" << endl;
    fileStream << "include \\masm32\\include\\user32.inc" << endl;
    fileStream << "includelib \\masm32\\lib\\kernel32.lib" << endl;
    fileStream << "includelib \\masm32\\lib\\user32.lib" << endl << endl;


    string error="\"Error: Se ha realizado una divison por 0\"";
    string error2="\"Error: No esta permitida la recursion en un procedimiento\"";
    if(existeDivision0){
        declareString(error,error);
    }
    declareString(error2,error2);


    fileStream <<".DATA"<<endl;
    for(string s: data){
        fileStream<<s<<endl;
    }
    fileStream <<".CODE"<<endl;
    insertar_ret();
    insertar_ENDP();
    for(string s: code){
        fileStream<<s<<endl;
    }
    if(!code.empty()){
        fileStream <<"        ret"<<endl;
        fileStream <<"    "+ nombreauxproc + "ENDP "<<endl;
    }

    if(existeDivision0){
        fileStream<<"      Error :"<<endl;
        fileStream<<"        invoke MessageBox, NULL, addr str"+ to_string(getNameString(error)) + ", addr str"+ to_string(getNameString(error)) + ", MB_OK" <<endl;
        fileStream<<"        invoke ExitProcess, 0 "<<endl;
    }

    fileStream<<"      Error_recursion :"<<endl;
    fileStream<<"        invoke MessageBox, NULL, addr str"+ to_string(getNameString(error2)) + ", addr str"+ to_string(getNameString(error2)) + ", MB_OK" <<endl;
    fileStream<<"        invoke ExitProcess, 0 "<<endl;



    fileStream <<"START:"<<endl;
    for(string s: program){
        fileStream<<s<<endl;
    }
    fileStream <<"END START"<<endl;
}


void Assembler::declareLongint(const string & varName){
    vars.push_back(varName);
    data.push_back("    "+varName + " DD ?");
}
void Assembler::declareLongint(const string & varName,const string & value){
    vars.push_back(varName);
    data.push_back("    "+varName + " DD "+ value);
}

void Assembler::declareFloat(const string &varName){
    vars.push_back(varName);
    data.push_back("    " + varName + " DD ? ");
}

void Assembler::declareString(const string & varName, const string & value){
    vars.push_back(varName);
    data.push_back("    str"+to_string(current_string)+" DB " + value + " , 0 ");// faltaria poner el contenido del string tmb
    var_strings.push_back(value);
    current_string++;
}
void Assembler::declareAux(const string &varName){
    vars.push_back(varName);
    data.push_back("    " + varName + " DD ? ");
}
void Assembler::declareAux(const string &varName,const string & f){
    vars.push_back(varName);
    data.push_back("    " + varName + " DD " +f);
}


void Assembler::declareSTVariables(Symbol_table * st){

    for(auto it = st->symbol_table.begin(); it!= st->symbol_table.end(); it++){

        if(it->second.uso == "variable" || it->second.uso == "parametro"){
            string name = it->first;
            if(it->second.Tipo == "Float"){
                declareFloat(name);
            }else{
                declareLongint(name);
            }
        }else if(it->second.uso == "constante"){ //Preguntar si tenemos que definir los strings
            if(it->second.Tipo == "String") {
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
    if(in_procedure){
        code.push_back(space + message);
    }else{
        program.push_back(space + message);
    }
}


//----------------------------------------------------------------------------------------//
//---------------------------------- Aritmethic Operations -------------------------------//
//----------------------------------------------------------------------------------------//

bool Assembler::isConstant(string op){
   if (!isRegister(op) && !isVariable(op)){
       return true;
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
    return stoi(op.substr(1,op.size()-1));
}

void Assembler::asignacion(Terceto &t){


    if (isVariable(t.getOp2()) || isConstant(t.getOp2())){
        asignarRegistro(t,"ADD");
        write("MOV " + t.getOp3() + "," + t.getOp2()); //reg = op1
        write("MOV " + t.getOp1() + "," + t.getOp3()); //reg = op2
        liberarRegistro(t);
    }else{
        Terceto t2 = searchTerceto(quitarCorchetes(t.getOp2()));
        write("MOV " + t.getOp1() + "," + t2.getOp3());
        liberarRegistro(t2);
    }

}

void Assembler::asignacionFloat(Terceto &t){

    if (isVariable(t.getOp2()) || isConstant(t.getOp2())){
        if(isConstant(t.getOp2())){
            string new_aux="@aux"+to_string(cont_var_aux);
            cont_var_aux++;
            declareAux(new_aux,t.getOp2());
            write("FLD " + new_aux);
        }else{
            write("FLD " + t.getOp2());
        }
        //asignarRegistro(t,"ADD");
        //write("MOV " + t.getOp3() + "," + t.getOp2());
        //write("MOV " + t.getOp1() + "," + t.getOp3());

        write("FSTP " + t.getOp1());
        //liberarRegistro(t);
    }else{
        Terceto t2 = searchTerceto(quitarCorchetes(t.getOp2()));
        //asignarRegistro(t,"ADD");
        //write("MOV " + t.getOp3() + "," + t2.getOp3());
        //write("MOV " + t.getOp1() + "," + t.getOp3());
        //liberarRegistro(t);
        write("FLD " + t2.getOp3());
        write("FSTP " + t.getOp1());
    }
}


void Assembler::addInt(Terceto &t) {

    if (getCase(t.getOp1(), t.getOp2()) == 1) {
        asignarRegistro(t,"ADD");
        write("MOV " + t.getOp3() + "," + t.getOp1());
        write("ADD " + t.getOp3() + "," + t.getOp2());
    } else {
        if (getCase(t.getOp1(), t.getOp2()) == 2){
            //search & get reg Terceto in list_tercetos
            Terceto t2 = searchTerceto(quitarCorchetes(t.getOp1()));
            write("ADD " + t2.getOp3() + "," + t.getOp2());
        } else {
            if (getCase(t.getOp1(), t.getOp2()) == 3) {
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
    if (getCase(t.getOp1(), t.getOp2()) == 1) {
        //set free reg in the Terceto
        asignarRegistro(t,"SUB");
        write("MOV " + t.getOp3() + "," + t.getOp1());
        write("SUB " + t.getOp3() + "," + t.getOp2());

    } else {
        if (getCase(t.getOp1(), t.getOp2()) == 2){
            //search & get reg Terceto in list_tercetos
            Terceto t2 = searchTerceto(quitarCorchetes(t.getOp1()));
            write("SUB " + t2.getOp3() + "," + t.getOp2());
        } else {
            if (getCase(t.getOp1(), t.getOp2()) == 3) {
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
    if (getCase(t.getOp1(), t.getOp2()) == 1) { //const y variable
        //set free reg in the Terceto
        asignarRegistro(t,"MUL");
        write("MOV " + t.getOp3() + "," + t.getOp2());
        write("MUL " + t.getOp3());
        write("MOV " + t.getOp3() + "," + "EAX");

    } else {
        if (getCase(t.getOp1(), t.getOp2()) == 2){ //registro y variable
            Terceto t1 = searchTerceto(quitarCorchetes(t.getOp1()));
            if(registros[0]==false && registros[3]==false) {
                t.setOp3(t1.getOp3());
                write("MOV EAX , " + t.getOp2());
                write("MUL " + t.getOp3());
                write("MOV " + t.getOp3() + "," + "EAX");
            }
        } else {
            if (getCase(t.getOp1(), t.getOp2()) == 3) { //variable y registro
                Terceto t1 = searchTerceto(quitarCorchetes(t.getOp2()));
                if(registros[0]==false && registros[3]==false) {
                    t.setOp3(t1.getOp3());
                    write("MOV EAX , " + t.getOp1());
                    write("MUL " + t.getOp3());
                    write("MOV " + t.getOp3() + "," + "EAX");
                }
            } else {  //registro y registro
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

//CHARLY//
void Assembler::divInt(Terceto &t) {
    existeDivision0 = true;
    if (getCase(t.getOp1(), t.getOp2()) == 1) {//const y variable
        //set free reg in the Terceto
        asignarRegistro(t,"DIV");
        write("MOV " + t.getOp3() + "," + t.getOp2());
        //cargo valor para comparar
        write("CMP " + t.getOp2() + ", 0");
        //salto si es cero el CMP
        write("JE Error");
        //falta cortar el programa
        write("DIV " + t.getOp3());


    } else {//registro y variable
        if (getCase(t.getOp1(), t.getOp2()) == 2){
            //search & get reg Terceto in list_tercetos
            Terceto t2 = searchTerceto(quitarCorchetes(t.getOp1()));

            if(registros[0] == false && registros[3] == false){
                t.setOp3(t2.getOp3());
                write("MOV EDX 0");
                write("MOV EAX , " + t2.getOp3());
                //controlar que t.getop2() no sea 0
                write("MOV " + t.getOp3() +  " , " + t.getOp2());

                //cargo valor para comparar
                write("CMP " + t.getOp3()+ ", 0");
                //salto si es cero el CMP
                write("JE Error");


                //cortar Programa


                write("DIV " + t.getOp3());
            }

        } else { //variable y registro
            if (getCase(t.getOp1(), t.getOp2()) == 3) {
                //search & get reg Terceto in list_tercetos
                Terceto t2 = searchTerceto(quitarCorchetes(t.getOp2()));
                //get reg in the Terceto
                if(registros[0] == false && registros[3] == false){
                    write("MOV EDX 0");
                    write("MOV EAX , " + t.getOp1());
                    t.setOp3(t2.getOp3());

                    //cargo valor para comparar
                    write("CMP " + t.getOp3()+ ", 0");
                    //salto si es cero el CMP
                    write("JE Error");

                    //cortar Programa


                    write("DIV " + t.getOp3());
                }
            } else {  //registro y registro
                //search & get Terceto in list_tercetos
                Terceto t1 = searchTerceto(quitarCorchetes(t.getOp1()));
                Terceto t2 = searchTerceto(quitarCorchetes(t.getOp2()));
                if(registros[0] == false && registros[3] == false){
                    t.setOp3(t2.getOp3());
                    write("MOV EDX 0");
                    write("MOV EAX , " + t1.getOp3());
                    liberarRegistro(t1);

                    //cargo valor para comparar
                    write("CMP " + t2.getOp3()+ ", 0");
                    //salto si es cero el CMP
                    write("JE Error");
                    //cortar Programa


                    write("DIV " + t.getOp3());
                }
            }
        }

    }

}

void Assembler::addFloat(Terceto &t) {
    if (getCase(t.getOp1(), t.getOp2()) == 1) {
        string new_aux="@aux"+to_string(cont_var_aux);

        if(isConstant(t.getOp1()) && isVariable(t.getOp2())){
            declareAux(new_aux,t.getOp1());
            write("FLD " + new_aux);
            write("FLD " + t.getOp2());
            cont_var_aux++;
        }
        if(isConstant(t.getOp2()) && isVariable(t.getOp1()) ){
                declareAux(new_aux,t.getOp2());
                write("FLD " + new_aux);
                write("FLD " + t.getOp1());
            cont_var_aux++;
        }
        if((isConstant(t.getOp2()) && isConstant(t.getOp1()))){

                declareAux(new_aux,t.getOp1());
            cont_var_aux++;
            string new_aux2="@aux"+to_string(cont_var_aux);
            cont_var_aux++;
                declareAux(new_aux2,t.getOp2());
                write("FLD " + new_aux);
                write("FLD " + new_aux2);
        }
        if((isVariable(t.getOp2()) && isVariable(t.getOp1()))){
            write("FLD " + t.getOp1());
            write("FLD " + t.getOp2());
        }
        //asignarRegistro(t,"ADD");
        //write("MOV " + t.getOp3() + "," + t.getOp1());

        string new_aux3="@aux"+to_string(cont_var_aux);
        declareAux(new_aux3);
        write("FADD ");
        write("FSTP "+ new_aux3); //i es el contador de variables auxiliares
        //liberarRegistro(t);
        t.setOp3(new_aux3);
        cont_var_aux++;

    } else {
        if (getCase(t.getOp1(), t.getOp2()) == 2) {
            string new_aux="@aux"+to_string(cont_var_aux);
            declareAux(new_aux);
            //search result in TS
            Terceto t2 = searchTerceto(quitarCorchetes(t.getOp1()));
            //write("ADD" +t2.getOp3()+", " + t.getOp2());
            //write("MOV "+ new_aux +","+t2.getOp3()); //i es el contador de variables auxiliares
            write("FLD " + t2.getOp3());
            write("FLD " + t.getOp2());
            write("FADD ");
            write("FSTP "+ new_aux); //i es el contador de variables auxiliares
            cont_var_aux++;
            //liberarRegistro(t);
            t.setOp3(new_aux);
        } else {
            if (getCase(t.getOp1(), t.getOp2()) == 3) {
                string new_aux="@aux"+to_string(cont_var_aux);
                declareAux(new_aux);
                Terceto t2 = searchTerceto(quitarCorchetes(t.getOp2()));
                //write("ADD " + t2.getOp3() + "," + t.getOp1());
                //write("MOV "+ new_aux +","+t2.getOp3()); //i es el contador de variables auxiliares
                write("FLD " + t.getOp1());
                write("FLD " + t2.getOp3());
                write("FADD ");
                write("FSTP "+ new_aux); //i es el contador de variables auxiliares
                cont_var_aux++;
                //liberarRegistro(t2);
                t2.setOp3(new_aux);

            } else {
                string new_aux="@aux"+to_string(cont_var_aux);
                declareAux(new_aux);
                cont_var_aux++;
                //search result in TS
                 Terceto t1 = searchTerceto(quitarCorchetes(t.getOp1()));
                //search result2 in TS
                 Terceto t2 = searchTerceto(quitarCorchetes(t.getOp2()));
                //write("ADD t1.getOp3(), t2.getOp3()");
                //write("MOV "+ new_aux +","+t1.getOp3()); //i es el contador de variables auxiliares
                //liberarRegistro(t1);
                //liberarRegistro(t2);
                write("FLD " + t1.getOp3());
                write("FLD " + t2.getOp3());
                write("FADD ");
                write("FSTP "+ new_aux); //i es el contador de variables auxiliares
                t1.setOp3(new_aux);
            }
        }
    }
}

void Assembler::subFloat(Terceto &t) {
    if (getCase(t.getOp1(), t.getOp2()) == 1) {
        string new_aux="@aux"+to_string(cont_var_aux);
        declareAux(new_aux);
        //asignarRegistro(t,"ADD");
        //write("MOV " + t.getOp3() + "," + t.getOp1());
        write("FLD " + t.getOp1());
        write("FLD " + t.getOp2());
        write("FSUB ");
        write("FSTP "+ new_aux); //i es el contador de variables auxiliares
        //liberarRegistro(t);
        t.setOp3(new_aux);
        cont_var_aux++;

    } else {
        if (getCase(t.getOp1(), t.getOp2()) == 2) {
            string new_aux="@aux"+to_string(cont_var_aux);
            declareAux(new_aux);
            //search result in TS
            Terceto t2 = searchTerceto(quitarCorchetes(t.getOp1()));
            //write("ADD" +t2.getOp3()+", " + t.getOp2());
            //write("MOV "+ new_aux +","+t2.getOp3()); //i es el contador de variables auxiliares
            write("FLD " + t2.getOp3());
            write("FLD " + t.getOp2());
            write("FSUB ");
            write("FSTP "+ new_aux); //i es el contador de variables auxiliares
            cont_var_aux++;
            //liberarRegistro(t);
            t.setOp3(new_aux);
        } else {
            if (getCase(t.getOp1(), t.getOp2()) == 3) {
                string new_aux="@aux"+to_string(cont_var_aux);
                declareAux(new_aux);
                Terceto t2 = searchTerceto(quitarCorchetes(t.getOp2()));
                //write("ADD " + t2.getOp3() + "," + t.getOp1());
                //write("MOV "+ new_aux +","+t2.getOp3()); //i es el contador de variables auxiliares
                write("FLD " + t.getOp1());
                write("FLD " + t2.getOp3());
                write("FSUB ");
                write("FSTP "+ new_aux); //i es el contador de variables auxiliares
                cont_var_aux++;
                //liberarRegistro(t2);
                t2.setOp3(new_aux);

            } else {
                string new_aux="@aux"+to_string(cont_var_aux);
                declareAux(new_aux);
                cont_var_aux++;
                //search result in TS
                Terceto t1 = searchTerceto(quitarCorchetes(t.getOp1()));
                //search result2 in TS
                Terceto t2 = searchTerceto(quitarCorchetes(t.getOp2()));
                //write("ADD t1.getOp3(), t2.getOp3()");
                //write("MOV "+ new_aux +","+t1.getOp3()); //i es el contador de variables auxiliares
                //liberarRegistro(t1);
                //liberarRegistro(t2);
                write("FLD " + t1.getOp3());
                write("FLD " + t2.getOp3());
                write("FSUB ");
                write("FSTP "+ new_aux); //i es el contador de variables auxiliares
                t1.setOp3(new_aux);
            }
        }
    }
}

//CHARLY//
void Assembler::asignarRegistro(Terceto &t, string s){
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

void Assembler::insertar_ENDP(){
    list<int> posiciones_ret;
    list<string> nombres_proc;
    int i = 0;
    for(string s: code){
        i++;
        if(s.find('@') != -1){
            if(s.find("PROC") != -1){
                nombres_proc.push_back(s);

            }
        }
    }
    i = 0;
    for(string s: code){
        i++;
        if(s.find("ret") != -1){
                posiciones_ret.push_back(i);
        }
    }

    int rets = 0;

    if(nombres_proc.size()>0){
        string auxx = nombres_proc.back();
        nombreauxproc = auxx.substr(0,auxx.size()-4);
    }

    for(int i : posiciones_ret){
        int x = 0;
        for(vector<string>::iterator it = code.begin() ;it != code.end();it++){
            x ++;
            if(x == i+rets){
                string s = nombres_proc.front();
                string aux_s = s.substr(0,s.size()-4);
                nombres_proc.pop_front();
                it++;
                code.insert(it,"    "+aux_s +" ENDP");
                rets++;
                it--;
                break;
            }
        }
    }

}
void Assembler::insertar_ret(){
    list<int> posiciones_ret;
    list<string> nombres_proc;
    int i = 0;
    for(string s: code){
        i++;
        if(s.find('@') != -1){
            if(s.find("PROC") != -1){
                posiciones_ret.push_back(i);
                nombres_proc.push_back(s);

            }
        }
    }

    int rets = 0;
    posiciones_ret.pop_front();

    for(int i : posiciones_ret){
        int x = 0;
        for(vector<string>::iterator it = code.begin() ;it != code.end();it++){
            x ++;
            if(x == i+rets){
                code.insert(it,"        ret");
                //code.push_back("     END PROC");
                rets++;
                break;
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
}

void Assembler::comp_int(Terceto  &t){

        if (getCase(t.getOp1(), t.getOp2()) == 1) {
            //set free reg in the Terceto
            asignarRegistro(t,"CMP");
            write("MOV " + t.getOp3() + "," + t.getOp1());
            write("CMP " + t.getOp3() + "," + t.getOp2());
        } else {
            if (getCase(t.getOp1(), t.getOp2()) == 2){
                //search & get reg Terceto in list_tercetos
                Terceto t2 = searchTerceto(quitarCorchetes(t.getOp1()));
                write("CMP " + t2.getOp3() + "," + t.getOp2());
            } else {
                if (getCase(t.getOp1(), t.getOp2()) == 3) {
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
            invoke_out(t);
            break;
        case str2int("BF"):
            BF_int(t);
            break;

        case str2int("BI"):
            write("JMP Label" + t.getOp1());

            break;
        case str2int("Call"):
            write("CALL " + t.getOp1());
            break;

        default:
            string tipo = tablita->getRegistry(t.getOp1()).Tipo;
            if( tipo == "Longint"){ //Depende el tipo xd
                seguimiento_registros(t);
            }
            else if( tipo == "Float"){
                variables_auxiliares(t);
            }
    }
}



bool Assembler::tercetoDeProc(int i,list<int> listita){
    for(list<int>::iterator it = listita.begin(); it != listita.end(); it++){
        if(*it == i){
            return true;
        }
    }
    return false;
}

void Assembler::generarAssembler(Symbol_table *tablita,list<int> listita){
    Intermediate_code::copiarLista(lista_tercetos);
    space = "    ";
    in_procedure = true;
    bool fin_proc = false;
    for (map<int,Terceto>::iterator it=lista_tercetos.begin(); it!=lista_tercetos.end(); ++it){
        space = "        ";
        if(tercetoDeProc(it->first,listita)){

            if(it->second.getOp()=="inicio_PROC"){
                fin_proc = false;
                space = "    ";
                code.push_back(space + it->second.getOp1()+ " PROC");
                declareLongint("_"+it->second.getOp1(), "0");
                space = "        ";
                write("CMP _" +it->second.getOp1()+", 1");

                write("JE Error_recursion");
                write("MOV _"+it->second.getOp1()+", 1");
            }



            generarCodigoAssembler(tablita,it->second);

        }
    }
    in_procedure = false;
    space ="";
    //write("START:");
    space = space + "    ";
    int i = 0;
    for (map<int,Terceto>::iterator it=lista_tercetos.begin(); it!=lista_tercetos.end(); ++it){
        if(!tercetoDeProc(it->first,listita)){
            i++;
            cout << to_string(i)<<".  " << "(" << it->second.getOp() << " , " << it->second.getOp1() << " , " << it->second.getOp2() <<" ) "<<'\n';
            generarCodigoAssembler(tablita,it->second);
        }
    }
    space ="";
    cout<<"\n--Se generara el codigo assembler en el archivo out_assembler.asm"<<endl;
}
