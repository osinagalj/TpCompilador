#ifndef COMPILADOR_LEXICAL_ANALYZER_HEADER_H
#define COMPILADOR_LEXICAL_ANALYZER_HEADER_H

#include <iostream>
#include <fstream>
#include "Semantic_actions.h"
#include <map>
#include <string>
#include "../SymbolTable/Symbol_table.h"

using namespace std;

#define COLUMN_LOWERCASE 0
#define COLUMN_UPPERCASE 1
#define COLUMN_LOWERCASE_L 2
#define COLUMN_LOWERCASE_F 3
#define COLUMN_DIGIT 4
#define COLUMN_DOT 5                    //'.'
#define COLUMN_SUM 6
#define COLUMN_MULTIPLICATION 7
#define COLUMN_SUBTRACTION 8            //"-"
#define COLUMN_UNDERSCORE 9             //"_"
#define COLUMN_EQUAL 10
#define COLUMN_LESS 11
#define COLUMN_GREATER 12
#define COLUMN_COLUMN_DIFFERENT 13      //"!"
#define COLUMN_QUOTE 14                 //'"'
#define COLUMN_DIVISION 15
#define COLUMN_PERCENTAGE 16
#define COLUMN_END_FILE 17              //'$' for this case
#define COLUMN_LITERALS 18
#define COLUMN_BL_TAB_NL 19
#define OTHER 20
#define F -1

#define FINAL_STATE -1      //SACAR
const int  nro_estados = 17;
const int nro_simbolos = 21;

#define longIdentificador 21 //XQ NO ES 20?????????????????




#endif //COMPILADOR_LEXICAL_ANALYZER_HEADER_H
