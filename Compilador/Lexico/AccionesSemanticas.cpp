#include "AccionesSemanticas.h"
#include "Lexico.h"

void AccionesSemanticas::inicializarToken(Lexico* lexico, char& c){
    lexico->cadena = c;
    lexico->aumentarCaracter();
}
void AccionesSemanticas::agregarCaracter(Lexico* lexico, char& c){
    lexico->cadena = lexico->cadena + c;
    lexico->aumentarCaracter();
}
void AccionesSemanticas::devolverIdentificador(Lexico* lexico, char& c){
    lexico->tokenEncontrado();
    //Chekear el rango
    if(lexico->cadena.length() > longIdentificador){
        lexico->cadena =  lexico->cadena.substr (0,20);
        lexico->guardarToken(ID, lexico->cadena);
        lexico->guardarEnTS(ID);
        //"Identificador supera la longitud maxima de 20 caracteres"
    }else{
        lexico->guardarToken(ID, lexico->cadena);
        lexico->guardarEnTS(ID);
    }
}
void AccionesSemanticas::devolverReservada(Lexico* lexico, char& c){
    lexico->tokenEncontrado();
    int id = lexico->getIdPalabraReservada();
    lexico->guardarToken(id, lexico->cadena);

}
void AccionesSemanticas::devolverConstante(Lexico* lexico, char& c){
    lexico->tokenEncontrado();
    lexico->guardarToken(CTE, lexico->cadena);
    lexico->guardarEnTS(CTE);

}
void AccionesSemanticas::devolverEnteroLargo(Lexico* lexico, char& c){
    //.5    6.3f-3
    //Valor maximo de un entero largo 2147483647
    lexico->tokenEncontrado();
    lexico->cadena = lexico->cadena.substr (0,lexico->cadena.size()-2);
    long numero = stol(lexico->cadena);
    if(numero <= 2147483648 ){ // preguntar
        lexico->guardarToken(LONGINT, lexico->cadena); //cambiar el 5

    }else{
        lexico->cadena = to_string(2147483648); //siempre que sea positivo el numero, el sintactico lo chekea
        lexico->guardarToken(LONGINT, lexico->cadena); //cambiar el 5

    }
    lexico->guardarEnTS(LONGINT);
}
void AccionesSemanticas::devolverFloat(Lexico* lexico, char& c){
    string acumulado="";
    float numero=0;
    int desplazamiento = 0;
    int i = 0;
    if(lexico->cadena[0] == '.'){
        string aux= "0" + lexico->cadena;
        acumulado=aux;
    }
    while (i < lexico->cadena.size()){
        if(lexico->cadena[i]=='f'){ //si hay desplazamiento
            if(lexico->cadena[i+1]=='+'){
                desplazamiento= stoi(lexico->cadena.substr(i+2,lexico->cadena.size()));
                //cout<<desplazamiento<<endl;
                numero=stof(acumulado);
                for(int i=0; i< desplazamiento; i++){
                    numero= numero * 10;
                }
                i = lexico->cadena.size();
            }else{
                desplazamiento=stoi(lexico->cadena.substr(i+2,lexico->cadena.size()));
                //cout<<desplazamiento<<endl;
                numero=stof(acumulado);
                for(int i=0; i< desplazamiento; i++){
                    numero= numero / 10;
                }
                i = lexico->cadena.size();
            }
        }else {
            acumulado = acumulado + lexico->cadena[i];
            numero = stof(acumulado);
            i++;
        }
    }
    lexico->guardarToken(FLOAT, to_string(numero)); //CAMBIAR A ID DE FLOAT DESP
    lexico->guardarEnTS(FLOAT);
    lexico->tokenEncontrado();
}
/*
void AccionesSemanticas::finCadena(Lexico* lexico, char& c){
    //HAY QUE AGREGAR EL " AL STRING PARA CUANDDO LO GUARDEMOS EN LA TABLA DE SIMBOLOS, SI NO LO GUARDAMOS HA YQUE ELIMINAR LAS COMILLAS QUE ABREN LA CADENA CAMBIANDO LA AS de la matriz.
    lexico->tokenEncontrado();
    lexico->guardarToken(30, lexico->cadena);
}
*/
//Blancos,TAB, Salto de linea
void AccionesSemanticas::descartarCaracter(Lexico *lexico, char &c) {
    lexico->aumentarCaracter();
    lexico->cadena="";
}

