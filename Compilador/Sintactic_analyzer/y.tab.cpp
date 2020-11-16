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
   22,   19,   19,   19,   19,   19,   19,   19,   19,   19,
   19,   19,    9,    9,    9,   23,   23,   23,   24,   24,
   24,   24,   24,    6,    6,    6,    5,    5,    5,
};
short yylen[] = {                                         2,
    1,    1,    2,    1,    1,    1,    2,    2,    1,    3,
    2,    4,    3,    1,    2,    2,    5,    3,    1,   14,
   14,   10,   10,    7,    2,    1,    1,    4,    2,    2,
    4,    4,    4,    2,    3,    3,    3,    8,    7,    7,
    1,    3,    2,    3,    2,    3,    2,    3,    3,    2,
    3,    2,    3,    3,    1,    1,    3,    3,    1,    1,
    2,    1,    2,    1,    1,    1,    5,    4,    4,
};
short yydefred[] = {                                      0,
    0,   66,   65,   64,    0,    0,   41,    0,    0,    0,
    0,    2,    4,    5,    6,    0,    9,    0,   14,    0,
    0,    0,    0,    0,   11,    0,    0,    0,    0,    0,
   25,    0,   59,   60,   62,    0,    0,    0,    0,    0,
   56,    3,    0,    7,    8,   15,   16,    0,    0,   30,
    0,    0,   10,   13,    0,   19,    0,    0,    0,    0,
    0,    0,    0,   61,   63,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   34,
    0,   12,    0,    0,   32,    0,   69,   29,    0,    0,
   68,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   31,   57,   58,    0,   36,    0,    0,    0,   18,   17,
   67,    0,    0,    0,    0,    0,    0,    0,   33,    0,
    0,   28,    0,    0,    0,    0,    0,   37,    0,    0,
    0,   39,   26,   27,    0,    0,   24,    0,   40,    0,
    0,    0,    0,   38,    0,    0,    0,    0,    0,   22,
    0,   23,    0,    0,    0,    0,    0,    0,   21,   20,
};
short yydgoto[] = {                                      10,
   11,   12,   13,   14,   15,   16,   17,   18,   38,   19,
   20,   21,   57,   22,   62,  135,   23,   50,   39,   51,
  107,   24,   40,   41,
};
short yysindex[] = {                                     50,
  -24,    0,    0,    0,   13,   15,    0,  -36,   60,    0,
   50,    0,    0,    0,    0, -199,    0,    2,    0,    3,
    6,   19,  -59,   26,    0, -199,  -44, -190,   88,  -38,
    0, -236,    0,    0,    0,   27, -245,   75,   29,  -16,
    0,    0,  -34,    0,    0,    0,    0, -236,   50,    0,
 -216,   88,    0,    0,  -26,    0,   -3,   30,   38,   21,
 -175,   -2,   24,    0,    0,   88,   88,   88,   88,   88,
   88,   88,   88, -118,   88,   88,   -1,  -40,  -39,    0,
   46,    0, -169,   33,    0,   34,    0,    0, -236, -187,
    0,    1,    1,    1,    1,    1,    1,  -16,  -16,  -32,
    0,    0,    0, -121,    0,   50, -168, -115,    0,    0,
    0, -162,   36,   50,   40,   48,   50,  -31,    0,  -12,
   50,    0, -160,  -22, -224, -152,  -13,    0,   50,   -4,
   66,    0,    0,    0,  -10,  -37,    0,    5,    0, -161,
   50, -146,   50,    0,   54,   14,   70,   23, -224,    0,
 -224,    0,    9,   11,   50,   50,   32,   41,    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  136,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   57,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   97,   99,    0,  100,  103,
  105,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  106,  108,  109,  110,  111,  117,   63,   83,    0,
    0,    0,    0,    0,    0,    0,  101,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
  247,   49,    0,    0,    0,  -20,   -5,    0,    7,    0,
    0,    0,    0,    0,  113, -119,    0,   85,  -23,    0,
    0,    0,  -21,  -19,
};
#define YYTABLESIZE 403
short yytable[] = {                                       9,
   37,  117,   60,   32,   49,   58,  142,  121,    9,   26,
   44,   61,   64,   65,   54,   28,   72,    9,   73,   26,
   53,    2,    3,    4,   25,   76,    9,   61,   81,  153,
   75,  154,   82,   55,   25,    9,   27,   84,   90,  104,
   83,   89,   89,   72,    9,   73,   79,   80,  133,  134,
   98,   99,   29,    9,   30,  102,  103,   43,   48,   42,
   45,   46,    9,   49,   47,   52,   56,   63,  112,   74,
   85,    9,   92,   93,   94,   95,   96,   97,   86,   87,
    9,   88,   91,  106,  105,  143,  108,  109,  113,    9,
  114,  110,  111,  128,  122,  119,  123,   55,  131,   55,
  125,   55,  132,   53,   37,   53,  136,   53,  126,  140,
  129,  137,  141,  145,  149,   55,   55,   72,   55,   73,
  139,   53,   53,   54,   53,   54,   42,   54,  147,  144,
  151,  155,   37,  156,   71,    1,   70,   47,  150,   45,
   43,   54,   54,   50,   54,   52,   48,  152,   46,   42,
   44,   49,  100,  115,  116,  120,  159,   51,  101,   35,
   77,    0,    0,    0,    0,  160,   42,    0,    0,    0,
    0,    0,   42,    0,    0,   42,    0,    0,   42,    0,
    0,    0,    0,    0,    0,    0,   42,    0,    0,    0,
    0,    0,    0,    0,   42,    0,   42,    0,    0,    0,
    0,    0,    0,    0,    0,   42,   42,    0,    0,    0,
    0,    0,   33,   34,   35,    0,    1,    2,    3,    4,
   31,    5,   59,    0,    6,    1,    2,    3,    4,    7,
    5,    8,    0,    6,    1,    2,    3,    4,    7,    5,
    8,    0,    6,    1,    2,    3,    4,    7,    5,    8,
    0,    6,    1,    2,    3,    4,    7,    5,    8,    0,
    6,    1,    2,    3,    4,    7,    5,    8,    0,    6,
    1,    2,    3,    4,    7,    5,    8,    0,    6,    1,
    2,    3,    4,    7,    5,    8,    0,    6,    1,    2,
    3,    4,    7,    5,    8,   78,    6,    1,    2,    3,
    4,    7,    5,    8,    0,    6,    1,    2,    3,    4,
    7,    5,    8,    0,    6,    0,   33,   34,   35,    7,
   36,    8,   55,   55,   55,   55,    0,    0,   53,   53,
   53,   53,    0,    0,    0,    0,    0,    0,    0,    0,
   66,   67,   68,   69,   33,   34,   35,    0,   54,   54,
   54,   54,  118,    0,    0,    0,    0,    0,    0,    0,
  124,    0,    0,  127,    0,    0,    0,  130,    0,    0,
    0,    0,    0,    0,    0,  138,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  146,    0,  148,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  157,  158,
};
short yycheck[] = {                                      40,
   45,  123,   41,   40,  123,   29,   44,  123,   40,   44,
   16,   32,  258,  259,   59,   40,   43,   40,   45,   44,
   26,  258,  259,  260,   59,   42,   40,   48,   52,  149,
   47,  151,   59,   27,   59,   40,   61,   41,   41,   41,
   44,   44,   44,   43,   40,   45,  263,  264,  273,  274,
   72,   73,   40,   40,   40,   75,   76,  257,   40,   11,
   59,   59,   40,  123,   59,   40,  257,   41,   89,   41,
   41,   40,   66,   67,   68,   69,   70,   71,   41,   59,
   40,  257,   59,  123,  125,  123,   41,  257,  276,   40,
  123,   59,   59,  125,  257,  264,   61,   41,  259,   43,
   61,   45,  125,   41,   45,   43,  259,   45,   61,   44,
  123,  125,  123,  275,   61,   59,   60,   43,   62,   45,
  125,   59,   60,   41,   62,   43,   78,   45,  275,  125,
   61,  123,   45,  123,   60,    0,   62,   41,  125,   41,
   41,   59,   60,   41,   62,   41,   41,  125,   41,   41,
   41,   41,  271,  275,  276,  271,  125,   41,   74,   59,
   48,   -1,   -1,   -1,   -1,  125,  118,   -1,   -1,   -1,
   -1,   -1,  124,   -1,   -1,  127,   -1,   -1,  130,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  138,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  146,   -1,  148,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  157,  158,   -1,   -1,   -1,
   -1,   -1,  257,  258,  259,   -1,  257,  258,  259,  260,
  257,  262,  261,   -1,  265,  257,  258,  259,  260,  270,
  262,  272,   -1,  265,  257,  258,  259,  260,  270,  262,
  272,   -1,  265,  257,  258,  259,  260,  270,  262,  272,
   -1,  265,  257,  258,  259,  260,  270,  262,  272,   -1,
  265,  257,  258,  259,  260,  270,  262,  272,   -1,  265,
  257,  258,  259,  260,  270,  262,  272,   -1,  265,  257,
  258,  259,  260,  270,  262,  272,   -1,  265,  257,  258,
  259,  260,  270,  262,  272,   49,  265,  257,  258,  259,
  260,  270,  262,  272,   -1,  265,  257,  258,  259,  260,
  270,  262,  272,   -1,  265,   -1,  257,  258,  259,  270,
  261,  272,  266,  267,  268,  269,   -1,   -1,  266,  267,
  268,  269,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  266,  267,  268,  269,  257,  258,  259,   -1,  266,  267,
  268,  269,  106,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  114,   -1,   -1,  117,   -1,   -1,   -1,  121,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  129,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  141,   -1,  143,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  155,  156,
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
	      			  chekeosGeneracion::insertar_terceto("=",yyvsp[-3].cadena,yyvsp[-1].cadena);
				  yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-3].cadena,yyvsp[-1].cadena);
	      			  }
