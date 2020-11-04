#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
#line 7 "gramatica.y"
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
    7,    4,    4,    4,    4,    4,   10,   13,   13,   14,
    8,    8,    8,    8,    8,   16,   16,   15,   15,   17,
   12,   12,   19,   19,   19,   19,   19,   20,   21,   22,
   11,   11,   11,   18,   18,   18,   18,   18,   18,   18,
   18,   18,   18,   18,    9,    9,    9,   23,   23,   23,
   24,   24,   24,   24,   24,    6,    6,    6,    5,    5,
    5,
};
short yylen[] = {                                         2,
    1,    1,    2,    1,    1,    1,    2,    2,    1,    3,
    2,    4,    3,    1,    2,    2,    5,    3,    1,    2,
   14,   14,   10,   10,    7,    1,    1,    4,    2,    4,
    2,    4,    2,    1,    4,    3,    3,    1,    1,    1,
    8,    7,    7,    3,    2,    3,    2,    3,    2,    3,
    3,    2,    3,    2,    3,    3,    1,    1,    3,    3,
    1,    1,    2,    1,    2,    1,    1,    1,    5,    4,
    4,
};
short yydefred[] = {                                      0,
    0,   68,   67,   66,    0,    0,   40,    0,    0,    0,
    0,    2,    4,    5,    6,    0,    9,    0,   14,    0,
    0,    0,    0,    0,   11,    0,    0,    0,    0,    0,
   20,    0,   61,   62,   64,    0,    0,    0,    0,    0,
   58,    3,    0,    7,    8,   15,   16,    0,    0,    0,
   31,    0,    0,   10,   13,    0,   19,    0,    0,    0,
    0,    0,    0,    0,   63,   65,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   33,    0,   12,    0,    0,   30,    0,   71,   29,
    0,    0,   70,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   32,   59,   60,    0,   37,    0,    0,   18,
   17,   69,    0,    0,    0,    0,    0,    0,   35,    0,
    0,   28,    0,    0,    0,    0,    0,    0,    0,    0,
   42,   26,   27,    0,    0,   25,    0,   43,    0,    0,
    0,    0,   41,    0,    0,    0,    0,    0,   23,    0,
   24,    0,    0,    0,    0,    0,    0,   22,   21,
};
short yydgoto[] = {                                      10,
   50,   12,   13,   14,   15,   16,   17,   18,   38,   19,
   20,   21,   58,   22,   63,  134,   23,   39,   51,   52,
   80,   24,   40,   41,
};
short yysindex[] = {                                     57,
  -30,    0,    0,    0,  -16,  -10,    0,  -31,   67,    0,
   57,    0,    0,    0,    0, -225,    0,   10,    0,   14,
   15,    4,  -24,   35,    0, -225,  -44, -219,   95,  -37,
    0, -212,    0,    0,    0,    9, -199,   82,   36,  -21,
    0,    0,  -32,    0,    0,    0,    0, -212,   57,   57,
    0, -201,   95,    0,    0,  -26,    0,   -5,   37,   40,
   17, -177,   -4,   23,    0,    0,   95,   95,   95,   95,
   95,   95,   95,   95,  -40,   95,   95,    1,   57, -181,
   57,    0,   43,    0, -172,   27,    0,   32,    0,    0,
 -212, -187,    0,  -23,  -23,  -23,  -23,  -23,  -23,  -21,
  -21,  -29,    0,    0,    0, -118,    0, -171, -117,    0,
    0,    0, -165,   34,   57,   38,   42,   57,    0,  -27,
   57,    0, -161,  -15, -209, -159,   -6,   57,    3,   58,
    0,    0,    0,  -22,  -36,    0,   12,    0, -169,   57,
 -167,   57,    0,   53,   21,   55,   30, -209,    0, -209,
    0,  -19,   -3,   57,   57,   39,   48,    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  117,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   64,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -57,
    0,   59,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   80,   93,    0,   97,
   98,  100,    0,    0,    0,    0,    0,    0,  -56,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  102,  104,  106,  107,  110,  112,   70,
   90,    0,    0,    0,    0,    0,    0,   77,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
   41,  292,    0,    0,    0,  -25,    2,    0,  -14,    0,
    0,    0,    0,    0,  113,  -99,    0,  -18,   85,    0,
   84,    0,   -2,   -9,
};
#define YYTABLESIZE 449
short yytable[] = {                                       9,
   37,   38,   39,   61,  118,  121,   62,  141,   32,   28,
   59,   26,   56,   26,   55,    9,   73,   44,   74,   73,
   77,   74,   62,   29,    9,   76,   25,   54,   25,   30,
   27,   43,   84,    9,   83,   86,   92,   57,   85,   91,
   11,  106,    9,   48,   91,    2,    3,    4,  152,   64,
  153,    9,   94,   95,   96,   97,   98,   99,   65,   66,
    9,   81,   82,  132,  133,  113,  104,  105,   45,    9,
  100,  101,   46,   47,   53,   89,   75,   87,    9,   90,
   88,   93,  107,  109,  110,  111,  142,    9,  114,   79,
  112,  122,  119,  115,  123,  128,    9,  130,  125,  135,
  140,  139,  126,  154,   57,  144,   57,  146,   57,  131,
   55,   37,   55,  148,   55,  150,    1,   34,  136,  155,
   49,   79,   57,   57,   73,   57,   74,  138,   55,   55,
   56,   55,   56,   47,   56,   36,  143,   45,   52,   37,
   54,   72,   50,   71,   48,  149,   44,   46,   56,   56,
   51,   56,   53,  120,  151,  124,  116,  117,  127,  103,
   78,  129,    0,  158,  108,    0,    0,    0,  137,    0,
    0,    0,  159,    0,    0,    0,    0,    0,    0,    0,
  145,    0,  147,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  156,  157,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   38,   38,   39,    0,    0,
    0,    0,   33,   34,   35,    0,    1,    2,    3,    4,
    0,    5,   49,   60,    6,   31,    0,    0,    0,    7,
  102,    8,    1,    2,    3,    4,    0,    5,   49,    0,
    6,    1,    2,    3,    4,    7,    5,    8,    0,    6,
    1,    2,    3,    4,    7,    5,    8,    0,    6,    1,
    2,    3,    4,    7,    5,    8,    0,    6,    1,    2,
    3,    4,    7,    5,    8,    0,    6,    1,    2,    3,
    4,    7,    5,    8,    0,    6,    1,    2,    3,    4,
    7,    5,    8,    0,    6,    1,    2,    3,    4,    7,
    5,    8,   42,    6,    1,    2,    3,    4,    7,    5,
    8,    0,    6,    1,    2,    3,    4,    7,    5,    8,
    0,    6,    0,   33,   34,   35,    7,   36,    8,   57,
   57,   57,   57,    0,    0,   55,   55,   55,   55,    0,
    0,   42,    0,    0,    0,    0,    0,   67,   68,   69,
   70,   33,   34,   35,    0,   56,   56,   56,   56,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   42,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   42,    0,    0,   42,    0,
   42,    0,    0,    0,    0,    0,    0,    0,   42,    0,
    0,    0,    0,    0,    0,    0,   42,    0,   42,    0,
    0,    0,    0,    0,    0,    0,    0,   42,   42,
};
short yycheck[] = {                                      40,
   45,   59,   59,   41,  123,  123,   32,   44,   40,   40,
   29,   44,   27,   44,   59,   40,   43,   16,   45,   43,
   42,   45,   48,   40,   40,   47,   59,   26,   59,   40,
   61,  257,   59,   40,   53,   41,   41,  257,   44,   44,
    0,   41,   40,   40,   44,  258,  259,  260,  148,   41,
  150,   40,   67,   68,   69,   70,   71,   72,  258,  259,
   40,  263,  264,  273,  274,   91,   76,   77,   59,   40,
   73,   74,   59,   59,   40,   59,   41,   41,   40,  257,
   41,   59,  264,   41,  257,   59,  123,   40,  276,   49,
   59,  257,  264,  123,   61,  123,   40,  259,   61,  259,
  123,   44,   61,  123,   41,  275,   43,  275,   45,  125,
   41,   45,   43,   61,   45,   61,    0,   59,  125,  123,
   41,   81,   59,   60,   43,   62,   45,  125,   59,   60,
   41,   62,   43,   41,   45,   59,  125,   41,   41,   45,
   41,   60,   41,   62,   41,  125,   41,   41,   59,   60,
   41,   62,   41,  271,  125,  115,  275,  276,  118,   75,
   48,  121,   -1,  125,   81,   -1,   -1,   -1,  128,   -1,
   -1,   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  140,   -1,  142,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  154,  155,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  263,  264,  264,   -1,   -1,
   -1,   -1,  257,  258,  259,   -1,  257,  258,  259,  260,
   -1,  262,  263,  261,  265,  257,   -1,   -1,   -1,  270,
  271,  272,  257,  258,  259,  260,   -1,  262,  263,   -1,
  265,  257,  258,  259,  260,  270,  262,  272,   -1,  265,
  257,  258,  259,  260,  270,  262,  272,   -1,  265,  257,
  258,  259,  260,  270,  262,  272,   -1,  265,  257,  258,
  259,  260,  270,  262,  272,   -1,  265,  257,  258,  259,
  260,  270,  262,  272,   -1,  265,  257,  258,  259,  260,
  270,  262,  272,   -1,  265,  257,  258,  259,  260,  270,
  262,  272,   11,  265,  257,  258,  259,  260,  270,  262,
  272,   -1,  265,  257,  258,  259,  260,  270,  262,  272,
   -1,  265,   -1,  257,  258,  259,  270,  261,  272,  266,
  267,  268,  269,   -1,   -1,  266,  267,  268,  269,   -1,
   -1,   50,   -1,   -1,   -1,   -1,   -1,  266,  267,  268,
  269,  257,  258,  259,   -1,  266,  267,  268,  269,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   79,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,  127,   -1,
  129,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  137,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  145,   -1,  147,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  156,  157,
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
"nombre_proc : PROC ID",
"procedimiento : nombre_proc '(' lista_de_parametros ')' NA '=' LONGINT ',' SHADOWING '=' true_false '{' bloque_sentencia '}'",
"procedimiento : PROC '(' lista_de_parametros ')' NA '=' LONGINT ',' SHADOWING '=' true_false '{' bloque_sentencia '}'",
"procedimiento : nombre_proc '(' lista_de_parametros ')' SHADOWING '=' true_false '{' bloque_sentencia '}'",
"procedimiento : nombre_proc '(' lista_de_parametros ')' NA '=' LONGINT '{' bloque_sentencia '}'",
"procedimiento : nombre_proc '(' lista_de_parametros ')' '{' bloque_sentencia '}'",
"true_false : TRUE",
"true_false : FALSE",
"lista_de_parametros : lista_de_parametros ',' tipo ID",
"lista_de_parametros : tipo ID",
"encabezado_if : IF '(' condicion ')'",
"sentencia_if : encabezado_if cuerpo_if",
"sentencia_if : '(' condicion ')' cuerpo_if",
"cuerpo_if : cuerpo_then END_IF",
"cuerpo_if : cuerpo_then",
"cuerpo_if : cuerpo_then ELSE cuerpo_else END_IF",
"cuerpo_if : cuerpo_then ELSE cuerpo_else",
"cuerpo_if : ELSE cuerpo_else END_IF",
"cuerpo_then : bloque_sentencia",
"cuerpo_else : bloque_sentencia",
"encabezado_while : WHILE",
"sentencia_while : encabezado_while '(' condicion ')' LOOP '{' bloque_sentencia '}'",
"sentencia_while : '(' condicion ')' LOOP '{' bloque_sentencia '}'",
"sentencia_while : encabezado_while '(' condicion ')' '{' bloque_sentencia '}'",
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
{Logger::write("Declaracion de variables");
						chekeosGeneracion::asignar_tipo(Lexical_analyzer::symbolTable,yyvsp[-1].cadena);
	      		      		}
break;
case 8:
#line 34 "gramatica.y"
{Logger::write("Declaracion de procedimiento"); }
break;
case 9:
#line 35 "gramatica.y"
{Logger::write("Error: Falta el tipo en la lista de variables");}
break;
case 10:
#line 42 "gramatica.y"
{ char * ambito = "Lista de variables";
		     				chekeosGeneracion::addVariable(yyvsp[-2].cadena);
                                                 chekeosGeneracion::convertS2(yyvsp[-2].cadena,ambito);
                                                  }
break;
case 11:
#line 46 "gramatica.y"
{	chekeosGeneracion::addVariable(yyvsp[-1].cadena);
		   		char * ambito = "Ultimo ID en lista de variables";
                            	 chekeosGeneracion::convertS2(yyvsp[-1].cadena,ambito);
                            	  }
break;
case 12:
#line 53 "gramatica.y"
{Logger::write("Asignacion");
	      			  chekeosGeneracion::insertar_terceto("=",yyvsp[-1].cadena,yyvsp[-1].cadena);
				  yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-3].cadena,yyvsp[-1].cadena);
	      			  }
