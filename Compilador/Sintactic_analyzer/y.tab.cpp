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
    8,    8,    8,    8,   14,   14,   15,   15,   16,   16,
   12,   12,   17,   18,   18,   18,   20,   21,   11,   11,
   11,   22,   19,   19,   23,   23,   23,   23,   23,   23,
    9,    9,    9,   24,   24,   24,   25,   25,   25,   25,
   25,    6,    6,    6,    5,    5,    5,
};
short yylen[] = {                                         2,
    1,    1,    2,    1,    1,    1,    2,    2,    1,    3,
    2,    4,    3,    1,    2,    2,    5,    3,    1,   11,
   14,   10,   10,    7,    5,    4,    1,    1,    4,    2,
    2,    4,    4,    4,    2,    3,    3,    3,    8,    7,
    7,    1,    3,    2,    1,    1,    1,    1,    1,    1,
    3,    3,    1,    1,    3,    3,    1,    1,    2,    1,
    2,    1,    1,    1,    5,    4,    4,
};
short yydefred[] = {                                      0,
    0,   64,   63,   62,    0,    0,   42,    0,    0,    0,
    0,    2,    4,    5,    6,    0,    9,    0,   14,    0,
    0,    0,    0,    0,   11,    0,    0,    0,    0,    0,
    0,    0,   57,   58,   60,    0,    0,    0,    0,    0,
   54,    3,    0,    7,    8,   15,   16,    0,    0,    0,
   31,    0,    0,   10,   13,    0,   19,    0,    0,    0,
    0,    0,    0,    0,    0,   59,   61,   48,   47,   45,
   46,   49,   50,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   35,    0,   12,    0,    0,   33,    0,
   67,   26,    0,   30,    0,    0,   66,    0,    0,    0,
    0,   32,   55,   56,    0,    0,   37,    0,    0,    0,
   18,   17,   65,   25,    0,    0,    0,    0,    0,    0,
    0,    0,   34,    0,    0,   29,    0,    0,    0,    0,
    0,    0,   38,    0,    0,    0,   40,    0,   27,   28,
    0,    0,   24,    0,   41,    0,    0,    0,    0,   39,
    0,    0,    0,    0,    0,    0,   22,   23,    0,   20,
    0,    0,   21,
};
short yydgoto[] = {                                      10,
   11,   12,   13,   14,   15,   16,   17,   18,   38,   19,
   20,   21,   58,   22,  141,   64,   23,   51,   39,   52,
  109,   24,   76,   40,   41,
};
short yysindex[] = {                                     58,
  -25,    0,    0,    0,  -26,  -18,    0,  -35,   68,    0,
   58,    0,    0,    0,    0, -226,    0,  -17,    0,  -10,
   15,  -40,  -84,   32,    0, -226,  -43, -203,   96,  -37,
   33, -199,    0,    0,    0,   34, -202,   83,   36,   -2,
    0,    0,  -27,    0,    0,    0,    0,   17, -199,   58,
    0, -200,   96,    0,    0,  -22,    0,   -3,   38,   41,
   24,  -21, -176,    6,   25,    0,    0,    0,    0,    0,
    0,    0,    0,   96,   96,   96, -116,   96,   96, -174,
    7,  -39,  -36,    0,   47,    0, -167,   37,    0,   42,
    0,    0,   14,    0, -199, -185,    0,   -2,   -2,  -16,
  -31,    0,    0,    0,   50, -117,    0,   58, -171, -111,
    0,    0,    0,    0, -160,   39,   58, -173,   43,   44,
   58,  -30,    0,   -8,   58,    0, -156,  -14,   46, -208,
 -150,   -5,    0,   58,    4,   55,    0, -208,    0,    0,
   -4,   -1,    0,   13,    0, -157,   12,   58,   58,    0,
   60,   58,   22,   31, -208,   40,    0,    0,   16,    0,
   58,   49,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  123,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   65,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   99,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   71,   91,  101,
    0,    0,    0,    0,    0,    0,    0,    0,   78,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
short yygindex[] = {                                      0,
  254,   35,    0,    0,    0,  -19,    2,    0,  -24,    0,
    0,    0,    0,    0, -130,  -38,    0,   67,  -20,    0,
    0,    0,    0,   -7,   -9,
};
#define YYTABLESIZE 415
short yytable[] = {                                      49,
    9,   37,   56,   61,   32,  121,   50,  147,   59,    9,
   81,  125,   63,   29,   28,   55,   26,   44,   26,   92,
   74,   30,   75,   93,  159,    9,   74,   54,   75,   63,
   43,   25,   85,   25,    9,   27,   86,   88,   50,   79,
   87,   45,   63,    9,   78,   42,   96,  106,   46,   95,
   95,  100,    9,   57,  114,   66,   67,   95,    2,    3,
    4,    9,   83,   84,  139,  140,   98,   99,  103,  104,
    9,   53,   62,   47,   65,  115,   77,   80,   89,    9,
   94,   90,   91,   97,  105,  107,  108,  110,    9,  111,
  116,  117,  123,  118,  133,  112,  126,    9,  146,  127,
  113,  129,  136,  130,  131,   53,  138,   53,  142,   53,
  137,   51,   37,   51,  134,   51,   42,  151,  148,  143,
  155,  149,    1,   53,   53,   74,   53,   75,  145,   51,
   51,   52,   51,   52,  152,   52,   36,  150,  161,   44,
   37,   43,   73,  102,   72,    0,  157,    0,    0,   52,
   52,    0,   52,    0,  101,  158,   42,  119,  120,  124,
    0,    0,   42,    0,  160,    0,   42,    0,    0,   42,
    0,    0,    0,  163,    0,    0,    0,    0,   42,    0,
    0,    0,    0,    0,    0,    0,    0,   42,   42,    0,
   42,    0,    0,    0,    0,    0,   42,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   33,   34,   35,    0,    1,    2,    3,
    4,   31,    5,   60,    0,    6,    1,    2,    3,    4,
    7,    5,    8,    0,    6,   48,    2,    3,    4,    7,
    0,    8,    1,    2,    3,    4,    0,    5,    0,    0,
    6,    1,    2,    3,    4,    7,    5,    8,    0,    6,
    1,    2,    3,    4,    7,    5,    8,    0,    6,    1,
    2,    3,    4,    7,    5,    8,    0,    6,    1,    2,
    3,    4,    7,    5,    8,    0,    6,    1,    2,    3,
    4,    7,    5,    8,    0,    6,    1,    2,    3,    4,
    7,    5,    8,   82,    6,    1,    2,    3,    4,    7,
    5,    8,    0,    6,    1,    2,    3,    4,    7,    5,
    8,    0,    6,    0,   33,   34,   35,    7,   36,    8,
   53,   53,   53,   53,    0,    0,   51,   51,   51,   51,
    0,    0,    0,    0,    0,    0,    0,    0,   68,   69,
   70,   71,   33,   34,   35,    0,   52,   52,   52,   52,
    0,  122,    0,    0,    0,    0,    0,    0,    0,    0,
  128,    0,    0,    0,  132,    0,    0,    0,  135,    0,
    0,    0,    0,    0,    0,    0,    0,  144,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  153,  154,    0,    0,  156,    0,    0,    0,    0,
    0,    0,    0,    0,  162,
};
short yycheck[] = {                                      40,
   40,   45,   27,   41,   40,  123,  123,  138,   29,   40,
   49,  123,   32,   40,   40,   59,   44,   16,   44,   41,
   43,   40,   45,   62,  155,   40,   43,   26,   45,   49,
  257,   59,   53,   59,   40,   61,   59,   41,  123,   42,
   44,   59,   62,   40,   47,   11,   41,   41,   59,   44,
   44,   76,   40,  257,   41,  258,  259,   44,  258,  259,
  260,   40,  263,  264,  273,  274,   74,   75,   78,   79,
   40,   40,   40,   59,   41,   95,   41,   61,   41,   40,
  257,   41,   59,   59,  259,  125,  123,   41,   40,  257,
  276,  123,  264,   44,  125,   59,  257,   40,   44,   61,
   59,  275,  259,   61,   61,   41,   61,   43,  259,   45,
  125,   41,   45,   43,  123,   45,   82,  275,  123,  125,
   61,  123,    0,   59,   60,   43,   62,   45,  125,   59,
   60,   41,   62,   43,  123,   45,   59,  125,  123,   41,
   45,   41,   60,   77,   62,   -1,  125,   -1,   -1,   59,
   60,   -1,   62,   -1,  271,  125,  122,  275,  276,  271,
   -1,   -1,  128,   -1,  125,   -1,  132,   -1,   -1,  135,
   -1,   -1,   -1,  125,   -1,   -1,   -1,   -1,  144,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  153,  154,   -1,
  156,   -1,   -1,   -1,   -1,   -1,  162,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  257,  258,  259,   -1,  257,  258,  259,
  260,  257,  262,  261,   -1,  265,  257,  258,  259,  260,
  270,  262,  272,   -1,  265,  276,  258,  259,  260,  270,
   -1,  272,  257,  258,  259,  260,   -1,  262,   -1,   -1,
  265,  257,  258,  259,  260,  270,  262,  272,   -1,  265,
  257,  258,  259,  260,  270,  262,  272,   -1,  265,  257,
  258,  259,  260,  270,  262,  272,   -1,  265,  257,  258,
  259,  260,  270,  262,  272,   -1,  265,  257,  258,  259,
  260,  270,  262,  272,   -1,  265,  257,  258,  259,  260,
  270,  262,  272,   50,  265,  257,  258,  259,  260,  270,
  262,  272,   -1,  265,  257,  258,  259,  260,  270,  262,
  272,   -1,  265,   -1,  257,  258,  259,  270,  261,  272,
  266,  267,  268,  269,   -1,   -1,  266,  267,  268,  269,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  266,  267,
  268,  269,  257,  258,  259,   -1,  266,  267,  268,  269,
   -1,  108,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  117,   -1,   -1,   -1,  121,   -1,   -1,   -1,  125,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  134,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  148,  149,   -1,   -1,  152,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  161,
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
"procedimiento : nombre_proc NA '=' LONGINT ',' SHADOWING '=' true_false '{' bloque_sentencia '}'",
"procedimiento : PROC '(' lista_de_parametros ')' NA '=' LONGINT ',' SHADOWING '=' true_false '{' bloque_sentencia '}'",
"procedimiento : nombre_proc '(' lista_de_parametros ')' SHADOWING '=' true_false '{' bloque_sentencia '}'",
"procedimiento : nombre_proc '(' lista_de_parametros ')' NA '=' LONGINT '{' bloque_sentencia '}'",
"procedimiento : nombre_proc '(' lista_de_parametros ')' '{' bloque_sentencia '}'",
"nombre_proc : PROC ID '(' lista_de_parametros ')'",
"nombre_proc : PROC ID '(' ')'",
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
						Intermediate_code::declare_variable_list(Lexical_analyzer::symbolTable,yyvsp[-1].cadena);
	      		      		}
break;
case 8:
#line 34 "gramatica.y"
{Logger::write("Declaracion de procedimiento"); Intermediate_code::shadowing = false;}
break;
case 9:
#line 35 "gramatica.y"
{Logger::write("Error: Falta el tipo en la lista de variables");}
break;
case 10:
#line 42 "gramatica.y"
{
		     	Intermediate_code::addVariable(yyvsp[-2].cadena);
		     	string s = "variable";
                        Intermediate_code::setUse(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,&s[0]);}
break;
case 11:
#line 46 "gramatica.y"
{
		   	Intermediate_code::addVariable(yyvsp[-1].cadena);
		   	string s = "variable";
                        Intermediate_code::setUse(Lexical_analyzer::symbolTable,yyvsp[-1].cadena,&s[0]);}
break;
case 12:
#line 53 "gramatica.y"
{
	    	Logger::write("Asignacion");
	    	yyval.cadena = Intermediate_code::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-3].cadena,yyvsp[-1].cadena);
		Intermediate_code::generarAsignacionTercetos(yyvsp[-3].cadena);
		}