break;
case 13:
#line 55 "gramatica.y"
{Logger::write("Error: Asignacion vacia");}
break;
case 14:
#line 56 "gramatica.y"
{Logger::write("invocacion procedimiento");}
break;
case 15:
#line 57 "gramatica.y"
{Logger::write("sentencia while"); chekeosGeneracion::desconcatenarAmbitoAnonimo();}
break;
case 16:
#line 58 "gramatica.y"
{Logger::write("sentencia if");chekeosGeneracion::desconcatenarAmbitoAnonimo();}
break;
case 17:
#line 62 "gramatica.y"
{chekeosGeneracion::estaAlAlcance(Lexical_analyzer::symbolTable,yyvsp[-4].cadena);}
break;
case 18:
#line 66 "gramatica.y"
{chekeosGeneracion::estaAlAlcance(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 19:
#line 67 "gramatica.y"
{chekeosGeneracion::estaAlAlcance(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 20:
#line 71 "gramatica.y"
{Sintactic_actions::check_list_parametros();
	    											chekeosGeneracion::eliminarUltimoAmbito();}
break;
case 21:
#line 74 "gramatica.y"
{Logger::write("Error: FALTA ID");chekeosGeneracion::eliminarUltimoAmbito();}
break;
case 22:
#line 75 "gramatica.y"
{Logger::write("Error: FALTA ESPECIFICAR VALOR NA");chekeosGeneracion::eliminarUltimoAmbito();}
break;
case 23:
#line 76 "gramatica.y"
{Logger::write("Error: FALTA ESPECIFICAR VALOR SHADOWING");chekeosGeneracion::eliminarUltimoAmbito();}
break;
case 24:
#line 77 "gramatica.y"
{Logger::write("Error: FALTA ESPECIFICAR LOS VALORES DE NA Y SHADOWING");chekeosGeneracion::eliminarUltimoAmbito();}
break;
case 25:
#line 80 "gramatica.y"
{	chekeosGeneracion::setUse(Lexical_analyzer::symbolTable,yyvsp[0].cadena,"nombre_proc");
			chekeosGeneracion::concatenarAmbito(yyvsp[0].cadena);
			chekeosGeneracion::asignarAmbito(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
			}
break;
case 26:
#line 87 "gramatica.y"
{ chekeosGeneracion::shadowing = true;}
break;
case 27:
#line 88 "gramatica.y"
{ chekeosGeneracion::shadowing = false;}
break;
case 28:
#line 92 "gramatica.y"
{Logger::write("lista_de_variables");
	 	       				       Sintactic_actions::number_of_parameters++;
	 	       				       chekeosGeneracion::setUse(Lexical_analyzer::symbolTable,yyvsp[0].cadena,"parametro");
						Lexical_analyzer::symbolTable->addType2(yyvsp[-1].cadena,yyvsp[0].cadena,chekeosGeneracion::ambito_actual);}
break;
case 29:
#line 96 "gramatica.y"
{Sintactic_actions::number_of_parameters++;
				chekeosGeneracion::setUse(Lexical_analyzer::symbolTable,yyvsp[0].cadena,"parametro");
				Lexical_analyzer::symbolTable->addType2(yyvsp[-1].cadena,yyvsp[0].cadena,chekeosGeneracion::ambito_actual);  }
break;
case 30:
#line 105 "gramatica.y"
{Logger::write("Sentencia IF");
	       				    }
break;
case 31:
#line 107 "gramatica.y"
{Logger::write("Error: FALTA EL IF");}
break;
case 32:
#line 110 "gramatica.y"
{chekeosGeneracion::concatenarAmbitoAnonimo("IF");}
break;
case 33:
#line 113 "gramatica.y"
{/*Desapilar*/
					    /*Completar terceto incompleto con el destino de la BI*/
					    chekeosGeneracion::modificar_terceto(chekeosGeneracion::desapilar(),0);
					    }
break;
case 34:
#line 117 "gramatica.y"
{/*Desapilar*/
			    /*Completar terceto incompleto con el destino de la BI*/
			    /*chekeosGeneracion::modificar_terceto(chekeosGeneracion::desapilar(),1);*/
			    }
break;
case 35:
#line 121 "gramatica.y"
{Logger::write("Error: FALTA EL END_IF");}
break;
case 36:
#line 124 "gramatica.y"
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
#line 140 "gramatica.y"
{Logger::write("Sentencia WHILE");
         								/*(1)desapilar,*/
         								/*(2)completar terceto incompleto.*/
         								chekeosGeneracion::modificar_terceto(chekeosGeneracion::desapilar(),1);
         								/*(3)Desapilo direccion de inicio y creo el terceto BI al inicio*/
         								chekeosGeneracion::insertar_terceto("BI",to_string(chekeosGeneracion::desapilar()),"");
         								}
break;
case 39:
#line 147 "gramatica.y"
{Logger::write("Error: FALTA 'WHILE' EN LA SENTENCIA");}
break;
case 40:
#line 148 "gramatica.y"
{Logger::write("Error: FALTA 'LOOP' EN SENTENCIA WHILE");}
break;
case 41:
#line 152 "gramatica.y"
{chekeosGeneracion::concatenarAmbitoAnonimo("WHILE");
        	/*apilar terceto de inicio para saber la BI*/
        	chekeosGeneracion::apilar();
        }
break;
case 42:
#line 161 "gramatica.y"
{Logger::write("Condicion igual");
	   			     yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);
				     chekeosGeneracion::insertar_terceto("==",yyvsp[-2].cadena,yyvsp[0].cadena);
	   			     chekeosGeneracion::apilar();
	   			     chekeosGeneracion::insertar_terceto("BF",to_string(chekeosGeneracion::getNumber()-1),"");}
break;
case 43:
#line 166 "gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 44:
#line 167 "gramatica.y"
{Logger::write("Condicion distinto");
	  				  yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);
	  				  chekeosGeneracion::insertar_terceto("!=",yyvsp[-2].cadena,yyvsp[0].cadena);
	  				  chekeosGeneracion::apilar();
				          chekeosGeneracion::insertar_terceto("BF",to_string(chekeosGeneracion::getNumber()-1),"");}
break;
case 45:
#line 172 "gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 46:
#line 173 "gramatica.y"
{Logger::write("Condicion menorigual");
	  				      yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);
	  				      chekeosGeneracion::insertar_terceto("<=",yyvsp[-2].cadena,yyvsp[0].cadena);
	  				      chekeosGeneracion::apilar();
					      chekeosGeneracion::insertar_terceto("BF",to_string(chekeosGeneracion::getNumber()-1),"");}
break;
case 47:
#line 178 "gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 48:
#line 179 "gramatica.y"
{Logger::write("Condicion mayorIgual");
	  					yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);
	  					chekeosGeneracion::insertar_terceto(">=",yyvsp[-2].cadena,yyvsp[0].cadena);
	  					chekeosGeneracion::apilar();
					        chekeosGeneracion::insertar_terceto("BF",to_string(chekeosGeneracion::getNumber()-1),"");}
break;
case 49:
#line 184 "gramatica.y"
{Logger::write("Condicion de mayor");
	  			    yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);
	  			    chekeosGeneracion::insertar_terceto(">",yyvsp[-2].cadena,yyvsp[0].cadena);
	  			    chekeosGeneracion::apilar();
				    chekeosGeneracion::insertar_terceto("BF",to_string(chekeosGeneracion::getNumber()-1),"");}
