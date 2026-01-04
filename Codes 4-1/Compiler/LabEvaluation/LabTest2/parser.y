%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

int yyerror(const char *s);
extern int lineno;
extern int yylex(void);
%}

%union{
    char str_val[100];
    int  int_val;
}

%token DEF THEN
%token INT IF
%token ADDOP GT
%token ASSIGN SEMI
%token<str_val> ID
%token ICONST CCONST

%type<int_val> type constant exp

%left GT
%left ADDOP

%start code

%%

code
    : declaration statement
    ;

declaration
    : DEF type ID ASSIGN exp SEMI
      { insert($3, $2); if (typecheck($2, $5) == 0) yyerror("Type mismatch in initialized declaration"); }
    ;

statement
    : IF exp THEN assignment
    ;

assignment
    : ID ASSIGN exp SEMI
      { if (!idcheck($1)) yyerror("Undeclared identifier in assignment"); else if (typecheck(gettype($1), $3) == 0) yyerror("Type mismatch in assignment"); }
    ;

type
    : INT    { $$ = INT_TYPE; }
    ;

exp
    : constant                    { $$ = $1; }
    | ID                          { $$ = idcheck($1) ? gettype($1) : (yyerror("Use of undeclared identifier"), UNDEF_TYPE); }
    | exp ADDOP exp               { $$ = typecheck($1, $3) ? typecheck($1, $3) : (yyerror("Type mismatch in addition"), UNDEF_TYPE); }
    | exp GT exp                  { $$ = INT_TYPE; }
    ;

constant
    : ICONST { $$ = INT_TYPE; }
    | CCONST { $$ = CHAR_TYPE; }
    ;

%%

int yyerror(const char *s)
{
    fprintf(stderr, "%s at line %d\n", s ? s : "syntax error", lineno);
    return 0;
}

int main (int argc, char *argv[])
{
    if (yyparse() == 0) {
        printf("Parsing finished!\n");
    }
    return 0;
}