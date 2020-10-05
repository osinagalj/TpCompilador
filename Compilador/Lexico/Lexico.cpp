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
        return COLUMN_LOWERCASE_L;
    if(carac=='f')
        return COLUMN_LOWERCASE_F;
    if (carac<='z' && carac>='a') // es minus
        return COLUMN_LOWERCASE;
    if (carac<='Z' && carac>='A') //es mayus
        return COLUMN_UPPERCASE;
    if (carac>='0' && carac<='9')// es dig
        return COLUMN_DIGIT;

    switch(carac)
    {
        case '.':
            return COLUMN_DOT;
        case '+':
            return COLUMN_SUM;
        case '*': //Multiplicacion
            return COLUMN_MULTIPLICATION;
        case '-': //Signo menos
            return COLUMN_SUBTRACTION;
        case '_': //Guion bajo
            return COLUMN_UNDERSCORE;
        case '=':
            return COLUMN_EQUAL;
        case '<': //Bloque de menor;
            return COLUMN_LESS;
        case '>':
            return COLUMN_GREATER;
        case '!':
            return COLUMN_COLUMN_DIFFERENT;
        case '"':
            return COLUMN_QUOTE;
        case '/':
            return COLUMN_DIVISION;
        case '%':
            return COLUMN_PERCENTAGE;
        case '(':
            return COLUMN_LITERALS;
        case ')':
            return COLUMN_LITERALS;
        case ',':
            return COLUMN_LITERALS;
        case ';':
            return COLUMN_LITERALS;
        case '{':
            return COLUMN_LITERALS;
        case '}':
            return COLUMN_LITERALS;
        case '$':
            return COLUMN_END_FILE;
        case ' ': //Espacio en blanco;
            return COLUMN_BL_TAB_NL;
        case '\n': //Salto de línea;
            return COLUMN_BL_TAB_NL;
        //default, es el bloque que se ejecuta en caso de que no se de ningún caso
        default:
            return OTHER; //devuelvo numero de columna 'OTHER'
    }
}

//Matriz Semantic Action
void Lexico::initializeMatrixSA(){
//CAMINO 0
    //INICIALIZAR
    //CAMINOS DIRECTOS
    //DEVOLVER OPERADOR
    matrizAS[0][COLUMN_BL_TAB_NL]= {0, &AccionesSemanticas::descartarCaracter};

    matrizAS[0][COLUMN_SUM] = {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[0][COLUMN_SUBTRACTION]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[0][COLUMN_MULTIPLICATION]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[0][COLUMN_END_FILE]={ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[0][COLUMN_LITERALS]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[0][COLUMN_DOT]= {5, &AccionesSemanticas::inicializarToken};
    matrizAS[0][COLUMN_LOWERCASE] = {1, &AccionesSemanticas::inicializarToken};
    matrizAS[0][COLUMN_LOWERCASE_F]= {1, &AccionesSemanticas::inicializarToken};
    matrizAS[0][COLUMN_LOWERCASE_L]= {1, &AccionesSemanticas::inicializarToken};


//Camino 1
    //AGREGAR
    matrizAS[1][COLUMN_LOWERCASE] = {1, &AccionesSemanticas::agregarCaracter};
    matrizAS[1][COLUMN_UNDERSCORE]= {1, &AccionesSemanticas::agregarCaracter};
    matrizAS[1][COLUMN_LOWERCASE_F]= {1, &AccionesSemanticas::agregarCaracter};
    matrizAS[1][COLUMN_LOWERCASE_L]= {1, &AccionesSemanticas::agregarCaracter};
    matrizAS[1][COLUMN_DIGIT]= {1, &AccionesSemanticas::agregarCaracter};
    //ENTREGAR ID
    matrizAS[1][OTHER]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][COLUMN_UPPERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][COLUMN_DOT]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][COLUMN_PERCENTAGE]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][COLUMN_SUBTRACTION]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][COLUMN_COLUMN_DIFFERENT]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][COLUMN_DIVISION]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][COLUMN_MULTIPLICATION]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][COLUMN_GREATER]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][COLUMN_EQUAL]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][COLUMN_LESS]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][COLUMN_QUOTE]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][COLUMN_LITERALS]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][COLUMN_BL_TAB_NL]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][COLUMN_END_FILE]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
    matrizAS[1][COLUMN_SUM]= {ESTADO_FINAL, &AccionesSemanticas::devolverIdentificador};
