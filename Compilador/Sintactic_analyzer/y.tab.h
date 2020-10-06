#define ID 257
#define CTE 258
#define FLOAT 259
#define LONGINT 260
#define INT 261
#define STRING 262
#define IF 263
#define ELSE 264
#define END_IF 265
#define OUT 266
#define GREATER_OR_EQUAL 267
#define LESS_OR_EQUAL 268
#define EQUAL 269
#define DIFFERENT 270
#define WHILE 271
#define LOOP 272
#define PROC 273
#define TRUE 274
#define FALSE 275
#define SHADOWING 276
#define NA 277
#define ERROR 278
typedef union {
    int entero;
    char * cadena;
    } YYSTYPE;
extern YYSTYPE yylval;
