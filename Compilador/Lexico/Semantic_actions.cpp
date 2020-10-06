#include "Semantic_actions.h"
#include "../Salida/Logger.h"

void Semantic_actions::initialize_token(Lexical_analyzer* lexical_analyzer, char& c){
    lexical_analyzer->word = c;
    lexical_analyzer->increase_character();
}

void Semantic_actions::add_character(Lexical_analyzer* lexical_analyzer, char& c){
    lexical_analyzer->word = lexical_analyzer->word + c;
    lexical_analyzer->increase_character();
}

void Semantic_actions::finish_identifier(Lexical_analyzer* lexical_analyzer, char& c){

    lexical_analyzer->set_token_found();
    //Chekear el rango
    if(lexical_analyzer->word.length() > longIdentificador){
        lexical_analyzer->word =  lexical_analyzer->word.substr (0,20);
        lexical_analyzer->save_token(ID, lexical_analyzer->word);
        lexical_analyzer->save_in_ST(ID);
        //"Identificador supera la longitud maxima de 20 caracteres"
    }else{
        lexical_analyzer->save_token(ID, lexical_analyzer->word);
        lexical_analyzer->save_in_ST(ID);
    }
}

void Semantic_actions::finish_reserved_word(Lexical_analyzer* lexical_analyzer, char& c)
{
    lexical_analyzer->set_token_found();
    int id = lexical_analyzer->getIdPalabraReservada();
    lexical_analyzer->save_token(id, lexical_analyzer->word);
}

void Semantic_actions::finish_constant(Lexical_analyzer* lexical_analyzer, char& c)
{
    lexical_analyzer->set_token_found();
    lexical_analyzer->save_token(CTE, lexical_analyzer->word);
    lexical_analyzer->save_in_ST(CTE);

}

void Semantic_actions::finish_longint(Lexical_analyzer* lexical_analyzer, char& c)
{
    //.5    6.3f-3
    //Valor maximo de un entero largo 2147483647
    lexical_analyzer->set_token_found();
    lexical_analyzer->increase_character();
    lexical_analyzer->word= lexical_analyzer->word + c;
    lexical_analyzer->word = lexical_analyzer->word.substr (0,lexical_analyzer->word.size()-2);
    long numero = stol(lexical_analyzer->word);
    if(numero <= 2147483648 ){
        lexical_analyzer->save_token(LONGINT, lexical_analyzer->word);

    }else{
        lexical_analyzer->word = to_string(2147483648); //siempre que sea positivo el numero, el sintactico lo chekea
        lexical_analyzer->save_token(LONGINT, lexical_analyzer->word);

    }
    lexical_analyzer->save_in_ST(LONGINT);
}

void Semantic_actions::finish_float(Lexical_analyzer* lexical_analyzer, char& c)
{
    string acumulado="";
    float numero=0;
    int desplazamiento = 0;
    int i = 0;
    if(lexical_analyzer->word[0] == '.'){
        string aux= "0" + lexical_analyzer->word;
        acumulado=aux;
    }
    while (i < lexical_analyzer->word.size()){
        if(lexical_analyzer->word[i]=='f'){ //si hay desplazamiento
            if(lexical_analyzer->word[i+1]=='+'){
                desplazamiento= stoi(lexical_analyzer->word.substr(i+2,lexical_analyzer->word.size()));
                //cout<<desplazamiento<<endl;
                numero=stof(acumulado);
                for(int i=0; i< desplazamiento; i++){
                    numero= numero * 10;
                }
                i = lexical_analyzer->word.size();
            }else{
                desplazamiento=stoi(lexical_analyzer->word.substr(i+2,lexical_analyzer->word.size()));
                numero=stof(acumulado);
                for(int i=0; i< desplazamiento; i++){
                    numero= numero / 10;
                }
                i = lexical_analyzer->word.size();
            }
        }else {
            acumulado = acumulado + lexical_analyzer->word[i];
            numero = stof(acumulado);
            i++;
        }
    }
    lexical_analyzer->save_token(FLOAT, to_string(numero)); //CAMBIAR A ID DE FLOAT DESP
    lexical_analyzer->save_in_ST(FLOAT);
    lexical_analyzer->set_token_found();
}

