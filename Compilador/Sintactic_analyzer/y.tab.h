#define ID 257
#define FLOAT 258
#define LONGINT 259
#define INT 260
#define STRING 261
#define IF 262
#define ELSE 263
#define END_IF 264
#define OUT 265
#define GREATER_OR_EQUAL 266
#define LESS_OR_EQUAL 267
#define EQUAL 268
#define DIFFERENT 269
#define WHILE 270
#define LOOP 271
#define PROC 272
#define TRUE 273
#define FALSE 274
#define SHADOWING 275
#define NA 276
#define ERROR 277
typedef union {
    int entero;
    char * cadena;
    } YYSTYPE;
extern YYSTYPE yylval;
