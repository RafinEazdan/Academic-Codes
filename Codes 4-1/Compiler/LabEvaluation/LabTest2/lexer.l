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
CHARLIT   \'[ -~]\'

%%

"DEF"        { return DEF; }
"THEN"       { return THEN; }
"INT"        { return INT; }
"IF"         { return IF; }

">"          { return GT; }
"+"          { return ADDOP; }
"="          { return ASSIGN; }
";"          { return SEMI; }

{ID}         { strcpy(yylval.str_val, yytext); return ID; }
{ICONST}     { return ICONST; }
{CHARLIT}    { return CCONST; }

[ \t\r\f]+   { }
\n           { lineno += 1; }

.            { yyerror("Unrecognized character"); }

%%