break;
case 13:
#line 58 "gramatica.y"
{Logger::write("Error: Asignacion vacia");}
break;
case 14:
#line 59 "gramatica.y"
{Logger::write("invocacion procedimiento");}
break;
case 15:
#line 60 "gramatica.y"
{Logger::write("sentencia while"); Intermediate_code::desconcatenarAmbitoAnonimo();}
break;
case 16:
#line 61 "gramatica.y"
{Logger::write("sentencia if");Intermediate_code::desconcatenarAmbitoAnonimo();}
break;
case 17:
#line 65 "gramatica.y"
{Intermediate_code::check_scope(Lexical_analyzer::symbolTable,yyvsp[-4].cadena);
	 			    Intermediate_code::insertar_terceto("Call",yyvsp[-4].cadena,"");}
break;
case 18:
#line 70 "gramatica.y"
{Intermediate_code::check_scope(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 19:
#line 71 "gramatica.y"
{Intermediate_code::check_scope(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 20:
#line 75 "gramatica.y"
{
	    	Intermediate_code::eliminarUltimoAmbito();
		Intermediate_code::check_NA(yyvsp[-7].cadena);
		Intermediate_code::desapilarProc();
	 }
break;
case 21:
#line 80 "gramatica.y"
{
		Logger::write("Error: FALTA ID");
		Intermediate_code::eliminarUltimoAmbito();
		Intermediate_code::check_NA(yyvsp[-7].cadena);
	}
break;
case 22:
#line 85 "gramatica.y"
{
		Logger::write("Error: FALTA ESPECIFICAR VALOR NA");
		Intermediate_code::eliminarUltimoAmbito();
	}
break;
case 23:
#line 89 "gramatica.y"
{
		Logger::write("Error: FALTA ESPECIFICAR VALOR SHADOWING");
		Intermediate_code::eliminarUltimoAmbito();
		Intermediate_code::check_NA(yyvsp[-3].cadena);
	}
break;
case 24:
#line 94 "gramatica.y"
{
		Logger::write("Error: FALTA ESPECIFICAR LOS VALORES DE NA Y SHADOWING");
		Intermediate_code::eliminarUltimoAmbito();
	}
break;
case 25:
#line 102 "gramatica.y"
{
			Intermediate_code::apilarProc(yyvsp[-3].cadena);
			Intermediate_code::insertarProc();
			Sintactic_actions::check_list_parametros();
			yyval.cadena=yyvsp[-3].cadena;
			string s = "nombre_proc";
			Intermediate_code::setUse(Lexical_analyzer::symbolTable,yyvsp[-3].cadena,&s[0]);
			Intermediate_code::concatenarAmbito(yyvsp[-3].cadena);
			Intermediate_code::set_ambit(Lexical_analyzer::symbolTable,yyvsp[-3].cadena);
			Intermediate_code::agregarAnidado();
			}
break;
case 26:
#line 113 "gramatica.y"
{
	    	Intermediate_code::apilarProc(yyvsp[-2].cadena);
	    	Intermediate_code::insertarProc();
		yyval.cadena=yyvsp[-2].cadena;
		string s = "nombre_proc";
		Intermediate_code::setUse(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,&s[0]);
		Intermediate_code::concatenarAmbito(yyvsp[-2].cadena);
		Intermediate_code::set_ambit(Lexical_analyzer::symbolTable,yyvsp[-2].cadena);
		Intermediate_code::agregarAnidado();
	    }
break;
case 27:
#line 126 "gramatica.y"
{ Intermediate_code::shadowing = true;}
break;
case 28:
#line 127 "gramatica.y"
{ Intermediate_code::shadowing = false;}
break;
case 29:
#line 131 "gramatica.y"
{
	 	      	   Logger::write("lista_de_variables");
	 	     	   Sintactic_actions::number_of_parameters++;

	 	 	   Intermediate_code::setUse(Lexical_analyzer::symbolTable,yyvsp[0].cadena,"parametro");
			   Lexical_analyzer::symbolTable->addType2(yyvsp[-1].cadena,yyvsp[0].cadena,Intermediate_code::ambito_actual);
		      }
break;
case 30:
#line 138 "gramatica.y"
{
		    	   Sintactic_actions::number_of_parameters++;
			   Intermediate_code::setUse(Lexical_analyzer::symbolTable,yyvsp[0].cadena,"parametro");
			   Lexical_analyzer::symbolTable->addType2(yyvsp[-1].cadena,yyvsp[0].cadena,Intermediate_code::ambito_actual);
		      }
break;
case 31:
#line 146 "gramatica.y"
{Logger::write("Sentencia IF");}
break;
case 32:
#line 147 "gramatica.y"
{Logger::write("Error: FALTA EL IF");}
break;
case 33:
#line 151 "gramatica.y"
{Intermediate_code::concatenarAmbitoAnonimo("IF");}
break;
case 34:
#line 154 "gramatica.y"
{/*Desapilar*/
					    /*Completar terceto incompleto con el destino de la BI*/
					    Intermediate_code::modificar_terceto(Intermediate_code::desapilar(),0);
					    }
break;
case 35:
#line 158 "gramatica.y"
{/*Desapilar*/
			    /*Completar terceto incompleto con el destino de la BI*/
			    /*Intermediate_code::modificar_terceto(Intermediate_code::desapilar(),1);*/
			    }
break;
case 36:
#line 162 "gramatica.y"
{Logger::write("Error: FALTA EL END_IF");}
break;
case 37:
#line 165 "gramatica.y"
{/*desapilar*/
			/*completar terceto incompleto con el destino de la bf*/
			Intermediate_code::modificar_terceto(Intermediate_code::desapilar(),1);
			/*apilar el numero del terceto incompleto (apilo antes porque sino me paso de rango y no lo encuentra)*/
			Intermediate_code::apilar();
			/* crear terceto incompleto para la BI*/
			Intermediate_code::insertar_terceto("BI","","");
			}
break;
case 39:
#line 181 "gramatica.y"
{Logger::write("Sentencia WHILE");
         								/*(1)desapilar,*/
         								/*(2)completar terceto incompleto.*/
         								Intermediate_code::modificar_terceto(Intermediate_code::desapilar(),1);
         								/*(3)Desapilo direccion de inicio y creo el terceto BI al inicio*/
         								Intermediate_code::insertar_terceto("BI",to_string(Intermediate_code::desapilar()),"");
         								}
break;
case 40:
#line 188 "gramatica.y"
{Logger::write("Error: FALTA 'WHILE' EN LA SENTENCIA");}
break;
case 41:
#line 189 "gramatica.y"
{Logger::write("Error: FALTA 'LOOP' EN SENTENCIA WHILE");}
break;
case 42:
#line 193 "gramatica.y"
{
        		Intermediate_code::concatenarAmbitoAnonimo("WHILE");
        		/*apilar terceto de inicio para saber la BI*/
        		Intermediate_code::apilar();
        	}
break;
case 43:
#line 202 "gramatica.y"
{
	           yyval.cadena = Intermediate_code::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);
		   Intermediate_code::expresionComparadorExpresion(yyvsp[0].cadena);
	   }
break;
case 44:
#line 206 "gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 45:
#line 209 "gramatica.y"
{Intermediate_code::generar_comparador("==");}
break;
case 46:
#line 210 "gramatica.y"
{Intermediate_code::generar_comparador("!=");}
break;
case 47:
#line 211 "gramatica.y"
{ Intermediate_code::generar_comparador("<=");}
break;
case 48:
#line 212 "gramatica.y"
{Intermediate_code::generar_comparador(">=");}
break;
case 49:
#line 213 "gramatica.y"
{Intermediate_code::generar_comparador(">");}
break;
case 50:
#line 214 "gramatica.y"
{Intermediate_code::generar_comparador("<");}
break;
case 51:
#line 219 "gramatica.y"
{
	    	yyval.cadena = Intermediate_code::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);
		Intermediate_code::expresionMenosTermino("+",yyvsp[0].cadena);
	   }
break;
case 52:
#line 224 "gramatica.y"
{
		yyval.cadena = Intermediate_code::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);
		Intermediate_code::expresionMenosTermino("-",yyvsp[0].cadena);
	   }
break;
case 53:
#line 229 "gramatica.y"
{yyval.cadena = yyvsp[0].cadena;}
break;
case 54:
#line 234 "gramatica.y"
{
	 	yyval.cadena= yyvsp[0].cadena;
		Intermediate_code::terminoFactor(yyvsp[0].cadena);
	 }
break;
case 55:
#line 239 "gramatica.y"
{
			      Sintactic_actions::check_division_zero(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
       			      yyval.cadena = Intermediate_code::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);
			      Intermediate_code::terminoDivididoFactor("/",yyvsp[0].cadena);
	 }
break;
case 56:
#line 245 "gramatica.y"
{
	    			Sintactic_actions::check_division_zero(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
           			 yyval.cadena = Intermediate_code::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);
				Intermediate_code::terminoDivididoFactor("*",yyvsp[0].cadena);
	}
break;
case 57:
#line 252 "gramatica.y"
{
	     yyval.cadena= yyvsp[0].cadena;
	     Intermediate_code::check_scope(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
	 }
break;
case 58:
#line 257 "gramatica.y"
{
	     yyval.cadena= yyvsp[0].cadena;
	     Intermediate_code::check_scope(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
	}
break;
case 59:
#line 262 "gramatica.y"
{
	     Intermediate_code::check_scope(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
	     yyval.cadena= Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
	}
break;
case 60:
#line 267 "gramatica.y"
{
		Intermediate_code::check_scope(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
		Sintactic_actions::check_limit(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
		yyval.cadena= yyvsp[0].cadena;
	}
break;
case 61:
#line 272 "gramatica.y"
{ Intermediate_code::check_scope(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
        	yyval.cadena=Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 62:
#line 277 "gramatica.y"
{ string s = "Int"; yyval.cadena = &s[0];}
break;
case 63:
#line 278 "gramatica.y"
{ string s = "Longint"; yyval.cadena = &s[0];}
break;
case 64:
#line 279 "gramatica.y"
{ string s = "Float"; yyval.cadena = &s[0];}
break;
case 65:
#line 283 "gramatica.y"
{Logger::write("Detecto sentencia OUT");
	  			Intermediate_code::insertar_terceto("OUT",yyvsp[-2].cadena,"");

	  				}
break;
case 66:
#line 287 "gramatica.y"
{Logger::write("Error: SE ESPERABA OUT PREVIAMENTE PARA IMPRIMIR");}
break;
case 67:
#line 288 "gramatica.y"
{Logger::write("Error: SE ESPERABA CADENA EN LA SENTENCIA OUT");}
break;
#line 821 "y.tab.c"
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
