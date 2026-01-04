input = input.txt
output = output.txt

main: lexer.l parser.y
	bison -d parser.y
	flex lexer.l
	gcc parser.tab.c lex.yy.c symtab.c -o a
	./a < $(input) > $(output)

clean:
	rm -f a a.out *.o parser.tab.* lex.yy.c