break;
case 13:
#line 57 "gramatica.y"
{Logger::write("Error: Asignacion vacia");}
break;
case 14:
#line 58 "gramatica.y"
{Logger::write("invocacion procedimiento");}
break;
case 15:
#line 59 "gramatica.y"
{Logger::write("sentencia while"); chekeosGeneracion::desconcatenarAmbitoAnonimo();}
break;
case 16:
#line 60 "gramatica.y"
{Logger::write("sentencia if");  chekeosGeneracion::desconcatenarAmbitoAnonimo();}
break;
case 20:
#line 71 "gramatica.y"
{chekeosGeneracion::concatenarAmbito(yyvsp[0].cadena);}
break;
case 21:
#line 76 "gramatica.y"
{Sintactic_actions::check_list_parametros();
	 											chekeosGeneracion::eliminarUltimoAmbito();
	 											  }
break;
case 22:
#line 79 "gramatica.y"
{Logger::write("Error: FALTA ID"); chekeosGeneracion::eliminarUltimoAmbito();}
break;
case 23:
#line 80 "gramatica.y"
{Logger::write("Error: FALTA ESPECIFICAR VALOR NA"); chekeosGeneracion::eliminarUltimoAmbito();}
break;
case 24:
#line 81 "gramatica.y"
{Logger::write("Error: FALTA ESPECIFICAR VALOR SHADOWING"); chekeosGeneracion::eliminarUltimoAmbito();}
break;
case 25:
#line 82 "gramatica.y"
{Logger::write("Error: FALTA ESPECIFICAR LOS VALORES DE NA Y SHADOWING"); chekeosGeneracion::eliminarUltimoAmbito();}
break;
case 28:
#line 91 "gramatica.y"
{Logger::write("lista_de_variables");
	 	       				       Sintactic_actions::number_of_parameters++;

	 	       				       }
