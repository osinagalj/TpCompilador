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
    lexico->tokenEncontrado();
    lexico->guardarToken(MAYUSCULA, lexico->cadena,"");
}
void AccionesSemanticas::devolverConstante(Yylex* lexico, char& c){
    // digito comun -32767 a 32768
    //if(lexico->cadena) Preguntar rango
    lexico->guardarToken(DIGITO, lexico->cadena,"");

}
void AccionesSemanticas::devolverEnteroLargo(Yylex* lexico, char& c){
    //.5    6.3f-3
    //Valor maximo de un entero largo 2147483647
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

    lexico->guardarToken(21, to_string(numero),""); //CAMBIAR A ID DE FLOAT DESP
}





void AccionesSemanticas::devolverOperador(Yylex* lexico, char& c){
}

void AccionesSemanticas::devolverSeparador(Yylex* lexico, char& c){
}

void AccionesSemanticas::devolverAsignacion(Yylex* lexico, char& c){
}

void AccionesSemanticas::devolverIgual(Yylex* lexico, char& c){
}

void AccionesSemanticas::devolverMayor(Yylex* lexico, char& c){
}

void AccionesSemanticas::devolverMayorIgual(Yylex* lexico, char& c){
}

void AccionesSemanticas::devolverMenor(Yylex* lexico, char& c){
}
void AccionesSemanticas::devolverMenorIgual(Yylex* lexico, char& c){
}
void AccionesSemanticas::finCadena(Yylex* lexico, char& c){
}
void AccionesSemanticas::notificarFinArchivo(Yylex* lexico, char& c){
}
void AccionesSemanticas::mensajeWarning(Yylex* lexico, char& c){

}
void AccionesSemanticas::mensajeError(Yylex* lexico, char& c){
}
