#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
#line 7 "gramatica.y"
typedef union {
    int entero;
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
    4,    4,    4,    4,    4,   10,   13,   13,    8,   15,
   15,   14,   14,   12,   12,   12,   11,   16,   16,   16,
   16,   16,   16,   16,    9,    9,    9,   17,   17,   17,
   18,   18,   18,   18,   18,    6,    6,    6,    5,
};
short yylen[] = {                                         2,
    1,    1,    2,    1,    1,    1,    2,    2,    3,    2,
    4,    3,    1,    2,    2,    5,    3,    1,   15,    1,
    1,    4,    2,    6,    8,    7,    8,    0,    3,    3,
    3,    3,    3,    3,    3,    3,    1,    1,    3,    3,
    1,    1,    2,    1,    2,    1,    1,    1,    5,
};
short yydefred[] = {                                      0,
    0,   48,   47,   46,    0,    0,    0,    0,    0,    0,
    2,    4,    5,    6,    0,    0,   13,    0,    0,    0,
    0,    0,    0,    0,    0,    3,    0,    7,    8,   14,
   15,   41,   42,   44,   12,    0,    0,    0,   38,   18,
    0,    0,    0,    0,    0,    0,   10,    0,   43,   45,
   11,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    9,    0,
    0,   39,   40,   17,   16,    0,    0,    0,    0,    0,
    0,    0,   49,    0,   23,    0,    0,    0,    0,    0,
    0,    0,    0,   26,    0,   22,    0,   25,   27,    0,
    0,    0,    0,   20,   21,    0,    0,    0,   19,
};
short yydgoto[] = {                                       9,
   10,   11,   12,   13,   14,   15,   28,   16,   42,   17,
   18,   19,   41,   68,  106,   43,   38,   39,
};
short yysindex[] = {                                   -170,
  -27,    0,    0,    0,   -5,    5,   16, -230,    0, -170,
    0,    0,    0,    0, -219,  -16,    0,   19,   24,  -44,
 -193,  -39, -167,  -39,   59,    0,  -11,    0,    0,    0,
    0,    0,    0,    0,    0, -173,  -13,   -6,    0,    0,
    3,  -23,   60,   62,   68, -162,    0, -219,    0,    0,
    0,  -39,  -39,  -39,  -39, -145,   54,  -39,  -39,  -39,
  -39,  -39,  -39, -170,   57, -157, -142,   14,    0,   -6,
   -6,    0,    0,    0,    0,   36,   36,   36,   36,   36,
   36, -197,    0,   -4,    0, -162, -159, -170, -138, -170,
 -137,   61, -188,    0, -122,    0, -136,    0,    0,   77,
 -151,   64, -169,    0,    0,    4, -170, -100,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  126,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   87,    0,   87,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -41,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -36,
  -31,    0,    0,    0,    0,   88,   89,   90,   91,   92,
   93,    0,    0,    0,    0,    0,    0,    0,   80,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
  -48,   -2,    0,    0,    0,  -29,   94,    0,   -9,    0,
    0,    0,    0,    0,    0,  117,   55,   56,
};
#define YYTABLESIZE 246
short yytable[] = {                                      37,
   36,   37,   99,   37,   35,   36,   35,   26,   35,   36,
   37,   36,   21,   36,   35,   82,   67,   37,   37,   52,
   37,   53,   35,   35,  109,   35,   25,   36,   36,   52,
   36,   53,   48,   20,   22,   55,   63,   27,   62,   93,
   54,   95,   29,   57,   23,   51,   56,   47,   76,   77,
   78,   79,   80,   81,   87,   24,   91,   86,  108,    1,
    2,    3,    4,   40,    5,   88,   89,    6,    1,    2,
    3,    4,    7,    5,    8,   98,    6,   30,   52,   26,
   53,    7,   31,    8,   49,   50,    1,    2,    3,    4,
   26,    5,   26,   44,    6,    2,    3,    4,   46,    7,
   64,    8,   65,  104,  105,   26,   70,   71,   66,   72,
   73,   74,   75,   84,   85,   83,   92,   94,   90,   96,
  101,   97,  100,  102,  103,    1,  107,   28,   32,   31,
   29,   30,   33,   34,    1,    2,    3,    4,   24,    5,
   45,   69,    6,    0,    0,    0,    0,    7,    0,    8,
    0,    0,    0,    0,    0,    0,    1,    2,    3,    4,
    0,    5,    0,    0,    6,    0,    0,    0,    0,    7,
    0,    8,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   32,   33,   34,    0,    0,   32,   33,   34,
    0,    0,    0,    0,   37,   37,   37,   37,    0,   35,
   35,   35,   35,    0,   36,   36,   36,   36,    0,    0,
    0,    0,   58,   59,   60,   61,
};
short yycheck[] = {                                      41,
   45,   43,  125,   45,   41,   45,   43,   10,   45,   41,
   20,   43,   40,   45,   59,   64,   46,   59,   60,   43,
   62,   45,   59,   60,  125,   62,  257,   59,   60,   43,
   62,   45,   44,   61,   40,   42,   60,  257,   62,   88,
   47,   90,   59,   41,   40,   59,   44,   59,   58,   59,
   60,   61,   62,   63,   41,   40,   86,   44,  107,  257,
  258,  259,  260,  257,  262,  263,  264,  265,  257,  258,
  259,  260,  270,  262,  272,  264,  265,   59,   43,   82,
   45,  270,   59,  272,  258,  259,  257,  258,  259,  260,
   93,  262,   95,  261,  265,  258,  259,  260,   40,  270,
   41,  272,   41,  273,  274,  108,   52,   53,   41,   54,
   55,  257,   59,  271,  257,   59,  276,  256,  123,  257,
   44,   61,  259,  275,   61,    0,  123,   41,   41,   41,
   41,   41,   41,   41,  257,  258,  259,  260,   59,  262,
   24,   48,  265,   -1,   -1,   -1,   -1,  270,   -1,  272,
   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,  260,
   -1,  262,   -1,   -1,  265,   -1,   -1,   -1,   -1,  270,
   -1,  272,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  257,  258,  259,   -1,   -1,  257,  258,  259,
   -1,   -1,   -1,   -1,  266,  267,  268,  269,   -1,  266,
  267,  268,  269,   -1,  266,  267,  268,  269,   -1,   -1,
   -1,   -1,  266,  267,  268,  269,
};
#define YYFINAL 9
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
"true_false : TRUE",
"true_false : FALSE",
"lista_de_parametros : lista_de_parametros ',' tipo ID",
"lista_de_parametros : tipo ID",
"sentencia_if : IF '(' condicion ')' bloque_sentencia END_IF",
"sentencia_if : IF '(' condicion ')' bloque_sentencia ELSE bloque_sentencia END_IF",
"sentencia_if : IF '(' condicion ')' bloque_sentencia END_IF error",
"sentencia_while : WHILE '(' condicion ')' LOOP '{' bloque_sentencia '}'",
"condicion :",
"condicion : expresion EQUAL expresion",
"condicion : expresion DIFFERENT expresion",
"condicion : expresion LESS_OR_EQUAL expresion",
"condicion : expresion GREATER_OR_EQUAL expresion",
"condicion : expresion '>' expresion",
"condicion : expresion '<' expresion",
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
case 8:
#line 32 "gramatica.y"
{Logger::write("Declaracion de procedimiento");}
break;
case 9:
#line 36 "gramatica.y"
{Logger::write("lista_de_variables");}
break;
case 11:
#line 41 "gramatica.y"
{Logger::write("Asignacion");}
break;
case 12:
#line 42 "gramatica.y"
{Logger::write("Error:Asignacion vacia");}
break;
case 13:
#line 43 "gramatica.y"
{Logger::write("invocacion procedimiento");}
break;
case 14:
#line 44 "gramatica.y"
{Logger::write("sentencia while");}
break;
case 15:
#line 45 "gramatica.y"
{Logger::write("sentencia if");}
break;
case 22:
#line 68 "gramatica.y"
{Logger::write("lista_de_parametros");}
break;
case 29:
#line 83 "gramatica.y"
{Logger::write("Condicion igual");}
break;
case 30:
#line 84 "gramatica.y"
{Logger::write("Condicion distinto");}
break;
case 31:
#line 85 "gramatica.y"
{Logger::write("Condicion menorigual");}
break;
case 32:
#line 86 "gramatica.y"
{Logger::write("Condicion mayorIgual");}
break;
case 33:
#line 87 "gramatica.y"
{Logger::write("Condicion de mayor");}
break;
case 34:
#line 88 "gramatica.y"
{Logger::write("Condicion de menor");}
break;
case 35:
#line 92 "gramatica.y"
{Logger::write("suma");}
break;
case 36:
#line 93 "gramatica.y"
{Logger::write("resta");}
break;
case 43:
#line 110 "gramatica.y"
{ Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 45:
#line 112 "gramatica.y"
{ Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,yyvsp[0].cadena);}
break;
case 49:
#line 121 "gramatica.y"
{Logger::write("Detecto sentencia OUT");}
break;
#line 461 "y.tab.c"
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