break;
case 29:
#line 95 "gramatica.y"
{Sintactic_actions::number_of_parameters++;
				 char * ambito = "id de lista de parametros";
                                  chekeosGeneracion::convertS2(yyvsp[-1].cadena,ambito);

                                  }
break;
case 30:
#line 102 "gramatica.y"
{chekeosGeneracion::concatenarAmbitoAnonimo("IF");}
break;
case 31:
#line 105 "gramatica.y"
{Logger::write("Sentencia IF");
	       				}
break;
case 32:
#line 107 "gramatica.y"
{Logger::write("Error: FALTA EL IF");}
break;
case 34:
#line 112 "gramatica.y"
{Logger::write("Error: FALTA END_IF");  }
break;
case 35:
#line 113 "gramatica.y"
{Logger::write("Error: FALTA END_IF");}
break;
case 40:
#line 126 "gramatica.y"
{chekeosGeneracion::concatenarAmbitoAnonimo("WHILE");}
break;
case 41:
#line 130 "gramatica.y"
{Logger::write("Sentencia WHILE");}
break;
case 42:
#line 131 "gramatica.y"
{Logger::write("Error: FALTA 'WHILE' EN LA SENTENCIA");}
break;
case 43:
#line 132 "gramatica.y"
{Logger::write("Error: FALTA 'LOOP' EN SENTENCIA WHILE");}
break;
case 44:
#line 137 "gramatica.y"
{Logger::write("Condicion igual");
	   			     yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);}
