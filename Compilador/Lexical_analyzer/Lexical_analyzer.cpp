#include <iostream>
#include "Lexical_analyzer.h"
#include "../Sintactic_analyzer/y.tab.h"
using namespace std;

Lexical_analyzer::Lexical_analyzer() {

    initializeMatrixSA();
    reserved_words.insert(pair<string,int>("IF",IF));
    reserved_words.insert(pair<string,int>("ELSE",ELSE));
    reserved_words.insert(pair<string,int>("END_IF",END_IF));
    reserved_words.insert(pair<string,int>("OUT",OUT));
    reserved_words.insert(pair<string,int>("WHILE",WHILE));
    reserved_words.insert(pair<string,int>("LOOP",LOOP));
    reserved_words.insert(pair<string,int>("FLOAT",FLOAT));
    reserved_words.insert(pair<string,int>("LONGINT",LONGINT));
    reserved_words.insert(pair<string,int>("INT",INT));
    reserved_words.insert(pair<string,int>("PROC",PROC));
    reserved_words.insert(pair<string,int>("TRUE",TRUE));
    reserved_words.insert(pair<string,int>("FALSE",FALSE));
    reserved_words.insert(pair<string,int>("NA",NA));
    reserved_words.insert(pair<string,int>("SHADOWING",SHADOWING));
    //INTEGER = CTE;
}

int Lexical_analyzer::get_reserved_word()
{
    auto search = reserved_words.find(word);
    if (search != reserved_words.end()) {
        return search->second;
    }
    return ERROR; //preguntar
}
void Lexical_analyzer::loadFile(string path)
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
void Lexical_analyzer::set_token_found()
{
    this->token_found=true;
}

void Lexical_analyzer::save_token(int id, string pointerST)
{
    this->t.id=id;
    this->t.pointerST=pointerST;
}

