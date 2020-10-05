#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
#define ID 257
#define CTE 258
#define FLOAT 259
#define LONGINT 260
#define INT 261
#define IF 262
#define ELSE 263
#define END_IF 264
#define OUT 265
#define MAYORIGUAL 266
#define MENORIGUAL 267
#define IGUAL 268
#define DISTINTO 269
#define CADENA 270
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
   16,   16,    9,    9,    9,   17,   17,   17,   18,   18,
   18,   18,   18,   18,   18,    6,    6,    6,    5,
};
short yylen[] = {                                         2,
    1,    1,    2,    1,    1,    1,    2,    2,    3,    2,
    4,    3,    1,    2,    2,    5,    3,    1,   15,    1,
    1,    4,    2,    6,    8,    7,    8,    0,    3,    3,
    3,    3,    3,    3,    1,    1,    3,    3,    1,    1,
    2,    1,    2,    1,    2,    1,    1,    1,    5,
};
short yydefred[] = {                                      0,
    0,   48,   47,   46,    0,    0,    0,    0,    0,    0,
    2,    4,    5,    6,    0,    0,   13,    0,    0,    0,
    0,    0,    0,    0,    0,    3,    0,    7,    8,   14,
   15,   39,   40,   42,   44,   12,    0,    0,    0,   36,
   18,    0,    0,    0,    0,    0,    0,   10,    0,   41,
   43,   45,   11,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    9,    0,
    0,   37,   38,   17,   16,    0,    0,    0,    0,    0,
   49,    0,   23,    0,    0,    0,    0,    0,    0,    0,
    0,   26,    0,   22,    0,   25,   27,    0,    0,    0,
    0,   20,   21,    0,    0,    0,   19,
};
short yydgoto[] = {                                       9,
   10,   11,   12,   13,   14,   15,   28,   16,   43,   17,
   18,   19,   42,   68,  104,   44,   39,   40,
};
short yysindex[] = {                                   -186,
  -19,    0,    0,    0,   -4,    9,   15, -190,    0, -186,
    0,    0,    0,    0, -180,   27,    0,   29,   31,  -44,
 -163,  -39, -173,  -39,   58,    0,  -22,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -234,    3,   -3,    0,
    0,   24,  -26,   59,   60,   61, -179,    0, -180,    0,
    0,    0,    0,  -39,  -39,  -39,  -39, -158,   44,  -39,
  -39,  -39,  -39, -186,   46, -166, -150,   25,    0,   -3,
   -3,    0,    0,    0,    0,    2,    2,    2,    2, -230,
    0,  -15,    0, -179, -168, -186, -146, -186, -145,   50,
 -201,    0, -122,    0, -144,    0,    0,   69, -161,   55,
 -191,    0,    0,   -6, -186, -105,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  118,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   78,    0,   78,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -41,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -36,
  -31,    0,    0,    0,    0,   79,   80,   81,   82,    0,
    0,    0,    0,    0,    0,    0,   65,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
  -48,   -2,    0,    0,    0,  -34,   76,    0,   -9,    0,
    0,    0,    0,    0,    0,  102,   38,   39,
};
#define YYTABLESIZE 243
short yytable[] = {                                      35,
   37,   35,   97,   35,   33,   37,   33,   26,   33,   34,
   38,   34,   67,   34,   36,   80,   54,   35,   55,  107,
   21,   49,   33,   50,   51,   52,    1,   34,    2,    3,
    4,    5,   86,   87,    6,   22,   48,   91,   57,   93,
    7,   20,    8,   56,   54,   54,   55,   55,   23,   89,
   76,   77,   78,   79,   24,    1,  106,    2,    3,    4,
    5,   53,   96,    6,   59,   85,   25,   58,   84,    7,
    1,    8,    2,    3,    4,    5,   27,   26,    6,    2,
    3,    4,  102,  103,    7,   29,    8,   30,   26,   31,
   26,   70,   71,   41,   72,   73,   45,   47,   74,   64,
   65,   66,   75,   26,   81,   82,   83,   88,   90,   92,
   95,   94,   99,   98,  100,  101,  105,    1,   28,   31,
   30,   29,   32,   24,   69,   46,    0,    0,    0,    0,
    0,    0,    0,    0,    1,    0,    2,    3,    4,    5,
    0,    0,    6,    0,    0,    0,    0,    0,    7,    0,
    8,    1,    0,    2,    3,    4,    5,    0,    0,    6,
    0,    0,    0,    0,    0,    7,    0,    8,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   32,   33,   34,   35,    0,   32,   33,   34,
   35,    0,    0,    0,   35,   35,   35,   35,    0,   33,
   33,   33,   33,    0,   34,   34,   34,   34,    0,   60,
   61,   62,   63,
};
short yycheck[] = {                                      41,
   45,   43,  125,   45,   41,   45,   43,   10,   45,   41,
   20,   43,   47,   45,   59,   64,   43,   59,   45,  125,
   40,   44,   59,  258,  259,  260,  257,   59,  259,  260,
  261,  262,  263,  264,  265,   40,   59,   86,   42,   88,
  271,   61,  273,   47,   43,   43,   45,   45,   40,   84,
   60,   61,   62,   63,   40,  257,  105,  259,  260,  261,
  262,   59,  264,  265,   41,   41,  257,   44,   44,  271,
  257,  273,  259,  260,  261,  262,  257,   80,  265,  259,
  260,  261,  274,  275,  271,   59,  273,   59,   91,   59,
   93,   54,   55,  257,   56,   57,  270,   40,  257,   41,
   41,   41,   59,  106,   59,  272,  257,  123,  277,  256,
   61,  257,   44,  258,  276,   61,  123,    0,   41,   41,
   41,   41,   41,   59,   49,   24,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  257,   -1,  259,  260,  261,  262,
   -1,   -1,  265,   -1,   -1,   -1,   -1,   -1,  271,   -1,
  273,  257,   -1,  259,  260,  261,  262,   -1,   -1,  265,
   -1,   -1,   -1,   -1,   -1,  271,   -1,  273,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  257,  258,  259,  260,   -1,  257,  258,  259,
  260,   -1,   -1,   -1,  266,  267,  268,  269,   -1,  266,
  267,  268,  269,   -1,  266,  267,  268,  269,   -1,  266,
  267,  268,  269,
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
"';'",0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"ID","CTE","FLOAT","LONGINT","INT","IF","ELSE","END_IF","OUT",
"MAYORIGUAL","MENORIGUAL","IGUAL","DISTINTO","CADENA","WHILE","LOOP","PROC",
"TRUE","FALSE","SHADOWING","NA","ERROR",
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
"condicion : expresion IGUAL expresion",
"condicion : expresion MENORIGUAL expresion",
"condicion : expresion MAYORIGUAL expresion",
"condicion : expresion DISTINTO expresion",
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
"imprimir : OUT '(' CADENA ')' ';'",
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
case 2:
#line 12 "gramatica.y"
{AccionesSintactico::imprime("bloque_sentencia");}
break;
case 3:
#line 13 "gramatica.y"
{AccionesSintactico::imprime("bloque_sentencia");}
break;
case 4:
#line 16 "gramatica.y"
{AccionesSintactico::imprime("declarativa");}
break;
case 5:
#line 17 "gramatica.y"
{AccionesSintactico::imprime("ejecutable");}
break;
case 6:
#line 18 "gramatica.y"
{AccionesSintactico::imprime("imprimir");}
break;
case 7:
#line 21 "gramatica.y"
{AccionesSintactico::imprime("declarativa");}
break;
case 8:
#line 22 "gramatica.y"
{AccionesSintactico::imprime("procedimiento");}
break;
case 9:
#line 26 "gramatica.y"
{AccionesSintactico::imprime("lista_variables");}
break;
case 10:
#line 27 "gramatica.y"
{AccionesSintactico::imprime("id de lista");}
break;
case 11:
#line 30 "gramatica.y"
{AccionesSintactico::imprime("expresion");}
break;
case 12:
#line 31 "gramatica.y"
{Logger::write("ASIGNACION VACIA TIENE QUE ENTRAR EN ARCHIVO SALIDA");}
break;
case 13:
#line 32 "gramatica.y"
{AccionesSintactico::imprime("inv proc");}
break;
case 14:
#line 33 "gramatica.y"
{AccionesSintactico::imprime("setencia_while");}
break;
case 15:
#line 34 "gramatica.y"
{AccionesSintactico::imprime("sentencia if");}
break;
case 16:
#line 37 "gramatica.y"
{AccionesSintactico::imprime("invocacion proc");}
break;
case 17:
#line 40 "gramatica.y"
{AccionesSintactico::imprime("parametros");}
break;
case 18:
#line 41 "gramatica.y"
{AccionesSintactico::imprime("id parametros");}
break;
case 19:
#line 44 "gramatica.y"
{AccionesSintactico::imprime("def proc");}
break;
case 22:
#line 51 "gramatica.y"
{AccionesSintactico::imprime("lista parametros");}
break;
case 23:
#line 52 "gramatica.y"
{AccionesSintactico::imprime("id listapar");}
break;
case 24:
#line 55 "gramatica.y"
{AccionesSintactico::imprime("if");}
break;
case 25:
#line 56 "gramatica.y"
{AccionesSintactico::imprime("if else");}
break;
case 26:
#line 57 "gramatica.y"
{yyerror("if error EN XDDDDDDDDDDDDDDDD");}
break;
case 27:
#line 60 "gramatica.y"
{AccionesSintactico::imprime("while");}
break;
case 29:
#line 64 "gramatica.y"
{AccionesSintactico::imprime("igual");}
break;
case 30:
#line 65 "gramatica.y"
{AccionesSintactico::imprime("menorigual");}
break;
case 31:
#line 66 "gramatica.y"
{AccionesSintactico::imprime("mayorigual");}
break;
case 32:
#line 67 "gramatica.y"
{AccionesSintactico::imprime("distinto");}
break;
case 33:
#line 71 "gramatica.y"
{AccionesSintactico::imprime("suma");}
break;
case 34:
#line 72 "gramatica.y"
{AccionesSintactico::imprime("resta");}
break;
case 35:
#line 73 "gramatica.y"
{AccionesSintactico::imprime("termino");}
break;
case 36:
#line 77 "gramatica.y"
{AccionesSintactico::imprime("factor");}
break;
case 37:
#line 78 "gramatica.y"
{AccionesSintactico::imprime("div");}
break;
case 38:
#line 79 "gramatica.y"
{AccionesSintactico::imprime("mult");}
break;
case 39:
#line 83 "gramatica.y"
{AccionesSintactico::imprime("factor");}
break;
case 40:
#line 84 "gramatica.y"
{AccionesSintactico::imprime("cte");}
break;
case 41:
#line 85 "gramatica.y"
{yyval = -1*yyvsp[0]; AccionesSintactico::imprime("se hizo negativo CTE");}
break;
case 43:
#line 87 "gramatica.y"
{yyval = -1*yyvsp[0]; AccionesSintactico::imprime("se hizo negativo FLOAT");}
break;
case 45:
#line 89 "gramatica.y"
{yyval = -1*yyvsp[0]; AccionesSintactico::imprime(" se hizo negativo LONGINT");}
break;
case 46:
#line 94 "gramatica.y"
{AccionesSintactico::imprime("INT");}
break;
case 47:
#line 95 "gramatica.y"
{AccionesSintactico::imprime("LONGINT");}
break;
case 48:
#line 96 "gramatica.y"
{AccionesSintactico::imprime("FLOAT");}
break;
case 49:
#line 99 "gramatica.y"
{AccionesSintactico::imprime("cadena");}
break;
#line 555 "y.tab.c"
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
