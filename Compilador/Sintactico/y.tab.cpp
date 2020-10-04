#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
#define ID 257
#define CTE 258
#define ERROR 259
#define IF 260
#define ELSE 261
#define END_IF 262
#define THEN 263
#define OUT 264
#define FUNC 265
#define RETURN 266
#define ULONGINT 267
#define FLOAT 268
#define INT 269
#define DOUBLE 270
#define WHILE 271
#define UINT 272
#define LOOP 273
#define LONGINT 274
#define MAYORIGUAL 275
#define MENORIGUAL 276
#define IGUAL 277
#define DISTINTO 278
#define CADENA 279
#define DIGITO 280
#define PROC 281
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    1,    1,    2,    2,    2,    3,    7,    7,    4,
    6,    6,    6,    5,    8,    9,    9,
};
short yylen[] = {                                         2,
    1,    1,    2,    1,    1,    1,    2,    3,    2,    4,
    1,    1,    1,    4,    1,    1,    1,
};
short yydefred[] = {                                      0,
    0,   17,   13,   11,   12,    0,    0,    2,    4,    5,
    6,    0,    0,   15,    0,    3,    0,    7,    0,    0,
    0,    9,   16,    0,   10,    8,   14,
};
short yydgoto[] = {                                       6,
    7,    8,    9,   10,   11,   12,   18,   13,   14,
};
short yysindex[] = {                                   -257,
  -59,    0,    0,    0,    0,    0, -257,    0,    0,    0,
    0, -251,  -36,    0, -249,    0,  -41,    0, -253,  -50,
 -251,    0,    0,  -49,    0,    0,    0,
};
short yyrindex[] = {                                      0,
  -30,    0,    0,    0,    0,    0,   14,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
    0,    8,    0,    0,    0,    0,   -5,    1,    0,
};
#define YYTABLESIZE 20
short yytable[] = {                                       1,
    2,   15,   21,   23,    2,   17,   19,   20,   25,   27,
    3,    4,   16,    1,   16,   26,    5,   22,    0,   24,
};
short yycheck[] = {                                     257,
  258,   61,   44,  257,  258,  257,   43,  257,   59,   59,
  268,  269,   43,    0,    7,   21,  274,   59,   -1,   19,
};
#define YYFINAL 6
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 281
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'+'","','",0,0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,"'='",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ID","CTE",
"ERROR","IF","ELSE","END_IF","THEN","OUT","FUNC","RETURN","ULONGINT","FLOAT",
"INT","DOUBLE","WHILE","UINT","LOOP","LONGINT","MAYORIGUAL","MENORIGUAL",
"IGUAL","DISTINTO","CADENA","DIGITO","PROC",
};
char *yyrule[] = {
"$accept : programa",
"programa : bloque_sentencia",
"bloque_sentencia : sentencia",
"bloque_sentencia : bloque_sentencia sentencia",
"sentencia : declarativa",
"sentencia : ejecutable",
"sentencia : expresion",
"declarativa : tipo lista_de_variables",
"lista_de_variables : ID ',' lista_de_variables",
"lista_de_variables : ID ';'",
"ejecutable : ID '=' ID ';'",
"tipo : INT",
"tipo : LONGINT",
"tipo : FLOAT",
"expresion : termino '+' termino ';'",
"termino : factor",
"factor : ID",
"factor : CTE",
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
#line 49 "gramatica.y"



/*

tipo:
	 CTE {AccionesSintactico::imprime("encontro integer");}
        |LONGINT {AccionesSintactico::imprime("encontro longint");}
        |FLOAT {AccionesSintactico::imprime("encontro float");}

;





%token ID CTE IF ELSE END_IF THEN OUT FUNC RETURN ULONGINT FLOAT INTEGER DOUBLE WHILE UINT LOOP LONGINT MAYORIGUAL MENORIGUAL IGUAL DISTINTO CADENA DIGITO F_MINUSCLA L_MINUSCULA MAYUSCULA MINUSCULA  PROC
%start programa
%%
programa:
          bloque_sentencia  {AccionesSintactico::imprime();}
;
bloque_sentencia:
	 sentencia {AccionesSintactico::imprime();}
	|bloque_sentencia sentencia {AccionesSintactico::imprime();}
;
sentencia:
	 declarativa {AccionesSintactico::imprime();}
	|ejecutable {AccionesSintactico::imprime();}
	|imprimir {AccionesSintactico::imprime();}
;
declarativa:
	 tipo lista_de_variables {AccionesSintactico::imprime();}
	|procedimiento ';' {AccionesSintactico::imprime();}

;
lista_de_variables:
	ID ',' lista_de_variables {AccionesSintactico::imprime();}
	|ID ';' {AccionesSintactico::imprime();}
;
ejecutable:
	 ID '=' expresion ';'{AccionesSintactico::imprime();}
	|invocacion_proc {AccionesSintactico::imprime();}
	|sentencia_while ';' {AccionesSintactico::imprime();}
	|sentencia_if {AccionesSintactico::imprime();}
;
invocacion_proc:
	 ID '(' parametros ')' ';' {AccionesSintactico::imprime();}

;
parametros:
	 parametros ',' ID {AccionesSintactico::imprime();}
	|ID {AccionesSintactico::imprime();}
;
procedimiento:
	PROC ID '(' lista_de_parametros ')' bloque_sentencia {AccionesSintactico::imprime();}
;
lista_de_parametros:
	 lista_de_parametros ',' tipo ID {AccionesSintactico::imprime();}
	|tipo ID {AccionesSintactico::imprime();}
;
sentencia_if:
	 IF '(' condicion ')' bloque_sentencia END_IF {AccionesSintactico::imprime();}
	|IF '(' condicion ')' bloque_sentencia ELSE bloque_sentencia END_IF {AccionesSintactico::imprime();}

;
sentencia_while:
	 WHILE '(' condicion ')' LOOP bloque_sentencia {AccionesSintactico::imprime();}

;
condicion:
	|expresion IGUAL expresion {AccionesSintactico::imprime();}
	|expresion MENORIGUAL expresion {AccionesSintactico::imprime();}
	|expresion MAYORIGUAL expresion {AccionesSintactico::imprime();}
	|expresion DISTINTO expresion {AccionesSintactico::imprime();}

;
expresion:
	   expresion '+' termino {AccionesSintactico::imprime();}
	  |expresion '-' termino {AccionesSintactico::imprime();}
	  |termino {AccionesSintactico::imprime();}

;
termino:
	 factor {AccionesSintactico::imprime();}
	|termino '/' factor {AccionesSintactico::imprime();}
	|termino '*' factor {AccionesSintactico::imprime();}
;
factor:
	 ID {AccionesSintactico::imprime();}
	|CTE {AccionesSintactico::imprime();}
;

tipo:
	 INTEGER {AccionesSintactico::imprime();}
        |UINT {AccionesSintactico::imprime();}
        |LONGINT {AccionesSintactico::imprime();}
        |ULONGINT {AccionesSintactico::imprime();}
        |FLOAT {AccionesSintactico::imprime();}
        |DOUBLE {AccionesSintactico::imprime();}
;
imprimir:
	OUT '(' CADENA ')' ';' {AccionesSintactico::imprime();}
;
%%
*/
#line 244 "y.tab.c"
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
case 1:
#line 5 "gramatica.y"
{AccionesSintactico::imprime("encontro programa");}
break;
case 2:
#line 8 "gramatica.y"
{AccionesSintactico::imprime("encontro bloque_sentencia");}
break;
case 3:
#line 9 "gramatica.y"
{AccionesSintactico::imprime("encontro bloque_sentencia");}
break;
case 4:
#line 13 "gramatica.y"
{AccionesSintactico::imprime("encontro sentencia");}
break;
case 5:
#line 14 "gramatica.y"
{AccionesSintactico::imprime("encontro sentencia");}
break;
case 7:
#line 18 "gramatica.y"
{AccionesSintactico::imprime("encontro declarativa");}
break;
case 8:
#line 22 "gramatica.y"
{AccionesSintactico::imprime("encontro lista v");}
break;
case 9:
#line 23 "gramatica.y"
{AccionesSintactico::imprime("encontro lista v");}
break;
case 10:
#line 27 "gramatica.y"
{AccionesSintactico::imprime("ejecutable ");}
break;
case 11:
#line 30 "gramatica.y"
{AccionesSintactico::imprime("encontro integer");}
break;
case 12:
#line 31 "gramatica.y"
{AccionesSintactico::imprime("encontro longint");}
break;
case 13:
#line 32 "gramatica.y"
{AccionesSintactico::imprime("encontro float");}
break;
case 14:
#line 36 "gramatica.y"
{AccionesSintactico::imprime("expresion");}
break;
case 15:
#line 39 "gramatica.y"
{AccionesSintactico::imprime("termino");}
break;
case 16:
#line 42 "gramatica.y"
{AccionesSintactico::imprime("factor ID");}
break;
case 17:
#line 43 "gramatica.y"
{AccionesSintactico::imprime("factor CTE");}
break;
#line 448 "y.tab.c"
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
