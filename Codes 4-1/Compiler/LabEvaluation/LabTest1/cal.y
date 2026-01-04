%{
#include <stdio.h>
void yyerror(char *s);
int yylex();

%}
%token WHO WHAT IS WAS YOU HIM QMARK
%start statements

%%
statements: statements statement
            |
            ;

statement: WHO IS YOU QMARK
           | WHO IS HIM QMARK
           | WHAT WAS YOU QMARK
           |
           ;
%%

int main()
{
    yyparse();
    printf("Parsing Finished\n");

}

void yyerror( char *s)
{
    fprintf(stderr, "Error: %s", s);
}