//CAMINO 2
    //INICIALIZAR
    matrizAS[0][COLUMN_UPPERCASE] = {2, &AccionesSemanticas::inicializarToken};
    //AGREGAR
    matrizAS[2][COLUMN_UPPERCASE] = {2, &AccionesSemanticas::agregarCaracter};
    matrizAS[2][COLUMN_UNDERSCORE]= {2, &AccionesSemanticas::agregarCaracter};
    //ENTREGAR PAL RESERVADA
    matrizAS[2][COLUMN_COLUMN_DIFFERENT]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COLUMN_DIGIT]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COLUMN_LOWERCASE_F]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COLUMN_LOWERCASE_L]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][OTHER]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COLUMN_LOWERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COLUMN_DOT]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COLUMN_PERCENTAGE]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COLUMN_SUBTRACTION]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COLUMN_DIVISION]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COLUMN_MULTIPLICATION]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COLUMN_GREATER]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COLUMN_EQUAL]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COLUMN_LESS]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COLUMN_QUOTE]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COLUMN_LITERALS]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COLUMN_BL_TAB_NL]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COLUMN_END_FILE]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
    matrizAS[2][COLUMN_SUM]= {ESTADO_FINAL, &AccionesSemanticas::devolverReservada};
//CAMINO 3
    //INICIALIZAR
    matrizAS[0][COLUMN_DIGIT] = {3, &AccionesSemanticas::inicializarToken};
    //AGREGAR
    matrizAS[3][COLUMN_DIGIT] = {3, &AccionesSemanticas::agregarCaracter};
    matrizAS[3][COLUMN_UNDERSCORE]= {4, &AccionesSemanticas::agregarCaracter};
    matrizAS[3][COLUMN_DOT]={5, &AccionesSemanticas::agregarCaracter};
    //ENTREGAR CONSTANTE SIMPLE
    matrizAS[3][COLUMN_COLUMN_DIFFERENT]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COLUMN_UPPERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COLUMN_LOWERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COLUMN_LOWERCASE_F]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COLUMN_LOWERCASE_L]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][OTHER]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COLUMN_PERCENTAGE]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COLUMN_SUBTRACTION]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COLUMN_DIVISION]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COLUMN_MULTIPLICATION]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COLUMN_GREATER]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COLUMN_EQUAL]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COLUMN_LESS]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COLUMN_QUOTE]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COLUMN_LITERALS]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COLUMN_BL_TAB_NL]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COLUMN_END_FILE]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
    matrizAS[3][COLUMN_SUM]= {ESTADO_FINAL, &AccionesSemanticas::devolverConstante};
//CAMINO 4
    //ENTREGAR ENTERO LARGO
    matrizAS[4][COLUMN_LOWERCASE_L] = {ESTADO_FINAL, &AccionesSemanticas::devolverEnteroLargo};
    //INFORMAR ERROR
    matrizAS[4][COLUMN_COLUMN_DIFFERENT]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][COLUMN_DIGIT]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][COLUMN_UNDERSCORE]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][COLUMN_DOT]={ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][COLUMN_UPPERCASE]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][COLUMN_LOWERCASE]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][COLUMN_LOWERCASE_F]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][OTHER]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][COLUMN_PERCENTAGE]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][COLUMN_SUBTRACTION]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][COLUMN_DIVISION]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][COLUMN_MULTIPLICATION]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][COLUMN_GREATER]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][COLUMN_EQUAL]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][COLUMN_LESS]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][COLUMN_QUOTE]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][COLUMN_LITERALS]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][COLUMN_BL_TAB_NL]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][COLUMN_END_FILE]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[4][COLUMN_SUM]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};

