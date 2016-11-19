tout :
	make y.tab.c
	make lex.yy.c
	make lex.yy.o
	make arbre.o
	make projet


y.tab.c : projet.y
	yacc -d -v projet.y

lex.yy.c : projet.l
	lex projet.l

lex.yy.o : lex.yy.c
	gcc -c lex.yy.c

arbre.o : arbre.c arbre.h
	gcc -Wall -c arbre.c arbre.h

projet : lex.yy.o y.tab.c
	gcc -o projet lex.yy.o y.tab.c -ly -ll


propre :
	rm lex.yy.c lex.yy.o y.output y.tab.c y.tab.h arbre.o arbre.h.gch projet
