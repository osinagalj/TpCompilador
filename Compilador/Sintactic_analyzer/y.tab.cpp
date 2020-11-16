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
    7,    4,    4,    4,    4,    4,   10,   13,   13,    8,
    8,    8,    8,    8,   14,   16,   16,   15,   15,   12,
   12,   17,   18,   18,   18,   20,   21,   11,   11,   11,
   22,   19,   19,   23,   23,   23,   23,   23,   23,    9,
    9,    9,   24,   24,   24,   25,   25,   25,   25,   25,
    6,    6,    6,    5,    5,    5,
};
short yylen[] = {                                         2,
    1,    1,    2,    1,    1,    1,    2,    2,    1,    3,
    2,    4,    3,    1,    2,    2,    5,    3,    1,   14,
   14,   10,   10,    7,    2,    1,    1,    4,    2,    2,
    4,    4,    4,    2,    3,    3,    3,    8,    7,    7,
    1,    3,    2,    1,    1,    1,    1,    1,    1,    3,
    3,    1,    1,    3,    3,    1,    1,    2,    1,    2,
    1,    1,    1,    5,    4,    4,
};
short yydefred[] = {                                      0,
    0,   63,   62,   61,    0,    0,   41,    0,    0,    0,
    0,    2,    4,    5,    6,    0,    9,    0,   14,    0,
    0,    0,    0,    0,   11,    0,    0,    0,    0,    0,
   25,    0,   56,   57,   59,    0,    0,    0,    0,    0,
   53,    3,    0,    7,    8,   15,   16,    0,    0,   30,
    0,    0,   10,   13,    0,   19,    0,    0,    0,    0,
    0,    0,    0,   58,   60,   47,   46,   44,   45,   48,
   49,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   34,    0,   12,    0,    0,   32,    0,   66,   29,    0,
    0,   65,    0,    0,    0,    0,   31,   54,   55,    0,
   36,    0,    0,    0,   18,   17,   64,    0,    0,    0,
    0,    0,    0,    0,   33,    0,    0,   28,    0,    0,
    0,    0,    0,   37,    0,    0,    0,   39,   26,   27,
    0,    0,   24,    0,   40,    0,    0,    0,    0,   38,
    0,    0,    0,    0,    0,   22,    0,   23,    0,    0,
    0,    0,    0,    0,   21,   20,
};
short yydgoto[] = {                                      10,
   11,   12,   13,   14,   15,   16,   17,   18,   38,   19,
   20,   21,   57,   22,   62,  131,   23,   50,   39,   51,
  103,   24,   74,   40,   41,
};
short yysindex[] = {                                     50,
  -28,    0,    0,    0,  -20,  -10,    0,  -36,   60,    0,
   50,    0,    0,    0,    0, -243,    0,  -21,    0,   -6,
    8,    6,  -61,   28,    0, -243,  -44, -188,   88,  -38,
    0, -210,    0,    0,    0,   29, -207,   75,   30,   -5,
    0,    0,  -27,    0,    0,    0,    0, -210,   50,    0,
 -208,   88,    0,    0,  -24,    0,  -16,   33,   34,   17,
 -184,   -1,   19,    0,    0,    0,    0,    0,    0,    0,
    0,   88,   88,   88, -118,   88,   88,    3,  -40,  -46,
    0,   38,    0, -177,   24,    0,   25,    0,    0, -210,
 -194,    0,   -5,   -5,  -19,  -35,    0,    0,    0, -121,
    0,   50, -175, -115,    0,    0,    0, -170,   31,   50,
   35,   40,   50,  -31,    0,  -32,   50,    0, -166,  -22,
 -215, -164,  -13,    0,   50,   -4,   55,    0,    0,    0,
  -14,  -37,    0,    5,    0, -168,   50, -165,   50,    0,
   52,   14,   53,   23, -215,    0, -215,    0,   -8,    4,
   50,   50,   32,   41,    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  111,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   57,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   90,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   63,   83,   93,    0,    0,    0,    0,    0,
    0,    0,   70,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
  256,   18,    0,    0,    0,  -26,   -3,    0,  -17,    0,
    0,    0,    0,    0,   92, -106,    0,   61,  -18,    0,
    0,    0,    0,  -12,  -11,
};
#define YYTABLESIZE 408
short yytable[] = {                                       9,
   37,  113,   60,   32,   49,   61,  138,  117,    9,   55,
   58,   28,   44,   43,   54,   26,   26,    9,   72,   29,
   73,   61,   53,   72,   85,   73,    9,   84,   42,   30,
   25,   25,   27,   82,   83,    9,   77,   45,  149,   91,
  150,   76,   90,  100,    9,   48,   90,    2,    3,    4,
   64,   65,   46,    9,   80,   81,   95,  129,  130,   93,
   94,   49,    9,  108,   98,   99,   47,   52,   56,   63,
   75,    9,   89,   86,   87,   88,  102,   92,  104,  105,
    9,  109,  106,  107,  101,  139,  118,  110,  115,    9,
  125,  119,  127,  124,  132,  121,   42,   52,  136,   52,
  122,   52,  128,   50,   37,   50,  141,   50,  137,  143,
    1,  133,  145,  147,  151,   52,   52,   72,   52,   73,
  135,   50,   50,   51,   50,   51,  152,   51,   35,  140,
   43,   42,   37,   42,   71,   97,   70,   42,  146,   78,
   42,   51,   51,   42,   51,    0,    0,  148,    0,    0,
    0,   42,   96,  111,  112,  116,  155,    0,    0,   42,
    0,   42,    0,    0,    0,  156,    0,    0,    0,    0,
   42,   42,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   33,   34,   35,    0,    1,    2,    3,    4,
   31,    5,   59,    0,    6,    1,    2,    3,    4,    7,
    5,    8,    0,    6,    1,    2,    3,    4,    7,    5,
    8,    0,    6,    1,    2,    3,    4,    7,    5,    8,
    0,    6,    1,    2,    3,    4,    7,    5,    8,    0,
    6,    1,    2,    3,    4,    7,    5,    8,    0,    6,
    1,    2,    3,    4,    7,    5,    8,    0,    6,    1,
    2,    3,    4,    7,    5,    8,    0,    6,    1,    2,
    3,    4,    7,    5,    8,    0,    6,    1,    2,    3,
    4,    7,    5,    8,   79,    6,    1,    2,    3,    4,
    7,    5,    8,    0,    6,    0,   33,   34,   35,    7,
   36,    8,   52,   52,   52,   52,    0,    0,   50,   50,
   50,   50,    0,    0,    0,    0,    0,    0,    0,    0,
   66,   67,   68,   69,   33,   34,   35,    0,   51,   51,
   51,   51,    0,    0,    0,    0,    0,  114,    0,    0,
    0,    0,    0,    0,    0,  120,    0,    0,  123,    0,
    0,    0,  126,    0,    0,    0,    0,    0,    0,    0,
  134,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  142,    0,  144,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  153,  154,
};
short yycheck[] = {                                      40,
   45,  123,   41,   40,  123,   32,   44,  123,   40,   27,
   29,   40,   16,  257,   59,   44,   44,   40,   43,   40,
   45,   48,   26,   43,   41,   45,   40,   44,   11,   40,
   59,   59,   61,   52,   59,   40,   42,   59,  145,   41,
  147,   47,   44,   41,   40,   40,   44,  258,  259,  260,
  258,  259,   59,   40,  263,  264,   74,  273,  274,   72,
   73,  123,   40,   90,   76,   77,   59,   40,  257,   41,
   41,   40,  257,   41,   41,   59,  123,   59,   41,  257,
   40,  276,   59,   59,  125,  123,  257,  123,  264,   40,
  123,   61,  259,  125,  259,   61,   79,   41,   44,   43,
   61,   45,  125,   41,   45,   43,  275,   45,  123,  275,
    0,  125,   61,   61,  123,   59,   60,   43,   62,   45,
  125,   59,   60,   41,   62,   43,  123,   45,   59,  125,
   41,  114,   45,   41,   60,   75,   62,  120,  125,   48,
  123,   59,   60,  126,   62,   -1,   -1,  125,   -1,   -1,
   -1,  134,  271,  275,  276,  271,  125,   -1,   -1,  142,
   -1,  144,   -1,   -1,   -1,  125,   -1,   -1,   -1,   -1,
  153,  154,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  257,  258,  259,   -1,  257,  258,  259,  260,
  257,  262,  261,   -1,  265,  257,  258,  259,  260,  270,
  262,  272,   -1,  265,  257,  258,  259,  260,  270,  262,
  272,   -1,  265,  257,  258,  259,  260,  270,  262,  272,
   -1,  265,  257,  258,  259,  260,  270,  262,  272,   -1,
  265,  257,  258,  259,  260,  270,  262,  272,   -1,  265,
  257,  258,  259,  260,  270,  262,  272,   -1,  265,  257,
  258,  259,  260,  270,  262,  272,   -1,  265,  257,  258,
  259,  260,  270,  262,  272,   -1,  265,  257,  258,  259,
  260,  270,  262,  272,   49,  265,  257,  258,  259,  260,
  270,  262,  272,   -1,  265,   -1,  257,  258,  259,  270,
  261,  272,  266,  267,  268,  269,   -1,   -1,  266,  267,
  268,  269,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  266,  267,  268,  269,  257,  258,  259,   -1,  266,  267,
  268,  269,   -1,   -1,   -1,   -1,   -1,  102,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  110,   -1,   -1,  113,   -1,
   -1,   -1,  117,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  137,   -1,  139,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  151,  152,
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
"procedimiento : nombre_proc '(' lista_de_parametros ')' NA '=' LONGINT ',' SHADOWING '=' true_false '{' bloque_sentencia '}'",
"procedimiento : PROC '(' lista_de_parametros ')' NA '=' LONGINT ',' SHADOWING '=' true_false '{' bloque_sentencia '}'",
"procedimiento : nombre_proc '(' lista_de_parametros ')' SHADOWING '=' true_false '{' bloque_sentencia '}'",
"procedimiento : nombre_proc '(' lista_de_parametros ')' NA '=' LONGINT '{' bloque_sentencia '}'",
"procedimiento : nombre_proc '(' lista_de_parametros ')' '{' bloque_sentencia '}'",
"nombre_proc : PROC ID",
"true_false : TRUE",
"true_false : FALSE",
"lista_de_parametros : lista_de_parametros ',' tipo ID",
"lista_de_parametros : tipo ID",
"sentencia_if : encabezado_if cuerpo",
"sentencia_if : '(' condicion ')' cuerpo",
"encabezado_if : IF '(' condicion ')'",
"cuerpo : cuerpo_if ELSE cuerpo_else END_IF",
"cuerpo : cuerpo_if END_IF",
"cuerpo : cuerpo_if ELSE cuerpo_else",
"cuerpo_if : '{' bloque_sentencia '}'",
"cuerpo_else : '{' bloque_sentencia '}'",
"sentencia_while : inicio_while '(' condicion ')' LOOP '{' bloque_sentencia '}'",
"sentencia_while : '(' condicion ')' LOOP '{' bloque_sentencia '}'",
"sentencia_while : inicio_while '(' condicion ')' '{' bloque_sentencia '}'",
"inicio_while : WHILE",
"condicion : expresion comparador expresion",
"condicion : expresion comparador",
"comparador : EQUAL",
"comparador : DIFFERENT",
"comparador : LESS_OR_EQUAL",
"comparador : GREATER_OR_EQUAL",
"comparador : '>'",
"comparador : '<'",
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
						chekeosGeneracion::declare_variable_list(Lexical_analyzer::symbolTable,yyvsp[-1].cadena);
	      		      		}
