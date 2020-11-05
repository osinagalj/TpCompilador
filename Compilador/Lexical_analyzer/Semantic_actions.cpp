#include "Semantic_actions.h"
#include "../Output/Logger.h"
#include "../Sintactic_analyzer/y.tab.h"

int Semantic_actions::initialize_token(Lexical_analyzer* lexical_analyzer, char& c)
{
    lexical_analyzer->word = c;
    lexical_analyzer->increase_character();
    return 0;
}

int Semantic_actions::add_character(Lexical_analyzer* lexical_analyzer, char& c)
{
    lexical_analyzer->word = lexical_analyzer->word + c;
    lexical_analyzer->increase_character();
    return 0;
}

int Semantic_actions::finish_identifier(Lexical_analyzer* lexical_analyzer, char& c)
{
    lexical_analyzer->set_token_found();
    //Chekear el rango
    if(lexical_analyzer->word.length() > longIdentificador){
        Logger::write("Warning: SE TRUNCO EL IDENTIFICADOR DEBIDO A QUE SUPERA LOS 20 CARACTERES");
        lexical_analyzer->word =  lexical_analyzer->word.substr (0,20);
        lexical_analyzer->save_token(ID, lexical_analyzer->word);
       // lexical_analyzer->save_in_ST2(ID);//comentar
        //"Identificador supera la longitud maxima de 20 caracteres"
    }else{
        lexical_analyzer->save_token(ID, lexical_analyzer->word);
       // lexical_analyzer->save_in_ST2(ID); //comentar
    }
    return 0;
}

int Semantic_actions::finish_reserved_word(Lexical_analyzer* lexical_analyzer, char& c)
{
    lexical_analyzer->set_token_found();
    int id = lexical_analyzer->get_reserved_word();
    if(id == -1){
        Logger::write("Error Lexico: Palabra reservada mal escrita.");
        return -1;
    }
    lexical_analyzer->save_token(id, lexical_analyzer->word);
   return 0;
}

int Semantic_actions::finish_constant(Lexical_analyzer* lexical_analyzer, char& c)
{
    Logger::write("Error: No se permiten las constantes de tipo entero. Las cosntantes pueden ser solo del tipo LOINGT y FLOAT");
    lexical_analyzer->set_token_found();
    lexical_analyzer->save_token(LONGINT, lexical_analyzer->word);
    lexical_analyzer->save_in_ST(LONGINT,"Longint");
    return 0;
}

//.5    6.3f-3
//Valor maximo de un entero largo 2147483647
int Semantic_actions::finish_longint(Lexical_analyzer* lexical_analyzer, char& c)
{
    lexical_analyzer->set_token_found();
    lexical_analyzer->increase_character();
    lexical_analyzer->word= lexical_analyzer->word + c;
    lexical_analyzer->word = lexical_analyzer->word.substr (0,lexical_analyzer->word.size()-2);
    double number = stod(lexical_analyzer->word);
    if(number <= 2147483648 ){
        lexical_analyzer->save_token(LONGINT, lexical_analyzer->word);

    }else{
        lexical_analyzer->word = to_string(2147483648); //siempre que sea positivo el numero, el sintactico lo chekea
        lexical_analyzer->save_token(LONGINT, lexical_analyzer->word);

    }
    lexical_analyzer->save_in_ST(LONGINT,"Longint");

    return 0;
}

int Semantic_actions::finish_float(Lexical_analyzer* lexical_analyzer, char& c)
{
    string acumulado="";
    float number=0;
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
                number=stof(acumulado);
                for(int i=0; i< desplazamiento; i++){
                    number= number * 10;
                }
                i = lexical_analyzer->word.size();
            }else{
                desplazamiento=stoi(lexical_analyzer->word.substr(i+2,lexical_analyzer->word.size()));
                number=stof(acumulado);
                for(int i=0; i< desplazamiento; i++){
                    number= number / 10;
                }
                i = lexical_analyzer->word.size();
            }
        }else {
            acumulado = acumulado + lexical_analyzer->word[i];
            number = stof(acumulado);
            i++;
        }
    }
    lexical_analyzer->save_token(FLOAT, to_string(number)); //CAMBIAR A ID DE FLOAT DESP
    lexical_analyzer->save_in_ST(FLOAT,"Float");
    lexical_analyzer->set_token_found();
    return 0;
}

//Blancos,TAB, Salto de linea
int Semantic_actions::discard_character(Lexical_analyzer *lexical_analyzer, char &c)
{
    lexical_analyzer->increase_character();
    lexical_analyzer->word="";
    return 0;
}

//$ en medio de un comentario o word de caracter
int Semantic_actions::eof_unexpected(Lexical_analyzer* lexical_analyzer, char& c)
{
    Logger::write("Se encontró fin de archivo adentro de un comentario o cadena de caracteres");
    return 0;
}

int Semantic_actions::error_mensagge(Lexical_analyzer* lexical_analyzer, char& c)
{
    lexical_analyzer->actual_state = 0;
    lexical_analyzer->increase_character();
    Logger::write("Error lexico, no se ha podido reconocer " + lexical_analyzer->word +to_string(c));
    return -1;
}

// Comparators: <=,>=,==,!=
int Semantic_actions::finish_composite_comparator(Lexical_analyzer* lexical_analyzer, char& c)
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
    return 0;
}

//No aumentamos token porque estamos parados en el siguiente
int Semantic_actions::finish_simple_comparator(Lexical_analyzer* lexical_analyzer, char& c)
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
    return 0;
}

int Semantic_actions::finish_division(Lexical_analyzer* lexical_analyzer, char& c)
{
        lexical_analyzer->set_token_found();
        lexical_analyzer->save_token(toascii('/'),lexical_analyzer->word);
    return 0;
}


int Semantic_actions::finish_symbol(Lexical_analyzer * lexical_analyzer, char & c)
{
    lexical_analyzer->increase_character();
    lexical_analyzer->set_token_found();
    lexical_analyzer->word = lexical_analyzer->word + c;
    switch(c)
    {
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
            lexical_analyzer->save_in_ST(STRING,"String");
            break;
        case '$':
            lexical_analyzer->save_token(0, lexical_analyzer->word); // yyparse() end with yylex() = 0
            lexical_analyzer->end = true;
            break;
    }
    return 0;
}