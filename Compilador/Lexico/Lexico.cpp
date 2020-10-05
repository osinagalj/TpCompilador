#include <iostream>
#include "Lexico.h"

using namespace std;

Lexico::Lexico() {

    initializeMatrixSA();
    palabrasReservadas.insert(pair<string,int>("IF",IF));
    palabrasReservadas.insert(pair<string,int>("ELSE",ELSE));
    palabrasReservadas.insert(pair<string,int>("END_IF",END_IF));

    palabrasReservadas.insert(pair<string,int>("OUT",OUT));
    palabrasReservadas.insert(pair<string,int>("WHILE",WHILE));
    palabrasReservadas.insert(pair<string,int>("LOOP",LOOP));
    palabrasReservadas.insert(pair<string,int>("FLOAT",FLOAT));
    palabrasReservadas.insert(pair<string,int>("LONGINT",LONGINT));
    palabrasReservadas.insert(pair<string,int>("INT",INT));
    palabrasReservadas.insert(pair<string,int>("PROC",PROC));
    palabrasReservadas.insert(pair<string,int>("TRUE",TRUE));
    palabrasReservadas.insert(pair<string,int>("FALSE",FALSE));
    palabrasReservadas.insert(pair<string,int>("NA",NA));
    palabrasReservadas.insert(pair<string,int>("SHADOWING",SHADOWING));

    //INTEGER = CTE;
}

int Lexico::getIdPalabraReservada()
{
    auto search = palabrasReservadas.find(cadena);
    if (search != palabrasReservadas.end()) {
        return search->second;
    }
    return ERROR; //preguntar
}
void Lexico::loadFile(string path)
{
    source_file.open(path,ifstream::in);
    if(!source_file.is_open()){
        cout << "Error al abrir el archivo de código fuente" << endl;
        exit(1);
    }else
        if(current_line>1){
            int aux=0;
            while(aux < current_line-1){
                //cout<<" entro kaka: " <<endl;
                aux ++;
                getline(source_file,line);
            }
        }
}
void Lexico::set_token_found(){
    this->token_found=true;
}

void Lexico::guardarToken(int id, string pointerST){
    this->t.id=id;
    this->t.pointerST=pointerST;
}

void Lexico::aumentarCaracter() {
    this->current_character++;
}
int Lexico::get_number_line() {
    return this->current_line;
}
Lexico::Token Lexico::getToken(string path){
   this->token_found=false;
   this->cadena="";
    actual_state=0;
        loadFile(path);
        while (!source_file.eof()) {
            getline(source_file,line);
            while(current_character < line.size() && !token_found && !end){
                char caracterActual=line[current_character];
                new_state = identify_character(caracterActual);
                matrizAS[actual_state][new_state].Action(this,caracterActual); //ejecutar acción semántica
                actual_state=matrizAS[actual_state][new_state].state; //actualizo el nuevo estado
            }
            if ((current_character < line.size()) && token_found){ // encontré toke
                source_file.close(); //cerramos archivo
                return t;
            }else{
                current_line++;
                current_character = 0;
            }
        }
        return t;
}
void Lexico::saveInST(int id){
    SymbolTable::Registro registro;
    registro.id = id;
    symbolTable->addSymbol(t.pointerST,registro);
}

