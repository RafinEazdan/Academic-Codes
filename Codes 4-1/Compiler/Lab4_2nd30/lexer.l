%option noyywrap

%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "parser.tab.h"

	int lineno = 1;
	int yyerror(const char *s);
%}

LETTER    [A-Za-z_]
DIGIT     [0-9]
ID        {LETTER}({LETTER}|{DIGIT})*
ICONST    {DIGIT}+
FCONST    {DIGIT}+"."{DIGIT}+
CHARLIT   \'[ -~]\'

%%

"//".*                   { }

"int"                    { return INT; }
"double"                 { return DOUBLE; }
"char"                   { return CHAR; }
"if"                     { return IF; }
"else"                   { return ELSE; }
"while"                  { return WHILE; }

"=="                     { return EQUOP; }
">"                      { return GT; }
"<"                      { return LT; }
"+"                      { return ADDOP; }
"-"                      { return SUBOP; }
"*"                      { return MULOP; }
"/"                      { return DIVOP; }
"="                      { return ASSIGN; }

"("                      { return LPAREN; }
")"                      { return RPAREN; }
"{"                      { return LBRACE; }
"}"                      { return RBRACE; }
";"                      { return SEMI; }

{ID}                     { strcpy(yylval.str_val, yytext); return ID; }
{ICONST}                 { return ICONST; }
{FCONST}                 { return FCONST; }
{CHARLIT}                { return CCONST; }

[ \t\r\f]+               { }
\n                       { lineno += 1; }

.                        { yyerror("Unrecognized character"); }

%%