break;
case 8:
#line 34 "gramatica.y"
{Logger::write("Declaracion de procedimiento"); chekeosGeneracion::shadowing = false;}
break;
case 9:
#line 35 "gramatica.y"
{Logger::write("Error: Falta el tipo en la lista de variables");}
break;
case 10:
#line 42 "gramatica.y"
{
		     				chekeosGeneracion::addVariable(yyvsp[-2].cadena);

                                                 chekeosGeneracion::setUse(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,"variable");}
break;
case 11:
#line 46 "gramatica.y"
{	chekeosGeneracion::addVariable(yyvsp[-1].cadena);
                             	chekeosGeneracion::setUse(Lexical_analyzer::symbolTable,yyvsp[-1].cadena,"variable");}
break;
case 12:
#line 51 "gramatica.y"
{Logger::write("Asignacion");

				  yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-3].cadena,yyvsp[-1].cadena);
	     			  if (chekeosGeneracion::getFlagPre() && !chekeosGeneracion::getFlagPost()){
				   /*modificar terceto incompleto ("=",factor,-) //agrego = al (-,factor,-)*/
				   /*chekeosGeneracion::completar_operando1(chekeosGeneracion::getNumber()-1,"=");*/
				   Terceto t = chekeosGeneracion::getTercetoIncompleto();
				   chekeosGeneracion::setFlagPost(false);
				   t.setOp("=");
				   t.setOp2(t.getOp1());
				   t.setOp1(yyvsp[-3].cadena);
				   chekeosGeneracion::insertar_terceto(t);
				   }
			       else if (!chekeosGeneracion::getFlagPre() && !chekeosGeneracion::getFlagPost()){
				   /*crear el terceto incompleto con el number de la expresion*/
				   /*chekeosGeneracion::insertar_terceto("=","["+to_string(chekeosGeneracion::getNumber())+"]","");*/
				   Terceto t("=",yyvsp[-3].cadena,"["+to_string(chekeosGeneracion::getNumber()-1)+"]");
				   chekeosGeneracion::insertar_terceto(t);
				   }
				   chekeosGeneracion::setFlagPre(false);
				   chekeosGeneracion::setFlagPost(false);



	      			  }
