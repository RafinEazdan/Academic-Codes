%option noyywrap
%{
#include "cal.tab.h"
%}

/* tokens */
%%
"Who"       { return WHO; }
"What"      { return WHAT; }
"IS"        { return IS; }
"WAS"       { return WAS; }
"You"       { return YOU; }
"HIM"       { return HIM; }
"?"         { return QMARK; }

[ \t\r\n]+  ;          /* ignore whitespace */
.           { return yytext[0]; }
%%