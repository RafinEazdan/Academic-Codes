%option noyywrap
%{
#include "cal.tab.h"
%}
delim [ \t\n]
ws {delim}+
digit [0-9]
number ({digit}+)

%%
{ws} {}
{number} {return (NUM);}
"="         { return ASSIGN; }
"+"         { return ADD; }
";"         { return SEMI; }
[0-9]+      { yylval = atoi(yytext); return NUM; }
[a-zA-Z_][a-zA-Z0-9_]*  { return ID; }
[ \t\n]+    ; // ignore whitespace
.           { return yytext[0]; }

%%