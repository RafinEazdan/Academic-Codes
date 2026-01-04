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
    int int_val;   /* we use this for type codes: INT_TYPE/REAL_TYPE/CHAR_TYPE */
}

/* tokens */
%token INT IF ELSE WHILE CONTINUE BREAK PRINT DOUBLE CHAR
%token ADDOP SUBOP MULOP DIVOP EQUOP LT GT
%token LPAREN RPAREN LBRACE RBRACE SEMI ASSIGN
%token<str_val> ID
%token ICONST
%token FCONST
%token CCONST

%type<int_val> type constant exp

/* precedence (lowest to highest) */
%left LT GT EQUOP
%left ADDOP SUBOP
%left MULOP DIVOP

%start code

%%

code
    : statements
    ;

statements
    : statements statement
    | /* empty */
    ;

statement
    : declaration
    | assignment
    | if_statement
    | while_statement
    ;

declaration
    : type ID SEMI
      {
        insert($2, $1);
      }
    | type ID ASSIGN exp SEMI
      {
        insert($2, $1);
        if (typecheck($1, $4) == 0)
          yyerror("Type mismatch in initialized declaration");
      }
    ;

assignment
    : ID ASSIGN exp SEMI
      {
        if (idcheck($1) == 0) {
          yyerror("Undeclared identifier in assignment");
        } else {
          if (typecheck(gettype($1), $3) == 0)
            yyerror("Type mismatch in assignment");
        }
      }
    ;

type
    : INT    { $$ = INT_TYPE; }
    | DOUBLE { $$ = REAL_TYPE; }
    | CHAR   { $$ = CHAR_TYPE; }
    ;

exp
    : constant                    { $$ = $1; }
    | ID
      {
        if (idcheck($1) == 0) {
          yyerror("Use of undeclared identifier");
          $$ = UNDEF_TYPE;
        } else {
          $$ = gettype($1);
        }
      }
    | exp ADDOP exp
      {
        if (typecheck($1, $3) == 0) {
          yyerror("Type mismatch in addition");
          $$ = UNDEF_TYPE;
        } else {
          $$ = typecheck($1, $3);
        }
      }
    | exp SUBOP exp
      {
        if (typecheck($1, $3) == 0) {
          yyerror("Type mismatch in subtraction");
          $$ = UNDEF_TYPE;
        } else {
          $$ = typecheck($1, $3);
        }
      }
    | exp MULOP exp
      {
        if (typecheck($1, $3) == 0) {
          yyerror("Type mismatch in multiplication");
          $$ = UNDEF_TYPE;
        } else {
          $$ = typecheck($1, $3);
        }
      }
    | exp DIVOP exp
      {
        if (typecheck($1, $3) == 0) {
          yyerror("Type mismatch in division");
          $$ = UNDEF_TYPE;
        } else {
          $$ = typecheck($1, $3);
        }
      }
    | exp LT exp
      { $$ = INT_TYPE; }   /* relational -> boolean (modeled as int) */
    | exp GT exp
      { $$ = INT_TYPE; }
    | exp EQUOP exp
      { $$ = INT_TYPE; }
    ;

constant
    : ICONST { $$ = INT_TYPE; }
    | FCONST { $$ = REAL_TYPE; }
    | CCONST { $$ = CHAR_TYPE; }
    ;

if_statement
    : IF LPAREN exp RPAREN LBRACE statements RBRACE optional_else
      {
        /* we could check that exp is INT_TYPE (boolean), but keep simple */
      }
    ;

optional_else
    : ELSE IF LPAREN exp RPAREN LBRACE statements RBRACE
    | ELSE LBRACE statements RBRACE
    | /* empty */
    ;

while_statement
    : WHILE LPAREN exp RPAREN LBRACE statements RBRACE
      {
        /* similarly, could validate condition type */
      }
    ;

%%

int yyerror(const char *s)
{
	fprintf(stderr, "%s at line %d\n", s ? s : "Syntax error", lineno);
	return 0;
}

int main (int argc, char *argv[])
{
	if (yyparse() == 0) {
		printf("Parsing finished!\n");
	}
	return 0;
}