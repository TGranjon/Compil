tout :
	make y.tab.c
	make lex.yy.c
	make lex.yy.o
	make projet


y.tab.c : projet.y
	yacc -d -v projet.y

lex.yy.c : projet.l
	lex projet.l

lex.yy.o : lex.yy.c
	gcc -c lex.yy.c

arith : lex.yy.o y.tab.c
	gcc -o projet lex.yy.o y.tab.c -ly -ll


clean :
	rm lex.yy.c lex.yy.o y.output y.tab.c y.tab.h projet
