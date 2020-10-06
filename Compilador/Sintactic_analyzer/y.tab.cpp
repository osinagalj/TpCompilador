#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
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
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    1,    1,    2,    2,    2,    3,    3,    7,    7,
    4,    4,    4,    4,    4,   10,   13,   13,    8,   15,
   15,   14,   14,   12,   12,   12,   11,   16,   16,   16,
   16,   16,   16,   16,    9,    9,    9,   17,   17,   17,
   18,   18,   18,   18,   18,   18,   18,    6,    6,    6,
    5,
};
short yylen[] = {                                         2,
    1,    1,    2,    1,    1,    1,    2,    2,    3,    2,
    4,    3,    1,    2,    2,    5,    3,    1,   15,    1,
    1,    4,    2,    6,    8,    7,    8,    0,    3,    3,
    3,    3,    3,    3,    3,    3,    1,    1,    3,    3,
    1,    1,    2,    1,    2,    1,    2,    1,    1,    1,
    5,
};
short yydefred[] = {                                      0,
    0,   50,   49,   48,    0,    0,    0,    0,    0,    0,
    2,    4,    5,    6,    0,    0,   13,    0,    0,    0,
    0,    0,    0,    0,    0,    3,    0,    7,    8,   14,
   15,   41,   42,   44,   46,   12,    0,    0,    0,   38,
   18,    0,    0,    0,    0,    0,    0,   10,    0,   43,
   45,   47,   11,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    9,    0,    0,   39,   40,   17,   16,    0,    0,    0,
    0,    0,    0,    0,   51,    0,   23,    0,    0,    0,
    0,    0,    0,    0,    0,   26,    0,   22,    0,   25,
   27,    0,    0,    0,    0,   20,   21,    0,    0,    0,
   19,
};
short yydgoto[] = {                                       9,
   10,   11,   12,   13,   14,   15,   28,   16,   43,   17,
   18,   19,   42,   70,  108,   44,   39,   40,
};
short yysindex[] = {                                   -161,
  -27,    0,    0,    0,   -5,    5,   21, -230,    0, -161,
    0,    0,    0,    0, -219,  -16,    0,    6,   33,  -44,
 -200,  -39, -168,  -39,   40,    0,  -11,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -173,  -13,   -6,    0,
    0,    3,  -23,   56,   60,   65, -146,    0, -219,    0,
    0,    0,    0,  -39,  -39,  -39,  -39, -150,   50,  -39,
  -39,  -39,  -39,  -39,  -39, -161,   52, -156, -140,   29,
    0,   -6,   -6,    0,    0,    0,    0,   45,   45,   45,
   45,   45,   45, -197,    0,   -4,    0, -146, -159, -161,
 -136, -161, -135,   62, -182,    0, -122,    0, -137,    0,
    0,   80, -151,   66, -225,    0,    0,    7, -161, -100,
    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  126,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   87,    0,   87,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -41,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -36,  -31,    0,    0,    0,    0,   88,   90,   91,
   92,   93,   95,    0,    0,    0,    0,    0,    0,    0,
   81,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
short yygindex[] = {                                      0,
  -50,   -2,    0,    0,    0,  -30,   94,    0,   -9,    0,
    0,    0,    0,    0,    0,  118,   17,   47,
};
#define YYTABLESIZE 247
short yytable[] = {                                      37,
   37,   37,  101,   37,   35,   37,   35,   26,   35,   36,
   38,   36,   21,   36,   36,   84,   69,   37,   37,   54,
   37,   55,   35,   35,  111,   35,   25,   36,   36,   54,
   36,   55,   49,   20,   22,   57,   65,   27,   64,   95,
   56,   97,   29,   59,   23,   53,   58,   48,  106,  107,
   78,   79,   80,   81,   82,   83,   41,   93,  110,    1,
   24,    2,    3,    4,   30,    5,   90,   91,    6,   89,
   72,   73,   88,    7,    1,    8,    2,    3,    4,   47,
    5,   26,  100,    6,   50,   51,   52,   54,    7,   55,
    8,   31,   26,   45,   26,    1,   66,    2,    3,    4,
   67,    5,   74,   75,    6,   68,   76,   26,   77,    7,
   85,    8,    2,    3,    4,   86,   87,   94,   92,   96,
  102,   98,   99,  103,  104,    1,  105,   28,   32,  109,
   31,   29,   30,   33,    1,   34,    2,    3,    4,   24,
    5,   46,   71,    6,    0,    0,    0,    0,    7,    0,
    8,    0,    0,    0,    0,    0,    1,    0,    2,    3,
    4,    0,    5,    0,    0,    6,    0,    0,    0,    0,
    7,    0,    8,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   32,   33,   34,   35,    0,   32,   33,   34,
   35,    0,    0,    0,    0,   37,   37,   37,   37,    0,
   35,   35,   35,   35,    0,   36,   36,   36,   36,    0,
    0,    0,    0,   60,   61,   62,   63,
};
short yycheck[] = {                                      41,
   45,   43,  125,   45,   41,   45,   43,   10,   45,   41,
   20,   43,   40,   45,   59,   66,   47,   59,   60,   43,
   62,   45,   59,   60,  125,   62,  257,   59,   60,   43,
   62,   45,   44,   61,   40,   42,   60,  257,   62,   90,
   47,   92,   59,   41,   40,   59,   44,   59,  274,  275,
   60,   61,   62,   63,   64,   65,  257,   88,  109,  257,
   40,  259,  260,  261,   59,  263,  264,  265,  266,   41,
   54,   55,   44,  271,  257,  273,  259,  260,  261,   40,
  263,   84,  265,  266,  258,  259,  260,   43,  271,   45,
  273,   59,   95,  262,   97,  257,   41,  259,  260,  261,
   41,  263,   56,   57,  266,   41,  257,  110,   59,  271,
   59,  273,  259,  260,  261,  272,  257,  277,  123,  256,
  258,  257,   61,   44,  276,    0,   61,   41,   41,  123,
   41,   41,   41,   41,  257,   41,  259,  260,  261,   59,
  263,   24,   49,  266,   -1,   -1,   -1,   -1,  271,   -1,
  273,   -1,   -1,   -1,   -1,   -1,  257,   -1,  259,  260,
  261,   -1,  263,   -1,   -1,  266,   -1,   -1,   -1,   -1,
  271,   -1,  273,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  257,  258,  259,  260,   -1,  257,  258,  259,
  260,   -1,   -1,   -1,   -1,  267,  268,  269,  270,   -1,
  267,  268,  269,  270,   -1,  267,  268,  269,  270,   -1,
   -1,   -1,   -1,  267,  268,  269,  270,
};
#define YYFINAL 9
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 278
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"ID","CTE","FLOAT","LONGINT","INT","STRING","IF","ELSE",
"END_IF","OUT","GREATER_OR_EQUAL","LESS_OR_EQUAL","EQUAL","DIFFERENT","WHILE",
"LOOP","PROC","TRUE","FALSE","SHADOWING","NA","ERROR",
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
"procedimiento : PROC ID '(' lista_de_parametros ')' NA '=' CTE ',' SHADOWING '=' true_false '{' bloque_sentencia '}'",
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
"factor : CTE",
"factor : '-' CTE",
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
#ifndef YYSTYPE
typedef int YYSTYPE;
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
#line 28 "gramatica.y"
{Logger::write("Declaracion de procedimiento");}
break;
case 9:
#line 32 "gramatica.y"
{Logger::write("lista_de_variables");}
break;
case 11:
#line 37 "gramatica.y"
{Logger::write("Asignacion");}
break;
case 12:
#line 38 "gramatica.y"
{Logger::write("Error:Asignacion vacia");}
break;
case 13:
#line 39 "gramatica.y"
{Logger::write("invocacion procedimiento");}
break;
case 14:
#line 40 "gramatica.y"
{Logger::write("sentencia while");}
break;
case 15:
#line 41 "gramatica.y"
{Logger::write("sentencia if");}
break;
case 22:
#line 64 "gramatica.y"
{Logger::write("lista_de_parametros");}
break;
case 29:
#line 79 "gramatica.y"
{Logger::write("Condicion igual");}
break;
case 30:
#line 80 "gramatica.y"
{Logger::write("Condicion distinto");}
break;
case 31:
#line 81 "gramatica.y"
{Logger::write("Condicion menorigual");}
break;
case 32:
#line 82 "gramatica.y"
{Logger::write("Condicion mayorIgual");}
break;
case 33:
#line 83 "gramatica.y"
{Logger::write("Condicion de mayor");}
break;
case 34:
#line 84 "gramatica.y"
{Logger::write("Condicion de menor");}
break;
case 35:
#line 88 "gramatica.y"
{Logger::write("suma");}
break;
case 36:
#line 89 "gramatica.y"
{Logger::write("resta");}
break;
case 43:
#line 106 "gramatica.y"
{yyval = -1*yyvsp[0];  Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,yyvsp[0]);}
break;
case 47:
#line 110 "gramatica.y"
{yyval = -1*yyvsp[0]; Sintactic_actions::negativizarVar(Lexical_analyzer::symbolTable,yyvsp[0]);}
break;
case 51:
#line 119 "gramatica.y"
{Logger::write("Detecto sentencia OUT");}
break;
#line 466 "y.tab.c"
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
