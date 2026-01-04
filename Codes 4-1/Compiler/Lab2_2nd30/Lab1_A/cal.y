%{
#include <stdio.h>
void yyerror(char *s);
int yylex();

%}
%token ASSIGN ADD SUB MULT NUM ID SEMI
%start statements

%%
statements: statements statement
            |
            ;

statement: ID ASSIGN exp SEMI
           |
           ;

exp: exp ADD NUM
   | exp SUB NUM
   | exp MULT NUM
   | ID
   | NUM
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