int Lexico::identify_character(char carac){
//esta funcion te devuelve el numero de columna de la matriz de transicion de estado

    if(carac=='l')
        return COLUMNA_L_MINUSCULA;
    if(carac=='f')
        return COLUMNA_F_MINUSCULA;
    if (carac<='z' && carac>='a') // es minus
        return COLUMN_LOWERCASE;
    if (carac<='Z' && carac>='A') //es mayus
        return COLUMN_UPPERCASE;
    if (carac>='0' && carac<='9')// es dig
        return COLUMNA_DIGITO;

    switch(carac)
    {
        case '.':
            return SIMBOLO_PUNTO;
        case '+':
            return SIGNO_SUMA;
        case '*': //Multiplicacion
            return SIGNO_MULTIPLICACION;
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

//Matriz Semantic Action
void Lexico::initializeMatrixSA(){
//CAMINO 0
    //INICIALIZAR
    //CAMINOS DIRECTOS
    //DEVOLVER OPERADOR
    matrizAS[0][BL_TAB_NL]= {0, &AccionesSemanticas::descartarCaracter};

    matrizAS[0][SIGNO_SUMA] = {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[0][SIGNO_RESTA]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[0][SIGNO_MULTIPLICACION]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[0][SIMBOLO_FIN_DE_ARCHIVO]={ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[0][LITERALES]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[0][SIMBOLO_PUNTO]= {5, &AccionesSemanticas::inicializarToken};
    matrizAS[0][COLUMN_LOWERCASE] = {1, &AccionesSemanticas::inicializarToken};
    matrizAS[0][COLUMNA_F_MINUSCULA]= {1, &AccionesSemanticas::inicializarToken};
    matrizAS[0][COLUMNA_L_MINUSCULA]= {1, &AccionesSemanticas::inicializarToken};


//Camino 1
    //AGREGAR
    matrizAS[1][COLUMN_LOWERCASE] = {1, &AccionesSemanticas::agregarCaracter};
    matrizAS[1][GUION_BAJO]= {1, &AccionesSemanticas::agregarCaracter};
    matrizAS[1][COLUMNA_F_MINUSCULA]= {1, &AccionesSemanticas::agregarCaracter};
    matrizAS[1][COLUMNA_L_MINUSCULA]= {1, &AccionesSemanticas::agregarCaracter};
    matrizAS[1][COLUMNA_DIGITO]= {1, &AccionesSemanticas::agregarCaracter};
    //ENTREGAR ID
    matrizAS[1][OTRO]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][COLUMN_UPPERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][SIMBOLO_PUNTO]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][SIMBOLO_PORCENTAJE]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][SIGNO_RESTA]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][SIMBOLO_DISTINTO]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][SIGNO_DIVISION]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][SIGNO_MULTIPLICACION]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][COMPARADOR_MAYOR]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][COMPARADOR_IGUAL]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][COMPARADOR_MENOR]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][COMILLA]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][LITERALES]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][BL_TAB_NL]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][SIMBOLO_FIN_DE_ARCHIVO]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][SIGNO_SUMA]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
//CAMINO 2
    //INICIALIZAR
    matrizAS[0][COLUMN_UPPERCASE] = {2, &AccionesSemanticas::inicializarToken};
    //AGREGAR
    matrizAS[2][COLUMN_UPPERCASE] = {2, &AccionesSemanticas::agregarCaracter};
    matrizAS[2][GUION_BAJO]= {2, &AccionesSemanticas::agregarCaracter};
    //ENTREGAR PAL RESERVADA
    matrizAS[2][SIMBOLO_DISTINTO]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COLUMNA_DIGITO]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COLUMNA_F_MINUSCULA]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COLUMNA_L_MINUSCULA]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][OTRO]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COLUMN_LOWERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][SIMBOLO_PUNTO]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][SIMBOLO_PORCENTAJE]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][SIGNO_RESTA]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][SIGNO_DIVISION]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][SIGNO_MULTIPLICACION]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COMPARADOR_MAYOR]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COMPARADOR_IGUAL]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COMPARADOR_MENOR]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COMILLA]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][LITERALES]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][BL_TAB_NL]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][SIMBOLO_FIN_DE_ARCHIVO]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][SIGNO_SUMA]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
//CAMINO 3
    //INICIALIZAR
    matrizAS[0][COLUMNA_DIGITO] = {3, &AccionesSemanticas::inicializarToken};
    //AGREGAR
    matrizAS[3][COLUMNA_DIGITO] = {3, &AccionesSemanticas::agregarCaracter};
    matrizAS[3][GUION_BAJO]= {4, &AccionesSemanticas::agregarCaracter};
    matrizAS[3][SIMBOLO_PUNTO]={5, &AccionesSemanticas::agregarCaracter};
    //ENTREGAR CONSTANTE SIMPLE
    matrizAS[3][SIMBOLO_DISTINTO]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COLUMN_UPPERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COLUMN_LOWERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COLUMNA_F_MINUSCULA]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COLUMNA_L_MINUSCULA]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][OTRO]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][SIMBOLO_PORCENTAJE]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][SIGNO_RESTA]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][SIGNO_DIVISION]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][SIGNO_MULTIPLICACION]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COMPARADOR_MAYOR]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COMPARADOR_IGUAL]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COMPARADOR_MENOR]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COMILLA]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][LITERALES]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][BL_TAB_NL]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][SIMBOLO_FIN_DE_ARCHIVO]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][SIGNO_SUMA]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