//CAMINO 5
    //AGREGAR
    matrizAS[5][COLUMN_DIGIT]= {5, &AccionesSemanticas::agregarCaracter};
    matrizAS[5][COLUMN_LOWERCASE_F] = {6, &AccionesSemanticas::agregarCaracter};
    //INFORMAR ERROR
    matrizAS[5][COLUMN_LOWERCASE_L] = {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][COLUMN_COLUMN_DIFFERENT]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][COLUMN_UNDERSCORE]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][COLUMN_DOT]={ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][COLUMN_UPPERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][COLUMN_LOWERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][OTHER]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][COLUMN_PERCENTAGE]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][COLUMN_SUBTRACTION]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][COLUMN_DIVISION]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][COLUMN_MULTIPLICATION]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][COLUMN_GREATER]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][COLUMN_EQUAL]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][COLUMN_LESS]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][COLUMN_QUOTE]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][COLUMN_LITERALS]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][COLUMN_BL_TAB_NL]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][COLUMN_END_FILE]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[5][COLUMN_SUM]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
//CAMINO 6
    //AGREGAR
    matrizAS[6][COLUMN_SUBTRACTION]= {7, &AccionesSemanticas::agregarCaracter};
    matrizAS[6][COLUMN_SUM] = {7, &AccionesSemanticas::agregarCaracter};
    //INFORMAR ERROR
    matrizAS[6][COLUMN_DIGIT]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][COLUMN_LOWERCASE_F] = {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][COLUMN_LOWERCASE_L] = {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][COLUMN_COLUMN_DIFFERENT]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][COLUMN_UNDERSCORE]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][COLUMN_DOT]={ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][COLUMN_UPPERCASE]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][COLUMN_LOWERCASE]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][OTHER]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][COLUMN_PERCENTAGE]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};

    matrizAS[6][COLUMN_DIVISION]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][COLUMN_MULTIPLICATION]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][COLUMN_GREATER]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][COLUMN_EQUAL]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][COLUMN_LESS]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][COLUMN_QUOTE]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][COLUMN_LITERALS]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][COLUMN_BL_TAB_NL]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[6][COLUMN_END_FILE]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
//CAMINO 7
    //AGREGAR
    matrizAS[7][COLUMN_DIGIT]= {7, &AccionesSemanticas::agregarCaracter};
    //DEVOLVER FLOAT
    matrizAS[7][COLUMN_SUM] = {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][COLUMN_SUBTRACTION]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][COLUMN_LOWERCASE_F] = {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][COLUMN_LOWERCASE_L] = {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][COLUMN_COLUMN_DIFFERENT]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][COLUMN_UNDERSCORE]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][COLUMN_DOT]={ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][COLUMN_UPPERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][COLUMN_LOWERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][OTHER]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][COLUMN_PERCENTAGE]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][COLUMN_SUBTRACTION]= {ESTADO_FINAL, &AccionesSemanticas::devolverEnteroLargo};
    matrizAS[7][COLUMN_DIVISION]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][COLUMN_MULTIPLICATION]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][COLUMN_GREATER]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][COLUMN_EQUAL]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][COLUMN_LESS]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][COLUMN_QUOTE]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][COLUMN_LITERALS]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][COLUMN_BL_TAB_NL]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
    matrizAS[7][COLUMN_END_FILE]= {ESTADO_FINAL, &AccionesSemanticas::devolverFloat};
