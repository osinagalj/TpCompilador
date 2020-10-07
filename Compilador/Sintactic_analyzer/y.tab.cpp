#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
#line 7 "Gramatica.y"
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
    0,    1,    1,    2,    2,    2,    3,    3,    7,    7,
    4,    4,    4,    4,    4,   10,   13,   13,    8,    8,
    8,    8,   15,   15,   14,   14,   12,   12,   12,   12,
   12,   11,   11,   11,   16,   16,   16,   16,   16,   16,
   16,   16,   16,   16,   16,    9,    9,    9,   17,   17,
   17,   18,   18,   18,   18,   18,    6,    6,    6,    5,
    5,    5,
};
short yylen[] = {                                         2,
    1,    1,    2,    1,    1,    1,    2,    2,    3,    2,
    4,    3,    1,    2,    2,    5,    3,    1,   15,   14,
   11,   11,    1,    1,    4,    2,    6,    5,    8,    7,
    5,    8,    7,    7,    3,    2,    3,    2,    3,    2,
    3,    3,    2,    3,    2,    3,    3,    1,    1,    3,
    3,    1,    1,    2,    1,    2,    1,    1,    1,    5,
    4,    4,
};
short yydefred[] = {                                      0,
    0,   59,   58,   57,    0,    0,    0,    0,    0,    0,
    0,    2,    4,    5,    6,    0,    0,   13,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   52,   53,   55,
    0,    0,    0,    0,    0,   49,    3,    0,    7,    8,
   14,   15,   12,    0,   18,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   54,   56,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   10,    0,   11,
    0,    0,    0,    0,   62,    0,    0,   26,    0,    0,
   61,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   50,   51,    9,   17,   16,    0,   60,    0,    0,
    0,    0,    0,    0,   31,    0,   27,    0,    0,    0,
    0,   25,    0,    0,    0,    0,   34,    0,    0,    0,
   33,   29,   32,   23,   24,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   21,    0,   22,    0,
    0,    0,    0,    0,    0,   20,   19,
};
short yydgoto[] = {                                      10,
   11,   12,   13,   14,   15,   16,   39,   17,   33,   18,
   19,   20,   46,   53,  126,   34,   35,   36,
};
short yysindex[] = {                                     66,
  -33,    0,    0,    0,  -29,  -18,  -13,  -36,   76,    0,
   66,    0,    0,    0,    0, -252,  -14,    0,   -5,   14,
  -44, -226,  -22,  -28,  -22,   -2, -241,    0,    0,    0,
   34, -209,   91,   36,  -26,    0,    0,  -30,    0,    0,
    0,    0,    0,  -35,    0,   -9,   40,   42,   25,   44,
 -241, -177,   -8,   27,    0,    0,  -22,  -22,  -22,  -22,
  -22,  -22,  -22,  -22,  -31,  -22,  -22,    0, -252,    0,
 -170,   32,   66,   33,    0, -121,   -4,    0, -241, -183,
    0,   -1,   -1,   -1,   -1,   -1,   -1,  -26,  -26,  -27,
  -15,    0,    0,    0,    0,    0,  -40,    0,  -25,   66,
 -219, -163,   38,   66,    0,   66,    0,   66,   -6,   41,
   43,    0, -164,    3,   12,   21,    0, -214, -159,   59,
    0,    0,    0,    0,    0,  -16,  -41, -174,   66, -167,
   66,   49,   30,   50,   39, -214,    0, -214,    0,  -11,
  -10,   66,   66,   48,   57,    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  105,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   73,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   68,   74,    0,   82,
   84,   85,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   86,   88,   89,   90,   96,  102,   79,   99,    0,
    0,    0,    0,    0,    0,    0,   58,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   93,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
  -53,   63,    0,    0,    0,  -21,   78,    0,    5,    0,
    0,    0,    0,   94,  -97,   23,    8,    2,
};
#define YYTABLESIZE 368
short yytable[] = {                                       9,
   32,  100,  130,   27,   38,   52,   22,   63,    9,   64,
   23,   91,   49,   69,   43,   67,    2,    3,    4,   97,
   66,   24,   32,   70,    9,   44,   25,   21,   68,   52,
   45,   72,   80,    9,   71,   79,  101,   51,  140,   79,
  141,   63,    9,   64,   40,   47,  109,   50,   55,   56,
  114,    9,  115,   41,  116,  110,  111,  102,  124,  125,
    9,   82,   83,   84,   85,   86,   87,   92,   93,    9,
   88,   89,   42,   37,   54,  133,   65,  135,    9,   78,
   73,  131,   74,   75,   76,   81,   95,    9,  144,  145,
   96,   98,  103,  112,  120,  104,    9,  108,  113,  127,
  132,  118,  128,  119,    1,    9,  129,  134,   40,  136,
  138,  142,  143,   48,   38,   48,   28,   48,  117,   46,
   32,   46,   36,   46,   43,   45,   41,  121,   39,   35,
   37,   48,   48,   63,   48,   64,   42,   46,   46,   47,
   46,   47,   44,   47,   77,  123,   94,    0,    0,   99,
   62,   30,   61,   37,  137,    0,    0,   47,   47,   37,
   47,    0,    0,  139,    0,    0,    0,    0,    0,    0,
    0,   37,  146,    0,    0,    0,   37,   37,   37,    0,
    0,  147,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   37,    0,   37,    0,    0,
    0,    0,    0,    0,    0,    0,   37,   37,    0,    0,
    0,    0,   28,   29,   30,    0,    1,    2,    3,    4,
   26,    5,  106,  107,    6,    1,    2,    3,    4,    7,
    5,    8,   48,    6,   28,   29,   30,    0,    7,   90,
    8,    1,    2,    3,    4,    0,    5,    0,  105,    6,
    1,    2,    3,    4,    7,    5,    8,    0,    6,    1,
    2,    3,    4,    7,    5,    8,    0,    6,    1,    2,
    3,    4,    7,    5,    8,  122,    6,    1,    2,    3,
    4,    7,    5,    8,    0,    6,    1,    2,    3,    4,
    7,    5,    8,    0,    6,    1,    2,    3,    4,    7,
    5,    8,    0,    6,    1,    2,    3,    4,    7,    5,
    8,    0,    6,    1,    2,    3,    4,    7,    5,    8,
    0,    6,    1,    2,    3,    4,    7,    5,    8,    0,
    6,    0,   28,   29,   30,    7,   31,    8,   48,   48,
   48,   48,    0,    0,   46,   46,   46,   46,    0,    0,
    0,    0,    0,    0,    0,    0,   57,   58,   59,   60,
    0,    0,    0,    0,   47,   47,   47,   47,
};
short yycheck[] = {                                      40,
   45,  123,   44,   40,  257,   27,   40,   43,   40,   45,
   40,   65,   41,   44,   59,   42,  258,  259,  260,   73,
   47,   40,   45,   59,   40,   21,   40,   61,   59,   51,
  257,   41,   41,   40,   44,   44,   41,   40,  136,   44,
  138,   43,   40,   45,   59,   23,  100,   25,  258,  259,
  104,   40,  106,   59,  108,  275,  276,   79,  273,  274,
   40,   57,   58,   59,   60,   61,   62,   66,   67,   40,
   63,   64,   59,   11,   41,  129,   41,  131,   40,  257,
   41,  123,   41,   59,   41,   59,  257,   40,  142,  143,
   59,   59,  276,  257,  259,  123,   40,  123,   61,  259,
  275,   61,   44,   61,    0,   40,  123,  275,   41,   61,
   61,  123,  123,   41,   41,   43,   59,   45,  125,   41,
   45,   43,   41,   45,   41,   41,   41,  125,   41,   41,
   41,   59,   60,   43,   62,   45,   41,   59,   60,   41,
   62,   43,   41,   45,   51,  125,   69,   -1,   -1,  271,
   60,   59,   62,   91,  125,   -1,   -1,   59,   60,   97,
   62,   -1,   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  109,  125,   -1,   -1,   -1,  114,  115,  116,   -1,
   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  133,   -1,  135,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  144,  145,   -1,   -1,
   -1,   -1,  257,  258,  259,   -1,  257,  258,  259,  260,
  257,  262,  263,  264,  265,  257,  258,  259,  260,  270,
  262,  272,  261,  265,  257,  258,  259,   -1,  270,  271,
  272,  257,  258,  259,  260,   -1,  262,   -1,  264,  265,
  257,  258,  259,  260,  270,  262,  272,   -1,  265,  257,
  258,  259,  260,  270,  262,  272,   -1,  265,  257,  258,
  259,  260,  270,  262,  272,  264,  265,  257,  258,  259,
  260,  270,  262,  272,   -1,  265,  257,  258,  259,  260,
  270,  262,  272,   -1,  265,  257,  258,  259,  260,  270,
  262,  272,   -1,  265,  257,  258,  259,  260,  270,  262,
  272,   -1,  265,  257,  258,  259,  260,  270,  262,  272,
   -1,  265,  257,  258,  259,  260,  270,  262,  272,   -1,
  265,   -1,  257,  258,  259,  270,  261,  272,  266,  267,
  268,  269,   -1,   -1,  266,  267,  268,  269,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  266,  267,  268,  269,
   -1,   -1,   -1,   -1,  266,  267,  268,  269,
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
#line 31 "Gramatica.y"
{Logger::write("Declaracion de variables");}
break;
case 8:
#line 32 "Gramatica.y"
{Logger::write("Declaracion de procedimiento");}
break;
case 11:
#line 41 "Gramatica.y"
{Logger::write("Asignacion");}
break;
case 12:
#line 42 "Gramatica.y"
{Logger::write("Error: Asignacion vacia");}
break;
case 13:
#line 43 "Gramatica.y"
{Logger::write("invocacion procedimiento");}
break;
case 14:
#line 44 "Gramatica.y"
{Logger::write("sentencia while");}
break;
case 15:
#line 45 "Gramatica.y"
{Logger::write("sentencia if");}
break;
case 19:
#line 58 "Gramatica.y"
{Sintactic_actions::check_list_parametros();}
break;
case 20:
#line 59 "Gramatica.y"
{Logger::write("Error: FALTA ID");}
break;
case 21:
#line 60 "Gramatica.y"
{Logger::write("Error: FALTA ESPECIFICAR VALOR NA");}
break;
case 22:
#line 61 "Gramatica.y"
{Logger::write("Error: FALTA ESPECIFICAR VALOR SHADOWING");}
break;
case 25:
#line 70 "Gramatica.y"
{Logger::write("lista_de_variables"); Sintactic_actions::contadorParametro++;}
break;
case 26:
#line 71 "Gramatica.y"
{Sintactic_actions::contadorParametro++;}
break;
case 27:
#line 75 "Gramatica.y"
{Logger::write("Sentencia IF");}
break;
case 28:
#line 76 "Gramatica.y"
{Logger::write("Error: FALTA END_IF");}
break;
case 29:
#line 77 "Gramatica.y"
{Logger::write("Sentencia IF-ELSE");}
break;
case 30:
#line 78 "Gramatica.y"
{Logger::write("Error: FALTA END_IF");}
break;
case 31:
#line 79 "Gramatica.y"
{Logger::write("Error: FALTA EL IF");}
break;
case 32:
#line 84 "Gramatica.y"
{Logger::write("Sentencia WHILE");}
break;
case 33:
#line 85 "Gramatica.y"
{Logger::write("Error: FALTA 'WHILE' EN LA SENTENCIA");}
break;
case 34:
#line 86 "Gramatica.y"
{Logger::write("Error: FALTA 'LOOP' EN SENTENCIA WHILE");}
break;
case 35:
#line 90 "Gramatica.y"
{Logger::write("Condicion igual");}
break;
case 36:
#line 91 "Gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 37:
#line 92 "Gramatica.y"
{Logger::write("Condicion distinto");}
break;
case 38:
#line 93 "Gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 39:
#line 94 "Gramatica.y"
{Logger::write("Condicion menorigual");}
break;
case 40:
#line 95 "Gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 41:
#line 96 "Gramatica.y"
{Logger::write("Condicion mayorIgual");}
break;
case 42:
#line 97 "Gramatica.y"
{Logger::write("Condicion de mayor");}
break;
case 43:
#line 98 "Gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 44:
#line 99 "Gramatica.y"
{Logger::write("Condicion de menor");}
break;
case 45:
#line 100 "Gramatica.y"
{Logger::write("Error: SE ESPERABA EXPRESION DE LADO DERECHO DE COMPARACIÓN");}
break;
case 46:
#line 104 "Gramatica.y"
{Logger::write("suma");}
break;
case 47:
#line 105 "Gramatica.y"
{Logger::write("resta");}
break;
case 50:
#line 112 "Gramatica.y"
{ Sintactic_actions::check_division_zero(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 54:
#line 119 "Gramatica.y"
{ Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 56:
#line 121 "Gramatica.y"
{ Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 60:
#line 131 "Gramatica.y"
{Logger::write("Detecto sentencia OUT");}
break;
case 61:
#line 132 "Gramatica.y"
{Logger::write("Error: SE ESPERABA OUT PREVIAMENTE PARA IMPRIMIR");}
break;
case 62:
#line 133 "Gramatica.y"
{Logger::write("Error: SE ESPERABA CADENA EN LA SENTENCIA OUT");}
break;
#line 598 "y.tab.c"
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