//Blancos,TAB, Salto de linea
void Semantic_actions::discard_character(Lexical_analyzer *lexical_analyzer, char &c)
{
    lexical_analyzer->increase_character();
    lexical_analyzer->word="";
}

//$ en medio de un comentario o word de caracter
void Semantic_actions::eof_unexpected(Lexical_analyzer* lexical_analyzer, char& c)
{
    Logger::write("Se encontró fin de archivo adentro de un comentario o cadena de caracteres");
}

void Semantic_actions::error_mensagge(Lexical_analyzer* lexical_analyzer, char& c)
{
    lexical_analyzer->increase_character();
    Logger::write("Error lexico, no se ha podido reconocer " + lexical_analyzer->word +to_string(c));
}

// Comparators: <=,>=,==,!=
void Semantic_actions::finish_composite_comparator(Lexical_analyzer* lexical_analyzer, char& c)
{
    lexical_analyzer->increase_character();
    lexical_analyzer->set_token_found();
    lexical_analyzer->word = lexical_analyzer->word + c;
    switch(lexical_analyzer->word[0]){  //El primer caracter es siempre un = en un comparador compuesto
        case '<':
            lexical_analyzer->save_token(GREATER_OR_EQUAL, lexical_analyzer->word); //MAYORIGUAL
            break;
        case '>':
            lexical_analyzer->save_token(LESS_OR_EQUAL, lexical_analyzer->word); //MENORIGUAL
            break;
        case '=': // ==
            lexical_analyzer->save_token(EQUAL, lexical_analyzer->word); //IGUAL
            break;
        case '!':
            lexical_analyzer->save_token(DIFFERENT, lexical_analyzer->word); //DISTINTO
            break;
        }
}

//No aumentamos token porque estamos parados en el siguiente
void Semantic_actions::finish_simple_comparator(Lexical_analyzer* lexical_analyzer, char& c)
{
    lexical_analyzer->set_token_found();
    switch(lexical_analyzer->word[0]){
        case '<':
            lexical_analyzer->save_token(toascii('<'), "");
            break;
        case '>':
            lexical_analyzer->save_token(toascii('>'), "");
            break;
        case '=':

            lexical_analyzer->save_token(toascii('='), "");
            break;
        }
}

void Semantic_actions::finish_symbol(Lexical_analyzer * lexical_analyzer, char & c)
{
    lexical_analyzer->increase_character();
    lexical_analyzer->set_token_found();
    lexical_analyzer->word = lexical_analyzer->word + c;
    switch(c)
    {
        case '/':
            lexical_analyzer->save_token(toascii('/'), to_string(c));
            break;
        case '-':
            lexical_analyzer->save_token(toascii('-'), lexical_analyzer->word);
            break;
        case '+':
            lexical_analyzer->save_token(toascii('+'), lexical_analyzer->word);
            break;
        case '*':
            lexical_analyzer->save_token(toascii('*'), lexical_analyzer->word);
            break;
        case '(':
            lexical_analyzer->save_token(toascii('('), lexical_analyzer->word);
            break;
        case ')':
            lexical_analyzer->save_token(toascii(')'), lexical_analyzer->word);
            break;
        case ',':
            lexical_analyzer->save_token(toascii(','), lexical_analyzer->word);
            break;
        case '}':
            lexical_analyzer->save_token(toascii('}'), lexical_analyzer->word);
            break;
        case ';':
            lexical_analyzer->save_token(toascii(';'), lexical_analyzer->word);
            break;
        case '{':
            lexical_analyzer->save_token(toascii('{'), lexical_analyzer->word);
            break;
        case '.':
            lexical_analyzer->save_token(toascii('.'), lexical_analyzer->word);
            break;
        case '"':
            lexical_analyzer->save_token(STRING, lexical_analyzer->word);
            lexical_analyzer->save_in_ST(STRING);
            break;
        case '$':
            lexical_analyzer->save_token(0, lexical_analyzer->word); // yyparse() end with yylex() = 0
            lexical_analyzer->end = true;
            break;
    }
}