break;
case 45:
#line 139 "gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 46:
#line 140 "gramatica.y"
{Logger::write("Condicion distinto");
	  				  yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);}
break;
case 47:
#line 142 "gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 48:
#line 143 "gramatica.y"
{Logger::write("Condicion menorigual");
	  				      yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);}
break;
case 49:
#line 145 "gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 50:
#line 146 "gramatica.y"
{Logger::write("Condicion mayorIgual");
	  					yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);}
break;
case 51:
#line 148 "gramatica.y"
{Logger::write("Condicion de mayor");
	  			    yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);}
break;
case 52:
#line 150 "gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 53:
#line 151 "gramatica.y"
{Logger::write("Condicion de menor");
                                    yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);}
break;
case 54:
#line 153 "gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 55:
#line 157 "gramatica.y"
{Logger::write("suma");
				  yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);
	   			}
break;
case 56:
#line 160 "gramatica.y"
{Logger::write("resta");
	  		 	  yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);}
break;
case 57:
#line 162 "gramatica.y"
{yyval.cadena = yyvsp[0].cadena;}
break;
case 58:
#line 167 "gramatica.y"
{yyval.cadena = yyvsp[0].cadena; }
break;
case 59:
#line 168 "gramatica.y"
{ Sintactic_actions::check_division_zero(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
			      yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);}
