#include <iostream>
#include "yylex.h"

using namespace std;

int identificarCaracter(char carac);


Yylex::Yylex(string pathArchivo) {
    cargarArchivo(pathArchivo);
    inicializarMatrizAS();
    //palabrasReservadas.insert()
    //El sintactico los tiene que definir solos
    palabrasReservadas.insert(pair<string,int>("IF",1));
    palabrasReservadas.insert(pair<string,int>("ELSE",2));
    palabrasReservadas.insert(pair<string,int>("END_IF",3));
    palabrasReservadas.insert(pair<string,int>("THEN",4));
    palabrasReservadas.insert(pair<string,int>("OUT",5));
    palabrasReservadas.insert(pair<string,int>("FUNC",6));
    palabrasReservadas.insert(pair<string,int>("RETURN",7));
    palabrasReservadas.insert(pair<string,int>("WHILE",8));
    palabrasReservadas.insert(pair<string,int>("LOOP",9));
    palabrasReservadas.insert(pair<string,int>("FLOAT",10));


}


void Yylex::cargarArchivo(string pathArchivo)
{
    archivoOrigen.open(pathArchivo,ifstream::in);
    if(archivoOrigen.fail()){
        cout << "Error al abrir el archivo de código fuente" << endl;
        exit(1);
    }
}

Yylex::Token Yylex::getToken(){
        while (!archivoOrigen.eof()) {
            linea_actual++;
            getline(archivoOrigen,linea);
            cout<< linea<<endl;
            while(caracteresAvanzados < linea.size()){
                token=token+linea[caracteresAvanzados];
                caracteresAvanzados++;
                estadoNuevo =identificarCaracter(linea[caracteresAvanzados]);
                //tipo = esToken(token,estadoNuevo);
               // if (tipo != ""){ //si es token
                    //devolverToken(token,tipo);//esto sería un return token nada más si lo hacemos una función
                    //acá cambiaríamos el estado de "buscar token" a "no buscar", hasta que el parser nos lo vuelva a cambiar y arranquetodo de nuevo
            }
        }
        //entregarToken(token,tipo); //dar token al parser
        return t;
}


int Yylex::identificarCaracter(char carac){
//esta funcion te devuelve el numero de columna de la matriz de transicion de estado

    if (carac<='z' && carac>='a') // es minus
        return MINUSCULA;
    if (carac<='Z' && carac>='A') //es mayus
        return MAYUSCULA;
    if (carac>='0' && carac<='9')// es dig
        return DIGITO;

    switch(carac)
    {
        case 'l':
            return L_MINUSCULA;
        case 'f':
            return F_MINUSCULA;
        case '.':
            return SIMBOLO_PUNTO;
        case '+':
            return SIGNO_OPERADOR;
        case '*': //Multiplicacion
            return SIGNO_OPERADOR;
        case '-': //Signo menos
            return SIGNO_RESTA;
        case '_': //Guion bajo
            return GUION_BAJO;
        case '=':
            return COMPARADOR_IGUAL;
        case '<': //Bloque de menor;
            return COMPARADOR_MENOR;
        case '>':
            return COMPARADOR_MAYOR;
        case '!':
            return SIMBOLO_DISTINTO;
        case '"':
            return COMILLA;
        case '/':
            return SIGNO_DIVISION;
        case '%':
            return SIMBOLO_PORCENTAJE;
        case '(':
            return LITERALES;
        case ')':
            return LITERALES;
        case ',':
            return LITERALES;
        case ';':
            return LITERALES;
        case '{':
            return LITERALES;
        case '}':
            return LITERALES;
        case '$':
            return SIMBOLO_FIN_DE_ARCHIVO;
        case ' ': //Espacio en blanco;
            return BL_TAB_NL;
        case '\n': //Salto de línea;
            return BL_TAB_NL;
        //default, es el bloque que se ejecuta en caso de que no se de ningún caso
        default:
            return OTRO; //devuelvo numero de columna 'otro'
    }
}

void Yylex::inicializarMatrizAS() {
    matrizAS[0][1] = {1, &AccionesSemanticas::agregarCaracter};
    matrizAS[0][1] = {1, &AccionesSemanticas::agregarCaracter};
    matrizAS[0][1] = {1, &AccionesSemanticas::agregarCaracter};
}