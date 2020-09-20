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

void Yylex::guardarToken(int id, string punt){
    this->t.id=id;
    this->t.lexema=punt;
}

void Yylex::aumentarCaracter() {
    this->caracteresAvanzados++;
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
    matrizAS[0][MINUSCULA] = {1, &AccionesSemanticas::inicializarToken};
    matrizAS[0][F_MINUSCULA]= {1, &AccionesSemanticas::inicializarToken};
    matrizAS[0][L_MINUSCULA]= {1, &AccionesSemanticas::inicializarToken};
    matrizAS[1][MINUSCULA] = {1, &AccionesSemanticas::agregarCaracter};
    matrizAS[1][GUION_BAJO]= {1, &AccionesSemanticas::agregarCaracter};
    matrizAS[1][F_MINUSCULA]= {1, &AccionesSemanticas::agregarCaracter};
    matrizAS[1][L_MINUSCULA]= {1, &AccionesSemanticas::agregarCaracter};
    matrizAS[1][DIGITO]= {1, &AccionesSemanticas::agregarCaracter};
    matrizAS[1][COMPARADOR_MAYOR]={17, &AccionesSemanticas::devolverIdentificador};
}