//CAMINO 8
    //AGREGAR
    matrizAS[0][COLUMN_LESS]= {8, &AccionesSemanticas::agregarCaracter};
    //DEVOLVER MENOR IGUAL
    matrizAS[8][COLUMN_EQUAL]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorCompuesto};
    //DEVOLVER MENOR
    matrizAS[8][COLUMN_DIGIT]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][COLUMN_SUM] = {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][COLUMN_SUBTRACTION]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][COLUMN_LOWERCASE_F] = {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][COLUMN_LOWERCASE_L] = {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][COLUMN_COLUMN_DIFFERENT]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][COLUMN_UNDERSCORE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][COLUMN_DOT]={ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][COLUMN_UPPERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][COLUMN_LOWERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][OTHER]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][COLUMN_PERCENTAGE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][COLUMN_DIVISION]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][COLUMN_MULTIPLICATION]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][COLUMN_GREATER]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][COLUMN_QUOTE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][COLUMN_LITERALS]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][COLUMN_BL_TAB_NL]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[8][COLUMN_END_FILE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
//CAMINO 9
    //AGREGAR
    matrizAS[0][COLUMN_GREATER]= {9, &AccionesSemanticas::agregarCaracter};
    //DEVOLVER MAYOR IGUAL
    matrizAS[9][COLUMN_EQUAL]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorCompuesto};
    //DEVOLVER MENOR
    matrizAS[9][COLUMN_DIGIT]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][COLUMN_SUM] = {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][COLUMN_SUBTRACTION]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][COLUMN_LOWERCASE_F] = {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][COLUMN_LOWERCASE_L] = {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][COLUMN_COLUMN_DIFFERENT]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][COLUMN_UNDERSCORE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][COLUMN_DOT]={ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][COLUMN_UPPERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][COLUMN_LOWERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][OTHER]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][COLUMN_PERCENTAGE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][COLUMN_DIVISION]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][COLUMN_MULTIPLICATION]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][COLUMN_LESS]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][COLUMN_QUOTE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][COLUMN_LITERALS]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][COLUMN_BL_TAB_NL]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[9][COLUMN_END_FILE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
//CAMINO 10
    //AGREGAR
    matrizAS[0][COLUMN_EQUAL]= {10, &AccionesSemanticas::agregarCaracter};
    //DEVOLVER IGUAL
    matrizAS[10][COLUMN_EQUAL]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorCompuesto};
    //DEVOLVER ASIGNACION
    matrizAS[10][COLUMN_DIGIT]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][COLUMN_SUM] = {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][COLUMN_SUBTRACTION]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][COLUMN_LOWERCASE_F] = {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][COLUMN_LOWERCASE_L] = {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][COLUMN_COLUMN_DIFFERENT]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][COLUMN_UNDERSCORE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][COLUMN_DOT]={ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][COLUMN_UPPERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][COLUMN_LOWERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][OTHER]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][COLUMN_PERCENTAGE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][COLUMN_DIVISION]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][COLUMN_MULTIPLICATION]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][COLUMN_LESS]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][COLUMN_GREATER]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][COLUMN_QUOTE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][COLUMN_LITERALS]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][COLUMN_BL_TAB_NL]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
    matrizAS[10][COLUMN_END_FILE]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorSimple};
//CAMINO 11
    //AGREGAR
    matrizAS[0][COLUMN_COLUMN_DIFFERENT]= {11, &AccionesSemanticas::agregarCaracter};
    //DEVOLVER DISTINTO
    matrizAS[11][COLUMN_EQUAL]= {ESTADO_FINAL, &AccionesSemanticas::devolverComparadorCompuesto};
    //INFORMAR ERROR
    matrizAS[11][COLUMN_DIGIT]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[11][COLUMN_LOWERCASE_F] = {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[11][COLUMN_LOWERCASE_L] = {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    //matrizAS[11][COLUMN_EQUAL]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError}; estaba repetido xd, 20 min buscando por que se me rompia el !=
    matrizAS[11][COLUMN_UNDERSCORE]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[11][COLUMN_DOT]={ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[11][COLUMN_UPPERCASE]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[11][COLUMN_LOWERCASE]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[11][OTHER]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[11][COLUMN_PERCENTAGE]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[11][COLUMN_SUBTRACTION]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[11][COLUMN_DIVISION]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[11][COLUMN_LESS]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[11][COLUMN_GREATER]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[11][COLUMN_QUOTE]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
    matrizAS[11][COLUMN_BL_TAB_NL]= {ESTADO_FINAL, &AccionesSemanticas::mensajeError};
//CAMINO 12
    //AGREGAR

    matrizAS[0][COLUMN_QUOTE]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COLUMN_COLUMN_DIFFERENT]= {11, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COLUMN_EQUAL]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COLUMN_SUM] = {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COLUMN_SUBTRACTION]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COLUMN_MULTIPLICATION]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COLUMN_LITERALS]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COLUMN_END_FILE]={0, &AccionesSemanticas::notificarFinArchivoInesperado};  // ACÁ PASABA ALGO?
    matrizAS[12][COLUMN_DIGIT]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COLUMN_LOWERCASE_F] = {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COLUMN_LOWERCASE_L] = {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COLUMN_EQUAL]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COLUMN_UNDERSCORE]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COLUMN_DOT]={12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COLUMN_UPPERCASE]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COLUMN_LOWERCASE]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][OTHER]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COLUMN_PERCENTAGE]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COLUMN_DIVISION]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COLUMN_LESS]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COLUMN_GREATER]= {12, &AccionesSemanticas::agregarCaracter};
    matrizAS[12][COLUMN_BL_TAB_NL]= {12, &AccionesSemanticas::agregarCaracter};
    //DEVOLVER CADENA
    matrizAS[12][COLUMN_QUOTE]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