//CAMINO 4
    //ENTREGAR ENTERO LARGO
    matrizAS[4][COLUMNA_L_MINUSCULA] = {ESTADO_FINAL, &AccionesSemanticas::devolverEnteroLargo};
    //INFORMAR ERROR
    matrizAS[4][SIMBOLO_DISTINTO]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][COLUMNA_DIGITO]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][GUION_BAJO]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][SIMBOLO_PUNTO]={ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][COLUMN_UPPERCASE]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][COLUMN_LOWERCASE]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][COLUMNA_F_MINUSCULA]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][OTRO]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][SIMBOLO_PORCENTAJE]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][SIGNO_RESTA]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][SIGNO_DIVISION]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][SIGNO_MULTIPLICACION]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][COMPARADOR_MAYOR]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][COMPARADOR_IGUAL]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][COMPARADOR_MENOR]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][COMILLA]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][LITERALES]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][BL_TAB_NL]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][SIMBOLO_FIN_DE_ARCHIVO]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][SIGNO_SUMA]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};

//CAMINO 5
    //AGREGAR
    matrizAS[5][COLUMNA_DIGITO]= {5, &AccionesSemanticas::agregarCaracter};
    matrizAS[5][COLUMNA_F_MINUSCULA] = {6, &AccionesSemanticas::agregarCaracter};
    //INFORMAR ERROR
    matrizAS[5][COLUMNA_L_MINUSCULA] = {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][SIMBOLO_DISTINTO]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][GUION_BAJO]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][SIMBOLO_PUNTO]={ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][COLUMN_UPPERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][COLUMN_LOWERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][OTRO]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][SIMBOLO_PORCENTAJE]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][SIGNO_RESTA]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][SIGNO_DIVISION]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][SIGNO_MULTIPLICACION]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][COMPARADOR_MAYOR]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][COMPARADOR_IGUAL]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][COMPARADOR_MENOR]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][COMILLA]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][LITERALES]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][BL_TAB_NL]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][SIMBOLO_FIN_DE_ARCHIVO]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][SIGNO_SUMA]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
//CAMINO 6
    //AGREGAR
    matrizAS[6][SIGNO_RESTA]= {7, &AccionesSemanticas::agregarCaracter};
    matrizAS[6][SIGNO_SUMA] = {7, &AccionesSemanticas::agregarCaracter};
    //INFORMAR ERROR
    matrizAS[6][COLUMNA_DIGITO]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][COLUMNA_F_MINUSCULA] = {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][COLUMNA_L_MINUSCULA] = {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][SIMBOLO_DISTINTO]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][GUION_BAJO]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][SIMBOLO_PUNTO]={ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][COLUMN_UPPERCASE]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][COLUMN_LOWERCASE]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][OTRO]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][SIMBOLO_PORCENTAJE]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};

    matrizAS[6][SIGNO_DIVISION]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][SIGNO_MULTIPLICACION]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][COMPARADOR_MAYOR]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][COMPARADOR_IGUAL]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][COMPARADOR_MENOR]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][COMILLA]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][LITERALES]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][BL_TAB_NL]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][SIMBOLO_FIN_DE_ARCHIVO]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
//CAMINO 7
    //AGREGAR
    matrizAS[7][COLUMNA_DIGITO]= {7, &AccionesSemanticas::agregarCaracter};
    //DEVOLVER FLOAT
    matrizAS[7][SIGNO_SUMA] = {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][SIGNO_RESTA]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][COLUMNA_F_MINUSCULA] = {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][COLUMNA_L_MINUSCULA] = {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][SIMBOLO_DISTINTO]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][GUION_BAJO]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][SIMBOLO_PUNTO]={ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][COLUMN_UPPERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][COLUMN_LOWERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][OTRO]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][SIMBOLO_PORCENTAJE]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][SIGNO_RESTA]= {ESTADO_FINAL, &AccionesSemanticas::devolverEnteroLargo};
    matrizAS[7][SIGNO_DIVISION]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][SIGNO_MULTIPLICACION]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][COMPARADOR_MAYOR]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][COMPARADOR_IGUAL]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][COMPARADOR_MENOR]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][COMILLA]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][LITERALES]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][BL_TAB_NL]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][SIMBOLO_FIN_DE_ARCHIVO]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