break;
case 50:
#line 189 "gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 51:
#line 190 "gramatica.y"
{Logger::write("Condicion de menor");
                                    yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);
                                    chekeosGeneracion::insertar_terceto("<",yyvsp[-2].cadena,yyvsp[0].cadena);
                                    chekeosGeneracion::apilar();
				    chekeosGeneracion::insertar_terceto("BF",to_string(chekeosGeneracion::getNumber()-1),"");}
break;
case 52:
#line 195 "gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 53:
#line 201 "gramatica.y"
{Logger::write("suma");
				  yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);
	   			}
break;
case 54:
#line 204 "gramatica.y"
{Logger::write("resta");
	  		 	  yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);}
break;
case 55:
#line 206 "gramatica.y"
{yyval.cadena = yyvsp[0].cadena;}
break;
case 56:
#line 211 "gramatica.y"
{yyval.cadena = yyvsp[0].cadena; }
break;
case 57:
#line 212 "gramatica.y"
{ 	/*chekeosGeneracion::estaAlAlcance(Lexical_analyzer::symbolTable,$3.cadena);*/

				Sintactic_actions::check_division_zero(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
			      yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);}
break;
case 58:
#line 216 "gramatica.y"
{ yyval.cadena = chekeosGeneracion::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);
				/*chekeosGeneracion::estaAlAlcance(Lexical_analyzer::symbolTable,$3.cadena);*/
				}