void Lexical_analyzer::increase_character()
{
    this->current_character++;
}
int Lexical_analyzer::get_number_line()
{
    return this->current_line;
}
Lexical_analyzer::Token Lexical_analyzer::getToken(string path)
{
   this->token_found=false;
   this->word="";
    actual_state=0;
        loadFile(path);
        while (!source_file.eof()) {
            getline(source_file,line);
            while(current_character < line.size() && !token_found && !end){
                char characterterActual=line[current_character];
                new_state = identify_character(characterterActual);
                matrizAS[actual_state][new_state].Action(this,characterterActual); //ejecutar acción semántica
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
void Lexical_analyzer::save_in_ST(int id)
{
    Symbol_table::Registry registry;
    registry.id = id;
    symbolTable->addSymbol(t.pointerST,registry);
}

int Lexical_analyzer::identify_character(char character){
//esta funcion te devuelve el numero de columna de la matriz de transicion de estado

    if(character=='l')
        return COLUMN_LOWERCASE_L;
    if(character=='f')
        return COLUMN_LOWERCASE_F;
    if (character<='z' && character>='a') // es minus
        return COLUMN_LOWERCASE;
    if (character<='Z' && character>='A') //es mayus
        return COLUMN_UPPERCASE;
    if (character>='0' && character<='9')// es dig
        return COLUMN_DIGIT;

    switch(character)
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
void Lexical_analyzer::initializeMatrixSA(){
//CAMINO 0
    //INICIALIZAR
    //CAMINOS DIRECTOS
    //DEVOLVER OPERADOR
    matrizAS[0][COLUMN_BL_TAB_NL]= {0, &Semantic_actions::discard_character};

    matrizAS[0][COLUMN_SUM] = {FINAL_STATE, &Semantic_actions::finish_symbol};
    matrizAS[0][COLUMN_SUBTRACTION]= {FINAL_STATE, &Semantic_actions::finish_symbol};
    matrizAS[0][COLUMN_MULTIPLICATION]= {FINAL_STATE, &Semantic_actions::finish_symbol};
    matrizAS[0][COLUMN_END_FILE]={FINAL_STATE, &Semantic_actions::finish_symbol};
    matrizAS[0][COLUMN_LITERALS]= {FINAL_STATE, &Semantic_actions::finish_symbol};
    matrizAS[0][COLUMN_DOT]= {5, &Semantic_actions::initialize_token};
    matrizAS[0][COLUMN_LOWERCASE] = {1, &Semantic_actions::initialize_token};
    matrizAS[0][COLUMN_LOWERCASE_F]= {1, &Semantic_actions::initialize_token};
    matrizAS[0][COLUMN_LOWERCASE_L]= {1, &Semantic_actions::initialize_token};


//Camino 1
    //AGREGAR
    matrizAS[1][COLUMN_LOWERCASE] = {1, &Semantic_actions::add_character};
    matrizAS[1][COLUMN_UNDERSCORE]= {1, &Semantic_actions::add_character};
    matrizAS[1][COLUMN_LOWERCASE_F]= {1, &Semantic_actions::add_character};
    matrizAS[1][COLUMN_LOWERCASE_L]= {1, &Semantic_actions::add_character};
    matrizAS[1][COLUMN_DIGIT]= {1, &Semantic_actions::add_character};
    //ENTREGAR ID
    matrizAS[1][OTHER]= {FINAL_STATE, &Semantic_actions::finish_identifier};
    matrizAS[1][COLUMN_UPPERCASE]= {FINAL_STATE, &Semantic_actions::finish_identifier};
    matrizAS[1][COLUMN_DOT]= {FINAL_STATE, &Semantic_actions::finish_identifier};
    matrizAS[1][COLUMN_PERCENTAGE]= {FINAL_STATE, &Semantic_actions::finish_identifier};
    matrizAS[1][COLUMN_SUBTRACTION]= {FINAL_STATE, &Semantic_actions::finish_identifier};
    matrizAS[1][COLUMN_COLUMN_DIFFERENT]= {FINAL_STATE, &Semantic_actions::finish_identifier};
    matrizAS[1][COLUMN_DIVISION]= {FINAL_STATE, &Semantic_actions::finish_identifier};
    matrizAS[1][COLUMN_MULTIPLICATION]= {FINAL_STATE, &Semantic_actions::finish_identifier};
    matrizAS[1][COLUMN_GREATER]= {FINAL_STATE, &Semantic_actions::finish_identifier};
    matrizAS[1][COLUMN_EQUAL]= {FINAL_STATE, &Semantic_actions::finish_identifier};
    matrizAS[1][COLUMN_LESS]= {FINAL_STATE, &Semantic_actions::finish_identifier};
    matrizAS[1][COLUMN_QUOTE]= {FINAL_STATE, &Semantic_actions::finish_identifier};
    matrizAS[1][COLUMN_LITERALS]= {FINAL_STATE, &Semantic_actions::finish_identifier};
    matrizAS[1][COLUMN_BL_TAB_NL]= {FINAL_STATE, &Semantic_actions::finish_identifier};
    matrizAS[1][COLUMN_END_FILE]= {FINAL_STATE, &Semantic_actions::finish_identifier};
    matrizAS[1][COLUMN_SUM]= {FINAL_STATE, &Semantic_actions::finish_identifier};
//CAMINO 2
    //INICIALIZAR
    matrizAS[0][COLUMN_UPPERCASE] = {2, &Semantic_actions::initialize_token};
    //AGREGAR
    matrizAS[2][COLUMN_UPPERCASE] = {2, &Semantic_actions::add_character};
    matrizAS[2][COLUMN_UNDERSCORE]= {2, &Semantic_actions::add_character};
    //ENTREGAR PAL RESERVADA
    matrizAS[2][COLUMN_COLUMN_DIFFERENT]= {FINAL_STATE, &Semantic_actions::finish_reserved_word};
    matrizAS[2][COLUMN_DIGIT]= {FINAL_STATE, &Semantic_actions::finish_reserved_word};
    matrizAS[2][COLUMN_LOWERCASE_F]= {FINAL_STATE, &Semantic_actions::finish_reserved_word};
    matrizAS[2][COLUMN_LOWERCASE_L]= {FINAL_STATE, &Semantic_actions::finish_reserved_word};
    matrizAS[2][OTHER]= {FINAL_STATE, &Semantic_actions::finish_reserved_word};
    matrizAS[2][COLUMN_LOWERCASE]= {FINAL_STATE, &Semantic_actions::finish_reserved_word};
    matrizAS[2][COLUMN_DOT]= {FINAL_STATE, &Semantic_actions::finish_reserved_word};
    matrizAS[2][COLUMN_PERCENTAGE]= {FINAL_STATE, &Semantic_actions::finish_reserved_word};
    matrizAS[2][COLUMN_SUBTRACTION]= {FINAL_STATE, &Semantic_actions::finish_reserved_word};
    matrizAS[2][COLUMN_DIVISION]= {FINAL_STATE, &Semantic_actions::finish_reserved_word};
    matrizAS[2][COLUMN_MULTIPLICATION]= {FINAL_STATE, &Semantic_actions::finish_reserved_word};
    matrizAS[2][COLUMN_GREATER]= {FINAL_STATE, &Semantic_actions::finish_reserved_word};
    matrizAS[2][COLUMN_EQUAL]= {FINAL_STATE, &Semantic_actions::finish_reserved_word};
    matrizAS[2][COLUMN_LESS]= {FINAL_STATE, &Semantic_actions::finish_reserved_word};
    matrizAS[2][COLUMN_QUOTE]= {FINAL_STATE, &Semantic_actions::finish_reserved_word};
    matrizAS[2][COLUMN_LITERALS]= {FINAL_STATE, &Semantic_actions::finish_reserved_word};
    matrizAS[2][COLUMN_BL_TAB_NL]= {FINAL_STATE, &Semantic_actions::finish_reserved_word};
    matrizAS[2][COLUMN_END_FILE]= {FINAL_STATE, &Semantic_actions::finish_reserved_word};
    matrizAS[2][COLUMN_SUM]= {FINAL_STATE, &Semantic_actions::finish_reserved_word};
//CAMINO 3
    //INICIALIZAR
    matrizAS[0][COLUMN_DIGIT] = {3, &Semantic_actions::initialize_token};
    //AGREGAR
    matrizAS[3][COLUMN_DIGIT] = {3, &Semantic_actions::add_character};
    matrizAS[3][COLUMN_UNDERSCORE]= {4, &Semantic_actions::add_character};
    matrizAS[3][COLUMN_DOT]={5, &Semantic_actions::add_character};
    //ENTREGAR CONSTANTE SIMPLE
    matrizAS[3][COLUMN_COLUMN_DIFFERENT]= {FINAL_STATE, &Semantic_actions::finish_constant};
    matrizAS[3][COLUMN_UPPERCASE]= {FINAL_STATE, &Semantic_actions::finish_constant};
    matrizAS[3][COLUMN_LOWERCASE]= {FINAL_STATE, &Semantic_actions::finish_constant};
    matrizAS[3][COLUMN_LOWERCASE_F]= {FINAL_STATE, &Semantic_actions::finish_constant};
    matrizAS[3][COLUMN_LOWERCASE_L]= {FINAL_STATE, &Semantic_actions::finish_constant};
    matrizAS[3][OTHER]= {FINAL_STATE, &Semantic_actions::finish_constant};
    matrizAS[3][COLUMN_PERCENTAGE]= {FINAL_STATE, &Semantic_actions::finish_constant};
    matrizAS[3][COLUMN_SUBTRACTION]= {FINAL_STATE, &Semantic_actions::finish_constant};
    matrizAS[3][COLUMN_DIVISION]= {FINAL_STATE, &Semantic_actions::finish_constant};
    matrizAS[3][COLUMN_MULTIPLICATION]= {FINAL_STATE, &Semantic_actions::finish_constant};
    matrizAS[3][COLUMN_GREATER]= {FINAL_STATE, &Semantic_actions::finish_constant};
    matrizAS[3][COLUMN_EQUAL]= {FINAL_STATE, &Semantic_actions::finish_constant};
    matrizAS[3][COLUMN_LESS]= {FINAL_STATE, &Semantic_actions::finish_constant};
    matrizAS[3][COLUMN_QUOTE]= {FINAL_STATE, &Semantic_actions::finish_constant};
    matrizAS[3][COLUMN_LITERALS]= {FINAL_STATE, &Semantic_actions::finish_constant};
    matrizAS[3][COLUMN_BL_TAB_NL]= {FINAL_STATE, &Semantic_actions::finish_constant};
    matrizAS[3][COLUMN_END_FILE]= {FINAL_STATE, &Semantic_actions::finish_constant};
    matrizAS[3][COLUMN_SUM]= {FINAL_STATE, &Semantic_actions::finish_constant};
//CAMINO 4
    //ENTREGAR ENTERO LARGO
    matrizAS[4][COLUMN_LOWERCASE_L] = {FINAL_STATE, &Semantic_actions::finish_longint};
    //INFORMAR ERROR
    matrizAS[4][COLUMN_COLUMN_DIFFERENT]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[4][COLUMN_DIGIT]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[4][COLUMN_UNDERSCORE]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[4][COLUMN_DOT]={FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[4][COLUMN_UPPERCASE]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[4][COLUMN_LOWERCASE]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[4][COLUMN_LOWERCASE_F]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[4][OTHER]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[4][COLUMN_PERCENTAGE]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[4][COLUMN_SUBTRACTION]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[4][COLUMN_DIVISION]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[4][COLUMN_MULTIPLICATION]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[4][COLUMN_GREATER]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[4][COLUMN_EQUAL]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[4][COLUMN_LESS]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[4][COLUMN_QUOTE]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[4][COLUMN_LITERALS]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[4][COLUMN_BL_TAB_NL]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[4][COLUMN_END_FILE]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[4][COLUMN_SUM]= {FINAL_STATE, &Semantic_actions::error_mensagge};

//CAMINO 5
    //AGREGAR
    matrizAS[5][COLUMN_DIGIT]= {5, &Semantic_actions::add_character};
    matrizAS[5][COLUMN_LOWERCASE_F] = {6, &Semantic_actions::add_character};
    //INFORMAR ERROR
    matrizAS[5][COLUMN_LOWERCASE_L] = {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[5][COLUMN_COLUMN_DIFFERENT]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[5][COLUMN_UNDERSCORE]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[5][COLUMN_DOT]={FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[5][COLUMN_UPPERCASE]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[5][COLUMN_LOWERCASE]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[5][OTHER]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[5][COLUMN_PERCENTAGE]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[5][COLUMN_SUBTRACTION]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[5][COLUMN_DIVISION]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[5][COLUMN_MULTIPLICATION]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[5][COLUMN_GREATER]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[5][COLUMN_EQUAL]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[5][COLUMN_LESS]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[5][COLUMN_QUOTE]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[5][COLUMN_LITERALS]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[5][COLUMN_BL_TAB_NL]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[5][COLUMN_END_FILE]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[5][COLUMN_SUM]= {FINAL_STATE, &Semantic_actions::finish_float};
//CAMINO 6
    //AGREGAR
    matrizAS[6][COLUMN_SUBTRACTION]= {7, &Semantic_actions::add_character};
    matrizAS[6][COLUMN_SUM] = {7, &Semantic_actions::add_character};
    //INFORMAR ERROR
    matrizAS[6][COLUMN_DIGIT]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[6][COLUMN_LOWERCASE_F] = {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[6][COLUMN_LOWERCASE_L] = {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[6][COLUMN_COLUMN_DIFFERENT]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[6][COLUMN_UNDERSCORE]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[6][COLUMN_DOT]={FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[6][COLUMN_UPPERCASE]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[6][COLUMN_LOWERCASE]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[6][OTHER]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[6][COLUMN_PERCENTAGE]= {FINAL_STATE, &Semantic_actions::error_mensagge};

    matrizAS[6][COLUMN_DIVISION]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[6][COLUMN_MULTIPLICATION]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[6][COLUMN_GREATER]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[6][COLUMN_EQUAL]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[6][COLUMN_LESS]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[6][COLUMN_QUOTE]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[6][COLUMN_LITERALS]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[6][COLUMN_BL_TAB_NL]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[6][COLUMN_END_FILE]= {FINAL_STATE, &Semantic_actions::error_mensagge};
//CAMINO 7
    //AGREGAR
    matrizAS[7][COLUMN_DIGIT]= {7, &Semantic_actions::add_character};
    //DEVOLVER FLOAT
    matrizAS[7][COLUMN_SUM] = {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[7][COLUMN_SUBTRACTION]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[7][COLUMN_LOWERCASE_F] = {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[7][COLUMN_LOWERCASE_L] = {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[7][COLUMN_COLUMN_DIFFERENT]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[7][COLUMN_UNDERSCORE]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[7][COLUMN_DOT]={FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[7][COLUMN_UPPERCASE]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[7][COLUMN_LOWERCASE]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[7][OTHER]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[7][COLUMN_PERCENTAGE]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[7][COLUMN_SUBTRACTION]= {FINAL_STATE, &Semantic_actions::finish_longint};
    matrizAS[7][COLUMN_DIVISION]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[7][COLUMN_MULTIPLICATION]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[7][COLUMN_GREATER]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[7][COLUMN_EQUAL]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[7][COLUMN_LESS]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[7][COLUMN_QUOTE]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[7][COLUMN_LITERALS]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[7][COLUMN_BL_TAB_NL]= {FINAL_STATE, &Semantic_actions::finish_float};
    matrizAS[7][COLUMN_END_FILE]= {FINAL_STATE, &Semantic_actions::finish_float};
//CAMINO 8
    //AGREGAR
    matrizAS[0][COLUMN_LESS]= {8, &Semantic_actions::add_character};
    //DEVOLVER MENOR IGUAL
    matrizAS[8][COLUMN_EQUAL]= {FINAL_STATE, &Semantic_actions::finish_composite_comparator};
    //DEVOLVER MENOR
    matrizAS[8][COLUMN_DIGIT]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[8][COLUMN_SUM] = {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[8][COLUMN_SUBTRACTION]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[8][COLUMN_LOWERCASE_F] = {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[8][COLUMN_LOWERCASE_L] = {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[8][COLUMN_COLUMN_DIFFERENT]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[8][COLUMN_UNDERSCORE]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[8][COLUMN_DOT]={FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[8][COLUMN_UPPERCASE]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[8][COLUMN_LOWERCASE]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[8][OTHER]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[8][COLUMN_PERCENTAGE]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[8][COLUMN_DIVISION]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[8][COLUMN_MULTIPLICATION]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[8][COLUMN_GREATER]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[8][COLUMN_QUOTE]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[8][COLUMN_LITERALS]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[8][COLUMN_BL_TAB_NL]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[8][COLUMN_END_FILE]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
//CAMINO 9
    //AGREGAR
    matrizAS[0][COLUMN_GREATER]= {9, &Semantic_actions::add_character};
    //DEVOLVER MAYOR IGUAL
    matrizAS[9][COLUMN_EQUAL]= {FINAL_STATE, &Semantic_actions::finish_composite_comparator};
    //DEVOLVER MENOR
    matrizAS[9][COLUMN_DIGIT]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[9][COLUMN_SUM] = {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[9][COLUMN_SUBTRACTION]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[9][COLUMN_LOWERCASE_F] = {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[9][COLUMN_LOWERCASE_L] = {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[9][COLUMN_COLUMN_DIFFERENT]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[9][COLUMN_UNDERSCORE]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[9][COLUMN_DOT]={FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[9][COLUMN_UPPERCASE]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[9][COLUMN_LOWERCASE]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[9][OTHER]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[9][COLUMN_PERCENTAGE]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[9][COLUMN_DIVISION]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[9][COLUMN_MULTIPLICATION]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[9][COLUMN_LESS]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[9][COLUMN_QUOTE]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[9][COLUMN_LITERALS]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[9][COLUMN_BL_TAB_NL]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[9][COLUMN_END_FILE]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
//CAMINO 10
    //AGREGAR
    matrizAS[0][COLUMN_EQUAL]= {10, &Semantic_actions::add_character};
    //DEVOLVER IGUAL
    matrizAS[10][COLUMN_EQUAL]= {FINAL_STATE, &Semantic_actions::finish_composite_comparator};
    //DEVOLVER ASIGNACION
    matrizAS[10][COLUMN_DIGIT]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[10][COLUMN_SUM] = {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[10][COLUMN_SUBTRACTION]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[10][COLUMN_LOWERCASE_F] = {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[10][COLUMN_LOWERCASE_L] = {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[10][COLUMN_COLUMN_DIFFERENT]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[10][COLUMN_UNDERSCORE]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[10][COLUMN_DOT]={FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[10][COLUMN_UPPERCASE]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[10][COLUMN_LOWERCASE]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[10][OTHER]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[10][COLUMN_PERCENTAGE]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[10][COLUMN_DIVISION]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[10][COLUMN_MULTIPLICATION]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[10][COLUMN_LESS]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[10][COLUMN_GREATER]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[10][COLUMN_QUOTE]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[10][COLUMN_LITERALS]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[10][COLUMN_BL_TAB_NL]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
    matrizAS[10][COLUMN_END_FILE]= {FINAL_STATE, &Semantic_actions::finish_simple_comparator};
//CAMINO 11
    //AGREGAR
    matrizAS[0][COLUMN_COLUMN_DIFFERENT]= {11, &Semantic_actions::add_character};
    //DEVOLVER DISTINTO
    matrizAS[11][COLUMN_EQUAL]= {FINAL_STATE, &Semantic_actions::finish_composite_comparator};
    //INFORMAR ERROR
    matrizAS[11][COLUMN_DIGIT]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[11][COLUMN_LOWERCASE_F] = {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[11][COLUMN_LOWERCASE_L] = {FINAL_STATE, &Semantic_actions::error_mensagge};
    //matrizAS[11][COLUMN_EQUAL]= {FINAL_STATE, &Semantic_actions::error_mensagge}; estaba repetido xd, 20 min buscando por que se me rompia el !=
    matrizAS[11][COLUMN_UNDERSCORE]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[11][COLUMN_DOT]={FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[11][COLUMN_UPPERCASE]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[11][COLUMN_LOWERCASE]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[11][OTHER]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[11][COLUMN_PERCENTAGE]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[11][COLUMN_SUBTRACTION]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[11][COLUMN_DIVISION]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[11][COLUMN_LESS]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[11][COLUMN_GREATER]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[11][COLUMN_QUOTE]= {FINAL_STATE, &Semantic_actions::error_mensagge};
    matrizAS[11][COLUMN_BL_TAB_NL]= {FINAL_STATE, &Semantic_actions::error_mensagge};
//CAMINO 12
    //AGREGAR

    matrizAS[0][COLUMN_QUOTE]= {12, &Semantic_actions::add_character};
    matrizAS[12][COLUMN_COLUMN_DIFFERENT]= {11, &Semantic_actions::add_character};
    matrizAS[12][COLUMN_EQUAL]= {12, &Semantic_actions::add_character};
    matrizAS[12][COLUMN_SUM] = {12, &Semantic_actions::add_character};
    matrizAS[12][COLUMN_SUBTRACTION]= {12, &Semantic_actions::add_character};
    matrizAS[12][COLUMN_MULTIPLICATION]= {12, &Semantic_actions::add_character};
    matrizAS[12][COLUMN_LITERALS]= {12, &Semantic_actions::add_character};
    matrizAS[12][COLUMN_END_FILE]={0, &Semantic_actions::eof_unexpected};  // ACÁ PASABA ALGO?
    matrizAS[12][COLUMN_DIGIT]= {12, &Semantic_actions::add_character};
    matrizAS[12][COLUMN_LOWERCASE_F] = {12, &Semantic_actions::add_character};
    matrizAS[12][COLUMN_LOWERCASE_L] = {12, &Semantic_actions::add_character};
    matrizAS[12][COLUMN_EQUAL]= {12, &Semantic_actions::add_character};
    matrizAS[12][COLUMN_UNDERSCORE]= {12, &Semantic_actions::add_character};
    matrizAS[12][COLUMN_DOT]={12, &Semantic_actions::add_character};
    matrizAS[12][COLUMN_UPPERCASE]= {12, &Semantic_actions::add_character};
    matrizAS[12][COLUMN_LOWERCASE]= {12, &Semantic_actions::add_character};
    matrizAS[12][OTHER]= {12, &Semantic_actions::add_character};
    matrizAS[12][COLUMN_PERCENTAGE]= {12, &Semantic_actions::add_character};
    matrizAS[12][COLUMN_DIVISION]= {12, &Semantic_actions::add_character};
    matrizAS[12][COLUMN_LESS]= {12, &Semantic_actions::add_character};
    matrizAS[12][COLUMN_GREATER]= {12, &Semantic_actions::add_character};
    matrizAS[12][COLUMN_BL_TAB_NL]= {12, &Semantic_actions::add_character};
    //DEVOLVER word
    matrizAS[12][COLUMN_QUOTE]= {FINAL_STATE, &Semantic_actions::finish_symbol};
//CAMINO 13
    //AGREGAR
    matrizAS[0][COLUMN_DIVISION]= {13, &Semantic_actions::add_character};
    //DEVOLVER DIVISION

    matrizAS[13][COLUMN_COLUMN_DIFFERENT]= {FINAL_STATE, &Semantic_actions::finalizarDivision};
    matrizAS[13][COLUMN_EQUAL]= {FINAL_STATE, &Semantic_actions::finalizarDivision};
    matrizAS[13][COLUMN_SUM] = {FINAL_STATE, &Semantic_actions::finalizarDivision};
    matrizAS[13][COLUMN_SUBTRACTION]= {FINAL_STATE, &Semantic_actions::finalizarDivision};
    matrizAS[13][COLUMN_MULTIPLICATION]= {FINAL_STATE, &Semantic_actions::finalizarDivision};
    matrizAS[13][COLUMN_LITERALS]= {FINAL_STATE, &Semantic_actions::finalizarDivision};
    matrizAS[13][COLUMN_END_FILE]={FINAL_STATE, &Semantic_actions::finalizarDivision};
    matrizAS[13][COLUMN_DIGIT]= {FINAL_STATE, &Semantic_actions::finalizarDivision};
    matrizAS[13][COLUMN_LOWERCASE_F] = {FINAL_STATE, &Semantic_actions::finalizarDivision};
    matrizAS[13][COLUMN_LOWERCASE_L] = {FINAL_STATE, &Semantic_actions::finalizarDivision};
    matrizAS[13][COLUMN_UNDERSCORE]= {FINAL_STATE, &Semantic_actions::finalizarDivision};
    matrizAS[13][COLUMN_DOT]={FINAL_STATE, &Semantic_actions::finalizarDivision};
    matrizAS[13][COLUMN_UPPERCASE]= {FINAL_STATE, &Semantic_actions::finalizarDivision};
    matrizAS[13][COLUMN_LOWERCASE]= {FINAL_STATE, &Semantic_actions::finalizarDivision};
    matrizAS[13][OTHER]= {FINAL_STATE, &Semantic_actions::finalizarDivision};
    matrizAS[13][COLUMN_QUOTE]= {FINAL_STATE, &Semantic_actions::finalizarDivision};
    matrizAS[13][COLUMN_LESS]= {FINAL_STATE, &Semantic_actions::finalizarDivision};
    matrizAS[13][COLUMN_GREATER]= {FINAL_STATE, &Semantic_actions::finalizarDivision};
    matrizAS[13][COLUMN_BL_TAB_NL]= {FINAL_STATE, &Semantic_actions::finalizarDivision};
    //INICIO DE COMENTARIO
    matrizAS[13][COLUMN_PERCENTAGE]= {14, &Semantic_actions::discard_character};
//CAMINO 14
    //AGREGAR
    matrizAS[14][COLUMN_DIVISION]= {14, &Semantic_actions::discard_character};
    matrizAS[14][COLUMN_COLUMN_DIFFERENT]= {14, &Semantic_actions::discard_character};
    matrizAS[14][COLUMN_EQUAL]= {14, &Semantic_actions::discard_character};
    matrizAS[14][COLUMN_SUM] = {14, &Semantic_actions::discard_character};
    matrizAS[14][COLUMN_SUBTRACTION]= {14, &Semantic_actions::discard_character};
    matrizAS[14][COLUMN_MULTIPLICATION]= {14, &Semantic_actions::discard_character};
    matrizAS[14][COLUMN_LITERALS]= {14, &Semantic_actions::discard_character};
    matrizAS[14][COLUMN_DIGIT]= {14, &Semantic_actions::discard_character};
    matrizAS[14][COLUMN_LOWERCASE_F] = {14, &Semantic_actions::discard_character};
    matrizAS[14][COLUMN_LOWERCASE_L] = {14, &Semantic_actions::discard_character};
    matrizAS[14][COLUMN_UNDERSCORE]= {14, &Semantic_actions::discard_character};
    matrizAS[14][COLUMN_DOT]={14, &Semantic_actions::discard_character};
    matrizAS[14][COLUMN_UPPERCASE]= {14, &Semantic_actions::discard_character};
    matrizAS[14][COLUMN_LOWERCASE]= {14, &Semantic_actions::discard_character};
    matrizAS[14][OTHER]= {14, &Semantic_actions::discard_character};
    matrizAS[14][COLUMN_QUOTE]= {14, &Semantic_actions::discard_character};
    matrizAS[14][COLUMN_LESS]= {14, &Semantic_actions::discard_character};
    matrizAS[14][COLUMN_GREATER]= {14, &Semantic_actions::discard_character};
    matrizAS[14][COLUMN_BL_TAB_NL]= {14, &Semantic_actions::discard_character};
    //POSIBLE FIN DE COMENTARIO
    matrizAS[14][COLUMN_PERCENTAGE]= {15, &Semantic_actions::discard_character};
    //FIN DE ARCHIVO EN MEDIO DEL COMENTARIO
    matrizAS[14][COLUMN_END_FILE]={0, &Semantic_actions::eof_unexpected};
//CAMINO 15
    //AGREGAR (VUELVO A ESTADO 14 PORQUE NO SE CERRO EL COMENTARIO)
    matrizAS[15][COLUMN_COLUMN_DIFFERENT]= {14, &Semantic_actions::discard_character};
    matrizAS[15][COLUMN_EQUAL]= {14, &Semantic_actions::discard_character};
    matrizAS[15][COLUMN_SUM] = {14, &Semantic_actions::discard_character};
    matrizAS[15][COLUMN_SUBTRACTION]= {14, &Semantic_actions::discard_character};
    matrizAS[15][COLUMN_MULTIPLICATION]= {14, &Semantic_actions::discard_character};
    matrizAS[15][COLUMN_LITERALS]= {14, &Semantic_actions::discard_character};
    matrizAS[15][COLUMN_DIGIT]= {14, &Semantic_actions::discard_character};
    matrizAS[15][COLUMN_LOWERCASE_F] = {14, &Semantic_actions::discard_character};
    matrizAS[15][COLUMN_LOWERCASE_L] = {14, &Semantic_actions::discard_character};
    matrizAS[15][COLUMN_UNDERSCORE]= {14, &Semantic_actions::discard_character};
    matrizAS[15][COLUMN_DOT]={14, &Semantic_actions::discard_character};
    matrizAS[15][COLUMN_UPPERCASE]= {14, &Semantic_actions::discard_character};
    matrizAS[15][COLUMN_LOWERCASE]= {14, &Semantic_actions::discard_character};

    matrizAS[15][OTHER]= {14, &Semantic_actions::discard_character};
    matrizAS[15][COLUMN_QUOTE]= {14, &Semantic_actions::discard_character};
    matrizAS[15][COLUMN_LESS]= {14, &Semantic_actions::discard_character};
    matrizAS[15][COLUMN_GREATER]= {14, &Semantic_actions::discard_character};
    matrizAS[15][COLUMN_BL_TAB_NL]= {14, &Semantic_actions::discard_character};
    //POSIBLE FIN DE COMENTARIO
    matrizAS[15][COLUMN_PERCENTAGE]= {15, &Semantic_actions::discard_character};
    //FIN COMENTARIO (descartar)
    matrizAS[15][COLUMN_DIVISION]= {0, &Semantic_actions::discard_character};
    //FIN DE ARCHIVO EN MEDIO DEL COMENTARIO
    matrizAS[15][COLUMN_END_FILE]={0, &Semantic_actions::eof_unexpected};


}