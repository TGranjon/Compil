tout :
	make y.tab.c
	make lex.yy.c
	make lex.yy.o
	make arbre.o
	make declaration.o
	make lexhc.o
	make region.o
	make projet

y.tab.c : projet.y
	yacc -d -v projet.y

lex.yy.c : projet.l
	lex projet.l

lex.yy.o : lex.yy.c
	gcc -c lex.yy.c

arbre.o : arbre.c arbre.h
	gcc -c arbre.c arbre.h

declaration.o : declaration.c declaration.h
	gcc -c declaration.c declaration.h

lexhc.o : lexhc.c lexhc.h
	gcc -c lexhc.c lexhc.h

region.o : region.c region.h
	gcc -c region.c region.h

projet : lex.yy.o y.tab.c
	gcc -o projet lex.yy.o y.tab.c -ly -ll

analyse :
	make y.tab.c
	make lex.yy.c
	make lex.yy.o


propre :
	rm lex.yy.c lex.yy.o y.output y.tab.c y.tab.h arbre.o arbre.h.gch declaration.o declaration.h.gch lexhc.o lexhc.h.gch region.o region.h.gch projet
