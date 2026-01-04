main: cal.l cal.y
	bison -d cal.y
	flex cal.l
	gcc cal.tab.c lex.yy.c -o calc
	./calc < input.txt > output.txt
clean:
	rm -f calc cal.tab.* lex.yy.c a.out output.txt