break;
case 60:
#line 170 "gramatica.y"
{ yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);}
break;
case 61:
#line 174 "gramatica.y"
{ char * ambito = "ambito id";
	 	  chekeosGeneracion::convertS2(yyvsp[0].cadena,ambito);
	 	  yyval.cadena= yyvsp[0].cadena;}
break;
case 62:
#line 177 "gramatica.y"
{yyval.cadena= yyvsp[0].cadena;}
break;
case 63:
#line 178 "gramatica.y"
{yyval.cadena= Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 64:
#line 179 "gramatica.y"
{ Sintactic_actions::check_limit(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
		   yyval.cadena= yyvsp[0].cadena;}
break;
case 65:
#line 181 "gramatica.y"
{ yyval.cadena=Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 66:
#line 185 "gramatica.y"
{ string s = "Int"; yyval.cadena = &s[0];}
break;
case 67:
#line 186 "gramatica.y"
{ string s = "Longint"; yyval.cadena = &s[0];}
break;
case 68:
#line 187 "gramatica.y"
{ string s = "Float"; yyval.cadena = &s[0];}
break;
case 69:
#line 191 "gramatica.y"
{Logger::write("Detecto sentencia OUT");}
break;
case 70:
#line 192 "gramatica.y"
{Logger::write("Error: SE ESPERABA OUT PREVIAMENTE PARA IMPRIMIR");}
break;
case 71:
#line 193 "gramatica.y"
{Logger::write("Error: SE ESPERABA CADENA EN LA SENTENCIA OUT");}
break;
#line 724 "y.tab.c"
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
