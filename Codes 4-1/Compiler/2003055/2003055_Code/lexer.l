%option noyywrap

%{
	#define INT_TYPE 1
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "parser.tab.h"
	
	int lineno = 1; // initialize to 1
	void yyerror();
%}

alpha     [a-zA-Z]
digit     [0-9]
alnum     {alpha}|{digit}
print     [ -~]

ID        {alpha}{alnum}*
ICONST    [0-9]{digit}*
%%

"//".*        { } 

"main"[ \t]+"function"[ \t]*"("[ \t]*")"   { return MAIN_FUNC; }
"suru"                                      { return SURU; }
"sesh"                                      { return SESH; }
"dhori"                                     { return DHORI; }
"ar"[ \t]+"type"                           { return AR_TYPE; }
"integer"                                   { yylval.int_val=INT_TYPE; return INTEGER; }
"soman"                                     { return SOMAN; }
"jog"                                       { return JOG; }
"print"[ \t]+"kori"                        { return PRINT_KORI; }

{ID}        {strcpy(yylval.str_val, yytext); return ID;}
{ICONST}    {yylval.int_val=atoi(yytext); return ICONST;}

"\n"        { lineno += 1; }
[ \t\r\f]+  

.       { yyerror("Unrecognized character"); }
