## ================= WSL + MacOS =======================
input = input.txt
output = output.txt

main: lexer.l parser.y
	bison -d parser.y 
	flex lexer.l 
	gcc parser.tab.c lex.yy.c
	
	./a.out <$(input)> $(output)
# 	Making .asm file
	grep -A 1000 "============= ASM CODE===============" $(output) | tail -n +2 | grep -v "^;" > prog1.asm

clean:
	rm -f parser.tab.c parser.tab.h lex.yy.c a.out output.txt prog1.asm