break;
case 59:
#line 222 "gramatica.y"
{
	 	  yyval.cadena= yyvsp[0].cadena;
	 	  chekeosGeneracion::estaAlAlcance(Lexical_analyzer::symbolTable,yyvsp[0].cadena);

	 	  }
break;
case 60:
#line 227 "gramatica.y"
{yyval.cadena= yyvsp[0].cadena;
		chekeosGeneracion::estaAlAlcance(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
		}
break;
case 61:
#line 230 "gramatica.y"
{chekeosGeneracion::estaAlAlcance(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
	yyval.cadena= Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,yyvsp[0].cadena);

		}
break;
case 62:
#line 234 "gramatica.y"
{ chekeosGeneracion::estaAlAlcance(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
	Sintactic_actions::check_limit(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
		   yyval.cadena= yyvsp[0].cadena;}
break;
case 63:
#line 237 "gramatica.y"
{ chekeosGeneracion::estaAlAlcance(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
        	yyval.cadena=Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 64:
#line 242 "gramatica.y"
{ string s = "Int"; yyval.cadena = &s[0];}
break;
case 65:
#line 243 "gramatica.y"
{ string s = "Longint"; yyval.cadena = &s[0];}
break;
case 66:
#line 244 "gramatica.y"
{ string s = "Float"; yyval.cadena = &s[0];}
break;
case 67:
#line 248 "gramatica.y"
{Logger::write("Detecto sentencia OUT");}
break;
case 68:
#line 249 "gramatica.y"
{Logger::write("Error: SE ESPERABA OUT PREVIAMENTE PARA IMPRIMIR");}
break;
case 69:
#line 250 "gramatica.y"
{Logger::write("Error: SE ESPERABA CADENA EN LA SENTENCIA OUT");}
break;
#line 791 "y.tab.c"
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
