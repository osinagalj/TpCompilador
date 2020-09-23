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
    estadoActual=0;
}


void Yylex::cargarArchivo(string pathArchivo)
{
    archivoOrigen.open(pathArchivo,ifstream::in);
    if(archivoOrigen.fail()){
        cout << "Error al abrir el archivo de código fuente" << endl;
        exit(1);
    }else
        if(linea_actual>0){
            int aux=0;
            while(aux<linea_actual-1){
                getline(archivoOrigen,linea);
            }
        }
}
void Yylex::tokenEncontrado(){
    this->encontroToken=true;
}

void Yylex::guardarToken(int id, string lexema,string warning){
    this->t.id=id;
    this->t.lexema=lexema;
    this->t.warning=warning;
}

void Yylex::aumentarCaracter() {
    this->caracteresAvanzados++;
}
int Yylex::getLinea() {
    return this->linea_actual;
}
Yylex::Token Yylex::getToken(){
        estadoActual=0;
        while (!archivoOrigen.eof()) {
            getline(archivoOrigen,linea);
            while(caracteresAvanzados < linea.size() && !encontroToken){
                char aux=linea[caracteresAvanzados];
                estadoNuevo=identificarCaracter(aux);
                if(matrizAS[estadoActual][estadoNuevo].Accion != nullptr){  // si hay acción semántica (CHEQUEAR SI HAY LUGARES SIN ACCIONES EN LA MATRIZ)
                    cout << "entro2"<<endl;
                    matrizAS[estadoActual][estadoNuevo].Accion(this,aux);
                }
                estadoActual=matrizAS[estadoActual][estadoNuevo].estado; //actualizo el nuevo estado
            }
            if ((caracteresAvanzados < linea.size()) && encontroToken ){
                //no aumentamos linea
                cout << "encontre token"<<endl;
                archivoOrigen.close(); //cerramos archivo
                return t;
            }
            else {
                linea_actual++;
                caracteresAvanzados=0;
            }
        }
        return t;
}


