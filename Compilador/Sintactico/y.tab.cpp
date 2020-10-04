#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
#define ID 257
#define CTE 258
#define IF 259
#define ELSE 260
#define END_IF 261
#define THEN 262
#define OUT 263
#define FUNC 264
#define RETURN 265
#define ULONGINT 266
#define FLOAT 267
#define INT 268
#define WHILE 269
#define ERROR 270
#define LOOP 271
#define LONGINT 272
#define MAYORIGUAL 273
#define MENORIGUAL 274
#define IGUAL 275
#define DISTINTO 276
#define CADENA 277
#define DIGITO 278
#define F_MINUSCLA 279
#define L_MINUSCULA 280
#define MAYUSCULA 281
#define MINUSCULA 282
#define PROC 283
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    1,    1,    2,    2,    2,    3,    3,    7,    7,
    4,    4,    4,    4,   10,   13,   13,    8,   14,   14,
   12,   12,   11,   15,   15,   15,   15,   15,    9,    9,
    9,   16,   16,   16,   17,   17,   17,   17,    6,    6,
    6,    5,
};
short yylen[] = {                                         2,
    1,    1,    2,    1,    1,    1,    2,    2,    3,    2,
    4,    1,    2,    2,    5,    3,    1,    8,    4,    2,
    6,    8,    8,    0,    3,    3,    3,    3,    3,    3,
    1,    1,    3,    3,    1,    1,    1,    2,    1,    1,
    1,    5,
};
short yydefred[] = {                                      0,
    0,    0,    0,   41,   39,    0,   40,    0,    0,    0,
    2,    4,    5,    6,    0,    0,   12,    0,    0,    0,
    0,    0,    0,    0,    0,    3,    0,    7,    8,   13,
   14,   35,   37,   36,    0,    0,    0,   32,   17,    0,
    0,    0,    0,    0,    0,   10,    0,   38,   11,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    9,    0,    0,   33,   34,   16,
   15,    0,    0,    0,    0,    0,   42,    0,   20,    0,
    0,    0,   21,    0,    0,    0,    0,    0,   19,    0,
   22,   23,   18,
};
short yydgoto[] = {                                       9,
   10,   11,   12,   13,   14,   15,   28,   16,   41,   17,
   18,   19,   40,   64,   42,   37,   38,
};
short yysindex[] = {                                   -190,
  -29,  -15,    9,    0,    0,   11,    0, -235,    0, -190,
    0,    0,    0,    0, -200,    7,    0,   15,   21,  -44,
 -189,  -44, -196,  -44,   50,    0,  -23,    0,    0,    0,
    0,    0,    0,    0, -166,  -19,   17,    0,    0,   14,
  -26,   53,   54,   55, -197,    0, -200,    0,    0,  -44,
  -44,  -44,  -44, -160,   39,  -44,  -44,  -44,  -44, -190,
   40, -171, -156,   47,    0,   17,   17,    0,    0,    0,
    0,   -2,   -2,   -2,   -2, -230,    0,  -21,    0, -197,
  -20, -190,    0, -190, -153, -190, -207, -122,    0, -105,
    0,    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  105,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   65,    0,   65,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -41,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -36,  -31,    0,    0,    0,
    0,   66,   67,   68,   69,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
short yygindex[] = {                                      0,
    3,   -4,    0,    0,    0,  -32,   64,    0,  -12,    0,
    0,    0,    0,    0,   88,  -35,  -18,
};
#define YYTABLESIZE 250
short yytable[] = {                                      31,
   35,   31,   92,   31,   29,   26,   29,   36,   29,   30,
   21,   30,   63,   30,   66,   67,   50,   31,   51,   93,
   47,   25,   29,   50,   22,   51,    1,   30,    2,   82,
   83,   20,    3,   68,   69,   46,    4,    5,    6,   49,
   50,    7,   51,   72,   73,   74,   75,   85,   23,    1,
   24,    2,    8,   91,   55,    3,   27,   54,   53,    4,
    5,    6,   76,   52,    7,   29,    1,   39,    2,    4,
    5,   26,    3,   30,    7,    8,    4,    5,    6,   31,
   43,    7,   26,   26,   87,   26,   88,   81,   90,   45,
   80,   48,    8,   60,   61,   62,   70,   71,   77,   78,
   79,   84,   86,   89,    1,   24,   27,   26,   25,   28,
   65,   44,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    1,    0,    2,    0,    0,    0,
    3,    0,    0,    0,    4,    5,    6,    0,    0,    7,
    0,    1,    0,    2,    0,    0,    0,    3,    0,    0,
    8,    4,    5,    6,    0,    0,    7,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    8,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   32,   33,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   34,    0,    0,
    0,   31,   31,   31,   31,    0,   29,   29,   29,   29,
    0,   30,   30,   30,   30,    0,   56,   57,   58,   59,
};
short yycheck[] = {                                      41,
   45,   43,  125,   45,   41,   10,   43,   20,   45,   41,
   40,   43,   45,   45,   50,   51,   43,   59,   45,  125,
   44,  257,   59,   43,   40,   45,  257,   59,  259,  260,
  261,   61,  263,   52,   53,   59,  267,  268,  269,   59,
   43,  272,   45,   56,   57,   58,   59,   80,   40,  257,
   40,  259,  283,  261,   41,  263,  257,   44,   42,  267,
  268,  269,   60,   47,  272,   59,  257,  257,  259,  267,
  268,   76,  263,   59,  272,  283,  267,  268,  269,   59,
  277,  272,   87,   88,   82,   90,   84,   41,   86,   40,
   44,  258,  283,   41,   41,   41,  257,   59,   59,  271,
  257,  123,  123,  257,    0,   41,   41,   41,   41,   41,
   47,   24,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  257,   -1,  259,   -1,   -1,   -1,
  263,   -1,   -1,   -1,  267,  268,  269,   -1,   -1,  272,
   -1,  257,   -1,  259,   -1,   -1,   -1,  263,   -1,   -1,
  283,  267,  268,  269,   -1,   -1,  272,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  283,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  257,  258,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  272,   -1,   -1,
   -1,  273,  274,  275,  276,   -1,  273,  274,  275,  276,
   -1,  273,  274,  275,  276,   -1,  273,  274,  275,  276,
};
#define YYFINAL 9
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 283
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
"';'",0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"ID","CTE","IF","ELSE","END_IF","THEN","OUT","FUNC","RETURN",
"ULONGINT","FLOAT","INT","WHILE","ERROR","LOOP","LONGINT","MAYORIGUAL",
"MENORIGUAL","IGUAL","DISTINTO","CADENA","DIGITO","F_MINUSCLA","L_MINUSCULA",
"MAYUSCULA","MINUSCULA","PROC",
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
"ejecutable : invocacion_proc",
"ejecutable : sentencia_while ';'",
"ejecutable : sentencia_if ';'",
"invocacion_proc : ID '(' parametros ')' ';'",
"parametros : parametros ',' ID",
"parametros : ID",
"procedimiento : PROC ID '(' lista_de_parametros ')' '{' bloque_sentencia '}'",
"lista_de_parametros : lista_de_parametros ',' tipo ID",
"lista_de_parametros : tipo ID",
"sentencia_if : IF '(' condicion ')' bloque_sentencia END_IF",
"sentencia_if : IF '(' condicion ')' bloque_sentencia ELSE bloque_sentencia END_IF",
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
"factor : LONGINT",
"factor : CTE",
"factor : '-' CTE",
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
#line 8 "Gramatica.y"
{AccionesSintactico::imprime("bloque_sentencia");}
break;
case 3:
#line 9 "Gramatica.y"
{AccionesSintactico::imprime("bloque_sentencia");}
break;
case 4:
#line 12 "Gramatica.y"
{AccionesSintactico::imprime("declarativa");}
break;
case 5:
#line 13 "Gramatica.y"
{AccionesSintactico::imprime("ejecutable");}
break;
case 6:
#line 14 "Gramatica.y"
{AccionesSintactico::imprime("imprimir");}
break;
case 7:
#line 17 "Gramatica.y"
{AccionesSintactico::imprime("declarativa");}
break;
case 8:
#line 18 "Gramatica.y"
{AccionesSintactico::imprime("procedimiento");}
break;
case 9:
#line 22 "Gramatica.y"
{AccionesSintactico::imprime("lista_variables");}
break;
case 10:
#line 23 "Gramatica.y"
{AccionesSintactico::imprime("id de lista");}
break;
case 11:
#line 26 "Gramatica.y"
{AccionesSintactico::imprime("expresion");}
break;
case 12:
#line 27 "Gramatica.y"
{AccionesSintactico::imprime("inv proc");}
break;
case 13:
#line 28 "Gramatica.y"
{AccionesSintactico::imprime("setencia_while");}
break;
case 14:
#line 29 "Gramatica.y"
{AccionesSintactico::imprime("sentencia if");}
break;
case 15:
#line 32 "Gramatica.y"
{AccionesSintactico::imprime("invocacion proc");}
break;
case 16:
#line 35 "Gramatica.y"
{AccionesSintactico::imprime("parametros");}
break;
case 17:
#line 36 "Gramatica.y"
{AccionesSintactico::imprime("id parametros");}
break;
case 18:
#line 39 "Gramatica.y"
{AccionesSintactico::imprime("def proc");}
break;
case 19:
#line 42 "Gramatica.y"
{AccionesSintactico::imprime("lista parametros");}
break;
case 20:
#line 43 "Gramatica.y"
{AccionesSintactico::imprime("id listapar");}
break;
case 21:
#line 46 "Gramatica.y"
{AccionesSintactico::imprime("if");}
break;
case 22:
#line 47 "Gramatica.y"
{AccionesSintactico::imprime("if else");}
break;
case 23:
#line 51 "Gramatica.y"
{AccionesSintactico::imprime("while");}
break;
case 25:
#line 55 "Gramatica.y"
{AccionesSintactico::imprime("igual");}
break;
case 26:
#line 56 "Gramatica.y"
{AccionesSintactico::imprime("menorigual");}
break;
case 27:
#line 57 "Gramatica.y"
{AccionesSintactico::imprime("mayorigual");}
break;
case 28:
#line 58 "Gramatica.y"
{AccionesSintactico::imprime("distinto");}
break;
case 29:
#line 62 "Gramatica.y"
{AccionesSintactico::imprime("suma");}
break;
case 30:
#line 63 "Gramatica.y"
{AccionesSintactico::imprime("resta");}
break;
case 31:
#line 64 "Gramatica.y"
{AccionesSintactico::imprime("termino");}
break;
case 32:
#line 68 "Gramatica.y"
{AccionesSintactico::imprime("factor");}
break;
case 33:
#line 69 "Gramatica.y"
{AccionesSintactico::imprime("div");}
break;
case 34:
#line 70 "Gramatica.y"
{AccionesSintactico::imprime("mult");}
break;
case 35:
#line 73 "Gramatica.y"
{AccionesSintactico::imprime("factor");}
break;
case 36:
#line 74 "Gramatica.y"
{AccionesSintactico::imprime("LONGINT");}
break;
case 37:
#line 75 "Gramatica.y"
{AccionesSintactico::imprime("cte");}
break;
case 38:
#line 76 "Gramatica.y"
{yyval = -1*yyvsp[0]; AccionesSintactico::imprime("se hizo negativo wachin");}
break;
case 39:
#line 80 "Gramatica.y"
{AccionesSintactico::imprime("INT");}
break;
case 40:
#line 81 "Gramatica.y"
{AccionesSintactico::imprime("LONGINT");}
break;
case 41:
#line 82 "Gramatica.y"
{AccionesSintactico::imprime("FLOAT");}
break;
case 42:
#line 85 "Gramatica.y"
{AccionesSintactico::imprime("cadena");}
break;
#line 539 "y.tab.c"
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
