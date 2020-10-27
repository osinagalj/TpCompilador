#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
#line 7 "gramatica.y"
typedef union {
    int entero=0;
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
   12,   12,   12,   11,   11,   11,   16,   16,   16,   16,
   16,   16,   16,   16,   16,   16,   16,    9,    9,    9,
   17,   17,   17,   18,   18,   18,   18,   18,    6,    6,
    6,    5,    5,    5,
};
short yylen[] = {                                         2,
    1,    1,    2,    1,    1,    1,    2,    2,    1,    3,
    2,    4,    3,    1,    2,    2,    5,    3,    1,   15,
   14,   11,   11,    8,    1,    1,    4,    2,    6,    5,
    8,    7,    5,    8,    7,    7,    3,    2,    3,    2,
    3,    2,    3,    3,    2,    3,    2,    3,    3,    1,
    1,    3,    3,    1,    1,    2,    1,    2,    1,    1,
    1,    5,    4,    4,
};
short yydefred[] = {                                      0,
    0,   61,   60,   59,    0,    0,    0,    0,    0,    0,
    0,    2,    4,    5,    6,    0,    9,    0,   14,    0,
    0,   11,    0,    0,    0,    0,    0,    0,    0,    0,
   54,   55,   57,    0,    0,    0,    0,    0,   51,    3,
    0,    7,    8,   15,   16,   10,   13,    0,   19,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   56,   58,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   12,    0,    0,    0,    0,   64,    0,    0,   28,
    0,    0,   63,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   52,   53,   18,   17,    0,   62,    0,
    0,    0,    0,    0,    0,   33,    0,   29,    0,    0,
    0,    0,    0,   27,    0,    0,    0,    0,   36,    0,
    0,    0,    0,   35,   31,   34,   25,   26,    0,    0,
   24,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   22,    0,   23,    0,    0,    0,    0,    0,    0,   21,
   20,
};
short yydgoto[] = {                                      10,
   11,   12,   13,   14,   15,   16,   17,   18,   36,   19,
   20,   21,   50,   57,  129,   37,   38,   39,
};
short yysindex[] = {                                     75,
  -32,    0,    0,    0,  -30,   -2,    2,  -36,   85,    0,
   75,    0,    0,    0,    0, -202,    0,   10,    0,   14,
   15,    0, -202,  -44, -190,  -22,  -28,  -22,   35, -195,
    0,    0,    0,   37, -239,  100,   42,  -25,    0,    0,
  -33,    0,    0,    0,    0,    0,    0,  -29,    0,   -9,
   44,   45,   28,   49, -195, -177,   -8,   32,    0,    0,
  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -31,  -22,
  -22,    0, -168,   33,   75,   34,    0, -120,   -4,    0,
 -195, -182,    0,    8,    8,    8,    8,    8,    8,  -25,
  -25,  -23,  -15,    0,    0,    0,    0,  -40,    0,  -21,
   75, -118, -159,   38,   75,    0,   75,    0,   75,   -6,
   43,   46,   75,    0, -158,    3,   12,   21,    0, -214,
 -156,   30,   61,    0,    0,    0,    0,    0,  -14,  -42,
    0, -167,   75, -165,   75,   50,   39,   51,   48, -214,
    0, -214,    0,  -10,   -7,   75,   75,   57,   66,    0,
    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  114,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   82,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   76,   77,    0,   79,   80,   81,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   83,   91,   93,   95,   97,   99,   88,
   94,    0,    0,    0,    0,    0,    0,   67,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   90,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
short yygindex[] = {                                      0,
  -51,  283,    0,    0,    0,  -24,    5,    0,  -17,    0,
    0,    0,    0,  104, -101,   40,    4,    6,
};
#define YYTABLESIZE 432
short yytable[] = {                                       9,
   35,  134,  101,   30,  113,   56,   48,   25,    9,   26,
   23,   23,   53,   67,   47,   68,   71,   93,   59,   60,
   42,   70,   35,   98,    9,   22,   22,   46,   24,   72,
   56,   74,   82,    9,   73,   81,  102,   27,  144,   81,
  145,   28,    9,   84,   85,   86,   87,   88,   89,  110,
   67,    9,   68,  116,   41,  117,  103,  118,  127,  128,
    9,  122,    2,    3,    4,   51,   49,   54,   43,    9,
   90,   91,   44,   45,   55,   94,   95,   58,    9,   80,
  135,  137,   69,  139,   75,   76,   77,    9,   96,   78,
   83,   97,   99,  104,  148,  149,    9,  114,  115,  105,
  123,  109,  130,  120,  132,    9,  121,  136,  133,  138,
  140,  142,  146,    1,    9,  147,   42,   40,  119,   38,
   45,   47,   50,   43,   50,   30,   50,  124,   48,   35,
   48,   41,   48,   37,   49,   39,   49,   44,   49,   46,
   50,   50,   67,   50,   68,  126,   48,   48,   32,   48,
  100,    0,   49,   49,  131,   49,  111,  112,   79,   66,
    0,   65,    0,  141,    0,    0,    0,    0,    0,    0,
    0,    0,  143,    0,    0,    0,    0,    0,    0,    0,
    0,  150,    0,    0,    0,    0,    0,    0,    0,    0,
  151,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   31,   32,   33,    0,    1,    2,    3,    4,
   29,    5,  107,  108,    6,    1,    2,    3,    4,    7,
    5,    8,   52,    6,   31,   32,   33,    0,    7,   92,
    8,    1,    2,    3,    4,    0,    5,    0,  106,    6,
    1,    2,    3,    4,    7,    5,    8,    0,    6,    1,
    2,    3,    4,    7,    5,    8,    0,    6,    1,    2,
    3,    4,    7,    5,    8,  125,    6,    1,    2,    3,
    4,    7,    5,    8,    0,    6,    1,    2,    3,    4,
    7,    5,    8,   40,    6,    1,    2,    3,    4,    7,
    5,    8,    0,    6,    1,    2,    3,    4,    7,    5,
    8,    0,    6,    1,    2,    3,    4,    7,    5,    8,
    0,    6,    1,    2,    3,    4,    7,    5,    8,    0,
    6,    1,    2,    3,    4,    7,    5,    8,    0,    6,
    0,   31,   32,   33,    7,   34,    8,   50,   50,   50,
   50,    0,    0,   48,   48,   48,   48,    0,    0,   49,
   49,   49,   49,    0,    0,   61,   62,   63,   64,    0,
    0,    0,    0,    0,    0,   40,    0,    0,    0,    0,
   40,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   40,    0,    0,    0,    0,    0,   40,   40,
   40,    0,    0,    0,   40,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   40,
    0,   40,    0,    0,    0,    0,    0,    0,    0,    0,
   40,   40,
};
short yycheck[] = {                                      40,
   45,   44,  123,   40,  123,   30,   24,   40,   40,   40,
   44,   44,   41,   43,   59,   45,   42,   69,  258,  259,
   16,   47,   45,   75,   40,   59,   59,   23,   61,   59,
   55,   41,   41,   40,   44,   44,   41,   40,  140,   44,
  142,   40,   40,   61,   62,   63,   64,   65,   66,  101,
   43,   40,   45,  105,  257,  107,   81,  109,  273,  274,
   40,  113,  258,  259,  260,   26,  257,   28,   59,   40,
   67,   68,   59,   59,   40,   70,   71,   41,   40,  257,
  123,  133,   41,  135,   41,   41,   59,   40,  257,   41,
   59,   59,   59,  276,  146,  147,   40,  257,   61,  123,
  259,  123,  259,   61,   44,   40,   61,  275,  123,  275,
   61,   61,  123,    0,   40,  123,   41,   41,  125,   41,
   41,   41,   41,   41,   43,   59,   45,  125,   41,   45,
   43,   41,   45,   41,   41,   41,   43,   41,   45,   41,
   59,   60,   43,   62,   45,  125,   59,   60,   59,   62,
  271,   -1,   59,   60,  125,   62,  275,  276,   55,   60,
   -1,   62,   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  257,  258,  259,   -1,  257,  258,  259,  260,
  257,  262,  263,  264,  265,  257,  258,  259,  260,  270,
  262,  272,  261,  265,  257,  258,  259,   -1,  270,  271,
  272,  257,  258,  259,  260,   -1,  262,   -1,  264,  265,
  257,  258,  259,  260,  270,  262,  272,   -1,  265,  257,
  258,  259,  260,  270,  262,  272,   -1,  265,  257,  258,
  259,  260,  270,  262,  272,  264,  265,  257,  258,  259,
  260,  270,  262,  272,   -1,  265,  257,  258,  259,  260,
  270,  262,  272,   11,  265,  257,  258,  259,  260,  270,
  262,  272,   -1,  265,  257,  258,  259,  260,  270,  262,
  272,   -1,  265,  257,  258,  259,  260,  270,  262,  272,
   -1,  265,  257,  258,  259,  260,  270,  262,  272,   -1,
  265,  257,  258,  259,  260,  270,  262,  272,   -1,  265,
   -1,  257,  258,  259,  270,  261,  272,  266,  267,  268,
  269,   -1,   -1,  266,  267,  268,  269,   -1,   -1,  266,
  267,  268,  269,   -1,   -1,  266,  267,  268,  269,   -1,
   -1,   -1,   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,
   98,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  110,   -1,   -1,   -1,   -1,   -1,  116,  117,
  118,   -1,   -1,   -1,  122,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  137,
   -1,  139,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  148,  149,
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
"sentencia_if : IF '(' condicion ')' bloque_sentencia END_IF",
"sentencia_if : IF '(' condicion ')' bloque_sentencia",
"sentencia_if : IF '(' condicion ')' bloque_sentencia ELSE bloque_sentencia END_IF",
"sentencia_if : IF '(' condicion ')' bloque_sentencia ELSE bloque_sentencia",
"sentencia_if : '(' condicion ')' bloque_sentencia END_IF",
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
#line 31 "gramatica.y"
{Logger::write("Declaracion de variables");}
break;
case 8:
#line 32 "gramatica.y"
{Logger::write("Declaracion de procedimiento");}
break;
case 9:
#line 33 "gramatica.y"
{Logger::write("Error: Falta el tipo en la lista de variables");}
break;
case 12:
#line 42 "gramatica.y"
{Logger::write("Asignacion");  chekeosGeneracion::insertar_terceto("=",yyvsp[-1].cadena,yyvsp[-1].cadena);}
break;
case 13:
#line 43 "gramatica.y"
{Logger::write("Error: Asignacion vacia");}
break;
case 14:
#line 44 "gramatica.y"
{Logger::write("invocacion procedimiento");}
break;
case 15:
#line 45 "gramatica.y"
{Logger::write("sentencia while");}
break;
case 16:
#line 46 "gramatica.y"
{Logger::write("sentencia if");}
break;
case 20:
#line 59 "gramatica.y"
{Sintactic_actions::check_list_parametros();}
break;
case 21:
#line 60 "gramatica.y"
{Logger::write("Error: FALTA ID");}
break;
case 22:
#line 61 "gramatica.y"
{Logger::write("Error: FALTA ESPECIFICAR VALOR NA");}
break;
case 23:
#line 62 "gramatica.y"
{Logger::write("Error: FALTA ESPECIFICAR VALOR SHADOWING");}
break;
case 24:
#line 63 "gramatica.y"
{Logger::write("Error: FALTA ESPECIFICAR LOS VALORES DE NA Y SHADOWING");}
break;
case 27:
#line 72 "gramatica.y"
{Logger::write("lista_de_variables"); Sintactic_actions::number_of_parameters++;}
break;
case 28:
#line 73 "gramatica.y"
{Sintactic_actions::number_of_parameters++;}
break;
case 29:
#line 77 "gramatica.y"
{Logger::write("Sentencia IF");}
break;
case 30:
#line 78 "gramatica.y"
{Logger::write("Error: FALTA END_IF");}
break;
case 31:
#line 79 "gramatica.y"
{Logger::write("Sentencia IF-ELSE");}
break;
case 32:
#line 80 "gramatica.y"
{Logger::write("Error: FALTA END_IF");}
break;
case 33:
#line 81 "gramatica.y"
{Logger::write("Error: FALTA EL IF");}
break;
case 34:
#line 86 "gramatica.y"
{Logger::write("Sentencia WHILE");}
break;
case 35:
#line 87 "gramatica.y"
{Logger::write("Error: FALTA 'WHILE' EN LA SENTENCIA");}
break;
case 36:
#line 88 "gramatica.y"
{Logger::write("Error: FALTA 'LOOP' EN SENTENCIA WHILE");}
break;
case 37:
#line 92 "gramatica.y"
{Logger::write("Condicion igual");}
break;
case 38:
#line 93 "gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 39:
#line 94 "gramatica.y"
{Logger::write("Condicion distinto");}
break;
case 40:
#line 95 "gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 41:
#line 96 "gramatica.y"
{Logger::write("Condicion menorigual");}
break;
case 42:
#line 97 "gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 43:
#line 98 "gramatica.y"
{Logger::write("Condicion mayorIgual");}
break;
case 44:
#line 99 "gramatica.y"
{Logger::write("Condicion de mayor");}
break;
case 45:
#line 100 "gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 46:
#line 101 "gramatica.y"
{Logger::write("Condicion de menor");}
break;
case 47:
#line 102 "gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 48:
#line 106 "gramatica.y"
{Logger::write("suma");}
break;
case 49:
#line 107 "gramatica.y"
{Logger::write("resta");}
break;
case 52:
#line 114 "gramatica.y"
{ Sintactic_actions::check_division_zero(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 56:
#line 121 "gramatica.y"
{ Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 57:
#line 122 "gramatica.y"
{ Sintactic_actions::check_limit(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 58:
#line 123 "gramatica.y"
{ Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 62:
#line 133 "gramatica.y"
{Logger::write("Detecto sentencia OUT");}
break;
case 63:
#line 134 "gramatica.y"
{Logger::write("Error: SE ESPERABA OUT PREVIAMENTE PARA IMPRIMIR");}
break;
case 64:
#line 135 "gramatica.y"
{Logger::write("Error: SE ESPERABA CADENA EN LA SENTENCIA OUT");}
break;
#line 629 "y.tab.c"
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