break;
case 13:
#line 76 "gramatica.y"
{Logger::write("Error: Asignacion vacia");}
break;
case 14:
#line 77 "gramatica.y"
{Logger::write("invocacion procedimiento");}
break;
case 15:
#line 78 "gramatica.y"
{Logger::write("sentencia while"); chekeosGeneracion::desconcatenarAmbitoAnonimo();}
break;
case 16:
#line 79 "gramatica.y"
{Logger::write("sentencia if");chekeosGeneracion::desconcatenarAmbitoAnonimo();}
break;
case 17:
#line 83 "gramatica.y"
{chekeosGeneracion::estaAlAlcance(Lexical_analyzer::symbolTable,yyvsp[-4].cadena);}
break;
case 18:
#line 87 "gramatica.y"
{chekeosGeneracion::estaAlAlcance(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 19:
#line 88 "gramatica.y"
{chekeosGeneracion::estaAlAlcance(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 20:
#line 93 "gramatica.y"
{Sintactic_actions::check_list_parametros();
	    											chekeosGeneracion::eliminarUltimoAmbito();
												chekeosGeneracion::insertar_terceto("Call",yyvsp[-13].cadena,"");
												if(chekeosGeneracion::cantProc > chekeosGeneracion::convertToI(yyvsp[-7].cadena)){
													cout<< "cantPorc: " + chekeosGeneracion::cantProc<< endl;
													cout<< "$7cadena: " + chekeosGeneracion::convertToString(yyvsp[-7].cadena)<< endl;
													Logger::write("Error: Tenes mas procedimientos de los que permite el NA");
												};
												chekeosGeneracion::cantProc++;
	    											}
break;
case 21:
#line 103 "gramatica.y"
{Logger::write("Error: FALTA ID");chekeosGeneracion::eliminarUltimoAmbito();

														cout<< "cantPorc: " + chekeosGeneracion::cantProc<< endl;
														cout<< "$7cadena: " + chekeosGeneracion::convertToString(yyvsp[-7].cadena)<< endl;

														if(chekeosGeneracion::cantProc > chekeosGeneracion::convertToI(yyvsp[-7].cadena)){
															Logger::write("Error: Tenes mas procedimientos de los que permite el NA");
															cout<< "cantPorc: " + chekeosGeneracion::cantProc<< endl;
															cout<< "$5cadena: " + chekeosGeneracion::convertToString(yyvsp[-7].cadena)<< endl;
														};
														chekeosGeneracion::cantProc++;
														}
break;
case 22:
#line 115 "gramatica.y"
{Logger::write("Error: FALTA ESPECIFICAR VALOR NA");chekeosGeneracion::eliminarUltimoAmbito();}
break;
case 23:
#line 116 "gramatica.y"
{Logger::write("Error: FALTA ESPECIFICAR VALOR SHADOWING");chekeosGeneracion::eliminarUltimoAmbito();

											cout<< "cantPorc: " + chekeosGeneracion::cantProc<< endl;
											cout<< "$7cadena: " + chekeosGeneracion::convertToString(yyvsp[-3].cadena)<< endl;
											if(chekeosGeneracion::cantProc > chekeosGeneracion::convertToI(yyvsp[-3].cadena)){
												Logger::write("Error: Tenes mas procedimientos de los que permite el NA");
												cout<< "cantPorc: " + chekeosGeneracion::cantProc<< endl;
												cout<< "$7cadena: " + chekeosGeneracion::convertToString(yyvsp[-3].cadena)<< endl;
											};
											chekeosGeneracion::cantProc++;
											}
break;
case 24:
#line 127 "gramatica.y"
{Logger::write("Error: FALTA ESPECIFICAR LOS VALORES DE NA Y SHADOWING");chekeosGeneracion::eliminarUltimoAmbito();

										}
break;
case 25:
#line 134 "gramatica.y"
{	yyval.cadena=yyvsp[0].cadena;
			chekeosGeneracion::setUse(Lexical_analyzer::symbolTable,yyvsp[0].cadena,"nombre_proc");
			chekeosGeneracion::concatenarAmbito(yyvsp[0].cadena);
			chekeosGeneracion::asignarAmbito(Lexical_analyzer::symbolTable,yyvsp[0].cadena);

			}
break;
case 26:
#line 143 "gramatica.y"
{ chekeosGeneracion::shadowing = true;}
break;
case 27:
#line 144 "gramatica.y"
{ chekeosGeneracion::shadowing = false;}
break;
case 28:
#line 148 "gramatica.y"
{Logger::write("lista_de_variables");
	 	       				       Sintactic_actions::number_of_parameters++;
	 	       				       chekeosGeneracion::setUse(Lexical_analyzer::symbolTable,yyvsp[0].cadena,"parametro");
						Lexical_analyzer::symbolTable->addType2(yyvsp[-1].cadena,yyvsp[0].cadena,chekeosGeneracion::ambito_actual);}
break;
case 29:
#line 152 "gramatica.y"
{Sintactic_actions::number_of_parameters++;
				chekeosGeneracion::setUse(Lexical_analyzer::symbolTable,yyvsp[0].cadena,"parametro");
				Lexical_analyzer::symbolTable->addType2(yyvsp[-1].cadena,yyvsp[0].cadena,chekeosGeneracion::ambito_actual);  }
break;
case 30:
#line 161 "gramatica.y"
{Logger::write("Sentencia IF");
	       				    }
break;
case 31:
#line 163 "gramatica.y"
{Logger::write("Error: FALTA EL IF");}
break;
case 32:
#line 166 "gramatica.y"
{chekeosGeneracion::concatenarAmbitoAnonimo("IF");}
break;
case 33:
#line 169 "gramatica.y"
{/*Desapilar*/
					    /*Completar terceto incompleto con el destino de la BI*/
					    chekeosGeneracion::modificar_terceto(chekeosGeneracion::desapilar(),0);
					    }
break;
case 34:
#line 173 "gramatica.y"
{/*Desapilar*/
			    /*Completar terceto incompleto con el destino de la BI*/
			    /*chekeosGeneracion::modificar_terceto(chekeosGeneracion::desapilar(),1);*/
			    }
break;
case 35:
#line 177 "gramatica.y"
{Logger::write("Error: FALTA EL END_IF");}
break;
case 36:
#line 180 "gramatica.y"
{/*desapilar*/
			/*completar terceto incompleto con el destino de la bf*/
			chekeosGeneracion::modificar_terceto(chekeosGeneracion::desapilar(),1);
			/*apilar el numero del terceto incompleto (apilo antes porque sino me paso de rango y no lo encuentra)*/
			chekeosGeneracion::apilar();
			/* crear terceto incompleto para la BI*/
			chekeosGeneracion::insertar_terceto("BI","","");
			}
break;
case 38:
#line 196 "gramatica.y"
{Logger::write("Sentencia WHILE");
         								/*(1)desapilar,*/
         								/*(2)completar terceto incompleto.*/
         								chekeosGeneracion::modificar_terceto(chekeosGeneracion::desapilar(),1);
         								/*(3)Desapilo direccion de inicio y creo el terceto BI al inicio*/
         								chekeosGeneracion::insertar_terceto("BI",to_string(chekeosGeneracion::desapilar()),"");
         								}
break;
case 39:
#line 203 "gramatica.y"
{Logger::write("Error: FALTA 'WHILE' EN LA SENTENCIA");}
break;
case 40:
#line 204 "gramatica.y"
{Logger::write("Error: FALTA 'LOOP' EN SENTENCIA WHILE");}
break;
case 41:
#line 208 "gramatica.y"
{chekeosGeneracion::concatenarAmbitoAnonimo("WHILE");
        	/*apilar terceto de inicio para saber la BI*/
        	chekeosGeneracion::apilar();
        }
break;
case 42:
#line 218 "gramatica.y"
{Logger::write("Condicion igual");
	   			     yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);
	   			     if (!chekeosGeneracion::getFlagPre() && chekeosGeneracion::getFlagPost()){
	   			     	Terceto t = chekeosGeneracion::getTercetoIncompleto(); /*descarto*/
	   			     	t = chekeosGeneracion::getTercetoIncompleto();
	   			     	cout<<t.getOp()<<endl;
	   			     	chekeosGeneracion::completar_operando3(t,yyvsp[0].cadena);
	   			     }
	   			     else if (chekeosGeneracion::getFlagPre() && chekeosGeneracion::getFlagPost()){
	   			        /*hay terceto incompleto pre-comparador y la derecha es un factor, pero se creó un terceto, lo descarto*/
	   			     	Terceto t = chekeosGeneracion::getTercetoIncompleto();
	   			     	t = chekeosGeneracion::getTercetoIncompleto();
					cout<<t.getOp()<<endl;
					chekeosGeneracion::completar_operando3(t,yyvsp[0].cadena);
	   			     }else if (chekeosGeneracion::getFlagPre() && !chekeosGeneracion::getFlagPost()){
					/*hay terceto incompleto pre-comparador y la derecha es un factor, pero se creó un terceto, lo descarto*/
					Terceto t = chekeosGeneracion::getTercetoIncompleto(); /*descarto*/
					t = chekeosGeneracion::getTercetoIncompleto();
					cout<<t.getOp()<<endl;
					chekeosGeneracion::completar_operando3(t,"["+to_string(chekeosGeneracion::getNumber()-1)+"]");
				     }
	   			     else{
	   			     	Terceto t = chekeosGeneracion::getTercetoIncompleto();
	   			     	cout<<t.getOp()<<endl;
					chekeosGeneracion::completar_operando3(t,"["+to_string(chekeosGeneracion::getNumber()-1)+"]");
	   			     }
	   			     chekeosGeneracion::setFlagPre(false);
	   			     chekeosGeneracion::setFlagPost(false);
	   			     chekeosGeneracion::apilar();
	   			     chekeosGeneracion::insertar_terceto("BF","["+to_string(chekeosGeneracion::getNumber()-1)+"]","");}
break;
case 43:
#line 248 "gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 44:
#line 251 "gramatica.y"
{if (chekeosGeneracion::getFlagPre() && !chekeosGeneracion::getFlagPost()){
		   /*modificar terceto incompleto ("==",factor,-) //agrego == al (-,factor,-)*/
		   /*chekeosGeneracion::completar_operando1(chekeosGeneracion::getNumber()-1,"==");*/
		   Terceto t = chekeosGeneracion::getTercetoIncompleto();
		   chekeosGeneracion::setFlagPost(true);
                   t.setOp("==");
		   chekeosGeneracion::insertarTercetoIncompleto(t);
		   }
	       else if (!chekeosGeneracion::getFlagPre() && !chekeosGeneracion::getFlagPost()){
		   /*crear el terceto incompleto con el number de la expresion*/
		   /*chekeosGeneracion::insertar_terceto("==","["+to_string(chekeosGeneracion::getNumber())+"]","");*/
		   Terceto t("==","["+to_string(chekeosGeneracion::getNumber()-1)+"]","-");
		   chekeosGeneracion::setFlagPost(true);
		   chekeosGeneracion::insertarTercetoIncompleto(t);
		   }
		}
break;
case 45:
#line 267 "gramatica.y"
{if (chekeosGeneracion::getFlagPre() && !chekeosGeneracion::getFlagPost()){
                  		   /*modificar terceto incompleto ("!=",factor,-) //agrego != al (-,factor,-)*/
                  		   /*chekeosGeneracion::completar_operando1(chekeosGeneracion::getNumber()-1,"!=");*/
                  		   Terceto t = chekeosGeneracion::getTercetoIncompleto();
                  		   chekeosGeneracion::setFlagPost(true);
                                     t.setOp("!=");
                  		   chekeosGeneracion::insertarTercetoIncompleto(t);
                  		   }
                  	       else if (!chekeosGeneracion::getFlagPre() && !chekeosGeneracion::getFlagPost()){
                  		   /*crear el terceto incompleto con el number de la expresion*/
                  		   /*chekeosGeneracion::insertar_terceto("!=","["+to_string(chekeosGeneracion::getNumber())+"]","");*/
                  		   Terceto t("!=","["+to_string(chekeosGeneracion::getNumber()-1)+"]","-");
                  		   chekeosGeneracion::setFlagPost(true);
                  		   chekeosGeneracion::insertarTercetoIncompleto(t);
                  		   }
                  		}
break;
case 46:
#line 283 "gramatica.y"
{if (chekeosGeneracion::getFlagPre() && !chekeosGeneracion::getFlagPost()){
                       		   /*modificar terceto incompleto ("<=",factor,-) //agrego <= al (-,factor,-)*/
                       		   /*chekeosGeneracion::completar_operando1(chekeosGeneracion::getNumber()-1,"<=");*/
                       		   Terceto t = chekeosGeneracion::getTercetoIncompleto();
                       		   chekeosGeneracion::setFlagPost(true);
                                          t.setOp("<=");
                       		   chekeosGeneracion::insertarTercetoIncompleto(t);
                       		   }
                       	       else if (!chekeosGeneracion::getFlagPre() && !chekeosGeneracion::getFlagPost()){
                       		   /*crear el terceto incompleto con el number de la expresion*/
                       		   /*chekeosGeneracion::insertar_terceto("<=","["+to_string(chekeosGeneracion::getNumber())+"]","");*/
                       		   Terceto t("<=","["+to_string(chekeosGeneracion::getNumber()-1)+"]","-");
                       		   chekeosGeneracion::setFlagPost(true);
                       		   chekeosGeneracion::insertarTercetoIncompleto(t);
                       		   }
                       		}
break;
case 47:
#line 299 "gramatica.y"
{if (chekeosGeneracion::getFlagPre() && !chekeosGeneracion::getFlagPost()){
                          		   /*modificar terceto incompleto (">=",factor,-) //agrego >= al (-,factor,-)*/
                          		   /*chekeosGeneracion::completar_operando1(chekeosGeneracion::getNumber()-1,">=");*/
                          		   Terceto t = chekeosGeneracion::getTercetoIncompleto();
                          		   chekeosGeneracion::setFlagPost(true);
                                             t.setOp(">=");
                          		   chekeosGeneracion::insertarTercetoIncompleto(t);
                          		   }
                          	       else if (!chekeosGeneracion::getFlagPre() && !chekeosGeneracion::getFlagPost()){
                          		   /*crear el terceto incompleto con el number de la expresion*/
                          		   /*chekeosGeneracion::insertar_terceto(">=","["+to_string(chekeosGeneracion::getNumber())+"]","");*/
                          		   Terceto t(">=","["+to_string(chekeosGeneracion::getNumber()-1)+"]","-");
                          		   chekeosGeneracion::setFlagPost(true);
                          		   chekeosGeneracion::insertarTercetoIncompleto(t);
                          		   }
                          		}
break;
case 48:
#line 315 "gramatica.y"
{if (chekeosGeneracion::getFlagPre() && !chekeosGeneracion::getFlagPost()){
             		   /*modificar terceto incompleto (">",factor,-) //agrego > al (-,factor,-)*/
             		   /*chekeosGeneracion::completar_operando1(chekeosGeneracion::getNumber()-1,">");*/
             		   Terceto t = chekeosGeneracion::getTercetoIncompleto();
             		   chekeosGeneracion::setFlagPost(true);
                                t.setOp(">");
             		   chekeosGeneracion::insertarTercetoIncompleto(t);
             		   }
             	       else if (!chekeosGeneracion::getFlagPre() && !chekeosGeneracion::getFlagPost()){
             		   /*crear el terceto incompleto con el number de la expresion*/
             		   /*chekeosGeneracion::insertar_terceto(">","["+to_string(chekeosGeneracion::getNumber())+"]","");*/
             		   Terceto t(">","["+to_string(chekeosGeneracion::getNumber()-1)+"]","-");
             		   chekeosGeneracion::setFlagPost(true);
             		   chekeosGeneracion::insertarTercetoIncompleto(t);
             		   }
             		}
break;
case 49:
#line 331 "gramatica.y"
{if (chekeosGeneracion::getFlagPre() && !chekeosGeneracion::getFlagPost()){
             		   /*modificar terceto incompleto ("<",factor,-) //agrego < al (-,factor,-)*/
             		   /*chekeosGeneracion::completar_operando1(chekeosGeneracion::getNumber()-1,"<");*/
             		   Terceto t = chekeosGeneracion::getTercetoIncompleto();
             		   chekeosGeneracion::setFlagPost(true);
                                t.setOp("<");
             		   chekeosGeneracion::insertarTercetoIncompleto(t);
             		   }
             	       else if (!chekeosGeneracion::getFlagPre() && !chekeosGeneracion::getFlagPost()){
             		   /*crear el terceto incompleto con el number de la expresion*/
             		   /*chekeosGeneracion::insertar_terceto("<","["+to_string(chekeosGeneracion::getNumber())+"]","");*/
             		   Terceto t("<","["+to_string(chekeosGeneracion::getNumber()-1)+"]","-");
             		   chekeosGeneracion::setFlagPost(true);
             		   chekeosGeneracion::insertarTercetoIncompleto(t);
             		   }
             		}
break;
case 50:
#line 352 "gramatica.y"
{Logger::write("suma");
				  yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);

                                  if (!chekeosGeneracion::getFlagPre() && chekeosGeneracion::getFlagPost()){
                                  					/*completar tercerto de la pila*/
                                  					Terceto t = chekeosGeneracion::getTercetoIncompleto();
                                  					t = chekeosGeneracion::getTercetoIncompleto();
                                  					t.setOp("+");
                                  					t.setOp2(yyvsp[0].cadena);
                                  					chekeosGeneracion::setFlagPost(false);
                                  					chekeosGeneracion::insertar_terceto(t);
                                  					/*chekeosGeneracion::completar_terceto(chekeosGeneracion::getNumber()-1,"+",$3.cadena);*/
                                  					}
                                  			  	else if (chekeosGeneracion::getFlagPre() && !chekeosGeneracion::getFlagPost()){
                                  					/*completar tercerto de la pila*/
                                  					Terceto t = chekeosGeneracion::getTercetoIncompleto();
                                  					t.setOp("+");
                                  					t.setOp2(yyvsp[0].cadena);
                                  					chekeosGeneracion::setFlagPre(false);
                                  					chekeosGeneracion::insertar_terceto(t);
                                  					/*chekeosGeneracion::completar_terceto(chekeosGeneracion::getNumber()-1,"+",$3.cadena);*/
                                  					}
                                  				      else if (chekeosGeneracion::getFlagPre() && chekeosGeneracion::getFlagPost()) {
                                  						/*completar tercerto de la pila*/
                                  						Terceto t = chekeosGeneracion::getTercetoIncompleto();
                                  						t.setOp("+");
                                  						t.setOp2(yyvsp[0].cadena);
                                  						chekeosGeneracion::setFlagPost(false);
                                  						chekeosGeneracion::insertar_terceto(t);
                                  						/*chekeosGeneracion::completar_terceto(chekeosGeneracion::getNumber()-1,"+",$3.cadena);*/
                                  						}
                                  						 else if (!chekeosGeneracion::getFlagPre() && !chekeosGeneracion::getFlagPost()){
                                  							/*insertar el terceto con el number del anterior*/
                                  							chekeosGeneracion::insertar_terceto("+","["+to_string(chekeosGeneracion::getNumber()-1)+"]",yyvsp[0].cadena);}


	   			}
break;
case 51:
#line 389 "gramatica.y"
{Logger::write("resta");
	  		 	  yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);
			          if (!chekeosGeneracion::getFlagPre() && chekeosGeneracion::getFlagPost()){
				  	/*completar tercerto de la pila*/
				  	Terceto t = chekeosGeneracion::getTercetoIncompleto();
				  	t = chekeosGeneracion::getTercetoIncompleto();
					t.setOp("-");
					t.setOp2(yyvsp[0].cadena);
					chekeosGeneracion::setFlagPost(false);
					chekeosGeneracion::insertar_terceto(t);
					/*chekeosGeneracion::completar_terceto(chekeosGeneracion::getNumber()-1,"-",$3.cadena);*/
					}
			      	  else if (chekeosGeneracion::getFlagPre() && !chekeosGeneracion::getFlagPost()) {
			      	  		/*completar tercerto de la pila*/
						Terceto t = chekeosGeneracion::getTercetoIncompleto();
						t.setOp("-");
						t.setOp2(yyvsp[0].cadena);
						chekeosGeneracion::setFlagPre(false);
						chekeosGeneracion::insertar_terceto(t);
						/*chekeosGeneracion::completar_terceto(chekeosGeneracion::getNumber()-1,"-",$3.cadena);*/
					}
					else if (chekeosGeneracion::getFlagPre() && chekeosGeneracion::getFlagPost()) {
						/*completar tercerto de la pila*/
						Terceto t = chekeosGeneracion::getTercetoIncompleto();
						t.setOp("-");
						t.setOp2(yyvsp[0].cadena);
						chekeosGeneracion::setFlagPost(false);
						chekeosGeneracion::insertar_terceto(t);
						/*chekeosGeneracion::completar_terceto(chekeosGeneracion::getNumber()-1,"-",$3.cadena);*/
						}
						 else if (!chekeosGeneracion::getFlagPre() && !chekeosGeneracion::getFlagPost()){
							/*insertar el terceto con el number del anterior*/
							chekeosGeneracion::insertar_terceto("-","["+to_string(chekeosGeneracion::getNumber()-1)+"]",yyvsp[0].cadena);}
				}
break;
case 52:
#line 423 "gramatica.y"
{yyval.cadena = yyvsp[0].cadena;}
break;
case 53:
#line 428 "gramatica.y"
{ yyval.cadena= yyvsp[0].cadena;
	         if(!chekeosGeneracion::getFlagPre() && !chekeosGeneracion::getFlagPost()){
			 /*SETEAR VARIABLE PRECOMPARADOR*/
			 chekeosGeneracion::setFlagPre(true);
			 /*insertar tercerto incompleto (-,factor,-)*/
			 Terceto t("-",yyvsp[0].cadena,"-");
			 chekeosGeneracion::insertarTercetoIncompleto(t);
			 /*chekeosGeneracion::insertar_terceto("",$1.cadena,"");*/
		 }else if(!chekeosGeneracion::getFlagPre() && chekeosGeneracion::getFlagPost()){
			/*SETEAR VARIABLE PRECOMPARADOR*/
			 /*insertar tercerto incompleto (-,factor,-)*/
			 Terceto t("-",yyvsp[0].cadena,"-");
			 chekeosGeneracion::insertarTercetoIncompleto(t);
			 /*chekeosGeneracion::insertar_terceto("",$1.cadena,"");*/
			}
			else if(chekeosGeneracion::getFlagPre() && chekeosGeneracion::getFlagPost()){
                        			/*SETEAR VARIABLE PRECOMPARADOR*/
                        			 /*insertar tercerto incompleto (-,factor,-)*/
                        			 Terceto t("-",yyvsp[0].cadena,"-");
						chekeosGeneracion::setFlagPre(false);
                        			 chekeosGeneracion::insertarTercetoIncompleto(t);
                        			 /*chekeosGeneracion::insertar_terceto("",$1.cadena,"");*/
                        			}
	 }
break;
case 54:
#line 452 "gramatica.y"
{ Sintactic_actions::check_division_zero(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
			      yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);
			  if (!chekeosGeneracion::getFlagPre() && chekeosGeneracion::getFlagPost()){
				/*completar tercerto de la pila*/
				Terceto t = chekeosGeneracion::getTercetoIncompleto();
				t.setOp("/");
				t.setOp2(yyvsp[0].cadena);
				chekeosGeneracion::setFlagPost(false);
				chekeosGeneracion::insertar_terceto(t);
				/*chekeosGeneracion::completar_terceto(chekeosGeneracion::getNumber()-1,"/",$3.cadena);*/
				}
			  else if (chekeosGeneracion::getFlagPre() && !chekeosGeneracion::getFlagPost()) {
					/*completar tercerto de la pila*/
					Terceto t = chekeosGeneracion::getTercetoIncompleto();
					t.setOp("/");
					t.setOp2(yyvsp[0].cadena);
					chekeosGeneracion::setFlagPre(false);
					chekeosGeneracion::insertar_terceto(t);
					/*chekeosGeneracion::completar_terceto(chekeosGeneracion::getNumber()-1,"/",$3.cadena);*/
				}
				else if (chekeosGeneracion::getFlagPre() && chekeosGeneracion::getFlagPost()) {
					/*completar tercerto de la pila*/
					Terceto t = chekeosGeneracion::getTercetoIncompleto();
					t.setOp("/");
					t.setOp2(yyvsp[0].cadena);
					chekeosGeneracion::setFlagPost(false);
					chekeosGeneracion::insertar_terceto(t);
					/*chekeosGeneracion::completar_terceto(chekeosGeneracion::getNumber()-1,"/",$3.cadena);*/
					}
					 else if (!chekeosGeneracion::getFlagPre() && !chekeosGeneracion::getFlagPost()){
						/*insertar el terceto con el number del anterior*/
						chekeosGeneracion::insertar_terceto("/","["+to_string(chekeosGeneracion::getNumber()-1)+"]",yyvsp[0].cadena);}
			      }
break;
case 55:
#line 486 "gramatica.y"
{ Sintactic_actions::check_division_zero(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
			      yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);
			      if (!chekeosGeneracion::getFlagPre() && chekeosGeneracion::getFlagPost()){
				/*completar tercerto de la pila*/
				Terceto t = chekeosGeneracion::getTercetoIncompleto();
				t.setOp("*");
				t.setOp2(yyvsp[0].cadena);
				chekeosGeneracion::setFlagPost(false);
				chekeosGeneracion::insertar_terceto(t);
				/*chekeosGeneracion::completar_terceto(chekeosGeneracion::getNumber()-1,"*",$3.cadena);*/
				}
			  else if (chekeosGeneracion::getFlagPre() && !chekeosGeneracion::getFlagPost()) {
					/*completar tercerto de la pila*/
					Terceto t = chekeosGeneracion::getTercetoIncompleto();
					t.setOp("*");
					t.setOp2(yyvsp[0].cadena);
					chekeosGeneracion::setFlagPre(false);
					chekeosGeneracion::insertar_terceto(t);
					/*chekeosGeneracion::completar_terceto(chekeosGeneracion::getNumber()-1,"*",$3.cadena);*/
				}
				else if (chekeosGeneracion::getFlagPre() && chekeosGeneracion::getFlagPost()) {
					/*completar tercerto de la pila*/
					Terceto t = chekeosGeneracion::getTercetoIncompleto();
					t.setOp("*");
					t.setOp2(yyvsp[0].cadena);
					chekeosGeneracion::setFlagPost(false);
					chekeosGeneracion::insertar_terceto(t);
					/*chekeosGeneracion::completar_terceto(chekeosGeneracion::getNumber()-1,"*",$3.cadena);*/
					}
					 else if (!chekeosGeneracion::getFlagPre() && !chekeosGeneracion::getFlagPost()){
						/*insertar el terceto con el number del anterior*/
						chekeosGeneracion::insertar_terceto("*","["+to_string(chekeosGeneracion::getNumber()-1)+"]",yyvsp[0].cadena);}
			      }
break;
case 56:
#line 522 "gramatica.y"
{
	 	  yyval.cadena= yyvsp[0].cadena;
	 	  chekeosGeneracion::estaAlAlcance(Lexical_analyzer::symbolTable,yyvsp[0].cadena);

	 	  }
break;
case 57:
#line 527 "gramatica.y"
{yyval.cadena= yyvsp[0].cadena;
		chekeosGeneracion::estaAlAlcance(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
		}
break;
case 58:
#line 530 "gramatica.y"
{chekeosGeneracion::estaAlAlcance(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
	yyval.cadena= Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,yyvsp[0].cadena);

		}
break;
case 59:
#line 534 "gramatica.y"
{ chekeosGeneracion::estaAlAlcance(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
	Sintactic_actions::check_limit(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
		   yyval.cadena= yyvsp[0].cadena;}
break;
case 60:
#line 537 "gramatica.y"
{ chekeosGeneracion::estaAlAlcance(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
        	yyval.cadena=Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 61:
#line 542 "gramatica.y"
{ string s = "Int"; yyval.cadena = &s[0];}
break;
case 62:
#line 543 "gramatica.y"
{ string s = "Longint"; yyval.cadena = &s[0];}
break;
case 63:
#line 544 "gramatica.y"
{ string s = "Float"; yyval.cadena = &s[0];}
break;
case 64:
#line 548 "gramatica.y"
{Logger::write("Detecto sentencia OUT");
	  			chekeosGeneracion::insertar_terceto("OUT",yyvsp[-2].cadena,"");	}
break;
case 65:
#line 550 "gramatica.y"
{Logger::write("Error: SE ESPERABA OUT PREVIAMENTE PARA IMPRIMIR");}
break;
case 66:
#line 551 "gramatica.y"
{Logger::write("Error: SE ESPERABA CADENA EN LA SENTENCIA OUT");}
break;
#line 1074 "y.tab.c"
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