//CAMINO 8
    //AGREGAR
    matrizAS[0][COMPARADOR_MENOR]= {8, &AccionesSemanticas::agregarCaracter};
    //DEVOLVER MENOR IGUAL
    matrizAS[8][COMPARADOR_IGUAL]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorCompuesto};
    //DEVOLVER MENOR
    matrizAS[8][COLUMNA_DIGITO]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][SIGNO_SUMA] = {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][SIGNO_RESTA]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][COLUMNA_F_MINUSCULA] = {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][COLUMNA_L_MINUSCULA] = {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][SIMBOLO_DISTINTO]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][GUION_BAJO]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][SIMBOLO_PUNTO]={ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][COLUMN_UPPERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][COLUMN_LOWERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][OTRO]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][SIMBOLO_PORCENTAJE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][SIGNO_DIVISION]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][SIGNO_MULTIPLICACION]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][COMPARADOR_MAYOR]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][COMILLA]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][LITERALES]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][BL_TAB_NL]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][SIMBOLO_FIN_DE_ARCHIVO]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
//CAMINO 9
    //AGREGAR
    matrizAS[0][COMPARADOR_MAYOR]= {9, &AccionesSemanticas::agregarCaracter};
    //DEVOLVER MAYOR IGUAL
    matrizAS[9][COMPARADOR_IGUAL]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorCompuesto};
    //DEVOLVER MENOR
    matrizAS[9][COLUMNA_DIGITO]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][SIGNO_SUMA] = {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][SIGNO_RESTA]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][COLUMNA_F_MINUSCULA] = {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][COLUMNA_L_MINUSCULA] = {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][SIMBOLO_DISTINTO]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][GUION_BAJO]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][SIMBOLO_PUNTO]={ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][COLUMN_UPPERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][COLUMN_LOWERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][OTRO]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][SIMBOLO_PORCENTAJE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][SIGNO_DIVISION]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][SIGNO_MULTIPLICACION]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][COMPARADOR_MENOR]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][COMILLA]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][LITERALES]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][BL_TAB_NL]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][SIMBOLO_FIN_DE_ARCHIVO]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
//CAMINO 10
    //AGREGAR
    matrizAS[0][COMPARADOR_IGUAL]= {10, &AccionesSemanticas::agregarCaracter};
    //DEVOLVER IGUAL
    matrizAS[10][COMPARADOR_IGUAL]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorCompuesto};
    //DEVOLVER ASIGNACION
    matrizAS[10][COLUMNA_DIGITO]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][SIGNO_SUMA] = {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][SIGNO_RESTA]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][COLUMNA_F_MINUSCULA] = {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][COLUMNA_L_MINUSCULA] = {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][SIMBOLO_DISTINTO]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][GUION_BAJO]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][SIMBOLO_PUNTO]={ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][COLUMN_UPPERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][COLUMN_LOWERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][OTRO]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][SIMBOLO_PORCENTAJE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][SIGNO_DIVISION]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][SIGNO_MULTIPLICACION]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][COMPARADOR_MENOR]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][COMPARADOR_MAYOR]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][COMILLA]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][LITERALES]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][BL_TAB_NL]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][SIMBOLO_FIN_DE_ARCHIVO]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
//CAMINO 11
    //AGREGAR
    matrizAS[0][SIMBOLO_DISTINTO]= {11, &AccionesSemanticas::agregarCaracter};
    //DEVOLVER DISTINTO
    matrizAS[11][COMPARADOR_IGUAL]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorCompuesto};
    //INFORMAR ERROR
    matrizAS[11][COLUMNA_DIGITO]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[11][COLUMNA_F_MINUSCULA] = {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[11][COLUMNA_L_MINUSCULA] = {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    //matrizAS[11][COMPARADOR_IGUAL]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError}; estaba repetido xd, 20 min buscando por que se me rompia el !=
    matrizAS[11][GUION_BAJO]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[11][SIMBOLO_PUNTO]={ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[11][COLUMN_UPPERCASE]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[11][COLUMN_LOWERCASE]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[11][OTRO]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[11][SIMBOLO_PORCENTAJE]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[11][SIGNO_RESTA]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[11][SIGNO_DIVISION]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[11][COMPARADOR_MENOR]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[11][COMPARADOR_MAYOR]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[11][COMILLA]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[11][BL_TAB_NL]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
//CAMINO 12
    //AGREGAR

    matrizAS[0][COMILLA]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][SIMBOLO_DISTINTO]= {11, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COMPARADOR_IGUAL]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][SIGNO_SUMA] = {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][SIGNO_RESTA]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][SIGNO_MULTIPLICACION]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][LITERALES]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][SIMBOLO_FIN_DE_ARCHIVO]={0, &AccionesSemanticas::notificarFinArchivoInesperado};  // ACÁ PASABA ALGO?
    matrizAS[12][COLUMNA_DIGITO]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COLUMNA_F_MINUSCULA] = {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COLUMNA_L_MINUSCULA] = {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COMPARADOR_IGUAL]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][GUION_BAJO]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][SIMBOLO_PUNTO]={12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COLUMN_UPPERCASE]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COLUMN_LOWERCASE]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][OTRO]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][SIMBOLO_PORCENTAJE]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][SIGNO_DIVISION]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COMPARADOR_MENOR]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COMPARADOR_MAYOR]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][BL_TAB_NL]= {12, &AccionesSemanticas::agregarCaracter};
    //DEVOLVER CADENA
    matrizAS[12][COMILLA]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