//$ en medio de un comentario o cadena de caracter
void AccionesSemanticas::notificarFinArchivoInesperado(Lexico* lexico, char& c){
    lexico->registro.warning = "Se encontró fin de archivo adentro de un comentario o cadena de caracteres"; //Puede ser en un comentario o una cadena de caracter
}

void AccionesSemanticas::mensajeError(Lexico* lexico, char& c){
    lexico->aumentarCaracter();
    // EN UN FUTURO GUARDAR EN UN ARCHIVO TODOS LOS ERRORES
    cout<< lexico->getLinea()<<endl;
    cout<<to_string(c)+" no fue reconocido"<<endl;
}

// Comparadores: <=,>=,==,!=
void AccionesSemanticas::devolverComparadorCompuesto(Lexico* lexico, char& c){
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->cadena = lexico->cadena + c;
    switch(lexico->cadena[0]){  //El primer caracter es siempre un = en un comparador compuesto
        case '<':
            lexico->guardarToken(MAYORIGUAL, lexico->cadena); //MAYORIGUAL
            break;
        case '>':
            lexico->guardarToken(MENORIGUAL, lexico->cadena); //MENORIGUAL
            break;
        case '=':
            lexico->guardarToken(IGUAL, lexico->cadena); //IGUAL
            break;
        case '!':
            lexico->guardarToken(DISTINTO, lexico->cadena); //DISTINTO
            break;
        }
}

void AccionesSemanticas::devolverComparadorSimple(Lexico* lexico, char& c){
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->cadena = lexico->cadena + c;
    switch(c){
        case '<':
            lexico->guardarToken(toascii('<'), "");
            break;
        case '>':
            lexico->guardarToken(toascii('>'), "");
            break;
        case '=':
            lexico->guardarToken(toascii('='), "");
            break;
        }
}


void AccionesSemanticas::devolverUnico(Lexico* lexico, char& c){
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->cadena = lexico->cadena + c;

    switch(c)
    {
        case '/':
            lexico->guardarToken(toascii('/'), to_string(c));
            break;
        case '-':
            lexico->guardarToken(toascii('-'), lexico->cadena);
            break;
        case '+': //Multiplicacion
            lexico->guardarToken(toascii('+'), lexico->cadena);
            break;
        case '*': //Multiplicacion
            lexico->guardarToken(toascii('*'), lexico->cadena);
            break;
        case '(': //Multiplicacion
            lexico->guardarToken(toascii('('), lexico->cadena);
            break;
        case ')': //Multiplicacion
            lexico->guardarToken(toascii(')'), lexico->cadena);
            break;
        case ',': //Multiplicacion
            lexico->guardarToken(toascii(','), lexico->cadena);
            break;
        case '}': //Multiplicacion
            lexico->guardarToken(toascii('}'), lexico->cadena);
            break;
        case ';': //Multiplicacion
            lexico->guardarToken(toascii(';'), lexico->cadena);
            break;
        case '{': //Multiplicacion
            lexico->guardarToken(toascii('{'), lexico->cadena);
            break;
        case '.': //Multiplicacion
            lexico->guardarToken(toascii('.'), lexico->cadena);
            break;
        case '"': //Multiplicacion
            //cout<<"entro en comilla " ass  \" "<<endl;
            lexico->guardarToken(CADENA, lexico->cadena);
            lexico->guardarEnTS(CADENA);
            break;
        case '$': //Multiplicacion
            lexico->guardarToken(0, lexico->cadena); //capaz es 0 el ID
            lexico->end = true;
            break;


    }
}


