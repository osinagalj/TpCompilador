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
        lexico->guardarToken(MINUSCULA, lexico->cadena);
        //"Identificador supera la longitud maxima de 20 caracteres"
    }else{
        lexico->guardarToken(MINUSCULA, lexico->cadena);
    }
}
void AccionesSemanticas::devolverReservada(Yylex* lexico, char& c){
    lexico->tokenEncontrado();
    lexico->guardarToken(MAYUSCULA, lexico->cadena);
}
void AccionesSemanticas::devolverConstante(Yylex* lexico, char& c){
    lexico->tokenEncontrado();
    lexico->guardarToken(DIGITO, lexico->cadena);

}
void AccionesSemanticas::devolverEnteroLargo(Yylex* lexico, char& c){
    //.5    6.3f-3
    //Valor maximo de un entero largo 2147483647
    //lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->cadena = lexico->cadena.substr (0,lexico->cadena.size()-2);
    long numero = stol(lexico->cadena);
    if(numero <= 2147483648 ){ // preguntar
        lexico->guardarToken(5, lexico->cadena); //cambiar el 5
    }else{
        lexico->cadena = to_string(2147483648); //siempre que sea positivo el numero, el sintactico lo chekea
        lexico->guardarToken(5, lexico->cadena); //cambiar el 5
        //Se reemplazo el entero largo por el valor extremo
    }

}

void AccionesSemanticas::devolverFloat(Yylex* lexico, char& c){
    string acumulado="";
    float numero=0;
    int desplazamiento = 0;
    int i = 0;
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
    lexico->guardarToken(20, to_string(numero)); //CAMBIAR A ID DE FLOAT DESP
    lexico->tokenEncontrado();
}


void AccionesSemanticas::finCadena(Yylex* lexico, char& c){
    //HAY QUE AGREGAR EL " AL STRING PARA CUANDDO LO GUARDEMOS EN LA TABLA DE SIMBOLOS, SI NO LO GUARDAMOS HA YQUE ELIMINAR LAS COMILLAS QUE ABREN LA CADENA CAMBIANDO LA AS de la matriz.
    lexico->tokenEncontrado();
    lexico->guardarToken(30, lexico->cadena);
}

//Blancos,TAB, Salto de linea
void AccionesSemanticas::descartarCaracter(Yylex *lexico, char &c) {
    lexico->aumentarCaracter();
    lexico->cadena="";
}

//$ en medio de un comentario o cadena de caracter
void AccionesSemanticas::notificarFinArchivoInesperado(Yylex* lexico, char& c){
    lexico->registro.warning = "Se encontró fin de archivo adentro de un comentario o cadena de caracteres"; //Puede ser en un comentario o una cadena de caracter
}

void AccionesSemanticas::mensajeError(Yylex* lexico, char& c){
    lexico->aumentarCaracter();
    // EN UN FUTURO GUARDAR EN UN ARCHIVO TODOS LOS ERRORES
    cout<< lexico->getLinea()<<endl;
    cout<<to_string(c)+" no fue reconocido"<<endl;
}

// Comparadores: <=,>=,==,!=
void AccionesSemanticas::devolverComparadorCompuesto(Yylex* lexico, char& c){
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->cadena = lexico->cadena + c;
    switch(lexico->cadena[0]){  //El primer caracter es siempre un = en un comparador compuesto
        case '<':
            lexico->guardarToken(21, lexico->cadena); //MAYORIGUAL
            break;
        case '>':
            lexico->guardarToken(22, lexico->cadena); //MENORIGUAL
            break;
        case '=':
            lexico->guardarToken(23, lexico->cadena); //IGUAL
            break;
        case '!':
            lexico->guardarToken(24, lexico->cadena); //DISTINTO
            break;
        }
}

void AccionesSemanticas::devolverComparadorSimple(Yylex* lexico, char& c){
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

void AccionesSemanticas::devolverUnico(Yylex* lexico, char& c){
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
        case '{': //Multiplicacion
            lexico->guardarToken(toascii('{'), lexico->cadena);
            break;
        case '.': //Multiplicacion
            lexico->guardarToken(toascii('.'), lexico->cadena);
            break;
        case '$': //Multiplicacion
            lexico->guardarToken(toascii('$'), lexico->cadena);
            lexico->end = true;
            break;


    }
}









/*******************************************************************************************************************/

/*
void AccionesSemanticas::devolverAsignacion(Yylex* lexico, char& c){
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->guardarToken(24, lexico->cadena);
}
void AccionesSemanticas::devolverDistinto(Yylex *lexico, char &c) {
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->guardarToken(31, lexico->cadena);
}
void AccionesSemanticas::devolverIgual(Yylex* lexico, char& c){
    //lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->guardarToken(25, lexico->cadena);
}
*/
/*
void AccionesSemanticas::devolverMayor(Yylex* lexico, char& c){
    //lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->guardarToken(26, lexico->cadena);
}
*/
/*
void AccionesSemanticas::devolverMayorIgual(Yylex* lexico, char& c){
    //lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->guardarToken(27, lexico->cadena);
}
*/
/*
void AccionesSemanticas::devolverMenor(Yylex* lexico, char& c){
    //lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->guardarToken(28, lexico->cadena);
}
 */
/*
void AccionesSemanticas::devolverMenorIgual(Yylex* lexico, char& c){
    lexico->aumentarCaracter();
    lexico->cadena = lexico->cadena + c;

    lexico->guardarToken(29, lexico->cadena);
    lexico->tokenEncontrado();
}

*/







/*
void AccionesSemanticas::devolverSuma(Yylex *lexico, char & c) {
    lexico->cadena = lexico->cadena + c;
    lexico->aumentarCaracter();

    lexico->tokenEncontrado();

    lexico->guardarToken(32, lexico->cadena);
}
void AccionesSemanticas::devolverResta(Yylex *lexico, char &c) {
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->guardarToken(33, lexico->cadena);
}
void AccionesSemanticas::devolverDivision(Yylex *lexico, char &c) {
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->guardarToken(34, to_string(c));
}

//MULTIPLICACION
void AccionesSemanticas::devolverOperador(Yylex* lexico, char& c){
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->guardarToken(22, lexico->cadena);
}
*/
/*
void AccionesSemanticas::devolverLiteral(Yylex* lexico, char& c){
    // "(",")","]",";",".",
    lexico->aumentarCaracter();
    lexico->tokenEncontrado();
    lexico->cadena = lexico->cadena + c;
    cout<<"entro en literales xd"<<endl;
    lexico->guardarToken(23, lexico->cadena);
}*/


/*
void AccionesSemanticas::entregarFinArchivo(Yylex *lexico, char &c){ //podriamos meterlo en devolverUNIQUE
    lexico->cadena = lexico->cadena + c; //devolvemos el $
    lexico->tokenEncontrado();
    lexico->aumentarCaracter();
    lexico->guardarToken(90, lexico->cadena);
    lexico->end = true;
}
 */