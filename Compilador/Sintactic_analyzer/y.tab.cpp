#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
#line 7 "Gramatica.y"
typedef union {
    int entero = 0;
    char * cadena;
    } YYSTYPE;
#line 11 "y.tab.c"
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
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    1,    1,    2,    2,    2,    3,    3,    3,    7,
    7,    4,    4,    4,    4,    4,   10,   13,   13,    8,
    8,    8,    8,    8,   15,   15,   14,   14,   12,   12,
   17,   17,   17,   17,   17,   18,   19,   11,   11,   11,
   16,   16,   16,   16,   16,   16,   16,   16,   16,   16,
   16,    9,    9,    9,   20,   20,   20,   21,   21,   21,
   21,   21,    6,    6,    6,    5,    5,    5,
};
short yylen[] = {                                         2,
    1,    1,    2,    1,    1,    1,    2,    2,    1,    3,
    2,    4,    3,    1,    2,    2,    5,    3,    1,   15,
   14,   11,   11,    8,    1,    1,    4,    2,    5,    5,
    2,    1,    4,    3,    3,    1,    1,    8,    7,    7,
    3,    2,    3,    2,    3,    2,    3,    3,    2,    3,
    2,    3,    3,    1,    1,    3,    3,    1,    1,    2,
    1,    2,    1,    1,    1,    5,    4,    4,
};
short yydefred[] = {                                      0,
    0,   65,   64,   63,    0,    0,    0,    0,    0,    0,
    0,    2,    4,    5,    6,    0,    9,    0,   14,    0,
    0,   11,    0,    0,    0,    0,    0,    0,    0,    0,
   58,   59,   61,    0,    0,    0,    0,    0,   55,    3,
    0,    7,    8,   15,   16,   10,   13,    0,   19,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   60,   62,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   12,    0,    0,    0,    0,   68,    0,    0,   28,
    0,    0,   67,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   56,   57,   18,   17,    0,    0,   29,
    0,   66,    0,    0,    0,    0,    0,    0,   30,    0,
    0,    0,   31,    0,    0,    0,    0,    0,   27,    0,
    0,   35,    0,    0,   40,    0,    0,    0,    0,   39,
   33,   38,   25,   26,    0,    0,   24,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   22,    0,   23,    0,
    0,    0,    0,    0,    0,   21,   20,
};
short yydgoto[] = {                                      10,
  110,   12,   13,   14,   15,   16,   17,   18,   36,   19,
   20,   21,   50,   57,  135,   37,  100,  101,  111,   38,
   39,
};
short yysindex[] = {                                     66,
  -23,    0,    0,    0,  -18,    1,   18,  -36,   76,    0,
   66,    0,    0,    0,    0, -248,    0,    6,    0,    7,
   10,    0, -248,  -44, -238,  -31,  -38,  -31,   20, -214,
    0,    0,    0,   37, -229,   91,   40,  -10,    0,    0,
  -32,    0,    0,    0,    0,    0,    0,  -19,    0,  -21,
   41,   42,   26,   43, -214, -195,  -13,   28,    0,    0,
  -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,  -40,  -31,
  -31,    0, -186,   31,  -24,   32,    0, -117,   -2,    0,
 -214, -196,    0,    4,    4,    4,    4,    4,    4,  -10,
  -10,  -34,  -15,    0,    0,    0,    0,   66,   66,    0,
 -209,    0,  -30,   66, -113, -165,   33,   66,    0,   66,
 -168,   66,    0,   66,   -6,   38,   44,   66,    0, -161,
    3,    0, -164,   12,    0, -217, -157,   21,   59,    0,
    0,    0,    0,    0,  -16,  -37,    0, -171,   66, -167,
   66,   49,   30,   50,   39, -217,    0, -217,    0,  -14,
   -8,   66,   66,   48,   57,    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  113,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   73,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   84,   86,    0,   88,   90,  102,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  107,  108,  109,  111,  119,  124,   79,
   99,    0,    0,    0,    0,    0,    0,    0,  -57,    0,
  110,    0,    0,    0,    0,    0,    0,    0,    0,  -54,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  112,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
  294,    2,    0,    0,    0,  -22,   -5,    0,   11,    0,
    0,    0,    0,  115,  -98,   25,    0,    0,   54,   -4,
   -3,
};
#define YYTABLESIZE 447
short yytable[] = {                                       9,
   35,   36,   53,   30,   37,  104,  140,   56,   41,  118,
   42,   23,   40,   35,   47,    9,   25,   46,   49,   74,
   23,   26,   73,   67,    9,   68,   22,   82,   59,   60,
   81,   71,   56,    9,   48,   22,   70,   24,  105,   72,
   27,   81,    9,    2,    3,    4,   67,  150,   68,  151,
   51,    9,   54,  112,  113,  133,  134,   28,  106,   55,
    9,   80,   90,   91,   43,   44,   94,   95,   45,    9,
   96,   84,   85,   86,   87,   88,   89,   58,    9,  107,
   69,   75,   76,   78,   77,  141,   83,    9,  108,   97,
  102,  119,  114,  120,   40,  122,    9,  129,  126,  131,
   40,  136,  138,  142,  127,    9,  139,  144,  152,  146,
  148,   40,    1,   54,  153,   54,   40,   54,  125,   52,
   35,   52,   40,   52,   46,   40,   44,  130,   42,   40,
   49,   54,   54,   67,   54,   68,  132,   52,   52,   53,
   52,   53,   51,   53,   40,  137,   40,   47,   45,   41,
   66,   43,   65,  103,  147,   40,   40,   53,   53,   48,
   53,  116,  117,  149,   50,  123,    0,    0,   32,   79,
   34,    0,  156,    0,    0,    0,    0,    0,    0,    0,
    0,  157,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   36,   36,    0,    0,   37,
    0,    0,   31,   32,   33,    0,    1,    2,    3,    4,
   29,    5,   52,    0,    6,   31,   32,   33,    0,    7,
   92,    8,    1,    2,    3,    4,    0,    5,   98,    0,
    6,    1,    2,    3,    4,    7,    5,    8,  109,    6,
    1,    2,    3,    4,    7,    5,    8,    0,    6,    1,
    2,    3,    4,    7,    5,    8,    0,    6,    1,    2,
    3,    4,    7,    5,    8,    0,    6,    1,    2,    3,
    4,    7,    5,    8,    0,    6,    1,    2,    3,    4,
    7,    5,    8,   11,    6,    1,    2,    3,    4,    7,
    5,    8,    0,    6,    1,    2,    3,    4,    7,    5,
    8,    0,    6,    1,    2,    3,    4,    7,    5,    8,
    0,    6,    1,    2,    3,    4,    7,    5,    8,    0,
    6,    0,   31,   32,   33,    7,   34,    8,   54,   54,
   54,   54,    0,    0,   52,   52,   52,   52,    0,    0,
    0,    0,    0,    0,    0,    0,   61,   62,   63,   64,
    0,    0,   93,    0,   53,   53,   53,   53,   99,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  115,    0,    0,
    0,  121,    0,    0,    0,    0,    0,  124,    0,    0,
    0,  128,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  143,    0,  145,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  154,  155,
};
short yycheck[] = {                                      40,
   45,   59,   41,   40,   59,  123,   44,   30,  257,  123,
   16,   44,   11,   45,   59,   40,   40,   23,  257,   41,
   44,   40,   44,   43,   40,   45,   59,   41,  258,  259,
   44,   42,   55,   40,   24,   59,   47,   61,   41,   59,
   40,   44,   40,  258,  259,  260,   43,  146,   45,  148,
   26,   40,   28,  263,  264,  273,  274,   40,   81,   40,
   40,  257,   67,   68,   59,   59,   70,   71,   59,   40,
  257,   61,   62,   63,   64,   65,   66,   41,   40,  276,
   41,   41,   41,   41,   59,  123,   59,   40,  123,   59,
   59,  257,  123,   61,   93,  264,   40,  259,   61,  264,
   99,  259,   44,  275,   61,   40,  123,  275,  123,   61,
   61,  110,    0,   41,  123,   43,  115,   45,  125,   41,
   45,   43,  121,   45,   41,  124,   41,  125,   41,  128,
   41,   59,   60,   43,   62,   45,  125,   59,   60,   41,
   62,   43,   41,   45,  143,  125,  145,   41,   41,   41,
   60,   41,   62,  271,  125,  154,  155,   59,   60,   41,
   62,  275,  276,  125,   41,  112,   -1,   -1,   59,   55,
   59,   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  263,  264,   -1,   -1,  264,
   -1,   -1,  257,  258,  259,   -1,  257,  258,  259,  260,
  257,  262,  261,   -1,  265,  257,  258,  259,   -1,  270,
  271,  272,  257,  258,  259,  260,   -1,  262,  263,   -1,
  265,  257,  258,  259,  260,  270,  262,  272,  264,  265,
  257,  258,  259,  260,  270,  262,  272,   -1,  265,  257,
  258,  259,  260,  270,  262,  272,   -1,  265,  257,  258,
  259,  260,  270,  262,  272,   -1,  265,  257,  258,  259,
  260,  270,  262,  272,   -1,  265,  257,  258,  259,  260,
  270,  262,  272,    0,  265,  257,  258,  259,  260,  270,
  262,  272,   -1,  265,  257,  258,  259,  260,  270,  262,
  272,   -1,  265,  257,  258,  259,  260,  270,  262,  272,
   -1,  265,  257,  258,  259,  260,  270,  262,  272,   -1,
  265,   -1,  257,  258,  259,  270,  261,  272,  266,  267,
  268,  269,   -1,   -1,  266,  267,  268,  269,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  266,  267,  268,  269,
   -1,   -1,   69,   -1,  266,  267,  268,  269,   75,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  104,   -1,   -1,
   -1,  108,   -1,   -1,   -1,   -1,   -1,  114,   -1,   -1,
   -1,  118,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  139,   -1,  141,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  152,  153,
};
#define YYFINAL 10
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 277
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"ID","FLOAT","LONGINT","INT","STRING","IF","ELSE","END_IF",
"OUT","GREATER_OR_EQUAL","LESS_OR_EQUAL","EQUAL","DIFFERENT","WHILE","LOOP",
"PROC","TRUE","FALSE","SHADOWING","NA","ERROR",
};
char *yyrule[] = {
"$accept : programa",
"programa : bloque_sentencia",
"bloque_sentencia : sentencia",
"bloque_sentencia : bloque_sentencia sentencia",
"sentencia : declarativa",
"sentencia : ejecutable",
"sentencia : imprimir",
"declarativa : tipo lista_de_variables",
"declarativa : procedimiento ';'",
"declarativa : lista_de_variables",
"lista_de_variables : ID ',' lista_de_variables",
"lista_de_variables : ID ';'",
"ejecutable : ID '=' expresion ';'",
"ejecutable : ID '=' ';'",
"ejecutable : invocacion_proc",
"ejecutable : sentencia_while ';'",
"ejecutable : sentencia_if ';'",
"invocacion_proc : ID '(' parametros ')' ';'",
"parametros : parametros ',' ID",
"parametros : ID",
"procedimiento : PROC ID '(' lista_de_parametros ')' NA '=' LONGINT ',' SHADOWING '=' true_false '{' bloque_sentencia '}'",
"procedimiento : PROC '(' lista_de_parametros ')' NA '=' LONGINT ',' SHADOWING '=' true_false '{' bloque_sentencia '}'",
"procedimiento : PROC ID '(' lista_de_parametros ')' SHADOWING '=' true_false '{' bloque_sentencia '}'",
"procedimiento : PROC ID '(' lista_de_parametros ')' NA '=' LONGINT '{' bloque_sentencia '}'",
"procedimiento : PROC ID '(' lista_de_parametros ')' '{' bloque_sentencia '}'",
"true_false : TRUE",
"true_false : FALSE",
"lista_de_parametros : lista_de_parametros ',' tipo ID",
"lista_de_parametros : tipo ID",
"sentencia_if : IF '(' condicion ')' cuerpo_if",
"sentencia_if : '(' condicion ')' bloque_sentencia END_IF",
"cuerpo_if : cuerpo_then END_IF",
"cuerpo_if : cuerpo_then",
"cuerpo_if : cuerpo_then ELSE cuerpo_else END_IF",
"cuerpo_if : cuerpo_then ELSE cuerpo_else",
"cuerpo_if : ELSE cuerpo_else END_IF",
"cuerpo_then : bloque_sentencia",
"cuerpo_else : bloque_sentencia",
"sentencia_while : WHILE '(' condicion ')' LOOP '{' bloque_sentencia '}'",
"sentencia_while : '(' condicion ')' LOOP '{' bloque_sentencia '}'",
"sentencia_while : WHILE '(' condicion ')' '{' bloque_sentencia '}'",
"condicion : expresion EQUAL expresion",
"condicion : expresion DIFFERENT",
"condicion : expresion DIFFERENT expresion",
"condicion : expresion LESS_OR_EQUAL",
"condicion : expresion LESS_OR_EQUAL expresion",
"condicion : expresion GREATER_OR_EQUAL",
"condicion : expresion GREATER_OR_EQUAL expresion",
"condicion : expresion '>' expresion",
"condicion : expresion '>'",
"condicion : expresion '<' expresion",
"condicion : expresion '<'",
"expresion : expresion '+' termino",
"expresion : expresion '-' termino",
"expresion : termino",
"termino : factor",
"termino : termino '/' factor",
"termino : termino '*' factor",
"factor : ID",
"factor : FLOAT",
"factor : '-' FLOAT",
"factor : LONGINT",
"factor : '-' LONGINT",
"tipo : INT",
"tipo : LONGINT",
"tipo : FLOAT",
"imprimir : OUT '(' STRING ')' ';'",
"imprimir : '(' STRING ')' ';'",
"imprimir : OUT '(' ')' ';'",
};
#endif
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#ifdef YYSTACKSIZE
#ifndef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#endif
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#define YYABORT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("yydebug: state %d, reading %d (%s)\n", yystate,
                    yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("yydebug: state %d, shifting to state %d (%s)\n",
                    yystate, yytable[yyn],yyrule[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("yydebug: state %d, error recovery shifting\
 to state %d\n", *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("yydebug: error recovery discarding state %d\n",
                            *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("yydebug: state %d, error recovery discards token %d (%s)\n",
                    yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("yydebug: state %d, reducing by rule %d (%s)\n",
                yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 7:
#line 31 "Gramatica.y"
{Logger::write("Declaracion de variables");
					chekeosGeneracion::asignar_tipo(Lexical_analyzer::symbolTable,yyvsp[-1].cadena,yyvsp[0].cadena);
					/*chekeosGeneracion::imprimirLista();*/
	      				}
break;
case 8:
#line 35 "Gramatica.y"
{Logger::write("Declaracion de procedimiento");}
break;
case 9:
#line 36 "Gramatica.y"
{Logger::write("Error: Falta el tipo en la lista de variables");}
break;
case 10:
#line 40 "Gramatica.y"
{yyval=yyvsp[0];}
break;
case 11:
#line 41 "Gramatica.y"
{yyval=yyvsp[-1]; string s=yyvsp[-1].cadena; cout<< "imprimo $1" + s<<endl;}
break;
case 12:
#line 45 "Gramatica.y"
{Logger::write("Asignacion");  chekeosGeneracion::insertar_terceto("=",yyvsp[-1].cadena,yyvsp[-1].cadena);}
break;
case 13:
#line 46 "Gramatica.y"
{Logger::write("Error: Asignacion vacia");}
break;
case 14:
#line 47 "Gramatica.y"
{Logger::write("invocacion procedimiento");}
break;
case 15:
#line 48 "Gramatica.y"
{Logger::write("sentencia while");}
break;
case 16:
#line 49 "Gramatica.y"
{Logger::write("sentencia if");}
break;
case 20:
#line 62 "Gramatica.y"
{Sintactic_actions::check_list_parametros();}
break;
case 21:
#line 63 "Gramatica.y"
{Logger::write("Error: FALTA ID");}
break;
case 22:
#line 64 "Gramatica.y"
{Logger::write("Error: FALTA ESPECIFICAR VALOR NA");}
break;
case 23:
#line 65 "Gramatica.y"
{Logger::write("Error: FALTA ESPECIFICAR VALOR SHADOWING");}
break;
case 24:
#line 66 "Gramatica.y"
{Logger::write("Error: FALTA ESPECIFICAR LOS VALORES DE NA Y SHADOWING");}
break;
case 27:
#line 75 "Gramatica.y"
{Logger::write("lista_de_variables");
	 	       				       Sintactic_actions::number_of_parameters++;
	 	       				       }
break;
case 28:
#line 78 "Gramatica.y"
{Sintactic_actions::number_of_parameters++;
		    		}
break;
case 29:
#line 83 "Gramatica.y"
{Logger::write("Sentencia IF");}
break;
case 30:
#line 84 "Gramatica.y"
{Logger::write("Error: FALTA EL IF");}
break;
case 32:
#line 89 "Gramatica.y"
{Logger::write("Error: FALTA END_IF");}
break;
case 33:
#line 90 "Gramatica.y"
{Logger::write("Error: FALTA END_IF");}
break;
case 38:
#line 110 "Gramatica.y"
{Logger::write("Sentencia WHILE");}
break;
case 39:
#line 111 "Gramatica.y"
{Logger::write("Error: FALTA 'WHILE' EN LA SENTENCIA");}
break;
case 40:
#line 112 "Gramatica.y"
{Logger::write("Error: FALTA 'LOOP' EN SENTENCIA WHILE");}
break;
case 41:
#line 116 "Gramatica.y"
{Logger::write("Condicion igual");}
break;
case 42:
#line 117 "Gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 43:
#line 118 "Gramatica.y"
{Logger::write("Condicion distinto");}
break;
case 44:
#line 119 "Gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 45:
#line 120 "Gramatica.y"
{Logger::write("Condicion menorigual");}
break;
case 46:
#line 121 "Gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 47:
#line 122 "Gramatica.y"
{Logger::write("Condicion mayorIgual");}
break;
case 48:
#line 123 "Gramatica.y"
{Logger::write("Condicion de mayor");}
break;
case 49:
#line 124 "Gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 50:
#line 125 "Gramatica.y"
{Logger::write("Condicion de menor");}
break;
case 51:
#line 126 "Gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 52:
#line 130 "Gramatica.y"
{Logger::write("suma");}
break;
case 53:
#line 131 "Gramatica.y"
{Logger::write("resta");}
break;
case 56:
#line 138 "Gramatica.y"
{ Sintactic_actions::check_division_zero(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 60:
#line 145 "Gramatica.y"
{ Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 61:
#line 146 "Gramatica.y"
{ Sintactic_actions::check_limit(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 62:
#line 147 "Gramatica.y"
{ Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 63:
#line 151 "Gramatica.y"
{ string s = "Int"; yyval.cadena = &s[0];}
break;
case 64:
#line 152 "Gramatica.y"
{ string s = "Longint"; yyval.cadena = &s[0];}
break;
case 65:
#line 153 "Gramatica.y"
{ string s = "Float"; yyval.cadena = &s[0];}
break;
case 66:
#line 157 "Gramatica.y"
{Logger::write("Detecto sentencia OUT");}
break;
case 67:
#line 158 "Gramatica.y"
{Logger::write("Error: SE ESPERABA OUT PREVIAMENTE PARA IMPRIMIR");}
break;
case 68:
#line 159 "Gramatica.y"
{Logger::write("Error: SE ESPERABA CADENA EN LA SENTENCIA OUT");}
break;
#line 659 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("yydebug: after reduction, shifting from state 0 to\
 state %d\n", YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("yydebug: state %d, reading %d (%s)\n",
                        YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("yydebug: after reduction, shifting from state %d \
to state %d\n", *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
