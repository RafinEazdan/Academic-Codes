%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
    #include "symtab.c"
    #include "codeGen.c"
	void yyerror();
	extern int lineno;
	extern int yylex();
%}

%union
{
    char str_val[100];
    int int_val;
}

%token MAIN_FUNC SURU SESH DHORI AR_TYPE SOMAN PRINT_KORI JOG
%token<str_val> ID
%token<int_val> ICONST
%token<int_val> INTEGER

%left JOG

%type<int_val> exp

%start program

%%
program: {gen_code(START, -1);} MAIN_FUNC SURU code SESH {gen_code(HALT, -1);}
        ;

code: statements;

statements: statements statement | ;

statement:  declaration
            |assignment
            |print_statement
            ;

declaration: DHORI ID AR_TYPE INTEGER
            {
                insert($2, $4);
            }
            ;

assignment: ID SOMAN exp
            {
                int address = idcheck($1);

                if(address != -1)
                {
                    gen_code(STORE, address);
                }
                else
                    yyerror();
            }
            ;

print_statement: PRINT_KORI ID
                {
                    int address = idcheck($2);

                    if(address != -1)
                    {
                        gen_code(PRINT_INT_VALUE, address);
                    }
                    else
                        yyerror();
                }
                ;

exp: ICONST
    {
        gen_code(LD_INT, $1);
    }
    | ID 
      {
            int address = idcheck($1);

            if(address != -1)
            {
                gen_code(LD_VAR, address);
            }
            else
                yyerror();
      }
    | exp JOG exp { gen_code(ADD, -1); }
    ;

%%

void yyerror ()
{
	printf("Syntax error at line %d\n", lineno);
	exit(1);
}

int main (int argc, char *argv[])
{
	yyparse();
	printf("Parsing finished!\n");

    printf("\n\n============= INTERMEDIATE CODE===============\n");
    print_code();

    printf("\n\n============= ASM CODE===============\n");
    print_assembly();

	return 0;
}