int Yylex::identificarCaracter(char carac){
//esta funcion te devuelve el numero de columna de la matriz de transicion de estado

    if(carac=='l')
        return L_MINUSCULA;
    if(carac=='f')
        return F_MINUSCULA;
    if (carac<='z' && carac>='a') // es minus
        return MINUSCULA;
    if (carac<='Z' && carac>='A') //es mayus
        return MAYUSCULA;
    if (carac>='0' && carac<='9')// es dig
        return DIGITO;

    switch(carac)
    {
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

void Yylex::inicializarMatrizAS(){
#define MINUSCULA 0
#define MAYUSCULA 1
#define L_MINUSCULA 2
#define F_MINUSCULA 3
#define DIGITO 4
#define SIMBOLO_PUNTO 5
#define SIGNO_OPERADOR 6
#define SIGNO_RESTA 7
#define GUION_BAJO 8
#define COMPARADOR_IGUAL 9
#define COMPARADOR_MENOR 10
#define COMPARADOR_MAYOR 11
#define SIMBOLO_DISTINTO 12
#define COMILLA 13
#define SIGNO_DIVISION 14
#define SIMBOLO_PORCENTAJE 15
#define LITERALES 16
#define BL_TAB_NL 17
#define SIMBOLO_FIN_DE_ARCHIVO 18
#define OTRO 19
#define  SIGNO_SUMA 20
//CAMINO 1
    //INICIALIZAR
    matrizAS[0][MINUSCULA] = {1, &AccionesSemanticas::inicializarToken};
    matrizAS[0][F_MINUSCULA]= {1, &AccionesSemanticas::inicializarToken};
    matrizAS[0][L_MINUSCULA]= {1, &AccionesSemanticas::inicializarToken};
    //AGREGAR
    matrizAS[1][MINUSCULA] = {1, &AccionesSemanticas::agregarCaracter};
    matrizAS[1][GUION_BAJO]= {1, &AccionesSemanticas::agregarCaracter};
    matrizAS[1][F_MINUSCULA]= {1, &AccionesSemanticas::agregarCaracter};
    matrizAS[1][L_MINUSCULA]= {1, &AccionesSemanticas::agregarCaracter};
    matrizAS[1][DIGITO]= {1, &AccionesSemanticas::agregarCaracter};
    //ENTREGAR ID
    matrizAS[1][OTRO]= {-1, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][MAYUSCULA]= {-1, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][SIMBOLO_PUNTO]= {-1, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][SIMBOLO_PORCENTAJE]= {-1, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][SIGNO_RESTA]= {-1, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][SIMBOLO_DISTINTO]= {-1, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][SIGNO_DIVISION]= {-1, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][SIGNO_OPERADOR]= {-1, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][COMPARADOR_MAYOR]= {-1, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][COMPARADOR_IGUAL]= {-1, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][COMPARADOR_MENOR]= {-1, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][COMILLA]= {-1, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][LITERALES]= {-1, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][BL_TAB_NL]= {-1, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][SIMBOLO_FIN_DE_ARCHIVO]= {-1, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][SIGNO_SUMA]= {-1, &AccionesSemanticas::devolverIdentificador};
//CAMINO 2
    //INICIALIZAR
    matrizAS[0][MAYUSCULA] = {2, &AccionesSemanticas::inicializarToken};
    //AGREGAR
    matrizAS[2][MAYUSCULA] = {2, &AccionesSemanticas::agregarCaracter};
    matrizAS[2][GUION_BAJO]= {2, &AccionesSemanticas::agregarCaracter};
    //ENTREGAR PAL RESERVADA
    matrizAS[2][SIMBOLO_DISTINTO]= {-1, &AccionesSemanticas::devolverReservada};
    matrizAS[2][DIGITO]= {-1, &AccionesSemanticas::devolverReservada};
    matrizAS[2][F_MINUSCULA]= {-1, &AccionesSemanticas::devolverReservada};
    matrizAS[2][L_MINUSCULA]= {-1, &AccionesSemanticas::devolverReservada};
    matrizAS[2][OTRO]= {-1, &AccionesSemanticas::devolverReservada};
    matrizAS[2][MINUSCULA]= {-1, &AccionesSemanticas::devolverReservada};
    matrizAS[2][SIMBOLO_PUNTO]= {-1, &AccionesSemanticas::devolverReservada};
    matrizAS[2][SIMBOLO_PORCENTAJE]= {-1, &AccionesSemanticas::devolverReservada};
    matrizAS[2][SIGNO_RESTA]= {-1, &AccionesSemanticas::devolverReservada};
    matrizAS[2][SIGNO_DIVISION]= {-1, &AccionesSemanticas::devolverReservada};
    matrizAS[2][SIGNO_OPERADOR]= {-1, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COMPARADOR_MAYOR]= {-1, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COMPARADOR_IGUAL]= {-1, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COMPARADOR_MENOR]= {-1, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COMILLA]= {-1, &AccionesSemanticas::devolverReservada};
    matrizAS[2][LITERALES]= {-1, &AccionesSemanticas::devolverReservada};
    matrizAS[2][BL_TAB_NL]= {-1, &AccionesSemanticas::devolverReservada};
    matrizAS[2][SIMBOLO_FIN_DE_ARCHIVO]= {-1, &AccionesSemanticas::devolverReservada};
    matrizAS[2][SIGNO_SUMA]= {-1, &AccionesSemanticas::devolverReservada};
//CAMINO 3
    //INICIALIZAR
    matrizAS[0][DIGITO] = {3, &AccionesSemanticas::inicializarToken};
    //AGREGAR
    matrizAS[3][DIGITO] = {3, &AccionesSemanticas::agregarCaracter};
    matrizAS[3][GUION_BAJO]= {4, &AccionesSemanticas::agregarCaracter};
    matrizAS[3][SIMBOLO_PUNTO]={5, &AccionesSemanticas::agregarCaracter};
    //ENTREGAR CONSTANTE SIMPLE
    matrizAS[3][SIMBOLO_DISTINTO]= {-1, &AccionesSemanticas::devolverConstante};
    matrizAS[3][MAYUSCULA]= {-1, &AccionesSemanticas::devolverConstante};
    matrizAS[3][MINUSCULA]= {-1, &AccionesSemanticas::devolverConstante};
    matrizAS[3][F_MINUSCULA]= {-1, &AccionesSemanticas::devolverConstante};
    matrizAS[3][L_MINUSCULA]= {-1, &AccionesSemanticas::devolverConstante};
    matrizAS[3][OTRO]= {-1, &AccionesSemanticas::devolverConstante};
    matrizAS[3][SIMBOLO_PORCENTAJE]= {-1, &AccionesSemanticas::devolverConstante};
    matrizAS[3][SIGNO_RESTA]= {-1, &AccionesSemanticas::devolverConstante};
    matrizAS[3][SIGNO_DIVISION]= {-1, &AccionesSemanticas::devolverConstante};
    matrizAS[3][SIGNO_OPERADOR]= {-1, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COMPARADOR_MAYOR]= {-1, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COMPARADOR_IGUAL]= {-1, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COMPARADOR_MENOR]= {-1, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COMILLA]= {-1, &AccionesSemanticas::devolverConstante};
    matrizAS[3][LITERALES]= {-1, &AccionesSemanticas::devolverConstante};
    matrizAS[3][BL_TAB_NL]= {-1, &AccionesSemanticas::devolverConstante};
    matrizAS[3][SIMBOLO_FIN_DE_ARCHIVO]= {-1, &AccionesSemanticas::devolverConstante};
    matrizAS[3][SIGNO_SUMA]= {-1, &AccionesSemanticas::devolverConstante};
//CAMINO 4
    //ENTREGAR ENTERO LARGO
    matrizAS[4][L_MINUSCULA] = {-1, &AccionesSemanticas::devolverEnteroLargo};
    //INFORMAR ERROR
    matrizAS[4][SIMBOLO_DISTINTO]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[4][DIGITO]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[4][GUION_BAJO]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[4][SIMBOLO_PUNTO]={-1, &AccionesSemanticas::mensajeError};
    matrizAS[4][MAYUSCULA]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[4][MINUSCULA]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[4][F_MINUSCULA]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[4][OTRO]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[4][SIMBOLO_PORCENTAJE]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[4][SIGNO_RESTA]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[4][SIGNO_DIVISION]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[4][SIGNO_OPERADOR]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[4][COMPARADOR_MAYOR]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[4][COMPARADOR_IGUAL]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[4][COMPARADOR_MENOR]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[4][COMILLA]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[4][LITERALES]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[4][BL_TAB_NL]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[4][SIMBOLO_FIN_DE_ARCHIVO]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[4][SIGNO_SUMA]= {-1, &AccionesSemanticas::mensajeError};
//CAMINO 5
    //AGREGAR
    matrizAS[5][DIGITO]= {5, &AccionesSemanticas::agregarCaracter};
    matrizAS[5][F_MINUSCULA] = {6, &AccionesSemanticas::agregarCaracter};
    //INFORMAR ERROR
    matrizAS[5][L_MINUSCULA] = {-1, &AccionesSemanticas::devolverEnteroLargo};
    matrizAS[5][SIMBOLO_DISTINTO]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[5][GUION_BAJO]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[5][SIMBOLO_PUNTO]={-1, &AccionesSemanticas::mensajeError};
    matrizAS[5][MAYUSCULA]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[5][MINUSCULA]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[5][OTRO]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[5][SIMBOLO_PORCENTAJE]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[5][SIGNO_RESTA]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[5][SIGNO_DIVISION]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[5][SIGNO_OPERADOR]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[5][COMPARADOR_MAYOR]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[5][COMPARADOR_IGUAL]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[5][COMPARADOR_MENOR]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[5][COMILLA]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[5][LITERALES]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[5][BL_TAB_NL]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[5][SIMBOLO_FIN_DE_ARCHIVO]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[5][SIGNO_SUMA]= {-1, &AccionesSemanticas::mensajeError};
//CAMINO 6
    //AGREGAR
    matrizAS[6][SIGNO_RESTA]= {7, &AccionesSemanticas::agregarCaracter};
    matrizAS[6][SIGNO_SUMA] = {7, &AccionesSemanticas::agregarCaracter};
    //INFORMAR ERROR
    matrizAS[6][DIGITO]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[6][F_MINUSCULA] = {-1, &AccionesSemanticas::mensajeError};
    matrizAS[6][L_MINUSCULA] = {-1, &AccionesSemanticas::mensajeError};
    matrizAS[6][SIMBOLO_DISTINTO]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[6][GUION_BAJO]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[6][SIMBOLO_PUNTO]={-1, &AccionesSemanticas::mensajeError};
    matrizAS[6][MAYUSCULA]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[6][MINUSCULA]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[6][OTRO]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[6][SIMBOLO_PORCENTAJE]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[6][SIGNO_RESTA]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[6][SIGNO_DIVISION]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[6][SIGNO_OPERADOR]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[6][COMPARADOR_MAYOR]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[6][COMPARADOR_IGUAL]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[6][COMPARADOR_MENOR]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[6][COMILLA]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[6][LITERALES]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[6][BL_TAB_NL]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[6][SIMBOLO_FIN_DE_ARCHIVO]= {-1, &AccionesSemanticas::mensajeError};
//CAMINO 7
    //AGREGAR
    matrizAS[7][DIGITO]= {7, &AccionesSemanticas::agregarCaracter};
    //DEVOLVER ENTERO LARGO
    matrizAS[7][SIGNO_SUMA] = {-1, &AccionesSemanticas::devolverEnteroLargo};
    matrizAS[7][SIGNO_RESTA]= {-1, &AccionesSemanticas::devolverEnteroLargo};
    matrizAS[7][F_MINUSCULA] = {-1, &AccionesSemanticas::devolverEnteroLargo};
    matrizAS[7][L_MINUSCULA] = {-1, &AccionesSemanticas::devolverEnteroLargo};
    matrizAS[7][SIMBOLO_DISTINTO]= {-1, &AccionesSemanticas::devolverEnteroLargo};
    matrizAS[7][GUION_BAJO]= {-1, &AccionesSemanticas::devolverEnteroLargo};
    matrizAS[7][SIMBOLO_PUNTO]={-1, &AccionesSemanticas::devolverEnteroLargo};
    matrizAS[7][MAYUSCULA]= {-1, &AccionesSemanticas::devolverEnteroLargo};
    matrizAS[7][MINUSCULA]= {-1, &AccionesSemanticas::devolverEnteroLargo};
    matrizAS[7][OTRO]= {-1, &AccionesSemanticas::devolverEnteroLargo};
    matrizAS[7][SIMBOLO_PORCENTAJE]= {-1, &AccionesSemanticas::devolverEnteroLargo};
    matrizAS[7][SIGNO_RESTA]= {-1, &AccionesSemanticas::devolverEnteroLargo};
    matrizAS[7][SIGNO_DIVISION]= {-1, &AccionesSemanticas::devolverEnteroLargo};
    matrizAS[7][SIGNO_OPERADOR]= {-1, &AccionesSemanticas::devolverEnteroLargo};
    matrizAS[7][COMPARADOR_MAYOR]= {-1, &AccionesSemanticas::devolverEnteroLargo};
    matrizAS[7][COMPARADOR_IGUAL]= {-1, &AccionesSemanticas::devolverEnteroLargo};
    matrizAS[7][COMPARADOR_MENOR]= {-1, &AccionesSemanticas::devolverEnteroLargo};
    matrizAS[7][COMILLA]= {-1, &AccionesSemanticas::devolverEnteroLargo};
    matrizAS[7][LITERALES]= {-1, &AccionesSemanticas::devolverEnteroLargo};
    matrizAS[7][BL_TAB_NL]= {-1, &AccionesSemanticas::devolverEnteroLargo};
    matrizAS[7][SIMBOLO_FIN_DE_ARCHIVO]= {-1, &AccionesSemanticas::devolverEnteroLargo};
//CAMINO 8
    //AGREGAR
    matrizAS[0][COMPARADOR_MENOR]= {8, &AccionesSemanticas::agregarCaracter};
    //DEVOLVER MENOR IGUAL
    matrizAS[8][COMPARADOR_IGUAL]= {-1, &AccionesSemanticas::devolverMenorIgual};
    //DEVOLVER MENOR
    matrizAS[8][DIGITO]= {-1, &AccionesSemanticas::devolverMenor};
    matrizAS[8][SIGNO_SUMA] = {-1, &AccionesSemanticas::devolverMenor};
    matrizAS[8][SIGNO_RESTA]= {-1, &AccionesSemanticas::devolverMenor};
    matrizAS[8][F_MINUSCULA] = {-1, &AccionesSemanticas::devolverMenor};
    matrizAS[8][L_MINUSCULA] = {-1, &AccionesSemanticas::devolverMenor};
    matrizAS[8][SIMBOLO_DISTINTO]= {-1, &AccionesSemanticas::devolverMenor};
    matrizAS[8][GUION_BAJO]= {-1, &AccionesSemanticas::devolverMenor};
    matrizAS[8][SIMBOLO_PUNTO]={-1, &AccionesSemanticas::devolverMenor};
    matrizAS[8][MAYUSCULA]= {-1, &AccionesSemanticas::devolverMenor};
    matrizAS[8][MINUSCULA]= {-1, &AccionesSemanticas::devolverMenor};
    matrizAS[8][OTRO]= {-1, &AccionesSemanticas::devolverMenor};
    matrizAS[8][SIMBOLO_PORCENTAJE]= {-1, &AccionesSemanticas::devolverMenor};
    matrizAS[8][SIGNO_RESTA]= {-1, &AccionesSemanticas::devolverMenor};
    matrizAS[8][SIGNO_DIVISION]= {-1, &AccionesSemanticas::devolverMenor};
    matrizAS[8][SIGNO_OPERADOR]= {-1, &AccionesSemanticas::devolverMenor};
    matrizAS[8][COMPARADOR_MAYOR]= {-1, &AccionesSemanticas::devolverMenor};
    matrizAS[8][COMILLA]= {-1, &AccionesSemanticas::devolverMenor};
    matrizAS[8][LITERALES]= {-1, &AccionesSemanticas::devolverMenor};
    matrizAS[8][BL_TAB_NL]= {-1, &AccionesSemanticas::devolverMenor};
    matrizAS[8][SIMBOLO_FIN_DE_ARCHIVO]= {-1, &AccionesSemanticas::devolverMenor};
//CAMINO 9
    //AGREGAR
    matrizAS[0][COMPARADOR_MAYOR]= {9, &AccionesSemanticas::agregarCaracter};
    //DEVOLVER MAYOR IGUAL
    matrizAS[9][COMPARADOR_IGUAL]= {-1, &AccionesSemanticas::devolverMayorIgual};
    //DEVOLVER MENOR
    matrizAS[9][DIGITO]= {-1, &AccionesSemanticas::devolverMayor};
    matrizAS[9][SIGNO_SUMA] = {-1, &AccionesSemanticas::devolverMayor};
    matrizAS[9][SIGNO_RESTA]= {-1, &AccionesSemanticas::devolverMayor};
    matrizAS[9][F_MINUSCULA] = {-1, &AccionesSemanticas::devolverMayor};
    matrizAS[9][L_MINUSCULA] = {-1, &AccionesSemanticas::devolverMayor};
    matrizAS[9][SIMBOLO_DISTINTO]= {-1, &AccionesSemanticas::devolverMayor};
    matrizAS[9][GUION_BAJO]= {-1, &AccionesSemanticas::devolverMayor};
    matrizAS[9][SIMBOLO_PUNTO]={-1, &AccionesSemanticas::devolverMayor};
    matrizAS[9][MAYUSCULA]= {-1, &AccionesSemanticas::devolverMayor};
    matrizAS[9][MINUSCULA]= {-1, &AccionesSemanticas::devolverMayor};
    matrizAS[9][OTRO]= {-1, &AccionesSemanticas::devolverMayor};
    matrizAS[9][SIMBOLO_PORCENTAJE]= {-1, &AccionesSemanticas::devolverMayor};
    matrizAS[9][SIGNO_RESTA]= {-1, &AccionesSemanticas::devolverMayor};
    matrizAS[9][SIGNO_DIVISION]= {-1, &AccionesSemanticas::devolverMayor};
    matrizAS[9][SIGNO_OPERADOR]= {-1, &AccionesSemanticas::devolverMayor};
    matrizAS[9][COMPARADOR_MENOR]= {-1, &AccionesSemanticas::devolverMayor};
    matrizAS[9][COMILLA]= {-1, &AccionesSemanticas::devolverMayor};
    matrizAS[9][LITERALES]= {-1, &AccionesSemanticas::devolverMayor};
    matrizAS[9][BL_TAB_NL]= {-1, &AccionesSemanticas::devolverMayor};
    matrizAS[9][SIMBOLO_FIN_DE_ARCHIVO]= {-1, &AccionesSemanticas::devolverMayor};
//CAMINO 10
    //AGREGAR
    matrizAS[0][COMPARADOR_IGUAL]= {10, &AccionesSemanticas::agregarCaracter};
    //DEVOLVER IGUAL
    matrizAS[10][COMPARADOR_IGUAL]= {-1, &AccionesSemanticas::devolverIgual};
    //DEVOLVER ASIGNACION
    matrizAS[10][DIGITO]= {-1, &AccionesSemanticas::devolverAsignacion};
    matrizAS[10][SIGNO_SUMA] = {-1, &AccionesSemanticas::devolverAsignacion};
    matrizAS[10][SIGNO_RESTA]= {-1, &AccionesSemanticas::devolverAsignacion};
    matrizAS[10][F_MINUSCULA] = {-1, &AccionesSemanticas::devolverAsignacion};
    matrizAS[10][L_MINUSCULA] = {-1, &AccionesSemanticas::devolverAsignacion};
    matrizAS[10][SIMBOLO_DISTINTO]= {-1, &AccionesSemanticas::devolverAsignacion};
    matrizAS[10][GUION_BAJO]= {-1, &AccionesSemanticas::devolverAsignacion};
    matrizAS[10][SIMBOLO_PUNTO]={-1, &AccionesSemanticas::devolverAsignacion};
    matrizAS[10][MAYUSCULA]= {-1, &AccionesSemanticas::devolverAsignacion};
    matrizAS[10][MINUSCULA]= {-1, &AccionesSemanticas::devolverAsignacion};
    matrizAS[10][OTRO]= {-1, &AccionesSemanticas::devolverAsignacion};
    matrizAS[10][SIMBOLO_PORCENTAJE]= {-1, &AccionesSemanticas::devolverAsignacion};
    matrizAS[10][SIGNO_DIVISION]= {-1, &AccionesSemanticas::devolverAsignacion};
    matrizAS[10][SIGNO_OPERADOR]= {-1, &AccionesSemanticas::devolverAsignacion};
    matrizAS[10][COMPARADOR_MENOR]= {-1, &AccionesSemanticas::devolverAsignacion};
    matrizAS[10][COMPARADOR_MAYOR]= {-1, &AccionesSemanticas::devolverAsignacion};
    matrizAS[10][COMILLA]= {-1, &AccionesSemanticas::devolverAsignacion};
    matrizAS[10][LITERALES]= {-1, &AccionesSemanticas::devolverAsignacion};
    matrizAS[10][BL_TAB_NL]= {-1, &AccionesSemanticas::devolverAsignacion};
    matrizAS[10][SIMBOLO_FIN_DE_ARCHIVO]= {-1, &AccionesSemanticas::devolverAsignacion};
//CAMINO 11
    //AGREGAR
    matrizAS[0][SIMBOLO_DISTINTO]= {11, &AccionesSemanticas::agregarCaracter};
    //DEVOLVER DISTINTO
    matrizAS[11][COMPARADOR_IGUAL]= {-1, &AccionesSemanticas::devolverDistinto};
    //INFORMAR ERROR
    matrizAS[11][DIGITO]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[11][F_MINUSCULA] = {-1, &AccionesSemanticas::mensajeError};
    matrizAS[11][L_MINUSCULA] = {-1, &AccionesSemanticas::mensajeError};
    matrizAS[11][COMPARADOR_IGUAL]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[11][GUION_BAJO]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[11][SIMBOLO_PUNTO]={-1, &AccionesSemanticas::mensajeError};
    matrizAS[11][MAYUSCULA]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[11][MINUSCULA]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[11][OTRO]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[11][SIMBOLO_PORCENTAJE]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[11][SIGNO_RESTA]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[11][SIGNO_DIVISION]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[11][COMPARADOR_MENOR]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[11][COMPARADOR_MAYOR]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[11][COMILLA]= {-1, &AccionesSemanticas::mensajeError};
    matrizAS[11][BL_TAB_NL]= {-1, &AccionesSemanticas::mensajeError};
//CAMINO 12
    //AGREGAR
    matrizAS[0][COMILLA]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][SIMBOLO_DISTINTO]= {11, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COMPARADOR_IGUAL]= {-1, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][SIGNO_SUMA] = {-1, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][SIGNO_RESTA]= {-1, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][SIGNO_OPERADOR]= {-1, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][LITERALES]= {-1, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][SIMBOLO_FIN_DE_ARCHIVO]={-1, &AccionesSemanticas::agregarCaracter};  // ACÁ PASABA ALGO?
    matrizAS[12][DIGITO]= {-1, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][F_MINUSCULA] = {-1, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][L_MINUSCULA] = {-1, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COMPARADOR_IGUAL]= {-1, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][GUION_BAJO]= {-1, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][SIMBOLO_PUNTO]={-1, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][MAYUSCULA]= {-1, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][MINUSCULA]= {-1, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][OTRO]= {-1, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][SIMBOLO_PORCENTAJE]= {-1, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][SIGNO_DIVISION]= {-1, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COMPARADOR_MENOR]= {-1, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COMPARADOR_MAYOR]= {-1, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][BL_TAB_NL]= {-1, &AccionesSemanticas::agregarCaracter};
    //DEVOLVER CADENA
    matrizAS[12][COMILLA]= {-1, &AccionesSemanticas::finCadena};
//CAMINO 13
    //AGREGAR
    matrizAS[0][SIGNO_DIVISION]= {13, &AccionesSemanticas::agregarCaracter};
    //DEVOLVER DIVISION
    matrizAS[13][SIMBOLO_DISTINTO]= {-1, &AccionesSemanticas::devolverDivision};
    matrizAS[13][COMPARADOR_IGUAL]= {-1, &AccionesSemanticas::devolverDivision};
    matrizAS[13][SIGNO_SUMA] = {-1, &AccionesSemanticas::devolverDivision};
    matrizAS[13][SIGNO_RESTA]= {-1, &AccionesSemanticas::devolverDivision};
    matrizAS[13][SIGNO_OPERADOR]= {-1, &AccionesSemanticas::devolverDivision};
    matrizAS[13][LITERALES]= {-1, &AccionesSemanticas::devolverDivision};
    matrizAS[13][SIMBOLO_FIN_DE_ARCHIVO]={-1, &AccionesSemanticas::devolverDivision};
    matrizAS[13][DIGITO]= {-1, &AccionesSemanticas::devolverDivision};
    matrizAS[13][F_MINUSCULA] = {-1, &AccionesSemanticas::devolverDivision};
    matrizAS[13][L_MINUSCULA] = {-1, &AccionesSemanticas::devolverDivision};
    matrizAS[13][GUION_BAJO]= {-1, &AccionesSemanticas::devolverDivision};
    matrizAS[13][SIMBOLO_PUNTO]={-1, &AccionesSemanticas::devolverDivision};
    matrizAS[13][MAYUSCULA]= {-1, &AccionesSemanticas::devolverDivision};
    matrizAS[13][MINUSCULA]= {-1, &AccionesSemanticas::devolverDivision};
    matrizAS[13][OTRO]= {-1, &AccionesSemanticas::devolverDivision};
    matrizAS[13][COMILLA]= {-1, &AccionesSemanticas::devolverDivision};
    matrizAS[13][COMPARADOR_MENOR]= {-1, &AccionesSemanticas::devolverDivision};
    matrizAS[13][COMPARADOR_MAYOR]= {-1, &AccionesSemanticas::devolverDivision};
    matrizAS[13][BL_TAB_NL]= {-1, &AccionesSemanticas::devolverDivision};
    //INICIO DE COMENTARIO
    matrizAS[13][SIMBOLO_PORCENTAJE]= {14, &AccionesSemanticas::agregarCaracter};
//CAMINO 14
    //AGREGAR
    matrizAS[14][SIGNO_DIVISION]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[14][SIMBOLO_DISTINTO]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[14][COMPARADOR_IGUAL]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[14][SIGNO_SUMA] = {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[14][SIGNO_RESTA]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[14][SIGNO_OPERADOR]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[14][LITERALES]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[14][DIGITO]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[14][F_MINUSCULA] = {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[14][L_MINUSCULA] = {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[14][GUION_BAJO]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[14][SIMBOLO_PUNTO]={14, &AccionesSemanticas::agregarCaracter};
    matrizAS[14][MAYUSCULA]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[14][MINUSCULA]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[14][OTRO]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[14][COMILLA]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[14][COMPARADOR_MENOR]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[14][COMPARADOR_MAYOR]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[14][BL_TAB_NL]= {14, &AccionesSemanticas::agregarCaracter};
    //POSIBLE FIN DE COMENTARIO
    matrizAS[14][SIMBOLO_PORCENTAJE]= {15, &AccionesSemanticas::agregarCaracter};
    //FIN DE ARCHIVO EN MEDIO DEL COMENTARIO
    matrizAS[14][SIMBOLO_FIN_DE_ARCHIVO]={0, &AccionesSemanticas::agregarCaracter};
//CAMINO 15
    //AGREGAR (VUELVO A ESTADO 14 PORQUE NO SE CERRO EL COMENTARIO)
    matrizAS[15][SIMBOLO_DISTINTO]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[15][COMPARADOR_IGUAL]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[15][SIGNO_SUMA] = {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[15][SIGNO_RESTA]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[15][SIGNO_OPERADOR]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[15][LITERALES]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[15][DIGITO]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[15][F_MINUSCULA] = {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[15][L_MINUSCULA] = {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[15][GUION_BAJO]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[15][SIMBOLO_PUNTO]={14, &AccionesSemanticas::agregarCaracter};
    matrizAS[15][MAYUSCULA]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[15][MINUSCULA]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[15][OTRO]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[15][COMILLA]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[15][COMPARADOR_MENOR]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[15][COMPARADOR_MAYOR]= {14, &AccionesSemanticas::agregarCaracter};
    matrizAS[15][BL_TAB_NL]= {14, &AccionesSemanticas::agregarCaracter};
    //POSIBLE FIN DE COMENTARIO
    matrizAS[15][SIMBOLO_PORCENTAJE]= {15, &AccionesSemanticas::agregarCaracter};
    //FIN COMENTARIO (descartar)
    matrizAS[15][SIGNO_DIVISION]= {-1, &AccionesSemanticas::descartarComentario};
    //FIN DE ARCHIVO EN MEDIO DEL COMENTARIO
    matrizAS[15][SIMBOLO_FIN_DE_ARCHIVO]={0, &AccionesSemanticas::agregarCaracter};
//CAMINOS DIRECTOS
    //DEVOLVER OPERADOR
    matrizAS[0][SIGNO_SUMA] = {-1, &AccionesSemanticas::devolverSuma};
    matrizAS[0][SIGNO_RESTA]= {-1, &AccionesSemanticas::devolverResta};
    matrizAS[0][SIGNO_OPERADOR]= {-1, &AccionesSemanticas::devolverOperador};
    //DEVOLVER LITERAL
    matrizAS[0][LITERALES]= {-1, &AccionesSemanticas::devolverAsignacion};
    matrizAS[0][SIMBOLO_FIN_DE_ARCHIVO]{-1, &AccionesSemanticas::notificarFinArchivo};

}