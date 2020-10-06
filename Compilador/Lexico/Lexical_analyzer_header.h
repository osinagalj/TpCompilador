#ifndef COMPILADOR_LEXICAL_ANALYZER_HEADER_H
#define COMPILADOR_LEXICAL_ANALYZER_HEADER_H

#include <iostream>
#include <fstream>
#include "AccionesSemanticas.h"
#include <map>
#include <string>
#include "../SymbolTable/SymbolTable.h"
#include "../Sintactico/y.tab.h"
using namespace std;

#define COLUMN_LOWERCASE 0
#define COLUMN_UPPERCASE 1
#define COLUMN_LOWERCASE_L 2
#define COLUMN_LOWERCASE_F 3
#define COLUMN_DIGIT 4
#define COLUMN_DOT 5                    //'.'
#define COLUMN_MULTIPLICATION 6
#define COLUMN_SUBTRACTION 7            //"-"
#define COLUMN_UNDERSCORE 8             //"_"
#define COLUMN_EQUAL 9
#define COLUMN_LESS 10
#define COLUMN_GREATER 11
#define COLUMN_COLUMN_DIFFERENT 12      //"!"
#define COLUMN_QUOTE 13                 //'"'
#define COLUMN_DIVISION 14
#define COLUMN_PERCENTAGE 15
#define COLUMN_LITERALS 16
#define COLUMN_BL_TAB_NL 17
#define COLUMN_END_FILE 18              //'$' for this case
#define OTHER 19
#define COLUMN_SUM 20
#define FINAL_STATE -1
const int  nro_estados = 17;
const int nro_simbolos = 21;

#define longIdentificador 21 //XQ NO ES 20?????????????????




#endif //COMPILADOR_LEXICAL_ANALYZER_HEADER_H
