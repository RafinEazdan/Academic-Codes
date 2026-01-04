main: cal.l cal.y
	bison -d cal.y
	flex cal.l
	gcc cal.tab.c lex.yy.c -o calc
	./calc < input.txt > output.txt