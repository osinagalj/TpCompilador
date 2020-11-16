#include <iostream>
#include "Lexical_analyzer.h"
#include "../Sintactic_analyzer/y.tab.h"
using namespace std;

Lexical_analyzer::Lexical_analyzer()
{
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
                //cout<<"estado neuvo: " + to_string(new_state) +"  ";
                char actual_c =line[current_character];                             //getting next character
                new_state = identify_character(actual_c);                           //gettin column of character
                int SA = (*matrix_SA[actual_state][new_state])(this, actual_c);
                actual_state = states_matrix_SA[actual_state][new_state];           //update actual state
                if(SA == -1){                                                       //If I have to discard an invalid token or character, I go to state 0 to continue compiling
                    actual_state = 0;
                    token_found = false;
                }
            }
            if ((current_character < line.size()) && token_found){                  //  token found
                source_file.close(); //cerramos archivo
                return t;
            }else{                                                                  //break line and token not founded
                current_line++;
                current_character = 0;
            }
        }
        return t;
}

//Identeificadores, parametros y nombres de proc
void Lexical_analyzer::save_in_ST(int id)
{
    Symbol_table::Registry registry;
    registry.id = id;
    registry.tipoToken = "id";
    symbolTable->addSymbol(t.pointerST,registry);
}

//Para las constantes
void Lexical_analyzer::save_in_ST(int id,string tipo)
{
    Symbol_table::Registry registry;
    registry.id = id;
    registry.Tipo = tipo;
    registry.tipoToken = "constante";
    symbolTable->addSymbol(t.pointerST,registry);
}


int Lexical_analyzer::get_reserved_word()
{
    auto search = reserved_words.find(word);
    if (search != reserved_words.end()) {
        return search->second;
    }
    return -1;
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

int Lexical_analyzer::identify_character(char character){
//esta funcion te devuelve el numero de columna de la matriz de transicion de estado

    if(character=='l')
        return COLUMN_LOWERCASE_L;
    if(character=='f')
        return COLUMN_LOWERCASE_F;
    if (character<='z' && character>='a')   // LOWERCASE
        return COLUMN_LOWERCASE;
    if (character<='Z' && character>='A')   //UPPERCASE
        return COLUMN_UPPERCASE;
    if (character>='0' && character<='9')   // DIGIT
        return COLUMN_DIGIT;

    switch(character)
    {
        case '.':
            return COLUMN_DOT;
        case '+':
            return COLUMN_SUM;
        case '*':
            return COLUMN_MULTIPLICATION;
        case '-':
            return COLUMN_SUBTRACTION;
        case '_':
            return COLUMN_UNDERSCORE;
        case '=':
            return COLUMN_EQUAL;
        case '<':
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
        case ' ':                   //blank space;
            return COLUMN_BL_TAB_NL;
        case '\n':                  //line break;
            return COLUMN_BL_TAB_NL;
        default:
            return OTHER;           //symbol not recognized by the lexical analyzer
    }
}