//CAMINO 13
    //AGREGAR
    matrizAS[0][COLUMN_DIVISION]= {13, &AccionesSemanticas::agregarCaracter};
    //DEVOLVER DIVISION
    matrizAS[13][COLUMN_COLUMN_DIFFERENT]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][COLUMN_EQUAL]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][COLUMN_SUM] = {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][COLUMN_SUBTRACTION]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][COLUMN_MULTIPLICATION]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][COLUMN_LITERALS]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][COLUMN_END_FILE]={ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][COLUMN_DIGIT]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][COLUMN_LOWERCASE_F] = {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][COLUMN_LOWERCASE_L] = {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][COLUMN_UNDERSCORE]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][COLUMN_DOT]={ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][COLUMN_UPPERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][COLUMN_LOWERCASE]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][OTHER]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][COLUMN_QUOTE]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][COLUMN_LESS]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][COLUMN_GREATER]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    matrizAS[13][COLUMN_BL_TAB_NL]= {ESTADO_FINAL, &AccionesSemanticas::devolverUnico};
    //INICIO DE COMENTARIO
    matrizAS[13][COLUMN_PERCENTAGE]= {14, &AccionesSemanticas::descartarCaracter};
//CAMINO 14
    //AGREGAR
    matrizAS[14][COLUMN_DIVISION]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][COLUMN_COLUMN_DIFFERENT]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][COLUMN_EQUAL]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][COLUMN_SUM] = {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][COLUMN_SUBTRACTION]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][COLUMN_MULTIPLICATION]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][COLUMN_LITERALS]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][COLUMN_DIGIT]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][COLUMN_LOWERCASE_F] = {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][COLUMN_LOWERCASE_L] = {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][COLUMN_UNDERSCORE]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][COLUMN_DOT]={14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][COLUMN_UPPERCASE]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][COLUMN_LOWERCASE]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][OTHER]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][COLUMN_QUOTE]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][COLUMN_LESS]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][COLUMN_GREATER]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[14][COLUMN_BL_TAB_NL]= {14, &AccionesSemanticas::descartarCaracter};
    //POSIBLE FIN DE COMENTARIO
    matrizAS[14][COLUMN_PERCENTAGE]= {15, &AccionesSemanticas::descartarCaracter};
    //FIN DE ARCHIVO EN MEDIO DEL COMENTARIO
    matrizAS[14][COLUMN_END_FILE]={0, &AccionesSemanticas::notificarFinArchivoInesperado};
//CAMINO 15
    //AGREGAR (VUELVO A ESTADO 14 PORQUE NO SE CERRO EL COMENTARIO)
    matrizAS[15][COLUMN_COLUMN_DIFFERENT]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][COLUMN_EQUAL]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][COLUMN_SUM] = {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][COLUMN_SUBTRACTION]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][COLUMN_MULTIPLICATION]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][COLUMN_LITERALS]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][COLUMN_DIGIT]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][COLUMN_LOWERCASE_F] = {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][COLUMN_LOWERCASE_L] = {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][COLUMN_UNDERSCORE]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][COLUMN_DOT]={14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][COLUMN_UPPERCASE]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][COLUMN_LOWERCASE]= {14, &AccionesSemanticas::descartarCaracter};

    matrizAS[15][OTHER]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][COLUMN_QUOTE]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][COLUMN_LESS]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][COLUMN_GREATER]= {14, &AccionesSemanticas::descartarCaracter};
    matrizAS[15][COLUMN_BL_TAB_NL]= {14, &AccionesSemanticas::descartarCaracter};
    //POSIBLE FIN DE COMENTARIO
    matrizAS[15][COLUMN_PERCENTAGE]= {15, &AccionesSemanticas::descartarCaracter};
    //FIN COMENTARIO (descartar)
    matrizAS[15][COLUMN_DIVISION]= {0, &AccionesSemanticas::descartarCaracter};
    //FIN DE ARCHIVO EN MEDIO DEL COMENTARIO
    matrizAS[15][COLUMN_END_FILE]={0, &AccionesSemanticas::notificarFinArchivoInesperado};


}