#include "AccionesSemanticas.h"
#include "yylex.h"

//Cambiar todos los id poruqe los asigna el sintactico solo

void AccionesSemanticas::inicializarToken(Yylex* lexico, char& c){
    lexico->cadena = c;
    lexico->aumentarCaracter();
}
void AccionesSemanticas::agregarCaracter(Yylex* lexico, char& c){
    lexico->cadena = lexico->cadena + c;
    lexico->aumentarCaracter();
}
void AccionesSemanticas::devolverIdentificador(Yylex* lexico, char& c){
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    //Chekear el rango
    if(lexico->cadena.length() > longIdentificador){
        lexico->cadena =  lexico->cadena.substr (0,20);
        lexico->guardarToken(MINUSCULA, lexico->cadena,"Identificador supera la longitud maxima de 20 caracteres");
    }else{
        lexico->guardarToken(MINUSCULA, lexico->cadena,"");
    }
}
void AccionesSemanticas::devolverReservada(Yylex* lexico, char& c){
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->guardarToken(MAYUSCULA, lexico->cadena,"");
}
void AccionesSemanticas::devolverConstante(Yylex* lexico, char& c){
    lexico->aumentarCaracter();
    // digito comun -32767 a 32768
    //if(lexico->cadena) Preguntar rango
    lexico->tokenEncontrado();
    lexico->guardarToken(DIGITO, lexico->cadena,"");

}
void AccionesSemanticas::devolverEnteroLargo(Yylex* lexico, char& c){
    //.5    6.3f-3
    //Valor maximo de un entero largo 2147483647
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->cadena = lexico->cadena.substr (0,lexico->cadena.size()-2);
    long numero = stol(lexico->cadena);
    if(numero <= 2147483648 ){ // preguntar
        lexico->guardarToken(5, lexico->cadena,""); //cambiar el 5
    }else{
        lexico->cadena = to_string(2147483648); //siempre que sea positivo el numero, el sintactico lo chekea
        lexico->guardarToken(5, lexico->cadena,"Se reemplazo el entero largo por el valor extremo "); //cambiar el 5
    }

}

void AccionesSemanticas::devolverFloat(Yylex* lexico, char& c){
    //.5    6.3f+12 63000
    // 6.666f+2
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    string acumulado="";
    float numero=0;
    int desplazamiento = 0;
    int i = 0;
    while (i < lexico->cadena.size()){
        if(lexico->cadena[i]=='f'){ //si hay desplazamiento
            if(lexico->cadena[i+1]=='+'){
                desplazamiento= stoi(lexico->cadena.substr(i+2,lexico->cadena.size()));
                cout<<desplazamiento<<endl;
                numero=stof(acumulado);
                for(int i=0; i< desplazamiento; i++){
                    numero= numero * 10;
                }
                i = lexico->cadena.size();
            }else{
                desplazamiento=stoi(lexico->cadena.substr(i+2,lexico->cadena.size()));
                cout<<desplazamiento<<endl;
                numero=stof(acumulado);
                for(int i=0; i< desplazamiento; i++){
                    numero= numero / 10;
                }
                i = lexico->cadena.size();
            }
        }else {
            acumulado = acumulado + lexico->cadena[i];
            i++;
        }
    }
    lexico->guardarToken(20, to_string(numero),""); //CAMBIAR A ID DE FLOAT DESP
}

void AccionesSemanticas::devolverOperador(Yylex* lexico, char& c){
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->guardarToken(22, lexico->cadena,"");
}

void AccionesSemanticas::devolverSeparador(Yylex* lexico, char& c){
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->guardarToken(23, lexico->cadena,"");
}

void AccionesSemanticas::devolverAsignacion(Yylex* lexico, char& c){
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->guardarToken(24, lexico->cadena,"");
}

void AccionesSemanticas::devolverIgual(Yylex* lexico, char& c){
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->guardarToken(25, lexico->cadena,"");
}

void AccionesSemanticas::devolverMayor(Yylex* lexico, char& c){
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->guardarToken(26, lexico->cadena,"");
}

void AccionesSemanticas::devolverMayorIgual(Yylex* lexico, char& c){
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->guardarToken(27, lexico->cadena,"");
}

void AccionesSemanticas::devolverMenor(Yylex* lexico, char& c){
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->guardarToken(28, lexico->cadena,"");
}
void AccionesSemanticas::devolverMenorIgual(Yylex* lexico, char& c){
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->guardarToken(29, lexico->cadena,"");
}
void AccionesSemanticas::finCadena(Yylex* lexico, char& c){
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    //FALTA CHEQUEAR SI SE ENCUENTRA UN $

    lexico->guardarToken(30, lexico->cadena,"");
}
void AccionesSemanticas::devolverDistinto(Yylex *lexico, char &c) {
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->guardarToken(31, lexico->cadena,"");
}
void AccionesSemanticas::devolverSuma(Yylex *lexico, char &c) {
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->guardarToken(32, lexico->cadena,"");
}
void AccionesSemanticas::devolverResta(Yylex *lexico, char &c) {
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->guardarToken(33, lexico->cadena,"");
}
void AccionesSemanticas::devolverDivision(Yylex *lexico, char &c) {
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->guardarToken(34, lexico->cadena,"");
}
void AccionesSemanticas::descartarComentario(Yylex *lexico, char &c) {
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->cadena="";
}
void AccionesSemanticas::notificarFinArchivo(Yylex* lexico, char& c){
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    //voy del estado 0 a F con $
    if(lexico->cadena.size() > 1){
        lexico->cadena=lexico->cadena.substr(lexico->cadena.size()-1,lexico->cadena.size()); //me quedo solo con el $, descarto la basura (comentario)
        lexico->guardarToken(35,lexico->cadena,"Se encontró fin de archivo dentro de un comentario que no se cerró");
        //PREGUNTAR SI ES ERROR
    }else{
        lexico->guardarToken(35,lexico->cadena,"");
    }
}
static void descartarComentario(Yylex* lexico, char& c){
    lexico->aumentarCaracter();
    lexico->cadena="";
}
void AccionesSemanticas::mensajeWarning(Yylex* lexico, char& c){
}
void AccionesSemanticas::mensajeError(Yylex* lexico, char& c){
    lexico->aumentarCaracter();
    // EN UN FUTURO GUARDAR EN UN ARCHIVO TODOS LOS ERRORES
    cout<< lexico->getLinea()<<endl;
    cout<<to_string(c)+" no fue reconocido"<<endl;
}