//CAMINO 13
    //AGREGAR
    matrizAS[0][SIGNO_DIVISION]= {13, &AccionesSemanticas::agregarCaracter};
    //DEVOLVER DIVISION
    matrizAS[13][SIMBOLO_DISTINTO]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][COMPARADOR_IGUAL]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][SIGNO_SUMA] = {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][SIGNO_RESTA]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][SIGNO_MULTIPLICACION]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][LITERALES]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][SIMBOLO_FIN_DE_ARCHIVO]={ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][COLUMNA_DIGITO]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][COLUMNA_F_MINUSCULA] = {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][COLUMNA_L_MINUSCULA] = {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][GUION_BAJO]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][SIMBOLO_PUNTO]={ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][COLUMN_UPPERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][COLUMN_LOWERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][OTRO]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][COMILLA]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][COMPARADOR_MENOR]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][COMPARADOR_MAYOR]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][BL_TAB_NL]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    //INICIO DE COMENTARIO
    matrizAS[13][SIMBOLO_PORCENTAJE]= {14, &AccionesSemanticas::descartarCaracter};
//CAMINO 14
    //AGREGAR
    matrizAS[14][SIGNO_DIVISION]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][SIMBOLO_DISTINTO]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][COMPARADOR_IGUAL]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][SIGNO_SUMA] = {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][SIGNO_RESTA]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][SIGNO_MULTIPLICACION]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][LITERALES]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][COLUMNA_DIGITO]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][COLUMNA_F_MINUSCULA] = {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][COLUMNA_L_MINUSCULA] = {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][GUION_BAJO]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][SIMBOLO_PUNTO]={14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][COLUMN_UPPERCASE]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][COLUMN_LOWERCASE]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][OTRO]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][COMILLA]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][COMPARADOR_MENOR]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][COMPARADOR_MAYOR]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][BL_TAB_NL]= {14, &AccionesSemanticas::descartarCaracter};
    //POSIBLE FIN DE COMENTARIO
    matrizAS[14][SIMBOLO_PORCENTAJE]= {15, &AccionesSemanticas::descartarCaracter};
    //FIN DE ARCHIVO EN MEDIO DEL COMENTARIO
    matrizAS[14][SIMBOLO_FIN_DE_ARCHIVO]={0, &AccionesSemanticas::notificarFinArchivoInesperado};
//CAMINO 15
    //AGREGAR (VUELVO A ESTADO 14 PORQUE NO SE CERRO EL COMENTARIO)
    matrizAS[15][SIMBOLO_DISTINTO]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][COMPARADOR_IGUAL]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][SIGNO_SUMA] = {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][SIGNO_RESTA]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][SIGNO_MULTIPLICACION]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][LITERALES]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][COLUMNA_DIGITO]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][COLUMNA_F_MINUSCULA] = {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][COLUMNA_L_MINUSCULA] = {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][GUION_BAJO]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][SIMBOLO_PUNTO]={14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][COLUMN_UPPERCASE]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][COLUMN_LOWERCASE]= {14, &AccionesSemanticas::descartarCaracter};

    matrizAS[15][OTRO]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][COMILLA]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][COMPARADOR_MENOR]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][COMPARADOR_MAYOR]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][BL_TAB_NL]= {14, &AccionesSemanticas::descartarCaracter};
    //POSIBLE FIN DE COMENTARIO
    matrizAS[15][SIMBOLO_PORCENTAJE]= {15, &AccionesSemanticas::descartarCaracter};
    //FIN COMENTARIO (descartar)
    matrizAS[15][SIGNO_DIVISION]= {0, &AccionesSemanticas::descartarCaracter};
    //FIN DE ARCHIVO EN MEDIO DEL COMENTARIO
    matrizAS[15][SIMBOLO_FIN_DE_ARCHIVO]={0, &AccionesSemanticas::notificarFinArchivoInesperado};


}