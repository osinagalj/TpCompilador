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
    7,    4,    4,    4,    4,    4,   14,   10,   13,   13,
    8,    8,    8,    8,    8,   15,   15,   18,   16,   16,
   17,   17,   12,   12,   19,   20,   20,   20,   22,   23,
   11,   11,   11,   24,   21,   21,   25,   25,   25,   25,
   25,   25,    9,    9,    9,   26,   26,   26,   27,   27,
   27,   27,   27,    6,    6,    6,    5,    5,    5,
};
short yylen[] = {                                         2,
    1,    1,    2,    1,    1,    1,    2,    2,    1,    3,
    2,    4,    3,    1,    2,    2,    0,   10,    3,    1,
   11,   14,   10,   10,    7,    4,    3,    2,    1,    1,
    4,    2,    2,    4,    4,    4,    2,    3,    3,    3,
    8,    7,    7,    1,    3,    2,    1,    1,    1,    1,
    1,    1,    3,    3,    1,    1,    3,    3,    1,    1,
    2,    1,    2,    1,    1,    1,    5,    4,    4,
};
short yydefred[] = {                                      0,
    0,   66,   65,   64,    0,    0,   44,    0,    0,    0,
    0,    2,    4,    5,    6,    0,    9,    0,   14,    0,
    0,    0,    0,    0,    0,   11,    0,    0,    0,    0,
    0,   28,    0,   59,   60,   62,    0,    0,    0,    0,
    0,   56,    3,    0,    7,    8,   15,   16,    0,    0,
    0,    0,   33,    0,    0,   10,   13,    0,   20,    0,
    0,    0,    0,    0,    0,    0,   61,   63,   50,   49,
   47,   48,   51,   52,    0,    0,    0,    0,    0,    0,
    0,    0,   27,    0,    0,    0,   37,    0,   12,    0,
    0,   35,    0,   69,   32,    0,    0,   68,    0,    0,
    0,    0,   34,   57,   58,    0,    0,   26,   39,    0,
    0,    0,   19,   17,   67,    0,    0,    0,    0,    0,
    0,    0,    0,   36,    0,    0,    0,   31,    0,    0,
    0,    0,    0,    0,   40,    0,    0,    0,    0,   42,
    0,   29,   30,    0,    0,   25,    0,   43,    0,    0,
    0,    0,    0,   41,    0,    0,    0,    0,    0,   18,
    0,    0,   23,   24,    0,   21,    0,    0,   22,
};
short yydgoto[] = {                                      10,
   11,   12,   13,   14,   15,   16,   17,   18,   39,   19,
   20,   21,   60,  127,   22,  144,   65,   23,   24,   53,
   40,   54,  111,   25,   77,   41,   42,
};
short yysindex[] = {                                     58,
  -29,    0,    0,    0,  -23,  -17,    0,  -35,   68,    0,
   58,    0,    0,    0,    0, -226,    0,  -19,    0,   15,
   16,  -40,   23,  -69,   33,    0, -226,  -43, -185,   96,
  -37,    0, -222,    0,    0,    0,   35, -202,   83,   36,
  -20,    0,    0,  -31,    0,    0,    0,    0,   17, -222,
  -21,   58,    0, -205,   96,    0,    0,   -4,    0,    1,
   38,   41,   24, -176,    5,   25,    0,    0,    0,    0,
    0,    0,    0,    0,   96,   96,   96, -114,   96,   96,
 -174,    6,    0,    7,  -39,  -36,    0,   47,    0, -167,
   34,    0,   37,    0,    0, -222, -184,    0,  -20,  -20,
  -24,  -32,    0,    0,    0,   50, -117,    0,    0,   58,
 -165, -111,    0,    0,    0, -160,   39,   58, -173,   42,
   43,   58,  -30,    0,  -18,   58, -156,    0, -152,  -14,
   48, -213, -144,   -5,    0,   58,    4,   78,   75,    0,
 -213,    0,    0,   -2,   -1,    0,   13,    0,   82, -140,
   19,   58,   58,    0,   80,   76,   58,   22,   31,    0,
 -213,   40,    0,    0,   21,    0,   58,   49,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  140,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   65,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  105,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   71,   91,
  107,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   90,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
  252,   32,    0,    0,    0,  -26,    2,    0,  -25,    0,
    0,    0,    0,    0,    0, -127,   14,    0,    0,   74,
  -22,    0,    0,    0,    0,   -9,  -11,
};
#define YYTABLESIZE 419
short yytable[] = {                                      50,
    9,   38,   58,   63,   33,  122,   64,   61,   52,    9,
   29,  126,   27,  151,   27,   57,   30,   45,   75,   83,
   76,   80,   31,   64,   64,    9,   79,   26,   56,   26,
   44,   28,   88,  165,    9,    2,    3,    4,   75,   46,
   76,   91,   43,    9,   90,   97,  107,  108,   96,   96,
   96,  101,    9,   52,   89,   67,   68,   86,   87,  142,
  143,    9,   51,   82,   84,   99,  100,  104,  105,  116,
    9,   59,   55,   47,   48,   66,   78,   81,   92,    9,
   95,   93,   94,   98,  106,  109,  110,  112,    9,  113,
  118,  117,  114,  119,  135,  115,  128,    9,  124,  129,
  138,  131,  132,  133,  136,   55,  139,   55,  141,   55,
  140,   53,   38,   53,  145,   53,   43,  149,  150,  146,
  152,  153,  155,   55,   55,   75,   55,   76,  148,   53,
   53,   54,   53,   54,  156,   54,  161,  154,  160,    1,
   38,  157,   74,  167,   73,   46,  163,   45,   38,   54,
   54,  103,   54,    0,   43,  164,  102,  120,  121,  125,
    0,   43,    0,    0,  166,   43,    0,    0,   43,    0,
    0,    0,    0,  169,    0,    0,    0,    0,   43,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   43,
   43,    0,    0,   43,    0,    0,    0,    0,    0,   43,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   34,   35,   36,    0,    1,    2,    3,
    4,   32,    5,   62,    0,    6,    1,    2,    3,    4,
    7,    5,    8,    0,    6,   49,    2,    3,    4,    7,
    0,    8,    1,    2,    3,    4,    0,    5,    0,    0,
    6,    1,    2,    3,    4,    7,    5,    8,    0,    6,
    1,    2,    3,    4,    7,    5,    8,    0,    6,    1,
    2,    3,    4,    7,    5,    8,    0,    6,    1,    2,
    3,    4,    7,    5,    8,    0,    6,    1,    2,    3,
    4,    7,    5,    8,    0,    6,    1,    2,    3,    4,
    7,    5,    8,   85,    6,    1,    2,    3,    4,    7,
    5,    8,    0,    6,    1,    2,    3,    4,    7,    5,
    8,    0,    6,    0,   34,   35,   36,    7,   37,    8,
   55,   55,   55,   55,    0,    0,   53,   53,   53,   53,
    0,    0,    0,    0,    0,    0,    0,    0,   69,   70,
   71,   72,   34,   35,   36,    0,   54,   54,   54,   54,
    0,  123,    0,    0,    0,    0,    0,    0,    0,  130,
    0,    0,    0,  134,    0,    0,    0,  137,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  147,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  158,  159,    0,    0,    0,  162,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  168,
};
short yycheck[] = {                                      40,
   40,   45,   28,   41,   40,  123,   33,   30,  123,   40,
   40,  123,   44,  141,   44,   59,   40,   16,   43,   41,
   45,   42,   40,   50,   51,   40,   47,   59,   27,   59,
  257,   61,   55,  161,   40,  258,  259,  260,   43,   59,
   45,   41,   11,   40,   44,   41,   41,   41,   44,   44,
   44,   77,   40,  123,   59,  258,  259,  263,  264,  273,
  274,   40,   40,   50,   51,   75,   76,   79,   80,   96,
   40,  257,   40,   59,   59,   41,   41,   61,   41,   40,
  257,   41,   59,   59,  259,  125,  123,   41,   40,  257,
  123,  276,   59,   44,  125,   59,  257,   40,  264,   61,
  257,  275,   61,   61,  123,   41,  259,   43,   61,   45,
  125,   41,   45,   43,  259,   45,   85,   40,   44,  125,
  123,  123,   41,   59,   60,   43,   62,   45,  125,   59,
   60,   41,   62,   43,  275,   45,   61,  125,   59,    0,
   45,  123,   60,  123,   62,   41,  125,   41,   59,   59,
   60,   78,   62,   -1,  123,  125,  271,  275,  276,  271,
   -1,  130,   -1,   -1,  125,  134,   -1,   -1,  137,   -1,
   -1,   -1,   -1,  125,   -1,   -1,   -1,   -1,  147,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  158,
  159,   -1,   -1,  162,   -1,   -1,   -1,   -1,   -1,  168,
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
  270,  262,  272,   52,  265,  257,  258,  259,  260,  270,
  262,  272,   -1,  265,  257,  258,  259,  260,  270,  262,
  272,   -1,  265,   -1,  257,  258,  259,  270,  261,  272,
  266,  267,  268,  269,   -1,   -1,  266,  267,  268,  269,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  266,  267,
  268,  269,  257,  258,  259,   -1,  266,  267,  268,  269,
   -1,  110,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  118,
   -1,   -1,   -1,  122,   -1,   -1,   -1,  126,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  136,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  152,  153,   -1,   -1,   -1,  157,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  167,
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
"$$1 :",
"invocacion_proc : ID '(' parametros ')' ';' $$1 ID '(' ')' ';'",
"parametros : parametros ',' ID",
"parametros : ID",
"procedimiento : nombre_proc NA '=' LONGINT ',' SHADOWING '=' true_false '{' bloque_sentencia '}'",
"procedimiento : PROC '(' lista_de_parametros ')' NA '=' LONGINT ',' SHADOWING '=' true_false '{' bloque_sentencia '}'",
"procedimiento : nombre_proc '(' lista_de_parametros ')' SHADOWING '=' true_false '{' bloque_sentencia '}'",
"procedimiento : nombre_proc '(' lista_de_parametros ')' NA '=' LONGINT '{' bloque_sentencia '}'",
"procedimiento : nombre_proc '(' lista_de_parametros ')' '{' bloque_sentencia '}'",
"nombre_proc : encabezado '(' lista_de_parametros ')'",
"nombre_proc : encabezado '(' ')'",
"encabezado : PROC ID",
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
		Intermediate_code::generarAsignacionTercetos(Lexical_analyzer::symbolTable,yyvsp[-3].cadena);
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
{
	 			    string proc = yyvsp[-4].cadena;
                                    proc = proc + "@"+Intermediate_code::ambito_actual;
	 			    Intermediate_code::insertar_terceto("Call",proc,"");
	 			    Intermediate_code::check_scope(Lexical_analyzer::symbolTable,yyvsp[-4].cadena);}
break;
case 18:
#line 70 "gramatica.y"
{
                                    string proc = yyvsp[-9].cadena;
                                    proc = proc + "@"+Intermediate_code::ambito_actual;
                                    Intermediate_code::insertar_terceto("Call",proc,"");
                                    Intermediate_code::check_scope(Lexical_analyzer::symbolTable,yyvsp[-9].cadena);}
break;
case 19:
#line 78 "gramatica.y"
{Intermediate_code::check_scope(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 20:
#line 79 "gramatica.y"
{Intermediate_code::check_scope(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 21:
#line 83 "gramatica.y"
{
	 		string proc = yyvsp[-10].cadena;
         		proc = proc + "@"+Intermediate_code::ambito_actual;
	 	Intermediate_code::insertar_terceto("fin_PROC",proc,"");

	    	Intermediate_code::eliminarUltimoAmbito();
		Intermediate_code::check_NA(yyvsp[-7].cadena);
		/*Intermediate_code::desapilarProc();*/
	 }
break;
case 22:
#line 92 "gramatica.y"
{
		Logger::write("Error: FALTA ID");
		Intermediate_code::eliminarUltimoAmbito();
		Intermediate_code::check_NA(yyvsp[-7].cadena);
	}
break;
case 23:
#line 97 "gramatica.y"
{
		Logger::write("Error: FALTA ESPECIFICAR VALOR NA");
		Intermediate_code::eliminarUltimoAmbito();
	}
break;
case 24:
#line 101 "gramatica.y"
{
		Logger::write("Error: FALTA ESPECIFICAR VALOR SHADOWING");
		Intermediate_code::eliminarUltimoAmbito();
		Intermediate_code::check_NA(yyvsp[-3].cadena);
	}
break;
case 25:
#line 106 "gramatica.y"
{
		Logger::write("Error: FALTA ESPECIFICAR LOS VALORES DE NA Y SHADOWING");
		Intermediate_code::eliminarUltimoAmbito();
	}
break;
case 26:
#line 114 "gramatica.y"
{
			Sintactic_actions::check_list_parametros();
			yyval.cadena=yyvsp[-3].cadena;
			}
break;
case 27:
#line 118 "gramatica.y"
{
		yyval.cadena=yyvsp[-2].cadena;
	    }
break;
case 28:
#line 123 "gramatica.y"
{
		string proc = yyvsp[0].cadena;
		proc = proc + "@"+Intermediate_code::ambito_actual;
		Intermediate_code::insertar_terceto("inicio_PROC",proc,"");
		/*Intermediate_code::apilarProc($2.cadena);*/
        	/*Intermediate_code::insertarProc();*/
		yyval.cadena=yyvsp[0].cadena;
		string s = "nombre_proc";
		Intermediate_code::setUse(Lexical_analyzer::symbolTable,yyvsp[0].cadena,&s[0]);
		Intermediate_code::concatenarAmbito(yyvsp[0].cadena);
		Intermediate_code::set_ambit(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
		Intermediate_code::agregarAnidado();
	}
break;
case 29:
#line 139 "gramatica.y"
{ Intermediate_code::shadowing = true;}
break;
case 30:
#line 140 "gramatica.y"
{ Intermediate_code::shadowing = false;}
break;
case 31:
#line 144 "gramatica.y"
{
	 	      	   Logger::write("lista_de_variables");
	 	     	   Sintactic_actions::number_of_parameters++;

	 	 	   Intermediate_code::setUse(Lexical_analyzer::symbolTable,yyvsp[0].cadena,"parametro");
			   Lexical_analyzer::symbolTable->addType2(yyvsp[-1].cadena,yyvsp[0].cadena,Intermediate_code::ambito_actual);
		      }
break;
case 32:
#line 151 "gramatica.y"
{
		    	   Sintactic_actions::number_of_parameters++;
			   Intermediate_code::setUse(Lexical_analyzer::symbolTable,yyvsp[0].cadena,"parametro");
			   Lexical_analyzer::symbolTable->addType2(yyvsp[-1].cadena,yyvsp[0].cadena,Intermediate_code::ambito_actual);
		      }
break;
case 33:
#line 159 "gramatica.y"
{Logger::write("Sentencia IF");}
break;
case 34:
#line 160 "gramatica.y"
{Logger::write("Error: FALTA EL IF");}
break;
case 35:
#line 164 "gramatica.y"
{Intermediate_code::concatenarAmbitoAnonimo("IF");}
break;
case 36:
#line 167 "gramatica.y"
{/*Desapilar*/
					    /*Completar terceto incompleto con el destino de la BI*/
					    Intermediate_code::modificar_terceto(Intermediate_code::desapilar(),0);
					    Intermediate_code::insertar_terceto("Label"+to_string(Intermediate_code::getNumber()),"IF","");
					    }
break;
case 37:
#line 172 "gramatica.y"
{/*Desapilar*/
			    /*Completar terceto incompleto con el destino de la BI*/
			    /*Intermediate_code::modificar_terceto(Intermediate_code::desapilar(),1);*/
			    }
break;
case 38:
#line 176 "gramatica.y"
{Logger::write("Error: FALTA EL END_IF");}
break;
case 39:
#line 179 "gramatica.y"
{/*desapilar*/
			/*completar terceto incompleto con el destino de la bf*/
			Intermediate_code::modificar_terceto(Intermediate_code::desapilar(),1);
			/*apilar el numero del terceto incompleto (apilo antes porque sino me paso de rango y no lo encuentra)*/
			Intermediate_code::apilar();
			/* crear terceto incompleto para la BI*/
			Intermediate_code::insertar_terceto("BI","","");
			Intermediate_code::insertar_terceto("Label"+to_string(Intermediate_code::getNumber()),"IF","");
			}
break;
case 41:
#line 196 "gramatica.y"
{Logger::write("Sentencia WHILE");
         								/*(1)desapilar,*/
         								/*(2)completar terceto incompleto.*/
         								Intermediate_code::modificar_terceto(Intermediate_code::desapilar(),1);
         								/*(3)Desapilo direccion de inicio y creo el terceto BI al inicio*/
         								Intermediate_code::insertar_terceto("BI",to_string(Intermediate_code::desapilar()),"");
									Intermediate_code::insertar_terceto("Label"+to_string(Intermediate_code::getNumber()),"WHILE","");

         								}
break;
case 42:
#line 205 "gramatica.y"
{Logger::write("Error: FALTA 'WHILE' EN LA SENTENCIA");}
break;
case 43:
#line 206 "gramatica.y"
{Logger::write("Error: FALTA 'LOOP' EN SENTENCIA WHILE");}
break;
case 44:
#line 210 "gramatica.y"
{
        		Intermediate_code::concatenarAmbitoAnonimo("WHILE");
        		/*apilar terceto de inicio para saber la BI*/
        		Intermediate_code::apilar();
        		Intermediate_code::insertar_terceto("Label"+to_string(Intermediate_code::getNumber()),"WHILE","");
        	}
break;
case 45:
#line 220 "gramatica.y"
{
	           yyval.cadena = Intermediate_code::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);
		   Intermediate_code::expresionComparadorExpresion(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
	   }
break;
case 46:
#line 224 "gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 47:
#line 227 "gramatica.y"
{Intermediate_code::generar_comparador("==");}
break;
case 48:
#line 228 "gramatica.y"
{Intermediate_code::generar_comparador("!=");}
break;
case 49:
#line 229 "gramatica.y"
{ Intermediate_code::generar_comparador("<=");}
break;
case 50:
#line 230 "gramatica.y"
{Intermediate_code::generar_comparador(">=");}
break;
case 51:
#line 231 "gramatica.y"
{Intermediate_code::generar_comparador(">");}
break;
case 52:
#line 232 "gramatica.y"
{Intermediate_code::generar_comparador("<");}
break;
case 53:
#line 237 "gramatica.y"
{
	    	yyval.cadena = Intermediate_code::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);
		Intermediate_code::expresionMenosTermino(Lexical_analyzer::symbolTable,"+",yyvsp[0].cadena);
	   }
break;
case 54:
#line 242 "gramatica.y"
{
		yyval.cadena = Intermediate_code::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);
		Intermediate_code::expresionMenosTermino(Lexical_analyzer::symbolTable,"-",yyvsp[0].cadena);
	   }
break;
case 55:
#line 247 "gramatica.y"
{yyval.cadena = yyvsp[0].cadena;}
break;
case 56:
#line 252 "gramatica.y"
{
	 	yyval.cadena= yyvsp[0].cadena;
		Intermediate_code::terminoFactor(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
	 }
break;
case 57:
#line 257 "gramatica.y"
{
			      Sintactic_actions::check_division_zero(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
       			      yyval.cadena = Intermediate_code::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);
			      Intermediate_code::terminoDivididoFactor(Lexical_analyzer::symbolTable,"/",yyvsp[0].cadena);
	 }
break;
case 58:
#line 263 "gramatica.y"
{
	    			Sintactic_actions::check_division_zero(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
           			 yyval.cadena = Intermediate_code::asignarTipo(Lexical_analyzer::symbolTable,yyvsp[-2].cadena,yyvsp[0].cadena);
				Intermediate_code::terminoDivididoFactor(Lexical_analyzer::symbolTable,"*",yyvsp[0].cadena);
	}
break;
case 59:
#line 270 "gramatica.y"
{
	     yyval.cadena= yyvsp[0].cadena;
	     Intermediate_code::check_scope(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
	 }
break;
case 60:
#line 275 "gramatica.y"
{
	     yyval.cadena= yyvsp[0].cadena;
	     Intermediate_code::check_scope(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
	}
break;
case 61:
#line 280 "gramatica.y"
{
	     Intermediate_code::check_scope(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
	     yyval.cadena= Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
	}
break;
case 62:
#line 285 "gramatica.y"
{
		Intermediate_code::check_scope(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
		Sintactic_actions::check_limit(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
		yyval.cadena= yyvsp[0].cadena;
	}
break;
case 63:
#line 290 "gramatica.y"
{ Intermediate_code::check_scope(Lexical_analyzer::symbolTable,yyvsp[0].cadena);
        	yyval.cadena=Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 64:
#line 295 "gramatica.y"
{ string s = "Int"; yyval.cadena = &s[0];}
break;
case 65:
#line 296 "gramatica.y"
{ string s = "Longint"; yyval.cadena = &s[0];}
break;
case 66:
#line 297 "gramatica.y"
{ string s = "Float"; yyval.cadena = &s[0];}
break;
case 67:
#line 301 "gramatica.y"
{Logger::write("Detecto sentencia OUT");
	  			Intermediate_code::insertar_terceto("OUT",yyvsp[-2].cadena,"");

	  				}
break;
case 68:
#line 305 "gramatica.y"
{Logger::write("Error: SE ESPERABA OUT PREVIAMENTE PARA IMPRIMIR");}
break;
case 69:
#line 306 "gramatica.y"
{Logger::write("Error: SE ESPERABA CADENA EN LA SENTENCIA OUT");}
break;
#line 845 "y.tab.c"
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
