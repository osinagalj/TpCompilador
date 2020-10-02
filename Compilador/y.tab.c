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
#define INTEGER 268
#define DOUBLE 269
#define WHILE 270
#define UINT 271
#define LOOP 272
#define LONGINT 273
#define MAYORIGUAL 274
#define MENORIGUAL 275
#define IGUAL 276
#define DISTINTO 277
#define CADENA 278
#define DIGITO 279
#define F_MINUSCLA 280
#define L_MINUSCULA 281
#define MAYUSCULA 282
#define MINUSCULA 283
#define PROC 284
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    1,    1,    2,    2,    2,    3,    3,    7,    7,
    4,    4,    4,    4,   10,   13,   13,    8,   14,   14,
   12,   12,   11,   15,   15,   15,   15,   15,    9,    9,
    9,   16,   16,   16,   17,   17,    6,    6,    6,    6,
    6,    6,    5,
};
short yylen[] = {                                         2,
    1,    1,    2,    1,    1,    1,    2,    2,    3,    2,
    4,    1,    2,    1,    5,    3,    1,    6,    4,    2,
    6,    8,    6,    0,    3,    3,    3,    3,    3,    3,
    1,    1,    3,    3,    1,    1,    1,    1,    1,    1,
    1,    1,    5,
};
short yydefred[] = {                                      0,
    0,    0,    0,   40,   41,   37,   42,    0,   38,   39,
    0,    0,    0,    2,    4,    5,    6,    0,    0,   12,
    0,   14,    0,    0,    0,    0,    0,    0,    3,    0,
    7,    8,   13,   35,   36,    0,    0,   32,   17,    0,
    0,    0,    0,    0,    0,   10,    0,   11,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    9,    0,    0,   33,   34,   16,   15,
    0,    0,    0,    0,    0,   43,    0,   20,    0,    0,
    0,   21,    0,    0,    0,    0,   19,   22,
};
short yydgoto[] = {                                      12,
   13,   14,   15,   16,   17,   18,   31,   19,   41,   20,
   21,   22,   40,   63,   42,   37,   38,
};
short yysindex[] = {                                   -163,
  -29,    7,   19,    0,    0,    0,    0,   24,    0,    0,
 -244,    0, -163,    0,    0,    0,    0, -236,    6,    0,
    9,    0, -224, -190, -224, -209, -224,   30,    0,  -28,
    0,    0,    0,    0,    0,    1,  -27,    0,    0,  -19,
  -26,   31,   35,   37, -155,    0, -236,    0, -224, -224,
 -224, -224, -177,   23, -224, -224, -224, -224, -163,   33,
 -189, -167,  -17,    0,  -27,  -27,    0,    0,    0,    0,
   11,   11,   11,   11, -218,    0, -163,    0, -155, -163,
 -163,    0, -163, -164, -163, -182,    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   95,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   56,    0,   56,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -41,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -36,  -31,    0,    0,    0,    0,
   57,   58,   60,   68,    0,    0,    0,    0,    0,    0,
    0,    0,   61,    0,   63,    0,    0,    0,
};
short yygindex[] = {                                      0,
  -51,  -12,    0,    0,    0,  -39,   70,    0,  -20,    0,
    0,    0,    0,    0,   88,    8,   10,
};
#define YYTABLESIZE 251
short yytable[] = {                                      31,
   29,   31,   36,   31,   29,   62,   29,   75,   29,   30,
   24,   30,   28,   30,   52,   47,   49,   31,   50,   51,
   30,   54,   29,   80,   53,   83,   79,   30,   85,   86,
   46,   23,   34,   35,   71,   72,   73,   74,    1,   84,
    2,   81,   82,   49,    3,   50,   25,    4,    5,    6,
    7,    8,    9,   49,   10,   50,   65,   66,   26,   48,
   67,   68,   29,   27,   32,   11,   39,   33,   43,   45,
   29,   59,   29,   29,    1,   60,    2,   61,   88,   69,
    3,   70,   77,    4,    5,    6,    7,    8,    9,   78,
   10,   76,   87,    1,    1,    2,   24,   27,   26,    3,
   25,   11,    4,    5,    6,    7,    8,    9,   28,   10,
    4,    5,    6,    7,   44,    9,   64,   10,    0,   23,
   11,   18,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   31,   31,   31,   31,    0,   29,   29,   29,
   29,    0,   30,   30,   30,   30,    0,   55,   56,   57,
   58,
};
short yycheck[] = {                                      41,
   13,   43,   23,   45,   41,   45,   43,   59,   45,   41,
   40,   43,  257,   45,   42,   44,   43,   59,   45,   47,
  257,   41,   59,   41,   44,   77,   44,   59,   80,   81,
   59,   61,  257,  258,   55,   56,   57,   58,  257,   79,
  259,  260,  261,   43,  263,   45,   40,  266,  267,  268,
  269,  270,  271,   43,  273,   45,   49,   50,   40,   59,
   51,   52,   75,   40,   59,  284,  257,   59,  278,   40,
   83,   41,   85,   86,  257,   41,  259,   41,  261,  257,
  263,   59,  272,  266,  267,  268,  269,  270,  271,  257,
  273,   59,  257,  257,    0,  259,   41,   41,   41,  263,
   41,  284,  266,  267,  268,  269,  270,  271,   41,  273,
  266,  267,  268,  269,   27,  271,   47,  273,   -1,   59,
  284,   59,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  274,  275,  276,  277,   -1,  274,  275,  276,
  277,   -1,  274,  275,  276,  277,   -1,  274,  275,  276,
  277,
};
#define YYFINAL 12
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 284
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
"';'",0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"ID","CTE","IF","ELSE","END_IF","THEN","OUT","FUNC","RETURN","ULONGINT",
"FLOAT","INTEGER","DOUBLE","WHILE","UINT","LOOP","LONGINT","MAYORIGUAL",
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
"ejecutable : sentencia_if",
"invocacion_proc : ID '(' parametros ')' ';'",
"parametros : parametros ',' ID",
"parametros : ID",
"procedimiento : PROC ID '(' lista_de_parametros ')' bloque_sentencia",
"lista_de_parametros : lista_de_parametros ',' tipo ID",
"lista_de_parametros : tipo ID",
"sentencia_if : IF '(' condicion ')' bloque_sentencia END_IF",
"sentencia_if : IF '(' condicion ')' bloque_sentencia ELSE bloque_sentencia END_IF",
"sentencia_while : WHILE '(' condicion ')' LOOP bloque_sentencia",
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
"tipo : INTEGER",
"tipo : UINT",
"tipo : LONGINT",
"tipo : ULONGINT",
"tipo : FLOAT",
"tipo : DOUBLE",
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
case 18:
#line 43 "Gramatica.y"

break;
case 33:
#line 74 "Gramatica.y"



break;
#line 388 "y.tab.c"
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
